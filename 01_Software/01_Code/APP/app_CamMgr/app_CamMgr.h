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

File Name: app_CamMgr.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/
#ifndef APP_CAMMGR_H
#define APP_CAMMGR_H

#include "lib_types.h"
#include "rte.h"

typedef enum APP_CAM_eObjTypeTemplate
{
  APP_CAM_OBJ_TYPE_VEHICLE = 0,
  APP_CAM_OBJ_TYPE_TRUCK = 1,
  APP_CAM_OBJ_TYPE_BIKE = 2,
  APP_CAM_OBJ_TYPE_PED = 3,
  APP_CAM_OBJ_TYPE_BICYCLE = 4,
} APP_CAM_eObjType_t;

typedef enum APP_CAM_eObjValidityTemplate
{
  APP_CAM_OBJ_NOT_VALID = 0,
  APP_CAM_OBJ_VALID = 1,
} APP_CAM_eObjValidity_t;

typedef struct APP_CAM_strMovingObjectTemplate
{
  /*Local ID*/
  uint8_t u8LocalId;
  /*Cam Object Id*/
  uint8_t u8CamObjId;
  /*Com Id - Cam Object Id*/
  uint16_t u16ComId_CamObjId;
  /*Object Type*/
  APP_CAM_eObjType_t eObjType;
  /*Com Id - Object Type*/
  uint16_t u16ComId_ObjType;
  /*Position in SIGRA X*/
  float fltPosX;
  /*Com Id - PosX*/
  uint16_t u16ComId_PosX;
  /*Position in SIGRA Y*/
  float fltPosY;
  /*Com Id - PosY*/
  uint16_t u16ComId_PosY;
  /*Velocity in Y*/
  float fltVelY;
  /*Com Id - VelY*/
  uint16_t u16ComId_VelY;
  /*Validity*/
  APP_CAM_eObjValidity_t eObjValidity;
} APP_CAM_strMovingObject_t;


void app_CamMgr_initialize(void);
void app_CamMgr_terminate(void);
void app_CamMgr_fcn(void);

#endif /*APP_CAMMGR_H*/
