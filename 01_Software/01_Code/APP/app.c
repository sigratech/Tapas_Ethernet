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

File Name: app.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app.h"
#include "uc_emac.h"

void rec_emac(uint8_t *u8data, uint16_t u16length);

void rec_emac(uint8_t *u8data, uint16_t u16length)
{
  uint8_t u8key = u8data[100];
}

void APP_vdInit(void)
{
  
  uint8_t u8Data[200] = {5}; 
  UC_EMAC_eSendBytes(&u8Data[0],200);
  UC_EMAC_eRegisterDataRxClbk((UC_EMAC_p2fDataReceivedClbk_t)rec_emac,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA);
//  app_test_gen_initialize();
  //APP_DIAG_vdInit();
}

void APP_vdDeInit(void)
{
//  app_test_gen_terminate();
}
