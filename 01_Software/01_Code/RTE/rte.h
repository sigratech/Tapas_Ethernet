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


#define RTE_DATA_NUM                                                       (14)

#define RTE_DATA_ID_CAM_GO_SIGNAL                                          (0)
#define RTE_DATA_ID_TEST_TO_CAM_1                                          (1)
#define RTE_DATA_ID_VEL_SPEEDLIMIT                                         (2)
#define RTE_DATA_ID_COM_OUTPUT1                                            (3)
#define RTE_DATA_ID_TEST_TO_COM_1                                          (4)
#define RTE_DATA_ID_MAIN_FAULT                                             (5)
#define RTE_DATA_ID_FLT_CLR_MAIN_FAULT                                     (6)
#define RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY                                (7)
#define RTE_DATA_ID_HMI_OUTPUT1                                            (8)
#define RTE_DATA_ID_TEST_TO_HMI_1                                          (9)
#define RTE_DATA_ID_POS_OUTPUT1                                            (10)
#define RTE_DATA_ID_TEST_TO_POS_1                                          (11)
#define RTE_DATA_ID_STR_OUTPUT1                                            (12)
#define RTE_DATA_ID_TEST_TO_STR_1                                          (13)


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
float RTE_Read_CAM_Go_Signal(void);
void RTE_Write_CAM_Go_Signal(float fltValue);
float RTE_Read_TEST_TO_CAM_1(void);
void RTE_Write_TEST_TO_CAM_1(float fltValue);
float RTE_Read_VEL_SpeedLimit(void);
void RTE_Write_VEL_SpeedLimit(float fltValue);
float RTE_Read_COM_Output1(void);
void RTE_Write_COM_Output1(float fltValue);
float RTE_Read_TEST_TO_COM_1(void);
void RTE_Write_TEST_TO_COM_1(float fltValue);
float RTE_Read_MAIN_Fault(void);
void RTE_Write_MAIN_Fault(float fltValue);
float RTE_Read_FLT_CLR_MAIN_Fault(void);
void RTE_Write_FLT_CLR_MAIN_Fault(float fltValue);
float RTE_Read_FLT_SystemErrorSeverity(void);
void RTE_Write_FLT_SystemErrorSeverity(float fltValue);
float RTE_Read_HMI_Output1(void);
void RTE_Write_HMI_Output1(float fltValue);
float RTE_Read_TEST_TO_HMI_1(void);
void RTE_Write_TEST_TO_HMI_1(float fltValue);
float RTE_Read_POS_Output1(void);
void RTE_Write_POS_Output1(float fltValue);
float RTE_Read_TEST_TO_POS_1(void);
void RTE_Write_TEST_TO_POS_1(float fltValue);
float RTE_Read_STR_Output1(void);
void RTE_Write_STR_Output1(float fltValue);
float RTE_Read_TEST_TO_STR_1(void);
void RTE_Write_TEST_TO_STR_1(float fltValue);

/* RTE SWC Init */
void RTE_vdInit(void);


/* RTE SWC Deinit */
void RTE_vdDeInit(void);


/* RTE SWC Access */
STATUS_t RTE_eReadData(uint16_t u16Id, float* pfltData);
STATUS_t RTE_eWriteData(uint16_t u16Id, float fltData);



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

