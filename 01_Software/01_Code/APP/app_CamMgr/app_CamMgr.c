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

File Name: app_CamMgr.c
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/



#include "app_CamMgr_cfg.h"
#include "app_CamMgr.h"
#include "app.h"
#include "rte.h"

#ifdef APP_CAMMGR_ENABLE


/********************************************************************************************/
/*********************************** INTERNAL MACROS ****************************************/
/********************************************************************************************/

/********************************************************************************************/
/********************* INTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/


/********************************************************************************************/
/********************* EXTERNAL GLOBAL VARIABLES DECLARATION ********************************/
/********************************************************************************************/
extern APP_CAM_strMovingObject_t APP_CAM_astrMovingObject[APP_CAM_OBJECTS_NUM_MAX];

/********************************************************************************************/
/******************************* CALLBLACKS DECLARATION *************************************/
/********************************************************************************************/



/********************************************************************************************/
/****************************** LOCAL FUNCTIONS DECLARATION *********************************/
/********************************************************************************************/

/********************************************************************************************/
/**************************** GLOBAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/

void app_CamMgr_initialize(void)
{


}

void app_CamMgr_terminate(void)
{
  

}


void app_CamMgr_fcn(void)
{
  uint8_t u8Id;
  STATUS_t eStatus;
  float fltCastVariable;
  uint8_t u8GoSignal;
  
  /* Collect Data From the Camera*/
  for(u8Id = (uint8_t)0; u8Id < APP_CAM_OBJECTS_NUM_MAX; u8Id++)
  {
    eStatus =  RTE_Service_COM_vdReadSignal(APP_CAM_astrMovingObject[u8Id].u16ComId_CamObjId, &fltCastVariable);
    
    if(eStatus == STATUS_OK)
    {
      APP_CAM_astrMovingObject[u8Id].eObjValidity = APP_CAM_OBJ_VALID;
      APP_CAM_astrMovingObject[u8Id].u8CamObjId = (uint8_t)fltCastVariable;
      RTE_Service_COM_vdReadSignal(APP_CAM_astrMovingObject[u8Id].u16ComId_ObjType, &fltCastVariable);
      APP_CAM_astrMovingObject[u8Id].eObjType = (APP_CAM_eObjType_t)fltCastVariable;
      RTE_Service_COM_vdReadSignal(APP_CAM_astrMovingObject[u8Id].u16ComId_PosX, &fltCastVariable);
      APP_CAM_astrMovingObject[u8Id].fltPosX = fltCastVariable;
      RTE_Service_COM_vdReadSignal(APP_CAM_astrMovingObject[u8Id].u16ComId_PosY, &fltCastVariable);
      APP_CAM_astrMovingObject[u8Id].fltPosY = fltCastVariable;
      RTE_Service_COM_vdReadSignal(APP_CAM_astrMovingObject[u8Id].u16ComId_VelY, &fltCastVariable);
      APP_CAM_astrMovingObject[u8Id].fltVelY = fltCastVariable;
    }
    else
    {
      APP_CAM_astrMovingObject[u8Id].eObjValidity = APP_CAM_OBJ_NOT_VALID;
    }
  }
  
  /*Checking For Obstacles*/
  u8GoSignal = TAPAS_TRUE;
  for(u8Id = (uint8_t)0; u8Id < APP_CAM_OBJECTS_NUM_MAX; u8Id++)
  {
    if(APP_CAM_astrMovingObject[u8Id].eObjValidity == APP_CAM_OBJ_VALID)
    {
      if(APP_CAM_astrMovingObject[u8Id].fltPosY <= APP_CAM_STRICT_ZONE_DEPTH_M)
      {
        if((APP_CAM_astrMovingObject[u8Id].fltPosX <= (APP_CAM_STRICT_ZONE_WIDTH_M/2.0f)) && 
           (APP_CAM_astrMovingObject[u8Id].fltPosX >= ((APP_CAM_STRICT_ZONE_WIDTH_M/2.0f)*(-1.0)))
          )
        {
          u8GoSignal = TAPAS_FALSE;
          break;
        }
      }
    }
  }
  
  RTE_Write_CAM_Go_Signal((float)u8GoSignal);
}






/********************************************************************************************/
/***************************** LOCAL FUNCTIONS IMPLEMENTATION *******************************/
/********************************************************************************************/



#endif /*APP_CAMMGR_ENABLE*/
