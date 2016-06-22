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


#define RTE_DATA_NUM                                                       (9)

#define RTE_DATA_ID_INPUTFROMANOTHERMODEL1                                 (0)
#define RTE_DATA_ID_INPUTFROMANOTHERMODEL2                                 (1)
#define RTE_DATA_ID_OUTPUTFROMANOTHERMODEL2                                (2)
#define RTE_DATA_ID_OUTPUTFROMANOTHERMODEL1                                (3)
#define RTE_DATA_ID_SYS_U8SYSTEMMODE                                       (4)
#define RTE_DATA_ID_TEST2_DASHRPM                                          (5)
#define RTE_DATA_ID_TEST2_DASHSPEED                                        (6)
#define RTE_DATA_ID_TEST_PEDALANALOG2                                      (7)
#define RTE_DATA_ID_TEST_PEDALANALOG1                                      (8)


typedef struct RTE_strDataTemplate
{
	/* Data ID */
	uint8_t u8IdData;
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
float RTE_Read_SYS_u8SystemMode(void);
void RTE_Write_SYS_u8SystemMode(float fltValue);
float RTE_Read_TEST2_DashRpm(void);
void RTE_Write_TEST2_DashRpm(float fltValue);
float RTE_Read_TEST2_DashSpeed(void);
void RTE_Write_TEST2_DashSpeed(float fltValue);
float RTE_Read_TEST_PedalAnalog2(void);
void RTE_Write_TEST_PedalAnalog2(float fltValue);
float RTE_Read_TEST_PedalAnalog1(void);
void RTE_Write_TEST_PedalAnalog1(float fltValue);

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

extern STATUS_t RTE_Service_COM_vdReadSignal(uint8_t u8IdSignal, float* pfltValue);
extern STATUS_t RTE_Service_COM_vdWriteSignal(uint8_t u8IdSignal, float fltValue);
extern STATUS_t RTE_Service_COM_vdEnable(uint8_t u8Enable);
extern STATUS_t RTE_Service_ANLG_eReadSignal(uint8_t u8IndexSignal, float* pfltValue);
extern STATUS_t RTE_Service_IO_eOutputControl(uint8_t u8IdOutput, ECU_IO_eOutputCommand_t eOutputCommand);
extern STATUS_t RTE_Service_IO_eInputRead(uint8_t u8IdInput, uint8_t* pu8Value);
extern STATUS_t RTE_Service_MEM_eWriteSignalValue(uint8_t u8SignalID, float fltValue);
extern STATUS_t RTE_Service_MEM_eReadSignalValue(uint8_t u8SignalID, float* pfltValue);
extern void RTE_Service_SYS_vdShutdown(void);
extern STATUS_t RTE_Service_IO_eReadPwm(uint8_t u8IdPin, uint32_t* pu32FreqHz, uint8_t* pu8DutyCycle);
extern STATUS_t RTE_Service_IO_eSetPwm(uint8_t u8IdPout, uint32_t u32FreqHz, uint8_t u8DutyCycle);

#endif /*RTE_H*/

