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

File Name: app_diag.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app.h"
#include "rte.h"

#define APP_DIAG_HEARTBEAT_HALF_PERIOD_MS                             100
#define APP_DIAG_TASK_MS                                              50

uint8_t APP_DIAG_u8ServiceId = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8DeviceId = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8RequestId = TAPAS_DEFAULT;
uint8_t APP_DIAG_au8RequestData[4] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_au8ResposneData[4] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
uint8_t APP_DIAG_au8DataNotUsed[4] = {0,0,0,0};

void local_APP_DIAG_vdHeartBeat(void);
void local_APP_DIAG_vdMainStateMachine(void);
void local_APP_DIAG_EndService(STATUS_t eStatus, uint8_t *pau8Data);
void local_APP_DIAG_vdIO_Control_Identifier(void);
void local_APP_DIAG_vdRead_Identifier(void);
void local_APP_DIAG_vdMemory_Write(void);
void local_APP_DIAG_vdMemory_Read(void);

void APP_DIAG_vdInit(void)
{

}

void APP_DIAG_vdMgr(void)
{
	STATUS_t eStatus;
	ECU_SYS_eEcuMode_t eEcuMode;

  
  /* Check the system mode */
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  
  if(eEcuMode == ECU_SYS_DIAG)
  {
    local_APP_DIAG_vdHeartBeat();
  }
  
	if(APP_DIAG_eStatus == APP_DIAG_STATUS_FREE)
	{
		eStatus = ECU_DIAG_u8GetDiagRequest(&APP_DIAG_u8ServiceId, &APP_DIAG_u8DeviceId, &APP_DIAG_u8RequestId, APP_DIAG_au8RequestData);
		
		if(eStatus == STATUS_OK)
		{			
			/* Check if it is the Diag session request */
			if((eEcuMode == ECU_SYS_NORMAL) && (APP_DIAG_u8ServiceId == SID_DIAG_SESSION_CONTROL))
			{
				ECU_SYS_vdSetEcuMode(ECU_SYS_DIAG);
				/* Send Positive Response */
				local_APP_DIAG_EndService(STATUS_OK, &APP_DIAG_au8DataNotUsed[0]);	
			}
			else if(eEcuMode == ECU_SYS_DIAG)
			{
				/* Serve the request */
				APP_DIAG_eStatus = APP_DIAG_STATUS_BUSY;
				local_APP_DIAG_vdMainStateMachine();
			}
			else
			{
				/* Send Negative Response */
				local_APP_DIAG_EndService(STATUS_NOK, &APP_DIAG_au8DataNotUsed[0]);				
			}
		}
	}
}

void local_APP_DIAG_vdMainStateMachine(void)
{
	switch(APP_DIAG_u8ServiceId) 
	{
		case SID_IO_CONTROL_BY_IDENTIFIER:
			local_APP_DIAG_vdIO_Control_Identifier();
			break;
		case SID_READ_DATA_BY_IDENTIFIER:
			local_APP_DIAG_vdRead_Identifier();
			break;
		case SID_WRITE_MEMORY_BY_ADDRESS:
      local_APP_DIAG_vdMemory_Write();
			break;
		case SID_READ_MEMORY_BY_ADDRESS:
      local_APP_DIAG_vdMemory_Read();
			break;
		default :
			local_APP_DIAG_EndService(STATUS_NOK, &APP_DIAG_au8DataNotUsed[0]);
	}
}

void local_APP_DIAG_vdIO_Control_Identifier(void)
{
	switch(APP_DIAG_u8DeviceId) 
	{
		default :
			local_APP_DIAG_EndService(STATUS_NOK, &APP_DIAG_au8DataNotUsed[0]);
	}
}

void local_APP_DIAG_vdRead_Identifier(void)
{
	switch(APP_DIAG_u8DeviceId) 
	{
		default :
			local_APP_DIAG_EndService(STATUS_NOK, &APP_DIAG_au8DataNotUsed[0]);
			break;
	}
}

void local_APP_DIAG_EndService(STATUS_t eStatus, uint8_t *pau8Data)
{
	APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
}

void local_APP_DIAG_vdMemory_Write(void)
{

}

void local_APP_DIAG_vdMemory_Read(void)
{

}

void local_APP_DIAG_vdHeartBeat(void)
{
	static uint32_t su32HeartBeatCounter = 1;
  
  if((su32HeartBeatCounter*APP_DIAG_TASK_MS) == APP_DIAG_HEARTBEAT_HALF_PERIOD_MS)
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_TOGGLE);
    su32HeartBeatCounter = 1;
  }
  else
  {
    su32HeartBeatCounter++;
  }
}