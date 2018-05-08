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

File Name: app_FaultMgr.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/


#ifndef APP_FAULTMGR_H
#define APP_FAULTMGR_H

#include "lib_types.h"
#include "rte.h"

typedef void (*APP_FLT_p2fSignalWrite_t)(float);
typedef float (*APP_FLT_p2fSignalRead_t)(void);

typedef enum APP_FLT_eDtcSeverityTemplate
{
  APP_FLT_DTC_SEV_NO_ERROR = 0,
  APP_FLT_DTC_SEV_WARNING = 1,
  APP_FLT_DTC_SEV_FAULT_L1 = 2,
  APP_FLT_DTC_SEV_FAULT_L2 = 3,
} APP_FLT_eDtcSeverity_t; 

typedef struct APP_FLT_strDtcTemplate
{
	/* DTC ID */
	uint16_t u8IdDtc;
  /* DTC Severity*/
  APP_FLT_eDtcSeverity_t eDtcSeverity;
  /*Reset Delta Time*/
  uint16_t u16ResetDeltaTimeMs;
  /*Delta Time Counter*/
  uint32_t u32DeltaTimeCounter;
  /*Error Count Limit*/
  uint8_t u8ErrorCountLimit;
  /*Error Flag*/
  uint8_t u8ErrorFlag;
  /*Error Count*/
  uint8_t u8ErrorCount;
  /*Pointer to the RTE Read Error Set Signal*/
  APP_FLT_p2fSignalRead_t p2fRteReadError;
  /*Pointer to the RTE Write Error Clear Signal*/
  APP_FLT_p2fSignalWrite_t p2fRteWriteErrorClear;
  /*Decided severity for the DTC*/
  APP_FLT_eDtcSeverity_t eDtcSeverityDecided;
  /*Memory Id*/
  uint16_t u16IdMemory;
} APP_FLT_strDtc_t;

void app_FaultMgr_initialize(void);
void app_FaultMgr_terminate(void);
void app_FaultMgr_fcn(void);
void app_FaultMgr_ClearDTC(void);
void app_FaultMgr_ReadConfirmedDTCs(uint8_t* pau8ConfirmedDTCs);
//STATUS_t app_FaultMgr_ReadDTC(uint16_t u16DID, APP_FLT_eDtcSeverity_t* eDTCSeverity, );

#endif /*APP_FAULTMGR_H*/

