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

ECU_DIAG_FrameType_t APP_DIAG_eFrameType = (ECU_DIAG_FrameType_t)TAPAS_DEFAULT;
uint8_t APP_DIAG_u8DataCount = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8ServiceId = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8SubFunction = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8SuppressPosResponse = TAPAS_DEFAULT;
uint8_t APP_DIAG_au8RequestData[ECU_DIAG_FRAME_DATA_BYTES] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_au8ResposneData[ECU_DIAG_FRAME_DATA_BYTES] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
uint8_t APP_DIAG_au8DataNotUsed[8] = {0,0,0,0,0,0,0,0};
ECU_SYS_eEcuMode_t APP_DIAG_eCurrentSession;

void local_APP_DIAG_vdDiagHeartBeat(void);
void local_APP_DIAG_vdMainStateMachine(ECU_SYS_eEcuMode_t eEcuMode);
void local_APP_DIAG_EndService(STATUS_t eStatus, uint8_t *pau8Data);
void local_APP_DIAG_vdIO_Control_Identifier(void);
void local_APP_DIAG_vdRead_Identifier(void);
void local_APP_DIAG_vdMemory_Write(void);
void local_APP_DIAG_vdMemory_Read(void);
void local_APP_DIAG_EndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus);
void local_APP_DIAG_vdFillEchoArray(uint8_t *pau8EchoArray);
void local_APP_DIAG_vdServeDiagRequest(ECU_SYS_eEcuMode_t ECU_Session);
void local_APP_DIAG_vdDiag_Session_Control(ECU_SYS_eEcuMode_t eEcuMode);
void local_APP_DIAG_vdNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode);
void local_APP_DIAG_vdBootHeartBeat(void);
void local_APP_DIAG_vdSingleFramePositiveResponse(uint8_t u8ResponseSID, uint8_t u8SubFunction, uint8_t* pu8Data, uint8_t u8DataSize);
void local_APP_DIAG_vdSingleFrameNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode);
void local_APP_DIAG_vdECU_Reset(void);
void local_APP_DIAG_vdTester_Present(void);
STATUS_t local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_eEcuMode_t Mode);


void APP_DIAG_vdInit(void)
{
  ECU_DIAG_vdRegisterAppDiagCallback(local_APP_DIAG_vdServeDiagRequest);
  APP_DIAG_eCurrentSession = ECU_SYS_eGetEcuMode();
}

void APP_DIAG_vdMgr(void)
{
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode();
  
//  local_APP_DIAG_vdHeartBeat();  
  if(eEcuMode == ECU_SYS_DIAG)
  {
    local_APP_DIAG_vdDiagHeartBeat();
  }
  else if(eEcuMode == ECU_SYS_BOOT)
  {
    local_APP_DIAG_vdBootHeartBeat();    
  }
}

void local_APP_DIAG_vdServeDiagRequest(ECU_SYS_eEcuMode_t ECU_Session)
{
	STATUS_t eStatus;
	ECU_SYS_eEcuMode_t eEcuMode;
  
  /* Check the system mode */
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  if(APP_DIAG_eCurrentSession == ECU_SYS_INIT) // Check whether the current session is initialization
  {
    APP_DIAG_eCurrentSession = eEcuMode;
  }
    
  eStatus = ECU_DIAG_u8GetDiagFrame(APP_DIAG_eFrameType, &APP_DIAG_u8DataCount, &APP_DIAG_u8ServiceId, &APP_DIAG_u8SubFunction, &APP_DIAG_u8SuppressPosResponse, APP_DIAG_au8RequestData, ECU_DIAG_FRAME_DATA_BYTES);  
  if(eStatus == STATUS_OK)
  {			
    
    local_APP_DIAG_vdMainStateMachine(eEcuMode);
//    /* Check if it is the Diag session request */
//    if((eEcuMode == ECU_SYS_NORMAL) && (APP_DIAG_u8ServiceId == SID_DIAG_SESSION_CONTROL) && (APP_DIAG_u8DeviceId == (uint8_t)ECU_SYS_DIAG))
//    {
//      ECU_SYS_vdSetEcuMode(ECU_SYS_DIAG);
//      /* Send Positive Response */
//      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_OK);
//    }
//    else if((APP_DIAG_u8ServiceId == SID_DIAG_SESSION_CONTROL))
//    {
//      APP_DIAG_au8ResposneData[0] = (uint8_t)eEcuMode;
//      APP_DIAG_au8ResposneData[1] = 0;
//      APP_DIAG_au8ResposneData[2] = 0;
//      APP_DIAG_au8ResposneData[3] = 0;
//      local_APP_DIAG_EndService(STATUS_NOK, APP_DIAG_au8ResposneData);
//    }
//    else if(eEcuMode == ECU_SYS_DIAG)
//    {
//      /* Serve the request */
//      APP_DIAG_eStatus = APP_DIAG_STATUS_BUSY;
//      local_APP_DIAG_vdMainStateMachine();
//    }
//    else
//    {
//      /* Send Negative Response */
//      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
//    }
  }
  
}

void local_APP_DIAG_vdMainStateMachine(ECU_SYS_eEcuMode_t eEcuMode)
{
  uint8_t u8Count;
  uint8_t u8DataCount = 0;
  
  // check if length of message receieved is wrong to send NRC //
  /*Check if sub-function byte is null*/
  if(APP_DIAG_u8SubFunction == 0x55 || APP_DIAG_u8SubFunction == 0xAA)
  {
    u8DataCount = 1; // only service ID byte
  }
  else
  {
    u8DataCount = 2; // service ID and sub-function bytes
    /*Get data bytes count*/
    for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
    {
      if(APP_DIAG_au8RequestData[u8Count] != 0x55)
      {
        u8DataCount++;
      }
    }    
  }
  if(APP_DIAG_u8DataCount != u8DataCount) 
  {
    local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
  }
  else // Message length is correct
  {
    switch(APP_DIAG_u8ServiceId) 
    {
  #ifdef APP_DIAG_BOOT_SERVICE_ENABLE
      case SID_SECURITY_ACCESS:
      
        break;
      case SID_COMMUNICATION_CONTROL:
        
        break;
      case SID_ACCESS_TIMING_PARAMETER:
        
        break;
      case SID_SECURED_DATA_TRANSMISSION:
        
        break;
      case SID_CONTROL_DTC_SETTING:
        
        break;
      case SID_LINK_CONTROL:
        
        break;
      case SID_READ_DATA_BY_PERIODIC_IDENTIFIER:
        
        break;
      case SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFER:
        local_APP_DIAG_vdIO_Control_Identifier();
        break;
      case SID_REQUEST_DOWNLOAD:
        
        break;
      case SID_REQUEST_UPLOAD:
        
        break;
      case SID_TRANSFER_DATA:
        
        break;
      case SID_REQUEST_TRANSFER_EXIT:
        
        break;
      case SID_REQUEST_FILE_TRANSFER:
        
        break;      
  #endif /*APP_DIAG_BOOT_SERVICE_ENABLE*/
      case SID_DIAG_SESSION_CONTROL:
        local_APP_DIAG_vdDiag_Session_Control(eEcuMode); // Conditions not correct NRC is not fully implemented
        break;
      case SID_ECU_RESET:
        local_APP_DIAG_vdECU_Reset(); // Conditions not correct and security access denied are not implemented
        break;    
      case SID_TESTER_PRESENT:
        local_APP_DIAG_vdTester_Present();
        break;
      case SID_RESPONSE_ON_EVENT:
        
        break;
      case SID_READ_DATA_BY_IDENTIFIER:
        local_APP_DIAG_vdRead_Identifier();      
        break;
      case SID_READ_MEMORY_BY_ADDRESS:
        local_APP_DIAG_vdMemory_Read();      
        break;
      case SID_READ_SCALING_DATA_BY_IDENTIFIER:
        
        break;
      case SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER:
        
        break;
      case SID_WRITE_DATA_BY_IDENTIFIER:
        
        break;
      case SID_WRITE_MEMORY_BY_ADDRESS:
        local_APP_DIAG_vdMemory_Write();      
        break;
      case SID_CLEAR_DIAGNOSTIC_INFORMATION:
        
        break;
      case SID_READ_DTC_INFORMATION:
        
        break;
      case SID_ROUTINE_CONTROL:
        
        break;
      default :  
        local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
    }    
  }
}

void local_APP_DIAG_vdDiag_Session_Control(ECU_SYS_eEcuMode_t eEcuMode)
{
  /*Negative error codes checks*/
  if(APP_DIAG_u8SubFunction == 0 || APP_DIAG_u8SubFunction > 0x3) // sub-function is not supported
  {
    local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_SubFunctionNotSupported);
  }      
  else
  {
    switch(eEcuMode )
    {
    case ECU_SYS_NORMAL:
      if(APP_DIAG_u8SubFunction == ECU_SYS_NORMAL) // default session
      { 
        /*send positive response, relock if client has unlocked before*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        /*re-initialize*/
        ECU_SYS_vdShutdownAndReset();
      }
      else if(APP_DIAG_u8SubFunction == ECU_SYS_BOOT)
      { /*stop each event that has been configured via ResponseOnEvent and enable security*/
        /*output control should be disabled any controlDTC settings should be reset*/
        /*normal communication should be restored*/
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }        
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_FALSE, TAPAS_FALSE);
        ECU_SYS_vdShutdownAndReset();
      }
      else
      { /*stop each event that has been configured via ResponseOnEvent*/
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        /*set to diag mode*/
        ECU_SYS_vdSetEcuMode(ECU_SYS_DIAG);
      }
      break;
    case ECU_SYS_DIAG: //**** Should be added when diag is requested
      if(APP_DIAG_u8SubFunction == ECU_SYS_NORMAL)
      { /*set app valid flag*/
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_TRUE, TAPAS_TRUE);
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        ECU_SYS_vdShutdownAndReset();      
      }
      else if(APP_DIAG_u8SubFunction == ECU_SYS_DIAG)
      { /*stop each event that has been configured via ResponseOnEvent and enable security*/
        /*output control should be disabled any controlDTC settings should be reset*/
        /*normal communication should be restored*/
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }      
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_DIAG);
        ECU_SYS_vdSetEcuMode(ECU_SYS_DIAG);
      }
      else
      {/*stop each event that has been configured via ResponseOnEvent and enable security*/
       /*output control should be disabled any controlDTC settings should be reset*/
       /*normal communication should be restored*/ 
       /*send positive response*/ 
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        } 
       /*reset app valid flag*/
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_FALSE, TAPAS_FALSE);              
        local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_BOOT);        
        ECU_SYS_vdShutdownAndReset();      
      }
      
      break;
    case ECU_SYS_BOOT:
      if(APP_DIAG_u8SubFunction == ECU_SYS_BOOT)
        /*stop each event that has been configured via ResponseOnEvent and relock security*/
        /*all other active diagnostic functionality from previous session and not dependent on security*/
        /*shall be maintained*/
      {
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(0x50,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }    
       /*reset app valid flag*/
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_FALSE, TAPAS_FALSE);               
        local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_BOOT);                
        ECU_SYS_vdShutdownAndReset();
      }
      else if(APP_DIAG_u8SubFunction == ECU_SYS_NORMAL)
      {
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(0x50,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
        /*set appvalid flag*/
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_TRUE, TAPAS_TRUE);
        ECU_SYS_vdShutdownAndReset();      
      }
      else
      {
        /*send positive response*/
        if(APP_DIAG_u8SuppressPosResponse == 0)
        {
          APP_DIAG_au8ResposneData[1] = 0x50;    // P2server is 50 ms - resolution is 1 ms
          APP_DIAG_au8ResposneData[2] = 0x05;    // P2*server is 5000 ms - resolution is 10 ms
          APP_DIAG_au8ResposneData[3] = 0;       // P2*server is 5000 ms - resolution is 10 ms
          local_APP_DIAG_vdSingleFramePositiveResponse(0x50,APP_DIAG_u8SubFunction,APP_DIAG_au8ResposneData,4);                    
        }
        /*check for timing constraint error*/
        if(ECU_DIAG_u8CheckTimerOverflowFlag() == TAPAS_TRUE)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(SID_DIAG_SESSION_CONTROL,APP_DIAG_ConditionsNotCorrect);          
        }
       /*reset app valid flag*/
        ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_FALSE, TAPAS_FALSE);               
        local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_DIAG);                
        ECU_SYS_vdShutdownAndReset();   
      }
      break;
    default:
      break;
    }    
  }

}

void local_APP_DIAG_vdECU_Reset(void)
{
  if(APP_DIAG_u8SubFunction != 0x02)
  {
    local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_SubFunctionNotSupported);    
  }
  else
  {
    local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8DataNotUsed,0);
//    LIB_DELAY_vdNanoSeconds(500000);
    ECU_SYS_vdShutdownAndReset();    
  }
}

void local_APP_DIAG_vdTester_Present(void)
{
  if(APP_DIAG_u8SubFunction != 0x00) // Check if sub-function is supported
  {
    local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_SubFunctionNotSupported);    
  }
  else if(APP_DIAG_u8SuppressPosResponse == TAPAS_FALSE) // Check if positive response is suppressed
  {
    local_APP_DIAG_vdSingleFramePositiveResponse(APP_DIAG_u8ServiceId,APP_DIAG_u8SubFunction,APP_DIAG_au8DataNotUsed,0);    
  }
}

void local_APP_DIAG_vdSingleFramePositiveResponse(uint8_t u8ResponseSID, uint8_t u8SubFunction, uint8_t* pu8Data, uint8_t u8DataSize)
{
  STATUS_t eStatus = STATUS_OK;
  uint8_t u8Count;
  uint8_t u8PR_Data[8] = {0};
  u8PR_Data[0] = u8DataSize + 2;
  u8PR_Data[1] = u8ResponseSID + 0x40;
  u8PR_Data[2] = u8SubFunction;
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
  {
    if(u8Count < u8DataSize)
    {
      u8PR_Data[u8Count + 3] = pu8Data[u8Count];      
    }
    else
    {
      u8PR_Data[u8Count + 3] = 0xAA;
    }
  }
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
  {
    APP_DIAG_au8ResposneData[u8Count] = 0;
  }
  ECU_DIAG_vdEndService(eStatus, u8PR_Data);
}

void local_APP_DIAG_vdSingleFrameNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode)
{
}

void local_APP_DIAG_vdUploadEEPROM_DTC(void)
{
  uint8_t au8CANFrame[6] = {0};
  uint32_t u32SignalID;
  uint32_t u32RawData;
  uint16_t u16Resolution;
  u32SignalID = APP_DIAG_au8RequestData[0] << 24U;
  u32SignalID |= APP_DIAG_au8RequestData[1] << 16U;
  u32SignalID |= APP_DIAG_au8RequestData[2] << 8U;
  u32SignalID |= APP_DIAG_au8RequestData[3];
  ECU_MEM_INT_eReadRawSignalValue(u32SignalID,&u32RawData);    
  u16Resolution = ECU_MEM_INT_u16ReadSignalResolution(u32SignalID);    
  au8CANFrame[0] =  u32RawData >> 24U;
  au8CANFrame[1] =  u32RawData >> 16U;
  au8CANFrame[2] =  u32RawData >> 8U;
  au8CANFrame[3] =  u32RawData;  
  au8CANFrame[4] =  u16Resolution >> 8U; // MSB
  au8CANFrame[5] =  u16Resolution;  // LSB
  local_APP_DIAG_EndServicePlusData(STATUS_OK,au8CANFrame);
}

void local_APP_DIAG_vdIO_Control_Identifier(void)
{
//	switch(APP_DIAG_u8DeviceId) 
//	{
//		default :
//      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
//	}
}

void local_APP_DIAG_vdRead_Identifier(void)
{
//	switch(APP_DIAG_u8DeviceId) 
//	{
//		default :
//      local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
//			break;
//	}
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
//  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE);  
	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
}

void local_APP_DIAG_EndServicePlusData(STATUS_t eStatus, uint8_t *pau8Data)
{
	APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE);  
	ECU_DIAG_vdServiceDonePlusData(eStatus, pau8Data);
}

void local_APP_DIAG_vdMemory_Write(void)
{
//  STATUS_t eStatus = STATUS_NOK;
//  float fltRecData;
//  uint8_t APP_DIAG_au8ReceivedData[4] = {0, 0, 0, 0};
//  uint32_t u32Data = 0;
//  u32Data = APP_DIAG_au8RequestData[0] << 24;
//  u32Data |= APP_DIAG_au8RequestData[1] << 16;
//  u32Data |= APP_DIAG_au8RequestData[2] << 8;
//  u32Data |= APP_DIAG_au8RequestData[3];
//  fltRecData = (float)u32Data;
//  u32Data = u32Data / 100;
//  fltRecData = fltRecData / 100.0f;
//  if(APP_DIAG_u8DeviceId == 0) // Internal Emulated 
//  {
//    eStatus = ECU_MEM_INT_eWriteSignalValue(APP_DIAG_u8RequestId, fltRecData, u32Data);
//  }
//  else // External EEPROM
//  {
//#ifdef ECU_MEM_EXT_MODULE_ENABLE
//  eStatus = ECU_MEM_EXT_eWriteSignalValue(APP_DIAG_u8RequestId, LIB_DATA_fltRaw2Phy(u32Data, 0.01, 0));    
//#else
//  eStatus = STATUS_NOK;
//#endif /*ECU_MEM_EXT_MODULE_ENABLE*/
//  }
//  APP_DIAG_au8ReceivedData[0] = APP_DIAG_au8RequestData[0];
//  APP_DIAG_au8ReceivedData[1] = APP_DIAG_au8RequestData[1];
//  APP_DIAG_au8ReceivedData[2] = APP_DIAG_au8RequestData[2];
//  APP_DIAG_au8ReceivedData[3] = APP_DIAG_au8RequestData[3];  
//  local_APP_DIAG_EndService(eStatus, APP_DIAG_au8ReceivedData);
}

void local_APP_DIAG_vdMemory_Read(void)
{
//  STATUS_t eStatus = STATUS_NOK;
//  uint32_t u32Data;
//  uint8_t APP_DIAG_au8TrialReceivedData[4] = {0, 0, 0, 0};
//  float fltData = 0.0;      
//  if(APP_DIAG_u8DeviceId == 0) // Internal Emulated 
//  {
//    eStatus = ECU_MEM_INT_eReadSignalValue(APP_DIAG_u8RequestId, &fltData);
//  }
//  else // External EEPROM
//  {
//#ifdef ECU_MEM_EXT_MODULE_ENABLE
//  eStatus = ECU_MEM_EXT_eReadSignalValue(APP_DIAG_u8RequestId, &fltData);    
//  u32Data =(uint32_t) (fltData * 100);
//#else
//  eStatus = STATUS_NOK;
//#endif /*ECU_MEM_EXT_MODULE_ENABLE*/
//  
//  }
//  u32Data = (uint32_t)(fltData * 100);
//  APP_DIAG_au8TrialReceivedData[0] = (u32Data >> 24);
//  APP_DIAG_au8TrialReceivedData[1] = (u32Data >> 16);
//  APP_DIAG_au8TrialReceivedData[2] = (u32Data >> 8);
//  APP_DIAG_au8TrialReceivedData[3] = (u32Data); 
//  local_APP_DIAG_EndService(eStatus, APP_DIAG_au8TrialReceivedData);
}

STATUS_t local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_eEcuMode_t Mode)
{
  uint32_t u32RawData = 0x80000000;
  STATUS_t eStatus = STATUS_NOK;
  u32RawData |= Mode;
  eStatus  = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_ECU_MODE_PLUS_FLAG, 0.0, u32RawData);
  return eStatus;
}

uint8_t APP_DIAG_u8DefaultEcuModeCheck(ECU_SYS_eEcuMode_t* Mode)
{
  uint8_t u8Flag = TAPAS_FALSE;
  uint32_t u32RawData;
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_ECU_MODE_PLUS_FLAG, &u32RawData);
  u8Flag = u32RawData >> 31U;
  *Mode = (ECU_SYS_eEcuMode_t)u32RawData;
  ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_ECU_MODE_PLUS_FLAG, 0.0, 0);
  return u8Flag;
}

void local_APP_DIAG_vdDiagHeartBeat(void)
{
	static uint32_t su32HeartBeatCounter = 1;
  
  if((su32HeartBeatCounter*APP_DIAG_TASK_MS) == APP_DIAG_HEARTBEAT_HALF_PERIOD_MS)
  {
    ECU_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_TOGGLE);
    su32HeartBeatCounter = 1;
  }
  else
  {
    su32HeartBeatCounter++;
  }
}

void local_APP_DIAG_vdBootHeartBeat(void)
{
  static uint32_t su32HeartBeatCounter = 1;
  static uint8_t su8Counter = 0;
    
  if(((su32HeartBeatCounter*APP_BOOT_TASK_MS) == APP_BOOT_HEARTBEAT_HALF_PERIOD_MS) && (su8Counter < (APP_BOOT_HEARTBEAT_FAST_COUNT*2)))
  {
    ECU_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_TOGGLE);
    su32HeartBeatCounter = 1;
    su8Counter++;
  }
  else if(su8Counter == (APP_BOOT_HEARTBEAT_FAST_COUNT*2))
  {
    ECU_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_ON);
    su8Counter = (APP_BOOT_HEARTBEAT_FAST_COUNT*2) + 1;
    su32HeartBeatCounter++;
  }
  else if ((su32HeartBeatCounter*APP_BOOT_TASK_MS) == APP_BOOT_HEARTBEAT_STATIC_PERIOD_MS)
  {
    su32HeartBeatCounter = 1;
    su8Counter = 0;
  }
  else
  {
    su32HeartBeatCounter++;
  }
}

#endif /*APP_DIAG_ENABLE*/
