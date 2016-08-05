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

File Name: app_boot.c
Author: Hany elShahawy 
E-mail: shany@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app_boot_cfg.h"
#include "app_boot.h"
#include "ecu.h"

#define APP_BOOT_BLOCK_BYTE_SIZE                                        (16)

#define APP_BOOT_BLOCKS_PER_PAGE                                        (APP_BOOT_PAGE_SIZE/APP_BOOT_BLOCK_BYTE_SIZE)

APP_BOOT_eStatus_t APP_BOOT_eStatus = APP_BOOT_ST_INIT;
APP_BOOT_eDownloadStatus_t APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
uint8_t APP_BOOT_au8PageReceived[APP_BOOT_PAGE_SIZE];
uint32_t APP_BOOT_u32HeartBeatCounter;
uint8_t APP_BOOT_au8DataNotUsed[4] = {0,0,0,0};
uint8_t APP_BOOT_u8ServiceId = TAPAS_DEFAULT;
uint8_t APP_BOOT_au8Data[6] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_BOOT_u8DataSize = 6;
uint32_t APP_BOOT_u32PageSize;
uint32_t APP_BOOT_u32StartAddress;
uint8_t APP_BOOT_u8BlockIndex=0;
uint8_t APP_BOOT_au8ReceivedData[APP_BOOT_BLOCK_BYTE_SIZE] = {0};
APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemory[APP_BOOT_BLOCKS_PER_PAGE] = {0,0,{0},0,0};
uint8_t APP_BOOT_u16BlockByteCounter = 0;
uint8_t APP_BOOT_u8CheckSumReceived;
uint8_t APP_BOOT_u8CheckSumCalculated;
uint8_t APP_BOOT_u8CheckSumOfPageWritten;
uint8_t APP_BOOT_u8DataBytesCountPerBlock = 0;
uint8_t APP_BOOT_au8RDTSend[4] = {0};
uint8_t APP_BOOT_au8ReceivedDataEcho[4] = {0}; // Array which has the data to be filled with received data so that it will be sent back again  
APP_BOOT_strPageMemory_t APP_BOOT_strPageMemoryTemplate = {0, APP_BOOT_BLOCKS_PER_PAGE, 0, {0}}; // Temporary page to read data every time and making checksum calculation
uint8_t APP_BOOT_au8ResposneData[4] = {0,0,0,0};
/********************************************************************************************/
/********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/

//#ifdef ECU_MEM_CODE_MODULE_ENABLE     
//extern APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemoryTemp[274];
//#endif 


/********************************************************************************************/
/****************************** LOCAL FUNCTIONS DECLARATION *********************************/
/********************************************************************************************/

void local_APP_BOOT_vdBootHeartBeat(void);
__ramfunc void local_APP_BOOT_vdSwDownload(void);
void local_APP_BOOT_vdPageDataReset(APP_BOOT_strPageMemory_t *strPageMemory);
void local_APP_BOOT_vdEndService(STATUS_t eStatus, uint8_t *pau8Data);
uint8_t local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_strBlockMemory_t* pBlockMemory, uint8_t u8PageSize); // Check sum of page as array of blocks
void local_APP_BOOT_vdFillEchoArray(uint8_t *au8EchoArray);
void local_APP_BOOT_vdEndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus);
uint8_t local_APP_BOOT_u8PageCheckSumCalculate(APP_BOOT_strPageMemory_t* pPageMemory);
void local_APP_BOOT_vdFlashApplicationSoftware(void);

/********************************************************************************************/
/**************************** GLOBAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/

void APP_BOOT_vdInit(void)
{
  APP_BOOT_eStatus = APP_BOOT_ST_INIT;
  APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
  float fltAppValid;
  
  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_APP_VALID,&fltAppValid);
  if(fltAppValid != TAPAS_FALSE)
  {
    ECU_SYS_vdGoToApplication(APP_BOOT_APPLICATION_ADDRESS);    
  }

  ECU_DIAG_vdRegisterAppBootCallback(local_APP_BOOT_vdFlashApplicationSoftware);
}

void APP_BOOT_vdDeInit(void)
{
  
}

void APP_BOOT_vdMgr(void)
{
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode();
  
  if(eEcuMode == ECU_SYS_BOOT)
  {
    /*Heart Beat*/
    local_APP_BOOT_vdBootHeartBeat();
  }
}

void local_APP_BOOT_vdFlashApplicationSoftware(void)
{
  
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  STATUS_t eStatus = STATUS_NOK;
  
  if(eEcuMode == ECU_SYS_BOOT)
  {   
    eStatus = ECU_DIAG_u8GetDiagFrame(&APP_BOOT_u8ServiceId, APP_BOOT_au8Data, APP_BOOT_u8DataSize);
    UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO10, UC_DIO_OUT_COMMAND_ON);      
    
    if((APP_BOOT_u8ServiceId == SID_DIAG_SESSION_CONTROL) && (APP_BOOT_au8Data[0] == (uint8_t)ECU_SYS_NORMAL))
    {
      ECU_SYS_vdSetEcuMode(ECU_SYS_NORMAL);
      local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_OK);
    }
    else if((APP_BOOT_u8ServiceId == SID_DIAG_SESSION_CONTROL))
    {
      APP_BOOT_au8ResposneData[0] = (uint8_t)eEcuMode;
      APP_BOOT_au8ResposneData[1] = 0;
      APP_BOOT_au8ResposneData[2] = 0;
      APP_BOOT_au8ResposneData[3] = 0;
      local_APP_BOOT_vdEndService(STATUS_NOK, APP_BOOT_au8ResposneData);
    }
    else
    {
      eEcuMode = ECU_SYS_eGetEcuMode();
      
      if(eEcuMode == ECU_SYS_BOOT)
      {
        if(	eStatus == STATUS_OK)
        {
          switch(APP_BOOT_u8ServiceId)      
            {
            case SID_REQUEST_DOWNLOAD:
              APP_BOOT_eStatus = APP_BOOT_ST_REQUEST_DOWNLOAD;
              break;
            case SID_REQUEST_UPLOAD:
              APP_BOOT_eStatus = APP_BOOT_ST_REQUEST_UPLOAD;
              break;
            case SID_TRANSFER_DATA:
              APP_BOOT_eStatus = APP_BOOT_ST_DATA_TRANSFER;
              break;
            case SID_REQUEST_TRANSFER_EXIT:
              APP_BOOT_eStatus = APP_BOOT_ST_DATA_TRANSFER;
              break;
            default:
              APP_BOOT_eStatus = APP_BOOT_ST_ERROR;
              break;
            }
          
          if((APP_BOOT_au8Data[4] == 1) && (APP_BOOT_u8ServiceId == SID_REQUEST_TRANSFER_EXIT))
          {
            local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_OK);
            ECU_MEM_INT_eDirectWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_TRUE);
            APP_BOOT_eStatus = APP_BOOT_ST_APP_RUN;
          }    
          /*Main Bootloader State Machine*/
          switch(APP_BOOT_eStatus)        
            {
            case APP_BOOT_ST_INIT:
              break;
            case APP_BOOT_ST_REQUEST_DOWNLOAD:
            case APP_BOOT_ST_DATA_TRANSFER:
              local_APP_BOOT_vdSwDownload();
              break;
            case APP_BOOT_ST_REQUEST_UPLOAD:
              
              break;
            case APP_BOOT_ST_APP_RUN:
              ECU_SYS_vdGoToApplication(APP_BOOT_APPLICATION_ADDRESS);
              break;
            case APP_BOOT_ST_ERROR:
              local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_NOK);
              break;
            default:
              APP_BOOT_eStatus = APP_BOOT_ST_INIT;
              break;
            }
        }
      }
    }
  }
}

void local_APP_BOOT_vdSwDownload(void)
{
  uint8_t u8Counter;
  STATUS_t eStatus = STATUS_BUSY;
  static uint8_t su8PageReceived = 0;
  //uint8_t u8Debug;
  switch(APP_BOOT_eDownloadStatus)
  {
  case APP_BOOT_DL_ST_INIT:
    local_APP_BOOT_vdPageDataReset((APP_BOOT_strPageMemory_t *)APP_BOOT_astrBlockMemory);
    APP_BOOT_u32StartAddress = 0;
    /*Prepare for page download*/
    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[0];
    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[1] << 8;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[2];
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[3] << 8;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[4] << 16;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[5] << 24;
    APP_BOOT_u16BlockByteCounter = 0;
    APP_BOOT_u8BlockIndex = 0;
    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_RECEIVE;
    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8ReceivedDataEcho,STATUS_OK);
    break;
  case APP_BOOT_DL_ST_PAGE_RECEIVE:
    /*Receive page and calcualte the received page checksum*/
    APP_BOOT_u8CheckSumReceived = 0;
    APP_BOOT_u8CheckSumCalculated = 0;
    APP_BOOT_u8CheckSumOfPageWritten = 0;
    if(su8PageReceived == 0)
    {
      for(u8Counter = 0; u8Counter < 6; u8Counter++)
      {
        APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].au8Byte[APP_BOOT_u16BlockByteCounter] = APP_BOOT_au8Data[u8Counter];
        APP_BOOT_u16BlockByteCounter++;
        if(APP_BOOT_u16BlockByteCounter == APP_BOOT_BLOCK_BYTE_SIZE)
        {
          APP_BOOT_u16BlockByteCounter = 0;
          APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].u32Address = (APP_BOOT_u32StartAddress + (APP_BOOT_u8BlockIndex * APP_BOOT_BLOCK_BYTE_SIZE));
          APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].u8DataBytesCount = 16;
          APP_BOOT_u8BlockIndex++;
          break;
          //u8Counter = 6;
        }
      }
    }
    if(APP_BOOT_u8BlockIndex == (APP_BOOT_u32PageSize/APP_BOOT_BLOCK_BYTE_SIZE))
    {
      su8PageReceived = 1;
    }
    if((su8PageReceived == 1) && (APP_BOOT_u8ServiceId == SID_REQUEST_TRANSFER_EXIT))
    {
      su8PageReceived = 0;
      APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_DOWNLOAD;     
      APP_BOOT_u8CheckSumReceived = APP_BOOT_au8Data[5];
      local_APP_BOOT_vdSwDownload();
      break;
    }
    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8ReceivedDataEcho, STATUS_OK);
    break;
    
  case APP_BOOT_DL_ST_PAGE_DOWNLOAD:
    /*Download the page and confirm the download by calcualting the checksum of the flashed bytes (read them)*/
    /* Check the real-time of flashing one block, to know how much flash in one task period */
    APP_BOOT_u8CheckSumCalculated = local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_astrBlockMemory, APP_BOOT_BLOCK_BYTE_SIZE);
    if(APP_BOOT_u8CheckSumCalculated == APP_BOOT_u8CheckSumReceived)
    {
      UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO14, UC_DIO_OUT_COMMAND_ON);
      ECU_MEM_CODE_eWriteBlocks(APP_BOOT_astrBlockMemory, APP_BOOT_u8BlockIndex); // Write page as array of blocks
      UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO14, UC_DIO_OUT_COMMAND_OFF);
      APP_BOOT_strPageMemoryTemplate.u32PageStartingAddress = APP_BOOT_u32StartAddress; // set page starting address of the temporary page
      UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO12, UC_DIO_OUT_COMMAND_ON);      
      ECU_MEM_CODE_eReadPage(&APP_BOOT_strPageMemoryTemplate); // Read page as a whole
      UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO12, UC_DIO_OUT_COMMAND_OFF);      
      APP_BOOT_u8CheckSumOfPageWritten = local_APP_BOOT_u8PageCheckSumCalculate(&APP_BOOT_strPageMemoryTemplate); // Calculate checksum of written page
      if(APP_BOOT_u8CheckSumOfPageWritten == APP_BOOT_u8CheckSumCalculated)
      {
        
        eStatus = STATUS_OK;
      }
      else
      {
        eStatus = STATUS_NOK;       
      }
    }
    else
    {
      eStatus = STATUS_NOK;
    }
    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;      
    APP_BOOT_au8RDTSend[3] = APP_BOOT_u8CheckSumCalculated;
    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8RDTSend, eStatus);
    UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO10, UC_DIO_OUT_COMMAND_OFF);      
    break;
    
  case APP_BOOT_DL_ST_ERROR:
    /*Respond with negative response*/
    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_NOK);
    break;
  default:
    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
    break;
  }
}

void local_APP_BOOT_vdEndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus)
{
  uint8_t u8Count;
  local_APP_BOOT_vdFillEchoArray(pau8EchoArray);
  local_APP_BOOT_vdEndService(eStatus, pau8EchoArray);
  for(u8Count = 0; u8Count < 8; u8Count++)
  {
    pau8EchoArray[u8Count] = 0;
  }
}

void local_APP_BOOT_vdFillEchoArray(uint8_t *pau8EchoArray)
{
  pau8EchoArray[0] = APP_BOOT_au8Data[2];
  pau8EchoArray[1] = APP_BOOT_au8Data[3];
  pau8EchoArray[2] = APP_BOOT_au8Data[4];
  pau8EchoArray[3] = APP_BOOT_au8Data[5];    
}

void local_APP_BOOT_vdEndService(STATUS_t eStatus, uint8_t *pau8Data)
{
	APP_BOOT_eStatus = APP_BOOT_ST_INIT;
	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
}

void local_APP_BOOT_vdBootHeartBeat(void)
{
  static uint32_t su32HeartBeatCounter = 1;
  static uint8_t su8Counter = 0;
    
  if(((su32HeartBeatCounter*APP_BOOT_TASK_MS) == APP_BOOT_HEARTBEAT_HALF_PERIOD_MS) && (su8Counter < (APP_BOOT_HEARTBEAT_FAST_COUNT*2)))
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_TOGGLE);
    su32HeartBeatCounter = 1;
    su8Counter++;
  }
  else if(su8Counter == (APP_BOOT_HEARTBEAT_FAST_COUNT*2))
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_ON);
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
  
//  /*Implement here the bootloader heartbeat*/
//  if((APP_BOOT_u32HeartBeatCounter * APP_BOOT_TASK_MS)  == 1000)
//  {
//    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_OFF);    
//    APP_BOOT_u32HeartBeatCounter  = 0;
//  }  
//  if((APP_BOOT_u32HeartBeatCounter * APP_BOOT_TASK_MS)  < 500)
//  {
//    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_TOGGLE);
//    APP_BOOT_u32HeartBeatCounter ++;       
//  }
//  if((APP_BOOT_u32HeartBeatCounter * APP_BOOT_TASK_MS)  >= 500 || (APP_BOOT_u32HeartBeatCounter * APP_BOOT_TASK_MS)  == 500)
//  {
//    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_ON);
//    APP_BOOT_u32HeartBeatCounter ++;       
//  }  
}

void local_APP_BOOT_vdPageDataReset(APP_BOOT_strPageMemory_t *strPageMemory)
{
  uint8_t u8IndexBlock;
  uint8_t u8Count;
  for(u8IndexBlock = (uint8_t)0; u8IndexBlock < APP_BOOT_BLOCKS_PER_PAGE; u8IndexBlock++)
  {
    for(u8Count = 0; u8Count < APP_BOOT_BLOCK_BYTE_SIZE; u8Count++)
    {
      strPageMemory[u8IndexBlock].UC_FLASH_astrBlocksOfMemory[u8IndexBlock].au8Byte[u8Count] = (uint8_t)0;      
    }
    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u32Address = 0;
    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u32LineNumber = 0;
    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u8DataBytesCount = 0;
    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u8CheckSum = 0;
  }
  strPageMemory->u16BytesNumber = 0;
  strPageMemory->u32PageStartingAddress = 0;
}

uint8_t local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_strBlockMemory_t* pBlockMemory, uint8_t u8PageSize) // Check sum of page as array of blocks
{
  uint8_t u8CheckSum = 0;
  uint8_t u8Counter;
  uint8_t u8LoopCounter;
  for(u8Counter = 0; u8Counter < u8PageSize; u8Counter++)
  {
    for(u8LoopCounter = 0; u8LoopCounter < APP_BOOT_BLOCK_BYTE_SIZE; u8LoopCounter++)
    {
      u8CheckSum = u8CheckSum + pBlockMemory[u8Counter].au8Byte[u8LoopCounter]; 
    }
  }
  return u8CheckSum;
}

uint8_t local_APP_BOOT_u8PageCheckSumCalculate(APP_BOOT_strPageMemory_t* pPageMemory)
{
  uint8_t u8PageCheckSum = 0;
  uint8_t u8Counter;
  uint8_t u8LoopCounter;
  for(u8LoopCounter = 0; u8LoopCounter < pPageMemory->u8BlocksNumber; u8LoopCounter++)
  {
    for(u8Counter = 0; u8Counter < APP_BOOT_BLOCK_BYTE_SIZE; u8Counter++)
    {
      u8PageCheckSum  = u8PageCheckSum  + pPageMemory->UC_FLASH_astrBlocksOfMemory[u8LoopCounter].au8Byte[u8Counter];      
    }
  }  
  return u8PageCheckSum ;
}