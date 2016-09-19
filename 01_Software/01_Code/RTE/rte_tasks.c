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

File Name: rte_tasks.c
Author: TAPAS Generated 
E-mail: info@sigratech.de  
***************************************************************************
***************************************************************************
*/

#include "rte_app.h"
#include "lib_data.h"
#include "lib_delay.h"

void APP_vdTask1ms(void);
void APP_vdTask10ms(void);
void APP_vdTask50ms(void);
void APP_vdTask100ms(void);

uint8_t APP_u8Counter = 0;

void APP_vdTask1ms(void)
{
  /* app_FaultMgr_fcn Package */
//  app_FaultMgr_fcn();
}


void APP_vdTask10ms(void)
{
  /* app_AccelMgr_fcn Package */
//  app_AccelMgr_fcn();
  
  if(APP_u8Counter == 10)
  {
    APP_u8Counter = 0;
    ECU_IO_eOutputControl(ECU_IO_DOUT_HEARTBEAT_LED, ECU_IO_OUT_COMMAND_TOGGLE);    
  }
  else
  {
    APP_u8Counter++;
    if(APP_u8Counter == 11)
    {
      APP_u8Counter = 0;
    }
  }  
}


void APP_vdTask50ms(void)
{
  /* app_DrivingMgr_fcn Package */
//  app_DrivingMgr_fcn();
//  /* app_McuMgr_fcn Package */
//  app_McuMgr_fcn();
}


void APP_vdTask100ms(void)
{
//  /* app_AirConMgr_fcn Package */
//  app_AirConMgr_fcn();
//  /* app_BatteryMgr_fcn Package */
//  app_BatteryMgr_fcn();
//  /* app_BrakeMgr_fcn Package */
//  app_BrakeMgr_fcn();
//  /* app_ChargingMgr_fcn Package */
//  app_ChargingMgr_fcn();
//  /* app_ComMgr_fcn Package */
//  app_ComMgr_fcn();
//  /* app_CoolingMgr_fcn Package */
//  app_CoolingMgr_fcn();
//  /* app_DashMgr_fcn Package */
//  app_DashMgr_fcn();
//  /* app_DcDcMgr_fcn Package */
//  app_DcDcMgr_fcn();
//  /* app_GearMgr_fcn Package */
//  app_GearMgr_fcn();
//  /* app_LightMgr_fcn Package */
//  app_LightMgr_fcn();
//  /* app_PowerSteeringMgr_fcn Package */
//  app_PowerSteeringMgr_fcn();
//  /* app_StartKeyMgr_fcn Package */
//  app_StartKeyMgr_fcn();
//  /* app_SysMgr_fcn Package */
//  app_SysMgr_fcn();
//  /* app_test_gen_fcn Package */
//  app_test_gen_fcn();
}


