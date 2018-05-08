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
 * File Name: app_SteeringMgr.c
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Fri Apr 20 14:13:35 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#include "app_SteeringMgr.h"
#include "app_SteeringMgr_private.h"

/* user code (top of source file) */
#include "rte.h"

/* Real-time model */
RT_MODEL_app_SteeringMgr_T app_SteeringMgr_M_;
RT_MODEL_app_SteeringMgr_T *const app_SteeringMgr_M = &app_SteeringMgr_M_;

/* Model step function for TID1 */
void app_SteeringMgr_fcn(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_SteeringMgr_fcn_at_outport_1' incorporates:
   *  SubSystem: '<Root>/app_SteeringMgr'
   */
  /* Inport: '<S1>/TEST_TO_STR_1' incorporates:
   *  Inport: '<Root>/TEST_TO_STR_1'
   */
  RTE_Write_STR_Output1(RTE_Read_TEST_TO_STR_1());

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_SteeringMgr_fcn_at_outport_1' */
}

/* Model initialize function */
void app_SteeringMgr_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(app_SteeringMgr_M, (NULL));

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_SteeringMgr_fcn_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/app_SteeringMgr'
   */
  /* SystemInitialize for Outport: '<S1>/STR_Output1' */
  RTE_Write_STR_Output1(app_SteeringMgr_P.STR_Output1_Y0);

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_SteeringMgr_fcn_at_outport_1' */
}

/* Model terminate function */
void app_SteeringMgr_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
