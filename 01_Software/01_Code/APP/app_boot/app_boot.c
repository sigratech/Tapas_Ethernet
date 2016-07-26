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


APP_BOOT_eStatus_t APP_BOOT_eStatus = APP_BOOT_ST_INIT;
APP_BOOT_eDownloadStatus_t APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;

/********************************************************************************************/
/********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/

#ifdef ECU_MEM_CODE_MODULE_ENABLE     
extern APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemory[274];
#endif 


void local_APP_BOOT_vdBootHeartBeat(void);
void local_APP_BOOT_vdSwDownload(void);

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
  /*Heart Beat*/
  local_APP_BOOT_vdBootHeartBeat();
    
  /*Main Bootloader State Machine*/
  switch(APP_BOOT_eStatus)
  {
  case APP_BOOT_ST_INIT:
    
    break;
  case APP_BOOT_ST_DOWNLOAD:
    local_APP_BOOT_vdSwDownload();
    break;
  case APP_BOOT_ST_UPLOAD:
    
    break;
  case APP_BOOT_ST_APP_RUN:
    ECU_SYS_vdGoToApplication(APP_BOOT_APPLICATION_ADDRESS);
    break;
  case APP_BOOT_ST_ERROR:
    
    break;
  default:
    APP_BOOT_eStatus = APP_BOOT_ST_INIT;
    break;
  }
}

void local_APP_BOOT_vdSwDownload(void)
{
  switch(APP_BOOT_eDownloadStatus)
  {
  case APP_BOOT_DL_ST_INIT:
    /*Prepare fow page download*/
    break;
  case APP_BOOT_DL_ST_PAGE_RECEIVE:
    /*Receive page and calcualte the received page checksum*/
    break;
  case APP_BOOT_DL_ST_PAGE_DOWNLOAD:
    /*Download the page and confirm the download by calcualting the checksum of the falshed bytes (read them)*/
    /* Check the real-time of flashing one block, to know how much flash in one task period */
    break;
  case APP_BOOT_DL_ST_ERROR:
    /*Respond with negative response*/
    break;
  default:
    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
    break;
  }
}

void local_APP_BOOT_vdBootHeartBeat(void)
{
  /*Implement here the bootloader heartbeat*/
}
