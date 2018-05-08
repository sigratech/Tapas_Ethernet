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

File Name: app_FaultMgr_cfg.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#include "app_FaultMgr_cfg.h"
#include "app_FaultMgr.h"


APP_FLT_strDtc_t FLT_astrDtc[APP_FLT_DTC_NUM] = 
{
  {
    /* DTC ID 0*/
    APP_FLT_DTC_MAIN_FAULT,
    /* DTC Severity*/
    APP_FLT_DTC_SEV_FAULT_L1,
    /*Reset Delta Time*/
    1000,
    /*Delta Time Counter*/
    TAPAS_DEFAULT,
    /*Error Count Limit*/
    3,
    /*Error Flag*/
    TAPAS_FALSE,
    /*Error Count*/
    TAPAS_DEFAULT,
    /*Pointer to the RTE Read Error Set Signal*/
    RTE_Read_MAIN_Fault,
    /*Pointer to the RTE Write Error Clear Signal*/
    RTE_Write_FLT_CLR_MAIN_Fault,
    /*Decided severity for the DTC*/
    APP_FLT_DTC_SEV_NO_ERROR,
    /*Memory Id*/
    ECU_MEM_INT_DTC_1,
  },
};

