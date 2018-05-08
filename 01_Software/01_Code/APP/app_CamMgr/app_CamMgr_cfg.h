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

File Name: app_CamMgr_cfg.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_CAMMGR_CFG_H
#define APP_CAMMGR_CFG_H

#undef APP_CAMMGR_ENABLE

#define APP_CAMMGR_TASK_MS                             (10)

#define APP_CAM_OBJECTS_NUM_MAX                        (13)
#define APP_CAM_OBJECTS_ID0                            (0)
#define APP_CAM_OBJECTS_ID1                            (1)
#define APP_CAM_OBJECTS_ID2                            (2)
#define APP_CAM_OBJECTS_ID3                            (3)
#define APP_CAM_OBJECTS_ID4                            (4)
#define APP_CAM_OBJECTS_ID5                            (5)
#define APP_CAM_OBJECTS_ID6                            (6)
#define APP_CAM_OBJECTS_ID7                            (7)
#define APP_CAM_OBJECTS_ID8                            (8)
#define APP_CAM_OBJECTS_ID9                            (9)
#define APP_CAM_OBJECTS_ID10                           (10)
#define APP_CAM_OBJECTS_ID11                           (11)
#define APP_CAM_OBJECTS_ID12                           (12)
//#define APP_CAM_OBJECTS_ID13                           (13)
//#define APP_CAM_OBJECTS_ID14                           (14)


#define APP_CAM_STRICT_ZONE_DEPTH_M                     (30.0f)
#define APP_CAM_STRICT_ZONE_WIDTH_M                     (5.0f)

#endif /*APP_CAMMGR_CFG_H*/

