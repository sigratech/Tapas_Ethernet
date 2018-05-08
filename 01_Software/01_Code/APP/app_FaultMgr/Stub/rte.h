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
//#include "ecu.h"
//#include "os.h"
#include "ecu_mem_cfg.h"


#define RTE_MUTEX_FREE                                          (0)
#define RTE_MUTEX_BUSY                                          (1)

#define RTE_LOG_NO                                              (0)
#define RTE_LOG_YES                                             (1)


#define RTE_DATA_NUM                                                       (286)

#define RTE_DATA_ID_INPUTFROMANOTHERMODEL1                                 (0)
#define RTE_DATA_ID_INPUTFROMANOTHERMODEL2                                 (1)
#define RTE_DATA_ID_OUTPUTFROMANOTHERMODEL2                                (2)
#define RTE_DATA_ID_OUTPUTFROMANOTHERMODEL1                                (3)
#define RTE_DATA_ID_ACP_COMBINEDFAULT                                      (4)
#define RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND                               (5)
#define RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC                                  (6)
#define RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND                               (7)
#define RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC                                  (8)
#define RTE_DATA_ID_TST_PEDALPOSITION2                                     (9)
#define RTE_DATA_ID_TST_PEDALPOSITION1                                     (10)
#define RTE_DATA_ID_ACP_PEDALPOSITION                                      (11)
#define RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON                             (12)
#define RTE_DATA_ID_SIM_AIRCON_VCU_SWVERSION                               (13)
#define RTE_DATA_ID_SIM_AIRCON_VCU_LIFEBEAT1                               (14)
#define RTE_DATA_ID_SIM_AIRCON_VCU_HWVERSION                               (15)
#define RTE_DATA_ID_SYS_SYSSTATE                                           (16)
#define RTE_DATA_ID_COM_BMS_VCU_SOC                                        (17)
#define RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST                        (18)
#define RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL                              (19)
#define RTE_DATA_ID_DRV_VCU_DASH_GEARRANGE                                 (20)
#define RTE_DATA_ID_COM_AIRCON_VCU_STATE                                   (21)
#define RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED                        (22)
#define RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT                              (23)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT                           (24)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT                               (25)
#define RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT                           (26)
#define RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS                           (27)
#define RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC                            (28)
#define RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC                             (29)
#define RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION                            (30)
#define RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY                         (31)
#define RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION                        (32)
#define RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM                        (33)
#define RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE                                  (34)
#define RTE_DATA_ID_BRK_VACUUMPUMPFAULT                                    (35)
#define RTE_DATA_ID_BRK_VACUUMWARNING                                      (36)
#define RTE_DATA_ID_BRK_VCU_DASH_HANDBRAKE                                 (37)
#define RTE_DATA_ID_BRK_VCU_DASH_FOOTBRAKE                                 (38)
#define RTE_DATA_ID_BRK_VACUUMLEVEL                                        (39)
#define RTE_DATA_ID_BRK_PUMPCOMMAND                                        (40)
#define RTE_DATA_ID_CHR_PLUGFAULT                                          (41)
#define RTE_DATA_ID_CHR_VCU_BMS_FASTCHARGESTATUS                           (42)
#define RTE_DATA_ID_CHR_VCU_BMS_SLOWCHARGESTATUS                           (43)
#define RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC                            (44)
#define RTE_DATA_ID_CHR_VCU_BMS_CHARGERC                                   (45)
#define RTE_DATA_ID_DCC_VCU_DVD_STARTSTATE                                 (46)
#define RTE_DATA_ID_DCC_VCU_DASH_BATTERYUNDERVOLTAGE                       (47)
#define RTE_DATA_ID_DCC_VCU_DASH_BATTERYSTATUS                             (48)
#define RTE_DATA_ID_COL_VCU_DASH_LOWSPEEDFAN                               (49)
#define RTE_DATA_ID_COL_VCU_DASH_HIGHSPEEDFAN                              (50)
#define RTE_DATA_ID_COL_VCU_DASH_FANFAILURE                                (51)
#define RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP                                (52)
#define RTE_DATA_ID_COL_VCU_DVD_PUMPFAILURE                                (53)
#define RTE_DATA_ID_FLT_VCU_FAULTLEVEL                                     (54)
#define RTE_DATA_ID_DCC_VCU_DVD_SEVERELOWBATTERYV                          (55)
#define RTE_DATA_ID_BAT_VCU_DVD_SOCLOW                                     (56)
#define RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW                                    (57)
#define RTE_DATA_ID_DCC_VCU_DVD_BATTERYV2LOW                               (58)
#define RTE_DATA_ID_SIM_DCDC_VCU_TRANSFORMERTEMP                           (59)
#define RTE_DATA_ID_SIM_DCDC_VCU_LVREALTIMEVOL                             (60)
#define RTE_DATA_ID_SIM_DCDC_VCU_LVREALTIMEC                               (61)
#define RTE_DATA_ID_SIM_DCDC_VCU_HVREALTIMEVOL                             (62)
#define RTE_DATA_ID_SIM_DCDC_VCU_DSPJUNTIONTEMP                            (63)
#define RTE_DATA_ID_SIM_DCDC_VCU_DCSTA1LIFEBEAT                            (64)
#define RTE_DATA_ID_SIM_DCDC_VCU_WATERCOOLINGREQUEST                       (65)
#define RTE_DATA_ID_SIM_DCDC_VCU_DCSTA2LIFEBEAT                            (66)
#define RTE_DATA_ID_SIM_DCDC_VCU_DCDCSWVERSION                             (67)
#define RTE_DATA_ID_SIM_DCDC_VCU_DCDCHWVERSION                             (68)
#define RTE_DATA_ID_SIM_PS_VCU_SWVERSION                                   (69)
#define RTE_DATA_ID_SIM_PS_VCU_HWVERSION                                   (70)
#define RTE_DATA_ID_DASH_ACCELSHORT2POWER                                  (71)
#define RTE_DATA_ID_DASH_ACCELSHORT2GROUND                                 (72)
#define RTE_DATA_ID_DASH_ACCELPERFALARM                                    (73)
#define RTE_DATA_ID_DASH_ACCELOC                                           (74)
#define RTE_DATA_ID_DASH_ECOMODE                                           (75)
#define RTE_DATA_ID_DRV_VCU_MCU_CAPACITYDISCHARGE                          (76)
#define RTE_DATA_ID_DRV_VCU_MCU_SLOPESTOPREQUEST                           (77)
#define RTE_DATA_ID_DASH_SYSTEM_STATUS                                     (78)
#define RTE_DATA_ID_PST_VCU_PS_SPEED                                       (79)
#define RTE_DATA_ID_PST_VCU_PS_ENABLE                                      (80)
#define RTE_DATA_ID_SYS_VCU_MCU_CARSTATUS                                  (81)
#define RTE_DATA_ID_DRV_VCU_MCU_INVERTERCOMMAND                            (82)
#define RTE_DATA_ID_DRV_VCU_MCU_MODECONTROL                                (83)
#define RTE_DATA_ID_DRV_VCU_MCU_TORQUESETPOINT                             (84)
#define RTE_DATA_ID_DRV_VCU_MCU_RPMSETPOINT                                (85)
#define RTE_DATA_ID_DRV_VCU_MCU_DRIVENCOMMAND                              (86)
#define RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM                           (87)
#define RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE                                (88)
#define RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED                             (89)
#define RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE                                (90)
#define RTE_DATA_ID_DRV_VCU_MCU_ENABLE                                     (91)
#define RTE_DATA_ID_DRV_VCU_MCU_K2STATUS                                   (92)
#define RTE_DATA_ID_DRV_VCU_MCU_RELAYK1STATUS                              (93)
#define RTE_DATA_ID_TEST_SYSTEM_IN                                         (94)
#define RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION                               (95)
#define RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION                               (96)
#define RTE_DATA_ID_SIM_VCU_DASH_VEHICLEMODE                               (97)
#define RTE_DATA_ID_SIM_VCU_DVD_STARTSTATE                                 (98)
#define RTE_DATA_ID_SIM_VCU_DASH_BATTERYUNDERVOLTAGE                       (99)
#define RTE_DATA_ID_SIM_VCU_DASH_BATTERYSTATUS                             (100)
#define RTE_DATA_ID_SIM_VCU_DASH_PUMPS                                     (101)
#define RTE_DATA_ID_SIM_VCU_DASH_HANDBRAKE                                 (102)
#define RTE_DATA_ID_SIM_VCU_DASH_FOOTBRAKE                                 (103)
#define RTE_DATA_ID_SIM_VCU_DASH_ACCELPEDALPERCENTAGE                      (104)
#define RTE_DATA_ID_SIM_VCU_DASH_FRONTMODULEPTC                            (105)
#define RTE_DATA_ID_SIM_VCU_DASH_BACKMODULEPTC                             (106)
#define RTE_DATA_ID_SIM_VCU_DASH_LOWSPEEDFAN                               (107)
#define RTE_DATA_ID_SIM_VCU_DASH_HIGHSPEEDFAN                              (108)
#define RTE_DATA_ID_SIM_VCU_DASH_FANFAILURE                                (109)
#define RTE_DATA_ID_SIM_VCU_DASH_VACUUMPUMPFAILURE                         (110)
#define RTE_DATA_ID_SIM_VCU_DASH_VACUUMPUMP                                (111)
#define RTE_DATA_ID_SIM_VCU_DASH_VACUUMFAILURE                             (112)
#define RTE_DATA_ID_SIM_VCU_DASH_VACUUMLEVEL                               (113)
#define RTE_DATA_ID_COM_DCDC_VCU_STATUS                                    (114)
#define RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL                                (115)
#define RTE_DATA_ID_SIM_VCU_DASH_PUMPFAILURE                               (116)
#define RTE_DATA_ID_SIM_VCU_DVD_VCUFAULTLEVEL                              (117)
#define RTE_DATA_ID_SIM_VCU_DVD_VEHICLEFAULTLEVEL                          (118)
#define RTE_DATA_ID_SIM_VCU_DVD_VACCUMALARM                                (119)
#define RTE_DATA_ID_SIM_VCU_DVD_SOCALARMFAILURE                            (120)
#define RTE_DATA_ID_SIM_VCU_DVD_SEVERELOWBATTERYV                          (121)
#define RTE_DATA_ID_SIM_VCU_DVD_SOCLOW                                     (122)
#define RTE_DATA_ID_SIM_VCU_DVD_SOC2LOW                                    (123)
#define RTE_DATA_ID_SIM_VCU_DVD_PUMPFAILURE                                (124)
#define RTE_DATA_ID_SIM_VCU_DVD_DCDCDROPPED                                (125)
#define RTE_DATA_ID_SIM_VCU_DVD_DCDCALARMLEVEL                             (126)
#define RTE_DATA_ID_SIM_VCU_DVD_CHARGERDROPPED                             (127)
#define RTE_DATA_ID_SIM_VCU_DVD_BATTERYV2LOW                               (128)
#define RTE_DATA_ID_SIM_VCU_DVD_POWERBATTERYV2LOW                          (129)
#define RTE_DATA_ID_SIM_VCU_DVD_ACALARMLEVEL                               (130)
#define RTE_DATA_ID_COM_VCU_DVD_ACALARMLEVEL                               (131)
#define RTE_DATA_ID_SIM_VCU_DVD_TEMPSENSORALARM                            (132)
#define RTE_DATA_ID_SIM_VCU_DVD_TEMP2HIGH                                  (133)
#define RTE_DATA_ID_SIM_VCU_DVD_OUTPUTSC                                   (134)
#define RTE_DATA_ID_SIM_VCU_DVD_LOWVOLLOWER                                (135)
#define RTE_DATA_ID_SIM_VCU_DVD_LOWVOL2LOW                                 (136)
#define RTE_DATA_ID_SIM_VCU_DVD_LOWSIDECSENSORFAULT                        (137)
#define RTE_DATA_ID_SIM_VCU_DVD_INTERLOCKFAULT                             (138)
#define RTE_DATA_ID_SIM_VCU_DVD_HIGHVOLLOWER                               (139)
#define RTE_DATA_ID_SIM_VCU_DVD_HIGHVOL2HIGH                               (140)
#define RTE_DATA_ID_SIM_VCU_DVD_FAIL2STOP                                  (141)
#define RTE_DATA_ID_SIM_VCU_DVD_FAIL2RUN                                   (142)
#define RTE_DATA_ID_SIM_VCU_DVD_DCDCWORKINSTRUCLOSS                        (143)
#define RTE_DATA_ID_SIM_VCU_DVD_SUPPLYVOLABNORMAL                          (144)
#define RTE_DATA_ID_SIM_VCU_DVD_SELFTESTFAILURE                            (145)
#define RTE_DATA_ID_SIM_VCU_DVD_OVERLOAD                                   (146)
#define RTE_DATA_ID_SIM_VCU_DVD_OVERHEAT                                   (147)
#define RTE_DATA_ID_SIM_VCU_DVD_OVERCURRENT                                (148)
#define RTE_DATA_ID_SIM_VCU_DVD_ABNORMALPOSITION                           (149)
#define RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE                         (150)
#define RTE_DATA_ID_SIM_VCU_DVD_VEHICLEFAULTCIRCUITRES                     (151)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORRESOLVE_P                             (152)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORPHASEOVERC_P                          (153)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTOROVERLOAD_P                            (154)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTOROVERTORQUE_P                          (155)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTOROVERT_P                               (156)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTOROVERSPEED_P                           (157)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORLACKPHASE_P                           (158)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORIGBT_P                                (159)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORIGBTOVERT_P                           (160)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORHWLOSESIGNAL_P                        (161)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORDRIVERBOARDOVERT_P                    (162)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORDRIVEPOWERUNDERV_P                    (163)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORDQOVERC_P                             (164)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORCVUNDERV_P                            (165)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORCVREVERSECONN_P                       (166)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORCVOVERV_P                             (167)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORCANCOMUIFAILURE_P                     (168)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORBUSLINEUNDERV_P                       (169)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORBUSLINEOVERV_P                        (170)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORBUSLINEOVERC_P                        (171)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORBRIDGEUPDOWN_P                        (172)
#define RTE_DATA_ID_SIM_VCU_DVD_MOTORBLOCKING_P                            (173)
#define RTE_DATA_ID_SIM_VCU_DVD_DISCHARGEFAILURE                           (174)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORRESOLVE_P                            (175)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORPHASEOVERC_P                         (176)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTOROVERLOAD_P                           (177)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTOROVERTORQUE_P                         (178)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTOROVERT_P                              (179)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTOROVERSPEED_P                          (180)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORLACKPHASE_P                          (181)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORIGBT_P                               (182)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORIGBTOVERT_P                          (183)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORHWLOSESIGNAL_P                       (184)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORDRIVERBOARDOVERT_P                   (185)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORDRIVEPOWERUNDERV_P                   (186)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORDQOVERC_P                            (187)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORCVUNDERV_P                           (188)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORCVREVERSECONN_P                      (189)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORCVOVERV_P                            (190)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORCANFAILURE_P                         (191)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORBUSLINEUNDERV_P                      (192)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORBUSLINEOVERV_P                       (193)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORBUSLINEOVERC_P                       (194)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORBRIDGEUPDOWN_P                       (195)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORBLOCKING_P                           (196)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORPHASEV                               (197)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORPHASEC                               (198)
#define RTE_DATA_ID_SIM_VCU_DASH_MOTORDCV                                  (199)
#define RTE_DATA_ID_SIM_VCU_DASH_TORQUECONTROL                             (200)
#define RTE_DATA_ID_SIM_VCU_DVD_ACCELSHORT2POWER                           (201)
#define RTE_DATA_ID_SIM_VCU_DVD_ACCELSHORT2GROUND                          (202)
#define RTE_DATA_ID_SIM_VCU_DVD_ACCELPERFALARM                             (203)
#define RTE_DATA_ID_SIM_VCU_DVD_ACCELOC                                    (204)
#define RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS                                (205)
#define RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION                          (206)
#define RTE_DATA_ID_COM_MCU_VCU_IDLE                                       (207)
#define RTE_DATA_ID_COM_MCU_VCU_MODECONTROL                                (208)
#define RTE_DATA_ID_SIM_VCU_DVD_BRAKESHORT2POWER                           (209)
#define RTE_DATA_ID_SIM_VCU_DVD_BRAKESHORT2GROUND                          (210)
#define RTE_DATA_ID_SIM_VCU_DVD_BRAKEPERFALARM                             (211)
#define RTE_DATA_ID_SIM_VCU_DVD_BRAKEOC                                    (212)
#define RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS                             (213)
#define RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL                                  (214)
#define RTE_DATA_ID_COM_HIGHVRELAYSTATUS_K8                                (215)
#define RTE_DATA_ID_COM_BMS_TOTAL_VOLTAGE                                  (216)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ                          (217)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR                          (218)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP                        (219)
#define RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER                              (220)
#define RTE_DATA_ID_COM_MCU_VCU_MCUTEMP                                    (221)
#define RTE_DATA_ID_COM_MCU_VCU_MOTORRPM                                   (222)
#define RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2                             (223)
#define RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS                            (224)
#define RTE_DATA_ID_COM_TESTOUT                                            (225)
#define RTE_DATA_ID_COL_HITEMPLEVEL2                                       (226)
#define RTE_DATA_ID_COL_HITEMPLEVEL1                                       (227)
#define RTE_DATA_ID_DRV_ECOMODEON                                          (228)
#define RTE_DATA_ID_DRV_VCU_DASH_VEHICLESPEED                              (229)
#define RTE_DATA_ID_DCC_VCU_DVD_DCDCDROPPED                                (230)
#define RTE_DATA_ID_DCC_VCU_DVD_DCDCALARMLEVEL                             (231)
#define RTE_DATA_ID_DCC_VCU_DASH_DCSTATUS                                  (232)
#define RTE_DATA_ID_TDRV_PEDALMASSFACTORSW                                 (233)
#define RTE_DATA_ID_TDRV_PEDALMIDDLEPOSITIONSW                             (234)
#define RTE_DATA_ID_TDRV_PEDALMIDDLEPOSITION                               (235)
#define RTE_DATA_ID_TDRV_PEDALMASSFACTOR                                   (236)
#define RTE_DATA_ID_AATEST_FWD_SPEED_LIMIT                                 (237)
#define RTE_DATA_ID_AATEST_APPLY_SPEED_STUBS                               (238)
#define RTE_DATA_ID_FLT_FAULTLEVEL                                         (239)
#define RTE_DATA_ID_TST_DRIVINGMODE                                        (240)
#define RTE_DATA_ID_TST_ALLOW2DRIVEOUT                                     (241)
#define RTE_DATA_ID_DRV_GEAR_REVERSE                                       (242)
#define RTE_DATA_ID_DRV_GEARSTATE                                          (243)
#define RTE_DATA_ID_DRV_PRECHARGESTATE                                     (244)
#define RTE_DATA_ID_DRV_VCU_MCU_K2CLOSEREQUESTVALI                         (245)
#define RTE_DATA_ID_DRV_VCU_MCU_K2CLOSEREQUEST                             (246)
#define RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY                                (247)
#define RTE_DATA_ID_ACP_FAULT1                                             (248)
#define RTE_DATA_ID_ACP_FAULT2                                             (249)
#define RTE_DATA_ID_ACP_FAULT3                                             (250)
#define RTE_DATA_ID_FLT_ACP_FAULT1_CLEAR                                   (251)
#define RTE_DATA_ID_FLT_ACP_FAULT2_CLEAR                                   (252)
#define RTE_DATA_ID_FLT_ACP_FAULT3_CLEAR                                   (253)
#define RTE_DATA_ID_SIGNAL1                                                (254)
#define RTE_DATA_ID_SIGNAL2                                                (255)
#define RTE_DATA_ID_SIGNAL3                                                (256)
#define RTE_DATA_ID_SIGNAL4                                                (257)
#define RTE_DATA_ID_PST_READY                                              (258)
#define RTE_DATA_ID_PST_FAULTCRITICAL                                      (259)
#define RTE_DATA_ID_PST_FAULTGENERAL                                       (260)
#define RTE_DATA_ID_PST_FAULTALARM                                         (261)
#define RTE_DATA_ID_MCU_PRECHARGE                                          (262)
#define RTE_DATA_ID_TEST_PIN_DUTY_WATERPUMP                                (263)
#define RTE_DATA_ID_TEST_PIN_FREQ_WATERPUMP                                (264)
#define RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING                             (265)
#define RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING                             (266)
#define RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY                                   (267)
#define RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP                                  (268)
#define RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2                                   (269)
#define RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC                               (270)
#define RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1                                   (271)
#define RTE_DATA_ID_TEST_ANLG_FAN_POS                                      (272)
#define RTE_DATA_ID_TEST_OUT_CABIN_HEATER                                  (273)
#define RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK                                (274)
#define RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT                              (275)
#define RTE_DATA_ID_TEST_OUT_HAND_BRAKE                                    (276)
#define RTE_DATA_ID_TEST_OUT_FOOT_BRAKE                                    (277)
#define RTE_DATA_ID_TEST_OUT_KEY_ACC                                       (278)
#define RTE_DATA_ID_TEST_OUT_AIR_CON_REQ                                   (279)
#define RTE_DATA_ID_TEST_OUT_GEAR_REVERSE                                  (280)
#define RTE_DATA_ID_TEST_OUT_KEY_START                                     (281)
#define RTE_DATA_ID_TEST_OUT_GEAR_DRIVE                                    (282)
#define RTE_DATA_ID_TEST_OUT_KEY_ON                                        (283)
#define RTE_DATA_ID_TEST_OUT_ECO                                           (284)
#define RTE_DATA_ID_TEST_OUT_ESTOP                                         (285)


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
float RTE_Read_InputFromAnotherModel1(void);
void RTE_Write_InputFromAnotherModel1(float fltValue);
float RTE_Read_InputFromAnotherModel2(void);
void RTE_Write_InputFromAnotherModel2(float fltValue);
float RTE_Read_OutputFromAnotherModel2(void);
void RTE_Write_OutputFromAnotherModel2(float fltValue);
float RTE_Read_OutputFromAnotherModel1(void);
void RTE_Write_OutputFromAnotherModel1(float fltValue);
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
float RTE_Read_COM_AirCon_VCU_FaultReason(void);
void RTE_Write_COM_AirCon_VCU_FaultReason(float fltValue);
float RTE_Read_SIM_AirCon_VCU_SWVersion(void);
void RTE_Write_SIM_AirCon_VCU_SWVersion(float fltValue);
float RTE_Read_SIM_AirCon_VCU_Lifebeat1(void);
void RTE_Write_SIM_AirCon_VCU_Lifebeat1(float fltValue);
float RTE_Read_SIM_AirCon_VCU_HWVersion(void);
void RTE_Write_SIM_AirCon_VCU_HWVersion(float fltValue);
float RTE_Read_SYS_SysState(void);
void RTE_Write_SYS_SysState(float fltValue);
float RTE_Read_COM_BMS_VCU_SOC(void);
void RTE_Write_COM_BMS_VCU_SOC(float fltValue);
float RTE_Read_COM_AirCon_VCU_AirConOffRequest(void);
void RTE_Write_COM_AirCon_VCU_AirConOffRequest(float fltValue);
float RTE_Read_COM_AirCon_VCU_FaultLevel(void);
void RTE_Write_COM_AirCon_VCU_FaultLevel(float fltValue);
float RTE_Read_DRV_VCU_DASH_GearRange(void);
void RTE_Write_DRV_VCU_DASH_GearRange(float fltValue);
float RTE_Read_COM_AirCon_VCU_State(void);
void RTE_Write_COM_AirCon_VCU_State(float fltValue);
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
float RTE_Read_ACC_VCU_DASH_FrontModulePTC(void);
void RTE_Write_ACC_VCU_DASH_FrontModulePTC(float fltValue);
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
float RTE_Read_BRK_VacuumPumpFault(void);
void RTE_Write_BRK_VacuumPumpFault(float fltValue);
float RTE_Read_BRK_VacuumWarning(void);
void RTE_Write_BRK_VacuumWarning(float fltValue);
float RTE_Read_BRK_VCU_DASH_Handbrake(void);
void RTE_Write_BRK_VCU_DASH_Handbrake(float fltValue);
float RTE_Read_BRK_VCU_DASH_FootBrake(void);
void RTE_Write_BRK_VCU_DASH_FootBrake(float fltValue);
float RTE_Read_BRK_VacuumLevel(void);
void RTE_Write_BRK_VacuumLevel(float fltValue);
float RTE_Read_BRK_PumpCommand(void);
void RTE_Write_BRK_PumpCommand(float fltValue);
float RTE_Read_CHR_PlugFault(void);
void RTE_Write_CHR_PlugFault(float fltValue);
float RTE_Read_CHR_VCU_BMS_FastChargeStatus(void);
void RTE_Write_CHR_VCU_BMS_FastChargeStatus(float fltValue);
float RTE_Read_CHR_VCU_BMS_SlowChargeStatus(void);
void RTE_Write_CHR_VCU_BMS_SlowChargeStatus(float fltValue);
float RTE_Read_CHR_VCU_BMS_PowerSupplyMaxC(void);
void RTE_Write_CHR_VCU_BMS_PowerSupplyMaxC(float fltValue);
float RTE_Read_CHR_VCU_BMS_ChargerC(void);
void RTE_Write_CHR_VCU_BMS_ChargerC(float fltValue);
float RTE_Read_DCC_VCU_DVD_StartState(void);
void RTE_Write_DCC_VCU_DVD_StartState(float fltValue);
float RTE_Read_DCC_VCU_DASH_BatteryUndervoltage(void);
void RTE_Write_DCC_VCU_DASH_BatteryUndervoltage(float fltValue);
float RTE_Read_DCC_VCU_DASH_BatteryStatus(void);
void RTE_Write_DCC_VCU_DASH_BatteryStatus(float fltValue);
float RTE_Read_COL_VCU_DASH_LowSpeedFan(void);
void RTE_Write_COL_VCU_DASH_LowSpeedFan(float fltValue);
float RTE_Read_COL_VCU_DASH_HighSpeedFan(void);
void RTE_Write_COL_VCU_DASH_HighSpeedFan(float fltValue);
float RTE_Read_COL_VCU_DASH_FanFailure(void);
void RTE_Write_COL_VCU_DASH_FanFailure(float fltValue);
float RTE_Read_DSH_VCU_DASH_VacuumPump(void);
void RTE_Write_DSH_VCU_DASH_VacuumPump(float fltValue);
float RTE_Read_COL_VCU_DVD_PumpFailure(void);
void RTE_Write_COL_VCU_DVD_PumpFailure(float fltValue);
float RTE_Read_FLT_VCU_FaultLevel(void);
void RTE_Write_FLT_VCU_FaultLevel(float fltValue);
float RTE_Read_DCC_VCU_DVD_SevereLowBatteryV(void);
void RTE_Write_DCC_VCU_DVD_SevereLowBatteryV(float fltValue);
float RTE_Read_BAT_VCU_DVD_SOCLow(void);
void RTE_Write_BAT_VCU_DVD_SOCLow(float fltValue);
float RTE_Read_BAT_VCU_DVD_SOC2Low(void);
void RTE_Write_BAT_VCU_DVD_SOC2Low(float fltValue);
float RTE_Read_DCC_VCU_DVD_BatteryV2Low(void);
void RTE_Write_DCC_VCU_DVD_BatteryV2Low(float fltValue);
float RTE_Read_SIM_DCDC_VCU_TransformerTemp(void);
void RTE_Write_SIM_DCDC_VCU_TransformerTemp(float fltValue);
float RTE_Read_SIM_DCDC_VCU_LVRealTimeVol(void);
void RTE_Write_SIM_DCDC_VCU_LVRealTimeVol(float fltValue);
float RTE_Read_SIM_DCDC_VCU_LVRealTimeC(void);
void RTE_Write_SIM_DCDC_VCU_LVRealTimeC(float fltValue);
float RTE_Read_SIM_DCDC_VCU_HVRealTimeVol(void);
void RTE_Write_SIM_DCDC_VCU_HVRealTimeVol(float fltValue);
float RTE_Read_SIM_DCDC_VCU_DSPJuntionTemp(void);
void RTE_Write_SIM_DCDC_VCU_DSPJuntionTemp(float fltValue);
float RTE_Read_SIM_DCDC_VCU_DCSTA1Lifebeat(void);
void RTE_Write_SIM_DCDC_VCU_DCSTA1Lifebeat(float fltValue);
float RTE_Read_SIM_DCDC_VCU_WaterCoolingRequest(void);
void RTE_Write_SIM_DCDC_VCU_WaterCoolingRequest(float fltValue);
float RTE_Read_SIM_DCDC_VCU_DCSTA2Lifebeat(void);
void RTE_Write_SIM_DCDC_VCU_DCSTA2Lifebeat(float fltValue);
float RTE_Read_SIM_DCDC_VCU_DCDCSWVersion(void);
void RTE_Write_SIM_DCDC_VCU_DCDCSWVersion(float fltValue);
float RTE_Read_SIM_DCDC_VCU_DCDCHWVersion(void);
void RTE_Write_SIM_DCDC_VCU_DCDCHWVersion(float fltValue);
float RTE_Read_SIM_PS_VCU_SWVersion(void);
void RTE_Write_SIM_PS_VCU_SWVersion(float fltValue);
float RTE_Read_SIM_PS_VCU_HWVersion(void);
void RTE_Write_SIM_PS_VCU_HWVersion(float fltValue);
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
float RTE_Read_DRV_VCU_MCU_CapacityDischarge(void);
void RTE_Write_DRV_VCU_MCU_CapacityDischarge(float fltValue);
float RTE_Read_DRV_VCU_MCU_SlopeStopRequest(void);
void RTE_Write_DRV_VCU_MCU_SlopeStopRequest(float fltValue);
float RTE_Read_DASH_System_Status(void);
void RTE_Write_DASH_System_Status(float fltValue);
float RTE_Read_PST_VCU_PS_Speed(void);
void RTE_Write_PST_VCU_PS_Speed(float fltValue);
float RTE_Read_PST_VCU_PS_Enable(void);
void RTE_Write_PST_VCU_PS_Enable(float fltValue);
float RTE_Read_SYS_VCU_MCU_CarStatus(void);
void RTE_Write_SYS_VCU_MCU_CarStatus(float fltValue);
float RTE_Read_DRV_VCU_MCU_InverterCommand(void);
void RTE_Write_DRV_VCU_MCU_InverterCommand(float fltValue);
float RTE_Read_DRV_VCU_MCU_ModeControl(void);
void RTE_Write_DRV_VCU_MCU_ModeControl(float fltValue);
float RTE_Read_DRV_VCU_MCU_TorqueSetpoint(void);
void RTE_Write_DRV_VCU_MCU_TorqueSetpoint(float fltValue);
float RTE_Read_DRV_VCU_MCU_RPMSetpoint(void);
void RTE_Write_DRV_VCU_MCU_RPMSetpoint(float fltValue);
float RTE_Read_DRV_VCU_MCU_DrivenCommand(void);
void RTE_Write_DRV_VCU_MCU_DrivenCommand(float fltValue);
float RTE_Read_DCC_VCU_DCDC_DCDCProtConfrim(void);
void RTE_Write_DCC_VCU_DCDC_DCDCProtConfrim(float fltValue);
float RTE_Read_DCC_VCU_DCDC_DCDCEnable(void);
void RTE_Write_DCC_VCU_DCDC_DCDCEnable(float fltValue);
float RTE_Read_DASH_VCU_DASH_VehicleSpeed(void);
void RTE_Write_DASH_VCU_DASH_VehicleSpeed(float fltValue);
float RTE_Read_DASH_VCU_DASH_GearRange(void);
void RTE_Write_DASH_VCU_DASH_GearRange(float fltValue);
float RTE_Read_DRV_VCU_MCU_Enable(void);
void RTE_Write_DRV_VCU_MCU_Enable(float fltValue);
float RTE_Read_DRV_VCU_MCU_K2Status(void);
void RTE_Write_DRV_VCU_MCU_K2Status(float fltValue);
float RTE_Read_DRV_VCU_MCU_RelayK1Status(void);
void RTE_Write_DRV_VCU_MCU_RelayK1Status(float fltValue);
float RTE_Read_TEST_System_In(void);
void RTE_Write_TEST_System_In(float fltValue);
float RTE_Read_SIM_VCU_MCU_VCUSWVersion(void);
void RTE_Write_SIM_VCU_MCU_VCUSWVersion(float fltValue);
float RTE_Read_SIM_VCU_MCU_VCUHWVersion(void);
void RTE_Write_SIM_VCU_MCU_VCUHWVersion(float fltValue);
float RTE_Read_SIM_VCU_DASH_VehicleMode(void);
void RTE_Write_SIM_VCU_DASH_VehicleMode(float fltValue);
float RTE_Read_SIM_VCU_DVD_StartState(void);
void RTE_Write_SIM_VCU_DVD_StartState(float fltValue);
float RTE_Read_SIM_VCU_DASH_BatteryUndervoltage(void);
void RTE_Write_SIM_VCU_DASH_BatteryUndervoltage(float fltValue);
float RTE_Read_SIM_VCU_DASH_BatteryStatus(void);
void RTE_Write_SIM_VCU_DASH_BatteryStatus(float fltValue);
float RTE_Read_SIM_VCU_DASH_Pumps(void);
void RTE_Write_SIM_VCU_DASH_Pumps(float fltValue);
float RTE_Read_SIM_VCU_DASH_Handbrake(void);
void RTE_Write_SIM_VCU_DASH_Handbrake(float fltValue);
float RTE_Read_SIM_VCU_DASH_FootBrake(void);
void RTE_Write_SIM_VCU_DASH_FootBrake(float fltValue);
float RTE_Read_SIM_VCU_DASH_AccelPedalPercentage(void);
void RTE_Write_SIM_VCU_DASH_AccelPedalPercentage(float fltValue);
float RTE_Read_SIM_VCU_DASH_FrontModulePTC(void);
void RTE_Write_SIM_VCU_DASH_FrontModulePTC(float fltValue);
float RTE_Read_SIM_VCU_DASH_BackModulePTC(void);
void RTE_Write_SIM_VCU_DASH_BackModulePTC(float fltValue);
float RTE_Read_SIM_VCU_DASH_LowSpeedFan(void);
void RTE_Write_SIM_VCU_DASH_LowSpeedFan(float fltValue);
float RTE_Read_SIM_VCU_DASH_HighSpeedFan(void);
void RTE_Write_SIM_VCU_DASH_HighSpeedFan(float fltValue);
float RTE_Read_SIM_VCU_DASH_FanFailure(void);
void RTE_Write_SIM_VCU_DASH_FanFailure(float fltValue);
float RTE_Read_SIM_VCU_DASH_VacuumPumpFailure(void);
void RTE_Write_SIM_VCU_DASH_VacuumPumpFailure(float fltValue);
float RTE_Read_SIM_VCU_DASH_VacuumPump(void);
void RTE_Write_SIM_VCU_DASH_VacuumPump(float fltValue);
float RTE_Read_SIM_VCU_DASH_VacuumFailure(void);
void RTE_Write_SIM_VCU_DASH_VacuumFailure(float fltValue);
float RTE_Read_SIM_VCU_DASH_VacuumLevel(void);
void RTE_Write_SIM_VCU_DASH_VacuumLevel(float fltValue);
float RTE_Read_COM_DCDC_VCU_Status(void);
void RTE_Write_COM_DCDC_VCU_Status(float fltValue);
float RTE_Read_COM_DCDC_VCU_FaultLevel(void);
void RTE_Write_COM_DCDC_VCU_FaultLevel(float fltValue);
float RTE_Read_SIM_VCU_DASH_PumpFailure(void);
void RTE_Write_SIM_VCU_DASH_PumpFailure(float fltValue);
float RTE_Read_SIM_VCU_DVD_VCUFaultLevel(void);
void RTE_Write_SIM_VCU_DVD_VCUFaultLevel(float fltValue);
float RTE_Read_SIM_VCU_DVD_VehicleFaultLevel(void);
void RTE_Write_SIM_VCU_DVD_VehicleFaultLevel(float fltValue);
float RTE_Read_SIM_VCU_DVD_VaccumAlarm(void);
void RTE_Write_SIM_VCU_DVD_VaccumAlarm(float fltValue);
float RTE_Read_SIM_VCU_DVD_SOCAlarmFailure(void);
void RTE_Write_SIM_VCU_DVD_SOCAlarmFailure(float fltValue);
float RTE_Read_SIM_VCU_DVD_SevereLowBatteryV(void);
void RTE_Write_SIM_VCU_DVD_SevereLowBatteryV(float fltValue);
float RTE_Read_SIM_VCU_DVD_SOCLow(void);
void RTE_Write_SIM_VCU_DVD_SOCLow(float fltValue);
float RTE_Read_SIM_VCU_DVD_SOC2Low(void);
void RTE_Write_SIM_VCU_DVD_SOC2Low(float fltValue);
float RTE_Read_SIM_VCU_DVD_PumpFailure(void);
void RTE_Write_SIM_VCU_DVD_PumpFailure(float fltValue);
float RTE_Read_SIM_VCU_DVD_DCDCDropped(void);
void RTE_Write_SIM_VCU_DVD_DCDCDropped(float fltValue);
float RTE_Read_SIM_VCU_DVD_DCDCAlarmLevel(void);
void RTE_Write_SIM_VCU_DVD_DCDCAlarmLevel(float fltValue);
float RTE_Read_SIM_VCU_DVD_ChargerDropped(void);
void RTE_Write_SIM_VCU_DVD_ChargerDropped(float fltValue);
float RTE_Read_SIM_VCU_DVD_BatteryV2Low(void);
void RTE_Write_SIM_VCU_DVD_BatteryV2Low(float fltValue);
float RTE_Read_SIM_VCU_DVD_PowerBatteryV2Low(void);
void RTE_Write_SIM_VCU_DVD_PowerBatteryV2Low(float fltValue);
float RTE_Read_SIM_VCU_DVD_ACAlarmLevel(void);
void RTE_Write_SIM_VCU_DVD_ACAlarmLevel(float fltValue);
float RTE_Read_COM_VCU_DVD_ACAlarmLevel(void);
void RTE_Write_COM_VCU_DVD_ACAlarmLevel(float fltValue);
float RTE_Read_SIM_VCU_DVD_TempSensorAlarm(void);
void RTE_Write_SIM_VCU_DVD_TempSensorAlarm(float fltValue);
float RTE_Read_SIM_VCU_DVD_Temp2High(void);
void RTE_Write_SIM_VCU_DVD_Temp2High(float fltValue);
float RTE_Read_SIM_VCU_DVD_OutputSC(void);
void RTE_Write_SIM_VCU_DVD_OutputSC(float fltValue);
float RTE_Read_SIM_VCU_DVD_LowVolLower(void);
void RTE_Write_SIM_VCU_DVD_LowVolLower(float fltValue);
float RTE_Read_SIM_VCU_DVD_LowVol2Low(void);
void RTE_Write_SIM_VCU_DVD_LowVol2Low(float fltValue);
float RTE_Read_SIM_VCU_DVD_LowSideCSensorFault(void);
void RTE_Write_SIM_VCU_DVD_LowSideCSensorFault(float fltValue);
float RTE_Read_SIM_VCU_DVD_InterlockFault(void);
void RTE_Write_SIM_VCU_DVD_InterlockFault(float fltValue);
float RTE_Read_SIM_VCU_DVD_HighVolLower(void);
void RTE_Write_SIM_VCU_DVD_HighVolLower(float fltValue);
float RTE_Read_SIM_VCU_DVD_HighVol2High(void);
void RTE_Write_SIM_VCU_DVD_HighVol2High(float fltValue);
float RTE_Read_SIM_VCU_DVD_Fail2stop(void);
void RTE_Write_SIM_VCU_DVD_Fail2stop(float fltValue);
float RTE_Read_SIM_VCU_DVD_Fail2Run(void);
void RTE_Write_SIM_VCU_DVD_Fail2Run(float fltValue);
float RTE_Read_SIM_VCU_DVD_DCDCWorkInstrucLoss(void);
void RTE_Write_SIM_VCU_DVD_DCDCWorkInstrucLoss(float fltValue);
float RTE_Read_SIM_VCU_DVD_SupplyVolAbnormal(void);
void RTE_Write_SIM_VCU_DVD_SupplyVolAbnormal(float fltValue);
float RTE_Read_SIM_VCU_DVD_SelfTestFailure(void);
void RTE_Write_SIM_VCU_DVD_SelfTestFailure(float fltValue);
float RTE_Read_SIM_VCU_DVD_Overload(void);
void RTE_Write_SIM_VCU_DVD_Overload(float fltValue);
float RTE_Read_SIM_VCU_DVD_Overheat(void);
void RTE_Write_SIM_VCU_DVD_Overheat(float fltValue);
float RTE_Read_SIM_VCU_DVD_Overcurrent(void);
void RTE_Write_SIM_VCU_DVD_Overcurrent(float fltValue);
float RTE_Read_SIM_VCU_DVD_AbnormalPosition(void);
void RTE_Write_SIM_VCU_DVD_AbnormalPosition(float fltValue);
float RTE_Read_COM_AirCon_VCU_CompressorTempe(void);
void RTE_Write_COM_AirCon_VCU_CompressorTempe(float fltValue);
float RTE_Read_SIM_VCU_DVD_VehicleFaultCircuitRes(void);
void RTE_Write_SIM_VCU_DVD_VehicleFaultCircuitRes(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorResolve_P(void);
void RTE_Write_SIM_VCU_DVD_MotorResolve_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorPhaseOverC_P(void);
void RTE_Write_SIM_VCU_DVD_MotorPhaseOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorOverload_P(void);
void RTE_Write_SIM_VCU_DVD_MotorOverload_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorOverTorque_P(void);
void RTE_Write_SIM_VCU_DVD_MotorOverTorque_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorOverT_P(void);
void RTE_Write_SIM_VCU_DVD_MotorOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorOverSpeed_P(void);
void RTE_Write_SIM_VCU_DVD_MotorOverSpeed_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorLackphase_P(void);
void RTE_Write_SIM_VCU_DVD_MotorLackphase_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorIGBT_P(void);
void RTE_Write_SIM_VCU_DVD_MotorIGBT_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorIGBTOverT_P(void);
void RTE_Write_SIM_VCU_DVD_MotorIGBTOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorHWLoseSignal_P(void);
void RTE_Write_SIM_VCU_DVD_MotorHWLoseSignal_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorDriverBoardOverT_P(void);
void RTE_Write_SIM_VCU_DVD_MotorDriverBoardOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorDrivePowerUnderV_P(void);
void RTE_Write_SIM_VCU_DVD_MotorDrivePowerUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorDQOverC_P(void);
void RTE_Write_SIM_VCU_DVD_MotorDQOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorCVUnderV_P(void);
void RTE_Write_SIM_VCU_DVD_MotorCVUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorCVReverseConn_P(void);
void RTE_Write_SIM_VCU_DVD_MotorCVReverseConn_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorCVOverV_P(void);
void RTE_Write_SIM_VCU_DVD_MotorCVOverV_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorCANComuiFailure_P(void);
void RTE_Write_SIM_VCU_DVD_MotorCANComuiFailure_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorBusLineUnderV_P(void);
void RTE_Write_SIM_VCU_DVD_MotorBusLineUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorBusLineOverV_P(void);
void RTE_Write_SIM_VCU_DVD_MotorBusLineOverV_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorBusLineOverC_P(void);
void RTE_Write_SIM_VCU_DVD_MotorBusLineOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorBridgeUpDown_P(void);
void RTE_Write_SIM_VCU_DVD_MotorBridgeUpDown_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_MotorBlocking_P(void);
void RTE_Write_SIM_VCU_DVD_MotorBlocking_P(float fltValue);
float RTE_Read_SIM_VCU_DVD_DischargeFailure(void);
void RTE_Write_SIM_VCU_DVD_DischargeFailure(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorResolve_P(void);
void RTE_Write_SIM_VCU_DASH_MotorResolve_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorPhaseOverC_P(void);
void RTE_Write_SIM_VCU_DASH_MotorPhaseOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorOverload_P(void);
void RTE_Write_SIM_VCU_DASH_MotorOverload_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorOverTorque_P(void);
void RTE_Write_SIM_VCU_DASH_MotorOverTorque_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorOverT_P(void);
void RTE_Write_SIM_VCU_DASH_MotorOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorOverSpeed_P(void);
void RTE_Write_SIM_VCU_DASH_MotorOverSpeed_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorLackphase_P(void);
void RTE_Write_SIM_VCU_DASH_MotorLackphase_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorIGBT_P(void);
void RTE_Write_SIM_VCU_DASH_MotorIGBT_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorIGBTOverT_P(void);
void RTE_Write_SIM_VCU_DASH_MotorIGBTOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorHWLoseSignal_P(void);
void RTE_Write_SIM_VCU_DASH_MotorHWLoseSignal_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorDriverBoardOverT_P(void);
void RTE_Write_SIM_VCU_DASH_MotorDriverBoardOverT_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorDrivePowerUnderV_P(void);
void RTE_Write_SIM_VCU_DASH_MotorDrivePowerUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorDQOverC_P(void);
void RTE_Write_SIM_VCU_DASH_MotorDQOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorCVUnderV_P(void);
void RTE_Write_SIM_VCU_DASH_MotorCVUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorCVReverseConn_P(void);
void RTE_Write_SIM_VCU_DASH_MotorCVReverseConn_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorCVOverV_P(void);
void RTE_Write_SIM_VCU_DASH_MotorCVOverV_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorCANFailure_P(void);
void RTE_Write_SIM_VCU_DASH_MotorCANFailure_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorBusLineUnderV_P(void);
void RTE_Write_SIM_VCU_DASH_MotorBusLineUnderV_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorBusLineOverV_P(void);
void RTE_Write_SIM_VCU_DASH_MotorBusLineOverV_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorBusLineOverC_P(void);
void RTE_Write_SIM_VCU_DASH_MotorBusLineOverC_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorBridgeUpDown_P(void);
void RTE_Write_SIM_VCU_DASH_MotorBridgeUpDown_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorBlocking_P(void);
void RTE_Write_SIM_VCU_DASH_MotorBlocking_P(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorPhaseV(void);
void RTE_Write_SIM_VCU_DASH_MotorPhaseV(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorPhaseC(void);
void RTE_Write_SIM_VCU_DASH_MotorPhaseC(float fltValue);
float RTE_Read_SIM_VCU_DASH_MotorDCV(void);
void RTE_Write_SIM_VCU_DASH_MotorDCV(float fltValue);
float RTE_Read_SIM_VCU_DASH_TorqueControl(void);
void RTE_Write_SIM_VCU_DASH_TorqueControl(float fltValue);
float RTE_Read_SIM_VCU_DVD_AccelShort2Power(void);
void RTE_Write_SIM_VCU_DVD_AccelShort2Power(float fltValue);
float RTE_Read_SIM_VCU_DVD_AccelShort2Ground(void);
void RTE_Write_SIM_VCU_DVD_AccelShort2Ground(float fltValue);
float RTE_Read_SIM_VCU_DVD_AccelPerfAlarm(void);
void RTE_Write_SIM_VCU_DVD_AccelPerfAlarm(float fltValue);
float RTE_Read_SIM_VCU_DVD_AccelOC(void);
void RTE_Write_SIM_VCU_DVD_AccelOC(float fltValue);
float RTE_Read_COM_MCU_VCU_ErrorStatus(void);
void RTE_Write_COM_MCU_VCU_ErrorStatus(float fltValue);
float RTE_Read_COM_MCU_VCU_RotationDirection(void);
void RTE_Write_COM_MCU_VCU_RotationDirection(float fltValue);
float RTE_Read_COM_MCU_VCU_Idle(void);
void RTE_Write_COM_MCU_VCU_Idle(float fltValue);
float RTE_Read_COM_MCU_VCU_ModeControl(void);
void RTE_Write_COM_MCU_VCU_ModeControl(float fltValue);
float RTE_Read_SIM_VCU_DVD_BrakeShort2Power(void);
void RTE_Write_SIM_VCU_DVD_BrakeShort2Power(float fltValue);
float RTE_Read_SIM_VCU_DVD_BrakeShort2Ground(void);
void RTE_Write_SIM_VCU_DVD_BrakeShort2Ground(float fltValue);
float RTE_Read_SIM_VCU_DVD_BrakePerfAlarm(void);
void RTE_Write_SIM_VCU_DVD_BrakePerfAlarm(float fltValue);
float RTE_Read_SIM_VCU_DVD_BrakeOC(void);
void RTE_Write_SIM_VCU_DVD_BrakeOC(float fltValue);
float RTE_Read_COM_PS_VCU_OperationStatus(void);
void RTE_Write_COM_PS_VCU_OperationStatus(float fltValue);
float RTE_Read_COM_PS_VCU_FaultLevel(void);
void RTE_Write_COM_PS_VCU_FaultLevel(float fltValue);
float RTE_Read_COM_HighVRelayStatus_K8(void);
void RTE_Write_COM_HighVRelayStatus_K8(float fltValue);
float RTE_Read_COM_BMS_Total_Voltage(void);
void RTE_Write_COM_BMS_Total_Voltage(float fltValue);
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
float RTE_Read_COM_Testout(void);
void RTE_Write_COM_Testout(float fltValue);
float RTE_Read_COL_HiTempLevel2(void);
void RTE_Write_COL_HiTempLevel2(float fltValue);
float RTE_Read_COL_HiTempLevel1(void);
void RTE_Write_COL_HiTempLevel1(float fltValue);
float RTE_Read_DRV_EcoModeOn(void);
void RTE_Write_DRV_EcoModeOn(float fltValue);
float RTE_Read_DRV_VCU_DASH_VehicleSpeed(void);
void RTE_Write_DRV_VCU_DASH_VehicleSpeed(float fltValue);
float RTE_Read_DCC_VCU_DVD_DCDCDropped(void);
void RTE_Write_DCC_VCU_DVD_DCDCDropped(float fltValue);
float RTE_Read_DCC_VCU_DVD_DCDCAlarmLevel(void);
void RTE_Write_DCC_VCU_DVD_DCDCAlarmLevel(float fltValue);
float RTE_Read_DCC_VCU_DASH_DCStatus(void);
void RTE_Write_DCC_VCU_DASH_DCStatus(float fltValue);
float RTE_Read_TDRV_PedalMassFactorSW(void);
void RTE_Write_TDRV_PedalMassFactorSW(float fltValue);
float RTE_Read_TDRV_PedalMiddlePositionSW(void);
void RTE_Write_TDRV_PedalMiddlePositionSW(float fltValue);
float RTE_Read_TDRV_PedalMiddlePosition(void);
void RTE_Write_TDRV_PedalMiddlePosition(float fltValue);
float RTE_Read_TDRV_PedalMassFactor(void);
void RTE_Write_TDRV_PedalMassFactor(float fltValue);
float RTE_Read_AATEST_Fwd_Speed_Limit(void);
void RTE_Write_AATEST_Fwd_Speed_Limit(float fltValue);
float RTE_Read_AATEST_Apply_Speed_Stubs(void);
void RTE_Write_AATEST_Apply_Speed_Stubs(float fltValue);
float RTE_Read_FLT_FaultLevel(void);
void RTE_Write_FLT_FaultLevel(float fltValue);
float RTE_Read_TST_DrivingMode(void);
void RTE_Write_TST_DrivingMode(float fltValue);
float RTE_Read_TST_Allow2driveOut(void);
void RTE_Write_TST_Allow2driveOut(float fltValue);
float RTE_Read_DRV_Gear_Reverse(void);
void RTE_Write_DRV_Gear_Reverse(float fltValue);
float RTE_Read_DRV_GearState(void);
void RTE_Write_DRV_GearState(float fltValue);
float RTE_Read_DRV_PrechargeState(void);
void RTE_Write_DRV_PrechargeState(float fltValue);
float RTE_Read_DRV_VCU_MCU_K2CloseRequestVali(void);
void RTE_Write_DRV_VCU_MCU_K2CloseRequestVali(float fltValue);
float RTE_Read_DRV_VCU_MCU_K2CloseRequest(void);
void RTE_Write_DRV_VCU_MCU_K2CloseRequest(float fltValue);
float RTE_Read_FLT_SystemErrorSeverity(void);
void RTE_Write_FLT_SystemErrorSeverity(float fltValue);
float RTE_Read_ACP_Fault1(void);
void RTE_Write_ACP_Fault1(float fltValue);
float RTE_Read_ACP_Fault2(void);
void RTE_Write_ACP_Fault2(float fltValue);
float RTE_Read_ACP_Fault3(void);
void RTE_Write_ACP_Fault3(float fltValue);
float RTE_Read_FLT_ACP_Fault1_Clear(void);
void RTE_Write_FLT_ACP_Fault1_Clear(float fltValue);
float RTE_Read_FLT_ACP_Fault2_Clear(void);
void RTE_Write_FLT_ACP_Fault2_Clear(float fltValue);
float RTE_Read_FLT_ACP_Fault3_Clear(void);
void RTE_Write_FLT_ACP_Fault3_Clear(float fltValue);
float RTE_Read_Signal1(void);
void RTE_Write_Signal1(float fltValue);
float RTE_Read_Signal2(void);
void RTE_Write_Signal2(float fltValue);
float RTE_Read_Signal3(void);
void RTE_Write_Signal3(float fltValue);
float RTE_Read_Signal4(void);
void RTE_Write_Signal4(float fltValue);
float RTE_Read_PST_Ready(void);
void RTE_Write_PST_Ready(float fltValue);
float RTE_Read_PST_FaultCritical(void);
void RTE_Write_PST_FaultCritical(float fltValue);
float RTE_Read_PST_FaultGeneral(void);
void RTE_Write_PST_FaultGeneral(float fltValue);
float RTE_Read_PST_FaultAlarm(void);
void RTE_Write_PST_FaultAlarm(float fltValue);
float RTE_Read_MCU_Precharge(void);
void RTE_Write_MCU_Precharge(float fltValue);
float RTE_Read_Test_Pin_Duty_WaterPump(void);
void RTE_Write_Test_Pin_Duty_WaterPump(float fltValue);
float RTE_Read_Test_Pin_Freq_WaterPump(void);
void RTE_Write_Test_Pin_Freq_WaterPump(float fltValue);
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
#define RTE_Service_MEM_eWriteSignalValue ECU_MEM_eWriteSignalValue
#define RTE_Service_MEM_eReadSignalValue ECU_MEM_eReadSignalValue
#define RTE_Service_SYS_vdShutdown ECU_SYS_vdShutdown
#define RTE_Service_IO_eReadPwm ECU_IO_eReadPwm
#define RTE_Service_IO_eSetPwm ECU_IO_eSetPwm
#define RTE_Service_SYS_vdGetResetStatus ECU_SYS_vdGetResetStatus
#define RTE_Service_SYS_vdClearResetStatus ECU_SYS_vdClearResetStatus

// extern STATUS_t RTE_Service_COM_vdReadSignal(uint8_t u8IdSignal, float* pfltValue);
// extern STATUS_t RTE_Service_COM_vdWriteSignal(uint8_t u8IdSignal, float fltValue);
// extern STATUS_t RTE_Service_COM_vdEnable(uint8_t u8Enable);
// extern STATUS_t RTE_Service_ANLG_eReadSignal(uint8_t u8IndexSignal, float* pfltValue);
// extern STATUS_t RTE_Service_IO_eOutputControl(uint8_t u8IdOutput, ECU_IO_eOutputCommand_t eOutputCommand);
// extern STATUS_t RTE_Service_IO_eInputRead(uint8_t u8IdInput, uint8_t* pu8Value);
// extern STATUS_t RTE_Service_MEM_eWriteSignalValue(uint8_t u8SignalID, float fltValue);
// extern STATUS_t RTE_Service_MEM_eReadSignalValue(uint8_t u8SignalID, float* pfltValue);
// extern void RTE_Service_SYS_vdShutdown(void);
// extern STATUS_t RTE_Service_IO_eReadPwm(uint8_t u8IdPin, uint32_t* pu32FreqHz, uint8_t* pu8DutyCycle);
// extern STATUS_t RTE_Service_IO_eSetPwm(uint8_t u8IdPout, uint32_t u32FreqHz, uint8_t u8DutyCycle);
// extern void RTE_Service_SYS_vdGetResetStatus(uint8_t* pu8IsExWdgReset);
// extern void RTE_Service_SYS_vdClearResetStatus(uint8_t u8IsExWdgResetNeeded);

#endif /*RTE_H*/

