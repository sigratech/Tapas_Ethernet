/*
***************************************************************************
***************************************************************************
(C) 2016 SIGRA Technologies GmbH  All rights reserved.

All data and information contained in or disclosed by this document is
confidential and proprietary information of SIGRA Technologies GmbH and all
rights therein are expressly reserved.  By accepting this material the
recipient agrees that this material and the information contained therein
is held in confidence and in trust and will not be used, copied, reproduced
in whole or in part, nor its contents revealed in any manner to others
without the express written permission of SIGRA Technologies GmbH

SIGRA Technologies GmbH
Agnes-Pockels-Bogen 1,
80992, Munich,
Germany

File Name: rte.h
Author: TAPAS Generated 
E-mail: info@sigratech.de  
***************************************************************************
***************************************************************************
*/
#ifndef RTE_H
#define RTE_H

#include "lib_types.h"
#include <stdlib.h>

/* TAPAS services includes */
#include "ecu.h"
#include "os.h"

#define RTE_MUTEX_FREE                                          (0)
#define RTE_MUTEX_BUSY                                          (1)

#define RTE_LOG_NO                                              (0)
#define RTE_LOG_YES                                             (1)


#define RTE_DATA_NUM                                                       (294)

#define RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT                              (0)
#define RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND                       (1)
#define RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC                          (2)
#define RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND                       (3)
#define RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC                          (4)
#define RTE_DATA_ID_ACP_COMBINEDFAULT                                      (5)
#define RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND                               (6)
#define RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC                                  (7)
#define RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND                               (8)
#define RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC                                  (9)
#define RTE_DATA_ID_TST_PEDALPOSITION2                                     (10)
#define RTE_DATA_ID_TST_PEDALPOSITION1                                     (11)
#define RTE_DATA_ID_ACP_PEDALPOSITION                                      (12)
#define RTE_DATA_ID_TST_MPV_NO_FAN                                         (13)
#define RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT                                  (14)
#define RTE_DATA_ID_COM_WARNING_ACC                                        (15)
#define RTE_DATA_ID_COM_FAULT_ACC                                          (16)
#define RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON                               (17)
#define RTE_DATA_ID_COM_AIRCON_VCU_STATE                                   (18)
#define RTE_DATA_ID_SYS_ENABLE_ACC                                         (19)
#define RTE_DATA_ID_BAT_SOC                                                (20)
#define RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON                             (21)
#define RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION                               (22)
#define RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1                               (23)
#define RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION                               (24)
#define RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST                        (25)
#define RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL                              (26)
#define RTE_DATA_ID_GER_GEARSTATE                                          (27)
#define RTE_DATA_ID_ACC_COMMWARNING                                        (28)
#define RTE_DATA_ID_ACC_COMMFAULT                                          (29)
#define RTE_DATA_ID_ACC_STATE                                              (30)
#define RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC                            (31)
#define RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING                           (32)
#define RTE_DATA_ID_ACC_HEATER_ENABLE                                      (33)
#define RTE_DATA_ID_ACC_AIRCON_ENABLE                                      (34)
#define RTE_DATA_ID_ACC_FAULT_AIRCON                                       (35)
#define RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED                        (36)
#define RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT                              (37)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT                           (38)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT                               (39)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT                           (40)
#define RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS                           (41)
#define RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC                             (42)
#define RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION                            (43)
#define RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY                         (44)
#define RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION                        (45)
#define RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM                        (46)
#define RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE                                  (47)
#define RTE_DATA_ID_COM_BMS_VCU_BATSTATUS                                  (48)
#define RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT                                  (49)
#define RTE_DATA_ID_COM_WARNING_BAT                                        (50)
#define RTE_DATA_ID_COM_FAULT_BAT                                          (51)
#define RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2                              (52)
#define RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1                              (53)
#define RTE_DATA_ID_SYS_STATE                                              (54)
#define RTE_DATA_ID_SYS_ENABLE_BAT                                         (55)
#define RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT                            (56)
#define RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE                                (57)
#define RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8                        (58)
#define RTE_DATA_ID_COM_BMS_VCU_TOTALVOL                                   (59)
#define RTE_DATA_ID_COM_BMS_VCU_BATFAILURE                                 (60)
#define RTE_DATA_ID_COM_BMS_VCU_SOC                                        (61)
#define RTE_DATA_ID_BAT_BATTERYDISCHARGE                                   (62)
#define RTE_DATA_ID_BAT_BATTERYOFF                                         (63)
#define RTE_DATA_ID_BAT_BATTERYCHARGING                                    (64)
#define RTE_DATA_ID_BAT_COMMFAULT                                          (65)
#define RTE_DATA_ID_BAT_COMMWARNING                                        (66)
#define RTE_DATA_ID_BAT_INTERNFAULTS1                                      (67)
#define RTE_DATA_ID_BAT_INTERNFAULTS2                                      (68)
#define RTE_DATA_ID_BMS_ALLOW2CHARGE                                       (69)
#define RTE_DATA_ID_BMS_HV_VOLTAGE                                         (70)
#define RTE_DATA_ID_BAT_STATE                                              (71)
#define RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE                              (72)
#define RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE                                (73)
#define RTE_DATA_ID_BAT_VCU_DVD_SOCLOW                                     (74)
#define RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE                            (75)
#define RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW                                    (76)
#define RTE_DATA_ID_SYS_ENABLE_BRK                                         (77)
#define RTE_DATA_ID_BRK_VACUUMPUMPFAULT                                    (78)
#define RTE_DATA_ID_BRK_VACUUMWARNING                                      (79)
#define RTE_DATA_ID_BRK_HANDBRAKEPRESSED                                   (80)
#define RTE_DATA_ID_BRK_FOOTBRAKEPRESSED                                   (81)
#define RTE_DATA_ID_BRK_VACUUMLEVEL                                        (82)
#define RTE_DATA_ID_BRK_PUMPCOMMAND                                        (83)
#define RTE_DATA_ID_DCC_STATE                                              (84)
#define RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT                   (85)
#define RTE_DATA_ID_DCC_HV_VOLTAGE                                         (86)
#define RTE_DATA_ID_SYS_ENABLE_CHR                                         (87)
#define RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY                                (88)
#define RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE                                (89)
#define RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE                                    (90)
#define RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE                            (91)
#define RTE_DATA_ID_CHR_RUNSUBSTATE                                        (92)
#define RTE_DATA_ID_CHR_STATE                                              (93)
#define RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT                           (94)
#define RTE_DATA_ID_CHR_OVERVOLTAGE                                        (95)
#define RTE_DATA_ID_CHR_PLUGDETECTED                                       (96)
#define RTE_DATA_ID_CHR_FASTCHARGESTATUS                                   (97)
#define RTE_DATA_ID_CHR_SLOWCHARGESTATUS                                   (98)
#define RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC                            (99)
#define RTE_DATA_ID_CHR_VCU_BMS_CHARGERC                                   (100)
#define RTE_DATA_ID_DSH_RPM                                                (101)
#define RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL                            (102)
#define RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED                               (103)
#define RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL                          (104)
#define RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE                               (105)
#define RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS                           (106)
#define RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS                        (107)
#define RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE                           (108)
#define RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN                        (109)
#define RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED                                 (110)
#define RTE_DATA_ID_DSH_BMSFAULT                                           (111)
#define RTE_DATA_ID_GER_GEARFAULT                                          (112)
#define RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT                                 (113)
#define RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT                             (114)
#define RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT                                (115)
#define RTE_DATA_ID_MCU_PRECHARGEFAULT                                     (116)
#define RTE_DATA_ID_KEY_FAULT                                              (117)
#define RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT                                 (118)
#define RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS                             (119)
#define RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI                         (120)
#define RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST                             (121)
#define RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS                                  (122)
#define RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE                                (123)
#define RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE                      (124)
#define RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS                            (125)
#define RTE_DATA_ID_COL_VCU_DASH_PUMPS                                     (126)
#define RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN                              (127)
#define RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN                             (128)
#define RTE_DATA_ID_COL_VCU_DASH_FANFAILURE                                (129)
#define RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE                                (130)
#define RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL                              (131)
#define RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV                         (132)
#define RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW                              (133)
#define RTE_DATA_ID_DASH_ACCELSHORT2POWER                                  (134)
#define RTE_DATA_ID_DASH_ACCELSHORT2GROUND                                 (135)
#define RTE_DATA_ID_DASH_ACCELPERFALARM                                    (136)
#define RTE_DATA_ID_DASH_ACCELOC                                           (137)
#define RTE_DATA_ID_DASH_ECOMODE                                           (138)
#define RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE                          (139)
#define RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST                           (140)
#define RTE_DATA_ID_DASH_SYSTEM_STATUS                                     (141)
#define RTE_DATA_ID_PST_VCU_PS_SPEED                                       (142)
#define RTE_DATA_ID_PST_VCU_PS_ENABLE                                      (143)
#define RTE_DATA_ID_SYS_CARSTATUS                                          (144)
#define RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND                            (145)
#define RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL                                (146)
#define RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT                             (147)
#define RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT                                (148)
#define RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND                              (149)
#define RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM                           (150)
#define RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE                                (151)
#define RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED                             (152)
#define RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE                                (153)
#define RTE_DATA_ID_MCU_VCU_MCU_ENABLE                                     (154)
#define RTE_DATA_ID_MCU_VCU_MCU_K2STATUS                                   (155)
#define RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS                              (156)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL                                 (157)
#define RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST                          (158)
#define RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT                            (159)
#define RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST                          (160)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE                       (161)
#define RTE_DATA_ID_COM_FAULT_DCC                                          (162)
#define RTE_DATA_ID_COM_WARNING_DCC                                        (163)
#define RTE_DATA_ID_COM_FAULT_MCU                                          (164)
#define RTE_DATA_ID_COM_WARNING_MCU                                        (165)
#define RTE_DATA_ID_COM_FAULT_PST                                          (166)
#define RTE_DATA_ID_COM_WARNING_PST                                        (167)
#define RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP                           (168)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP                                  (169)
#define RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL                             (170)
#define RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC                               (171)
#define RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL                             (172)
#define RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE                              (173)
#define RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION                               (174)
#define RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION                               (175)
#define RTE_DATA_ID_COM_DCDC_VCU_STATUS                                    (176)
#define RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL                                (177)
#define RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE                         (178)
#define RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS                                (179)
#define RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION                          (180)
#define RTE_DATA_ID_COM_MCU_VCU_IDLE                                       (181)
#define RTE_DATA_ID_COM_MCU_VCU_MODECONTROL                                (182)
#define RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS                             (183)
#define RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL                                  (184)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ                          (185)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR                          (186)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP                        (187)
#define RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER                              (188)
#define RTE_DATA_ID_COM_MCU_VCU_MCUTEMP                                    (189)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORRPM                                   (190)
#define RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2                             (191)
#define RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS                            (192)
#define RTE_DATA_ID_TST_WATERPUMPDUTY                                      (193)
#define RTE_DATA_ID_TST_WATERPUMPDUTYSW                                    (194)
#define RTE_DATA_ID_SYS_ENABLE_COL                                         (195)
#define RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT                       (196)
#define RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT                            (197)
#define RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT                         (198)
#define RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT                     (199)
#define RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT                   (200)
#define RTE_DATA_ID_COL_STATE                                              (201)
#define RTE_DATA_ID_COL_HIGHSPEEDFAN                                       (202)
#define RTE_DATA_ID_COL_LOWSPEEDFAN                                        (203)
#define RTE_DATA_ID_COL_WATERPUMP_FAULT                                    (204)
#define RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT                               (205)
#define RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT                           (206)
#define RTE_DATA_ID_MCU_RPM                                                (207)
#define RTE_DATA_ID_DRV_TORQUESP                                           (208)
#define RTE_DATA_ID_SYS_ENABLE_DSH                                         (209)
#define RTE_DATA_ID_SYS_INITFAULT                                          (210)
#define RTE_DATA_ID_DCC_COMMFAULT                                          (211)
#define RTE_DATA_ID_MCU_COMMWARNING                                        (212)
#define RTE_DATA_ID_PST_COMMFAULT                                          (213)
#define RTE_DATA_ID_DCC_COMMWARNING                                        (214)
#define RTE_DATA_ID_MCU_COMMFAULT                                          (215)
#define RTE_DATA_ID_PST_COMMWARNING                                        (216)
#define RTE_DATA_ID_SYS_MGRRUNSTATE                                        (217)
#define RTE_DATA_ID_KEY_POSITION                                           (218)
#define RTE_DATA_ID_DRV_ECOMODEON                                          (219)
#define RTE_DATA_ID_MCU_VEHICLESPEED                                       (220)
#define RTE_DATA_ID_DSH_STATE                                              (221)
#define RTE_DATA_ID_DSH_PWR2_RELAY                                         (222)
#define RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS                                 (223)
#define RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP                                (224)
#define RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT                                  (225)
#define RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT                         (226)
#define RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT                                (227)
#define RTE_DATA_ID_SYS_ENABLE_DCC                                         (228)
#define RTE_DATA_ID_DCC_PWR1_RELAYREQUEST                                  (229)
#define RTE_DATA_ID_DCC_INTERNALVOLTAGE                                    (230)
#define RTE_DATA_ID_DCC_INTERNFAULT                                        (231)
#define RTE_DATA_ID_DCC_LV_VOLTAGE                                         (232)
#define RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE                                (233)
#define RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE                                (234)
#define RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION                                (235)
#define RTE_DATA_ID_DRV_PEDALMASSFACTOR                                    (236)
#define RTE_DATA_ID_DRV_DISTANCEDRIVEN                                     (237)
#define RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED                                (238)
#define RTE_DATA_ID_DRV_TST_TORQUESP                                       (239)
#define RTE_DATA_ID_FLT_CLR_KEY_FAULT                                      (240)
#define RTE_DATA_ID_FLT_CLR_GER_GEARFAULT                                  (241)
#define RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT                             (242)
#define RTE_DATA_ID_SYS_DEINITFAULT                                        (243)
#define RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT                                (244)
#define RTE_DATA_ID_SYS_WATCHDOGFAULT                                      (245)
#define RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT                              (246)
#define RTE_DATA_ID_FLT_CLR_SYS_INITFAULT                                  (247)
#define RTE_DATA_ID_PS_INTERNFAULTS1                                       (248)
#define RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1                               (249)
#define RTE_DATA_ID_PS_INTERNFAULTS2                                       (250)
#define RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2                               (251)
#define RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING                                (252)
#define RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING                                (253)
#define RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING                                (254)
#define RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING                                (255)
#define RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT                                  (256)
#define RTE_DATA_ID_FLT_CLR_PST_COMMWARNING                                (257)
#define RTE_DATA_ID_FLT_CLR_PST_COMMFAULT                                  (258)
#define RTE_DATA_ID_SYS_HISIDEDRIVERFAULT                                  (259)
#define RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT                          (260)
#define RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT                                  (261)
#define RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT                          (262)
#define RTE_DATA_ID_SYS_ENABLE_MCU                                         (263)
#define RTE_DATA_ID_MCU_MOTORSTOPPED                                       (264)
#define RTE_DATA_ID_MCU_STATE                                              (265)
#define RTE_DATA_ID_SYS_ENABLE_PST                                         (266)
#define RTE_DATA_ID_PST_STATE                                              (267)
#define RTE_DATA_ID_SYS_ENABLE_KEY                                         (268)
#define RTE_DATA_ID_DCC_PWR1                                               (269)
#define RTE_DATA_ID_TEST_OUT_SLOPE_MODE                                    (270)
#define RTE_DATA_ID_TEST_ANLG_24V_SUPPLY                                   (271)
#define RTE_DATA_ID_TEST_ANLG_12V_SUPPLY                                   (272)
#define RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING                             (273)
#define RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING                             (274)
#define RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY                                   (275)
#define RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP                                  (276)
#define RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2                                   (277)
#define RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC                               (278)
#define RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1                                   (279)
#define RTE_DATA_ID_TEST_ANLG_FAN_POS                                      (280)
#define RTE_DATA_ID_TEST_OUT_CABIN_HEATER                                  (281)
#define RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK                                (282)
#define RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT                              (283)
#define RTE_DATA_ID_TEST_OUT_HAND_BRAKE                                    (284)
#define RTE_DATA_ID_TEST_OUT_FOOT_BRAKE                                    (285)
#define RTE_DATA_ID_TEST_OUT_KEY_ACC                                       (286)
#define RTE_DATA_ID_TEST_OUT_AIR_CON_REQ                                   (287)
#define RTE_DATA_ID_TEST_OUT_GEAR_REVERSE                                  (288)
#define RTE_DATA_ID_TEST_OUT_KEY_START                                     (289)
#define RTE_DATA_ID_TEST_OUT_GEAR_DRIVE                                    (290)
#define RTE_DATA_ID_TEST_OUT_KEY_ON                                        (291)
#define RTE_DATA_ID_TEST_OUT_ECO                                           (292)
#define RTE_DATA_ID_TEST_OUT_ESTOP                                         (293)


typedef struct RTE_strDataTemplate
{
	/* Data ID */
	uint16_t u8IdData;
	/* Data */
	float fltData;
	/* Access Mutex */
	uint32_t u32AccessMutex;
	/* Log Flag */
	uint8_t u8FlagLog;
} RTE_strData_t;


/* RTE Sender Receiver Bus Declaration */
extern RTE_strData_t RTE_astrData[RTE_DATA_NUM];


/* RTE Sender Receiver Interfaces Declarations */
float RTE_Read_FLT_CLR_ACP_CombinedFault(void);
void RTE_Write_FLT_CLR_ACP_CombinedFault(float fltValue);
float RTE_Read_FLT_CLR_ACP_FaultP1_Short2Ground(void);
void RTE_Write_FLT_CLR_ACP_FaultP1_Short2Ground(float fltValue);
float RTE_Read_FLT_CLR_ACP_FaultP1_Short2Vcc(void);
void RTE_Write_FLT_CLR_ACP_FaultP1_Short2Vcc(float fltValue);
float RTE_Read_FLT_CLR_ACP_FaultP2_Short2Ground(void);
void RTE_Write_FLT_CLR_ACP_FaultP2_Short2Ground(float fltValue);
float RTE_Read_FLT_CLR_ACP_FaultP2_Short2Vcc(void);
void RTE_Write_FLT_CLR_ACP_FaultP2_Short2Vcc(float fltValue);
float RTE_Read_ACP_CombinedFault(void);
void RTE_Write_ACP_CombinedFault(float fltValue);
float RTE_Read_ACP_FaultP2_Short2Ground(void);
void RTE_Write_ACP_FaultP2_Short2Ground(float fltValue);
float RTE_Read_ACP_FaultP2_Short2Vcc(void);
void RTE_Write_ACP_FaultP2_Short2Vcc(float fltValue);
float RTE_Read_ACP_FaultP1_Short2Ground(void);
void RTE_Write_ACP_FaultP1_Short2Ground(float fltValue);
float RTE_Read_ACP_FaultP1_Short2Vcc(void);
void RTE_Write_ACP_FaultP1_Short2Vcc(float fltValue);
float RTE_Read_TST_PedalPosition2(void);
void RTE_Write_TST_PedalPosition2(float fltValue);
float RTE_Read_TST_PedalPosition1(void);
void RTE_Write_TST_PedalPosition1(float fltValue);
float RTE_Read_ACP_PedalPosition(void);
void RTE_Write_ACP_PedalPosition(float fltValue);
float RTE_Read_TST_MPV_NO_FAN(void);
void RTE_Write_TST_MPV_NO_FAN(float fltValue);
float RTE_Read_FLT_CLR_ACC_CommFault(void);
void RTE_Write_FLT_CLR_ACC_CommFault(float fltValue);
float RTE_Read_COM_Warning_ACC(void);
void RTE_Write_COM_Warning_ACC(float fltValue);
float RTE_Read_COM_Fault_ACC(void);
void RTE_Write_COM_Fault_ACC(float fltValue);
float RTE_Read_FLT_CLR_ACC_Fault_AirCon(void);
void RTE_Write_FLT_CLR_ACC_Fault_AirCon(float fltValue);
float RTE_Read_COM_AirCon_VCU_State(void);
void RTE_Write_COM_AirCon_VCU_State(float fltValue);
float RTE_Read_SYS_Enable_ACC(void);
void RTE_Write_SYS_Enable_ACC(float fltValue);
float RTE_Read_BAT_Soc(void);
void RTE_Write_BAT_Soc(float fltValue);
float RTE_Read_COM_AirCon_VCU_FaultReason(void);
void RTE_Write_COM_AirCon_VCU_FaultReason(float fltValue);
float RTE_Read_COM_AirCon_VCU_SWVersion(void);
void RTE_Write_COM_AirCon_VCU_SWVersion(float fltValue);
float RTE_Read_COM_AirCon_VCU_Lifebeat1(void);
void RTE_Write_COM_AirCon_VCU_Lifebeat1(float fltValue);
float RTE_Read_COM_AirCon_VCU_HWVersion(void);
void RTE_Write_COM_AirCon_VCU_HWVersion(float fltValue);
float RTE_Read_COM_AirCon_VCU_AirConOffRequest(void);
void RTE_Write_COM_AirCon_VCU_AirConOffRequest(float fltValue);
float RTE_Read_COM_AirCon_VCU_FaultLevel(void);
void RTE_Write_COM_AirCon_VCU_FaultLevel(float fltValue);
float RTE_Read_GER_GearState(void);
void RTE_Write_GER_GearState(float fltValue);
float RTE_Read_ACC_CommWarning(void);
void RTE_Write_ACC_CommWarning(float fltValue);
float RTE_Read_ACC_CommFault(void);
void RTE_Write_ACC_CommFault(float fltValue);
float RTE_Read_ACC_State(void);
void RTE_Write_ACC_State(float fltValue);
float RTE_Read_ACC_VCU_DASH_FrontModulePTC(void);
void RTE_Write_ACC_VCU_DASH_FrontModulePTC(float fltValue);
float RTE_Read_ACC_VCU_DASH_AirConditioning(void);
void RTE_Write_ACC_VCU_DASH_AirConditioning(float fltValue);
float RTE_Read_ACC_Heater_Enable(void);
void RTE_Write_ACC_Heater_Enable(float fltValue);
float RTE_Read_ACC_AirCon_Enable(void);
void RTE_Write_ACC_AirCon_Enable(float fltValue);
float RTE_Read_ACC_Fault_AirCon(void);
void RTE_Write_ACC_Fault_AirCon(float fltValue);
float RTE_Read_ACC_VCU_DVD_ACControllerDropped(void);
void RTE_Write_ACC_VCU_DVD_ACControllerDropped(float fltValue);
float RTE_Read_ACC_VCU_DVD_UnderVolFault(void);
void RTE_Write_ACC_VCU_DVD_UnderVolFault(float fltValue);
float RTE_Read_ACC_VCU_DVD_OverheatingFault(void);
void RTE_Write_ACC_VCU_DVD_OverheatingFault(float fltValue);
float RTE_Read_ACC_VCU_DVD_OverVolFault(void);
void RTE_Write_ACC_VCU_DVD_OverVolFault(float fltValue);
float RTE_Read_ACC_VCU_DVD_OverCurrentFault(void);
void RTE_Write_ACC_VCU_DVD_OverCurrentFault(float fltValue);
float RTE_Read_ACC_VCU_DVD_FailureTestFails(void);
void RTE_Write_ACC_VCU_DVD_FailureTestFails(float fltValue);
float RTE_Read_ACC_VCU_DASH_BackModulePTC(void);
void RTE_Write_ACC_VCU_DASH_BackModulePTC(float fltValue);
float RTE_Read_ACC_VCU_AirCon_GearPosition(void);
void RTE_Write_ACC_VCU_AirCon_GearPosition(float fltValue);
float RTE_Read_ACC_VCU_AirCon_CommandValidity(void);
void RTE_Write_ACC_VCU_AirCon_CommandValidity(float fltValue);
float RTE_Read_ACC_VCU_AirCon_FrontFanPosition(void);
void RTE_Write_ACC_VCU_AirCon_FrontFanPosition(float fltValue);
float RTE_Read_ACC_VCU_AirCon_AirCompressorRPM(void);
void RTE_Write_ACC_VCU_AirCon_AirCompressorRPM(float fltValue);
float RTE_Read_ACC_VCU_AirCon_Enable(void);
void RTE_Write_ACC_VCU_AirCon_Enable(float fltValue);
float RTE_Read_COM_BMS_VCU_BatStatus(void);
void RTE_Write_COM_BMS_VCU_BatStatus(float fltValue);
float RTE_Read_FLT_CLR_BAT_CommFault(void);
void RTE_Write_FLT_CLR_BAT_CommFault(float fltValue);
float RTE_Read_COM_Warning_BAT(void);
void RTE_Write_COM_Warning_BAT(float fltValue);
float RTE_Read_COM_Fault_BAT(void);
void RTE_Write_COM_Fault_BAT(float fltValue);
float RTE_Read_FLT_CLR_BAT_InternFaultS2(void);
void RTE_Write_FLT_CLR_BAT_InternFaultS2(float fltValue);
float RTE_Read_FLT_CLR_BAT_InternFaultS1(void);
void RTE_Write_FLT_CLR_BAT_InternFaultS1(float fltValue);
float RTE_Read_SYS_State(void);
void RTE_Write_SYS_State(float fltValue);
float RTE_Read_SYS_Enable_BAT(void);
void RTE_Write_SYS_Enable_BAT(float fltValue);
float RTE_Read_COM_BMS_VCU_InsulationFault(void);
void RTE_Write_COM_BMS_VCU_InsulationFault(float fltValue);
float RTE_Read_COM_BMS_VCU_AllowCharge(void);
void RTE_Write_COM_BMS_VCU_AllowCharge(float fltValue);
float RTE_Read_COM_BMS_VCU_HighVRelayStatus_K8(void);
void RTE_Write_COM_BMS_VCU_HighVRelayStatus_K8(float fltValue);
float RTE_Read_COM_BMS_VCU_TotalVol(void);
void RTE_Write_COM_BMS_VCU_TotalVol(float fltValue);
float RTE_Read_COM_BMS_VCU_BatFailure(void);
void RTE_Write_COM_BMS_VCU_BatFailure(float fltValue);
float RTE_Read_COM_BMS_VCU_SOC(void);
void RTE_Write_COM_BMS_VCU_SOC(float fltValue);
float RTE_Read_BAT_BatteryDischarge(void);
void RTE_Write_BAT_BatteryDischarge(float fltValue);
float RTE_Read_BAT_BatteryOff(void);
void RTE_Write_BAT_BatteryOff(float fltValue);
float RTE_Read_BAT_BatteryCharging(void);
void RTE_Write_BAT_BatteryCharging(float fltValue);
float RTE_Read_BAT_CommFault(void);
void RTE_Write_BAT_CommFault(float fltValue);
float RTE_Read_BAT_CommWarning(void);
void RTE_Write_BAT_CommWarning(float fltValue);
float RTE_Read_BAT_InternFaultS1(void);
void RTE_Write_BAT_InternFaultS1(float fltValue);
float RTE_Read_BAT_InternFaultS2(void);
void RTE_Write_BAT_InternFaultS2(float fltValue);
float RTE_Read_BMS_Allow2Charge(void);
void RTE_Write_BMS_Allow2Charge(float fltValue);
float RTE_Read_BMS_HV_Voltage(void);
void RTE_Write_BMS_HV_Voltage(float fltValue);
float RTE_Read_BAT_State(void);
void RTE_Write_BAT_State(float fltValue);
float RTE_Read_BAT_VCU_DVD_TotalVolGauge(void);
void RTE_Write_BAT_VCU_DVD_TotalVolGauge(float fltValue);
float RTE_Read_BAT_VCU_DVD_AveVolGauge(void);
void RTE_Write_BAT_VCU_DVD_AveVolGauge(float fltValue);
float RTE_Read_BAT_VCU_DVD_SOCLow(void);
void RTE_Write_BAT_VCU_DVD_SOCLow(float fltValue);
float RTE_Read_BAT_VCU_DVD_SOCAlarmFailure(void);
void RTE_Write_BAT_VCU_DVD_SOCAlarmFailure(float fltValue);
float RTE_Read_BAT_VCU_DVD_SOC2Low(void);
void RTE_Write_BAT_VCU_DVD_SOC2Low(float fltValue);
float RTE_Read_SYS_Enable_BRK(void);
void RTE_Write_SYS_Enable_BRK(float fltValue);
float RTE_Read_BRK_VacuumPumpFault(void);
void RTE_Write_BRK_VacuumPumpFault(float fltValue);
float RTE_Read_BRK_VacuumWarning(void);
void RTE_Write_BRK_VacuumWarning(float fltValue);
float RTE_Read_BRK_HandBrakePressed(void);
void RTE_Write_BRK_HandBrakePressed(float fltValue);
float RTE_Read_BRK_FootBrakePressed(void);
void RTE_Write_BRK_FootBrakePressed(float fltValue);
float RTE_Read_BRK_VacuumLevel(void);
void RTE_Write_BRK_VacuumLevel(float fltValue);
float RTE_Read_BRK_PumpCommand(void);
void RTE_Write_BRK_PumpCommand(float fltValue);
float RTE_Read_DCC_State(void);
void RTE_Write_DCC_State(float fltValue);
float RTE_Read_FLT_CLR_CHR_DeltaVoltageReadingFault(void);
void RTE_Write_FLT_CLR_CHR_DeltaVoltageReadingFault(float fltValue);
float RTE_Read_DCC_HV_Voltage(void);
void RTE_Write_DCC_HV_Voltage(float fltValue);
float RTE_Read_SYS_Enable_CHR(void);
void RTE_Write_SYS_Enable_CHR(float fltValue);
float RTE_Read_FLT_SystemErrorSeverity(void);
void RTE_Write_FLT_SystemErrorSeverity(float fltValue);
float RTE_Read_FLT_CLR_CHR_Overvoltage(void);
void RTE_Write_FLT_CLR_CHR_Overvoltage(float fltValue);
float RTE_Read_CHR_PlugTypeVoltage(void);
void RTE_Write_CHR_PlugTypeVoltage(float fltValue);
float RTE_Read_CHR_VCU_BMS_DcChargerEnable(void);
void RTE_Write_CHR_VCU_BMS_DcChargerEnable(float fltValue);
float RTE_Read_CHR_RunSubState(void);
void RTE_Write_CHR_RunSubState(float fltValue);
float RTE_Read_CHR_State(void);
void RTE_Write_CHR_State(float fltValue);
float RTE_Read_CHR_DeltaVoltageReadingFault(void);
void RTE_Write_CHR_DeltaVoltageReadingFault(float fltValue);
float RTE_Read_CHR_Overvoltage(void);
void RTE_Write_CHR_Overvoltage(float fltValue);
float RTE_Read_CHR_PlugDetected(void);
void RTE_Write_CHR_PlugDetected(float fltValue);
float RTE_Read_CHR_FastChargeStatus(void);
void RTE_Write_CHR_FastChargeStatus(float fltValue);
float RTE_Read_CHR_SlowChargeStatus(void);
void RTE_Write_CHR_SlowChargeStatus(float fltValue);
float RTE_Read_CHR_VCU_BMS_PowerSupplyMaxC(void);
void RTE_Write_CHR_VCU_BMS_PowerSupplyMaxC(float fltValue);
float RTE_Read_CHR_VCU_BMS_ChargerC(void);
void RTE_Write_CHR_VCU_BMS_ChargerC(float fltValue);
float RTE_Read_DSH_Rpm(void);
void RTE_Write_DSH_Rpm(float fltValue);
float RTE_Read_DASH_VCU_DVD_DCDCAlarmLevel(void);
void RTE_Write_DASH_VCU_DVD_DCDCAlarmLevel(float fltValue);
float RTE_Read_DASH_VCU_DVD_DCDCDropped(void);
void RTE_Write_DASH_VCU_DVD_DCDCDropped(float fltValue);
float RTE_Read_DSH_VCU_DVD_VehicleFaultLevel(void);
void RTE_Write_DSH_VCU_DVD_VehicleFaultLevel(float fltValue);
float RTE_Read_DSH_VCU_DASH_VehicleMode(void);
void RTE_Write_DSH_VCU_DASH_VehicleMode(float fltValue);
float RTE_Read_DSH_VCU_DVD_FailureTestFails(void);
void RTE_Write_DSH_VCU_DVD_FailureTestFails(float fltValue);
float RTE_Read_DSH_VCU_DVD_DCDCWorkInstrucLoss(void);
void RTE_Write_DSH_VCU_DVD_DCDCWorkInstrucLoss(float fltValue);
float RTE_Read_VCU_DVD_MotorCANComuiFailure(void);
void RTE_Write_VCU_DVD_MotorCANComuiFailure(float fltValue);
float RTE_Read_DSH_VCU_DVD_CANCommuniBreakdown(void);
void RTE_Write_DSH_VCU_DVD_CANCommuniBreakdown(float fltValue);
float RTE_Read_DSH_VCU_DVD_BMSDropped(void);
void RTE_Write_DSH_VCU_DVD_BMSDropped(float fltValue);
float RTE_Read_DSH_BmsFault(void);
void RTE_Write_DSH_BmsFault(float fltValue);
float RTE_Read_GER_GearFault(void);
void RTE_Write_GER_GearFault(float fltValue);
float RTE_Read_COL_MCUTemp_High_Fault(void);
void RTE_Write_COL_MCUTemp_High_Fault(float fltValue);
float RTE_Read_COL_MCUTemp_VeryHigh_Fault(void);
void RTE_Write_COL_MCUTemp_VeryHigh_Fault(float fltValue);
float RTE_Read_DSH_VCU_DASH_MotorOverT(void);
void RTE_Write_DSH_VCU_DASH_MotorOverT(float fltValue);
float RTE_Read_MCU_PreChargeFault(void);
void RTE_Write_MCU_PreChargeFault(float fltValue);
float RTE_Read_KEY_Fault(void);
void RTE_Write_KEY_Fault(float fltValue);
float RTE_Read_DCC_LV_MinVoltageFault(void);
void RTE_Write_DCC_LV_MinVoltageFault(float fltValue);
float RTE_Read_DASH_VCU_DASH_ChargeStatus(void);
void RTE_Write_DASH_VCU_DASH_ChargeStatus(float fltValue);
float RTE_Read_MCU_VCU_MCU_K2CloseRequestVali(void);
void RTE_Write_MCU_VCU_MCU_K2CloseRequestVali(float fltValue);
float RTE_Read_MCU_VCU_MCU_K2CloseRequest(void);
void RTE_Write_MCU_VCU_MCU_K2CloseRequest(float fltValue);
float RTE_Read_DSH_VCU_DASH_DCStatus(void);
void RTE_Write_DSH_VCU_DASH_DCStatus(float fltValue);
float RTE_Read_DASH_VCU_DVD_StartState(void);
void RTE_Write_DASH_VCU_DVD_StartState(float fltValue);
float RTE_Read_DASH_VCU_DASH_BatteryUndervoltage(void);
void RTE_Write_DASH_VCU_DASH_BatteryUndervoltage(float fltValue);
float RTE_Read_DASH_VCU_DASH_BatteryStatus(void);
void RTE_Write_DASH_VCU_DASH_BatteryStatus(float fltValue);
float RTE_Read_COL_VCU_DASH_Pumps(void);
void RTE_Write_COL_VCU_DASH_Pumps(float fltValue);
float RTE_Read_DASH_VCU_DASH_LowSpeedFan(void);
void RTE_Write_DASH_VCU_DASH_LowSpeedFan(float fltValue);
float RTE_Read_DASH_VCU_DASH_HighSpeedFan(void);
void RTE_Write_DASH_VCU_DASH_HighSpeedFan(float fltValue);
float RTE_Read_COL_VCU_DASH_FanFailure(void);
void RTE_Write_COL_VCU_DASH_FanFailure(float fltValue);
float RTE_Read_DSH_VCU_DVD_PumpFailure(void);
void RTE_Write_DSH_VCU_DVD_PumpFailure(float fltValue);
float RTE_Read_DSH_VCU_DVD_VcuFaultLevel(void);
void RTE_Write_DSH_VCU_DVD_VcuFaultLevel(float fltValue);
float RTE_Read_DASH_VCU_DVD_SevereLowBatteryV(void);
void RTE_Write_DASH_VCU_DVD_SevereLowBatteryV(float fltValue);
float RTE_Read_DASH_VCU_DVD_BatteryV2Low(void);
void RTE_Write_DASH_VCU_DVD_BatteryV2Low(float fltValue);
float RTE_Read_DASH_AccelShort2Power(void);
void RTE_Write_DASH_AccelShort2Power(float fltValue);
float RTE_Read_DASH_AccelShort2Ground(void);
void RTE_Write_DASH_AccelShort2Ground(float fltValue);
float RTE_Read_DASH_AccelPerfAlarm(void);
void RTE_Write_DASH_AccelPerfAlarm(float fltValue);
float RTE_Read_DASH_AccelOC(void);
void RTE_Write_DASH_AccelOC(float fltValue);
float RTE_Read_DASH_EcoMode(void);
void RTE_Write_DASH_EcoMode(float fltValue);
float RTE_Read_MCU_VCU_MCU_CapacityDischarge(void);
void RTE_Write_MCU_VCU_MCU_CapacityDischarge(float fltValue);
float RTE_Read_MCU_VCU_MCU_SlopeStopRequest(void);
void RTE_Write_MCU_VCU_MCU_SlopeStopRequest(float fltValue);
float RTE_Read_DASH_System_Status(void);
void RTE_Write_DASH_System_Status(float fltValue);
float RTE_Read_PST_VCU_PS_Speed(void);
void RTE_Write_PST_VCU_PS_Speed(float fltValue);
float RTE_Read_PST_VCU_PS_Enable(void);
void RTE_Write_PST_VCU_PS_Enable(float fltValue);
float RTE_Read_SYS_CarStatus(void);
void RTE_Write_SYS_CarStatus(float fltValue);
float RTE_Read_MCU_VCU_MCU_InverterCommand(void);
void RTE_Write_MCU_VCU_MCU_InverterCommand(float fltValue);
float RTE_Read_MCU_VCU_MCU_ModeControl(void);
void RTE_Write_MCU_VCU_MCU_ModeControl(float fltValue);
float RTE_Read_MCU_VCU_MCU_TorqueSetpoint(void);
void RTE_Write_MCU_VCU_MCU_TorqueSetpoint(float fltValue);
float RTE_Read_MCU_VCU_MCU_RPMSetpoint(void);
void RTE_Write_MCU_VCU_MCU_RPMSetpoint(float fltValue);
float RTE_Read_MCU_VCU_MCU_DrivenCommand(void);
void RTE_Write_MCU_VCU_MCU_DrivenCommand(float fltValue);
float RTE_Read_DCC_VCU_DCDC_DCDCProtConfrim(void);
void RTE_Write_DCC_VCU_DCDC_DCDCProtConfrim(float fltValue);
float RTE_Read_DCC_VCU_DCDC_DCDCEnable(void);
void RTE_Write_DCC_VCU_DCDC_DCDCEnable(float fltValue);
float RTE_Read_DASH_VCU_DASH_VehicleSpeed(void);
void RTE_Write_DASH_VCU_DASH_VehicleSpeed(float fltValue);
float RTE_Read_DASH_VCU_DASH_GearRange(void);
void RTE_Write_DASH_VCU_DASH_GearRange(float fltValue);
float RTE_Read_MCU_VCU_MCU_Enable(void);
void RTE_Write_MCU_VCU_MCU_Enable(float fltValue);
float RTE_Read_MCU_VCU_MCU_K2Status(void);
void RTE_Write_MCU_VCU_MCU_K2Status(float fltValue);
float RTE_Read_MCU_VCU_MCU_RelayK1Status(void);
void RTE_Write_MCU_VCU_MCU_RelayK1Status(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorDCVol(void);
void RTE_Write_COM_MCU_VCU_MotorDCVol(float fltValue);
float RTE_Read_COM_MCU_VCU_MCULowVolSelftest(void);
void RTE_Write_COM_MCU_VCU_MCULowVolSelftest(float fltValue);
float RTE_Read_COM_MCU_VCU_DASH_MotorOverT(void);
void RTE_Write_COM_MCU_VCU_DASH_MotorOverT(float fltValue);
float RTE_Read_COM_DCDC_VCU_WorkInstructLost(void);
void RTE_Write_COM_DCDC_VCU_WorkInstructLost(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorCANComuiFailure(void);
void RTE_Write_COM_MCU_VCU_MotorCANComuiFailure(float fltValue);
float RTE_Read_COM_Fault_DCC(void);
void RTE_Write_COM_Fault_DCC(float fltValue);
float RTE_Read_COM_Warning_DCC(void);
void RTE_Write_COM_Warning_DCC(float fltValue);
float RTE_Read_COM_Fault_MCU(void);
void RTE_Write_COM_Fault_MCU(float fltValue);
float RTE_Read_COM_Warning_MCU(void);
void RTE_Write_COM_Warning_MCU(float fltValue);
float RTE_Read_COM_Fault_PST(void);
void RTE_Write_COM_Fault_PST(float fltValue);
float RTE_Read_COM_Warning_PST(void);
void RTE_Write_COM_Warning_PST(float fltValue);
float RTE_Read_COM_DCDC_VCU_TransformerTemp(void);
void RTE_Write_COM_DCDC_VCU_TransformerTemp(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorTemp(void);
void RTE_Write_COM_MCU_VCU_MotorTemp(float fltValue);
float RTE_Read_COM_DCDC_VCU_HVRealTimeVol(void);
void RTE_Write_COM_DCDC_VCU_HVRealTimeVol(float fltValue);
float RTE_Read_COM_DCDC_VCU_LVRealTimeC(void);
void RTE_Write_COM_DCDC_VCU_LVRealTimeC(float fltValue);
float RTE_Read_COM_DCDC_VCU_LVRealTimeVol(void);
void RTE_Write_COM_DCDC_VCU_LVRealTimeVol(float fltValue);
float RTE_Read_SIM_VCU_DVD_TotalVolGauge(void);
void RTE_Write_SIM_VCU_DVD_TotalVolGauge(float fltValue);
float RTE_Read_SIM_VCU_MCU_VCUSWVersion(void);
void RTE_Write_SIM_VCU_MCU_VCUSWVersion(float fltValue);
float RTE_Read_SIM_VCU_MCU_VCUHWVersion(void);
void RTE_Write_SIM_VCU_MCU_VCUHWVersion(float fltValue);
float RTE_Read_COM_DCDC_VCU_Status(void);
void RTE_Write_COM_DCDC_VCU_Status(float fltValue);
float RTE_Read_COM_DCDC_VCU_FaultLevel(void);
void RTE_Write_COM_DCDC_VCU_FaultLevel(float fltValue);
float RTE_Read_COM_AirCon_VCU_CompressorTempe(void);
void RTE_Write_COM_AirCon_VCU_CompressorTempe(float fltValue);
float RTE_Read_COM_MCU_VCU_ErrorStatus(void);
void RTE_Write_COM_MCU_VCU_ErrorStatus(float fltValue);
float RTE_Read_COM_MCU_VCU_RotationDirection(void);
void RTE_Write_COM_MCU_VCU_RotationDirection(float fltValue);
float RTE_Read_COM_MCU_VCU_Idle(void);
void RTE_Write_COM_MCU_VCU_Idle(float fltValue);
float RTE_Read_COM_MCU_VCU_ModeControl(void);
void RTE_Write_COM_MCU_VCU_ModeControl(float fltValue);
float RTE_Read_COM_PS_VCU_OperationStatus(void);
void RTE_Write_COM_PS_VCU_OperationStatus(float fltValue);
float RTE_Read_COM_PS_VCU_FaultLevel(void);
void RTE_Write_COM_PS_VCU_FaultLevel(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorMaxBrakeTorq(void);
void RTE_Write_COM_MCU_VCU_MotorMaxBrakeTorq(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorMaxDrivenTor(void);
void RTE_Write_COM_MCU_VCU_MotorMaxDrivenTor(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorMaxRegenerateP(void);
void RTE_Write_COM_MCU_VCU_MotorMaxRegenerateP(float fltValue);
float RTE_Read_COM_MCU_VCU_MaxDrivePower(void);
void RTE_Write_COM_MCU_VCU_MaxDrivePower(float fltValue);
float RTE_Read_COM_MCU_VCU_MCUTemp(void);
void RTE_Write_COM_MCU_VCU_MCUTemp(float fltValue);
float RTE_Read_COM_MCU_VCU_MotorRPM(void);
void RTE_Write_COM_MCU_VCU_MotorRPM(float fltValue);
float RTE_Read_COM_MCU_VCU_AllowedCloseK2(void);
void RTE_Write_COM_MCU_VCU_AllowedCloseK2(float fltValue);
float RTE_Read_COM_MCU_VCU_PrechargeStatus(void);
void RTE_Write_COM_MCU_VCU_PrechargeStatus(float fltValue);
float RTE_Read_TST_WaterPumpDuty(void);
void RTE_Write_TST_WaterPumpDuty(float fltValue);
float RTE_Read_TST_WaterPumpDutySW(void);
void RTE_Write_TST_WaterPumpDutySW(float fltValue);
float RTE_Read_SYS_Enable_COL(void);
void RTE_Write_SYS_Enable_COL(float fltValue);
float RTE_Read_FLT_CLR_COL_MotorTemp_High_Fault(void);
void RTE_Write_FLT_CLR_COL_MotorTemp_High_Fault(float fltValue);
float RTE_Read_FLT_CLR_COL_WaterPump_Fault(void);
void RTE_Write_FLT_CLR_COL_WaterPump_Fault(float fltValue);
float RTE_Read_FLT_CLR_COL_MCUTemp_High_Fault(void);
void RTE_Write_FLT_CLR_COL_MCUTemp_High_Fault(float fltValue);
float RTE_Read_FLT_CLR_COL_MCUTemp_VeryHigh_Fault(void);
void RTE_Write_FLT_CLR_COL_MCUTemp_VeryHigh_Fault(float fltValue);
float RTE_Read_FLT_CLR_COL_MotorTemp_VeryHigh_Fault(void);
void RTE_Write_FLT_CLR_COL_MotorTemp_VeryHigh_Fault(float fltValue);
float RTE_Read_COL_State(void);
void RTE_Write_COL_State(float fltValue);
float RTE_Read_COL_HighSpeedFan(void);
void RTE_Write_COL_HighSpeedFan(float fltValue);
float RTE_Read_COL_LowSpeedFan(void);
void RTE_Write_COL_LowSpeedFan(float fltValue);
float RTE_Read_COL_WaterPump_Fault(void);
void RTE_Write_COL_WaterPump_Fault(float fltValue);
float RTE_Read_COL_MotorTemp_High_Fault(void);
void RTE_Write_COL_MotorTemp_High_Fault(float fltValue);
float RTE_Read_COL_MotorTemp_VeryHigh_Fault(void);
void RTE_Write_COL_MotorTemp_VeryHigh_Fault(float fltValue);
float RTE_Read_MCU_Rpm(void);
void RTE_Write_MCU_Rpm(float fltValue);
float RTE_Read_DRV_TorqueSp(void);
void RTE_Write_DRV_TorqueSp(float fltValue);
float RTE_Read_SYS_Enable_DSH(void);
void RTE_Write_SYS_Enable_DSH(float fltValue);
float RTE_Read_SYS_InitFault(void);
void RTE_Write_SYS_InitFault(float fltValue);
float RTE_Read_DCC_CommFault(void);
void RTE_Write_DCC_CommFault(float fltValue);
float RTE_Read_MCU_CommWarning(void);
void RTE_Write_MCU_CommWarning(float fltValue);
float RTE_Read_PST_CommFault(void);
void RTE_Write_PST_CommFault(float fltValue);
float RTE_Read_DCC_CommWarning(void);
void RTE_Write_DCC_CommWarning(float fltValue);
float RTE_Read_MCU_CommFault(void);
void RTE_Write_MCU_CommFault(float fltValue);
float RTE_Read_PST_CommWarning(void);
void RTE_Write_PST_CommWarning(float fltValue);
float RTE_Read_SYS_MgrRunState(void);
void RTE_Write_SYS_MgrRunState(float fltValue);
float RTE_Read_KEY_Position(void);
void RTE_Write_KEY_Position(float fltValue);
float RTE_Read_DRV_EcoModeOn(void);
void RTE_Write_DRV_EcoModeOn(float fltValue);
float RTE_Read_MCU_VehicleSpeed(void);
void RTE_Write_MCU_VehicleSpeed(float fltValue);
float RTE_Read_DSH_State(void);
void RTE_Write_DSH_State(float fltValue);
float RTE_Read_DSH_PWR2_Relay(void);
void RTE_Write_DSH_PWR2_Relay(float fltValue);
float RTE_Read_DASH_VCU_DASH_DCStatus(void);
void RTE_Write_DASH_VCU_DASH_DCStatus(float fltValue);
float RTE_Read_DSH_VCU_DASH_VacuumPump(void);
void RTE_Write_DSH_VCU_DASH_VacuumPump(float fltValue);
float RTE_Read_FLT_CLR_DCC_CommFault(void);
void RTE_Write_FLT_CLR_DCC_CommFault(float fltValue);
float RTE_Read_FLT_CLR_DCC_LV_MinVoltageFault(void);
void RTE_Write_FLT_CLR_DCC_LV_MinVoltageFault(float fltValue);
float RTE_Read_FLT_CLR_DCC_InternFault(void);
void RTE_Write_FLT_CLR_DCC_InternFault(float fltValue);
float RTE_Read_SYS_Enable_DCC(void);
void RTE_Write_SYS_Enable_DCC(float fltValue);
float RTE_Read_DCC_PWR1_RelayRequest(void);
void RTE_Write_DCC_PWR1_RelayRequest(float fltValue);
float RTE_Read_DCC_InternalVoltage(void);
void RTE_Write_DCC_InternalVoltage(float fltValue);
float RTE_Read_DCC_InternFault(void);
void RTE_Write_DCC_InternFault(float fltValue);
float RTE_Read_DCC_LV_Voltage(void);
void RTE_Write_DCC_LV_Voltage(float fltValue);
float RTE_Read_MCU_MotorMaxRegenTorque(void);
void RTE_Write_MCU_MotorMaxRegenTorque(float fltValue);
float RTE_Read_MCU_MotorMaxDriveTorque(void);
void RTE_Write_MCU_MotorMaxDriveTorque(float fltValue);
float RTE_Read_DRV_PedalMiddlePosition(void);
void RTE_Write_DRV_PedalMiddlePosition(float fltValue);
float RTE_Read_DRV_PedalMassFactor(void);
void RTE_Write_DRV_PedalMassFactor(float fltValue);
float RTE_Read_DRV_DistanceDriven(void);
void RTE_Write_DRV_DistanceDriven(float fltValue);
float RTE_Read_DRV_TST_MaxVehicleSpeed(void);
void RTE_Write_DRV_TST_MaxVehicleSpeed(float fltValue);
float RTE_Read_DRV_TST_TorqueSp(void);
void RTE_Write_DRV_TST_TorqueSp(float fltValue);
float RTE_Read_FLT_CLR_KEY_Fault(void);
void RTE_Write_FLT_CLR_KEY_Fault(float fltValue);
float RTE_Read_FLT_CLR_GER_GearFault(void);
void RTE_Write_FLT_CLR_GER_GearFault(float fltValue);
float RTE_Read_FLT_CLR_MCU_PreChargeFault(void);
void RTE_Write_FLT_CLR_MCU_PreChargeFault(float fltValue);
float RTE_Read_SYS_DeinitFault(void);
void RTE_Write_SYS_DeinitFault(float fltValue);
float RTE_Read_FLT_CLR_SYS_DeinitFault(void);
void RTE_Write_FLT_CLR_SYS_DeinitFault(float fltValue);
float RTE_Read_SYS_WatchdogFault(void);
void RTE_Write_SYS_WatchdogFault(float fltValue);
float RTE_Read_FLT_CLR_SYS_WatchdogFault(void);
void RTE_Write_FLT_CLR_SYS_WatchdogFault(float fltValue);
float RTE_Read_FLT_CLR_SYS_InitFault(void);
void RTE_Write_FLT_CLR_SYS_InitFault(float fltValue);
float RTE_Read_PS_InternFaultS1(void);
void RTE_Write_PS_InternFaultS1(float fltValue);
float RTE_Read_FLT_CLR_PS_InternFaultS1(void);
void RTE_Write_FLT_CLR_PS_InternFaultS1(float fltValue);
float RTE_Read_PS_InternFaultS2(void);
void RTE_Write_PS_InternFaultS2(float fltValue);
float RTE_Read_FLT_CLR_PS_InternFaultS2(void);
void RTE_Write_FLT_CLR_PS_InternFaultS2(float fltValue);
float RTE_Read_FLT_CLR_ACC_CommWarning(void);
void RTE_Write_FLT_CLR_ACC_CommWarning(float fltValue);
float RTE_Read_FLT_CLR_BAT_CommWarning(void);
void RTE_Write_FLT_CLR_BAT_CommWarning(float fltValue);
float RTE_Read_FLT_CLR_DCC_CommWarning(void);
void RTE_Write_FLT_CLR_DCC_CommWarning(float fltValue);
float RTE_Read_FLT_CLR_MCU_CommWarning(void);
void RTE_Write_FLT_CLR_MCU_CommWarning(float fltValue);
float RTE_Read_FLT_CLR_MCU_CommFault(void);
void RTE_Write_FLT_CLR_MCU_CommFault(float fltValue);
float RTE_Read_FLT_CLR_PST_CommWarning(void);
void RTE_Write_FLT_CLR_PST_CommWarning(float fltValue);
float RTE_Read_FLT_CLR_PST_CommFault(void);
void RTE_Write_FLT_CLR_PST_CommFault(float fltValue);
float RTE_Read_SYS_HiSideDriverFault(void);
void RTE_Write_SYS_HiSideDriverFault(float fltValue);
float RTE_Read_FLT_CLR_SYS_HiSideDriverFault(void);
void RTE_Write_FLT_CLR_SYS_HiSideDriverFault(float fltValue);
float RTE_Read_SYS_LoSideDriverFault(void);
void RTE_Write_SYS_LoSideDriverFault(float fltValue);
float RTE_Read_FLT_CLR_SYS_LoSideDriverFault(void);
void RTE_Write_FLT_CLR_SYS_LoSideDriverFault(float fltValue);
float RTE_Read_SYS_Enable_MCU(void);
void RTE_Write_SYS_Enable_MCU(float fltValue);
float RTE_Read_MCU_MotorStopped(void);
void RTE_Write_MCU_MotorStopped(float fltValue);
float RTE_Read_MCU_State(void);
void RTE_Write_MCU_State(float fltValue);
float RTE_Read_SYS_Enable_PST(void);
void RTE_Write_SYS_Enable_PST(float fltValue);
float RTE_Read_PST_State(void);
void RTE_Write_PST_State(float fltValue);
float RTE_Read_SYS_Enable_KEY(void);
void RTE_Write_SYS_Enable_KEY(float fltValue);
float RTE_Read_DCC_PWR1(void);
void RTE_Write_DCC_PWR1(float fltValue);
float RTE_Read_Test_Out_Slope_Mode(void);
void RTE_Write_Test_Out_Slope_Mode(float fltValue);
float RTE_Read_Test_Anlg_24v_Supply(void);
void RTE_Write_Test_Anlg_24v_Supply(float fltValue);
float RTE_Read_Test_Anlg_12v_Supply(void);
void RTE_Write_Test_Anlg_12v_Supply(float fltValue);
float RTE_Read_Test_Pout_Duty_Ac_Charging(void);
void RTE_Write_Test_Pout_Duty_Ac_Charging(float fltValue);
float RTE_Read_Test_Pout_Freq_Ac_Charging(void);
void RTE_Write_Test_Pout_Freq_Ac_Charging(float fltValue);
float RTE_Read_Test_Anlg_3v3_Supply(void);
void RTE_Write_Test_Anlg_3v3_Supply(float fltValue);
float RTE_Read_Test_Anlg_Vacuum_Pump(void);
void RTE_Write_Test_Anlg_Vacuum_Pump(float fltValue);
float RTE_Read_Test_Anlg_Gas_Pedal2(void);
void RTE_Write_Test_Anlg_Gas_Pedal2(float fltValue);
float RTE_Read_Test_Anlg_Ac_Charging_CC(void);
void RTE_Write_Test_Anlg_Ac_Charging_CC(float fltValue);
float RTE_Read_Test_Anlg_Gas_Pedal1(void);
void RTE_Write_Test_Anlg_Gas_Pedal1(float fltValue);
float RTE_Read_Test_Anlg_Fan_Pos(void);
void RTE_Write_Test_Anlg_Fan_Pos(float fltValue);
float RTE_Read_Test_Out_Cabin_Heater(void);
void RTE_Write_Test_Out_Cabin_Heater(float fltValue);
float RTE_Read_Test_Out_Dc_Charge_Lock(void);
void RTE_Write_Test_Out_Dc_Charge_Lock(float fltValue);
float RTE_Read_Test_Out_Water_Pump_Fault(void);
void RTE_Write_Test_Out_Water_Pump_Fault(float fltValue);
float RTE_Read_Test_Out_Hand_Brake(void);
void RTE_Write_Test_Out_Hand_Brake(float fltValue);
float RTE_Read_Test_Out_Foot_Brake(void);
void RTE_Write_Test_Out_Foot_Brake(float fltValue);
float RTE_Read_Test_Out_Key_Acc(void);
void RTE_Write_Test_Out_Key_Acc(float fltValue);
float RTE_Read_Test_Out_Air_Con_Req(void);
void RTE_Write_Test_Out_Air_Con_Req(float fltValue);
float RTE_Read_Test_Out_Gear_Reverse(void);
void RTE_Write_Test_Out_Gear_Reverse(float fltValue);
float RTE_Read_Test_Out_Key_Start(void);
void RTE_Write_Test_Out_Key_Start(float fltValue);
float RTE_Read_Test_Out_Gear_Drive(void);
void RTE_Write_Test_Out_Gear_Drive(float fltValue);
float RTE_Read_Test_Out_Key_On(void);
void RTE_Write_Test_Out_Key_On(float fltValue);
float RTE_Read_Test_Out_Eco(void);
void RTE_Write_Test_Out_Eco(float fltValue);
float RTE_Read_Test_Out_Estop(void);
void RTE_Write_Test_Out_Estop(float fltValue);

/* RTE SWC Init */
void RTE_vdInit(void);


/* RTE SWC DeInit */
void RTE_vdDeInit(void);



/* Framework External Services Interfaces */
#define RTE_Service_COM_vdReadSignal ECU_COM_vdReadSignal
#define RTE_Service_COM_vdWriteSignal ECU_COM_vdWriteSignal
#define RTE_Service_COM_vdEnable ECU_COM_vdEnable
#define RTE_Service_ANLG_eReadSignal ECU_ANLG_eReadSignal
#define RTE_Service_IO_eOutputControl ECU_IO_eOutputControl
#define RTE_Service_IO_eInputRead ECU_IO_eInputRead
#define RTE_Service_MEM_eWriteSignalValue ECU_MEM_INT_eWriteSignalValue
#define RTE_Service_MEM_eReadSignalValue ECU_MEM_INT_eReadSignalValue
#define RTE_Service_SYS_vdShutdown ECU_SYS_vdShutdown
#define RTE_Service_IO_eReadPwm ECU_IO_eReadPwm
#define RTE_Service_IO_eSetPwm ECU_IO_eSetPwm
#define RTE_Service_SYS_vdGetResetStatus ECU_SYS_vdGetResetStatus
#define RTE_Service_SYS_vdClearResetStatus ECU_SYS_vdClearResetStatus
#define RTE_Service_IO_eInternalOutputControl ECU_IO_eInternalOutputControl

extern STATUS_t RTE_Service_COM_vdReadSignal(uint8_t u8IdSignal, float* pfltValue);
extern STATUS_t RTE_Service_COM_vdWriteSignal(uint8_t u8IdSignal, float fltValue);
extern STATUS_t RTE_Service_COM_vdEnable(uint8_t u8Enable);
extern STATUS_t RTE_Service_ANLG_eReadSignal(uint8_t u8IndexSignal, float* pfltValue);
extern STATUS_t RTE_Service_IO_eOutputControl(uint8_t u8IdOutput, ECU_IO_eOutputCommand_t eOutputCommand);
extern STATUS_t RTE_Service_IO_eInputRead(uint8_t u8IdInput, uint8_t* pu8Value);
extern STATUS_t RTE_Service_MEM_eWriteSignalValue(uint8_t u8SignalID, float fltValue, uint32_t u32Value);
extern STATUS_t RTE_Service_MEM_eReadSignalValue(uint8_t u8SignalID, float* pfltValue);
extern void RTE_Service_SYS_vdShutdown(void);
extern STATUS_t RTE_Service_IO_eReadPwm(uint8_t u8IdPin, uint32_t* pu32FreqHz, uint8_t* pu8DutyCycle);
extern STATUS_t RTE_Service_IO_eSetPwm(uint8_t u8IdPout, uint32_t u32FreqHz, uint8_t u8DutyCycle);
extern void RTE_Service_SYS_vdGetResetStatus(uint8_t* pu8IsExWdgReset);
extern void RTE_Service_SYS_vdClearResetStatus(uint8_t u8IsExWdgResetNeeded);
extern STATUS_t RTE_Service_IO_eInternalOutputControl(uint8_t u8IdOutput, ECU_IO_eOutputCommand_t eOutputCommand);

#endif /*RTE_H*/

