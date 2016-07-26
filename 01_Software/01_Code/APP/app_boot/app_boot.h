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

File Name: app_boot.h
Author: Hany elShahawy 
E-mail: shany@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_BOOT_H
#define APP_BOOT_H

#include "ecu.h"

typedef ECU_MEM_strBlockMemory_t APP_BOOT_strBlockMemory_t;

typedef enum APP_BOOT_eStatusTemplate
{
  APP_BOOT_ST_INIT = 0,
  APP_BOOT_ST_DOWNLOAD = 1,
  APP_BOOT_ST_UPLOAD = 2,
  APP_BOOT_ST_APP_RUN = 3,
  APP_BOOT_ST_ERROR = 4,
} APP_BOOT_eStatus_t;


typedef enum APP_BOOT_eDownloadStatusTemplate
{
  APP_BOOT_DL_ST_INIT = 0,
  APP_BOOT_DL_ST_PAGE_RECEIVE = 1,
  APP_BOOT_DL_ST_PAGE_DOWNLOAD = 2,
  APP_BOOT_DL_ST_ERROR = 3,
} APP_BOOT_eDownloadStatus_t;


void APP_BOOT_vdInit(void);
void APP_BOOT_vdDeInit(void);
void APP_BOOT_vdMgr(void);

#endif /*APP_BOOT_H*/

