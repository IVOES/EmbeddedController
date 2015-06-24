/* Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Register map for IT83xx processor
 */

#ifndef __CROS_EC_REGISTERS_H
#define __CROS_EC_REGISTERS_H

#include "common.h"

/* IRQ numbers */
#define IT83XX_IRQ_WKO20           1
#define IT83XX_IRQ_KBC_OUT         2
#define IT83XX_IRQ_PMC_OUT         3
#define IT83XX_IRQ_SMB_D           4
#define IT83XX_IRQ_WKINTAD         5
#define IT83XX_IRQ_WKO23           6
#define IT83XX_IRQ_PWM             7
#define IT83XX_IRQ_ADC             8
#define IT83XX_IRQ_SMB_A           9
#define IT83XX_IRQ_SMB_B          10
#define IT83XX_IRQ_KB_MATRIX      11
#define IT83XX_IRQ_WKO26          12
#define IT83XX_IRQ_WKINTC         13
#define IT83XX_IRQ_WKO25          14
#define IT83XX_IRQ_CIR            15
#define IT83XX_IRQ_SMB_C          16
#define IT83XX_IRQ_WKO24          17
#define IT83XX_IRQ_PS2_2          18
#define IT83XX_IRQ_PS2_1          19
#define IT83XX_IRQ_PS2_0          20
#define IT83XX_IRQ_WKO22          21
#define IT83XX_IRQ_SMFI           22
#define IT83XX_IRQ_KBC_IN         24
#define IT83XX_IRQ_PMC_IN         25
#define IT83XX_IRQ_PMC2_OUT       26
#define IT83XX_IRQ_PMC2_IN        27
#define IT83XX_IRQ_GINT           28
#define IT83XX_IRQ_EGPC           29
#define IT83XX_IRQ_EXT_TIMER1     30
#define IT83XX_IRQ_WKO21          31
#define IT83XX_IRQ_GPINT0         32
#define IT83XX_IRQ_GPINT1         33
#define IT83XX_IRQ_GPINT2         34
#define IT83XX_IRQ_GPINT3         35
#define IT83XX_IRQ_CIR_GPINT      36
#define IT83XX_IRQ_SSPI           37
#define IT83XX_IRQ_UART1          38
#define IT83XX_IRQ_UART2          39
#define IT83XX_IRQ_WKO60          48
#define IT83XX_IRQ_WKO61          49
#define IT83XX_IRQ_WKO62          50
#define IT83XX_IRQ_WKO63          51
#define IT83XX_IRQ_WKO64          52
#define IT83XX_IRQ_WKO65          53
#define IT83XX_IRQ_WKO66          54
#define IT83XX_IRQ_WKO67          55
#define IT83XX_IRQ_RTCT_ALARM1    56
#define IT83XX_IRQ_RTCT_ALARM2    57
#define IT83XX_IRQ_EXT_TIMER2     58
#define IT83XX_IRQ_TMR_A0         60
#define IT83XX_IRQ_TMR_A1         61
#define IT83XX_IRQ_TMR_B0         62
#define IT83XX_IRQ_TMR_B1         63
#define IT83XX_IRQ_PMC2EX_OUT     64
#define IT83XX_IRQ_PMC2EX_IN      65
#define IT83XX_IRQ_PMC3_OUT       66
#define IT83XX_IRQ_PMC3_IN        67
#define IT83XX_IRQ_PMC4_OUT       68
#define IT83XX_IRQ_PMC4_IN        69
#define IT83XX_IRQ_I2BRAM         71
#define IT83XX_IRQ_WKO70          72
#define IT83XX_IRQ_WKO71          73
#define IT83XX_IRQ_WKO72          74
#define IT83XX_IRQ_WKO73          75
#define IT83XX_IRQ_WKO74          76
#define IT83XX_IRQ_WKO75          77
#define IT83XX_IRQ_WKO76          78
#define IT83XX_IRQ_WKO77          79
#define IT83XX_IRQ_EXT_TMR8       80
#define IT83XX_IRQ_SMB_CLOCK_HELD 81
#define IT83XX_IRQ_CEC            82
#define IT83XX_IRQ_H2RAM_LPC      83
#define IT83XX_IRQ_WKO88          85
#define IT83XX_IRQ_WKO89          86
#define IT83XX_IRQ_WKO90          87
#define IT83XX_IRQ_WKO80          88
#define IT83XX_IRQ_WKO81          89
#define IT83XX_IRQ_WKO82          90
#define IT83XX_IRQ_WKO83          91
#define IT83XX_IRQ_WKO84          92
#define IT83XX_IRQ_WKO85          93
#define IT83XX_IRQ_WKO86          94
#define IT83XX_IRQ_WKO87          95
#define IT83XX_IRQ_WKO91          96
#define IT83XX_IRQ_WKO92          97
#define IT83XX_IRQ_WKO93          98
#define IT83XX_IRQ_WKO94          99
#define IT83XX_IRQ_WKO95          100
#define IT83XX_IRQ_WKO96          101
#define IT83XX_IRQ_WKO97          102
#define IT83XX_IRQ_WKO98          103
#define IT83XX_IRQ_WKO99          104
#define IT83XX_IRQ_WKO100         105
#define IT83XX_IRQ_WKO101         106
#define IT83XX_IRQ_WKO102         107
#define IT83XX_IRQ_WKO103         108
#define IT83XX_IRQ_WKO104         109
#define IT83XX_IRQ_WKO105         110
#define IT83XX_IRQ_WKO106         111
#define IT83XX_IRQ_WKO107         112
#define IT83XX_IRQ_WKO108         113
#define IT83XX_IRQ_WKO109         114
#define IT83XX_IRQ_WKO110         115
#define IT83XX_IRQ_WKO111         116
#define IT83XX_IRQ_WKO112         117
#define IT83XX_IRQ_WKO113         118
#define IT83XX_IRQ_WKO114         119
#define IT83XX_IRQ_WKO115         120
#define IT83XX_IRQ_WKO116         121
#define IT83XX_IRQ_WKO117         122
#define IT83XX_IRQ_WKO118         123
#define IT83XX_IRQ_WKO119         124
#define IT83XX_IRQ_WKO120         125
#define IT83XX_IRQ_WKO121         126
#define IT83XX_IRQ_WKO122         127
#define IT83XX_IRQ_WKO128         128
#define IT83XX_IRQ_WKO129         129
#define IT83XX_IRQ_WKO130         130
#define IT83XX_IRQ_WKO131         131
#define IT83XX_IRQ_WKO132         132
#define IT83XX_IRQ_WKO133         133
#define IT83XX_IRQ_WKO134         134
#define IT83XX_IRQ_PMC5_OUT       149
#define IT83XX_IRQ_PMC5_IN        150
#define IT83XX_IRQ_V_COMP         151
#define IT83XX_IRQ_SMB_E          152
#define IT83XX_IRQ_SMB_F          153
#define IT83XX_IRQ_OSC_DMA        154
#define IT83XX_IRQ_EXT_TIMER3     155
#define IT83XX_IRQ_EXT_TIMER4     156
#define IT83XX_IRQ_EXT_TIMER5     157
#define IT83XX_IRQ_EXT_TIMER6     158
#define IT83XX_IRQ_EXT_TIMER7     159
#define IT83XX_IRQ_PECI           160
#define IT83XX_IRQ_SOFTWARE       161
#define IT83XX_IRQ_COUNT          162

/* IRQ dispatching to CPU INT vectors */
#define IT83XX_CPU_INT_IRQ_1       2
#define IT83XX_CPU_INT_IRQ_2       5
#define IT83XX_CPU_INT_IRQ_3       4
#define IT83XX_CPU_INT_IRQ_4       6
#define IT83XX_CPU_INT_IRQ_5       2
#define IT83XX_CPU_INT_IRQ_6       2
#define IT83XX_CPU_INT_IRQ_7       4
#define IT83XX_CPU_INT_IRQ_8       7
#define IT83XX_CPU_INT_IRQ_9       6
#define IT83XX_CPU_INT_IRQ_10      6
#define IT83XX_CPU_INT_IRQ_11      5
#define IT83XX_CPU_INT_IRQ_12      2
#define IT83XX_CPU_INT_IRQ_13      2
#define IT83XX_CPU_INT_IRQ_14      2
#define IT83XX_CPU_INT_IRQ_15      8
#define IT83XX_CPU_INT_IRQ_16      6
#define IT83XX_CPU_INT_IRQ_17      2
#define IT83XX_CPU_INT_IRQ_18      8
#define IT83XX_CPU_INT_IRQ_19      8
#define IT83XX_CPU_INT_IRQ_20      8
#define IT83XX_CPU_INT_IRQ_21      2
#define IT83XX_CPU_INT_IRQ_22     12
#define IT83XX_CPU_INT_IRQ_24      5
#define IT83XX_CPU_INT_IRQ_25      4
#define IT83XX_CPU_INT_IRQ_26      4
#define IT83XX_CPU_INT_IRQ_27      4
#define IT83XX_CPU_INT_IRQ_28     11
#define IT83XX_CPU_INT_IRQ_29     11
#define IT83XX_CPU_INT_IRQ_30      3
#define IT83XX_CPU_INT_IRQ_31      2
#define IT83XX_CPU_INT_IRQ_32     11
#define IT83XX_CPU_INT_IRQ_33     11
#define IT83XX_CPU_INT_IRQ_34     11
#define IT83XX_CPU_INT_IRQ_35     11
#define IT83XX_CPU_INT_IRQ_36      8
#define IT83XX_CPU_INT_IRQ_37      9
#define IT83XX_CPU_INT_IRQ_38      9
#define IT83XX_CPU_INT_IRQ_39      9
#define IT83XX_CPU_INT_IRQ_48      2
#define IT83XX_CPU_INT_IRQ_49      2
#define IT83XX_CPU_INT_IRQ_50      2
#define IT83XX_CPU_INT_IRQ_51      2
#define IT83XX_CPU_INT_IRQ_52      2
#define IT83XX_CPU_INT_IRQ_53      2
#define IT83XX_CPU_INT_IRQ_54      2
#define IT83XX_CPU_INT_IRQ_55      2
#define IT83XX_CPU_INT_IRQ_56     10
#define IT83XX_CPU_INT_IRQ_57     10
#define IT83XX_CPU_INT_IRQ_58      3
#define IT83XX_CPU_INT_IRQ_60      3
#define IT83XX_CPU_INT_IRQ_61      3
#define IT83XX_CPU_INT_IRQ_62      3
#define IT83XX_CPU_INT_IRQ_63      3
#define IT83XX_CPU_INT_IRQ_64      4
#define IT83XX_CPU_INT_IRQ_65      4
#define IT83XX_CPU_INT_IRQ_66      4
#define IT83XX_CPU_INT_IRQ_67      4
#define IT83XX_CPU_INT_IRQ_68      4
#define IT83XX_CPU_INT_IRQ_69      4
#define IT83XX_CPU_INT_IRQ_70     12
#define IT83XX_CPU_INT_IRQ_71     12
#define IT83XX_CPU_INT_IRQ_72      2
#define IT83XX_CPU_INT_IRQ_73      2
#define IT83XX_CPU_INT_IRQ_74      2
#define IT83XX_CPU_INT_IRQ_75      2
#define IT83XX_CPU_INT_IRQ_76      2
#define IT83XX_CPU_INT_IRQ_77      2
#define IT83XX_CPU_INT_IRQ_78      2
#define IT83XX_CPU_INT_IRQ_79      2
#define IT83XX_CPU_INT_IRQ_80      3
#define IT83XX_CPU_INT_IRQ_81      6
#define IT83XX_CPU_INT_IRQ_82     12
#define IT83XX_CPU_INT_IRQ_83     12
#define IT83XX_CPU_INT_IRQ_84      5
#define IT83XX_CPU_INT_IRQ_85      2
#define IT83XX_CPU_INT_IRQ_86      2
#define IT83XX_CPU_INT_IRQ_87      2
#define IT83XX_CPU_INT_IRQ_88      2
#define IT83XX_CPU_INT_IRQ_89      2
#define IT83XX_CPU_INT_IRQ_90      2
#define IT83XX_CPU_INT_IRQ_91      2
#define IT83XX_CPU_INT_IRQ_92      2
#define IT83XX_CPU_INT_IRQ_93      2
#define IT83XX_CPU_INT_IRQ_94      2
#define IT83XX_CPU_INT_IRQ_95      2
#define IT83XX_CPU_INT_IRQ_96      2
#define IT83XX_CPU_INT_IRQ_97      2
#define IT83XX_CPU_INT_IRQ_98      2
#define IT83XX_CPU_INT_IRQ_99      2
#define IT83XX_CPU_INT_IRQ_100     2
#define IT83XX_CPU_INT_IRQ_101     2
#define IT83XX_CPU_INT_IRQ_102     2
#define IT83XX_CPU_INT_IRQ_103     2
#define IT83XX_CPU_INT_IRQ_104     2
#define IT83XX_CPU_INT_IRQ_105     2
#define IT83XX_CPU_INT_IRQ_106     2
#define IT83XX_CPU_INT_IRQ_107     2
#define IT83XX_CPU_INT_IRQ_108     2
#define IT83XX_CPU_INT_IRQ_109     2
#define IT83XX_CPU_INT_IRQ_110     2
#define IT83XX_CPU_INT_IRQ_111     2
#define IT83XX_CPU_INT_IRQ_112     2
#define IT83XX_CPU_INT_IRQ_113     2
#define IT83XX_CPU_INT_IRQ_114     2
#define IT83XX_CPU_INT_IRQ_115     2
#define IT83XX_CPU_INT_IRQ_116     2
#define IT83XX_CPU_INT_IRQ_117     2
#define IT83XX_CPU_INT_IRQ_118     2
#define IT83XX_CPU_INT_IRQ_119     2
#define IT83XX_CPU_INT_IRQ_120     2
#define IT83XX_CPU_INT_IRQ_121     2
#define IT83XX_CPU_INT_IRQ_122     2
#define IT83XX_CPU_INT_IRQ_123     2
#define IT83XX_CPU_INT_IRQ_124     2
#define IT83XX_CPU_INT_IRQ_125     2
#define IT83XX_CPU_INT_IRQ_126     2
#define IT83XX_CPU_INT_IRQ_127     2
#define IT83XX_CPU_INT_IRQ_128     2
#define IT83XX_CPU_INT_IRQ_129     2
#define IT83XX_CPU_INT_IRQ_130     2
#define IT83XX_CPU_INT_IRQ_131     2
#define IT83XX_CPU_INT_IRQ_132     2
#define IT83XX_CPU_INT_IRQ_133     2
#define IT83XX_CPU_INT_IRQ_134     2
#define IT83XX_CPU_INT_IRQ_144     2
#define IT83XX_CPU_INT_IRQ_145     2
#define IT83XX_CPU_INT_IRQ_146     2
#define IT83XX_CPU_INT_IRQ_147     2
#define IT83XX_CPU_INT_IRQ_148     2
#define IT83XX_CPU_INT_IRQ_149     4
#define IT83XX_CPU_INT_IRQ_150     4
#define IT83XX_CPU_INT_IRQ_151     7
#define IT83XX_CPU_INT_IRQ_152     6
#define IT83XX_CPU_INT_IRQ_153     6
#define IT83XX_CPU_INT_IRQ_154    12
#define IT83XX_CPU_INT_IRQ_155     3
#define IT83XX_CPU_INT_IRQ_156     3
#define IT83XX_CPU_INT_IRQ_157     3
#define IT83XX_CPU_INT_IRQ_158     3
#define IT83XX_CPU_INT_IRQ_159     3
#define IT83XX_CPU_INT_IRQ_160    12
#define IT83XX_CPU_INT_IRQ_161    12

/* "Fake" IRQ to declare in readable fashion all WKO IRQ routed to INT#2 */
#define CPU_INT_2_ALL_GPIOS      255
#define IT83XX_CPU_INT_IRQ_255     2

#define CPU_INT_GROUP_5          254
#define IT83XX_CPU_INT_IRQ_254     5

#define CPU_INT_GROUP_4          252
#define IT83XX_CPU_INT_IRQ_252     4

#define CPU_INT_GROUP_12         253
#define IT83XX_CPU_INT_IRQ_253    12

#define CPU_INT(irq) CONCAT2(IT83XX_CPU_INT_IRQ_, irq)

/* --- INTC --- */
#define IT83XX_INTC_BASE    0x00F01100

#define IT83XX_INTC_REG(n)  REG8(IT83XX_INTC_BASE+(n))

#define IT83XX_INTC_AIVCT   REG8(IT83XX_INTC_BASE+0x10)

#define IT83XX_INTC_IER0    REG8(IT83XX_INTC_BASE+0x04)
#define IT83XX_INTC_IER1    REG8(IT83XX_INTC_BASE+0x05)
#define IT83XX_INTC_IER2    REG8(IT83XX_INTC_BASE+0x06)
#define IT83XX_INTC_IER3    REG8(IT83XX_INTC_BASE+0x07)
#define IT83XX_INTC_IER4    REG8(IT83XX_INTC_BASE+0x15)
#define IT83XX_INTC_IER5    REG8(IT83XX_INTC_BASE+0x19)
#define IT83XX_INTC_IER6    REG8(IT83XX_INTC_BASE+0x1d)
#define IT83XX_INTC_IER7    REG8(IT83XX_INTC_BASE+0x21)
#define IT83XX_INTC_IER8    REG8(IT83XX_INTC_BASE+0x25)
#define IT83XX_INTC_IER9    REG8(IT83XX_INTC_BASE+0x29)
#define IT83XX_INTC_IER10   REG8(IT83XX_INTC_BASE+0x2d)
#define IT83XX_INTC_IER11   REG8(IT83XX_INTC_BASE+0x31)
#define IT83XX_INTC_IER12   REG8(IT83XX_INTC_BASE+0x35)
#define IT83XX_INTC_IER13   REG8(IT83XX_INTC_BASE+0x39)
#define IT83XX_INTC_IER14   REG8(IT83XX_INTC_BASE+0x3d)
#define IT83XX_INTC_IER15   REG8(IT83XX_INTC_BASE+0x41)
#define IT83XX_INTC_IER16   REG8(IT83XX_INTC_BASE+0x45)
#define IT83XX_INTC_IER17   REG8(IT83XX_INTC_BASE+0x49)
#define IT83XX_INTC_IER18   REG8(IT83XX_INTC_BASE+0x4d)
#define IT83XX_INTC_IER19   REG8(IT83XX_INTC_BASE+0x51)
#define IT83XX_INTC_IER20   REG8(IT83XX_INTC_BASE+0x55)

#define IT83XX_INTC_ISR0    REG8(IT83XX_INTC_BASE+0x00)
#define IT83XX_INTC_ISR1    REG8(IT83XX_INTC_BASE+0x01)
#define IT83XX_INTC_ISR2    REG8(IT83XX_INTC_BASE+0x02)
#define IT83XX_INTC_ISR3    REG8(IT83XX_INTC_BASE+0x03)
#define IT83XX_INTC_ISR4    REG8(IT83XX_INTC_BASE+0x14)
#define IT83XX_INTC_ISR5    REG8(IT83XX_INTC_BASE+0x18)
#define IT83XX_INTC_ISR6    REG8(IT83XX_INTC_BASE+0x1c)
#define IT83XX_INTC_ISR7    REG8(IT83XX_INTC_BASE+0x20)
#define IT83XX_INTC_ISR8    REG8(IT83XX_INTC_BASE+0x24)
#define IT83XX_INTC_ISR9    REG8(IT83XX_INTC_BASE+0x28)
#define IT83XX_INTC_ISR10   REG8(IT83XX_INTC_BASE+0x2c)
#define IT83XX_INTC_ISR11   REG8(IT83XX_INTC_BASE+0x30)
#define IT83XX_INTC_ISR12   REG8(IT83XX_INTC_BASE+0x34)
#define IT83XX_INTC_ISR13   REG8(IT83XX_INTC_BASE+0x38)
#define IT83XX_INTC_ISR14   REG8(IT83XX_INTC_BASE+0x3c)
#define IT83XX_INTC_ISR15   REG8(IT83XX_INTC_BASE+0x40)
#define IT83XX_INTC_ISR16   REG8(IT83XX_INTC_BASE+0x44)
#define IT83XX_INTC_ISR17   REG8(IT83XX_INTC_BASE+0x48)
#define IT83XX_INTC_ISR18   REG8(IT83XX_INTC_BASE+0x4c)
#define IT83XX_INTC_ISR19   REG8(IT83XX_INTC_BASE+0x50)
#define IT83XX_INTC_ISR20   REG8(IT83XX_INTC_BASE+0x54)

#define IT83XX_INTC_IELMR10 REG8(IT83XX_INTC_BASE+0x2E)
#define IT83XX_INTC_IPOLR10 REG8(IT83XX_INTC_BASE+0x2F)
#define IT83XX_INTC_IELMR19 REG8(IT83XX_INTC_BASE+0x52)
#define IT83XX_INTC_IPOLR19 REG8(IT83XX_INTC_BASE+0x53)

#define IT83XX_INTC_EXT_IER0    REG8(IT83XX_INTC_BASE+0x60)
#define IT83XX_INTC_EXT_IER1    REG8(IT83XX_INTC_BASE+0x61)
#define IT83XX_INTC_EXT_IER2    REG8(IT83XX_INTC_BASE+0x62)
#define IT83XX_INTC_EXT_IER3    REG8(IT83XX_INTC_BASE+0x63)
#define IT83XX_INTC_EXT_IER4    REG8(IT83XX_INTC_BASE+0x64)
#define IT83XX_INTC_EXT_IER5    REG8(IT83XX_INTC_BASE+0x65)
#define IT83XX_INTC_EXT_IER6    REG8(IT83XX_INTC_BASE+0x66)
#define IT83XX_INTC_EXT_IER7    REG8(IT83XX_INTC_BASE+0x67)
#define IT83XX_INTC_EXT_IER8    REG8(IT83XX_INTC_BASE+0x68)
#define IT83XX_INTC_EXT_IER9    REG8(IT83XX_INTC_BASE+0x69)
#define IT83XX_INTC_EXT_IER10   REG8(IT83XX_INTC_BASE+0x6A)
#define IT83XX_INTC_EXT_IER11   REG8(IT83XX_INTC_BASE+0x6B)
#define IT83XX_INTC_EXT_IER12   REG8(IT83XX_INTC_BASE+0x6C)
#define IT83XX_INTC_EXT_IER13   REG8(IT83XX_INTC_BASE+0x6D)
#define IT83XX_INTC_EXT_IER14   REG8(IT83XX_INTC_BASE+0x6E)
#define IT83XX_INTC_EXT_IER15   REG8(IT83XX_INTC_BASE+0x6F)
#define IT83XX_INTC_EXT_IER16   REG8(IT83XX_INTC_BASE+0x70)
#define IT83XX_INTC_EXT_IER17   REG8(IT83XX_INTC_BASE+0x71)
#define IT83XX_INTC_EXT_IER18   REG8(IT83XX_INTC_BASE+0x72)
#define IT83XX_INTC_EXT_IER19   REG8(IT83XX_INTC_BASE+0x73)
#define IT83XX_INTC_EXT_IER20   REG8(IT83XX_INTC_BASE+0x74)

#define IT83XX_INTC_EXT_IER_OFF(n) (0x60 + (n))

#define IT83XX_INTC_IVCT0       REG8(IT83XX_INTC_BASE+0x80)
#define IT83XX_INTC_IVCT1       REG8(IT83XX_INTC_BASE+0x81)
#define IT83XX_INTC_IVCT2       REG8(IT83XX_INTC_BASE+0x82)
#define IT83XX_INTC_IVCT3       REG8(IT83XX_INTC_BASE+0x83)
#define IT83XX_INTC_IVCT4       REG8(IT83XX_INTC_BASE+0x84)
#define IT83XX_INTC_IVCT5       REG8(IT83XX_INTC_BASE+0x85)
#define IT83XX_INTC_IVCT6       REG8(IT83XX_INTC_BASE+0x86)
#define IT83XX_INTC_IVCT7       REG8(IT83XX_INTC_BASE+0x87)
#define IT83XX_INTC_IVCT8       REG8(IT83XX_INTC_BASE+0x88)
#define IT83XX_INTC_IVCT9       REG8(IT83XX_INTC_BASE+0x89)
#define IT83XX_INTC_IVCT10      REG8(IT83XX_INTC_BASE+0x8A)
#define IT83XX_INTC_IVCT11      REG8(IT83XX_INTC_BASE+0x8B)
#define IT83XX_INTC_IVCT12      REG8(IT83XX_INTC_BASE+0x8C)
#define IT83XX_INTC_IVCT13      REG8(IT83XX_INTC_BASE+0x8D)
#define IT83XX_INTC_IVCT14      REG8(IT83XX_INTC_BASE+0x8E)
#define IT83XX_INTC_IVCT15      REG8(IT83XX_INTC_BASE+0x8F)

/* --- EC Access to the Host Controlled Modules (EC2I Bridge) --- */
#define IT83XX_EC2I_BASE  0x00F01200

#define IT83XX_EC2I_IHIOA       REG8(IT83XX_EC2I_BASE+0x00)
#define IT83XX_EC2I_IHD         REG8(IT83XX_EC2I_BASE+0x01)
#define IT83XX_EC2I_LSIOHA      REG8(IT83XX_EC2I_BASE+0x02)
#define IT83XX_EC2I_SIOLV       REG8(IT83XX_EC2I_BASE+0x03)
#define IT83XX_EC2I_IBMAE       REG8(IT83XX_EC2I_BASE+0x04)
#define IT83XX_EC2I_IBCTL       REG8(IT83XX_EC2I_BASE+0x05)

/* --- System Wake-UP Control (SWUC) --- */
#define IT83XX_SWUC_BASE  0x00F01400
#define IT83XX_SWUC_SWCTL1      REG8(IT83XX_SWUC_BASE+0x00)

/* --- Wake-Up Control (WUC) --- */
#define IT83XX_WUC_BASE   0x00F01B00

#define IT83XX_WUC_WUEMR1 (IT83XX_WUC_BASE+0x00)
#define IT83XX_WUC_WUEMR6 (IT83XX_WUC_BASE+0x10)
#define IT83XX_WUC_WUESR1 (IT83XX_WUC_BASE+0x04)
#define IT83XX_WUC_WUESR6 (IT83XX_WUC_BASE+0x11)

#define IT83XX_WUC_WUESR10    REG8(IT83XX_WUC_BASE+0x21)
#define IT83XX_WUC_WUESR11    REG8(IT83XX_WUC_BASE+0x25)

#define IT83XX_WUC_WUEMR3     REG8(IT83XX_WUC_BASE+0x02)
#define IT83XX_WUC_WUESR3     REG8(IT83XX_WUC_BASE+0x06)
#define IT83XX_WUC_WUENR3     REG8(IT83XX_WUC_BASE+0x0A)

/* --- UART --- */
#define IT83XX_UART0_BASE 0x00F02700
#define IT83XX_UART1_BASE 0x00F02800

#define IT83XX_UART_BASE(n)        CONCAT3(IT83XX_UART, n, _BASE)
#define IT83XX_UART_REG(n, offset) REG8(IT83XX_UART_BASE(n) + (offset))

#define IT83XX_UART_DLL(n)         IT83XX_UART_REG(n, 0x00)
#define IT83XX_UART_DLM(n)         IT83XX_UART_REG(n, 0x01)
#define IT83XX_UART_RBR(n)         IT83XX_UART_REG(n, 0x00)
#define IT83XX_UART_THR(n)         IT83XX_UART_REG(n, 0x00)
#define IT83XX_UART_IER(n)         IT83XX_UART_REG(n, 0x01)
#define IT83XX_UART_IIR(n)         IT83XX_UART_REG(n, 0x02)
#define IT83XX_UART_FCR(n)         IT83XX_UART_REG(n, 0x02)
#define IT83XX_UART_LCR(n)         IT83XX_UART_REG(n, 0x03)
#define IT83XX_UART_MCR(n)         IT83XX_UART_REG(n, 0x04)
#define IT83XX_UART_LSR(n)         IT83XX_UART_REG(n, 0x05)
#define IT83XX_UART_MSR(n)         IT83XX_UART_REG(n, 0x06)
#define IT83XX_UART_SCR(n)         IT83XX_UART_REG(n, 0x07)
#define IT83XX_UART_ECSMPR(n)      IT83XX_UART_REG(n, 0x08)
#define IT83XX_UART_CSSR(n)        IT83XX_UART_REG(n, 0x09)

/* --- GPIO --- */

#define IT83XX_GPIO_BASE  0x00F01600

#define IT83XX_GPIO_GCR         REG8(IT83XX_GPIO_BASE+0x00)

#define IT83XX_GPIO_GPCRA0      REG8(IT83XX_GPIO_BASE+0x10)
#define IT83XX_GPIO_GPCRA1      REG8(IT83XX_GPIO_BASE+0x11)
#define IT83XX_GPIO_GPCRA2      REG8(IT83XX_GPIO_BASE+0x12)
#define IT83XX_GPIO_GPCRA3      REG8(IT83XX_GPIO_BASE+0x13)
#define IT83XX_GPIO_GPCRA4      REG8(IT83XX_GPIO_BASE+0x14)
#define IT83XX_GPIO_GPCRA5      REG8(IT83XX_GPIO_BASE+0x15)
#define IT83XX_GPIO_GPCRA6      REG8(IT83XX_GPIO_BASE+0x16)
#define IT83XX_GPIO_GPCRA7      REG8(IT83XX_GPIO_BASE+0x17)

#define IT83XX_GPIO_GPCRF0      REG8(IT83XX_GPIO_BASE+0x38)
#define IT83XX_GPIO_GPCRF1      REG8(IT83XX_GPIO_BASE+0x39)
#define IT83XX_GPIO_GPCRF2      REG8(IT83XX_GPIO_BASE+0x3A)
#define IT83XX_GPIO_GPCRF3      REG8(IT83XX_GPIO_BASE+0x3B)
#define IT83XX_GPIO_GPCRF4      REG8(IT83XX_GPIO_BASE+0x3C)
#define IT83XX_GPIO_GPCRF5      REG8(IT83XX_GPIO_BASE+0x3D)
#define IT83XX_GPIO_GPCRF6      REG8(IT83XX_GPIO_BASE+0x3E)
#define IT83XX_GPIO_GPCRF7      REG8(IT83XX_GPIO_BASE+0x3F)

#define IT83XX_GPIO_GPCRI0      REG8(IT83XX_GPIO_BASE+0x50)
#define IT83XX_GPIO_GPCRI1      REG8(IT83XX_GPIO_BASE+0x51)
#define IT83XX_GPIO_GPCRI2      REG8(IT83XX_GPIO_BASE+0x52)
#define IT83XX_GPIO_GPCRI3      REG8(IT83XX_GPIO_BASE+0x53)
#define IT83XX_GPIO_GPCRI4      REG8(IT83XX_GPIO_BASE+0x54)
#define IT83XX_GPIO_GPCRI5      REG8(IT83XX_GPIO_BASE+0x55)
#define IT83XX_GPIO_GPCRI6      REG8(IT83XX_GPIO_BASE+0x56)
#define IT83XX_GPIO_GPCRI7      REG8(IT83XX_GPIO_BASE+0x57)

#define IT83XX_GPIO_GRC1        REG8(IT83XX_GPIO_BASE+0xF0)
#define IT83XX_GPIO_GRC2        REG8(IT83XX_GPIO_BASE+0xF1)
#define IT83XX_GPIO_GRC3        REG8(IT83XX_GPIO_BASE+0xF2)
#define IT83XX_GPIO_GRC4        REG8(IT83XX_GPIO_BASE+0xF3)
#define IT83XX_GPIO_GRC5        REG8(IT83XX_GPIO_BASE+0xF4)
#define IT83XX_GPIO_GRC6        REG8(IT83XX_GPIO_BASE+0xF5)
#define IT83XX_GPIO_GRC7        REG8(IT83XX_GPIO_BASE+0xF6)
#define IT83XX_GPIO_GRC8        REG8(IT83XX_GPIO_BASE+0xF7)

#define IT83XX_GPIO_DATA_BASE        (IT83XX_GPIO_BASE + 0x00)
#define IT83XX_GPIO_OUTPUT_TYPE_BASE (IT83XX_GPIO_BASE + 0x70)

enum {
	GPIO_A = 0x1,
	GPIO_B = 0x2,
	GPIO_C = 0x3,
	GPIO_D = 0x4,
	GPIO_E = 0x5,
	GPIO_F = 0x6,
	GPIO_G = 0x7,
	GPIO_H = 0x8,
	GPIO_I = 0x9,
	GPIO_J = 0xa,
	GPIO_M = 0xd,
};
#define DUMMY_GPIO_BANK GPIO_A

#define IT83XX_GPIO_DATA(port)     REG8(IT83XX_GPIO_DATA_BASE + port)
#define IT83XX_GPIO_GPOT(port)     REG8(IT83XX_GPIO_OUTPUT_TYPE_BASE + port)
#define IT83XX_GPIO_CTRL(port_offset, pin_offset) \
	REG8(IT83XX_GPIO_BASE + port_offset + pin_offset)

/* --- Clock and Power Management (ECPM) --- */

#define IT83XX_ECPM_BASE  0x00F01E00

#define IT83XX_ECPM_CGCTRL1R_OFF 0x01
#define IT83XX_ECPM_CGCTRL2R_OFF 0x02
#define IT83XX_ECPM_CGCTRL3R_OFF 0x05
#define IT83XX_ECPM_CGCTRL4R_OFF 0x09

#define IT83XX_ECPM_PLLCTRL	REG8(IT83XX_ECPM_BASE+0x03)
#define IT83XX_ECPM_AUTOCG	REG8(IT83XX_ECPM_BASE+0x04)
#define IT83XX_ECPM_PLLFREQR	REG8(IT83XX_ECPM_BASE+0x06)
#define IT83XX_ECPM_PLLCSS	REG8(IT83XX_ECPM_BASE+0x08)
#define IT83XX_ECPM_SCDCR0	REG8(IT83XX_ECPM_BASE+0x0c)
#define IT83XX_ECPM_SCDCR1	REG8(IT83XX_ECPM_BASE+0x0d)
#define IT83XX_ECPM_SCDCR2	REG8(IT83XX_ECPM_BASE+0x0e)
#define IT83XX_ECPM_SCDCR3	REG8(IT83XX_ECPM_BASE+0x0f)

/*
 * The clock gate offsets combine the register offset from ECPM_BASE and the
 * mask within that register into one value. These are used for
 * clock_enable_peripheral() and clock_disable_peripheral()
 */
enum clock_gate_offsets {
	CGC_OFFSET_EGPC  = ((IT83XX_ECPM_CGCTRL2R_OFF << 8) | 0x40),
	CGC_OFFSET_CIR   = ((IT83XX_ECPM_CGCTRL2R_OFF << 8) | 0x20),
	CGC_OFFSET_SWUC  = ((IT83XX_ECPM_CGCTRL2R_OFF << 8) | 0x10),
	CGC_OFFSET_USB   = ((IT83XX_ECPM_CGCTRL3R_OFF << 8) | 0x20),
	CGC_OFFSET_PECI  = ((IT83XX_ECPM_CGCTRL3R_OFF << 8) | 0x08),
	CGC_OFFSET_UART  = ((IT83XX_ECPM_CGCTRL3R_OFF << 8) | 0x04),
	CGC_OFFSET_SSPI  = ((IT83XX_ECPM_CGCTRL3R_OFF << 8) | 0x02),
	CGC_OFFSET_DBGR  = ((IT83XX_ECPM_CGCTRL3R_OFF << 8) | 0x01),
	CGC_OFFSET_SMB   = ((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x02),
	CGC_OFFSET_CEC   = ((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x01)
};

/* --- Timer (TMR) --- */
#define IT83XX_TMR_BASE         0x00F02900

#define IT83XX_TMR_PRSC         REG8(IT83XX_TMR_BASE+0x00)
#define IT83XX_TMR_GCSMS        REG8(IT83XX_TMR_BASE+0x01)
#define IT83XX_TMR_CTR_A0       REG8(IT83XX_TMR_BASE+0x02)
#define IT83XX_TMR_CTR_A1       REG8(IT83XX_TMR_BASE+0x03)
#define IT83XX_TMR_CTR_B0       REG8(IT83XX_TMR_BASE+0x04)
#define IT83XX_TMR_CTR_B1       REG8(IT83XX_TMR_BASE+0x05)
#define IT83XX_TMR_DCR_A0       REG8(IT83XX_TMR_BASE+0x06)
#define IT83XX_TMR_DCR_A1       REG8(IT83XX_TMR_BASE+0x07)
#define IT83XX_TMR_DCR_B0       REG8(IT83XX_TMR_BASE+0x08)
#define IT83XX_TMR_DCR_B1       REG8(IT83XX_TMR_BASE+0x09)
#define IT83XX_TMR_CCGSR        REG8(IT83XX_TMR_BASE+0x0A)
#define IT83XX_TMR_TMRCE        REG8(IT83XX_TMR_BASE+0x0B)
#define IT83XX_TMR_TMRIE        REG8(IT83XX_TMR_BASE+0x0C)

/* --- External Timer and Watchdog (ETWD) --- */
#define IT83XX_ETWD_BASE  0x00F01F00

#define IT83XX_ETWD_ETWCFG        REG8(IT83XX_ETWD_BASE+0x01)
#define IT83XX_ETWD_ET1PSR        REG8(IT83XX_ETWD_BASE+0x02)
#define IT83XX_ETWD_ET1CNTLHR     REG8(IT83XX_ETWD_BASE+0x03)
#define IT83XX_ETWD_ET1CNTLLR     REG8(IT83XX_ETWD_BASE+0x04)
#define IT83XX_ETWD_ETWCTRL       REG8(IT83XX_ETWD_BASE+0x05)
#define IT83XX_ETWD_EWDCNTLLR     REG8(IT83XX_ETWD_BASE+0x06)
#define IT83XX_ETWD_EWDKEYR       REG8(IT83XX_ETWD_BASE+0x07)
#define IT83XX_ETWD_EWDCNTLHR     REG8(IT83XX_ETWD_BASE+0x09)
#define IT83XX_ETWD_ET3CTRL       REG8(IT83XX_ETWD_BASE+0x10)
#define IT83XX_ETWD_ET3PSR        REG8(IT83XX_ETWD_BASE+0x11)
#define IT83XX_ETWD_ET3CNTLLR     REG8(IT83XX_ETWD_BASE+0x14)
#define IT83XX_ETWD_ET3CNTLHR     REG8(IT83XX_ETWD_BASE+0x15)
#define IT83XX_ETWD_ET3CNTLH2R    REG8(IT83XX_ETWD_BASE+0x16)
#define IT83XX_ETWD_ETXCTRL(n)    REG8(IT83XX_ETWD_BASE + 0x10 + (n << 3))
#define IT83XX_ETWD_ETXPSR(n)     REG8(IT83XX_ETWD_BASE + 0x11 + (n << 3))
#define IT83XX_ETWD_ETXCNTLLR(n)  REG8(IT83XX_ETWD_BASE + 0x14 + (n << 3))
#define IT83XX_ETWD_ETXCNTLHR(n)  REG8(IT83XX_ETWD_BASE + 0x15 + (n << 3))
#define IT83XX_ETWD_ETXCNTLH2R(n) REG8(IT83XX_ETWD_BASE + 0x16 + (n << 3))

/* --- General Control (GCTRL) --- */
#define IT83XX_GCTRL_BASE 0x00F02000

#define IT83XX_GCTRL_WNCKR     REG8(IT83XX_GCTRL_BASE+0x0B)
#define IT83XX_GCTRL_RSTS      REG8(IT83XX_GCTRL_BASE+0x06)
#define IT83XX_GCTRL_BADRSEL   REG8(IT83XX_GCTRL_BASE+0x0A)
#define IT83XX_GCTRL_RSTC4     REG8(IT83XX_GCTRL_BASE+0x11)
#define IT83XX_GCTRL_MCCR2     REG8(IT83XX_GCTRL_BASE+0x44)

/* --- Pulse Width Modulation (PWM) --- */
#define IT83XX_PWM_BASE   0x00F01800

#define IT83XX_PWM_C0CPRS       REG8(IT83XX_PWM_BASE+0x00)
#define IT83XX_PWM_CTR          REG8(IT83XX_PWM_BASE+0x01)
#define IT83XX_PWM_DCR0         REG8(IT83XX_PWM_BASE+0x02)
#define IT83XX_PWM_DCR1         REG8(IT83XX_PWM_BASE+0x03)
#define IT83XX_PWM_DCR2         REG8(IT83XX_PWM_BASE+0x04)
#define IT83XX_PWM_DCR3         REG8(IT83XX_PWM_BASE+0x05)
#define IT83XX_PWM_DCR4         REG8(IT83XX_PWM_BASE+0x06)
#define IT83XX_PWM_DCR5         REG8(IT83XX_PWM_BASE+0x07)
#define IT83XX_PWM_DCR6         REG8(IT83XX_PWM_BASE+0x08)
#define IT83XX_PWM_DCR7         REG8(IT83XX_PWM_BASE+0x09)
#define IT83XX_PWM_PWMPOL       REG8(IT83XX_PWM_BASE+0x0A)
#define IT83XX_PWM_PCFSR        REG8(IT83XX_PWM_BASE+0x0B)
#define IT83XX_PWM_PCSSGL       REG8(IT83XX_PWM_BASE+0x0C)
#define IT83XX_PWM_PCSSGH       REG8(IT83XX_PWM_BASE+0x0D)
#define IT83XX_PWM_CR256PCSSG   REG8(IT83XX_PWM_BASE+0x0E)
#define IT83XX_PWM_PCSGR        REG8(IT83XX_PWM_BASE+0x0F)
#define IT83XX_PWM_F1TLRR       REG8(IT83XX_PWM_BASE+0x1E)
#define IT83XX_PWM_F1TMRR       REG8(IT83XX_PWM_BASE+0x1F)
#define IT83XX_PWM_F2TLRR       REG8(IT83XX_PWM_BASE+0x20)
#define IT83XX_PWM_F2TMRR       REG8(IT83XX_PWM_BASE+0x21)
#define IT83XX_PWM_ZINTSCR      REG8(IT83XX_PWM_BASE+0x22)
#define IT83XX_PWM_ZTIER        REG8(IT83XX_PWM_BASE+0x23)
#define IT83XX_PWM_TSWCTLR      REG8(IT83XX_PWM_BASE+0x24)
#define IT83XX_PWM_C4CPRS       REG8(IT83XX_PWM_BASE+0x27)
#define IT83XX_PWM_C4MCPRS      REG8(IT83XX_PWM_BASE+0x28)
#define IT83XX_PWM_C6CPRS       REG8(IT83XX_PWM_BASE+0x2B)
#define IT83XX_PWM_C6MCPRS      REG8(IT83XX_PWM_BASE+0x2C)
#define IT83XX_PWM_C7CPRS       REG8(IT83XX_PWM_BASE+0x2D)
#define IT83XX_PWM_C7MCPRS      REG8(IT83XX_PWM_BASE+0x2E)
#define IT83XX_PWM_CLK6MSEL     REG8(IT83XX_PWM_BASE+0x40)
#define IT83XX_PWM_CTR1         REG8(IT83XX_PWM_BASE+0x41)
#define IT83XX_PWM_CTR2         REG8(IT83XX_PWM_BASE+0x42)
#define IT83XX_PWM_CTR3         REG8(IT83XX_PWM_BASE+0x43)
#define IT83XX_PWM_PWM5TOCTRL   REG8(IT83XX_PWM_BASE+0x44)
#define IT83XX_PWM_CFLRR        REG8(IT83XX_PWM_BASE+0x45)
#define IT83XX_PWM_CFMRR        REG8(IT83XX_PWM_BASE+0x46)
#define IT83XX_PWM_CFINTCTRL    REG8(IT83XX_PWM_BASE+0x47)
#define IT83XX_PWM_TSWCTRL      REG8(IT83XX_PWM_BASE+0x48)
#define IT83XX_PWM_PWMODENR     REG8(IT83XX_PWM_BASE+0x49)

/* Analog to Digital Converter (ADC) */
#define IT83XX_ADC_BASE   0x00F01900

#define IT83XX_ADC_ADCSTS       REG8(IT83XX_ADC_BASE+0x00)
#define IT83XX_ADC_ADCCFG       REG8(IT83XX_ADC_BASE+0x01)
#define IT83XX_ADC_ADCCTL       REG8(IT83XX_ADC_BASE+0x02)
#define IT83XX_ADC_ADCGCR       REG8(IT83XX_ADC_BASE+0x03)
#define IT83XX_ADC_VCH0CTL      REG8(IT83XX_ADC_BASE+0x04)
#define IT83XX_ADC_KDCTL        REG8(IT83XX_ADC_BASE+0x05)
#define IT83XX_ADC_VCH1CTL      REG8(IT83XX_ADC_BASE+0x06)
#define IT83XX_ADC_VCH1DATL     REG8(IT83XX_ADC_BASE+0x07)
#define IT83XX_ADC_VCH1DATM     REG8(IT83XX_ADC_BASE+0x08)
#define IT83XX_ADC_VCH2CTL      REG8(IT83XX_ADC_BASE+0x09)
#define IT83XX_ADC_VCH2DATL     REG8(IT83XX_ADC_BASE+0x0A)
#define IT83XX_ADC_VCH2DATM     REG8(IT83XX_ADC_BASE+0x0B)
#define IT83XX_ADC_VCH3CTL      REG8(IT83XX_ADC_BASE+0x0C)
#define IT83XX_ADC_VCH3DATL     REG8(IT83XX_ADC_BASE+0x0D)
#define IT83XX_ADC_VCH3DATM     REG8(IT83XX_ADC_BASE+0x0E)
#define IT83XX_ADC_VHSCDBL      REG8(IT83XX_ADC_BASE+0x14)
#define IT83XX_ADC_VHSCDBM      REG8(IT83XX_ADC_BASE+0x15)
#define IT83XX_ADC_VCH0DATL     REG8(IT83XX_ADC_BASE+0x18)
#define IT83XX_ADC_VCH0DATM     REG8(IT83XX_ADC_BASE+0x19)
#define IT83XX_ADC_VHSGCDBL     REG8(IT83XX_ADC_BASE+0x1C)
#define IT83XX_ADC_VHSGCDBM     REG8(IT83XX_ADC_BASE+0x1D)
#define IT83XX_ADC_ADCSAR       REG8(IT83XX_ADC_BASE+0x32)
#define IT83XX_ADC_VCMPSCP      REG8(IT83XX_ADC_BASE+0x37)
#define IT83XX_ADC_VCH4CTL      REG8(IT83XX_ADC_BASE+0x38)
#define IT83XX_ADC_VCH4DATM     REG8(IT83XX_ADC_BASE+0x39)
#define IT83XX_ADC_VCH4DATL     REG8(IT83XX_ADC_BASE+0x3A)
#define IT83XX_ADC_VCH5CTL      REG8(IT83XX_ADC_BASE+0x3B)
#define IT83XX_ADC_VCH5DATM     REG8(IT83XX_ADC_BASE+0x3C)
#define IT83XX_ADC_VCH5DATL     REG8(IT83XX_ADC_BASE+0x3D)
#define IT83XX_ADC_VCH6CTL      REG8(IT83XX_ADC_BASE+0x3E)
#define IT83XX_ADC_VCH6DATM     REG8(IT83XX_ADC_BASE+0x3F)
#define IT83XX_ADC_VCH6DATL     REG8(IT83XX_ADC_BASE+0x40)
#define IT83XX_ADC_VCH7CTL      REG8(IT83XX_ADC_BASE+0x41)
#define IT83XX_ADC_VCH7DATM     REG8(IT83XX_ADC_BASE+0x42)
#define IT83XX_ADC_VCH7DATL     REG8(IT83XX_ADC_BASE+0x43)
#define IT83XX_ADC_ADCDVSTS     REG8(IT83XX_ADC_BASE+0x44)
#define IT83XX_ADC_VCMPSTS      REG8(IT83XX_ADC_BASE+0x45)
#define IT83XX_ADC_VCMP0CTL     REG8(IT83XX_ADC_BASE+0x46)
#define IT83XX_ADC_CMP0THRDATM  REG8(IT83XX_ADC_BASE+0x47)
#define IT83XX_ADC_CMP0THRDATL  REG8(IT83XX_ADC_BASE+0x48)
#define IT83XX_ADC_VCMP1CTL     REG8(IT83XX_ADC_BASE+0x49)
#define IT83XX_ADC_CMP1THRDATM  REG8(IT83XX_ADC_BASE+0x4A)
#define IT83XX_ADC_CMP1THRDATL  REG8(IT83XX_ADC_BASE+0x4B)
#define IT83XX_ADC_VCMP2CTL     REG8(IT83XX_ADC_BASE+0x4C)
#define IT83XX_ADC_CMP2THRDATM  REG8(IT83XX_ADC_BASE+0x4D)
#define IT83XX_ADC_CMP2THRDATL  REG8(IT83XX_ADC_BASE+0x4E)

/* Keyboard Controller (KBC) */
#define IT83XX_KBC_BASE   0x00F01300

#define IT83XX_KBC_KBHICR       REG8(IT83XX_KBC_BASE+0x00)
#define IT83XX_KBC_KBIRQR       REG8(IT83XX_KBC_BASE+0x02)
#define IT83XX_KBC_KBHISR       REG8(IT83XX_KBC_BASE+0x04)
#define IT83XX_KBC_KBHIKDOR     REG8(IT83XX_KBC_BASE+0x06)
#define IT83XX_KBC_KBHIMDOR     REG8(IT83XX_KBC_BASE+0x08)
#define IT83XX_KBC_KBHIDIR      REG8(IT83XX_KBC_BASE+0x0A)

/* Power Management Channel (PMC) */
#define IT83XX_PMC_BASE   0x00F01500

#define IT83XX_PMC_PM1STS       REG8(IT83XX_PMC_BASE+0x00)
#define IT83XX_PMC_PM1DO        REG8(IT83XX_PMC_BASE+0x01)
#define IT83XX_PMC_PM1DOSCI     REG8(IT83XX_PMC_BASE+0x02)
#define IT83XX_PMC_PM1DOSMI     REG8(IT83XX_PMC_BASE+0x03)
#define IT83XX_PMC_PM1DI        REG8(IT83XX_PMC_BASE+0x04)
#define IT83XX_PMC_PM1DISCI     REG8(IT83XX_PMC_BASE+0x05)
#define IT83XX_PMC_PM1CTL       REG8(IT83XX_PMC_BASE+0x06)
#define IT83XX_PMC_PM1IC        REG8(IT83XX_PMC_BASE+0x07)
#define IT83XX_PMC_PM1IE        REG8(IT83XX_PMC_BASE+0x08)
#define IT83XX_PMC_PM2STS       REG8(IT83XX_PMC_BASE+0x10)
#define IT83XX_PMC_PM2DO        REG8(IT83XX_PMC_BASE+0x11)
#define IT83XX_PMC_PM2DOSCI     REG8(IT83XX_PMC_BASE+0x12)
#define IT83XX_PMC_PM2DOSMI     REG8(IT83XX_PMC_BASE+0x13)
#define IT83XX_PMC_PM2DI        REG8(IT83XX_PMC_BASE+0x14)
#define IT83XX_PMC_PM2DISCI     REG8(IT83XX_PMC_BASE+0x15)
#define IT83XX_PMC_PM2CTL       REG8(IT83XX_PMC_BASE+0x16)
#define IT83XX_PMC_PM2IC        REG8(IT83XX_PMC_BASE+0x17)
#define IT83XX_PMC_PM2IE        REG8(IT83XX_PMC_BASE+0x18)
#define IT83XX_PMC_PM3STS       REG8(IT83XX_PMC_BASE+0x20)
#define IT83XX_PMC_PM3DO        REG8(IT83XX_PMC_BASE+0x21)
#define IT83XX_PMC_PM3DI        REG8(IT83XX_PMC_BASE+0x22)
#define IT83XX_PMC_PM3CTL       REG8(IT83XX_PMC_BASE+0x23)
#define IT83XX_PMC_PM3IC        REG8(IT83XX_PMC_BASE+0x24)
#define IT83XX_PMC_PM3IE        REG8(IT83XX_PMC_BASE+0x25)
#define IT83XX_PMC_PM4STS       REG8(IT83XX_PMC_BASE+0x30)
#define IT83XX_PMC_PM4DO        REG8(IT83XX_PMC_BASE+0x31)
#define IT83XX_PMC_PM4DI        REG8(IT83XX_PMC_BASE+0x32)
#define IT83XX_PMC_PM4CTL       REG8(IT83XX_PMC_BASE+0x33)
#define IT83XX_PMC_PM4IC        REG8(IT83XX_PMC_BASE+0x34)
#define IT83XX_PMC_PM4IE        REG8(IT83XX_PMC_BASE+0x35)
#define IT83XX_PMC_PM5STS       REG8(IT83XX_PMC_BASE+0x40)
#define IT83XX_PMC_PM5DO        REG8(IT83XX_PMC_BASE+0x41)
#define IT83XX_PMC_PM5DI        REG8(IT83XX_PMC_BASE+0x42)
#define IT83XX_PMC_PM5CTL       REG8(IT83XX_PMC_BASE+0x43)
#define IT83XX_PMC_PM5IC        REG8(IT83XX_PMC_BASE+0x44)
#define IT83XX_PMC_PM5IE        REG8(IT83XX_PMC_BASE+0x45)
#define IT83XX_PMC_MBXCTRL      REG8(IT83XX_PMC_BASE+0x19)
#define IT83XX_PMC_MBXEC_00     REG8(IT83XX_PMC_BASE+0xF0)
#define IT83XX_PMC_MBXEC_01     REG8(IT83XX_PMC_BASE+0xF1)
#define IT83XX_PMC_MBXEC_02     REG8(IT83XX_PMC_BASE+0xF2)
#define IT83XX_PMC_MBXEC_03     REG8(IT83XX_PMC_BASE+0xF3)
#define IT83XX_PMC_MBXEC_04     REG8(IT83XX_PMC_BASE+0xF4)
#define IT83XX_PMC_MBXEC_05     REG8(IT83XX_PMC_BASE+0xF5)
#define IT83XX_PMC_MBXEC_06     REG8(IT83XX_PMC_BASE+0xF6)
#define IT83XX_PMC_MBXEC_07     REG8(IT83XX_PMC_BASE+0xF7)
#define IT83XX_PMC_MBXEC_08     REG8(IT83XX_PMC_BASE+0xF8)
#define IT83XX_PMC_MBXEC_09     REG8(IT83XX_PMC_BASE+0xF9)
#define IT83XX_PMC_MBXEC_10     REG8(IT83XX_PMC_BASE+0xFA)
#define IT83XX_PMC_MBXEC_11     REG8(IT83XX_PMC_BASE+0xFB)
#define IT83XX_PMC_MBXEC_12     REG8(IT83XX_PMC_BASE+0xFC)
#define IT83XX_PMC_MBXEC_13     REG8(IT83XX_PMC_BASE+0xFD)
#define IT83XX_PMC_MBXEC_14     REG8(IT83XX_PMC_BASE+0xFE)
#define IT83XX_PMC_MBXEC_15     REG8(IT83XX_PMC_BASE+0xFF)
#define IT83XX_PMC_PMSTS(ch)    REG8(IT83XX_PMC_BASE + 0x00 + (ch << 4))
#define IT83XX_PMC_PMDO(ch)     REG8(IT83XX_PMC_BASE + 0x01 + (ch << 4))
#define IT83XX_PMC_PMDI(ch)     \
REG8(IT83XX_PMC_BASE + (ch > LPC_PM2 ? 2 : 4) + (ch << 4))
#define IT83XX_PMC_PMCTL(ch)     \
REG8(IT83XX_PMC_BASE + (ch > LPC_PM2 ? 3 : 6) + (ch << 4))

/* Keyboard Matrix Scan control (KBS) */
#define IT83XX_KBS_BASE   0x00F01D00

#define IT83XX_KBS_KSOL         REG8(IT83XX_KBS_BASE+0x00)
#define IT83XX_KBS_KSOH1        REG8(IT83XX_KBS_BASE+0x01)
#define IT83XX_KBS_KSOCTRL      REG8(IT83XX_KBS_BASE+0x02)
#define IT83XX_KBS_KSOH2        REG8(IT83XX_KBS_BASE+0x03)
#define IT83XX_KBS_KSI          REG8(IT83XX_KBS_BASE+0x04)
#define IT83XX_KBS_KSICTRL      REG8(IT83XX_KBS_BASE+0x05)
#define IT83XX_KBS_KSIGCTRL     REG8(IT83XX_KBS_BASE+0x06)
#define IT83XX_KBS_KSIGOEN      REG8(IT83XX_KBS_BASE+0x07)
#define IT83XX_KBS_KSIGDAT      REG8(IT83XX_KBS_BASE+0x08)
#define IT83XX_KBS_KSIGDMRR     REG8(IT83XX_KBS_BASE+0x09)
#define IT83XX_KBS_KSOHGCTRL    REG8(IT83XX_KBS_BASE+0x0A)
#define IT83XX_KBS_KSOHGOEN     REG8(IT83XX_KBS_BASE+0x0B)
#define IT83XX_KBS_KSOHGDMRR    REG8(IT83XX_KBS_BASE+0x0C)
#define IT83XX_KBS_KSOLGCTRL    REG8(IT83XX_KBS_BASE+0x0D)
#define IT83XX_KBS_KSOLGOEN     REG8(IT83XX_KBS_BASE+0x0E)
#define IT83XX_KBS_KSOLGDMRR    REG8(IT83XX_KBS_BASE+0x0F)
#define IT83XX_KBS_KSO0LSDR     REG8(IT83XX_KBS_BASE+0x10)
#define IT83XX_KBS_KSO1LSDR     REG8(IT83XX_KBS_BASE+0x11)
#define IT83XX_KBS_KSO2LSDR     REG8(IT83XX_KBS_BASE+0x12)
#define IT83XX_KBS_KSO3LSDR     REG8(IT83XX_KBS_BASE+0x13)
#define IT83XX_KBS_KSO4LSDR     REG8(IT83XX_KBS_BASE+0x14)
#define IT83XX_KBS_KSO5LSDR     REG8(IT83XX_KBS_BASE+0x15)
#define IT83XX_KBS_KSO6LSDR     REG8(IT83XX_KBS_BASE+0x16)
#define IT83XX_KBS_KSO7LSDR     REG8(IT83XX_KBS_BASE+0x17)
#define IT83XX_KBS_KSO8LSDR     REG8(IT83XX_KBS_BASE+0x18)
#define IT83XX_KBS_KSO9LSDR     REG8(IT83XX_KBS_BASE+0x19)
#define IT83XX_KBS_KSO10LSDR    REG8(IT83XX_KBS_BASE+0x1A)
#define IT83XX_KBS_KSO11LSDR    REG8(IT83XX_KBS_BASE+0x1B)
#define IT83XX_KBS_KSO12LSDR    REG8(IT83XX_KBS_BASE+0x1C)
#define IT83XX_KBS_KSO13LSDR    REG8(IT83XX_KBS_BASE+0x1D)
#define IT83XX_KBS_KSO14LSDR    REG8(IT83XX_KBS_BASE+0x1E)
#define IT83XX_KBS_KSO15LSDR    REG8(IT83XX_KBS_BASE+0x1F)
#define IT83XX_KBS_KSO16LSDR    REG8(IT83XX_KBS_BASE+0x20)
#define IT83XX_KBS_KSO17LSDR    REG8(IT83XX_KBS_BASE+0x21)
#define IT83XX_KBS_SDC1R        REG8(IT83XX_KBS_BASE+0x22)
#define IT83XX_KBS_SDC2R        REG8(IT83XX_KBS_BASE+0x23)
#define IT83XX_KBS_SDC3R        REG8(IT83XX_KBS_BASE+0x24)
#define IT83XX_KBS_SDSR         REG8(IT83XX_KBS_BASE+0x25)

/* Shared Memory Flash Interface Bridge (SMFI) */
#define IT83XX_SMFI_BASE  0x00F01000

#define IT83XX_SMFI_HRAMWC      REG8(IT83XX_SMFI_BASE+0x5A)
#define IT83XX_SMFI_HRAMW0BA    REG8(IT83XX_SMFI_BASE+0x5B)
#define IT83XX_SMFI_HRAMW1BA    REG8(IT83XX_SMFI_BASE+0x5C)
#define IT83XX_SMFI_HRAMW0AAS   REG8(IT83XX_SMFI_BASE+0x5D)
#define IT83XX_SMFI_HRAMW1AAS   REG8(IT83XX_SMFI_BASE+0x5E)
#define IT83XX_SMFI_HRAMW2BA    REG8(IT83XX_SMFI_BASE+0x76)
#define IT83XX_SMFI_HRAMW3BA    REG8(IT83XX_SMFI_BASE+0x77)
#define IT83XX_SMFI_HRAMW2AAS   REG8(IT83XX_SMFI_BASE+0x78)
#define IT83XX_SMFI_HRAMW3AAS   REG8(IT83XX_SMFI_BASE+0x79)
#define IT83XX_SMFI_H2RAMECSIE  REG8(IT83XX_SMFI_BASE+0x7A)
#define IT83XX_SMFI_H2RAMECSA   REG8(IT83XX_SMFI_BASE+0x7B)
#define IT83XX_SMFI_H2RAMHSS    REG8(IT83XX_SMFI_BASE+0x7C)

/* Serial Peripheral Interface (SSPI) */
#define IT83XX_SSPI_BASE  0x00F02600

#define IT83XX_SSPI_SPIDATA     REG8(IT83XX_SSPI_BASE+0x00)
#define IT83XX_SSPI_SPICTRL1    REG8(IT83XX_SSPI_BASE+0x01)
#define IT83XX_SSPI_SPICTRL2    REG8(IT83XX_SSPI_BASE+0x02)
#define IT83XX_SSPI_SPISTS      REG8(IT83XX_SSPI_BASE+0x03)
#define IT83XX_SSPI_SPICTRL3    REG8(IT83XX_SSPI_BASE+0x04)

/* Platform Environment Control Interface (PECI) */
#define IT83XX_PECI_BASE  0x00F02C00

#define IT83XX_PECI_HOSTAR      REG8(IT83XX_PECI_BASE+0x00)
#define IT83XX_PECI_HOCTLR      REG8(IT83XX_PECI_BASE+0x01)
#define IT83XX_PECI_HOCMDR      REG8(IT83XX_PECI_BASE+0x02)
#define IT83XX_PECI_HOTRADDR    REG8(IT83XX_PECI_BASE+0x03)
#define IT83XX_PECI_HOWRLR      REG8(IT83XX_PECI_BASE+0x04)
#define IT83XX_PECI_HORDLR      REG8(IT83XX_PECI_BASE+0x05)
#define IT83XX_PECI_HOWRDR      REG8(IT83XX_PECI_BASE+0x06)
#define IT83XX_PECI_HORDDR      REG8(IT83XX_PECI_BASE+0x07)
#define IT83XX_PECI_HOCTL2R     REG8(IT83XX_PECI_BASE+0x08)
#define IT83XX_PECI_RWFCSV      REG8(IT83XX_PECI_BASE+0x09)
#define IT83XX_PECI_RRFCSV      REG8(IT83XX_PECI_BASE+0x0A)
#define IT83XX_PECI_WFCSV       REG8(IT83XX_PECI_BASE+0x0B)
#define IT83XX_PECI_RFCSV       REG8(IT83XX_PECI_BASE+0x0C)
#define IT83XX_PECI_AWFCSV      REG8(IT83XX_PECI_BASE+0x0D)
#define IT83XX_PECI_PADCTLR     REG8(IT83XX_PECI_BASE+0x0E)

/* --- MISC (not implemented yet) --- */

#define IT83XX_PS2_BASE   0x00F01700
#define IT83XX_DAC_BASE   0x00F01A00
#define IT83XX_WUC_BASE   0x00F01B00
#define IT83XX_SMB_BASE   0x00F01C00
#define IT83XX_EGPIO_BASE 0x00F02100
#define IT83XX_BRAM_BASE  0x00F02200
#define IT83XX_CIR_BASE   0x00F02300
#define IT83XX_DBGR_BASE  0x00F02500
#define IT83XX_OW_BASE    0x00F02A00
#define IT83XX_I2C_BASE   0x00F02D00
#define IT83XX_CEC_BASE   0x00F02E00
#define IT83XX_USB_BASE   0x00F02F00

#endif /* __CROS_EC_REGISTERS_H */
