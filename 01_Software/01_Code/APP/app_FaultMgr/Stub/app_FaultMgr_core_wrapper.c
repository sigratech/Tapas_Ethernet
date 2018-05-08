

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include "app_FaultMgr_cfg.h"
#include "app_FaultMgr.h"
#include "stub.h"

#define ECU_MEM_INT_MODULE_ENABLE
#include "ecu_mem_cfg.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void app_FaultMgr_core_Outputs_wrapper(const real_T *ACP_Fault1,
			const real_T *ACP_Fault2,
			const real_T *ACP_Fault3,
			real_T *FLT_SystemErrorSeverity,
			real_T *ACP_Clear_Fault1,
			real_T *ACP_Clear_Fault2,
			real_T *ACP_Clear_Fault3)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/

RTE_Write_ACP_Fault1(ACP_Fault1[0]);
RTE_Write_ACP_Fault2(ACP_Fault2[0]);
RTE_Write_ACP_Fault3(ACP_Fault3[0]);

app_FaultMgr_fcn();

FLT_SystemErrorSeverity[0] = RTE_Read_FLT_SystemErrorSeverity();
ACP_Clear_Fault1[0] = RTE_Read_FLT_ACP_Fault1_Clear();
ACP_Clear_Fault2[0] = RTE_Read_FLT_ACP_Fault2_Clear();
ACP_Clear_Fault3[0] = RTE_Read_FLT_ACP_Fault3_Clear();
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
