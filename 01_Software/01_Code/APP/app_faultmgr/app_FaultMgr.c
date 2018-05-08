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

File Name: app_FaultMgr.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app_FaultMgr_cfg.h"
#include "app_FaultMgr.h"
#include "app.h"

#ifdef APP_FLT_MODULE_ENABLE


/********************************************************************************************/
/*********************************** INTERNAL MACROS ****************************************/
/********************************************************************************************/


/********************************************************************************************/
/********************* INTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/
APP_FLT_eDtcSeverity_t APP_FLT_eDtcSeverity = APP_FLT_DTC_SEV_NO_ERROR;

/********************************************************************************************/
/********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/
extern APP_FLT_strDtc_t FLT_astrDtc[APP_FLT_DTC_NUM];

/********************************************************************************************/
/******************************* CALLBLACKS DECLARATION *************************************/
/********************************************************************************************/



/********************************************************************************************/
/****************************** LOCAL FUNCTIONS DECLARATION *********************************/
/********************************************************************************************/
void local_vdFaultLedsControl(void);
void local_vdSaveDtcsToRAM(void);

/********************************************************************************************/
/**************************** GLOBAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/
void app_FaultMgr_initialize(void)
{
  uint16_t u16IndexDtc;
  
  for(u16IndexDtc = (uint16_t)0; u16IndexDtc < APP_FLT_DTC_NUM; u16IndexDtc++)
  {
    FLT_astrDtc[u16IndexDtc].u8ErrorCount = (uint8_t)0;
    FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided = APP_FLT_DTC_SEV_NO_ERROR;
  }
}

void app_FaultMgr_terminate(void)
{
  /*Save the latest DTCs to the RAM*/
  local_vdSaveDtcsToRAM();
}

void app_FaultMgr_fcn(void)
{
  uint16_t u16IndexDtc;
  uint8_t u8FaultExists = TAPAS_FALSE;
  
  /*Loop on all the DTCs*/
  for(u16IndexDtc = (uint16_t)0; u16IndexDtc < APP_FLT_DTC_NUM; u16IndexDtc++)
  {
    /*If there is an error read fucntion*/
    if(FLT_astrDtc[u16IndexDtc].p2fRteReadError != TAPAS_NULL)
    {
      /* Check if there is or there is not an error*/
      u8FaultExists = (uint8_t)FLT_astrDtc[u16IndexDtc].p2fRteReadError();
      
      /*If there is an error*/
      if((u8FaultExists == TAPAS_TRUE) && (FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided != FLT_astrDtc[u16IndexDtc].eDtcSeverity))
      {       
        if(FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter == 0)
        {
          FLT_astrDtc[u16IndexDtc].u8ErrorCount++;
          
          if(FLT_astrDtc[u16IndexDtc].u8ErrorCount < FLT_astrDtc[u16IndexDtc].u8ErrorCountLimit)
          {
            if(FLT_astrDtc[u16IndexDtc].eDtcSeverity != APP_FLT_DTC_SEV_WARNING)
            {
              FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided = APP_FLT_DTC_SEV_WARNING;
            }
          }
          else
          {
            /*Limit reached*/
            FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided = FLT_astrDtc[u16IndexDtc].eDtcSeverity;
          }
          
          FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter++;
        }
        else
        {
          FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter++;
          
          if((FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter * APP_FLT_TASK_MS) >= FLT_astrDtc[u16IndexDtc].u16ResetDeltaTimeMs)
          {
            /*Reset the counter*/
            FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter = 0;
            /*Try to clear the error*/
            FLT_astrDtc[u16IndexDtc].p2fRteWriteErrorClear(TAPAS_TRUE);
          }
          else
          {
            FLT_astrDtc[u16IndexDtc].p2fRteWriteErrorClear(TAPAS_FALSE);
          }
        }
      }
      else
      {
        if(u8FaultExists == TAPAS_FALSE)
        {
          FLT_astrDtc[u16IndexDtc].p2fRteWriteErrorClear(TAPAS_FALSE);
          
          /* If error has been cleared, reset counters as long the severity is not set*/
          /* If the severity of the DTC is warning, it can be reset*/
          if(FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided != FLT_astrDtc[u16IndexDtc].eDtcSeverity)
          {
            /*Reset Counters and Errors*/
#if 0
            FLT_astrDtc[u16IndexDtc].u8ErrorCount = 0;
            FLT_astrDtc[u16IndexDtc].u32DeltaTimeCounter = 0;
            FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided = APP_FLT_DTC_SEV_NO_ERROR;
#endif /*0 - Remove error reset in warning phase since it is not handled probably in the models yet*/
          }
          else if((FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided == FLT_astrDtc[u16IndexDtc].eDtcSeverity) && (FLT_astrDtc[u16IndexDtc].eDtcSeverity == APP_FLT_DTC_SEV_WARNING))
          {
            FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided = APP_FLT_DTC_SEV_NO_ERROR;
          }
        }
      }
    }
  }

  /*Check for the highest severity exists*/
  APP_FLT_eDtcSeverity = APP_FLT_DTC_SEV_NO_ERROR;
  for(u16IndexDtc = (uint16_t)0; u16IndexDtc < APP_FLT_DTC_NUM; u16IndexDtc++)
  {
    if(FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided > APP_FLT_eDtcSeverity)
    {
      APP_FLT_eDtcSeverity = FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided; 
    }
  }
  
  /* Indicate the faults through leds*/
  local_vdFaultLedsControl();
  
  /* Report to the system the fault severity*/
  RTE_Write_FLT_SystemErrorSeverity((float)APP_FLT_eDtcSeverity);
  
  /*Periodically save current dtcs to the RAM */
  local_vdSaveDtcsToRAM();
}

void app_FaultMgr_ClearDTC(void)
{
  uint8_t u8Counter;
  for(u8Counter = 0; u8Counter < APP_FLT_DTC_NUM; u8Counter++)
  {
    FLT_astrDtc[u8Counter].u32DeltaTimeCounter = TAPAS_DEFAULT;
    FLT_astrDtc[u8Counter].u8ErrorFlag = TAPAS_FALSE;
    FLT_astrDtc[u8Counter].u8ErrorCount = TAPAS_DEFAULT;
    FLT_astrDtc[u8Counter].eDtcSeverityDecided = APP_FLT_DTC_SEV_NO_ERROR;
  }
}

void app_FaultMgr_ReadConfirmedDTCs(uint8_t* pau8ConfirmedDTCs)
{
  uint8_t u8Counter;
  for(u8Counter = 0; u8Counter < APP_FLT_DTC_NUM; u8Counter++)
  {
    if(FLT_astrDtc[u8Counter].eDtcSeverityDecided == FLT_astrDtc[u8Counter].eDtcSeverity)
    {
      uint8_t u8Value = 0x08;
      u8Value |= (FLT_astrDtc[u8Counter].eDtcSeverityDecided);
      uint8_t u8Temp = (FLT_astrDtc[u8Counter].u8ErrorCount & 0x01);
      u8Value |= (u8Temp << 2U); // extract lsb
      u8Temp = ((FLT_astrDtc[u8Counter].u8ErrorCount & 0x1E) >> 1U);
      u8Temp = (u8Temp & 0x0F);
      u8Value |= (u8Temp << 4U); // extract next 4 bits
      pau8ConfirmedDTCs[u8Counter] = u8Value;
    }
    else
    {
      uint8_t u8Value = 0;
      u8Value |= (FLT_astrDtc[u8Counter].eDtcSeverityDecided);
      uint8_t u8Temp = (FLT_astrDtc[u8Counter].u8ErrorCount & 0x01);
      u8Value |= (u8Temp << 2U); // extract lsb
      u8Temp = ((FLT_astrDtc[u8Counter].u8ErrorCount & 0x1E) >> 1U);
      u8Temp = (u8Temp & 0x0F);
      u8Value |= (u8Temp << 4U); // extract next 4 bits
      pau8ConfirmedDTCs[u8Counter] = u8Value;
    }
  }
}
/********************************************************************************************/
/***************************** LOCAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/

void local_vdSaveDtcsToRAM(void)
{
  uint32_t u32MemoryBlock;
  uint16_t u16IndexDtc;
  
  /*Loop on all the DTCs*/
  for(u16IndexDtc = (uint16_t)0; u16IndexDtc < APP_FLT_DTC_NUM; u16IndexDtc++)
  {
    u32MemoryBlock = (uint32_t)0;
    u32MemoryBlock |= (
                        (FLT_astrDtc[u16IndexDtc].u8IdDtc << (8*0))            |
                        (((uint8_t)FLT_astrDtc[u16IndexDtc].eDtcSeverityDecided) << (8*2))|
                        (FLT_astrDtc[u16IndexDtc].u8ErrorCount << (8*3))
                      );
    
    RTE_Service_MEM_eWriteSignalValue(FLT_astrDtc[u16IndexDtc].u16IdMemory, (float)u32MemoryBlock, (uint32_t)u32MemoryBlock);
  }  
}

void local_vdFaultLedsControl(void)
{
  static uint32_t su32Counter = 1;
  
  switch(APP_FLT_eDtcSeverity)
  {
    case APP_FLT_DTC_SEV_NO_ERROR:
      /*Green Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_BOOT_HB, ECU_IO_OUT_COMMAND_OFF);
      /*White Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_OFF);
      break;
    case APP_FLT_DTC_SEV_WARNING:
      /*Green Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_BOOT_HB, ECU_IO_OUT_COMMAND_ON);
      /*White Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_OFF);
      break;
    case APP_FLT_DTC_SEV_FAULT_L1:
      /*Green Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_BOOT_HB, ECU_IO_OUT_COMMAND_OFF);
      /*White Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_ON);
      break;
    case APP_FLT_DTC_SEV_FAULT_L2:      
      if((su32Counter*APP_FLT_TASK_MS) >= 500)
      {
        /*Green Led*/
        RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_BOOT_HB, ECU_IO_OUT_COMMAND_TOGGLE);
        /*White Led*/
        RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_TOGGLE);
        su32Counter = 1;
      }
      else
      {
        su32Counter++;
      }
      break;
    default:
      /*Green Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_BOOT_HB, ECU_IO_OUT_COMMAND_OFF);
      /*White Led*/
      RTE_Service_IO_eInternalOutputControl(ECU_IO_DOUT_INT_DIAG_HB, ECU_IO_OUT_COMMAND_OFF);
      break;
  }
}

/********************************************************************************************/
/************************************* CALLBACKS ********************************************/
/********************************************************************************************/

#endif /*APP_FLT_MODULE_ENABLE*/
