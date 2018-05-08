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
 * File Name: app_VelocityMgr.h
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Tue Apr 24 19:25:52 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#ifndef RTW_HEADER_app_VelocityMgr_h_
#define RTW_HEADER_app_VelocityMgr_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef app_VelocityMgr_COMMON_INCLUDES_
# define app_VelocityMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* app_VelocityMgr_COMMON_INCLUDES_ */

#include "app_VelocityMgr_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S1>/SpeedLimitManager' */
  uint8_T is_active_c3_app_VelocityMgr;/* '<S1>/SpeedLimitManager' */
  uint8_T is_c3_app_VelocityMgr;       /* '<S1>/SpeedLimitManager' */
} DW_app_VelocityMgr_T;

/* Parameters (auto storage) */
struct P_app_VelocityMgr_T_ {
  real_T WaitTime_sec_Value;           /* Expression: 1
                                        * Referenced by: '<S1>/WaitTime_sec'
                                        */
  real_T SpeedLimit_kmph_Value;        /* Expression: 30
                                        * Referenced by: '<S1>/SpeedLimit_kmph'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_app_VelocityMgr_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_app_VelocityMgr_T app_VelocityMgr_P;

/* Block states (auto storage) */
extern DW_app_VelocityMgr_T app_VelocityMgr_DW;

/* Model entry point functions */
extern void app_VelocityMgr_initialize(void);
extern void app_VelocityMgr_terminate(void);

/* Exported entry point functions */
extern void app_VelocityMgr_fcn(void);

/* Exported entry point functions */
extern void app_VelocityMgr_fcn(void);

/* Real-time Model object */
extern RT_MODEL_app_VelocityMgr_T *const app_VelocityMgr_M;

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
 * '<Root>' : 'app_VelocityMgr'
 * '<S1>'   : 'app_VelocityMgr/app_VelocityMgr'
 * '<S2>'   : 'app_VelocityMgr/app_VelocityMgr/SpeedLimitManager'
 */
#endif                                 /* RTW_HEADER_app_VelocityMgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
