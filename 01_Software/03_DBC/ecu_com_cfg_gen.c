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

File Name: ecu_com_cfg_gen.c
Author: TAPAS Generated 
E-mail: N/A 
***************************************************************************
***************************************************************************
*/

#include "ecu_com.h"
#include "ecu_com_cfg_gen.h"


/*********** NETWORK 1 ***********/
ECU_COM_strMsg_t ECU_COM_astrRx1Msg[ECU_COM_RX1_MSGS_NUM] =
{
	{
  	/*Msg ID*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	},
	{
  	/*Msg ID*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	}
};


ECU_COM_strMsg_t ECU_COM_astrTx1Msg[ECU_COM_TX1_MSGS_NUM] =
{
	{
  	/*Msg ID*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	},
	{
  	/*Msg ID*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	},
	{
  	/*Msg ID*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	},
	{
  	/*Msg ID*/
		DC_DC_CONTROL,
    /*Can Msg Id*/
		402690000,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	}
};


ECU_COM_strSignal_t ECU_COM_astrRx1Signal[ECU_COM_RX1_SIGNALS_NUM] =
{
	{
  	/*Signal ID*/
		DASH_VCU_BATTERYVOL,
    /*Frame Id*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DASH_VCU_DASHSWVERSION,
    /*Frame Id*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		63,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DASH_VCU_DASHHWVERSION,
    /*Frame Id*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DASH_VCU_ACCUMULATEDMILE,
    /*Frame Id*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*Size*/
		24,
    /*Mask*/
		16777215,
    /*MSB number*/
		31,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DASH_VCU_DASHLIFE,
    /*Frame Id*/
		DASH_STATUS,
    /*Can Msg Id*/
		402706472,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DC_DC_JUNCTION_TEMP,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		63,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DC_DC_TRANSFORMER_TEMP,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		39,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		HV_VOLTAGE,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		LV_VOLTAGE,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		LV_CURRENT,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		31,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DCDCSTATUS1LIFEBEAT,
    /*Frame Id*/
		DC_DC_STATUS1,
    /*Can Msg Id*/
		402706575,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	}
};


ECU_COM_strSignal_t ECU_COM_astrTx1Signal[ECU_COM_TX1_SIGNALS_NUM] =
{
	{
  	/*Signal ID*/
		VCU_DASH_MOTORHWLOSESIGNAL_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		62,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORRESOLVE_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		61,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORLACKPHASE_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		60,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCOUNTEREMF_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		59,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCANFAILURE_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		58,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTOROVERSPEED_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		57,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORDRIVERBOARDOVERT_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		56,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORBLOCKING_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTOROVERLOAD_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		54,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTOROVERTORQUE_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		53,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORBUSLINEOVERV_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		52,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORBUSLINEUNDERV_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		51,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORDQOVERC_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		50,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCVOVERV_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		49,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCVREVERSECONN_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		48,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCVUNDERV_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		47,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORPHASEOVERC_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		46,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORBUSLINEOVERC_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		45,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTOROVERT_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		44,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORIGBTOVERT_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		43,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORBRIDGEUPDOWN_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		42,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORDRIVEPOWERUNDERV_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		41,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORIGBT_P,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		40,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_RPM,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		31,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-15000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_DRIVINGMILE,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VEHICLESPEED,
    /*Frame Id*/
		DASH_CONTROL3,
    /*Can Msg Id*/
		402925776,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VEHICLECONTROLLER,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		29,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_SOC,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		63,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.4,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VACUUMLEVEL,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.01,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORCONTROLLERTEMP,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		47,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_BATTERYSTATUS,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		36,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VACUUMPUMPFAILURE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		35,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_FANFAILURE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		34,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_PUMPFAILURE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		32,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_BETTERYSYSFAILURE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		27,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORSYSFAILURE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		25,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VEHICLEMODE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		3,
    /*Mask*/
		7,
    /*MSB number*/
		20,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_CHARGESTATUS,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		17,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_BACKMODULEPTC,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		13,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_FRONTMODULEPTC,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		11,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_GEARRANGE,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		9,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_CONTROL2_LIFEBEAT,
    /*Frame Id*/
		DASH_CONTROL2,
    /*Can Msg Id*/
		402860240,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_POWERORECOMODE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		63,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_FOOTBRAKE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		62,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_HANDBRAKE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		61,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_AIRCONDITIONING,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		60,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VACUUMPUMP,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		59,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_HIGHSPEEDFAN,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		58,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_LOWSPEEDFAN,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		57,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_PUMPS,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		56,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_MOTORTEMP,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_TORQUECONTROL,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		39,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		-30000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_ACCELPEDALPERCENTAGE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		23,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.4,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_DCSTATUS,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_BATTERYUNDERVOLTAGE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		14,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VACUUMFAILURE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		13,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_CONTROLLERFAILURE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		12,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_CONTROL1_LIFEBEAT,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_DASH_VEHICLEOPERATINGSTATE,
    /*Frame Id*/
		DASH_CONTROL1,
    /*Can Msg Id*/
		402794704,
    /*Size*/
		3,
    /*Mask*/
		7,
    /*MSB number*/
		10,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DC_DC_COMMAND,
    /*Frame Id*/
		DC_DC_CONTROL,
    /*Can Msg Id*/
		402690000,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		9,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DC_DC_CLEARERROR,
    /*Frame Id*/
		DC_DC_CONTROL,
    /*Can Msg Id*/
		402690000,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		11,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		DCDCCONTROLLIFEBEAT,
    /*Frame Id*/
		DC_DC_CONTROL,
    /*Can Msg Id*/
		402690000,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_LITTLE_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	}
};


/*********** NETWORK 2 ***********/
ECU_COM_strMsg_t ECU_COM_astrRx2Msg[ECU_COM_RX2_MSGS_NUM] =
{
	{
  	/*Msg ID*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	}
};


ECU_COM_strMsg_t ECU_COM_astrTx2Msg[ECU_COM_TX2_MSGS_NUM] =
{
	{
  	/*Msg ID*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*DLC*/
		8,
    /*Lower Layer Frame Id */
		TAPAS_DEFAULT,
    /*Data*/
		{TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT,TAPAS_DEFAULT},
    /*Status*/
		MESSAGE_NOT_AVAILABLE
	}
};


ECU_COM_strSignal_t ECU_COM_astrRx2Signal[ECU_COM_RX2_SIGNALS_NUM] =
{
	{
  	/*Signal ID*/
		MCU_VCU_MOTORTORQUE,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		-30000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MCUTEMP,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		47,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_ROTATIONDIRECTION,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		2,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_PRECHARGESTATUS,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		0,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MOTORTEMP,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		39,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-40,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MOTORRPM,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		23,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-15000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MODECONTROL,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		1,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MCULOWVOLSELFTEST,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		5,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_MCULIFE,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_ALLOWEDCLOSEK2,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		4,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_IDLE,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		3,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		MCU_VCU_ERRORSTATUS,
    /*Frame Id*/
		MCU_STATUS1,
    /*Can Msg Id*/
		201380079,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	}
};


ECU_COM_strSignal_t ECU_COM_astrTx2Signal[ECU_COM_TX2_SIGNALS_NUM] =
{
	{
  	/*Signal ID*/
		VCU_MCU_RELAYK1STATUS,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		57,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_CAPACITYDISCHARGE,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		56,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_K2STATUS,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		58,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_K2CLOSEREQUEST,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		59,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_K2CLOSEREQUESTVALI,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		60,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_SLOPESTOPREQUEST,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		61,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_TORQUESETPOINT,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		39,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		0.1,
    /*Offset*/
		-30000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_RPMSETPOINT,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		16,
    /*Mask*/
		65535,
    /*MSB number*/
		23,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		-15000,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_MODECONTROL,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		14,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_ENABLE,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		1,
    /*Mask*/
		1,
    /*MSB number*/
		15,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_INVERTERCOMMAND,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		13,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_DRIVENCOMMAND,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		2,
    /*Mask*/
		3,
    /*MSB number*/
		11,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_CARSTATUS,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		55,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	},
	{
  	/*Signal ID*/
		VCU_MCU_VCULIFE,
    /*Frame Id*/
		MCU_CONTROL1,
    /*Can Msg Id*/
		201387984,
    /*Size*/
		8,
    /*Mask*/
		255,
    /*MSB number*/
		7,
    /*Big/Little Endian*/
		TAPAS_BIG_ENDIAN,
    /*Resolution*/
		1,
    /*Offset*/
		0,
    /*Raw Value*/
		TAPAS_DEFAULT,
    /*Physical Value*/
		TAPAS_DEFAULT,
    /*Status*/
		SIGNAL_NOT_AVAILABLE
	}
};


ECU_COM_strSigDecode_t ECU_COM_astrSigDecodeRx[ECU_COM_RX_SIGNALS_NUM] = 
{
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DASH_VCU_BATTERYVOL,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DASH_VCU_DASHSWVERSION,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DASH_VCU_DASHHWVERSION,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DASH_VCU_ACCUMULATEDMILE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DASH_VCU_DASHLIFE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DC_DC_JUNCTION_TEMP,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DC_DC_TRANSFORMER_TEMP,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		HV_VOLTAGE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		LV_VOLTAGE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		LV_CURRENT,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		DCDCSTATUS1LIFEBEAT,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MOTORTORQUE,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MCUTEMP,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_ROTATIONDIRECTION,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_PRECHARGESTATUS,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MOTORTEMP,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MOTORRPM,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MODECONTROL,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MCULOWVOLSELFTEST,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_MCULIFE,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_ALLOWEDCLOSEK2,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_IDLE,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_RX,
    /* Signal Id*/
		MCU_VCU_ERRORSTATUS,
	}
};


ECU_COM_strSigDecode_t ECU_COM_astrSigDecodeTx[ECU_COM_TX_SIGNALS_NUM] = 
{
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORHWLOSESIGNAL_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORRESOLVE_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORLACKPHASE_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCOUNTEREMF_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCANFAILURE_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTOROVERSPEED_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORDRIVERBOARDOVERT_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORBLOCKING_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTOROVERLOAD_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTOROVERTORQUE_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORBUSLINEOVERV_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORBUSLINEUNDERV_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORDQOVERC_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCVOVERV_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCVREVERSECONN_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCVUNDERV_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORPHASEOVERC_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORBUSLINEOVERC_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTOROVERT_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORIGBTOVERT_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORBRIDGEUPDOWN_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORDRIVEPOWERUNDERV_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORIGBT_P,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_RPM,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_DRIVINGMILE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VEHICLESPEED,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VEHICLECONTROLLER,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_SOC,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VACUUMLEVEL,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORCONTROLLERTEMP,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_BATTERYSTATUS,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VACUUMPUMPFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_FANFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_PUMPFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_BETTERYSYSFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORSYSFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VEHICLEMODE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_CHARGESTATUS,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_BACKMODULEPTC,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_FRONTMODULEPTC,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_GEARRANGE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_CONTROL2_LIFEBEAT,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_POWERORECOMODE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_FOOTBRAKE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_HANDBRAKE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_AIRCONDITIONING,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VACUUMPUMP,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_HIGHSPEEDFAN,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_LOWSPEEDFAN,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_PUMPS,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_MOTORTEMP,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_TORQUECONTROL,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_ACCELPEDALPERCENTAGE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_DCSTATUS,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_BATTERYUNDERVOLTAGE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VACUUMFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_CONTROLLERFAILURE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_CONTROL1_LIFEBEAT,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_DASH_VEHICLEOPERATINGSTATE,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		DC_DC_COMMAND,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		DC_DC_CLEARERROR,
	},
	{
  	/* Handler Id */
		0,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		DCDCCONTROLLIFEBEAT,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_RELAYK1STATUS,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_CAPACITYDISCHARGE,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_K2STATUS,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_K2CLOSEREQUEST,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_K2CLOSEREQUESTVALI,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_SLOPESTOPREQUEST,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_TORQUESETPOINT,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_RPMSETPOINT,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_MODECONTROL,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_ENABLE,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_INVERTERCOMMAND,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_DRIVENCOMMAND,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_CARSTATUS,
	},
	{
  	/* Handler Id */
		1,
    /* Signal Type */
		ECU_COM_CH_TYPE_TX,
    /* Signal Id*/
		VCU_MCU_VCULIFE,
	}
};


