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
 * File Name: app_HmiMgr.h
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Fri Apr 20 14:07:47 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#ifndef RTW_HEADER_app_HmiMgr_h_
#define RTW_HEADER_app_HmiMgr_h_
#include <stddef.h>
#include <string.h>
#ifndef app_HmiMgr_COMMON_INCLUDES_
# define app_HmiMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* app_HmiMgr_COMMON_INCLUDES_ */

#include "app_HmiMgr_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T HeartbeatLed;                 /* '<S1>/Heartbeat' */
} B_app_HmiMgr_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_app_HmiMgr;     /* '<S1>/Heartbeat' */
  uint8_T is_c3_app_HmiMgr;            /* '<S1>/Heartbeat' */
  uint8_T temporalCounter_i1;          /* '<S1>/Heartbeat' */
} DW_app_HmiMgr_T;

/* Parameters (auto storage) */
struct P_app_HmiMgr_T_ {
  real_T IO_WriteDigitalOutput_PARAM_ID;/* Mask Parameter: IO_WriteDigitalOutput_PARAM_ID
                                         * Referenced by: '<S3>/Constant'
                                         */
  real_T HMI_Output1_Y0;               /* Computed Parameter: HMI_Output1_Y0
                                        * Referenced by: '<S1>/HMI_Output1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_app_HmiMgr_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_app_HmiMgr_T app_HmiMgr_P;

/* Block signals (auto storage) */
extern B_app_HmiMgr_T app_HmiMgr_B;

/* Block states (auto storage) */
extern DW_app_HmiMgr_T app_HmiMgr_DW;

/* Model entry point functions */
extern void app_HmiMgr_initialize(void);
extern void app_HmiMgr_terminate(void);

/* Exported entry point functions */
extern void app_HmiMgr_fcn(void);

/* Exported entry point functions */
extern void app_HmiMgr_fcn(void);

/* Real-time Model object */
extern RT_MODEL_app_HmiMgr_T *const app_HmiMgr_M;

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
 * '<Root>' : 'app_HmiMgr'
 * '<S1>'   : 'app_HmiMgr/app_HmiMgr'
 * '<S2>'   : 'app_HmiMgr/app_HmiMgr/Heartbeat'
 * '<S3>'   : 'app_HmiMgr/app_HmiMgr/IO_WriteDigitalOutput'
 */
#endif                                 /* RTW_HEADER_app_HmiMgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
