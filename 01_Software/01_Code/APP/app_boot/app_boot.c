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
//
#include "app_boot_cfg.h"
#include "app_boot.h"
#include "ecu.h"
#include "lib_data.h"

#ifdef APP_BOOT_ENABLE

//#define APP_BOOT_BLOCK_BYTE_SIZE                                        (16)
//
//#define APP_BOOT_BLOCKS_PER_PAGE                                        (APP_BOOT_PAGE_SIZE/APP_BOOT_BLOCK_BYTE_SIZE)
//
//APP_BOOT_eStatus_t APP_BOOT_eStatus = APP_BOOT_ST_INIT;
//APP_BOOT_eDownloadStatus_t APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_HEADER_RECEIVE_PRE_INIT;
//uint8_t APP_BOOT_au8PageReceived[APP_BOOT_PAGE_SIZE];
uint32_t APP_BOOT_u32HeartBeatCounter;
//uint8_t APP_BOOT_au8DataNotUsed[4] = {0,0,0,0};
//uint8_t APP_BOOT_u8ServiceId = TAPAS_DEFAULT;
//uint8_t APP_BOOT_au8Data[6] = {TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT, TAPAS_DEFAULT};
//uint8_t APP_BOOT_u8DataSize = 6;
//uint32_t APP_BOOT_u32PageSize;
////uint32_t APP_BOOT_u32ApplicationStartAddress = (uint32_t)APP_BOOT_APPLICATION_START_ADDRESS;
//uint32_t APP_BOOT_u32ApplicationEndAddress = 0;
//uint32_t APP_BOOT_u32StartAddress;
//uint8_t APP_BOOT_u8BlockIndex=0;
//uint8_t APP_BOOT_au8ReceivedData[APP_BOOT_BLOCK_BYTE_SIZE] = {0};
//APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemory[APP_BOOT_BLOCKS_PER_PAGE] = {0,0,{0},0,0};
//uint8_t APP_BOOT_u16BlockByteCounter = 0;
//uint8_t APP_BOOT_u8CheckSumReceived;
//uint8_t APP_BOOT_u8CheckSumCalculated;
//uint8_t APP_BOOT_u8CheckSumOfPageWritten;
//uint8_t APP_BOOT_u8DataBytesCountPerBlock = 0;
//uint8_t APP_BOOT_au8RDTSend[4] = {0};
//uint8_t APP_BOOT_au8ReceivedDataEcho[4] = {0}; // Array which has the data to be filled with received data so that it will be sent back again  
//APP_BOOT_strPageMemory_t APP_BOOT_strPageMemoryTemplate = {0, APP_BOOT_BLOCKS_PER_PAGE, 0, {0}}; // Temporary page to read data every time and making checksum calculation
//uint8_t APP_BOOT_au8ResposneData[4] = {0,0,0,0};
//ECU_MEM_strBlockMemory_t APP_BOOT_strBlockTemp = {0,16,{0},0,0}; // initialize temporary block with 16 data bytes as default bytes per block
//uint8_t APP_BOOT_u8BlockData[16] = {0};
//uint32_t APP_BOOT_u32UploadEEPROMAddress = EEPROM_STARTING_ADDRESS;
//uint32_t APP_BOOT_u32DownloadEEPROMAddress = EEPROM_STARTING_ADDRESS;
//uint8_t APP_BOOT_u8FirstRead = 1;
//uint8_t APP_BOOT_u8FirstWrite = 1;
//uint8_t APP_BOOT_u8DataRec[16] = {0};
uint8_t APP_BOOT_u8FlashingMode = 0;
////debugging
//uint8_t u8flag = 0;
///********************************************************************************************/
///********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
///********************************************************************************************/
//
////#ifdef ECU_MEM_CODE_MODULE_ENABLE     
////extern APP_BOOT_strBlockMemory_t APP_BOOT_astrBlockMemoryTemp[274];
////#endif 
//
//
///********************************************************************************************/
///****************************** LOCAL FUNCTIONS DECLARATION *********************************/
///********************************************************************************************/
//
void local_APP_BOOT_vdBootHeartBeat(void);
//__ramfunc void local_APP_BOOT_vdSwDownload(void);
//void local_APP_BOOT_vdPageDataReset(APP_BOOT_strPageMemory_t *strPageMemory);
//void local_APP_BOOT_vdEndService(STATUS_t eStatus, uint8_t *pau8Data);
//uint8_t local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_strBlockMemory_t* pBlockMemory, uint8_t u8PageSize); // Check sum of page as array of blocks
//void local_APP_BOOT_vdFillEchoArray(uint8_t *au8EchoArray);
//void local_APP_BOOT_vdEndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus);
//uint8_t local_APP_BOOT_u8PageCheckSumCalculate(APP_BOOT_strPageMemory_t* pPageMemory);
//void local_APP_BOOT_vdFlashApplicationSoftware(void);
//void local_APP_BOOT_vdSwUpload(void);
//void local_APP_BOOT_vdReceiveHeaderSrecLine(void);
//void local_APP_BOOT_vdReceiveLastSrecLine(void);
//void local_APP_BOOT_vdUploadEEPROM(void);
//void local_APP_BOOT_vdDownloadEEPROM(void);
//
///********************************************************************************************/
///**************************** GLOBAL FUNCTIONS IMPLEMENTATION *******************************/
///********************************************************************************************/
//
void APP_BOOT_vdInit(void)
{
//  APP_BOOT_eStatus = APP_BOOT_ST_INIT;
//  APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_HEADER_RECEIVE_PRE_INIT;
//  float fltAppValid;
//  float fltStartAddress;
//  float fltEndAddress;
//  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_PROGRAM_START_ADDRESS,&fltStartAddress);
//  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_PROGRAM_END_ADDRESS,&fltEndAddress);
//  APP_BOOT_u32ApplicationEndAddress = (uint32_t)fltEndAddress;
//  ECU_MEM_INT_eReadSignalValue(ECU_MEM_INT_APP_VALID,&fltAppValid);
//  if(fltAppValid == TAPAS_TRUE)
//  {
//    ECU_SYS_vdGoToApplication(APP_BOOT_APPLICATION_START_ADDRESS);    
//  }
////  ECU_DIAG_vdRegisterAppBootCallback(local_APP_BOOT_vdFlashApplicationSoftware);
}

void APP_BOOT_vdDeInit(void)
{
  
}

void APP_BOOT_vdMgr(void)
{
	ECU_SYS_eEcuMode_t eEcuMode;
  eEcuMode = ECU_SYS_eGetEcuMode();

  local_APP_BOOT_vdBootHeartBeat();  
  if(eEcuMode == ECU_SYS_PROGRAMMING)
  {
    /*Heart Beat*/
    local_APP_BOOT_vdBootHeartBeat();
  }
}

void local_APP_BOOT_vdBootHeartBeat(void)
{
  static uint32_t su32NormalHeartBeatCounter = 1;
  static uint32_t su32FlashHeartBeatCounter = 1;
  static uint8_t su8Counter = 0;
  
  if(APP_BOOT_u8FlashingMode == 0)
  {
    if(((su32NormalHeartBeatCounter*APP_BOOT_TASK_MS) == APP_BOOT_HEARTBEAT_HALF_PERIOD_MS) && (su8Counter < (APP_BOOT_HEARTBEAT_FAST_COUNT*2)))
    {
      ECU_IO_eInternalOutputControl(ECU_IO_DOUT_CHECK_HEARBEAT, ECU_IO_OUT_COMMAND_TOGGLE);
      su32NormalHeartBeatCounter = 1;
      su8Counter++;
    }
    else if(su8Counter == (APP_BOOT_HEARTBEAT_FAST_COUNT*2))
    {
      ECU_IO_eInternalOutputControl(ECU_IO_DOUT_CHECK_HEARBEAT, ECU_IO_OUT_COMMAND_ON);
      su8Counter = (APP_BOOT_HEARTBEAT_FAST_COUNT*2) + 1;
      su32NormalHeartBeatCounter++;
    }
    else if ((su32NormalHeartBeatCounter*APP_BOOT_TASK_MS) == APP_BOOT_HEARTBEAT_STATIC_PERIOD_MS)
    {
      su32NormalHeartBeatCounter = 1;
      su8Counter = 0;
    }
    else
    {
      su32NormalHeartBeatCounter++;
    }    
  }
  else
  {
    if((su32FlashHeartBeatCounter*APP_BOOT_TASK_MS) == (APP_BOOT_HEARTBEAT_HALF_PERIOD_MS/2))
    {
      ECU_IO_eInternalOutputControl(ECU_IO_DOUT_CHECK_HEARBEAT, ECU_IO_OUT_COMMAND_TOGGLE);
      su32FlashHeartBeatCounter = 1;
    }
    else
    {
      su32FlashHeartBeatCounter++;
    }
  }

}
//
//void local_APP_BOOT_vdFlashApplicationSoftware(void)
//{
//	ECU_SYS_eEcuMode_t eEcuMode;
//  eEcuMode = ECU_SYS_eGetEcuMode(); 
//  STATUS_t eStatus = STATUS_NOK;
//  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY);
//  
//  if(eEcuMode == ECU_SYS_PROGRAMMING)
//  {   
////    eStatus = ECU_DIAG_u8GetDiagFrame(&APP_BOOT_u8ServiceId, APP_BOOT_au8Data, APP_BOOT_u8DataSize);
//    UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO10, UC_DIO_OUT_COMMAND_ON);      
//    
//    if((APP_BOOT_u8ServiceId == SID_DIAG_SESSION_CONTROL) && (APP_BOOT_au8Data[0] == (uint8_t)ECU_SYS_DEFAULT))
//    {
//      ECU_SYS_vdSetEcuMode(ECU_SYS_DEFAULT);
//      local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_OK);
//    }
//    else if((APP_BOOT_u8ServiceId == SID_DIAG_SESSION_CONTROL))
//    {
//      APP_BOOT_au8ResposneData[0] = (uint8_t)eEcuMode;
//      APP_BOOT_au8ResposneData[1] = 0;
//      APP_BOOT_au8ResposneData[2] = 0;
//      APP_BOOT_au8ResposneData[3] = 0;
//      local_APP_BOOT_vdEndService(STATUS_NOK, APP_BOOT_au8ResposneData);
//    }
//    else
//    {
//      eEcuMode = ECU_SYS_eGetEcuMode();
//      
//      if(eEcuMode == ECU_SYS_PROGRAMMING)
//      {
//        if(	eStatus == STATUS_OK)
//        {
//          switch(APP_BOOT_u8ServiceId)      
//            {
//            case SID_REQUEST_DOWNLOAD:
//              APP_BOOT_u8FlashingMode = 1;
//              ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent receiving frames from other connection
//              APP_BOOT_eStatus = APP_BOOT_ST_REQUEST_DOWNLOAD;
//              break;
//            case SID_REQUEST_UPLOAD:
//              ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent receiving frames from other connection              
//              APP_BOOT_eStatus = APP_BOOT_ST_REQUEST_UPLOAD;
//              break;
//            case SID_TRANSFER_DATA:
//              APP_BOOT_eStatus = APP_BOOT_ST_DATA_TRANSFER;
//              break;
//            case SID_REQUEST_TRANSFER_EXIT:
//              if(APP_BOOT_eStatus == APP_BOOT_ST_REQUEST_UPLOAD || APP_BOOT_eStatus == APP_BOOT_RESET_REQUEST ) // check if uploading finishes to restart 
//              {
//                local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_NOK);                              
//                APP_BOOT_eStatus = APP_BOOT_ST_APP_RUN;
//                break;
//              }
//              // downloading is still in progress .. receiving of jump-ready signal is done here
//              APP_BOOT_eStatus = APP_BOOT_ST_DATA_TRANSFER;
//              break;
//            case UPLOAD_EE2PROM:
//              ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent receiving frames from other connection              
//              local_APP_BOOT_vdUploadEEPROM();
//              APP_BOOT_eStatus = APP_BOOT_RESET_REQUEST;
//              break;
//            case DOWNLOAD_EE2PROM:
//              ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent receiving frames from other connection              
//              local_APP_BOOT_vdDownloadEEPROM();
//              APP_BOOT_eStatus = APP_BOOT_RESET_REQUEST;
//              break;
//            default:
//              APP_BOOT_eStatus = APP_BOOT_ST_INIT;
//              break;
//            }
//          
//          if((APP_BOOT_au8Data[4] == 1) && (APP_BOOT_u8ServiceId == SID_REQUEST_TRANSFER_EXIT)) // Request transfer exit and jump-ready signal
//          {
//            /*Save program start address in emulated flash*/
//            ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_PROGRAM_START_ADDRESS, APP_BOOT_APPLICATION_START_ADDRESS, APP_BOOT_APPLICATION_START_ADDRESS);
//            /*Get program end address and save it in emulated flash*/
//            APP_BOOT_u32ApplicationEndAddress = (APP_BOOT_au8Data[0] << 24);
//            APP_BOOT_u32ApplicationEndAddress |= (APP_BOOT_au8Data[1] << 16);
//            APP_BOOT_u32ApplicationEndAddress |= (APP_BOOT_au8Data[2] << 8);
//            APP_BOOT_u32ApplicationEndAddress |= (APP_BOOT_au8Data[3]);
//            ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_PROGRAM_END_ADDRESS, APP_BOOT_u32ApplicationEndAddress, APP_BOOT_u32ApplicationEndAddress);
//            /*Set application valid flag*/
//            ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_APP_VALID, TAPAS_TRUE, TAPAS_TRUE);
//            /*Send positive feedback*/
//            local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_OK);
//            /*Change state machine to application run*/
//            APP_BOOT_eStatus = APP_BOOT_ST_APP_RUN;
//          }    
//          /*Main Bootloader State Machine*/
//          switch(APP_BOOT_eStatus)        
//            {
//            case APP_BOOT_ST_INIT:
//              break;
//            case APP_BOOT_ST_REQUEST_DOWNLOAD:
//            case APP_BOOT_ST_DATA_TRANSFER:
//              local_APP_BOOT_vdSwDownload();
//              break;
//            case APP_BOOT_ST_REQUEST_UPLOAD:
//              local_APP_BOOT_vdSwUpload();
//              break;
//            case APP_BOOT_ST_APP_RUN:
//              ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE); // reset app status to allow receiving data from other connection
//              ECU_SYS_vdShutdownAndReset(); // Save EEPROM and reset
//              break;
//            case APP_BOOT_ST_ERROR:
//              local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_NOK);
//              break;
//            case APP_BOOT_RESET_REQUEST:
//              break;
//            default:
//              APP_BOOT_eStatus = APP_BOOT_ST_INIT;
//              break;
//            }
//        }
//      }
//    }
//  }
//}
//
//void local_APP_BOOT_vdDownloadEEPROM(void)
//{
////  uint8_t u8Count;
////  static uint8_t su8DownloadCount = 0;
////  if(APP_BOOT_u8FirstWrite == 1)
////  {
////    ECU_MEM_INT_eEraseSector((ECU_MEM_INT_eAddressSector_t)0xF0200000);
////    ECU_MEM_INT_eEraseSector((ECU_MEM_INT_eAddressSector_t)0xF0204000);
////    ECU_MEM_INT_eEraseSector((ECU_MEM_INT_eAddressSector_t)0xF0208000);
////    ECU_MEM_INT_eEraseSector((ECU_MEM_INT_eAddressSector_t)0xF020C000);
////    APP_BOOT_u8FirstWrite = 0;
////  }
////  APP_BOOT_u8DataRec[su8DownloadCount] = APP_BOOT_au8Data[2];
////  APP_BOOT_u8DataRec[su8DownloadCount + 1] = APP_BOOT_au8Data[3];
////  APP_BOOT_u8DataRec[su8DownloadCount + 2] = APP_BOOT_au8Data[4];
////  APP_BOOT_u8DataRec[su8DownloadCount + 3] = APP_BOOT_au8Data[5];
////  su8DownloadCount = su8DownloadCount + 4;
////  if(su8DownloadCount == 16)
////  {
////    ECU_MEM_INT_eWriteBlock(APP_BOOT_u32DownloadEEPROMAddress, APP_BOOT_u8DataRec);
////    APP_BOOT_u32DownloadEEPROMAddress = APP_BOOT_u32DownloadEEPROMAddress + 16;
////    su8DownloadCount = 0;
////    for(u8Count = 0; u8Count < 16; u8Count++)
////    {
////      APP_BOOT_u8DataRec[u8Count] = 0;
////    }
////  }
////  local_APP_BOOT_vdEndService(STATUS_OK, APP_BOOT_au8DataNotUsed);    
//}
//
//void local_APP_BOOT_vdUploadEEPROM(void)
//{
//  static uint8_t su8BytePos = 0;
//  uint8_t au8CANFrame[4] = {0};
//  if(APP_BOOT_u8FirstRead == 1) // Due to Fapi library limitaions on starting reading sector from middle
//  {
//    APP_BOOT_u8FirstRead = 0;
//    ECU_MEM_INT_eReadBlock(APP_BOOT_u32UploadEEPROMAddress, APP_BOOT_u8BlockData);            
//  }
//  else if(su8BytePos == 0 && APP_BOOT_u8FirstRead == 0)
//  {
//    APP_BOOT_u32UploadEEPROMAddress = APP_BOOT_u32UploadEEPROMAddress + 16;
//    ECU_MEM_INT_eReadBlock(APP_BOOT_u32UploadEEPROMAddress, APP_BOOT_u8BlockData);        
//    APP_BOOT_u8FirstRead = 0; 
//  }
//  au8CANFrame[0] =  APP_BOOT_u8BlockData[su8BytePos + 0];
//  au8CANFrame[1] =  APP_BOOT_u8BlockData[su8BytePos + 1];
//  au8CANFrame[2] =  APP_BOOT_u8BlockData[su8BytePos + 2];
//  au8CANFrame[3] =  APP_BOOT_u8BlockData[su8BytePos + 3];  
//  local_APP_BOOT_vdEndService(STATUS_OK,au8CANFrame);
//  su8BytePos = su8BytePos + 4;
//  if(su8BytePos == 16)
//  {
//    su8BytePos = 0;
//  }
//}
//
//void local_APP_BOOT_vdSwUpload(void)
//{
//  uint32_t u32AddressReceived;
//  uint32_t u32StartAddressSREC = 0;
//  uint8_t au8Response[4] = {0};
//  uint32_t u32ApplicationStartAddress = (uint32_t)APP_BOOT_APPLICATION_START_ADDRESS;
//  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent intervention from other connection
//  
//  if(APP_BOOT_au8Data[0] == 0x1) //Response with confirmation plus start address
//  {
//    au8Response[3] = (uint8_t)(u32ApplicationStartAddress); //MSB
//    au8Response[2] = (uint8_t)(u32ApplicationStartAddress >> 8);
//    au8Response[1] = (uint8_t)(u32ApplicationStartAddress >> 16);
//    au8Response[0] = (uint8_t)(u32ApplicationStartAddress >> 24); //LSB
//    local_APP_BOOT_vdEndService(STATUS_OK, au8Response);
//    return;
//  }
//  else if(APP_BOOT_au8Data[0] == 0x2) //Response with confirmation plus end address
//  {
//    au8Response[3] = (uint8_t)(APP_BOOT_u32ApplicationEndAddress);
//    au8Response[2] = (uint8_t)(APP_BOOT_u32ApplicationEndAddress >> 8);
//    au8Response[1] = (uint8_t)(APP_BOOT_u32ApplicationEndAddress >> 16);
//    au8Response[0] = (uint8_t)(APP_BOOT_u32ApplicationEndAddress >> 24);
//    local_APP_BOOT_vdEndService(STATUS_OK, au8Response);    
//    return;
//  }
//  else if(APP_BOOT_au8Data[0] == 0x3) //Response with confirmation plus S0 srec record
//  {
//    static uint8_t su8Count = 0;
//    uint32_t u32Temp = 0;
//    uint8_t u8SignalNum;
//    switch(su8Count)
//    {
//    case 0:
//      u8SignalNum = ECU_MEM_INT_HEADER_SREC_0;
//      su8Count++;
//      break;
//    case 1:
//      u8SignalNum = ECU_MEM_INT_HEADER_SREC_1;
//      su8Count++;
//      break;
//    case 2:
//      u8SignalNum = ECU_MEM_INT_HEADER_SREC_2;
//      su8Count++;
//      break;
//    case 3:
//      u8SignalNum = ECU_MEM_INT_HEADER_SREC_3;
//      break;
//    default:
//      break;
//    }
//    ECU_MEM_INT_eReadRawSignalValue(u8SignalNum, &u32Temp);
//    au8Response[3] = (uint8_t)(u32Temp);
//    au8Response[2] = (uint8_t)(u32Temp >> 8);
//    au8Response[1] = (uint8_t)(u32Temp >> 16);
//    au8Response[0] = (uint8_t)(u32Temp >> 24);
//    local_APP_BOOT_vdEndService(STATUS_OK, au8Response);   
//    return;
//  }
//  else if(APP_BOOT_au8Data[0] == 0x4) //Response with confirmation plus starting address (last srec record)
//  {
//    ECU_MEM_INT_eReadRawSignalValue(ECU_MEM_INT_START_ADDRESS, &u32StartAddressSREC);
//    au8Response[3] = (uint8_t)(u32StartAddressSREC);
//    au8Response[2] = (uint8_t)(u32StartAddressSREC >> 8);
//    au8Response[1] = (uint8_t)(u32StartAddressSREC >> 16);
//    au8Response[0] = (uint8_t)(u32StartAddressSREC >> 24);
//    local_APP_BOOT_vdEndService(STATUS_OK, au8Response);    
//    ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_IDLE);
//    return;
//  }  
//  else if(APP_BOOT_au8Data[0] == 0) // Start uploading current application
//  {
//    static uint8_t u8UploadByteCounter = 0;
//    u32AddressReceived = 0;
//    u32AddressReceived = (APP_BOOT_au8Data[2] << 24);
//    u32AddressReceived |= (APP_BOOT_au8Data[3] << 16);
//    u32AddressReceived |= (APP_BOOT_au8Data[4] << 8);
//    u32AddressReceived |= (APP_BOOT_au8Data[5]);
//    if(APP_BOOT_strBlockTemp.u32Address == 0) // First time read request - this handles the case when u32address is = 0
//    {
//      APP_BOOT_strBlockTemp.u32Address = u32AddressReceived;  
//      ECU_MEM_CODE_eReadBlock(&APP_BOOT_strBlockTemp);
//    }
//    else if((u32AddressReceived >= (APP_BOOT_strBlockTemp.u32Address + 16)) && (u32AddressReceived != 0)) // check for new address or next 4 bytes of same address
//    {
//      APP_BOOT_strBlockTemp.u32Address = u32AddressReceived;  
//      ECU_MEM_CODE_eReadBlock(&APP_BOOT_strBlockTemp);
//    }
//    uint8_t u8LoopCount;
//    uint8_t au8CANFrame[4] = {0};
//    /*Send bytes in existing block depending on value of static variable*/
//    for(u8LoopCount = (u8UploadByteCounter*4); u8LoopCount < (4 + (u8UploadByteCounter*4)); u8LoopCount++)
//    {
//      au8CANFrame[u8LoopCount - (u8UploadByteCounter*4)] = APP_BOOT_strBlockTemp.au8Byte[u8LoopCount];
//    }
//    local_APP_BOOT_vdEndService(STATUS_OK,au8CANFrame);
//    u8UploadByteCounter++;
//    if(u8UploadByteCounter == 4)
//    {
//      u8UploadByteCounter = 0;
//    }
//  }
//  else
//  {
//    return;
//  }
//}
//
//void local_APP_BOOT_vdSwDownload(void)
//{
//  uint8_t u8Counter;
//  STATUS_t eStatus = STATUS_BUSY;
//  static uint8_t su8PageReceived = 0;
//  ECU_DIAG_vdSetAppStatus(ECU_DIAG_APP_BUSY); // set app status to busy to prevent intervention from other connection  
//  switch(APP_BOOT_eDownloadStatus)
//  {
//  case APP_BOOT_DL_ST_HEADER_RECEIVE_PRE_INIT: // This state receives the header srec line
//    local_APP_BOOT_vdReceiveHeaderSrecLine();
//  break;
//  case APP_BOOT_DL_ST_START_SREC_RECEIVE_PRE_INIT: // This state receives last srec line
//    local_APP_BOOT_vdReceiveLastSrecLine();
//  break;
//  case APP_BOOT_DL_ST_INIT:
//    local_APP_BOOT_vdPageDataReset((APP_BOOT_strPageMemory_t *)APP_BOOT_astrBlockMemory);
//    APP_BOOT_u32StartAddress = 0;
//    /*Prepare for page download*/
//    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[0];
//    APP_BOOT_u32PageSize |= APP_BOOT_au8Data[1] << 8;
//    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[2];
//    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[3] << 8;
//    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[4] << 16;
//    APP_BOOT_u32StartAddress |= APP_BOOT_au8Data[5] << 24;
//    APP_BOOT_u16BlockByteCounter = 0;
//    APP_BOOT_u8BlockIndex = 0;
//    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_RECEIVE;
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8ReceivedDataEcho,STATUS_OK);
//    break;
//  case APP_BOOT_DL_ST_PAGE_RECEIVE:
//    /*Receive page and calcualte the received page checksum*/
//    APP_BOOT_u8CheckSumReceived = 0;
//    APP_BOOT_u8CheckSumCalculated = 0;
//    APP_BOOT_u8CheckSumOfPageWritten = 0;
//    if(su8PageReceived == 0)
//    {
//      for(u8Counter = 0; u8Counter < 6; u8Counter++)
//      {
//        APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].au8Byte[APP_BOOT_u16BlockByteCounter] = APP_BOOT_au8Data[u8Counter];
//        APP_BOOT_u16BlockByteCounter++;
//        if(APP_BOOT_u16BlockByteCounter == APP_BOOT_BLOCK_BYTE_SIZE)
//        {
//          APP_BOOT_u16BlockByteCounter = 0;
//          APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].u32Address = (APP_BOOT_u32StartAddress + (APP_BOOT_u8BlockIndex * APP_BOOT_BLOCK_BYTE_SIZE));
//          APP_BOOT_astrBlockMemory[APP_BOOT_u8BlockIndex].u8DataBytesCount = 16;
//          APP_BOOT_u8BlockIndex++;
//          break;
//        }
//      }
//    }
//    if(APP_BOOT_u8BlockIndex == (APP_BOOT_u32PageSize/APP_BOOT_BLOCK_BYTE_SIZE))
//    {
//      su8PageReceived = 1;
//    }
//    if((su8PageReceived == 1) && (APP_BOOT_u8ServiceId == SID_REQUEST_TRANSFER_EXIT))
//    {
//      su8PageReceived = 0;
//      APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_PAGE_DOWNLOAD;     
//      APP_BOOT_u8CheckSumReceived = APP_BOOT_au8Data[5];
//      local_APP_BOOT_vdSwDownload();
//      break;
//    }
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8ReceivedDataEcho, STATUS_OK);
//    break;
//    
//  case APP_BOOT_DL_ST_PAGE_DOWNLOAD:
//    /*Download the page and confirm the download by calcualting the checksum of the flashed bytes (read them)*/
//    /* Check the real-time of flashing one block, to know how much flash in one task period */
//    
//    APP_BOOT_u8CheckSumCalculated = local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_astrBlockMemory, APP_BOOT_BLOCK_BYTE_SIZE);
//    
//    if(APP_BOOT_u8CheckSumCalculated == APP_BOOT_u8CheckSumReceived)
//    {
//      ECU_MEM_CODE_eWriteBlocks(APP_BOOT_astrBlockMemory, APP_BOOT_u8BlockIndex); // Write page as array of blocks
//      APP_BOOT_strPageMemoryTemplate.u32PageStartingAddress = APP_BOOT_u32StartAddress; // set page starting address of the temporary page  
//      
//      ECU_MEM_CODE_eReadPage(&APP_BOOT_strPageMemoryTemplate); // Read page as a whole
//      APP_BOOT_u8CheckSumOfPageWritten = local_APP_BOOT_u8PageCheckSumCalculate(&APP_BOOT_strPageMemoryTemplate); // Calculate checksum of written page
//      
//      if(APP_BOOT_u8CheckSumOfPageWritten == APP_BOOT_u8CheckSumCalculated)
//      {
//        
//        eStatus = STATUS_OK;
//      }
//      else
//      {
//        eStatus = STATUS_NOK;       
//      }
//    }
//    else
//    {
//      eStatus = STATUS_NOK;
//    }
//    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;      
//    APP_BOOT_au8RDTSend[3] = APP_BOOT_u8CheckSumCalculated;
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8RDTSend, eStatus);
//    UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIO10, UC_DIO_OUT_COMMAND_OFF);      
//    break;
//    
//  case APP_BOOT_DL_ST_ERROR:
//    /*Respond with negative response*/
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, STATUS_NOK);
//    break;
//  default:
//    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
//    break;
//  }
//}
//
//void local_APP_BOOT_vdReceiveHeaderSrecLine(void)
//{
//  STATUS_t eStatus = STATUS_BUSY;
//  static uint32_t su32SREC_S0 = 0;
//  static uint8_t su8S0_Count = 0;
//  float fltRecData = 0.0;
//  switch(su8S0_Count)
//  {
//  case 0:
//    su32SREC_S0 = APP_BOOT_au8Data[0] << 24;
//    su32SREC_S0 |= APP_BOOT_au8Data[1] << 16;
//    su32SREC_S0 |= APP_BOOT_au8Data[2] << 8;
//    su32SREC_S0 |= APP_BOOT_au8Data[3];
//    fltRecData = (float)(su32SREC_S0);
//    eStatus = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_HEADER_SREC_0,fltRecData, su32SREC_S0);
//    su32SREC_S0 = 0;
//    fltRecData = 0;
//    su32SREC_S0 = APP_BOOT_au8Data[4] << 24;
//    su32SREC_S0 |= APP_BOOT_au8Data[5] << 16;
//    su8S0_Count++;
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, eStatus);
//    break;
//  case 1:
//    su32SREC_S0 |= APP_BOOT_au8Data[0] << 8;
//    su32SREC_S0 |= APP_BOOT_au8Data[1];
//    fltRecData = (float)(su32SREC_S0);
//    eStatus = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_HEADER_SREC_1,fltRecData, su32SREC_S0);
//    su32SREC_S0 = 0;
//    fltRecData = 0.0;
//    su32SREC_S0 = APP_BOOT_au8Data[2] << 24;
//    su32SREC_S0 |= APP_BOOT_au8Data[3] << 16;
//    su32SREC_S0 |= APP_BOOT_au8Data[4] << 8;
//    su32SREC_S0 |= APP_BOOT_au8Data[5];
//    fltRecData = (float)(su32SREC_S0);
//    eStatus = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_HEADER_SREC_2,fltRecData, su32SREC_S0);
//    su8S0_Count++;
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, eStatus);
//    break;
//  case 2:
//    su32SREC_S0 = 0;
//    fltRecData = 0.0;
//    su32SREC_S0 = APP_BOOT_au8Data[0] << 24;
//    su32SREC_S0 |= APP_BOOT_au8Data[1] << 16;
//    su32SREC_S0 |= APP_BOOT_au8Data[2] << 8;
//    su32SREC_S0 |= APP_BOOT_au8Data[3];
//    fltRecData = (float)(su32SREC_S0);
//    eStatus = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_HEADER_SREC_3,fltRecData, su32SREC_S0);
//    local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, eStatus);
//    APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_START_SREC_RECEIVE_PRE_INIT;  
//    break;
//  default:
//    break;
//  }
//}
//
//void local_APP_BOOT_vdReceiveLastSrecLine(void)
//{
//  STATUS_t eStatus = STATUS_BUSY;
//  float fltRecData;
//  uint32_t u32StartingAddress = 0;
//  u32StartingAddress = APP_BOOT_au8Data[0] << 24;
//  u32StartingAddress |= APP_BOOT_au8Data[1] << 16;
//  u32StartingAddress |= APP_BOOT_au8Data[2] << 8;
//  u32StartingAddress |= APP_BOOT_au8Data[3];
//  fltRecData = (float)(u32StartingAddress);
//  eStatus = ECU_MEM_INT_eWriteSignalValue(ECU_MEM_INT_START_ADDRESS, fltRecData, u32StartingAddress);
//  local_APP_BOOT_vdEndServiceWithEchoArray(APP_BOOT_au8DataNotUsed, eStatus);  
//  APP_BOOT_eDownloadStatus = APP_BOOT_DL_ST_INIT;
//}
//
//void local_APP_BOOT_vdEndServiceWithEchoArray(uint8_t *pau8EchoArray, STATUS_t eStatus)
//{
//  uint8_t u8Count;
//  local_APP_BOOT_vdFillEchoArray(pau8EchoArray);
//  local_APP_BOOT_vdEndService(eStatus, pau8EchoArray);
//  for(u8Count = 0; u8Count < 8; u8Count++)
//  {
//    pau8EchoArray[u8Count] = 0;
//  }
//}
//
//void local_APP_BOOT_vdFillEchoArray(uint8_t *pau8EchoArray)
//{
//  pau8EchoArray[0] = APP_BOOT_au8Data[2];
//  pau8EchoArray[1] = APP_BOOT_au8Data[3];
//  pau8EchoArray[2] = APP_BOOT_au8Data[4];
//  pau8EchoArray[3] = APP_BOOT_au8Data[5];    
//}
//
//void local_APP_BOOT_vdEndService(STATUS_t eStatus, uint8_t *pau8Data)
//{
//	APP_BOOT_eStatus = APP_BOOT_ST_INIT;
//	ECU_DIAG_vdServiceDone(eStatus, pau8Data);
//}
//

//
//void local_APP_BOOT_vdPageDataReset(APP_BOOT_strPageMemory_t *strPageMemory)
//{
//  uint8_t u8IndexBlock;
//  uint8_t u8Count;
//  for(u8IndexBlock = (uint8_t)0; u8IndexBlock < APP_BOOT_BLOCKS_PER_PAGE; u8IndexBlock++)
//  {
//    for(u8Count = 0; u8Count < APP_BOOT_BLOCK_BYTE_SIZE; u8Count++)
//    {
//      strPageMemory[u8IndexBlock].UC_FLASH_astrBlocksOfMemory[u8IndexBlock].au8Byte[u8Count] = (uint8_t)0;      
//    }
//    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u32Address = 0;
//    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u32LineNumber = 0;
//    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u8DataBytesCount = 0;
//    strPageMemory->UC_FLASH_astrBlocksOfMemory[u8IndexBlock].u8CheckSum = 0;
//  }
//  strPageMemory->u16BytesNumber = 0;
//  strPageMemory->u32PageStartingAddress = 0;
//}
//
//uint8_t local_APP_BOOT_u8BlocksArrayCheckSumCalculate(APP_BOOT_strBlockMemory_t* pBlockMemory, uint8_t u8PageSize) // Check sum of page as array of blocks
//{
//  uint8_t u8CheckSum = 0;
//  uint8_t u8Counter;
//  uint8_t u8LoopCounter;
//  for(u8Counter = 0; u8Counter < u8PageSize; u8Counter++)
//  {
//    for(u8LoopCounter = 0; u8LoopCounter < APP_BOOT_BLOCK_BYTE_SIZE; u8LoopCounter++)
//    {
//      u8CheckSum = u8CheckSum + pBlockMemory[u8Counter].au8Byte[u8LoopCounter]; 
//    }
//  }
//  u8CheckSum = ~u8CheckSum;
//  return u8CheckSum;
//}
//
//uint8_t local_APP_BOOT_u8PageCheckSumCalculate(APP_BOOT_strPageMemory_t* pPageMemory)
//{
//  uint8_t u8PageCheckSum = 0;
//  uint8_t u8Counter;
//  uint8_t u8LoopCounter;
//  for(u8LoopCounter = 0; u8LoopCounter < pPageMemory->u8BlocksNumber; u8LoopCounter++)
//  {
//    for(u8Counter = 0; u8Counter < APP_BOOT_BLOCK_BYTE_SIZE; u8Counter++)
//    {
//      u8PageCheckSum  = u8PageCheckSum  + pPageMemory->UC_FLASH_astrBlocksOfMemory[u8LoopCounter].au8Byte[u8Counter];      
//    }
//  }
//  u8PageCheckSum = ~u8PageCheckSum;
//  return u8PageCheckSum ;
//}
//
#endif