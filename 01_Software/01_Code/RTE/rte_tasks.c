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


void APP_vdTask1ms(void);
void APP_vdTask10ms(void);
void APP_vdTask50ms(void);
void APP_vdTask100ms(void);

uint8_t APP_u8Counter = 0;

void APP_vdTask1ms(void)
{

}


void APP_vdTask10ms(void)
{
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

}


void APP_vdTask100ms(void)
{

}


