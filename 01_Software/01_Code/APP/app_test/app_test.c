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

File Name: app_test.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app_test.h"
#include "ecu.h"
#include "uc.h"

#define APP_TEST_TASK_MS                               (100)
#define APP_TEST_HEARTBEAT_HALF_PERIOD_MS              (500)

uint8_t APP_TEST_u8InputReadMaxim;
uint32_t APP_TEST_u32SubSchCounter = 1;
uint8_t u8ShutDown = 0;
uint8_t u8Counter = 0;
uint8_t u8Flag = 0;
uint8_t au8EEPROMData[4] = {0xA0,0xB0,0xC0,0xD0};

void APP_vdTestMgr(void)
{
//  static uint8_t su8Counter = 0;
//  static uint8_t u8Flag = 0;
//  static uint8_t u8Loop;
//  float fltValue;
  
//  su8Counter++;
  if(u8Flag == 0)
  {
    UC_EEPROM_ERASE_SECTOR(0);
    UC_EEPROM_WRITE(0xF0200000, au8EEPROMData, 4);      
    u8Flag = 1;
  }
  if(u8Counter == 20)
  {
    UC_DIO_eCommandOutputPin(14, UC_DIO_OUT_COMMAND_OFF);    
    u8Counter = 0;
  }  
  if(u8Counter < 10 || u8Counter == 10)
  {
    UC_DIO_eCommandOutputPin(14, UC_DIO_OUT_COMMAND_TOGGLE);
    u8Counter++;       
  }
  if(u8Counter > 10)
  {
    UC_DIO_eCommandOutputPin(14, UC_DIO_OUT_COMMAND_ON);
    u8Counter++;       
  }  
//  if (su8Counter == 5)
//  {
//    UC_DIO_eCommandOutputPin(UC_DIO_OUTPUT_GIOHB, UC_DIO_OUT_COMMAND_TOGGLE);
//    su8Counter = 0;
//  }
  //ECU_MEM_INT_eEraseSector(0);
//  ECU_MEM_INT_eWriteSignalValue(0, 20.4);
//  ECU_MEM_INT_eWriteSignalValue(1, 21.4);
//  ECU_MEM_INT_eWriteSignalValue(2, 22.4);
//  ECU_MEM_INT_eWriteSignalValue(3, 23.4);
//  ECU_MEM_INT_eWriteSignalValue(4, 24.4);
//  ECU_MEM_INT_eWriteSignalValue(5, 25.4);
//  if(u8ShutDown == 1)
//    ECU_MEM_INT_eDirectWriteSignalValue(10, 400.400);
//  for(u8Loop = 0; u8Loop < 35; u8Loop++)
//  {
//    ECU_MEM_eWriteSignalValue(u8Loop, 1050);
//  }
//  if(u8Flag == 1)
//  {
//    ECU_SYS_vdShutdown();    
//  }
//
//  ECU_ANLG_eReadSignal(ECU_ANLG_CABIN_FAN_POS, &fltValue);
//  ECU_IO_eSetPwm(ECU_IO_POUT_WATER_PUMP, 1000, (uint8_t)fltValue);
  
//  float fltSignal;
//  uint8_t u8IsExWdgReset;
//  uint8_t u8IsExWdgResetNeeded;
//  ECU_SYS_vdGetResetStatus(&u8IsExWdgReset);
//  
//  u8IsExWdgResetNeeded = 0;
//  
//  ECU_COM_vdWriteSignal(APP_TX_VCU_DASH_FANFAILURE, u8IsExWdgReset);  
//  
//  ECU_COM_vdReadSignal(APP_RX_LV_CURRENT, &fltSignal);
//  if(fltSignal == 1)
//  {
//    u8IsExWdgResetNeeded = 1;
//  }
//
//  ECU_SYS_vdClearResetStatus(u8IsExWdgResetNeeded);
  
//  float fltSignal = 0.0f;
//  STATUS_t eStatus;
//  uint32_t u32Test;
  

//  eStatus = ECU_COM_vdReadSignal(APP_RX_SIGNAL_CONTROL_1, &fltSignal);
//  
//  u32Test = (uint32_t)((fltSignal * (float)10));
//  
//  if(u32Test == 27)
//  {
//    if(eStatus == STATUS_OK)
//    {
//      ECU_COM_vdWriteSignal(APP_TX_TI_A1CH2, fltSignal);
//    }
//  }
//  else
//  {
//    ECU_COM_vdWriteSignal(APP_TX_TI_A1CH2, fltSignal);
//    eStatus = STATUS_NOK;
//  }
//  
//  eStatus = ECU_COM_vdReadSignal(APP_RX_RX2SIG2, &fltSignal);
//  
//  if(eStatus == STATUS_OK)
//  {
//    ECU_COM_vdWriteSignal(APP_TX_TI_A1CH0, fltSignal);
//  }

//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_0, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH0, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_1, &fltSignal);
////  ECU_COM_vdWriteSignal(APP_TX_VCU_DASH_DRIVINGMILE, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_2, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH2, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_3, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH3, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_4, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH4, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_5, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH5, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_6, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH6, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_7, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH7, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_8, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH8, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_9, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH9, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_10, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH10, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_11, &fltSignal);
//  //ECU_COM_vdWriteSignal(ANALOGCH11, fltSignal);
//  ECU_ANLG_eReadSignal(ECU_ANLG_SIG_3V3_SUPPLY, &fltSignal);
//  //ECU_COM_vdWriteSignal(SUPPLY_3V3, fltSignal);
  
  //ECU_IO_eInputRead(ECU_IO_INPUT_ID_1, &APP_TEST_u8InputReadMaxim);
  //ECU_COM_vdReadSignal(SIGNAL_CONTROL_1, &fltSignal);
  //ECU_COM_vdWriteSignal(TI_SPI3C0, fltSignal);
  
  //ECU_IO_eInputRead(ECU_IO_INPUT_ID_2, &APP_TEST_u8InputReadMaxim);
  //ECU_COM_vdReadSignal(SIGNAL_CONTROL_2, &fltSignal);
  //ECU_COM_vdWriteSignal(TI_A1CH2, fltSignal);
  
  //ECU_IO_eInputRead(ECU_IO_INPUT_ID_6, &APP_TEST_u8InputReadMaxim);
  //ECU_COM_vdReadSignal(SIGNAL_CONTROL_3, &fltSignal);
  //ECU_COM_vdWriteSignal(TI_A1CH0, fltSignal);
  
//  ECU_COM_vdReadSignal(BIT4, &fltSignal);
//  ECU_COM_vdWriteSignal(BIT1, fltSignal);
//  ECU_COM_vdReadSignal(BIT5, &fltSignal);
//  ECU_COM_vdWriteSignal(BIT2, fltSignal);
//  ECU_COM_vdReadSignal(BIT6, &fltSignal);
//  ECU_COM_vdWriteSignal(BIT3, fltSignal);
//  
//  ECU_COM_vdReadSignal(APP_RX_MCU_VCU_MOTORRPM, &fltSignal);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_RPMSETPOINT, fltSignal);
//  
//  ECU_COM_vdReadSignal(APP_RX_MCU_VCU_MOTORTORQUE, &fltSignal);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_TORQUESETPOINT, fltSignal);
//  
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_ENABLE, 0);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_MODECONTROL, 1);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_INVERTERCOMMAND, 2);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_MCU_DRIVENCOMMAND, 3);
  
//  ECU_COM_vdReadSignal(APP_RX_DASH_VCU_DASHLIFE, &fltSignal);
//  ECU_COM_vdWriteSignal(APP_TX_VCU_DASH_VEHICLESPEED, fltSignal);
  
  
//  if((APP_TEST_u32SubSchCounter*APP_TEST_TASK_MS) == APP_TEST_HEARTBEAT_HALF_PERIOD_MS)
//  {
//    ECU_IO_eOutputControl(ECU_IO_OUTPUT_LED4, ECU_IO_OUT_COMMAND_TOGGLE);
//    //ECU_IO_eOutputControl(ECU_IO_OUTPUT_AC_CHARGING_LED3, ECU_IO_OUT_COMMAND_TOGGLE);
//    //ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO12_LED2, ECU_IO_OUT_COMMAND_TOGGLE);
//    //ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO11_LED1, ECU_IO_OUT_COMMAND_TOGGLE);
//    APP_TEST_u32SubSchCounter = 1;
//  }
//  else
//  {
//    APP_TEST_u32SubSchCounter++;
//  }
  
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO0 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO1 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO2 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO3 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO4 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO5 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO6 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO7 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO8 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO9 , ECU_IO_OUT_COMMAND_TOGGLE);
//  ECU_IO_eOutputControl(ECU_IO_OUTPUT_DO10, ECU_IO_OUT_COMMAND_TOGGLE);
////  ECU_IO_eOutputControl(ECU_IO_OUTPUT_WDI , ECU_IO_OUT_COMMAND_TOGGLE);
////  ECU_IO_eOutputControl(ECU_IO_OUTPUT_WD_NEN , ECU_IO_OUT_COMMAND_OFF);
////  ECU_IO_eOutputControl(ECU_IO_OUTPUT_HOLD , ECU_IO_OUT_COMMAND_TOGGLE);
////  ECU_IO_eOutputControl(ECU_IO_OUTPUT_WP, ECU_IO_OUT_COMMAND_TOGGLE);
}



