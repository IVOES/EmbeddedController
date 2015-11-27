#!/usr/bin/python
# Copyright 2015 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Module for initializing and driving a SPI TPM."""

from __future__ import print_function

import os
import struct
import sys
import traceback

# Suppressing pylint warning about an import not at the top of the file. The
# path needs to be set *before* the last import.
# pylint: disable=C6204
root_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
sys.path.append(os.path.join(root_dir, '..', '..', 'build', 'tpm_test'))

import crypto_test
import hash_test
import ftdi_spi_tpm

# Extension command for dcypto testing
EXT_CMD = 0xbaccd00a

class TpmError(Exception):
  pass


class TPM(object):
  """TPM accessor class.

  Object of this class allows to send valid and extended TPM commands (using
  the command() method. The wrap_command/unwrap_response methods provide a
  means of encapsulating extended commands in proper TPM data packets, as well
  as extracting extended command responses.

  Attributes:
    _handle: a ftdi_spi_tpm object, a USB/FTDI/SPI driver which allows
      communicate with a TPM connected over USB dongle.
  """

  HEADER_FMT = '>H2IH'
  STARTUP_CMD = '80 01 00 00 00 0c 00 00 01 44 00 00'
  STARTUP_RSP = ('80 01 00 00 00 0a 00 00 00 00',
                 '80 01 00 00 00 0a 00 00 01 00')

  def __init__(self, freq=800*1000, debug_mode=False):
    self._debug_enabled = debug_mode
    self._handle = ftdi_spi_tpm
    if not self._handle.FtdiSpiInit(freq, debug_mode):
      raise TpmError()
    response = self.command(''.join('%c' % int('0x%s' % x, 16)
                                    for x in self.STARTUP_CMD.split()))
    if ' '.join('%2.2x' % ord(x) for x in response) not in self.STARTUP_RSP:
      raise TpmError('init failed')

  def validate(self, data_blob, response_mode=False):
    """Check if a data blob complies with TPM command/response header format."""
    (tag, size, cmd_code, _) = struct.unpack_from(
        self.HEADER_FMT, data_blob + '  ')
    prefix = 'Misformatted blob: '
    if tag not in (0x8001, 0x8002):
      raise TpmError(prefix + 'bad tag value 0x%4.4x' % tag)
    if size != len(data_blob):
      raise TpmError(prefix + 'size mismatch: header %d, actual %d' %
                     (size, len(data_blob)))
    if size > 4096:
      raise TpmError(prefix + 'invalid size %d' % size)
    if response_mode:
      return
    if cmd_code >= 0x11f and cmd_code <= 0x18f:
      return  # This is a valid command
    if cmd_code == EXT_CMD:
      return  # This is an extension command

    raise TpmError(prefix + 'invalid command code 0x%x' % cmd_code)

  def command(self, cmd_data):
    # Verify command header
    self.validate(cmd_data)
    response = self._handle.FtdiSendCommandAndWait(cmd_data)
    self.validate(response, response_mode=True)
    return response

  def wrap_ext_command(self, subcmd_code, cmd_body):
    return struct.pack(self.HEADER_FMT, 0x8001,
                       len(cmd_body) + struct.calcsize(self.HEADER_FMT),
                       EXT_CMD, subcmd_code) + cmd_body

  def unwrap_ext_response(self, expected_subcmd, response):
    """Verify basic validity and strip off TPM extended command header.

    Get the response generated by the device, as it came off the wire, verify
    that header fields match expectations, then strip off the extension
    command header and return the payload to the caller.

    Args:
      expected_subcmd: an int, up to 16 bits in size, the extension command
        this response is supposed to be for.
      response: a binary string, the actual response received over the wire.
    Returns:
      the binary string of the response payload, if validation succeeded.
    Raises:
      TpmError: in case there are any validation problems, the error message
        describes the problem.
    """
    header_size = struct.calcsize(self.HEADER_FMT)
    tag, size, cmd, subcmd = struct.unpack(self.HEADER_FMT,
                                           response[:header_size])
    if tag != 0x8001:
      raise TpmError('Wrong response tag: %4.4x' % tag)
    if cmd != EXT_CMD:
      raise TpmError('Unexpected response command field: %8.8x' % cmd)
    if subcmd != expected_subcmd:
      raise TpmError('Unexpected response subcommand field: %2.2x' %
                     subcmd)
    if size != len(response):
      raise TpmError('Size mismatch: header %d, actual %d' % (
          size, len(response)))
    return response[header_size:]

  def debug_enabled(self):
    return self._debug_enabled


if __name__ == '__main__':
  try:
    debug_needed = len(sys.argv) == 2 and sys.argv[1] == '-d'
    t = TPM(debug_mode=debug_needed)

    crypto_test.crypto_tests(t, os.path.join(root_dir, 'crypto_test.xml'))
    hash_test.hash_test(t)
  except (TpmError, crypto_test.CryptoError, hash_test.HashError) as e:
    print()
    print('Error:', e)
    if debug_needed:
      traceback.print_exc()
    sys.exit(1)
