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
 * File Name: app_ComMgr.c
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Tue Apr 24 19:26:41 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#include "app_ComMgr.h"
#include "app_ComMgr_private.h"

/* user code (top of source file) */
#include "rte.h"

/* Block signals (auto storage) */
B_app_ComMgr_T app_ComMgr_B;

/* Real-time model */
RT_MODEL_app_ComMgr_T app_ComMgr_M_;
RT_MODEL_app_ComMgr_T *const app_ComMgr_M = &app_ComMgr_M_;

/* Output and update for atomic system: '<S1>/COM_ReadSignal1' */
void app_ComMgr_COM_ReadSignal(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/COM_ReadSignal1' */

  /* S-Function Block: <S2>/TAPAS_COM_ReadSignal */
  /* Insert Comment Here */
  STATUS_t eStatus;
  float fltValue;
  eStatus = RTE_Service_COM_vdReadSignal((uint8_t)
    (app_ComMgr_P.COM_ReadSignal1_PARAM_ID-1), &fltValue);
  app_ComMgr_B.TAPAS_COM_ReadSignal_o1 = fltValue;
  if (eStatus == STATUS_OK) {
    app_ComMgr_B.TAPAS_COM_ReadSignal_o2 = 1;
  } else {
    app_ComMgr_B.TAPAS_COM_ReadSignal_o2 = 0;
  }

  /* End of Outputs for SubSystem: '<S1>/COM_ReadSignal1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  app_ComMgr_B.DataTypeConversion = app_ComMgr_B.TAPAS_COM_ReadSignal_o1;
}

/* Output and update for atomic system: '<S1>/COM_WriteSignal1' */
void app_ComMgr_COM_WriteSignal(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/COM_WriteSignal1' */

  /* S-Function Block: <S3>/TAPAS_COM_WriteSignal */
  /* Insert Comment Here */
  RTE_Service_COM_vdWriteSignal((uint8_t)(app_ComMgr_P.COM_WriteSignal1_PARAM_ID
    -1), app_ComMgr_B.DataTypeConversion);

  /* End of Outputs for SubSystem: '<S1>/COM_WriteSignal1' */
}

/* Output and update for atomic system: '<S1>/COM_WriteSignal2' */
void app_ComMgr_COM_WriteSignal2(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/COM_WriteSignal2' */

  /* S-Function Block: <S4>/TAPAS_COM_WriteSignal */
  /* Insert Comment Here */
  RTE_Service_COM_vdWriteSignal((uint8_t)(app_ComMgr_P.COM_WriteSignal2_PARAM_ID
    -1), RTE_Read_VEL_SpeedLimit());

  /* End of Outputs for SubSystem: '<S1>/COM_WriteSignal2' */
}

/* Model step function for TID1 */
void app_ComMgr_fcn(void)              /* Sample time: [0.1s, 0.0s] */
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_ComMgr_fcn_at_outport_1' incorporates:
   *  SubSystem: '<Root>/app_ComMgr'
   */
  /* Inport: '<S1>/TEST_TO_COM_1' incorporates:
   *  Inport: '<Root>/TEST_TO_COM_1'
   */
  RTE_Write_COM_Output1(RTE_Read_TEST_TO_COM_1());

  /* Outputs for Atomic SubSystem: '<S1>/COM_WriteSignal2' */
  app_ComMgr_COM_WriteSignal2();

  /* End of Outputs for SubSystem: '<S1>/COM_WriteSignal2' */

  /* Outputs for Atomic SubSystem: '<S1>/COM_ReadSignal1' */
  app_ComMgr_COM_ReadSignal();

  /* End of Outputs for SubSystem: '<S1>/COM_ReadSignal1' */

  /* Outputs for Atomic SubSystem: '<S1>/COM_WriteSignal1' */
  app_ComMgr_COM_WriteSignal();

  /* End of Outputs for SubSystem: '<S1>/COM_WriteSignal1' */

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_ComMgr_fcn_at_outport_1' */
}

/* Model initialize function */
void app_ComMgr_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(app_ComMgr_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &app_ComMgr_B), 0,
                sizeof(B_app_ComMgr_T));

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_ComMgr_fcn_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/app_ComMgr'
   */
  /* SystemInitialize for Outport: '<S1>/COM_Output1' */
  RTE_Write_COM_Output1(app_ComMgr_P.COM_Output1_Y0);

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_app_ComMgr_fcn_at_outport_1' */
}

/* Model terminate function */
void app_ComMgr_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
