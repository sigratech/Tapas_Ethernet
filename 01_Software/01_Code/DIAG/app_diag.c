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
uint8_t APP_DIAG_au8IndexOfZeroDataReceived[8] = {0,0,0,0,0,0,0,0};
uint8_t APP_DIAG_au8DataNotUsed[8] = {0,0,0,0,0,0,0,0};
ECU_SYS_eEcuMode_t APP_DIAG_eCurrentSession;
uint32_t APP_DIAG_u32ApplicationEndAddress = 0;
APP_DIAG_strFlowControl_t FlowControlFrame = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_u8FlowControlExpected = TAPAS_FALSE;
uint8_t APP_DIAG_u8FlowControlServiceID = TAPAS_FALSE;
APP_DIAG_strConsecutiveFrame_t ConsecutiveFlowFrame = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_DIAG_u8FirstFrameServiceID = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8ConsecutiveFrameServiceID = TAPAS_DEFAULT;
uint8_t APP_DIAG_u8ConsecutiveFrameSequenceNumber = TAPAS_DEFAULT;
/*Global variables of SID 0x23 ReadMemoryByAddress*/
uint8_t APP_DIAG_au8ReadDataByAddress[APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_NUMBER] = {TAPAS_DEFAULT};
uint8_t APP_DIAG_u8ReadDataByAddress_BytesNum;
uint32_t APP_DIAG_u32ReadDataByAddress_SeparationTimeInNanoSeconds;
uint8_t APP_DIAG_u8ReadDataByAddress_FirstFlowControl = TAPAS_FALSE;
uint8_t APP_DIAG_u8ReadDataByAddress_RemainingBytes ;
uint8_t APP_DIAG_u8ReadDataByAddress_GlobalCounter = TAPAS_FALSE;
uint8_t APP_DIAG_u8ReadDataByAddress_Wait;
uint8_t APP_DIAG_u8ReadDataByAddress_OverFlow;
/*Global variables of SID 0x3D WriteMemoryByAddress*/
uint8_t APP_DIAG_u8WriteDataByAddress_ServiceTotalBytesNum;
uint8_t APP_DIAG_u8WriteDataByAddress_SizeBytesNum;
uint8_t APP_DIAG_u8WriteDataByAddress_AddressBytesNum;
uint8_t APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_FALSE;
uint32_t APP_DIAG_u32WriteDataByAddress_Address;
uint8_t APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_WRITE_DATA_BY_ADDRESS_MAX_BYTES_NUMBER] = {TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT};
uint8_t APP_DIAG_u8WriteDataByAddress_BytesIndex = 0;
uint8_t APP_DIAG_u8WriteDataByAddress_DataBytesCount;
uint8_t APP_DIAG_u8WriteDataByAddress_ZeroElementsReceived = 0;

void local_APP_DIAG_vdDiagHeartBeat(void);
void local_APP_DIAG_vdMainStateMachine(ECU_SYS_eEcuMode_t eEcuMode);
void local_APP_DIAG_vdIO_Control_Identifier(void);
void local_APP_DIAG_vdRead_Identifier(void);
void local_APP_DIAG_vdMemory_Write(void);
void local_APP_DIAG_vdMemory_Read(void);
void local_APP_DIAG_vdServeDiagRequest(ECU_SYS_eEcuMode_t ECU_Session);
void local_APP_DIAG_vdDiag_Session_Control(ECU_SYS_eEcuMode_t eEcuMode);
void local_APP_DIAG_vdNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode);
void local_APP_DIAG_vdBootHeartBeat(void);
void local_APP_DIAG_vdSingleFramePositiveResponse(uint8_t u8ResponseSID, uint8_t u8SubFunction, uint8_t* pu8Data, uint8_t u8DataSize);
void local_APP_DIAG_vdSingleFrameNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode);
void local_APP_DIAG_vdECU_Reset(void);
void local_APP_DIAG_vdTester_Present(void);
void local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_eEcuMode_t Mode);
void local_APP_DIAG_EndServicePlusData(STATUS_t eStatus, uint8_t *pau8Data);
uint8_t local_APP_DIAG_u8AppValidCheck(void);
void local_APP_DIAG_vdAppValidClear(void);
void local_APP_DIAG_vdAppValidSet(void);
uint8_t APP_DIAG_u8DefaultEcuModeCheck(ECU_SYS_eEcuMode_t* Mode);
void local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_eEcuMode_t Mode);
uint8_t local_APP_DIAG_u8SingleFrameLengthErrorCheck(void);
void local_APP_DIAG_vdFramePositiveResponseWithFullArrayBytes(uint8_t* pu8Data);
void local_APP_DIAG_vdSingleFramePositiveResponseWithoutSubfunction(uint8_t u8ResponseSID, uint8_t* pu8Data, uint8_t u8DataSize);
void local_APP_DIAG_vdReadMemoryByAddressInitializeArray(void);
void local_APP_DIAG_vdWriteMemoryByAddressFirstFrameHandler(void);
void local_APP_DIAG_vdWriteMemoryByAddressConsecutiveFrameHandler(void);
uint8_t local_APP_DIAG_u8NumberOfZeroElementsReceived(void);
void local_APP_DIAG_vdResetAllGlobalVariables(void);
void local_APP_DIAG_vdResetArray(uint8_t* pau8Array, uint8_t u8ArraySize);
void local_APP_DIAG_vdClearReceivingVariables(void);

void APP_DIAG_vdInit(void)
{
  float fltStartAddress;
  float fltEndAddress;
  ECU_DIAG_vdRegisterAppDiagCallback(local_APP_DIAG_vdServeDiagRequest);
  APP_DIAG_eCurrentSession = ECU_SYS_eGetEcuMode();
  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_PROGRAM_START_ADDRESS,&fltStartAddress);
  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_PROGRAM_END_ADDRESS,&fltEndAddress);
  APP_DIAG_u32ApplicationEndAddress = (uint32_t)fltEndAddress;
  if(local_APP_DIAG_u8AppValidCheck() == TAPAS_TRUE)
  {
    ECU_SYS_vdGoToApplication(APP_DIAG_APPLICATION_START_ADDRESS);    
  }
  local_APP_DIAG_vdResetArray(APP_DIAG_u8WriteDataByAddress_DataBytes,APP_DIAG_WRITE_DATA_BY_ADDRESS_MAX_BYTES_NUMBER); // trials showed that this array gets corrupted upon initialization
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
  
//  //debug
//  goto Reinitialize;
  
  /* Check the system mode */
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  if(APP_DIAG_eCurrentSession == ECU_SYS_INIT) // Check whether the current session is initialization
  {
    APP_DIAG_eCurrentSession = eEcuMode;
  }
    
  eStatus = ECU_DIAG_u8GetDiagFrame(&APP_DIAG_eFrameType, &APP_DIAG_u8DataCount, &APP_DIAG_u8ServiceId, &APP_DIAG_u8SubFunction, &APP_DIAG_u8SuppressPosResponse, APP_DIAG_au8RequestData, ECU_DIAG_FRAME_DATA_BYTES, APP_DIAG_au8IndexOfZeroDataReceived);  
  // 1st byte:APP_DIAG_eFrameType(7:4) and APP_DIAG_u8DataCount(3:0),2nd byte:APP_DIAG_u8ServiceId,3rd byte:APP_DIAG_u8SubFunction(6:0)and APP_DIAG_u8SuppressPosResponse(7),4th to 8th:APP_DIAG_au8RequestData
  if(eStatus == STATUS_OK)
  {	
//    if()
//    {
//      
//    }
//    if(APP_DIAG_eFrameType == ECU_DIAG_FirstFrame && APP_DIAG_u8SubFunction == SID_WRITE_MEMORY_BY_ADDRESS) // check if write memory by address SID
//    {
//      local_APP_DIAG_vdWriteMemoryByAddressFirstFrameHandler(); // function to receive FF, send FC and prepare data to be written into memory
//      APP_DIAG_u8ServiceId = SID_WRITE_MEMORY_BY_ADDRESS;
//    }		
    local_APP_DIAG_vdMainStateMachine(eEcuMode);
  }
}

void local_APP_DIAG_vdMainStateMachine(ECU_SYS_eEcuMode_t eEcuMode)
{
  if(APP_DIAG_eFrameType == ECU_DIAG_FirstFrame)
  {
    APP_DIAG_u8FirstFrameServiceID = APP_DIAG_u8ServiceId;
    APP_DIAG_u8ServiceId = APP_DIAG_u8SubFunction;
  }
  else if(APP_DIAG_eFrameType == ECU_DIAG_FlowControl)
  {
    if(FlowControlFrame.u8ExpectedFC_Flag == TAPAS_TRUE)
    {
      APP_DIAG_u8FlowControlServiceID = APP_DIAG_u8ServiceId; // this variable is added to handle the case of flow control, since APP_DIAG_u8ServiceId is altered to skip the state machine, APP_DIAG_u8FlowControlServiceID is the variable used afterwards through flow control algorithm
      APP_DIAG_u8ServiceId = FlowControlFrame.u8ServiceID;
    }
    else
    {
      // NRC corresponding to receiving flow control without previous frames - not expecting to receive such message     
      APP_DIAG_u8ServiceId = 0; // to skip state machine
    }
  }
  else if(APP_DIAG_eFrameType == ECU_DIAG_ConsecutiveFrame)
  {
    if(ConsecutiveFlowFrame.u8ExpectedCF_Flag == TAPAS_TRUE)
    {
      if(APP_DIAG_u8DataCount != APP_DIAG_u8ConsecutiveFrameSequenceNumber)
      {
        local_APP_DIAG_vdSingleFrameNegativeResponse(ConsecutiveFlowFrame.u8SeriveID, APP_DIAG_WrongBlockSequenceCounter);// NRC corresponding to wrong sequence number
      }
      else
      {
        APP_DIAG_u8ConsecutiveFrameServiceID = APP_DIAG_u8ServiceId; // this variable is added to handle the case of consecutive frame, since APP_DIAG_u8ServiceId is altered to skip the state machine, APP_DIAG_u8ConsecutiveFlowServiceID is the variable used afterwards through consecutive frame algorithm
        APP_DIAG_u8ServiceId = ConsecutiveFlowFrame.u8SeriveID;              
        APP_DIAG_u8ConsecutiveFrameSequenceNumber++;
        if(APP_DIAG_u8ConsecutiveFrameSequenceNumber == 0x10) // wrap-around check, range is from 0 to 15 
        {
          APP_DIAG_u8ConsecutiveFrameSequenceNumber = 0;
        }
      }
    }
    else
    {
      // NRC corresponding to receiving consecutive frame without previous frames - not expecting to receive such message
      APP_DIAG_u8ServiceId = 0; // to skip state machine
    }
  }
  else if(APP_DIAG_eFrameType == ECU_DIAG_SingleFrame)
  {
    if(local_APP_DIAG_u8SingleFrameLengthErrorCheck() == TAPAS_FALSE) 
    {
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
      APP_DIAG_u8ServiceId = 0; // to skip state machine
    }    
  }
  switch(APP_DIAG_u8ServiceId) 
  {
    case SID_SECURITY_ACCESS:
#ifdef SID_SECURITY_ACCESS
      
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_SECURITY_ACCESS*/  
      break;
      
    case SID_COMMUNICATION_CONTROL:
#ifdef SID_COMMUNICATION_CONTROL
      
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_COMMUNICATION_CONTROL*/        
      break;
      
    case SID_ACCESS_TIMING_PARAMETER:
#ifdef SID_COMMUNICATION_CONTROL
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupported);   
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_COMMUNICATION_CONTROL*/       
      break;
      
    case SID_SECURED_DATA_TRANSMISSION:
#ifdef SID_SECURED_DATA_TRANSMISSION

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_SECURED_DATA_TRANSMISSION*/       
      break;
      
    case SID_CONTROL_DTC_SETTING:
#ifdef SID_CONTROL_DTC_SETTING

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_CONTROL_DTC_SETTING*/        
      break;
    case SID_LINK_CONTROL:
#ifdef SID_LINK_CONTROL

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_LINK_CONTROL*/       
      break;
      
    case SID_READ_DATA_BY_PERIODIC_IDENTIFIER:
#ifdef SID_READ_DATA_BY_PERIODIC_IDENTIFIER

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_READ_DATA_BY_PERIODIC_IDENTIFIER*/       
      break;
      
    case SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFER:
#ifdef SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFER
      local_APP_DIAG_vdIO_Control_Identifier();
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFER*/          
      break;
      
    case SID_REQUEST_DOWNLOAD:
#ifdef SID_REQUEST_DOWNLOAD

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_REQUEST_DOWNLOAD*/       
      break;
      
    case SID_REQUEST_UPLOAD:
#ifdef SID_REQUEST_UPLOAD

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_REQUEST_UPLOAD*/      
      break;
      
    case SID_TRANSFER_DATA:
#ifdef SID_TRANSFER_DATA

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_TRANSFER_DATA*/      
      break;
      
    case SID_REQUEST_TRANSFER_EXIT:
#ifdef SID_REQUEST_TRANSFER_EXIT

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_REQUEST_TRANSFER_EXIT*/      
      break;
      
    case SID_REQUEST_FILE_TRANSFER:
#ifdef SID_REQUEST_FILE_TRANSFER

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_REQUEST_FILE_TRANSFER*/       
      break;    
      
    case SID_DIAG_SESSION_CONTROL:
#ifdef SID_DIAG_SESSION_CONTROL
      local_APP_DIAG_vdDiag_Session_Control(eEcuMode); // Conditions not correct NRC is not fully implemented
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_DIAG_SESSION_CONTROL*/      
      break;
      
    case SID_ECU_RESET:
#ifdef SID_ECU_RESET
      local_APP_DIAG_vdECU_Reset(); // Conditions not correct and security access denied are not implemented
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_ECU_RESET*/        
      break;    
      
    case SID_TESTER_PRESENT:
#ifdef SID_TESTER_PRESENT
      local_APP_DIAG_vdTester_Present();
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_TESTER_PRESENT*/       
      break;
      
    case SID_RESPONSE_ON_EVENT:
#ifdef SID_RESPONSE_ON_EVENT

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_RESPONSE_ON_EVENT*/        
      break;
      
    case SID_READ_DATA_BY_IDENTIFIER:
#ifdef SID_READ_DATA_BY_IDENTIFIER
      local_APP_DIAG_vdRead_Identifier();
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_READ_DATA_BY_IDENTIFIER*/             
      break;
      
    case SID_READ_MEMORY_BY_ADDRESS:
#ifdef SID_READ_MEMORY_BY_ADDRESS
      local_APP_DIAG_vdMemory_Read();      
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_READ_MEMORY_BY_ADDRESS*/       
      break;
      
    case SID_READ_SCALING_DATA_BY_IDENTIFIER:
#ifdef SID_READ_SCALING_DATA_BY_IDENTIFIER

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_READ_SCALING_DATA_BY_IDENTIFIER*/         
      break;
      
    case SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER:
#ifdef SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER*/        
      break;
      
    case SID_WRITE_DATA_BY_IDENTIFIER:
#ifdef SID_WRITE_DATA_BY_IDENTIFIER

#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_WRITE_DATA_BY_IDENTIFIER*/      
      break;
      
    case SID_WRITE_MEMORY_BY_ADDRESS:
#ifdef SID_WRITE_MEMORY_BY_ADDRESS
      local_APP_DIAG_vdMemory_Write();      
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_WRITE_MEMORY_BY_ADDRESS*/      
      break;
      
    case SID_CLEAR_DIAGNOSTIC_INFORMATION:
#ifdef SID_CLEAR_DIAGNOSTIC_INFORMATION
     
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_CLEAR_DIAGNOSTIC_INFORMATION*/      
      break;
      
    case SID_READ_DTC_INFORMATION:
#ifdef SID_READ_DTC_INFORMATION
     
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_READ_DTC_INFORMATION*/          
      break;
      
    case SID_ROUTINE_CONTROL:
#ifdef SID_ROUTINE_CONTROL
     
#else
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupportedInActiveSession);
#endif /*SID_ROUTINE_CONTROL*/         
      break;
      
    default :  
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_ServiceNotSupported);
      break;
      //local_APP_DIAG_EndServiceWithEchoArray(APP_DIAG_au8DataNotUsed, STATUS_NOK);
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
        local_APP_DIAG_vdAppValidClear();
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
        local_APP_DIAG_vdAppValidSet();
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
        local_APP_DIAG_vdAppValidClear();              
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
        local_APP_DIAG_vdAppValidClear();               
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
        local_APP_DIAG_vdAppValidSet();
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
        local_APP_DIAG_vdAppValidClear();               
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

void local_APP_DIAG_vdIO_Control_Identifier(void)
{

}

void local_APP_DIAG_vdRead_Identifier(void)
{

}

void local_APP_DIAG_vdMemory_Write(void)
{
  if(APP_DIAG_eFrameType == ECU_DIAG_FirstFrame && APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished != TAPAS_TRUE) // check if ff and all data are not received yet
  {
    APP_DIAG_u8WriteDataByAddress_ZeroElementsReceived = local_APP_DIAG_u8NumberOfZeroElementsReceived();
    local_APP_DIAG_vdWriteMemoryByAddressFirstFrameHandler();
  }
  else if(APP_DIAG_eFrameType == ECU_DIAG_ConsecutiveFrame && APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished != TAPAS_TRUE) // check if cf and all data are not received yet
  {
    local_APP_DIAG_vdWriteMemoryByAddressConsecutiveFrameHandler();
  }
  else if (APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished == TAPAS_TRUE) // check if all data are received to start writing them into memory
  {
    uint8_t u8AddressLastByte = (APP_DIAG_u32WriteDataByAddress_Address >> 24U); //this variable to make sure address is 32-bit
    //Minimum length check
    if(u8AddressLastByte == 0 || APP_DIAG_u8WriteDataByAddress_ServiceTotalBytesNum == 0 || APP_DIAG_u8WriteDataByAddress_DataBytesCount == 0 || APP_DIAG_u8WriteDataByAddress_SizeBytesNum == 0 || APP_DIAG_u8WriteDataByAddress_AddressBytesNum == 0)
    {
      ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_FALSE;
      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
    }
//    if(APP_DIAG_u8WriteDataByAddress_ZeroElementsReceived > 3) // if true, this means 
//    {
//      ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_FALSE;
//      local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
//    }
    else
    {
//      uint32_t u32MemoryAddress;
//      uint8_t u8AddressBytesNumber = (APP_DIAG_u8SubFunction & 0x0F);
//      uint8_t u8DataBytesNumber = (APP_DIAG_u8SubFunction & 0xF0) >> 4U; 
//      u32MemoryAddress =  APP_DIAG_au8RequestData[0] << 24U;
//      u32MemoryAddress |=  APP_DIAG_au8RequestData[1] << 16U;
//      u32MemoryAddress |=  APP_DIAG_au8RequestData[2] << 8U;
//      u32MemoryAddress |=  APP_DIAG_au8RequestData[3];
//      APP_DIAG_u8WriteDataByAddress_BytesNum = APP_DIAG_au8RequestData[4];
      
      //Check on addressandlengthformatidentifier if applicable
      if(APP_DIAG_u32WriteDataByAddress_Address < 0xF0200000 || APP_DIAG_u32WriteDataByAddress_Address > 0xF020FFFF || APP_DIAG_u8WriteDataByAddress_DataBytesCount > APP_DIAG_WRITE_DATA_BY_ADDRESS_MAX_BYTES_NUMBER)
      {
        ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_FALSE;
        local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_RequestOutOfRange);
      }
      else if(APP_DIAG_u8WriteDataByAddress_SizeBytesNum != 1 || APP_DIAG_u8WriteDataByAddress_AddressBytesNum != 4) // total length check
      {
        ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_FALSE;
        local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_RequestOutOfRange);
      }    
      else 
      {
      /******** Security check should be added here as else if statement***********/
//        uint8_t u8Counter;
//        uint8_t au8WriteDataTemp[APP_DIAG_WRITE_DATA_BY_ADDRESS_MAX_BYTES_NUMBER] = {0};
//        for(u8Counter = 0; u8Counter < APP_DIAG_u8WriteDataByAddress_DataBytesCount; u8Counter++)
//        {
//          au8WriteDataTemp[u8Counter] = APP_DIAG_u8WriteDataByAddress_DataBytes[u8Counter];
//        }
        
        STATUS_t eStatus = ECU_MEM_INT_eWriteFourSignalsByAddress(APP_DIAG_u32WriteDataByAddress_Address, APP_DIAG_u8WriteDataByAddress_DataBytes, APP_DIAG_u8WriteDataByAddress_DataBytesCount);
        if(eStatus == STATUS_NOK)
        {
          local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_RequestOutOfRange);
        }
        else
        {
          uint8_t u8AddressAndLength = (APP_DIAG_u8WriteDataByAddress_SizeBytesNum << 4U);
          u8AddressAndLength |= (APP_DIAG_u8WriteDataByAddress_AddressBytesNum && 0x0F);
          uint8_t au8CanPositiveResponse[5] = {0};
          au8CanPositiveResponse[0] = (APP_DIAG_u32WriteDataByAddress_Address >> 24U);
          au8CanPositiveResponse[1] = (APP_DIAG_u32WriteDataByAddress_Address >> 16U);  
          au8CanPositiveResponse[2] = (APP_DIAG_u32WriteDataByAddress_Address >> 8U);  
          au8CanPositiveResponse[3] = (APP_DIAG_u32WriteDataByAddress_Address);
          au8CanPositiveResponse[4] = APP_DIAG_u8WriteDataByAddress_DataBytesCount;
          local_APP_DIAG_vdSingleFramePositiveResponse(0x3D, u8AddressAndLength, au8CanPositiveResponse, 5);
        }
        ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_FALSE;
        local_APP_DIAG_vdResetAllGlobalVariables();
      }
    }
  }
}

void local_APP_DIAG_vdMemory_Read(void)
{
  //Minimum length check
  if(APP_DIAG_u8DataCount < 4 && APP_DIAG_eFrameType == ECU_DIAG_SingleFrame)
  {
    local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
  }
  else
  {
    if(FlowControlFrame.u8ExpectedFC_Flag == TAPAS_FALSE && APP_DIAG_eFrameType == ECU_DIAG_SingleFrame) //Check whether this is the first frame or consecutive frame
    {
      uint32_t u32MemoryAddress;
      uint8_t u8Counter = 0;
      uint8_t u8Count;
      uint8_t u8LoopCounter;
      uint8_t u8AddressBytesNumber = (APP_DIAG_u8SubFunction & 0x0F);
      uint8_t u8DataBytesNumber = (APP_DIAG_u8SubFunction & 0xF0) >> 4U;
      uint8_t au8CanFrame[8] = {0};
      u32MemoryAddress =  APP_DIAG_au8RequestData[0] << 24U;
      u32MemoryAddress |=  APP_DIAG_au8RequestData[1] << 16U;
      u32MemoryAddress |=  APP_DIAG_au8RequestData[2] << 8U;
      u32MemoryAddress |=  APP_DIAG_au8RequestData[3];
      APP_DIAG_u8ReadDataByAddress_BytesNum = APP_DIAG_au8RequestData[4];
      //Check on addressandlengthformatidentifier if applicable
      if(u32MemoryAddress < 0xF0200000 || u32MemoryAddress > 0xF020FFFF || APP_DIAG_u8ReadDataByAddress_BytesNum > APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_NUMBER)
      {
        local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_RequestOutOfRange);
      }
      else if(u8DataBytesNumber != 1 || u8AddressBytesNumber != 4) // total length check
      {
        local_APP_DIAG_vdSingleFrameNegativeResponse(APP_DIAG_u8ServiceId,APP_DIAG_IncorrectMessageLengthOrInvalidFormat);
      }
      else
      {
        /******** Security check should be added here as else if statement***********/
        
        //Fill array of data from memory
        if(APP_DIAG_u8FlowControlExpected == 0) //done first time only
        {
          uint8_t u8BytesNumTemp = APP_DIAG_u8ReadDataByAddress_BytesNum;
          APP_DIAG_u8FlowControlExpected = 1;
          uint8_t u8LoopMax = APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS; 
          
          if(u8BytesNumTemp % APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS == 0) // 16, 32, 64, 128
          {
            for(u8LoopCounter = 0; u8LoopCounter < u8BytesNumTemp; u8LoopCounter = u8LoopCounter + APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS)
            {
              uint8_t au8TempData[APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS] = {0};
              ECU_MEM_INT_eReadBlock(u32MemoryAddress, au8TempData);              
              for(u8Count = 0; u8Count < u8LoopMax; u8Count++)
              {
                APP_DIAG_au8ReadDataByAddress[u8LoopCounter + u8Count] =  au8TempData[u8Count];                
              }
              u32MemoryAddress = u32MemoryAddress + APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS; 
            }
          }
          else 
          {
            while(u8BytesNumTemp % APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS != 0)
            {
              if(u8BytesNumTemp / APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS == 0)
              {
                u8LoopMax = u8BytesNumTemp;
              }
              uint8_t au8TempData[APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS] = {0};
              ECU_MEM_INT_eReadBlock(u32MemoryAddress, au8TempData);
              for(u8Count = 0; u8Count < u8LoopMax; u8Count++)
              {
                APP_DIAG_au8ReadDataByAddress[u8Counter + u8Count] =  au8TempData[u8Count];
              }
              u32MemoryAddress = u32MemoryAddress + APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS;      
              u8BytesNumTemp = u8BytesNumTemp - APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS;
              u8Counter = u8Counter + APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_PER_ADDRESS;
              if(u8BytesNumTemp > APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_NUMBER)
              {
                u8BytesNumTemp = 0;
              }
            }            
          }        
        }
        
        if(APP_DIAG_u8ReadDataByAddress_BytesNum <= 6) // check if data read could fit in single frame .. 6 is the maximum data bytes could be embedded in SF message
        {
          //Send single frame which has number of following data bytes
          for(u8Counter = 0; u8Counter < APP_DIAG_u8ReadDataByAddress_BytesNum; u8Counter++)
          {
            au8CanFrame[u8Counter] = APP_DIAG_au8ReadDataByAddress[u8Counter];
          }
          local_APP_DIAG_vdSingleFramePositiveResponseWithoutSubfunction(APP_DIAG_u8ServiceId,au8CanFrame,APP_DIAG_u8ReadDataByAddress_BytesNum);                            
        }
        else
        {
          //Send first frame which has number of following data bytes
          au8CanFrame[0] = 0x10;
          au8CanFrame[1] = APP_DIAG_u8ReadDataByAddress_BytesNum;
          au8CanFrame[2] = 0x63;
          for(u8Counter = 0; u8Counter < 5; u8Counter++)
          {
            au8CanFrame[u8Counter + 3] = APP_DIAG_au8ReadDataByAddress[u8Counter];            
          }
          FlowControlFrame.u8ExpectedFC_Flag = TAPAS_TRUE;
          FlowControlFrame.u8ServiceID = SID_READ_MEMORY_BY_ADDRESS;
          APP_DIAG_u8ReadDataByAddress_FirstFlowControl = 1;
          local_APP_DIAG_vdFramePositiveResponseWithFullArrayBytes(au8CanFrame);     
        }
      }
    }
    else
    {
      // check of flow control 1st byte ..flow status //
      if(APP_DIAG_u8DataCount == 1) 
      {
        APP_DIAG_u8ReadDataByAddress_Wait = 1;
      }
      else if(APP_DIAG_u8DataCount == 2) 
      {
        APP_DIAG_u8ReadDataByAddress_OverFlow = 1;
      }
      // check of flow control 2nd byte ..block size //      
      if(APP_DIAG_u8FlowControlServiceID != 0)
      {
        FlowControlFrame.u8MaxNumberOfConsecutiveFrames = APP_DIAG_u8FlowControlServiceID;
      }
      // check of flow control 3rd byte ..separation time //
      if(APP_DIAG_u8SubFunction != 0) 
      {
        if(APP_DIAG_u8SubFunction <= 0x7F) // milli seconds
        {
          APP_DIAG_u32ReadDataByAddress_SeparationTimeInNanoSeconds = APP_DIAG_u8SubFunction * 1000000;
        }
        else if(APP_DIAG_u8SubFunction >= 0xF1 && APP_DIAG_u8SubFunction <= 0xF9)
        {
          APP_DIAG_u32ReadDataByAddress_SeparationTimeInNanoSeconds = APP_DIAG_u8SubFunction * 1000;
        }
      }
      else
      {
        APP_DIAG_u32ReadDataByAddress_SeparationTimeInNanoSeconds = 0;
      }
//      }
      if(APP_DIAG_u8ReadDataByAddress_Wait == 0 && APP_DIAG_u8ReadDataByAddress_OverFlow == 0)
      {
        //Send consecutive frames which has requested data
        uint8_t u8Count;
        uint8_t u8TempCount;
        uint8_t u8PciSequenceNumber = 0x20;
        uint8_t au8CanFrame[8] = {APP_DIAG_RESPONSE_FILLER};
        uint8_t u8InnerLoopMax;
        APP_DIAG_u8ReadDataByAddress_RemainingBytes = APP_DIAG_u8ReadDataByAddress_BytesNum - 5 - (FlowControlFrame.u8NumberOfFramesSent * 7);//5 is the maximum data bytes could be embedded in SF message and the start of data bytes to be send in CF
        while(APP_DIAG_u8ReadDataByAddress_RemainingBytes > 0)
        {
          for(u8TempCount = 0; u8TempCount < 8; u8TempCount++)
          {
            au8CanFrame[u8TempCount] = APP_DIAG_RESPONSE_FILLER;            
          }
          au8CanFrame[0] = u8PciSequenceNumber; // first byte is the pci plus sequence number
          if((APP_DIAG_u8ReadDataByAddress_RemainingBytes - 7) < 0) // check if this is the last loop
          {
            u8InnerLoopMax = APP_DIAG_u8ReadDataByAddress_RemainingBytes;
          }
          else 
          {
            u8InnerLoopMax = 7;
          }
          for(u8Count = 0; u8Count < u8InnerLoopMax; u8Count++) // fill frame with bytes starting from data which has been sent either in FF or last loop
          {
            au8CanFrame[u8Count + 1] = APP_DIAG_au8ReadDataByAddress[u8Count + APP_DIAG_u8ReadDataByAddress_GlobalCounter + 5];
          }    
          local_APP_DIAG_vdFramePositiveResponseWithFullArrayBytes(au8CanFrame);
          //Separation time received from Flow Control message
          LIB_DELAY_vdNanoSeconds(APP_DIAG_u32ReadDataByAddress_SeparationTimeInNanoSeconds);
          u8PciSequenceNumber++;
          if(u8PciSequenceNumber == 0x30) // wrap around check
          {
            u8PciSequenceNumber = 0x20;
          }          
          APP_DIAG_u8ReadDataByAddress_GlobalCounter = APP_DIAG_u8ReadDataByAddress_GlobalCounter + 7;
          APP_DIAG_u8ReadDataByAddress_RemainingBytes = APP_DIAG_u8ReadDataByAddress_RemainingBytes - 7;
          FlowControlFrame.u8NumberOfFramesSent++;
          //Decrement consecutive frame index
          FlowControlFrame.u8ConsecutiveFrameIndex++;
          if(FlowControlFrame.u8ConsecutiveFrameIndex == FlowControlFrame.u8MaxNumberOfConsecutiveFrames)
          {
            APP_DIAG_u8FlowControlExpected = 1;
            break;
          }          
          if(APP_DIAG_u8ReadDataByAddress_RemainingBytes > 128 || APP_DIAG_u8ReadDataByAddress_RemainingBytes == 0) // Signales end of reading
          {
            FlowControlFrame.u8ExpectedFC_Flag = TAPAS_FALSE;
            APP_DIAG_u8FlowControlExpected = 0;
            APP_DIAG_u8ReadDataByAddress_RemainingBytes = 0;
            APP_DIAG_u8ReadDataByAddress_BytesNum = 0;
            APP_DIAG_u8ReadDataByAddress_GlobalCounter = 0;
            APP_DIAG_u8ReadDataByAddress_FirstFlowControl = 0;
            local_APP_DIAG_vdReadMemoryByAddressInitializeArray();
          }
        }
        //  local_APP_DIAG_vdResetAllGlobalVariables();
      }
    }
  }
}

void local_APP_DIAG_vdWriteMemoryByAddressConsecutiveFrameHandler(void)
{
  uint8_t u8Count;
  switch(APP_DIAG_u8DataCount) // represents sequence number
  {
  case 0:
    APP_DIAG_u8WriteDataByAddress_DataBytesCount = APP_DIAG_u8ConsecutiveFrameServiceID;
    if(APP_DIAG_u8WriteDataByAddress_DataBytesCount == 1) // check if data bytes to be written is only 1
    {
      APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
      APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8SubFunction; // 1st byte    
    }
    else if(APP_DIAG_u8WriteDataByAddress_DataBytesCount == 0)
    {
      APP_DIAG_u8WriteDataByAddress_ZeroElementsReceived++;
    }
    else // data bytes to be written > 1
    {
      APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8SubFunction; // 1st byte     
      APP_DIAG_u8WriteDataByAddress_BytesIndex++;
      if(APP_DIAG_u8WriteDataByAddress_BytesIndex == APP_DIAG_u8WriteDataByAddress_DataBytesCount)
      {
        APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;        
        break;
      }        
      for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++) // loop to fill data bytes in CF, 5 data bytes are in array
      {
        if((u8Count + APP_DIAG_u8WriteDataByAddress_BytesIndex) == APP_DIAG_u8WriteDataByAddress_DataBytesCount) // check whether all data bytes have been already read
        {
          APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
          break;
        }
        else
        {
          APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex + u8Count] = APP_DIAG_au8RequestData[u8Count]; // fill array with data bytes
        }
      }
      APP_DIAG_u8WriteDataByAddress_BytesIndex = APP_DIAG_u8WriteDataByAddress_BytesIndex + ECU_DIAG_FRAME_DATA_BYTES; // increment index by 5
    }
    break;
  case 1:
    APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8ConsecutiveFrameServiceID; // 1st byte    
    APP_DIAG_u8WriteDataByAddress_BytesIndex++;
    if(APP_DIAG_u8WriteDataByAddress_BytesIndex == APP_DIAG_u8WriteDataByAddress_DataBytesCount)
    {
      APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
      break;
    }    
    APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8SubFunction; // 2nd byte     
    APP_DIAG_u8WriteDataByAddress_BytesIndex++;
    if(APP_DIAG_u8WriteDataByAddress_BytesIndex == APP_DIAG_u8WriteDataByAddress_DataBytesCount)
    {
      APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;      
      break;
    }
    for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++) // loop to fill data bytes in CF, 5 data bytes are in array
    {
      if((u8Count + APP_DIAG_u8WriteDataByAddress_BytesIndex) == APP_DIAG_u8WriteDataByAddress_DataBytesCount) // check whether all data bytes have been already read
      {
        APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
        break;
      }
      else
      {
        APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex + u8Count] = APP_DIAG_au8RequestData[u8Count]; // fill array with data bytes
      }
    }
    APP_DIAG_u8WriteDataByAddress_BytesIndex = APP_DIAG_u8WriteDataByAddress_BytesIndex + ECU_DIAG_FRAME_DATA_BYTES; // increment index by 5
    break;
  case 2:
    APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8ConsecutiveFrameServiceID; // 1st byte        
    APP_DIAG_u8WriteDataByAddress_BytesIndex++;
    if(APP_DIAG_u8WriteDataByAddress_BytesIndex == APP_DIAG_u8WriteDataByAddress_DataBytesCount)
    {
      APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
      break;
    }
    APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex] = APP_DIAG_u8SubFunction; // 2nd byte     
    APP_DIAG_u8WriteDataByAddress_BytesIndex++;
    if(APP_DIAG_u8WriteDataByAddress_BytesIndex == APP_DIAG_u8WriteDataByAddress_DataBytesCount)
    {
      APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
      break;
    }
    for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++) // loop to fill data bytes in CF
    {
      if((u8Count + APP_DIAG_u8WriteDataByAddress_BytesIndex) == APP_DIAG_u8WriteDataByAddress_DataBytesCount) // check whether all data bytes have been already read
      {
        APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_TRUE;
        break;
      }
      else
      {
        APP_DIAG_u8WriteDataByAddress_DataBytes[APP_DIAG_u8WriteDataByAddress_BytesIndex + u8Count] = APP_DIAG_au8RequestData[u8Count]; // fill array with data bytes
      }
    }         
    break;
  default:
    break;
  }
  if(APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished == TAPAS_TRUE)
  {
    local_APP_DIAG_vdMemory_Write();
  }
}

void local_APP_DIAG_vdWriteMemoryByAddressFirstFrameHandler(void)
{
  uint8_t au8CanFrame[8] = {APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER,APP_DIAG_RESPONSE_FILLER};
  // Receive first frame message
  APP_DIAG_u8WriteDataByAddress_ServiceTotalBytesNum = APP_DIAG_u8FirstFrameServiceID; // to be checked
  APP_DIAG_u8WriteDataByAddress_SizeBytesNum = APP_DIAG_au8RequestData[0] >> 4U; // higher nibble
  APP_DIAG_u8WriteDataByAddress_AddressBytesNum = (APP_DIAG_au8RequestData[0] & 0x0F); // lower nibble
  APP_DIAG_u32WriteDataByAddress_Address = APP_DIAG_au8RequestData[1] << 24U;
  APP_DIAG_u32WriteDataByAddress_Address |= APP_DIAG_au8RequestData[2] << 16U;
  APP_DIAG_u32WriteDataByAddress_Address |= APP_DIAG_au8RequestData[3] << 8U;
  APP_DIAG_u32WriteDataByAddress_Address |= APP_DIAG_au8RequestData[4];
  // Send flow control message
  if(APP_DIAG_u8WriteDataByAddress_ServiceTotalBytesNum > 22) // Overflow check, 10 is the maximum data bytes could be received for 0x3D service 
  {
    au8CanFrame[0] = 0x32;
  }
  else
  {
    au8CanFrame[0] = 0x30;    
  }
  au8CanFrame[1] = 0; // Block size; number of received frames before flow control is sent from ECU
  au8CanFrame[2] = APP_DIAG_WRITE_DATA_BY_ADDRESS_FC_SEPARATION_TIME_MS; // Separation time; time between each CF send by tester
  ConsecutiveFlowFrame.u8ExpectedCF_Flag = TAPAS_TRUE;
  ConsecutiveFlowFrame.u8SeriveID = SID_WRITE_MEMORY_BY_ADDRESS;
  local_APP_DIAG_vdFramePositiveResponseWithFullArrayBytes(au8CanFrame);
}

uint8_t local_APP_DIAG_u8NumberOfZeroElementsReceived(void)
{
  uint8_t u8Count;
  uint8_t u8Ocurrences = 0;
  for(u8Count = 0; u8Count < 8; u8Count++)
  {
    if(APP_DIAG_au8IndexOfZeroDataReceived[u8Count] == 1)
    {
      u8Ocurrences++;
    }
  }
  return u8Ocurrences;
}

uint8_t local_APP_DIAG_u8SingleFrameLengthErrorCheck(void)
{
  uint8_t u8Count;
  uint8_t u8DataCount = 0;
  // check if length of message receieved is wrong to send NRC --- for SF only//
  /*Check if sub-function byte is null*/
  if(APP_DIAG_u8SubFunction == APP_DIAG_REQUEST_FILLER || APP_DIAG_u8SubFunction == APP_DIAG_RESPONSE_FILLER)
  {
    u8DataCount = 1; // only service ID byte
  }
  else
  {
    u8DataCount = 2; // service ID and sub-function bytes
    /*Get data bytes count*/
    for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
    {
      if(APP_DIAG_au8RequestData[u8Count] != APP_DIAG_REQUEST_FILLER)
      {
        u8DataCount++;
      }
    }    
  }
  if(APP_DIAG_u8DataCount != u8DataCount)
  {
    return TAPAS_FALSE;
  }
  else
  {
    return TAPAS_TRUE;
  }  
}

void local_APP_DIAG_vdResetAllGlobalVariables(void)
{
  APP_DIAG_eFrameType = (ECU_DIAG_FrameType_t)TAPAS_DEFAULT;
  APP_DIAG_u8DataCount = TAPAS_DEFAULT;
  APP_DIAG_u8ServiceId = TAPAS_DEFAULT;
  APP_DIAG_u8SubFunction = TAPAS_DEFAULT;
  APP_DIAG_u8SuppressPosResponse = TAPAS_DEFAULT;
  APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
  APP_DIAG_u32ApplicationEndAddress = 0;
  /*Global variables of SID 0x23 ReadMemoryByAddress*/
  APP_DIAG_u8ReadDataByAddress_FirstFlowControl = TAPAS_FALSE;
  APP_DIAG_u8ReadDataByAddress_GlobalCounter = TAPAS_FALSE;
  APP_DIAG_u8FlowControlExpected = TAPAS_FALSE;
  APP_DIAG_u8FlowControlServiceID = TAPAS_FALSE;
  /*Global variables of SID 0x3D WriteMemoryByAddress*/
  APP_DIAG_u8WriteDataByAddress_ConsecutiveFrameFinished = TAPAS_FALSE;
  APP_DIAG_u8WriteDataByAddress_BytesIndex = 0;
  APP_DIAG_u8WriteDataByAddress_ZeroElementsReceived = 0;  
}

void local_APP_DIAG_vdClearReceivingVariables(void) //  (&APP_DIAG_eFrameType, &APP_DIAG_u8DataCount, &APP_DIAG_u8ServiceId, &APP_DIAG_u8SubFunction, &APP_DIAG_u8SuppressPosResponse, APP_DIAG_au8RequestData, ECU_DIAG_FRAME_DATA_BYTES, APP_DIAG_au8IndexOfZeroDataReceived);  
{
  APP_DIAG_eFrameType = (ECU_DIAG_FrameType_t)TAPAS_DEFAULT;
  APP_DIAG_u8DataCount = TAPAS_DEFAULT;
  APP_DIAG_u8ServiceId = TAPAS_DEFAULT;
  APP_DIAG_u8SubFunction = TAPAS_DEFAULT;
  APP_DIAG_u8SuppressPosResponse = TAPAS_DEFAULT;
  uint8_t u8Count;
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
  {
     APP_DIAG_au8RequestData[u8Count] = 0; 
     APP_DIAG_au8IndexOfZeroDataReceived[u8Count] = 0;
  }
  APP_DIAG_au8IndexOfZeroDataReceived[5] = 0;
  APP_DIAG_au8IndexOfZeroDataReceived[6] = 0;
  APP_DIAG_au8IndexOfZeroDataReceived[7] = 0;
}

void local_APP_DIAG_vdFramePositiveResponseWithFullArrayBytes(uint8_t* pu8Data)
{
  STATUS_t eStatus = STATUS_OK;
  local_APP_DIAG_vdClearReceivingVariables();
  ECU_DIAG_vdEndService(eStatus, pu8Data);  
}

void local_APP_DIAG_vdSingleFramePositiveResponseWithoutSubfunction(uint8_t u8ResponseSID, uint8_t* pu8Data, uint8_t u8DataSize)
{
  STATUS_t eStatus = STATUS_OK;
  uint8_t u8Count;
  uint8_t u8PR_Data[8] = {0};
  u8PR_Data[0] = u8DataSize + 2;
  u8PR_Data[1] = u8ResponseSID + 0x40;
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES + 1; u8Count++)
  {
    if(u8Count < u8DataSize)
    {
      u8PR_Data[u8Count + 2] = pu8Data[u8Count];      
    }
    else
    {
      u8PR_Data[u8Count + 2] = APP_DIAG_RESPONSE_FILLER;
    }
  }
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES + 1; u8Count++)
  {
    APP_DIAG_au8ResposneData[u8Count] = 0;
  }
  local_APP_DIAG_vdClearReceivingVariables();
  ECU_DIAG_vdEndService(eStatus, u8PR_Data);
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
      u8PR_Data[u8Count + 3] = APP_DIAG_RESPONSE_FILLER;
    }
  }
  for(u8Count = 0; u8Count < ECU_DIAG_FRAME_DATA_BYTES; u8Count++)
  {
    APP_DIAG_au8ResposneData[u8Count] = 0;
  }
  local_APP_DIAG_vdClearReceivingVariables();
  ECU_DIAG_vdEndService(eStatus, u8PR_Data);
}

void local_APP_DIAG_vdSingleFrameNegativeResponse(uint8_t u8RequestedService, APP_DIAG_NRC_t eNRCCode)
{
  STATUS_t eStatus = STATUS_OK;
  uint8_t u8NRC_Data[8] = {0};
  u8NRC_Data[0] = 0x3;
  u8NRC_Data[1] = 0x7F;
  u8NRC_Data[2] = u8RequestedService;
  u8NRC_Data[3] = eNRCCode;
  u8NRC_Data[4] = APP_DIAG_RESPONSE_FILLER;
  u8NRC_Data[5] = APP_DIAG_RESPONSE_FILLER;
  u8NRC_Data[6] = APP_DIAG_RESPONSE_FILLER;
  u8NRC_Data[7] = APP_DIAG_RESPONSE_FILLER;
  local_APP_DIAG_vdClearReceivingVariables();
	ECU_DIAG_vdEndService(eStatus, u8NRC_Data);
}

void local_APP_DIAG_vdDefaultEcuModeSet(ECU_SYS_eEcuMode_t Mode)
{
  uint32_t u32RawData = 0;
  float fltPhyData = 0.0;  
  uint32_t u32Resolution = ECU_MEM_INT_u16ReadSignalResolution(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG);  
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, &u32RawData);
  u32RawData |= 0x01000000;
  u32RawData |= (Mode << 8U);
  fltPhyData = u32RawData / u32Resolution;  
  ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, fltPhyData, u32RawData); //resolution is 1 and offset is 0, raw signal only is written
}

uint8_t APP_DIAG_u8DefaultEcuModeCheck(ECU_SYS_eEcuMode_t* Mode) // Check then clear flag and mode and leave app valid flag
{
  uint8_t u8Flag = TAPAS_FALSE;
  uint32_t u32RawData;
  float fltPhyData;
  uint32_t u32Resolution = ECU_MEM_INT_u16ReadSignalResolution(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG);
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, &u32RawData);
  u8Flag = (u32RawData >> 24U);
  *Mode = (ECU_SYS_eEcuMode_t)(u32RawData >> 8U);
  u32RawData &= 1U; // Clear all except app valid flag
  fltPhyData = u32RawData / u32Resolution;
  ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, fltPhyData, u32RawData); //resolution is 1 and offset is 0, raw signal only is written  
  return u8Flag;
}

void local_APP_DIAG_vdReadMemoryByAddressInitializeArray(void)
{
  uint8_t u8Count;
  for(u8Count = 0; u8Count < APP_DIAG_READ_DATA_BY_ADDRESS_BYTES_NUMBER; u8Count++)
  {
    APP_DIAG_au8ReadDataByAddress[u8Count] = 0;
  }
}

void local_APP_DIAG_vdAppValidSet(void)
{
  uint32_t u32RawData = 0;
  float fltPhyData = 0.0;
  uint32_t u32Resolution = ECU_MEM_INT_u16ReadSignalResolution(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG);
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, &u32RawData);
  u32RawData |= 1U;
  fltPhyData = u32RawData / u32Resolution;
  ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, fltPhyData, u32RawData); //resolution is 1 and offset is 0, raw signal only is written
}

void local_APP_DIAG_vdAppValidClear(void)
{
  uint32_t u32RawData = 0;
  float fltPhyData = 0.0;
  uint32_t u32Resolution = ECU_MEM_INT_u16ReadSignalResolution(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG);
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, &u32RawData);
  u32RawData &= (0xFFFFFFF0);
  fltPhyData = u32RawData / u32Resolution;  
  ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, fltPhyData, u32RawData); //resolution is 1 and offset is 0, raw signal only is written
}

uint8_t local_APP_DIAG_u8AppValidCheck(void)
{
  uint32_t u32RawData = 0;
  uint8_t u8Flag = TAPAS_DEFAULT;
  ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_APP_VALID_PLUS_BOOT_MODE_AND_FLAG, &u32RawData);
  u8Flag = (uint8_t)u32RawData;
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

void local_APP_DIAG_vdResetArray(uint8_t* pau8Array, uint8_t u8ArraySize)
{
  uint8_t u8Count;
  for(u8Count = 0; u8Count < u8ArraySize; u8Count++)
  {
    pau8Array[u8Count] = 0;
  }
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

void local_APP_DIAG_EndServicePlusData(STATUS_t eStatus, uint8_t *pau8Data)
{
//	APP_DIAG_eStatus = APP_DIAG_STATUS_FREE;
//  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE);  
//	ECU_DIAG_vdServiceDonePlusData(eStatus, pau8Data);
}
#endif /*APP_DIAG_ENABLE*/
