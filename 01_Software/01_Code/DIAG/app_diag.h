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

#include "lib_types.h"
#include "app.h"

/* List of diag global defines */
#define APP_DIAG_STATUS_FREE                                    (0)                                           
#define APP_DIAG_STATUS_BUSY                                    (1)
#define APP_DIAG_RESPONSE_FILLER                                (0xAA)
#define APP_DIAG_REQUEST_FILLER                                 (0x55)

/* Read data by address maximum bytes number to be read*/
#define APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_NUMBER              (128)
#define APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS         (16)

/* Write data by address macros */
#define APP_DIAG_WRITE_DATA_BY_ADDRESS_MAX_BYTES_NUMBER         (16)
#define APP_DIAG_WRITE_DATA_BY_ADDRESS_FC_SEPARATION_TIME_MS    (100)

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

typedef struct APP_DIAG_strFlowControlTemplate // when ECU sends first frame and wait for flow control from tester to continue sending consecutive frames
{
  uint8_t u8ServiceID;
  uint8_t u8ExpectedFC_Flag;
  uint8_t u8MaxNumberOfConsecutiveFrames;
  uint8_t u8ConsecutiveFrameIndex;
  uint8_t u8NumberOfFramesSent;
} APP_DIAG_strFlowControl_t;

typedef struct APP_DIAG_strConsecutiveFlowTemplate // when tester sends first frame and wait for flow control from ECU to continue sending consecutive frames
{
  uint8_t u8SeriveID;
  uint8_t u8ExpectedCF_Flag;
  uint8_t u8ExpectedCF_Number;
  uint8_t u8SequenceNumber;
} APP_DIAG_strConsecutiveFrame_t;

void APP_DIAG_vdInit(void);
void APP_DIAG_vdMgr(void);
uint8_t APP_DIAG_u8DefaultEcuModeCheck(ECU_SYS_eEcuMode_t* Mode);

#endif /*APP_DIAG_H*/

