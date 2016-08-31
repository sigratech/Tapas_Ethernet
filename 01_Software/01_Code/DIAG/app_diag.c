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
#include "app_diag_cfg.h"
#include "app_diag.h"

#ifdef APP_DIAG_ENABLE

#include "app.h"
#include "rte.h"
#include "lib_data.h"
#include "lib_delay.h"

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
void local_APP_DIAG_EndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus);
void local_APP_DIAG_vdFillEchoArray(uint8_t *pau8EchoArray);
void local_APP_DIAG_vdServeDiagRequest(void);


void APP_DIAG_vdInit(void)
{
  ECU_DIAG_vdRegisterAppDiagCallback(local_APP_DIAG_vdServeDiagRequest);
}

void APP_DIAG_vdMgr(void)
{
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode();
  
//  local_APP_DIAG_vdHeartBeat();  
  if(eEcuMode == ECU_SYS_DIAG)
  {
    local_APP_DIAG_vdHeartBeat();
  }
}

void local_APP_DIAG_vdServeDiagRequest(void)
{
	STATUS_t eStatus;
	ECU_SYS_eEcuMode_t eEcuMode;
  
  /* Check the system mode */
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  
  
  if(eEcuMode != ECU_SYS_BOOT)
  {
    ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY);    
    if(APP_DIAG_eStatus == APP_DIAG_STATUS_FREE)
    {
      eStatus = ECU_DIAG_u8GetDiagRequest(&APP_DIAG_u8ServiceId, &APP_DIAG_u8DeviceId, &APP_DIAG_u8RequestId, APP_DIAG_au8RequestData);
      
      if(eStatus == STATUS_OK)
      {			
        /* Check if it is the Diag session request */
        if((eEcuMode == ECU_SYS_NORMAL) && (APP_DIAG_u8ServiceId == SID_DIAG_SESSION_CONTROL) && (APP_DIAG_u8DeviceId == (uint8_t)ECU_SYS_DIAG))
        {
          ECU_SYS_vdSetEcuMode(ECU_SYS_DIAG);
          /* Send Positive Response */
          local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_OK);
        }
        else if((APP_DIAG_u8ServiceId == SID_DIAG_SESSION_CONTROL))
        {
          APP_DIAG_au8ResposneData[0] = (uint8_t)eEcuMode;
          APP_DIAG_au8ResposneData[1] = 0;
          APP_DIAG_au8ResposneData[2] = 0;
          APP_DIAG_au8ResposneData[3] = 0;
          local_APP_DIAG_EndService(STATUS_NOK, APP_DIAG_au8ResposneData);
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
          local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
        }
      }
    }
  }
}

void local_APP_DIAG_vdMainStateMachine(void)
{
  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY);
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
		case SID_ECU_RESET:
      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_OK);
      //LIB_DELAY_vdNanoSeconds(500000);
      ECU_SYS_vdShutdownAndReset();
			break;
		default :  
      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
	}
}

void local_APP_DIAG_vdIO_Control_Identifier(void)
{
	switch(APP_DIAG_u8DeviceId) 
	{
		default :
      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
	}
}

void local_APP_DIAG_vdRead_Identifier(void)
{
	switch(APP_DIAG_u8DeviceId) 
	{
		default :
      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
			break;
	}
}

void local_APP_DIAG_EndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus)
{
  uint8_t u8Count;
  local_APP_DIAG_vdFillEchoArray(pau8EchoArray);
  local_APP_DIAG_EndService(eStatus, pau8EchoArray);
  for(u8Count = 0; u8Count < 8; u8Count++)
  {
    pau8EchoArray[u8Count] = 0;
  }
}

void local_APP_DIAG_vdFillEchoArray(uint8_t *pau8EchoArray)
{
  pau8EchoArray[0] = APP_DIAG_au8RequestData[0];
  pau8EchoArray[1] = APP_DIAG_au8RequestData[1];
  pau8EchoArray[2] = APP_DIAG_au8RequestData[2];
  pau8EchoArray[3] = APP_DIAG_au8RequestData[3];    
}

void local_APP_DIAG_EndService(STATUS_t eStatus, uint8_t *pau8Data)
{
	APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE);  
	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
}

void local_APP_DIAG_vdMemory_Write(void)
{
  STATUS_t eStatus = STATUS_NOK;
  float fltRecData;
  uint8_t APP_DIAG_au8ReceivedData[4] = {0, 0, 0, 0};
  uint32_t u32Data = 0;
  u32Data = APP_DIAG_au8RequestData[0] << 24;
  u32Data |= APP_DIAG_au8RequestData[1] << 16;
  u32Data |= APP_DIAG_au8RequestData[2] << 8;
  u32Data |= APP_DIAG_au8RequestData[3];
  fltRecData = (float)u32Data;
  u32Data = u32Data / 100;
  fltRecData = fltRecData / 100.0f;
  if(APP_DIAG_u8DeviceId == 0) // Internal Emulated 
  {
    eStatus = ECU_MEM_INT_eWriteSignalValue(APP_DIAG_u8RequestId, fltRecData, u32Data);
  }
  else // External EEPROM
  {
#ifdef ECU_MEM_EXT_MODULE_ENABLE
  eStatus = ECU_MEM_EXT_eWriteSignalValue(APP_DIAG_u8RequestId, LIB_DATA_fltRaw2Phy(u32Data, 0.01, 0));    
#else
  eStatus = STATUS_NOK;
#endif /*ECU_MEM_EXT_MODULE_ENABLE*/
  }
  APP_DIAG_au8ReceivedData[0] = APP_DIAG_au8RequestData[0];
  APP_DIAG_au8ReceivedData[1] = APP_DIAG_au8RequestData[1];
  APP_DIAG_au8ReceivedData[2] = APP_DIAG_au8RequestData[2];
  APP_DIAG_au8ReceivedData[3] = APP_DIAG_au8RequestData[3];  
  local_APP_DIAG_EndService(eStatus, APP_DIAG_au8ReceivedData);
}

void local_APP_DIAG_vdMemory_Read(void)
{
  STATUS_t eStatus = STATUS_NOK;
  uint32_t u32Data;
  uint8_t APP_DIAG_au8TrialReceivedData[4] = {0, 0, 0, 0};
  float fltData = 0.0;      
  if(APP_DIAG_u8DeviceId == 0) // Internal Emulated 
  {
    eStatus = ECU_MEM_INT_eReadSignalValue(APP_DIAG_u8RequestId, &fltData);
  }
  else // External EEPROM
  {
#ifdef ECU_MEM_EXT_MODULE_ENABLE
  eStatus = ECU_MEM_EXT_eReadSignalValue(APP_DIAG_u8RequestId, &fltData);    
  u32Data =(uint32_t) (fltData * 100);
#else
  eStatus = STATUS_NOK;
#endif /*ECU_MEM_EXT_MODULE_ENABLE*/
  
  }
  u32Data = (uint32_t)(fltData * 100);
  APP_DIAG_au8TrialReceivedData[0] = (u32Data >> 24);
  APP_DIAG_au8TrialReceivedData[1] = (u32Data >> 16);
  APP_DIAG_au8TrialReceivedData[2] = (u32Data >> 8);
  APP_DIAG_au8TrialReceivedData[3] = (u32Data); 
  local_APP_DIAG_EndService(eStatus, APP_DIAG_au8TrialReceivedData);
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

#endif /*APP_DIAG_ENABLE*/
