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

APP_BOOT_eStatus_t APP_BOOT_eStatus = APP_BOOT_ST_INIT;
APP_BOOT_eDownloadStatus_t APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
uint8_t APP_BOOT_au8PageReceived[APP_BOOT_PAGE_SIZE];
uint8_t APP_BOOT_u8HeartBeatCounter;
uint8_t APP_BOOT_au8DataNotUsed[4] = {0,0,0,0};
uint8_t APP_BOOT_u8ServiceId = TAPAS_DEFAULT;
uint8_t APP_BOOT_au8Data[6] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
uint8_t APP_BOOT_u8DataSize = 6;
uint32_t APP_BOOT_u32PageSize;
uint32_t APP_BOOT_u32StartAddress;
uint8_t APP_BOOT_u8BlockIndex=0;
uint8_t APP_BOOT_au8ReceivedData[16] = {0};
APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemory[16] = {0,0,{0},0,0};

/********************************************************************************************/
/********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/

//#ifdef ECU_MEM_CODE_MODULE_ENABLE     
//extern APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemory[274];
//#endif 


/********************************************************************************************/
/****************************** LOCAL FUNCTIONS DECLARATION *********************************/
/********************************************************************************************/

void local_APP_BOOT_vdBootHeartBeat(void);
void local_APP_BOOT_vdSwDownload(void);
void local_APP_BOOT_vdPageDataReset(void);
void local_APP_BOOT_EndService(STATUS_t eStatus, uint8_t *pau8Data);

/********************************************************************************************/
/**************************** GLOBAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/

void APP_BOOT_vdInit(void)
{
//  uint8_t u8LoopCounter;
//  uint8_t u8Counter;
//  uint8_t u8ByteCounter;
//  uint16_t u16RecordsCount = 0;
//  uint16_t u16NumberOfBytes = 0;
//  uint8_t u8PagesNumber = ((ECU_MEM_CODE_RECORDS_NUM + UC_FLASH_MAX_BLOCK_SIZE_IN_BYTES - 1)/UC_FLASH_MAX_BLOCK_SIZE_IN_BYTES);
//  ECU_MEM_CODE_strPageMemory_t ECU_MEM_CODE_strApplicationCode[3] = {0};//{0,0,{{0,0,{0},0,0}}}; // Max BL size is 32Kb --> 125 pages
//  for(u8LoopCounter = 0; u8LoopCounter < u8PagesNumber; u8LoopCounter++)
//  {
//    for(u8Counter = 0; u8Counter < 16; u8Counter++)
//    {
//      ECU_MEM_CODE_strApplicationCode[u8LoopCounter].UC_FLASH_astrBlocksOfMemory[u8Counter].u32Address = APP_BOOT_astrBlockMemory[u16RecordsCount].u32Address;
//      ECU_MEM_CODE_strApplicationCode[u8LoopCounter].UC_FLASH_astrBlocksOfMemory[u8Counter].u32LineNumber = APP_BOOT_astrBlockMemory[u16RecordsCount].u32LineNumber; 
//      ECU_MEM_CODE_strApplicationCode[u8LoopCounter].UC_FLASH_astrBlocksOfMemory[u8Counter].u8CheckSum = APP_BOOT_astrBlockMemory[u16RecordsCount].u8CheckSum;
//      ECU_MEM_CODE_strApplicationCode[u8LoopCounter].UC_FLASH_astrBlocksOfMemory[u8Counter].u8DataBytesCount = APP_BOOT_astrBlockMemory[u16RecordsCount].u8DataBytesCount;
//      for(u8ByteCounter = 0; u8ByteCounter < APP_BOOT_astrBlockMemory[u16RecordsCount].u8DataBytesCount; u8ByteCounter++)
//      {
//        ECU_MEM_CODE_strApplicationCode[u8LoopCounter].UC_FLASH_astrBlocksOfMemory[u8Counter].au8Byte[u8ByteCounter] = APP_BOOT_astrBlockMemory[u16RecordsCount].au8Byte[u8ByteCounter];
//        u16NumberOfBytes++;
//      }
//      u16RecordsCount++;
//      if(u16RecordsCount == ECU_MEM_CODE_RECORDS_NUM)
//      {
//        u8LoopCounter = u8PagesNumber; // Break out of bigger loop
//        break;                         // Break out of smaller loop
//      }      
//    }
//    ECU_MEM_CODE_strApplicationCode[u8LoopCounter].u8BlocksNumber = u16RecordsCount;
//    ECU_MEM_CODE_strApplicationCode[u8LoopCounter].u16BytesNumber = u16NumberOfBytes;
//  }
//  for(u8Counter = 0; u8Counter < u8PagesNumber; u8Counter++)
//  {
//    ECU_MEM_CODE_eWritePage(ECU_MEM_CODE_strApplicationCode[u8Counter]);
//  }
//  APP_BOOT_vdMgr();
}

void APP_BOOT_vdDeInit(void)
{
  
}

void APP_BOOT_vdMgr(void)
{
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode(); 
  STATUS_t eStatus = STATUS_NOK;
  
  if(eEcuMode == ECU_SYS_BOOT)
  {
  /*Heart Beat*/
  local_APP_BOOT_vdBootHeartBeat();
  }
  
  eStatus = ECU_DIAG_u8GetDiagFrame(&APP_BOOT_u8ServiceId, APP_BOOT_au8Data, APP_BOOT_u8DataSize);
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
      APP_BOOT_eStatus = APP_BOOT_ST_APP_RUN;
      break;
    default:
      APP_BOOT_eStatus = APP_BOOT_ST_ERROR;
      break;
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
      local_APP_BOOT_EndService(STATUS_NOK, APP_BOOT_au8DataNotUsed);
      break;
    default:
      APP_BOOT_eStatus = APP_BOOT_ST_INIT;
      break;
    }
  }
}

void local_APP_BOOT_vdSwDownload(void)
{
  static uint16_t su16BlockByteCounter = 0;
  uint8_t u8Counter;
  uint8_t u8Debug;
  switch(APP_BOOT_eDownloadStatus)
  {
  case APP_BOOT_DL_ST_INIT:
    /*Prepare for page download*/
    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[0];
    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[1] << 8;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[2];
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[3] << 8;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[4] << 16;
    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[5] << 24;
    APP_BOOT_u8BlockIndex = 0;

    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_RECEIVE;
		local_APP_BOOT_EndService(STATUS_OK, &APP_BOOT_au8DataNotUsed[0]);
    break;
  case APP_BOOT_DL_ST_PAGE_RECEIVE:
    /*Receive page and calcualte the received page checksum*/
    for(u8Counter = 0; u8Counter < 6; u8Counter++)
    {
      APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].au8Byte[su16BlockByteCounter] = APP_BOOT_au8Data[u8Counter];
      su16BlockByteCounter++;
      if(su16BlockByteCounter == APP_BOOT_BLOCK_BYTE_SIZE)
      {
        APP_BOOT_u8BlockIndex++;
        su16BlockByteCounter = 0;
      }
    }
//    if(APP_BOOT_u8BlockIndex == 14)
//    {
//      u8Debug = 1;
//    }
    u8Debug = (APP_BOOT_u32PageSize/APP_BOOT_BLOCK_BYTE_SIZE);
    if(APP_BOOT_u8BlockIndex == (APP_BOOT_u32PageSize/APP_BOOT_BLOCK_BYTE_SIZE))
    {
      APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_DOWNLOAD;      
    }
    local_APP_BOOT_EndService(STATUS_OK, &APP_BOOT_au8DataNotUsed[0]);
    break;
  case APP_BOOT_DL_ST_PAGE_DOWNLOAD:
    /*Download the page and confirm the download by calcualting the checksum of the falshed bytes (read them)*/
    /* Check the real-time of flashing one block, to know how much flash in one task period */
    
    break;
  case APP_BOOT_DL_ST_ERROR:
    /*Respond with negative response*/
    local_APP_BOOT_EndService(STATUS_NOK, APP_BOOT_au8DataNotUsed);
    break;
  default:
    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
    break;
  }
}

void local_PP_BOOT_vdPageDownload(APP_BOOT_strBlockMemory_t* APP_BOOT_strApplicationCode)
{
  
  
}
void local_APP_BOOT_vdBootHeartBeat(void)
{
  /*Implement here the bootloader heartbeat*/
  if(APP_BOOT_u8HeartBeatCounter == 15)
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_OFF);    
    APP_BOOT_u8HeartBeatCounter  = 0;
  }  
  if(APP_BOOT_u8HeartBeatCounter  < 5)
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_TOGGLE);
    APP_BOOT_u8HeartBeatCounter ++;       
  }
  if(APP_BOOT_u8HeartBeatCounter  > 5 || APP_BOOT_u8HeartBeatCounter  == 5)
  {
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_ON);
    APP_BOOT_u8HeartBeatCounter ++;       
  }  
}

void local_APP_BOOT_vdPageDataReset(void)
{
  uint8_t u8IndexByte;
  
  for(u8IndexByte = (uint8_t)0; u8IndexByte < APP_BOOT_PAGE_SIZE; u8IndexByte++)
  {
    APP_BOOT_au8PageReceived[u8IndexByte] = (uint8_t)0;
  }
}

void local_APP_BOOT_EndService(STATUS_t eStatus, uint8_t *pau8Data)
{
	APP_BOOT_eStatus = APP_BOOT_ST_INIT;
	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
}

uint8_t local_APP_BOOT_u8CheckSumCalculate(uint8_t* pau8DataArray, uint8_t u8DataArraySize)
{
  uint8_t u8CheckSum = 0;
  uint8_t u8Counter;
  for(u8Counter = 0; u8Counter < u8DataArraySize; u8Counter++)
  {
    u8CheckSum = u8CheckSum + pau8DataArray[u8Counter];
  }
  return u8CheckSum;
}