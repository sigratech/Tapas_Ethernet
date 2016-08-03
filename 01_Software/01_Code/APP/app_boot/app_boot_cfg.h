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

File Name: app_boot_cfg.h
Author: Hany elShahawy 
E-mail: shany@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_BOOT_CFG_H
#define APP_BOOT_CFG_H

#define APP_BOOT_ENABLE

#define APP_BOOT_TASK_MS                                             (1)

#define APP_BOOT_APPLICATION_ADDRESS                                 (0x100000)

#define APP_BOOT_PAGE_SIZE                                           (256)

#define APP_BOOT_HEARTBEAT_HALF_PERIOD_MS                            (100)
#define APP_BOOT_HEARTBEAT_STATIC_PERIOD_MS                          (500)
#define APP_BOOT_HEARTBEAT_FAST_COUNT                                (3)

#endif /*APP_BOOT_CFG_H*/

