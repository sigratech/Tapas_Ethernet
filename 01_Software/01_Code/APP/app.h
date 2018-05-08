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

File Name: app.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_H
#define APP_H

#define APPLICATION_SOFTWARE


#include "rte_app.h"
#include "app_diag_cfg.h"
#include "app_diag.h"
#include "app_diag_gf.h"
#include "app_FaultMgr_cfg.h"
#include "app_FaultMgr.h"
#include "app_CamMgr_cfg.h"
#include "app_CamMgr.h"

void APP_vdInit(void);
void APP_vdDeInit(void);

#endif /*APP_H*/

