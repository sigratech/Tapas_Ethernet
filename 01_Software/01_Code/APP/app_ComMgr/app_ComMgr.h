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
 * File Name: app_ComMgr.h
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Tue Apr 24 19:26:41 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#ifndef RTW_HEADER_app_ComMgr_h_
#define RTW_HEADER_app_ComMgr_h_
#include <stddef.h>
#include <string.h>
#ifndef app_ComMgr_COMMON_INCLUDES_
# define app_ComMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* app_ComMgr_COMMON_INCLUDES_ */

#include "app_ComMgr_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TAPAS_COM_ReadSignal_o1;      /* '<S2>/TAPAS_COM_ReadSignal' */
  real_T TAPAS_COM_ReadSignal_o2;      /* '<S2>/TAPAS_COM_ReadSignal' */
  real_T DataTypeConversion;           /* '<S2>/Data Type Conversion' */
} B_app_ComMgr_T;

/* Parameters (auto storage) */
struct P_app_ComMgr_T_ {
  real_T COM_ReadSignal1_PARAM_ID;     /* Mask Parameter: COM_ReadSignal1_PARAM_ID
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T COM_WriteSignal1_PARAM_ID;    /* Mask Parameter: COM_WriteSignal1_PARAM_ID
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T COM_WriteSignal2_PARAM_ID;    /* Mask Parameter: COM_WriteSignal2_PARAM_ID
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T COM_Output1_Y0;               /* Computed Parameter: COM_Output1_Y0
                                        * Referenced by: '<S1>/COM_Output1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_app_ComMgr_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_app_ComMgr_T app_ComMgr_P;

/* Block signals (auto storage) */
extern B_app_ComMgr_T app_ComMgr_B;

/* Model entry point functions */
extern void app_ComMgr_initialize(void);
extern void app_ComMgr_terminate(void);

/* Exported entry point functions */
extern void app_ComMgr_fcn(void);

/* Exported entry point functions */
extern void app_ComMgr_fcn(void);

/* Real-time Model object */
extern RT_MODEL_app_ComMgr_T *const app_ComMgr_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'app_ComMgr'
 * '<S1>'   : 'app_ComMgr/app_ComMgr'
 * '<S2>'   : 'app_ComMgr/app_ComMgr/COM_ReadSignal1'
 * '<S3>'   : 'app_ComMgr/app_ComMgr/COM_WriteSignal1'
 * '<S4>'   : 'app_ComMgr/app_ComMgr/COM_WriteSignal2'
 */
#endif                                 /* RTW_HEADER_app_ComMgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
