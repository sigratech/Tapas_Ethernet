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
 * File Name: app_PosMgr.h
 * Author: TAPAS/Matlab/Simulink/Embedded Coder Generated
 * TAPAS Generation Date: Sun Apr 08 12:13:14 2018
 * ***************************************************************************
 * ***************************************************************************
 */

#ifndef RTW_HEADER_app_PosMgr_h_
#define RTW_HEADER_app_PosMgr_h_
#include <stddef.h>
#ifndef app_PosMgr_COMMON_INCLUDES_
# define app_PosMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* app_PosMgr_COMMON_INCLUDES_ */

#include "app_PosMgr_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_app_PosMgr_T_ {
  real_T POS_Output1_Y0;               /* Computed Parameter: POS_Output1_Y0
                                        * Referenced by: '<S1>/POS_Output1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_app_PosMgr_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_app_PosMgr_T app_PosMgr_P;

/* Model entry point functions */
extern void app_PosMgr_initialize(void);
extern void app_PosMgr_terminate(void);

/* Exported entry point functions */
extern void app_PosMgr_fcn(void);

/* Exported entry point functions */
extern void app_PosMgr_fcn(void);

/* Real-time Model object */
extern RT_MODEL_app_PosMgr_T *const app_PosMgr_M;

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
 * '<Root>' : 'app_PosMgr'
 * '<S1>'   : 'app_PosMgr/app_PosMgr'
 */
#endif                                 /* RTW_HEADER_app_PosMgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
