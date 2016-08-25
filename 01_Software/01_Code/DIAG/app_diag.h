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

File Name: app_diag.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_DIAG_H
#define APP_DIAG_H

/* List of diag global defines */
#define APP_DIAG_STATUS_FREE                                    (0)                                           
#define APP_DIAG_STATUS_BUSY                                    (1)


/* List of Service Ids */
#define SID_DIAG_SESSION_CONTROL                                (0x10)
#define SID_ECU_RESET                                           (0x11)
#define SID_SECURITY_ACCESS                                     (0x27)
#define SID_COMMUNICATION_CONTROL                               (0x28)
#define SID_CONTROL_DTC_SETTING                                 (0x85)
#define SID_READ_DATA_BY_PERIODIC_IDENTIFIER                    (0x2A)
#define SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFER                   (0x2F)
#define SID_CLEAR_DIAGNOSTIC_INFO                               (0x14)
#define SID_READ_DTC_INFORMATION                                (0x19)
#define SID_READ_DATA_BY_IDENTIFIER                             (0x22)
#define SID_READ_MEMORY_BY_ADDRESS                              (0x23)
#define SID_READ_SCALE_DATA_IDENTIFIER                          (0x24)
#define SID_SECURITY_ACCESS                                     (0x27)
#define SID_COMM_CONTROL                                        (0x28)
#define SID_READ_DATA_IDENTIFIER_PERIODIC                       (0x2A)
#define SID_DYNAMIC_DEFINE_DATA_IDENTIFIER                      (0x2C)
#define SID_WRITE_DATA_BY_IDENTIFIER                            (0x2E)
#define SID_IO_CONTROL_BY_IDENTIFIER                            (0x2F)
#define SID_REMOTE_CONTROL                                      (0x31)
#define SID_WRITE_MEMORY_BY_ADDRESS                             (0x3D)
#define SID_TESTER_PRESENT                                      (0x3E)
#define SID_ACCESS_TIME_PARAM                                   (0x83)
#define SID_SECURED_DATA_TRANSMISSION                           (0x84)
#define SID_CONTROL_DTC_SETTINGS                                (0x85)
#define SID_RESPONSE_ON_EVENT                                   (0x86)
#define SID_LINK_CONTROL                                        (0x87)
#define SID_REQUEST_DOWNLOAD                                    (0x34)
#define SID_REQUEST_UPLOAD                                      (0x35)
#define SID_TRANSFER_DATA                                       (0x36)
#define SID_REQUEST_TRANSFER_EXIT                               (0x37)
#define SID_REQUEST_FILE_TRANSFER                               (0x38)
#define SID_ACCESS_TIMING_PARAMETER                             (0x83)
#define SID_READ_SCALING_DATA_BY_IDENTIFIER                     (0x24)
#define SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER                  (0x2C)
#define SID_ROUTINE_CONTROL                                     (0x31)
#define SID_CLEAR_DIAGNOSTIC_INFORMATION                        (0x14)

typedef enum APP_DIAG_NRC_template
{
  APP_DIAG_GeneralReject = 0x10,
  APP_DIAG_ServiceNotSupported = 0x11,
  APP_DIAG_SubFunctionNotSupported = 0x12,
  APP_DIAG_IncorrectMessageLengthOrInvalidFormat = 0x13,
  APP_DIAG_ResponseTooLong = 0x14,
  APP_DIAG_BusyRepeatRequest = 0x21,
  APP_DIAG_ConditionsNotCorrect = 0x22,
  APP_DIAG_RequestSequenceError = 0x24,
  APP_DIAG_NoResponseFromSubnetComponent = 0x25,
  APP_DIAG_FailurePreventsExecutionOfRequestedAction = 0x26,
  APP_DIAG_RequestOutOfRange = 0x31,
  APP_DIAG_SecurityAccessDenied = 0x33,
  APP_DIAG_InvalidKey = 0x35,
  APP_DIAG_ExceedNumberOfAttempts = 0x36,
  APP_DIAG_RequiredTimeDelayNotExpired = 0x37,
  APP_DIAG_UploadDownloadNotAccepted = 0x70,
  APP_DIAG_TransferDataSuspended = 0x71,
  APP_DIAG_GeneralProgrammingFailure = 0x72,
  APP_DIAG_WrongBlockSequenceCounter = 0x73,
  APP_DIAG_RequestCorrectlyReceivedResponsePending = 0x78,
  APP_DIAG_SubFunctionNotSupportedInActiveSession = 0x7E,
  APP_DIAG_ServiceNotSupportedInActiveSession = 0x7F,
  APP_DIAG_RpmTooHigh = 0x81,
  APP_DIAG_RpmTooLow = 0x82,
  APP_DIAG_EngineIsRunning = 0x83,
  APP_DIAG_EngineIsNotRunning = 0x84,
  APP_DIAG_EngineRunTimeTooLow = 0x85,
  APP_DIAG_TemperatureTooHigh = 0x86,
  APP_DIAG_TemperatureTooLow = 0x87,
  APP_DIAG_VehicleSpeedTooHigh = 0x88,
  APP_DIAG_VehicleSpeedTooLow = 0x89,
  APP_DIAG_Throttle_PedalTooHigh = 0x8A,
  APP_DIAG_Throttle_PedalTooLow = 0x8B,
  APP_DIAG_TransmissionRangeNotInNeutral = 0x8C,
  APP_DIAG_TransmissionRangeNotInGear = 0x8D,
  APP_DIAG_BrakePedalNotPressed = 0x8F,
  APP_DIAG_ShifterLeverNotInPark = 0x90,
  APP_DIAG_TorqueConverterClutchLocked = 0x91,
  APP_DIAG_VoltageTooHigh = 0x92,
  APP_DIAG_VoltageTooLow = 0x93,
} APP_DIAG_NRC_t;

//typedef struct APP_DIAG_strServiceModuleTemplate
//{
//  uint8_t u8ServiceID,
//  
//  
//} APP_DIAG_strServiceModule_t

void APP_DIAG_vdInit(void);
void APP_DIAG_vdMgr(void);


#endif /*APP_DIAG_H*/

