///*
//***************************************************************************
//***************************************************************************
//(C) 2016 SIGRA Technologies GmbH  All rights reserved.
//
//All data and information contained in or disclosed by this document is
//confidential and proprietary information of SIGRA Technologies GmbH and all
//rights therein are expressly reserved.  By accepting this material the
//recipient agrees that this material and the information contained therein
//is held in confidence and in trust and will not be used, copied, reproduced
//in whole or in part, nor its contents revealed in any manner to others
//without the express written permission of SIGRA Technologies GmbH
//
//SIGRA Technologies GmbH
//Agnes-Pockels-Bogen 1,
//80992, Munich,
//Germany
//
//File Name: app_CamMgr_cfg.c
//Author: Karim Mansour 
//E-mail: karim@sigratech.de 
//***************************************************************************
//***************************************************************************
//*/
//
//#include "rte.h"
//#include "app_CamMgr.h"
//#include "app_CamMgr_cfg.h"
//
//APP_CAM_strMovingObject_t APP_CAM_astrMovingObject[APP_CAM_OBJECTS_NUM_MAX] = 
//{
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID0,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A0,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A0,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A0,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A0,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A0,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID1,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A1,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A1,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A1,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A1,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A1,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID2,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A2,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A2,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A2,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A2,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A2,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID3,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A3,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A3,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A3,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A3,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A3,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID4,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A4,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A4,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A4,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A4,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A4,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID5,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A5,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A5,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A5,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A5,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A5,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID6,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A6,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A6,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A6,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A6,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A6,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID7,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A7,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A7,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A7,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A7,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A7,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID8,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A8,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A8,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A8,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A8,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A8,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID9,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A9,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A9,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A9,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A9,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A9,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID10,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A10,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A10,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A10,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A10,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A10,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID11,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A11,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A11,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A11,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A11,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A11,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//  {
//    /*Local ID*/
//    APP_CAM_OBJECTS_ID12,
//    /*Cam Object Id*/
//    0,
//    /*Com Id - Cam Object Id*/
//    APP_RX_OBSTACLEID_A12,
//    /*Object Type*/
//    APP_CAM_OBJ_TYPE_VEHICLE,
//    /*Com Id - Object Type*/
//    APP_RX_OBSTACLETYPE_A12,
//    /*Position in SIGRA X*/
//    0.0f,
//    /*Com Id - PosX*/
//    APP_RX_OBSTACLEPOSY_A12,
//    /*Position in SIGRA Y*/
//    0.0f,
//    /*Com Id - PosY*/
//    APP_RX_OBSTACLEPOSX_A12,
//    /*Velocity in Y*/
//    0.0f,
//    /*Com Id - VelY*/
//    APP_RX_OBSTACLEVELX_A12,
//    /*Validity*/
//    APP_CAM_OBJ_NOT_VALID,
//  },
//};
