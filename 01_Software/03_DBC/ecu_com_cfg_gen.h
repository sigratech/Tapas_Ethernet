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

File Name: ecu_com_cfg_gen.h
Author: TAPAS Generated 
E-mail: N/A 
***************************************************************************
***************************************************************************
*/

#ifndef ECU_COM_CFG_GEN_H
#define ECU_COM_CFG_GEN_H


/*********** NETWORK 1 ***********/
/* Defines of Rx Messages */
#define ECU_COM_RX1_MSGS_NUM                                               (2)
#define DASH_STATUS                                                        (0)
#define DC_DC_STATUS1                                                      (1)


/* Defines of Tx Messages */
#define ECU_COM_TX1_MSGS_NUM                                               (4)
#define DASH_CONTROL3                                                      (0)
#define DASH_CONTROL2                                                      (1)
#define DASH_CONTROL1                                                      (2)
#define DC_DC_CONTROL                                                      (3)


/* Defines of Rx Signals */
#define ECU_COM_RX1_SIGNALS_NUM                                            (11)
#define DASH_VCU_BATTERYVOL                                                (0)
#define DASH_VCU_DASHSWVERSION                                             (1)
#define DASH_VCU_DASHHWVERSION                                             (2)
#define DASH_VCU_ACCUMULATEDMILE                                           (3)
#define DASH_VCU_DASHLIFE                                                  (4)
#define DC_DC_JUNCTION_TEMP                                                (5)
#define DC_DC_TRANSFORMER_TEMP                                             (6)
#define HV_VOLTAGE                                                         (7)
#define LV_VOLTAGE                                                         (8)
#define LV_CURRENT                                                         (9)
#define DCDCSTATUS1LIFEBEAT                                                (10)


/* Defines of Tx Signals */
#define ECU_COM_TX1_SIGNALS_NUM                                            (62)
#define VCU_DASH_MOTORHWLOSESIGNAL_P                                       (0)
#define VCU_DASH_MOTORRESOLVE_P                                            (1)
#define VCU_DASH_MOTORLACKPHASE_P                                          (2)
#define VCU_DASH_MOTORCOUNTEREMF_P                                         (3)
#define VCU_DASH_MOTORCANFAILURE_P                                         (4)
#define VCU_DASH_MOTOROVERSPEED_P                                          (5)
#define VCU_DASH_MOTORDRIVERBOARDOVERT_P                                   (6)
#define VCU_DASH_MOTORBLOCKING_P                                           (7)
#define VCU_DASH_MOTOROVERLOAD_P                                           (8)
#define VCU_DASH_MOTOROVERTORQUE_P                                         (9)
#define VCU_DASH_MOTORBUSLINEOVERV_P                                       (10)
#define VCU_DASH_MOTORBUSLINEUNDERV_P                                      (11)
#define VCU_DASH_MOTORDQOVERC_P                                            (12)
#define VCU_DASH_MOTORCVOVERV_P                                            (13)
#define VCU_DASH_MOTORCVREVERSECONN_P                                      (14)
#define VCU_DASH_MOTORCVUNDERV_P                                           (15)
#define VCU_DASH_MOTORPHASEOVERC_P                                         (16)
#define VCU_DASH_MOTORBUSLINEOVERC_P                                       (17)
#define VCU_DASH_MOTOROVERT_P                                              (18)
#define VCU_DASH_MOTORIGBTOVERT_P                                          (19)
#define VCU_DASH_MOTORBRIDGEUPDOWN_P                                       (20)
#define VCU_DASH_MOTORDRIVEPOWERUNDERV_P                                   (21)
#define VCU_DASH_MOTORIGBT_P                                               (22)
#define VCU_DASH_RPM                                                       (23)
#define VCU_DASH_DRIVINGMILE                                               (24)
#define VCU_DASH_VEHICLESPEED                                              (25)
#define VCU_DASH_VEHICLECONTROLLER                                         (26)
#define VCU_DASH_SOC                                                       (27)
#define VCU_DASH_VACUUMLEVEL                                               (28)
#define VCU_DASH_MOTORCONTROLLERTEMP                                       (29)
#define VCU_DASH_BATTERYSTATUS                                             (30)
#define VCU_DASH_VACUUMPUMPFAILURE                                         (31)
#define VCU_DASH_FANFAILURE                                                (32)
#define VCU_DASH_PUMPFAILURE                                               (33)
#define VCU_DASH_BETTERYSYSFAILURE                                         (34)
#define VCU_DASH_MOTORSYSFAILURE                                           (35)
#define VCU_DASH_VEHICLEMODE                                               (36)
#define VCU_DASH_CHARGESTATUS                                              (37)
#define VCU_DASH_BACKMODULEPTC                                             (38)
#define VCU_DASH_FRONTMODULEPTC                                            (39)
#define VCU_DASH_GEARRANGE                                                 (40)
#define VCU_DASH_CONTROL2_LIFEBEAT                                         (41)
#define VCU_DASH_POWERORECOMODE                                            (42)
#define VCU_DASH_FOOTBRAKE                                                 (43)
#define VCU_DASH_HANDBRAKE                                                 (44)
#define VCU_DASH_AIRCONDITIONING                                           (45)
#define VCU_DASH_VACUUMPUMP                                                (46)
#define VCU_DASH_HIGHSPEEDFAN                                              (47)
#define VCU_DASH_LOWSPEEDFAN                                               (48)
#define VCU_DASH_PUMPS                                                     (49)
#define VCU_DASH_MOTORTEMP                                                 (50)
#define VCU_DASH_TORQUECONTROL                                             (51)
#define VCU_DASH_ACCELPEDALPERCENTAGE                                      (52)
#define VCU_DASH_DCSTATUS                                                  (53)
#define VCU_DASH_BATTERYUNDERVOLTAGE                                       (54)
#define VCU_DASH_VACUUMFAILURE                                             (55)
#define VCU_DASH_CONTROLLERFAILURE                                         (56)
#define VCU_DASH_CONTROL1_LIFEBEAT                                         (57)
#define VCU_DASH_VEHICLEOPERATINGSTATE                                     (58)
#define DC_DC_COMMAND                                                      (59)
#define DC_DC_CLEARERROR                                                   (60)
#define DCDCCONTROLLIFEBEAT                                                (61)


/*********** NETWORK 2 ***********/
/* Defines of Rx Messages */
#define ECU_COM_RX2_MSGS_NUM                                               (1)
#define MCU_STATUS1                                                        (0)


/* Defines of Tx Messages */
#define ECU_COM_TX2_MSGS_NUM                                               (1)
#define MCU_CONTROL1                                                       (0)


/* Defines of Rx Signals */
#define ECU_COM_RX2_SIGNALS_NUM                                            (12)
#define MCU_VCU_MOTORTORQUE                                                (0)
#define MCU_VCU_MCUTEMP                                                    (1)
#define MCU_VCU_ROTATIONDIRECTION                                          (2)
#define MCU_VCU_PRECHARGESTATUS                                            (3)
#define MCU_VCU_MOTORTEMP                                                  (4)
#define MCU_VCU_MOTORRPM                                                   (5)
#define MCU_VCU_MODECONTROL                                                (6)
#define MCU_VCU_MCULOWVOLSELFTEST                                          (7)
#define MCU_VCU_MCULIFE                                                    (8)
#define MCU_VCU_ALLOWEDCLOSEK2                                             (9)
#define MCU_VCU_IDLE                                                       (10)
#define MCU_VCU_ERRORSTATUS                                                (11)


/* Defines of Tx Signals */
#define ECU_COM_TX2_SIGNALS_NUM                                            (14)
#define VCU_MCU_RELAYK1STATUS                                              (0)
#define VCU_MCU_CAPACITYDISCHARGE                                          (1)
#define VCU_MCU_K2STATUS                                                   (2)
#define VCU_MCU_K2CLOSEREQUEST                                             (3)
#define VCU_MCU_K2CLOSEREQUESTVALI                                         (4)
#define VCU_MCU_SLOPESTOPREQUEST                                           (5)
#define VCU_MCU_TORQUESETPOINT                                             (6)
#define VCU_MCU_RPMSETPOINT                                                (7)
#define VCU_MCU_MODECONTROL                                                (8)
#define VCU_MCU_ENABLE                                                     (9)
#define VCU_MCU_INVERTERCOMMAND                                            (10)
#define VCU_MCU_DRIVENCOMMAND                                              (11)
#define VCU_MCU_CARSTATUS                                                  (12)
#define VCU_MCU_VCULIFE                                                    (13)




/* Defines of Application ECU Signals */

/* Defines of Application ECU Rx Signals */
#define ECU_COM_RX_SIGNALS_NUM                                             (23)
#define APP_RX_DASH_VCU_BATTERYVOL                                         (0)
#define APP_RX_DASH_VCU_DASHSWVERSION                                      (1)
#define APP_RX_DASH_VCU_DASHHWVERSION                                      (2)
#define APP_RX_DASH_VCU_ACCUMULATEDMILE                                    (3)
#define APP_RX_DASH_VCU_DASHLIFE                                           (4)
#define APP_RX_DC_DC_JUNCTION_TEMP                                         (5)
#define APP_RX_DC_DC_TRANSFORMER_TEMP                                      (6)
#define APP_RX_HV_VOLTAGE                                                  (7)
#define APP_RX_LV_VOLTAGE                                                  (8)
#define APP_RX_LV_CURRENT                                                  (9)
#define APP_RX_DCDCSTATUS1LIFEBEAT                                         (10)
#define APP_RX_MCU_VCU_MOTORTORQUE                                         (11)
#define APP_RX_MCU_VCU_MCUTEMP                                             (12)
#define APP_RX_MCU_VCU_ROTATIONDIRECTION                                   (13)
#define APP_RX_MCU_VCU_PRECHARGESTATUS                                     (14)
#define APP_RX_MCU_VCU_MOTORTEMP                                           (15)
#define APP_RX_MCU_VCU_MOTORRPM                                            (16)
#define APP_RX_MCU_VCU_MODECONTROL                                         (17)
#define APP_RX_MCU_VCU_MCULOWVOLSELFTEST                                   (18)
#define APP_RX_MCU_VCU_MCULIFE                                             (19)
#define APP_RX_MCU_VCU_ALLOWEDCLOSEK2                                      (20)
#define APP_RX_MCU_VCU_IDLE                                                (21)
#define APP_RX_MCU_VCU_ERRORSTATUS                                         (22)

/* Defines of Application ECU Tx Signals */
#define ECU_COM_TX_SIGNALS_NUM                                             (76)
#define APP_TX_VCU_DASH_MOTORHWLOSESIGNAL_P                                (0)
#define APP_TX_VCU_DASH_MOTORRESOLVE_P                                     (1)
#define APP_TX_VCU_DASH_MOTORLACKPHASE_P                                   (2)
#define APP_TX_VCU_DASH_MOTORCOUNTEREMF_P                                  (3)
#define APP_TX_VCU_DASH_MOTORCANFAILURE_P                                  (4)
#define APP_TX_VCU_DASH_MOTOROVERSPEED_P                                   (5)
#define APP_TX_VCU_DASH_MOTORDRIVERBOARDOVERT_P                            (6)
#define APP_TX_VCU_DASH_MOTORBLOCKING_P                                    (7)
#define APP_TX_VCU_DASH_MOTOROVERLOAD_P                                    (8)
#define APP_TX_VCU_DASH_MOTOROVERTORQUE_P                                  (9)
#define APP_TX_VCU_DASH_MOTORBUSLINEOVERV_P                                (10)
#define APP_TX_VCU_DASH_MOTORBUSLINEUNDERV_P                               (11)
#define APP_TX_VCU_DASH_MOTORDQOVERC_P                                     (12)
#define APP_TX_VCU_DASH_MOTORCVOVERV_P                                     (13)
#define APP_TX_VCU_DASH_MOTORCVREVERSECONN_P                               (14)
#define APP_TX_VCU_DASH_MOTORCVUNDERV_P                                    (15)
#define APP_TX_VCU_DASH_MOTORPHASEOVERC_P                                  (16)
#define APP_TX_VCU_DASH_MOTORBUSLINEOVERC_P                                (17)
#define APP_TX_VCU_DASH_MOTOROVERT_P                                       (18)
#define APP_TX_VCU_DASH_MOTORIGBTOVERT_P                                   (19)
#define APP_TX_VCU_DASH_MOTORBRIDGEUPDOWN_P                                (20)
#define APP_TX_VCU_DASH_MOTORDRIVEPOWERUNDERV_P                            (21)
#define APP_TX_VCU_DASH_MOTORIGBT_P                                        (22)
#define APP_TX_VCU_DASH_RPM                                                (23)
#define APP_TX_VCU_DASH_DRIVINGMILE                                        (24)
#define APP_TX_VCU_DASH_VEHICLESPEED                                       (25)
#define APP_TX_VCU_DASH_VEHICLECONTROLLER                                  (26)
#define APP_TX_VCU_DASH_SOC                                                (27)
#define APP_TX_VCU_DASH_VACUUMLEVEL                                        (28)
#define APP_TX_VCU_DASH_MOTORCONTROLLERTEMP                                (29)
#define APP_TX_VCU_DASH_BATTERYSTATUS                                      (30)
#define APP_TX_VCU_DASH_VACUUMPUMPFAILURE                                  (31)
#define APP_TX_VCU_DASH_FANFAILURE                                         (32)
#define APP_TX_VCU_DASH_PUMPFAILURE                                        (33)
#define APP_TX_VCU_DASH_BETTERYSYSFAILURE                                  (34)
#define APP_TX_VCU_DASH_MOTORSYSFAILURE                                    (35)
#define APP_TX_VCU_DASH_VEHICLEMODE                                        (36)
#define APP_TX_VCU_DASH_CHARGESTATUS                                       (37)
#define APP_TX_VCU_DASH_BACKMODULEPTC                                      (38)
#define APP_TX_VCU_DASH_FRONTMODULEPTC                                     (39)
#define APP_TX_VCU_DASH_GEARRANGE                                          (40)
#define APP_TX_VCU_DASH_CONTROL2_LIFEBEAT                                  (41)
#define APP_TX_VCU_DASH_POWERORECOMODE                                     (42)
#define APP_TX_VCU_DASH_FOOTBRAKE                                          (43)
#define APP_TX_VCU_DASH_HANDBRAKE                                          (44)
#define APP_TX_VCU_DASH_AIRCONDITIONING                                    (45)
#define APP_TX_VCU_DASH_VACUUMPUMP                                         (46)
#define APP_TX_VCU_DASH_HIGHSPEEDFAN                                       (47)
#define APP_TX_VCU_DASH_LOWSPEEDFAN                                        (48)
#define APP_TX_VCU_DASH_PUMPS                                              (49)
#define APP_TX_VCU_DASH_MOTORTEMP                                          (50)
#define APP_TX_VCU_DASH_TORQUECONTROL                                      (51)
#define APP_TX_VCU_DASH_ACCELPEDALPERCENTAGE                               (52)
#define APP_TX_VCU_DASH_DCSTATUS                                           (53)
#define APP_TX_VCU_DASH_BATTERYUNDERVOLTAGE                                (54)
#define APP_TX_VCU_DASH_VACUUMFAILURE                                      (55)
#define APP_TX_VCU_DASH_CONTROLLERFAILURE                                  (56)
#define APP_TX_VCU_DASH_CONTROL1_LIFEBEAT                                  (57)
#define APP_TX_VCU_DASH_VEHICLEOPERATINGSTATE                              (58)
#define APP_TX_DC_DC_COMMAND                                               (59)
#define APP_TX_DC_DC_CLEARERROR                                            (60)
#define APP_TX_DCDCCONTROLLIFEBEAT                                         (61)
#define APP_TX_VCU_MCU_RELAYK1STATUS                                       (62)
#define APP_TX_VCU_MCU_CAPACITYDISCHARGE                                   (63)
#define APP_TX_VCU_MCU_K2STATUS                                            (64)
#define APP_TX_VCU_MCU_K2CLOSEREQUEST                                      (65)
#define APP_TX_VCU_MCU_K2CLOSEREQUESTVALI                                  (66)
#define APP_TX_VCU_MCU_SLOPESTOPREQUEST                                    (67)
#define APP_TX_VCU_MCU_TORQUESETPOINT                                      (68)
#define APP_TX_VCU_MCU_RPMSETPOINT                                         (69)
#define APP_TX_VCU_MCU_MODECONTROL                                         (70)
#define APP_TX_VCU_MCU_ENABLE                                              (71)
#define APP_TX_VCU_MCU_INVERTERCOMMAND                                     (72)
#define APP_TX_VCU_MCU_DRIVENCOMMAND                                       (73)
#define APP_TX_VCU_MCU_CARSTATUS                                           (74)
#define APP_TX_VCU_MCU_VCULIFE                                             (75)


extern ECU_COM_strMsg_t ECU_COM_astrRx1Msg[ECU_COM_RX1_MSGS_NUM];
extern ECU_COM_strMsg_t ECU_COM_astrTx1Msg[ECU_COM_TX1_MSGS_NUM];
extern ECU_COM_strSignal_t ECU_COM_astrRx1Signal[ECU_COM_RX1_SIGNALS_NUM];
extern ECU_COM_strSignal_t ECU_COM_astrTx1Signal[ECU_COM_TX1_SIGNALS_NUM];
extern ECU_COM_strMsg_t ECU_COM_astrRx2Msg[ECU_COM_RX2_MSGS_NUM];
extern ECU_COM_strMsg_t ECU_COM_astrTx2Msg[ECU_COM_TX2_MSGS_NUM];
extern ECU_COM_strSignal_t ECU_COM_astrRx2Signal[ECU_COM_RX2_SIGNALS_NUM];
extern ECU_COM_strSignal_t ECU_COM_astrTx2Signal[ECU_COM_TX2_SIGNALS_NUM];
extern ECU_COM_strSigDecode_t ECU_COM_astrSigDecodeRx[ECU_COM_RX_SIGNALS_NUM];
extern ECU_COM_strSigDecode_t ECU_COM_astrSigDecodeTx[ECU_COM_TX_SIGNALS_NUM];


#endif /*ECU_COM_CFG_GEN_H*/


