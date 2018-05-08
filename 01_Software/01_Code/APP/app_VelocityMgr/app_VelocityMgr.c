/*
 * ***************************************************************************
 * ***************************************************************************
 * (C) 2016 SIGRA Technologies GmbH  All rights reserved.
 *
 * All data and information contained in or disclosed by this document is
 * confidential and proprietary information of SIGRA Technologies GmbH and all
 * rights therein are expressly reserved.  By accepting this material the
 * recipient agrees that this material and the information contained therein
 * is held in confidence and in trust and will not be used, copied, reproduced
 * in whole or in part, nor its contents revealed in any manner to others
 * without the express written permission of SIGRA Technologies GmbH
 *
 * SIGRA Technologies GmbH
 * Agnes-Pockels-Bogen 1,
 * 80992, Munich,
 * Germany
 *
 * File Name: app_VelocityMgr.c
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Tue Apr 24 19:25:52 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#include "app_VelocityMgr.h"
#include "app_VelocityMgr_private.h"

/* Named constants for Chart: '<S1>/SpeedLimitManager' */
#define app_VelocityMgr_IN_GO          ((uint8_T)1U)
#define app_VelocityMgr_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define app_VelocityMgr_IN_STOP        ((uint8_T)2U)
#define app_VelocityMgr_IN_WAIT        ((uint8_T)3U)

/* user code (top of source file) */
#include "rte.h"

/* Block states (auto storage) */
DW_app_VelocityMgr_T app_VelocityMgr_DW;

/* Real-time model */
RT_MODEL_app_VelocityMgr_T app_VelocityMgr_M_;
RT_MODEL_app_VelocityMgr_T *const app_VelocityMgr_M = &app_VelocityMgr_M_;

/* Model step function for TID1 */
void app_VelocityMgr_fcn(void)         /* Sample time: [0.01s, 0.0s] */
{
  boolean_T guard1 = false;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_VelocityMgr_fcn_at_outport_1' incorporates:
   *  SubSystem: '<Root>/app_VelocityMgr'
   */
  /* Chart: '<S1>/SpeedLimitManager' incorporates:
   *  Constant: '<S1>/SpeedLimit_kmph'
   *  Inport: '<Root>/CAM_Go_Signal'
   */
  if (app_VelocityMgr_DW.temporalCounter_i1 < MAX_uint32_T) {
    app_VelocityMgr_DW.temporalCounter_i1++;
  }

  /* Gateway: app_VelocityMgr/SpeedLimitManager */
  /* During: app_VelocityMgr/SpeedLimitManager */
  if (app_VelocityMgr_DW.is_active_c3_app_VelocityMgr == 0U) {
    /* Entry: app_VelocityMgr/SpeedLimitManager */
    app_VelocityMgr_DW.is_active_c3_app_VelocityMgr = 1U;

    /* Entry Internal: app_VelocityMgr/SpeedLimitManager */
    /* Transition: '<S2>:2' */
    app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_GO;
  } else {
    guard1 = false;
    switch (app_VelocityMgr_DW.is_c3_app_VelocityMgr) {
     case app_VelocityMgr_IN_GO:
      /* During 'GO': '<S2>:1' */
      if (RTE_Read_CAM_Go_Signal() == 0.0) {
        /* Transition: '<S2>:5' */
        app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_STOP;
      } else {
        RTE_Write_VEL_SpeedLimit(app_VelocityMgr_P.SpeedLimit_kmph_Value);
      }
      break;

     case app_VelocityMgr_IN_STOP:
      /* During 'STOP': '<S2>:3' */
      if (RTE_Read_CAM_Go_Signal() == 1.0) {
        /* Transition: '<S2>:6' */
        app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_WAIT;
        app_VelocityMgr_DW.temporalCounter_i1 = 0U;
      } else {
        RTE_Write_VEL_SpeedLimit(0.0);
      }
      break;

     default:
      /* During 'WAIT': '<S2>:4' */
      if (app_VelocityMgr_DW.temporalCounter_i1 >= (uint32_T)ceil
          (app_VelocityMgr_P.WaitTime_sec_Value / 0.01 - 1.0E-10)) {
        /* Transition: '<S2>:8' */
        if (RTE_Read_CAM_Go_Signal() == 1.0) {
          /* Transition: '<S2>:9' */
          app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_GO;
        } else if (RTE_Read_CAM_Go_Signal() == 0.0) {
          /* Transition: '<S2>:10' */
          app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_STOP;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      RTE_Write_VEL_SpeedLimit(0.0);
    }
  }

  /* End of Chart: '<S1>/SpeedLimitManager' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_VelocityMgr_fcn_at_outport_1' */
}

/* Model initialize function */
void app_VelocityMgr_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(app_VelocityMgr_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&app_VelocityMgr_DW, 0,
                sizeof(DW_app_VelocityMgr_T));

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_VelocityMgr_fcn_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/app_VelocityMgr'
   */
  /* SystemInitialize for Chart: '<S1>/SpeedLimitManager' */
  app_VelocityMgr_DW.temporalCounter_i1 = 0U;
  app_VelocityMgr_DW.is_active_c3_app_VelocityMgr = 0U;
  app_VelocityMgr_DW.is_c3_app_VelocityMgr = app_VelocityMgr_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_VelocityMgr_fcn_at_outport_1' */
}

/* Model terminate function */
void app_VelocityMgr_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
