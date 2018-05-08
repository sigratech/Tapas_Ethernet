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
 * File Name: app_HmiMgr.c
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Fri Apr 20 14:07:47 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#include "app_HmiMgr.h"
#include "app_HmiMgr_private.h"

/* Named constants for Chart: '<S1>/Heartbeat' */
#define app_HmiMgr_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define app_HmiMgr_IN_OFF              ((uint8_T)1U)
#define app_HmiMgr_IN_ON               ((uint8_T)2U)

/* user code (top of source file) */
#include "rte.h"

/* Block signals (auto storage) */
B_app_HmiMgr_T app_HmiMgr_B;

/* Block states (auto storage) */
DW_app_HmiMgr_T app_HmiMgr_DW;

/* Real-time model */
RT_MODEL_app_HmiMgr_T app_HmiMgr_M_;
RT_MODEL_app_HmiMgr_T *const app_HmiMgr_M = &app_HmiMgr_M_;

/* Output and update for atomic system: '<S1>/IO_WriteDigitalOutput' */
void app_HmiMgr_IO_WriteDigitalOutput(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/IO_WriteDigitalOutput' */

  /* S-Function Block: <S3>/TAPAS_IO_WriteDigitalOutput */
  /* Insert Comment Here */

  /*TAPAS: User Defined Code Starts Here */
  if ((uint8_T)app_HmiMgr_B.HeartbeatLed != (uint8_T)0) {
    RTE_Service_IO_eOutputControl((uint8_T)
      (app_HmiMgr_P.IO_WriteDigitalOutput_PARAM_ID-1) , ECU_IO_OUT_COMMAND_ON);
  } else {
    RTE_Service_IO_eOutputControl((uint8_T)
      (app_HmiMgr_P.IO_WriteDigitalOutput_PARAM_ID-1) , ECU_IO_OUT_COMMAND_OFF);
  }

  /*TAPAS: User Defined Code Ends Here */

  /* End of Outputs for SubSystem: '<S1>/IO_WriteDigitalOutput' */
}

/* Model step function for TID1 */
void app_HmiMgr_fcn(void)              /* Sample time: [0.1s, 0.0s] */
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_HmiMgr_fcn_at_outport_1' incorporates:
   *  SubSystem: '<Root>/app_HmiMgr'
   */
  /* Inport: '<S1>/TEST_TO_HMI_1' incorporates:
   *  Inport: '<Root>/TEST_TO_HMI_1'
   */
  RTE_Write_HMI_Output1(RTE_Read_TEST_TO_HMI_1());

  /* Chart: '<S1>/Heartbeat' */
  if (app_HmiMgr_DW.temporalCounter_i1 < 7U) {
    app_HmiMgr_DW.temporalCounter_i1++;
  }

  /* Gateway: app_HmiMgr/Heartbeat */
  /* During: app_HmiMgr/Heartbeat */
  if (app_HmiMgr_DW.is_active_c3_app_HmiMgr == 0U) {
    /* Entry: app_HmiMgr/Heartbeat */
    app_HmiMgr_DW.is_active_c3_app_HmiMgr = 1U;

    /* Entry Internal: app_HmiMgr/Heartbeat */
    /* Transition: '<S2>:5' */
    app_HmiMgr_DW.is_c3_app_HmiMgr = app_HmiMgr_IN_OFF;
    app_HmiMgr_DW.temporalCounter_i1 = 0U;
  } else if (app_HmiMgr_DW.is_c3_app_HmiMgr == app_HmiMgr_IN_OFF) {
    /* During 'OFF': '<S2>:1' */
    if (app_HmiMgr_DW.temporalCounter_i1 >= 5U) {
      /* Transition: '<S2>:6' */
      app_HmiMgr_DW.is_c3_app_HmiMgr = app_HmiMgr_IN_ON;
      app_HmiMgr_DW.temporalCounter_i1 = 0U;
    } else {
      app_HmiMgr_B.HeartbeatLed = 0.0;
    }
  } else {
    /* During 'ON': '<S2>:4' */
    if (app_HmiMgr_DW.temporalCounter_i1 >= 5U) {
      /* Transition: '<S2>:7' */
      app_HmiMgr_DW.is_c3_app_HmiMgr = app_HmiMgr_IN_OFF;
      app_HmiMgr_DW.temporalCounter_i1 = 0U;
    } else {
      app_HmiMgr_B.HeartbeatLed = 1.0;
    }
  }

  /* End of Chart: '<S1>/Heartbeat' */

  /* Outputs for Atomic SubSystem: '<S1>/IO_WriteDigitalOutput' */
  app_HmiMgr_IO_WriteDigitalOutput();

  /* End of Outputs for SubSystem: '<S1>/IO_WriteDigitalOutput' */

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_HmiMgr_fcn_at_outport_1' */
}

/* Model initialize function */
void app_HmiMgr_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(app_HmiMgr_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &app_HmiMgr_B), 0,
                sizeof(B_app_HmiMgr_T));

  /* states (dwork) */
  (void) memset((void *)&app_HmiMgr_DW, 0,
                sizeof(DW_app_HmiMgr_T));

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_HmiMgr_fcn_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/app_HmiMgr'
   */
  /* SystemInitialize for Chart: '<S1>/Heartbeat' */
  app_HmiMgr_DW.temporalCounter_i1 = 0U;
  app_HmiMgr_DW.is_active_c3_app_HmiMgr = 0U;
  app_HmiMgr_DW.is_c3_app_HmiMgr = app_HmiMgr_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<S1>/HMI_Output1' */
  RTE_Write_HMI_Output1(app_HmiMgr_P.HMI_Output1_Y0);

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_HmiMgr_fcn_at_outport_1' */
}

/* Model terminate function */
void app_HmiMgr_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
