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

File Name: rte.c
Author: TAPAS Generated 
E-mail: info@sigratech.de  
***************************************************************************
***************************************************************************
*/

#include "lib_types.h"
#include "rte.h"
#include "rte_app.h"


/* RTE Sender Receiver Bus Definition */

RTE_strData_t RTE_astrData[RTE_DATA_NUM] =
{
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_COMBINEDFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TST_PEDALPOSITION2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TST_PEDALPOSITION1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACP_PEDALPOSITION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TST_MPV_NO_FAN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_WARNING_ACC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_FAULT_ACC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_ACC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_SOC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_GER_GEARSTATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_HEATER_ENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_AIRCON_ENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_FAULT_AIRCON,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_BATSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_WARNING_BAT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_FAULT_BAT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_BAT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_TOTALVOL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_BATFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_BMS_VCU_SOC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_BATTERYDISCHARGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_BATTERYOFF,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_BATTERYCHARGING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_INTERNFAULTS1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_INTERNFAULTS2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BMS_ALLOW2CHARGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BMS_HV_VOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_VCU_DVD_SOCLOW,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_BRK,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_VACUUMPUMPFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_VACUUMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_HANDBRAKEPRESSED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_FOOTBRAKEPRESSED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_VACUUMLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_BRK_PUMPCOMMAND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_HV_VOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_CHR,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_RUNSUBSTATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_OVERVOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_PLUGDETECTED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_FASTCHARGESTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_SLOWCHARGESTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_CHR_VCU_BMS_CHARGERC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_RPM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_BMSFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_GER_GEARFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_PRECHARGEFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_KEY_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_VCU_DASH_PUMPS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_VCU_DASH_FANFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_ACCELSHORT2POWER,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_ACCELSHORT2GROUND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_ACCELPERFALARM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_ACCELOC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_ECOMODE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_SYSTEM_STATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PST_VCU_PS_SPEED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PST_VCU_PS_ENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_CARSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_ENABLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_K2STATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_FAULT_DCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_WARNING_DCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_FAULT_MCU,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_WARNING_MCU,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_FAULT_PST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_WARNING_PST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_STATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_IDLE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MODECONTROL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MCUTEMP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_MOTORRPM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TST_WATERPUMPDUTY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TST_WATERPUMPDUTYSW,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_COL,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_HIGHSPEEDFAN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_LOWSPEEDFAN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_WATERPUMP_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_RPM,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_TORQUESP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_DSH,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_INITFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PST_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PST_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_MGRRUNSTATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_KEY_POSITION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_ECOMODEON,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_VEHICLESPEED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_PWR2_RELAY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_DCC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_PWR1_RELAYREQUEST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_INTERNALVOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_INTERNFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_LV_VOLTAGE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_PEDALMASSFACTOR,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_DISTANCEDRIVEN,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DRV_TST_TORQUESP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_KEY_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_GER_GEARFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_DEINITFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_WATCHDOGFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_SYS_INITFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PS_INTERNFAULTS1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PS_INTERNFAULTS2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_PST_COMMWARNING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_PST_COMMFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_HISIDEDRIVERFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_MCU,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_MOTORSTOPPED,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_MCU_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_PST,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_PST_STATE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_SYS_ENABLE_KEY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_DCC_PWR1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_SLOPE_MODE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_24V_SUPPLY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_12V_SUPPLY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_ANLG_FAN_POS,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_CABIN_HEATER,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_HAND_BRAKE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_FOOT_BRAKE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_KEY_ACC,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_AIR_CON_REQ,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_GEAR_REVERSE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_KEY_START,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_GEAR_DRIVE,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_KEY_ON,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_ECO,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	},
	{
		/* Data ID */
		RTE_DATA_ID_TEST_OUT_ESTOP,
		/* Data */
		TAPAS_DEFAULT,
		/* Access Mutex */
		RTE_MUTEX_FREE,
		/* Log Flag */
		RTE_LOG_NO
	}
};

/*RTE Access APIs*/
STATUS_t RTE_eReadData(uint16_t u16Id, float* pfltData)
{
  STATUS_t eStatus = STATUS_NOK;
  if(u16Id < RTE_DATA_NUM)
  {
     eStatus = STATUS_OK;
     *pfltData = RTE_astrData[u16Id].fltData;
  }
  return eStatus;
}

STATUS_t RTE_eWriteData(uint16_t u16Id, float fltData)
{
  STATUS_t eStatus = STATUS_NOK;
  if(u16Id < RTE_DATA_NUM)
  {
     eStatus = STATUS_OK;
     RTE_astrData[u16Id].fltData = fltData;
  }
  return eStatus;  
}

/* -----------------------------------------  */
/* RTE Sender Receiver Interfaces Defintions  */
/* -----------------------------------------  */

float RTE_Read_FLT_CLR_ACP_CombinedFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACP_CombinedFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_COMBINEDFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACP_FaultP1_Short2Ground(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACP_FaultP1_Short2Ground(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2GROUND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACP_FaultP1_Short2Vcc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACP_FaultP1_Short2Vcc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP1_SHORT2VCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACP_FaultP2_Short2Ground(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACP_FaultP2_Short2Ground(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2GROUND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACP_FaultP2_Short2Vcc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACP_FaultP2_Short2Vcc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACP_FAULTP2_SHORT2VCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_CombinedFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_COMBINEDFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_COMBINEDFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_CombinedFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_COMBINEDFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_COMBINEDFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_FaultP2_Short2Ground(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_FaultP2_Short2Ground(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2GROUND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_FaultP2_Short2Vcc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_FaultP2_Short2Vcc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_FAULTP2_SHORT2VCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_FaultP1_Short2Ground(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_FaultP1_Short2Ground(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2GROUND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_FaultP1_Short2Vcc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_FaultP1_Short2Vcc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_FAULTP1_SHORT2VCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_TST_PedalPosition2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_TST_PedalPosition2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_TST_PedalPosition1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_TST_PedalPosition1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TST_PEDALPOSITION1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACP_PedalPosition(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_PEDALPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACP_PEDALPOSITION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACP_PedalPosition(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACP_PEDALPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACP_PEDALPOSITION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_TST_MPV_NO_FAN(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TST_MPV_NO_FAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TST_MPV_NO_FAN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_TST_MPV_NO_FAN(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TST_MPV_NO_FAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TST_MPV_NO_FAN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACC_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACC_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Warning_ACC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_WARNING_ACC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Warning_ACC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_WARNING_ACC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Fault_ACC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_FAULT_ACC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Fault_ACC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_FAULT_ACC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACC_Fault_AirCon(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACC_Fault_AirCon(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_FAULT_AIRCON].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_ACC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_ACC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_ACC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_ACC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_Soc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_SOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_SOC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_Soc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_SOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_SOC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_FaultReason(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_FaultReason(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTREASON].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_SWVersion(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_SWVersion(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_SWVERSION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_Lifebeat1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_Lifebeat1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_LIFEBEAT1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_HWVersion(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_HWVersion(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_HWVERSION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_AirConOffRequest(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_AirConOffRequest(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_AIRCONOFFREQUEST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_FaultLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_FaultLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_FAULTLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_GER_GearState(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_GER_GEARSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_GER_GEARSTATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_GER_GearState(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_GER_GEARSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_GER_GEARSTATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DASH_FrontModulePTC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DASH_FrontModulePTC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_FRONTMODULEPTC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DASH_AirConditioning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DASH_AirConditioning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_AIRCONDITIONING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_Heater_Enable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_HEATER_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_HEATER_ENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_Heater_Enable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_HEATER_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_HEATER_ENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_AirCon_Enable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_AIRCON_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_AIRCON_ENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_AirCon_Enable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_AIRCON_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_AIRCON_ENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_Fault_AirCon(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_FAULT_AIRCON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_FAULT_AIRCON].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_Fault_AirCon(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_FAULT_AIRCON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_FAULT_AIRCON].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_ACControllerDropped(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_ACControllerDropped(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_ACCONTROLLERDROPPED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_UnderVolFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_UnderVolFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_UNDERVOLFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_OverheatingFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_OverheatingFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERHEATINGFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_OverVolFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_OverVolFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERVOLFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_OverCurrentFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_OverCurrentFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_OVERCURRENTFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DVD_FailureTestFails(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DVD_FailureTestFails(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DVD_FAILURETESTFAILS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_DASH_BackModulePTC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_DASH_BackModulePTC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_DASH_BACKMODULEPTC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_AirCon_GearPosition(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_AirCon_GearPosition(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_GEARPOSITION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_AirCon_CommandValidity(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_AirCon_CommandValidity(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_COMMANDVALIDITY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_AirCon_FrontFanPosition(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_AirCon_FrontFanPosition(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_FRONTFANPOSITION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_AirCon_AirCompressorRPM(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_AirCon_AirCompressorRPM(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_AIRCOMPRESSORRPM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_ACC_VCU_AirCon_Enable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_ACC_VCU_AirCon_Enable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_ACC_VCU_AIRCON_ENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_BatStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_BatStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_BAT_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_BAT_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Warning_BAT(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_WARNING_BAT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Warning_BAT(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_WARNING_BAT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Fault_BAT(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_FAULT_BAT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Fault_BAT(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_FAULT_BAT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_BAT_InternFaultS2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_BAT_InternFaultS2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_BAT_InternFaultS1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_BAT_InternFaultS1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_INTERNFAULTS1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_BAT(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BAT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_BAT(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BAT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BAT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_InsulationFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_InsulationFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_INSULATIONFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_AllowCharge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_AllowCharge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_ALLOWCHARGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_HighVRelayStatus_K8(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_HighVRelayStatus_K8(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_HIGHVRELAYSTATUS_K8].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_TotalVol(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_TOTALVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_TOTALVOL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_TotalVol(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_TOTALVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_TOTALVOL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_BatFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_BatFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_BATFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_BMS_VCU_SOC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_SOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_SOC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_BMS_VCU_SOC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_SOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_BMS_VCU_SOC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_BatteryDischarge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYDISCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_BATTERYDISCHARGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_BatteryDischarge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYDISCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_BATTERYDISCHARGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_BatteryOff(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYOFF].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_BATTERYOFF].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_BatteryOff(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYOFF].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_BATTERYOFF].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_BatteryCharging(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYCHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_BATTERYCHARGING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_BatteryCharging(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_BATTERYCHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_BATTERYCHARGING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_InternFaultS1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_InternFaultS1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_InternFaultS2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_InternFaultS2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_INTERNFAULTS2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BMS_Allow2Charge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BMS_ALLOW2CHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BMS_ALLOW2CHARGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BMS_Allow2Charge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BMS_ALLOW2CHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BMS_ALLOW2CHARGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BMS_HV_Voltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BMS_HV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BMS_HV_VOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BMS_HV_Voltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BMS_HV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BMS_HV_VOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_VCU_DVD_TotalVolGauge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_VCU_DVD_TotalVolGauge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_TOTALVOLGAUGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_VCU_DVD_AveVolGauge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_VCU_DVD_AveVolGauge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_AVEVOLGAUGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_VCU_DVD_SOCLow(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCLOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCLOW].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_VCU_DVD_SOCLow(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCLOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCLOW].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_VCU_DVD_SOCAlarmFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_VCU_DVD_SOCAlarmFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOCALARMFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BAT_VCU_DVD_SOC2Low(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BAT_VCU_DVD_SOC2Low(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BAT_VCU_DVD_SOC2LOW].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_BRK(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BRK].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BRK].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_BRK(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BRK].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_BRK].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_VacuumPumpFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMPUMPFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_VACUUMPUMPFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_VacuumPumpFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMPUMPFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_VACUUMPUMPFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_VacuumWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_VACUUMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_VacuumWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_VACUUMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_HandBrakePressed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_HANDBRAKEPRESSED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_HANDBRAKEPRESSED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_HandBrakePressed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_HANDBRAKEPRESSED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_HANDBRAKEPRESSED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_FootBrakePressed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_FOOTBRAKEPRESSED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_FOOTBRAKEPRESSED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_FootBrakePressed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_FOOTBRAKEPRESSED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_FOOTBRAKEPRESSED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_VacuumLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_VACUUMLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_VacuumLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_VACUUMLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_VACUUMLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_BRK_PumpCommand(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_PUMPCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_BRK_PUMPCOMMAND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_BRK_PumpCommand(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_BRK_PUMPCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_BRK_PUMPCOMMAND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_CHR_DeltaVoltageReadingFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_CHR_DeltaVoltageReadingFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_DELTAVOLTAGEREADINGFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_HV_Voltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_HV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_HV_VOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_HV_Voltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_HV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_HV_VOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_CHR(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_CHR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_CHR].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_CHR(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_CHR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_CHR].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_SystemErrorSeverity(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_SystemErrorSeverity(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_SYSTEMERRORSEVERITY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_CHR_Overvoltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_CHR_Overvoltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_CHR_OVERVOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_PlugTypeVoltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_PlugTypeVoltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_PLUGTYPEVOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_VCU_BMS_DcChargerEnable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_VCU_BMS_DcChargerEnable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_DCCHARGERENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_RunSubState(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_RUNSUBSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_RUNSUBSTATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_RunSubState(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_RUNSUBSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_RUNSUBSTATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_DeltaVoltageReadingFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_DeltaVoltageReadingFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_DELTAVOLTAGEREADINGFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_Overvoltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_OVERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_OVERVOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_Overvoltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_OVERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_OVERVOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_PlugDetected(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_PLUGDETECTED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_PLUGDETECTED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_PlugDetected(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_PLUGDETECTED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_PLUGDETECTED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_FastChargeStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_FASTCHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_FASTCHARGESTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_FastChargeStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_FASTCHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_FASTCHARGESTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_SlowChargeStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_SLOWCHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_SLOWCHARGESTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_SlowChargeStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_SLOWCHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_SLOWCHARGESTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_VCU_BMS_PowerSupplyMaxC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_VCU_BMS_PowerSupplyMaxC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_POWERSUPPLYMAXC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_CHR_VCU_BMS_ChargerC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_CHARGERC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_CHARGERC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_CHR_VCU_BMS_ChargerC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_CHARGERC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_CHR_VCU_BMS_CHARGERC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_Rpm(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_RPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_RPM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_Rpm(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_RPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_RPM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DVD_DCDCAlarmLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DVD_DCDCAlarmLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCALARMLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DVD_DCDCDropped(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DVD_DCDCDropped(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_DCDCDROPPED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_VehicleFaultLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_VehicleFaultLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VEHICLEFAULTLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DASH_VehicleMode(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DASH_VehicleMode(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VEHICLEMODE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_FailureTestFails(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_FailureTestFails(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_FAILURETESTFAILS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_DCDCWorkInstrucLoss(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_DCDCWorkInstrucLoss(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_DCDCWORKINSTRUCLOSS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_VCU_DVD_MotorCANComuiFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_VCU_DVD_MotorCANComuiFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_VCU_DVD_MOTORCANCOMUIFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_CANCommuniBreakdown(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_CANCommuniBreakdown(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_CANCOMMUNIBREAKDOWN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_BMSDropped(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_BMSDropped(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_BMSDROPPED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_BmsFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_BMSFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_BMSFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_BmsFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_BMSFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_BMSFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_GER_GearFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_GER_GEARFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_GER_GEARFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_GER_GearFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_GER_GEARFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_GER_GEARFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_MCUTemp_High_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_MCUTemp_High_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_HIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_MCUTemp_VeryHigh_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_MCUTemp_VeryHigh_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_MCUTEMP_VERYHIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DASH_MotorOverT(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DASH_MotorOverT(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_MOTOROVERT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_PreChargeFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_PRECHARGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_PRECHARGEFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_PreChargeFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_PRECHARGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_PRECHARGEFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_KEY_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_KEY_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_KEY_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_KEY_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_KEY_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_KEY_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_LV_MinVoltageFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_LV_MinVoltageFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_LV_MINVOLTAGEFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_ChargeStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_ChargeStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_CHARGESTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_K2CloseRequestVali(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_K2CloseRequestVali(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUESTVALI].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_K2CloseRequest(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_K2CloseRequest(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2CLOSEREQUEST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DASH_DCStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DASH_DCStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_DCSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DVD_StartState(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DVD_StartState(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_STARTSTATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_BatteryUndervoltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_BatteryUndervoltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYUNDERVOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_BatteryStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_BatteryStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_BATTERYSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_VCU_DASH_Pumps(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_PUMPS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_PUMPS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_VCU_DASH_Pumps(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_PUMPS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_PUMPS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_LowSpeedFan(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_LowSpeedFan(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_LOWSPEEDFAN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_HighSpeedFan(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_HighSpeedFan(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_HIGHSPEEDFAN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_VCU_DASH_FanFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_FANFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_FANFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_VCU_DASH_FanFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_FANFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_VCU_DASH_FANFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_PumpFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_PumpFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_PUMPFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DVD_VcuFaultLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DVD_VcuFaultLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DVD_VCUFAULTLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DVD_SevereLowBatteryV(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DVD_SevereLowBatteryV(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_SEVERELOWBATTERYV].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DVD_BatteryV2Low(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DVD_BatteryV2Low(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DVD_BATTERYV2LOW].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_AccelShort2Power(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2POWER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2POWER].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_AccelShort2Power(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2POWER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2POWER].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_AccelShort2Ground(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2GROUND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_AccelShort2Ground(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2GROUND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_ACCELSHORT2GROUND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_AccelPerfAlarm(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELPERFALARM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_ACCELPERFALARM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_AccelPerfAlarm(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELPERFALARM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_ACCELPERFALARM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_AccelOC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_ACCELOC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_AccelOC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ACCELOC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_ACCELOC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_EcoMode(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ECOMODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_ECOMODE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_EcoMode(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_ECOMODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_ECOMODE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_CapacityDischarge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_CapacityDischarge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_CAPACITYDISCHARGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_SlopeStopRequest(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_SlopeStopRequest(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_SLOPESTOPREQUEST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_System_Status(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_SYSTEM_STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_SYSTEM_STATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_System_Status(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_SYSTEM_STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_SYSTEM_STATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PST_VCU_PS_Speed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PST_VCU_PS_SPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PST_VCU_PS_SPEED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PST_VCU_PS_Speed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PST_VCU_PS_SPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PST_VCU_PS_SPEED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PST_VCU_PS_Enable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PST_VCU_PS_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PST_VCU_PS_ENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PST_VCU_PS_Enable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PST_VCU_PS_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PST_VCU_PS_ENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_CarStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_CARSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_CARSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_CarStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_CARSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_CARSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_InverterCommand(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_InverterCommand(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_INVERTERCOMMAND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_ModeControl(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_ModeControl(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_MODECONTROL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_TorqueSetpoint(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_TorqueSetpoint(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_TORQUESETPOINT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_RPMSetpoint(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_RPMSetpoint(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RPMSETPOINT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_DrivenCommand(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_DrivenCommand(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_DRIVENCOMMAND].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_VCU_DCDC_DCDCProtConfrim(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_VCU_DCDC_DCDCProtConfrim(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCPROTCONFRIM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_VCU_DCDC_DCDCEnable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_VCU_DCDC_DCDCEnable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_VCU_DCDC_DCDCENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_VehicleSpeed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_VehicleSpeed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_VEHICLESPEED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_GearRange(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_GearRange(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_GEARRANGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_Enable(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_ENABLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_Enable(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_ENABLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_ENABLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_K2Status(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2STATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_K2Status(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_K2STATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VCU_MCU_RelayK1Status(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VCU_MCU_RelayK1Status(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VCU_MCU_RELAYK1STATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorDCVol(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorDCVol(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORDCVOL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MCULowVolSelftest(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MCULowVolSelftest(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCULOWVOLSELFTEST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_DASH_MotorOverT(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_DASH_MotorOverT(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_DASH_MOTOROVERT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_WorkInstructLost(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_WorkInstructLost(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_WORKINSTRUCTLOST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorCANComuiFailure(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorCANComuiFailure(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORCANCOMUIFAILURE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Fault_DCC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_FAULT_DCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Fault_DCC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_FAULT_DCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Warning_DCC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_WARNING_DCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Warning_DCC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_WARNING_DCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Fault_MCU(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_FAULT_MCU].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Fault_MCU(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_FAULT_MCU].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Warning_MCU(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_WARNING_MCU].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Warning_MCU(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_WARNING_MCU].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Fault_PST(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_FAULT_PST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Fault_PST(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_FAULT_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_FAULT_PST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_Warning_PST(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_WARNING_PST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_Warning_PST(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_WARNING_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_WARNING_PST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_TransformerTemp(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_TransformerTemp(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_TRANSFORMERTEMP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorTemp(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorTemp(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORTEMP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_HVRealTimeVol(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_HVRealTimeVol(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_HVREALTIMEVOL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_LVRealTimeC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_LVRealTimeC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_LVRealTimeVol(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_LVRealTimeVol(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_LVREALTIMEVOL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SIM_VCU_DVD_TotalVolGauge(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SIM_VCU_DVD_TotalVolGauge(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SIM_VCU_DVD_TOTALVOLGAUGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SIM_VCU_MCU_VCUSWVersion(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SIM_VCU_MCU_VCUSWVersion(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUSWVERSION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SIM_VCU_MCU_VCUHWVersion(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SIM_VCU_MCU_VCUHWVersion(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SIM_VCU_MCU_VCUHWVERSION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_Status(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_STATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_Status(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_STATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_STATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_DCDC_VCU_FaultLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_DCDC_VCU_FaultLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_DCDC_VCU_FAULTLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_AirCon_VCU_CompressorTempe(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_AirCon_VCU_CompressorTempe(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_AIRCON_VCU_COMPRESSORTEMPE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_ErrorStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_ErrorStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ERRORSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_RotationDirection(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_RotationDirection(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ROTATIONDIRECTION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_Idle(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_IDLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_IDLE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_Idle(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_IDLE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_IDLE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_ModeControl(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MODECONTROL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MODECONTROL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_ModeControl(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MODECONTROL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MODECONTROL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_PS_VCU_OperationStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_PS_VCU_OperationStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_PS_VCU_OPERATIONSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_PS_VCU_FaultLevel(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_PS_VCU_FaultLevel(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_PS_VCU_FAULTLEVEL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorMaxBrakeTorq(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorMaxBrakeTorq(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXBRAKETORQ].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorMaxDrivenTor(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorMaxDrivenTor(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXDRIVENTOR].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorMaxRegenerateP(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorMaxRegenerateP(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORMAXREGENERATEP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MaxDrivePower(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MaxDrivePower(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MAXDRIVEPOWER].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MCUTemp(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCUTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCUTEMP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MCUTemp(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCUTEMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MCUTEMP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_MotorRPM(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORRPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORRPM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_MotorRPM(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORRPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_MOTORRPM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_AllowedCloseK2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_AllowedCloseK2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_ALLOWEDCLOSEK2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COM_MCU_VCU_PrechargeStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COM_MCU_VCU_PrechargeStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COM_MCU_VCU_PRECHARGESTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_TST_WaterPumpDuty(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_TST_WaterPumpDuty(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_TST_WaterPumpDutySW(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTYSW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTYSW].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_TST_WaterPumpDutySW(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTYSW].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TST_WATERPUMPDUTYSW].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_COL(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_COL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_COL].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_COL(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_COL].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_COL].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_COL_MotorTemp_High_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_COL_MotorTemp_High_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_HIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_COL_WaterPump_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_COL_WaterPump_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_WATERPUMP_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_COL_MCUTemp_High_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_COL_MCUTemp_High_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_HIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_COL_MCUTemp_VeryHigh_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_COL_MCUTemp_VeryHigh_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MCUTEMP_VERYHIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_COL_MotorTemp_VeryHigh_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_COL_MotorTemp_VeryHigh_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_COL_MOTORTEMP_VERYHIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_HighSpeedFan(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_HIGHSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_HIGHSPEEDFAN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_HighSpeedFan(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_HIGHSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_HIGHSPEEDFAN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_LowSpeedFan(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_LOWSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_LOWSPEEDFAN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_LowSpeedFan(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_LOWSPEEDFAN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_LOWSPEEDFAN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_WaterPump_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_WATERPUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_WATERPUMP_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_WaterPump_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_WATERPUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_WATERPUMP_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_MotorTemp_High_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_MotorTemp_High_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_HIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_COL_MotorTemp_VeryHigh_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_COL_MotorTemp_VeryHigh_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_COL_MOTORTEMP_VERYHIGH_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_Rpm(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_RPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_RPM].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_Rpm(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_RPM].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_RPM].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_TorqueSp(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TORQUESP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_TORQUESP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_TorqueSp(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TORQUESP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_TORQUESP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_DSH(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DSH].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DSH].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_DSH(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DSH].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DSH].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_InitFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_INITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_INITFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_InitFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_INITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_INITFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PST_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PST_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PST_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PST_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PST_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PST_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PST_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PST_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PST_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PST_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PST_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PST_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_MgrRunState(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_MGRRUNSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_MGRRUNSTATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_MgrRunState(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_MGRRUNSTATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_MGRRUNSTATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_KEY_Position(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_KEY_POSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_KEY_POSITION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_KEY_Position(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_KEY_POSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_KEY_POSITION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_EcoModeOn(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_ECOMODEON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_ECOMODEON].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_EcoModeOn(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_ECOMODEON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_ECOMODEON].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_VehicleSpeed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_VEHICLESPEED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_VehicleSpeed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_VEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_VEHICLESPEED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_PWR2_Relay(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_PWR2_RELAY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_PWR2_RELAY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_PWR2_Relay(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_PWR2_RELAY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_PWR2_RELAY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DASH_VCU_DASH_DCStatus(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DASH_VCU_DASH_DCStatus(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DASH_VCU_DASH_DCSTATUS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DSH_VCU_DASH_VacuumPump(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DSH_VCU_DASH_VacuumPump(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DSH_VCU_DASH_VACUUMPUMP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_DCC_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_DCC_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_DCC_LV_MinVoltageFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_DCC_LV_MinVoltageFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_LV_MINVOLTAGEFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_DCC_InternFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_DCC_InternFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_INTERNFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_DCC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DCC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_DCC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DCC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_DCC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_PWR1_RelayRequest(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_PWR1_RELAYREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_PWR1_RELAYREQUEST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_PWR1_RelayRequest(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_PWR1_RELAYREQUEST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_PWR1_RELAYREQUEST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_InternalVoltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_INTERNALVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_INTERNALVOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_InternalVoltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_INTERNALVOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_INTERNALVOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_InternFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_INTERNFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_INTERNFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_InternFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_INTERNFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_INTERNFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_LV_Voltage(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_LV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_LV_VOLTAGE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_LV_Voltage(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_LV_VOLTAGE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_LV_VOLTAGE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_MotorMaxRegenTorque(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_MotorMaxRegenTorque(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXREGENTORQUE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_MotorMaxDriveTorque(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_MotorMaxDriveTorque(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_MOTORMAXDRIVETORQUE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_PedalMiddlePosition(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_PedalMiddlePosition(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_PEDALMIDDLEPOSITION].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_PedalMassFactor(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_PEDALMASSFACTOR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_PEDALMASSFACTOR].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_PedalMassFactor(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_PEDALMASSFACTOR].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_PEDALMASSFACTOR].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_DistanceDriven(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_DISTANCEDRIVEN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_DISTANCEDRIVEN].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_DistanceDriven(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_DISTANCEDRIVEN].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_DISTANCEDRIVEN].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_TST_MaxVehicleSpeed(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_TST_MaxVehicleSpeed(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_TST_MAXVEHICLESPEED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DRV_TST_TorqueSp(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TST_TORQUESP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DRV_TST_TORQUESP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DRV_TST_TorqueSp(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DRV_TST_TORQUESP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DRV_TST_TORQUESP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_KEY_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_KEY_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_KEY_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_KEY_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_KEY_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_KEY_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_GER_GearFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_GER_GEARFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_GER_GEARFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_GER_GearFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_GER_GEARFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_GER_GEARFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_MCU_PreChargeFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_MCU_PreChargeFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_PRECHARGEFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_DeinitFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_DEINITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_DEINITFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_DeinitFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_DEINITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_DEINITFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_SYS_DeinitFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_SYS_DeinitFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_DEINITFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_WatchdogFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_WATCHDOGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_WATCHDOGFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_WatchdogFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_WATCHDOGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_WATCHDOGFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_SYS_WatchdogFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_SYS_WatchdogFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_WATCHDOGFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_SYS_InitFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_INITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_INITFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_SYS_InitFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_INITFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_INITFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PS_InternFaultS1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PS_InternFaultS1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_PS_InternFaultS1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_PS_InternFaultS1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PS_InternFaultS2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PS_InternFaultS2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PS_INTERNFAULTS2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_PS_InternFaultS2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_PS_InternFaultS2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_PS_INTERNFAULTS2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_ACC_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_ACC_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_ACC_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_BAT_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_BAT_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_BAT_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_DCC_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_DCC_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_DCC_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_MCU_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_MCU_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_MCU_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_MCU_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_MCU_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_PST_CommWarning(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMWARNING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_PST_CommWarning(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMWARNING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMWARNING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_PST_CommFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_PST_CommFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_PST_COMMFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_HiSideDriverFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_HISIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_HISIDEDRIVERFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_HiSideDriverFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_HISIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_HISIDEDRIVERFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_SYS_HiSideDriverFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_SYS_HiSideDriverFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_HISIDEDRIVERFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_LoSideDriverFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_LoSideDriverFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_LOSIDEDRIVERFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_FLT_CLR_SYS_LoSideDriverFault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_FLT_CLR_SYS_LoSideDriverFault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_FLT_CLR_SYS_LOSIDEDRIVERFAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_MCU(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_MCU].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_MCU(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_MCU].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_MCU].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_MotorStopped(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORSTOPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_MOTORSTOPPED].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_MotorStopped(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_MOTORSTOPPED].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_MOTORSTOPPED].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_MCU_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_MCU_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_MCU_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_MCU_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_MCU_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_PST(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_PST].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_PST(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_PST].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_PST].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_PST_State(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_PST_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_PST_STATE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_PST_State(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_PST_STATE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_PST_STATE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_SYS_Enable_KEY(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_KEY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_SYS_ENABLE_KEY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_SYS_Enable_KEY(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_SYS_ENABLE_KEY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_SYS_ENABLE_KEY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_DCC_PWR1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_PWR1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_DCC_PWR1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_DCC_PWR1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_DCC_PWR1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_DCC_PWR1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Slope_Mode(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_SLOPE_MODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_SLOPE_MODE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Slope_Mode(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_SLOPE_MODE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_SLOPE_MODE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_24v_Supply(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_24V_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_24V_SUPPLY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_24v_Supply(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_24V_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_24V_SUPPLY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_12v_Supply(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_12V_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_12V_SUPPLY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_12v_Supply(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_12V_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_12V_SUPPLY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Pout_Duty_Ac_Charging(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Pout_Duty_Ac_Charging(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_POUT_DUTY_AC_CHARGING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Pout_Freq_Ac_Charging(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Pout_Freq_Ac_Charging(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_POUT_FREQ_AC_CHARGING].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_3v3_Supply(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_3v3_Supply(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_3V3_SUPPLY].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_Vacuum_Pump(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_Vacuum_Pump(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_VACUUM_PUMP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_Gas_Pedal2(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_Gas_Pedal2(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL2].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_Ac_Charging_CC(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_Ac_Charging_CC(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_AC_CHARGING_CC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_Gas_Pedal1(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_Gas_Pedal1(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_GAS_PEDAL1].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Anlg_Fan_Pos(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_FAN_POS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_ANLG_FAN_POS].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Anlg_Fan_Pos(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_ANLG_FAN_POS].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_ANLG_FAN_POS].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Cabin_Heater(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_CABIN_HEATER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_CABIN_HEATER].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Cabin_Heater(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_CABIN_HEATER].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_CABIN_HEATER].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Dc_Charge_Lock(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Dc_Charge_Lock(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_DC_CHARGE_LOCK].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Water_Pump_Fault(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Water_Pump_Fault(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_WATER_PUMP_FAULT].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Hand_Brake(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_HAND_BRAKE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_HAND_BRAKE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Hand_Brake(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_HAND_BRAKE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_HAND_BRAKE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Foot_Brake(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_FOOT_BRAKE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_FOOT_BRAKE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Foot_Brake(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_FOOT_BRAKE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_FOOT_BRAKE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Key_Acc(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ACC].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Key_Acc(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ACC].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ACC].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Air_Con_Req(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_AIR_CON_REQ].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_AIR_CON_REQ].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Air_Con_Req(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_AIR_CON_REQ].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_AIR_CON_REQ].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Gear_Reverse(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_REVERSE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_REVERSE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Gear_Reverse(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_REVERSE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_REVERSE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Key_Start(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_START].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_START].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Key_Start(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_START].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_START].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Gear_Drive(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_DRIVE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_DRIVE].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Gear_Drive(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_DRIVE].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_GEAR_DRIVE].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Key_On(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ON].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Key_On(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ON].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_KEY_ON].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Eco(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_ECO].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_ECO].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Eco(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_ECO].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_ECO].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}

float RTE_Read_Test_Out_Estop(void)
{
	STATUS_t eStatus;
	float fltReturnValue = 0;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_ESTOP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		fltReturnValue = RTE_astrData[RTE_DATA_ID_TEST_OUT_ESTOP].fltData;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return fltReturnValue;
}

void RTE_Write_Test_Out_Estop(float fltValue)
{
	STATUS_t eStatus;
	
	if(RTE_astrData[RTE_DATA_ID_TEST_OUT_ESTOP].u32AccessMutex == RTE_MUTEX_FREE)
	{
		RTE_astrData[RTE_DATA_ID_TEST_OUT_ESTOP].fltData = fltValue;
		eStatus = STATUS_OK;
	}
	else
	{
		eStatus = STATUS_NOK;
	}
	
	/* eStatus will be used later for quality signals */
	VARIABLE_NOT_USED(eStatus);
	
	return;
}



/*------------------------------------*/
/*       SWCs Initialization          */
/*------------------------------------*/

void RTE_vdInit(void)
{
  /*1ms Runnables Init*/
//  app_FaultMgr_initialize();
//  /*5ms Runnables Init*/
//  app_AccelMgr_initialize();
//  /*50ms Runnables Init*/
//  app_DrivingMgr_initialize();
//  app_McuMgr_initialize();
//  /*100ms Runnables Init*/
//  app_AirConMgr_initialize();
//  app_BatteryMgr_initialize();
//  app_BrakeMgr_initialize();
//  app_ChargingMgr_initialize();
//  app_ComMgr_initialize();
//  app_CoolingMgr_initialize();
//  app_DashMgr_initialize();
//  app_DcDcMgr_initialize();
//  app_GearMgr_initialize();
//  app_LightMgr_initialize();
//  app_PowerSteeringMgr_initialize();
//  app_StartKeyMgr_initialize();
//  app_SysMgr_initialize();
//  app_test_gen_initialize();
}




/*------------------------------------*/
/*       SWCs DeInitialization          */
/*------------------------------------*/

void RTE_vdDeInit(void)
{
  /*1ms Runnables Init*/
//  app_FaultMgr_terminate();
//  /*5ms Runnables Init*/
//  app_AccelMgr_terminate();
//  /*50ms Runnables Init*/
//  app_DrivingMgr_terminate();
//  app_McuMgr_terminate();
//  /*100ms Runnables Init*/
//  app_AirConMgr_terminate();
//  app_BatteryMgr_terminate();
//  app_BrakeMgr_terminate();
//  app_ChargingMgr_terminate();
//  app_ComMgr_terminate();
//  app_CoolingMgr_terminate();
//  app_DashMgr_terminate();
//  app_DcDcMgr_terminate();
//  app_GearMgr_terminate();
//  app_LightMgr_terminate();
//  app_PowerSteeringMgr_terminate();
//  app_StartKeyMgr_terminate();
//  app_SysMgr_terminate();
//  app_test_gen_terminate();
}


