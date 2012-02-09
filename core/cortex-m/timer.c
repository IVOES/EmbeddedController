/* Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Timer module for Chrome EC operating system */

#include <stdint.h>

#include "task.h"
#include "timer.h"
#include "hwtimer.h"
#include "atomic.h"
#include "console.h"
#include "uart.h"
#include "util.h"

/* high word of the 64-bit timestamp counter  */
static volatile uint32_t clksrc_high;

/* bitmap of currently running timers */
static uint32_t timer_running = 0;

/* deadlines of all timers */
static timestamp_t timer_deadline[TASK_ID_COUNT];

static uint32_t next_deadline = 0xffffffff;

/* Hardware timer routine IRQ number */
static int timer_irq;

static void expire_timer(task_id_t tskid)
{
	/* we are done with this timer */
	atomic_clear(&timer_running, 1<<tskid);
	/* wake up the taks waiting for this timer */
	task_send_msg(tskid, TASK_ID_TIMER, 0);
}

/**
 * Search the next deadline and program it in the timer hardware
 *
 * overflow: if true, the 32-bit counter as overflowed since the last call.
 */
void process_timers(int overflow)
{
	uint32_t check_timer, running_t0;
	timestamp_t next;
	timestamp_t now;

	if (overflow)
		clksrc_high++;

reprocess_timers:
	next.val = 0xffffffffffffffff;
	now = get_time();
	do {
		/* read atomically the current state of timer running */
		check_timer = running_t0 = timer_running;
		while (check_timer) {
			int tskid = 31 - __builtin_clz(check_timer);

			/* timer has expired ? */
			if (timer_deadline[tskid].val < now.val)
				expire_timer(tskid);
			else if ((timer_deadline[tskid].le.hi == now.le.hi) &&
			         (timer_deadline[tskid].le.lo < next.le.lo))
				next.val = timer_deadline[tskid].val;

			check_timer &= ~(1 << tskid);
		}
	/* if there is a new timer, let's retry */
	} while (timer_running & ~running_t0);

	if (next.le.hi == 0xffffffff) {
		/* no deadline to set */
		__hw_clock_event_clear();
		next_deadline = 0xffffffff;
		return;
	}

	if (next.val <= get_time().val)
		goto reprocess_timers;
	__hw_clock_event_set(next.le.lo);
	next_deadline = next.le.lo;
	//TODO narrow race: deadline might have been reached before
}

void udelay(unsigned us)
{
	timestamp_t deadline = get_time();

	deadline.val += us;
	while (get_time().val < deadline.val) {}
}

int timer_arm(timestamp_t tstamp, task_id_t tskid)
{
	ASSERT(tskid < TASK_ID_COUNT);

	if (timer_running & (1<<tskid))
		return EC_ERROR_BUSY;

	timer_deadline[tskid] = tstamp;
	atomic_or(&timer_running, 1<<tskid);

	/* modify the next event if needed */
	if ((tstamp.le.hi < clksrc_high) ||
	    ((tstamp.le.hi == clksrc_high) && (tstamp.le.lo <= next_deadline)))
		task_trigger_irq(timer_irq);

	return EC_SUCCESS;
}

int timer_cancel(task_id_t tskid)
{
	ASSERT(tskid < TASK_ID_COUNT);

	atomic_clear(&timer_running, 1<<tskid);
	/* don't bother about canceling the interrupt:
	 * it would be slow, just do it on the next IT
	 */

	return EC_SUCCESS;
}


void usleep(unsigned us)
{
	uint32_t evt = 0;
	ASSERT(us);
	do {
		evt |= task_wait_msg(us);
	} while (!(evt & (1 << TASK_ID_TIMER)));
	/* re-queue other events which happened in the meanwhile */
	if (evt)
		atomic_or(task_get_event_bitmap(task_get_current()),
		          evt & ~(1 << TASK_ID_TIMER));
}


timestamp_t get_time(void)
{
	timestamp_t ts;
	ts.le.hi = clksrc_high;
	ts.le.lo = __hw_clock_source_read();
	if (ts.le.hi != clksrc_high) {
		ts.le.hi = clksrc_high;
		ts.le.lo = __hw_clock_source_read();
	}
	return ts;
}


static int command_wait(int argc, char **argv)
{
	if (argc < 2)
		return EC_ERROR_INVAL;

	udelay(atoi(argv[1]) * 1000);

	return EC_SUCCESS;
}
DECLARE_CONSOLE_COMMAND(waitms, command_wait);


static int command_get_time(int argc, char **argv)
{
	timestamp_t ts = get_time();
	uart_printf("Time: 0x%08x%08x us\n", ts.le.hi, ts.le.lo);
	return EC_SUCCESS;

}
DECLARE_CONSOLE_COMMAND(gettime, command_get_time);


int command_timer_info(int argc, char **argv)
{
	timestamp_t ts = get_time();
	int tskid;

	uart_printf("Time:     0x%08x%08x us\n"
	            "Deadline: 0x%08x%08x us\n"
	            "Active timers:\n",
	            ts.le.hi, ts.le.lo, clksrc_high,
		    __hw_clock_event_get());
	for (tskid = 0; tskid < TASK_ID_COUNT; tskid++) {
		if (timer_running & (1<<tskid))
			uart_printf("Tsk %d tmr 0x%08x%08x\n", tskid,
			            timer_deadline[tskid].le.hi,
			            timer_deadline[tskid].le.lo);
	}
	return EC_SUCCESS;
}
DECLARE_CONSOLE_COMMAND(timerinfo, command_timer_info);


int timer_init(void)
{
	BUILD_ASSERT(TASK_ID_COUNT < sizeof(timer_running) * 8);

	timer_irq = __hw_clock_source_init();

	return EC_SUCCESS;
}
