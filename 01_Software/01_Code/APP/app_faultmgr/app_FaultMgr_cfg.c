///*
//***************************************************************************
//***************************************************************************
//(C) 2016 SIGRA Technologies GmbH  All rights reserved.
//
//All data and information contained in or disclosed by this document is
//confidential and proprietary information of SIGRA Technologies GmbH and all
//rights therein are expressly reserved.  By accepting this material the
//recipient agrees that this material and the information contained therein
//is held in confidence and in trust and will not be used, copied, reproduced
//in whole or in part, nor its contents revealed in any manner to others
//without the express written permission of SIGRA Technologies GmbH
//
//SIGRA Technologies GmbH
//Agnes-Pockels-Bogen 1,
//80992, Munich,
//Germany
//
//File Name: app_FaultMgr_cfg.c
//Author: Karim Mansour 
//E-mail: karim@sigratech.de 
//***************************************************************************
//***************************************************************************
//*/
//
//#include "app_FaultMgr_cfg.h"
//#include "app_FaultMgr.h"
//
//
//APP_FLT_strDtc_t FLT_astrDtc[APP_FLT_DTC_NUM] = 
//{
//  {
//    /* DTC ID 0*/
//    APP_FLT_DTC_KEY_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    3,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_KEY_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_KEY_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_KEY_FAULT,
//  },
//  {
//    /* DTC ID 1*/
//    APP_FLT_DTC_ACP_FAULTP1_SHORT2GROUND,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACP_FaultP1_Short2Ground,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACP_FaultP1_Short2Ground,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACP_FAULTP1_SHORT2GROUND,
//  },
//  {
//    /* DTC ID 2*/
//    APP_FLT_DTC_ACP_FAULTP1_SHORT2VCC,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACP_FaultP1_Short2Vcc,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACP_FaultP1_Short2Vcc,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACP_FAULTP1_SHORT2VCC,
//  },
//  {
//    /* DTC ID 3*/
//    APP_FLT_DTC_ACP_FAULTP2_SHORT2GROUND,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACP_FaultP2_Short2Ground,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACP_FaultP2_Short2Ground,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACP_FAULTP2_SHORT2GROUND,
//  },
//  {
//    /* DTC ID 4*/
//    APP_FLT_DTC_ACP_FAULTP2_SHORT2VCC,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACP_FaultP2_Short2Vcc,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACP_FaultP2_Short2Vcc,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACP_FAULTP2_SHORT2VCC,
//  },
//  {
//    /* DTC ID 5*/
//    APP_FLT_DTC_ACP_COMBINEDFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACP_CombinedFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACP_CombinedFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACP_COMBINEDFAULT,
//  },
//  {
//    /* DTC ID 6*/
//    APP_FLT_DTC_GER_GEARFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_GER_GearFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_GER_GearFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_GER_GEARFAULT,
//  },
//  {
//    /* DTC ID 7*/
//    APP_FLT_DTC_MCU_PRECHARGEFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    3,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_MCU_PreChargeFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_MCU_PreChargeFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_MCU_PRECHARGEFAULT,
//  },
//  {
//    /* DTC ID 8*/
//    APP_FLT_DTC_CHR_OVERVOLTAGE,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    5000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_CHR_Overvoltage,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_CHR_Overvoltage,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_CHR_OVERVOLTAGE,
//  },
//  {
//    /* DTC ID 9*/
//    APP_FLT_DTC_CHR_DELTAVOLTAGEREADINGFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    5000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_CHR_DeltaVoltageReadingFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_CHR_DeltaVoltageReadingFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_CHR_DELTAVOLTAGEREADINGFAULT,
//  },
//  {
//    /* DTC ID 10*/
//    APP_FLT_DTC_DCC_INTERNFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_DCC_InternFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_DCC_InternFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_DCC_INTERNFAULT,
//  },
//  {
//    /* DTC ID 11*/
//    APP_FLT_DTC_SYS_DEINITFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    0,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    1,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_SYS_DeinitFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_SYS_DeinitFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_SYS_DEINITFAULT,
//  },
//  {
//    /* DTC ID 12*/
//    APP_FLT_DTC_SYS_WATCHDOGFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    0,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    1,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_SYS_WatchdogFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_SYS_WatchdogFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_SYS_WATCHDOGFAULT,
//  },
//  {
//    /* DTC ID 13*/
//    APP_FLT_DTC_DCC_LV_MINVOLTAGEFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_DCC_LV_MinVoltageFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_DCC_LV_MinVoltageFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_DCC_LV_MINVOLTAGEFAULT,
//  },
//  {
//    /* DTC ID 14*/
//    APP_FLT_DTC_SYS_INITFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    0,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    1,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_SYS_InitFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_SYS_InitFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_SYS_INITFAULT,
//  },
//  {
//    /* DTC ID 15*/
//    APP_FLT_DTC_BAT_INTERNFAULTS1,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_BAT_InternFaultS1,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_BAT_InternFaultS1,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_BAT_INTERNFAULTS1,
//  },
//  {
//    /* DTC ID 16*/
//    APP_FLT_DTC_BAT_INTERNFAULTS2,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_BAT_InternFaultS2,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_BAT_InternFaultS2,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_BAT_INTERNFAULTS2,
//  },
//  {
//    /* DTC ID 17*/
//    APP_FLT_DTC_ACC_FAULT_AIRCON,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACC_Fault_AirCon,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACC_Fault_AirCon,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACC_FAULT_AIRCON,
//  },
//  {
//    /* DTC ID 18*/
//    APP_FLT_DTC_COL_WATERPUMP_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_COL_WaterPump_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_COL_WaterPump_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_COL_WATERPUMP_FAULT,
//  },
//  {
//    /* DTC ID 19*/
//    APP_FLT_DTC_COL_MCUTEMP_HIGH_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_COL_MCUTemp_High_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_COL_MCUTemp_High_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_COL_MCUTEMP_HIGH_FAULT,
//  },
//  {
//    /* DTC ID 20*/
//    APP_FLT_DTC_COL_MCUTEMP_VERYHIGH_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_COL_MCUTemp_VeryHigh_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_COL_MCUTemp_VeryHigh_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_COL_MCUTEMP_VERYHIGH_FAULT,
//  },
//  {
//    /* DTC ID 21*/
//    APP_FLT_DTC_COL_MOTORTEMP_HIGH_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_COL_MotorTemp_High_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_COL_MotorTemp_High_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_COL_MOTORTEMP_HIGH_FAULT,
//  },
//  {
//    /* DTC ID 22*/
//    APP_FLT_DTC_COL_MOTORTEMP_VERYHIGH_FAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_COL_MotorTemp_VeryHigh_Fault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_COL_MotorTemp_VeryHigh_Fault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_COL_MOTORTEMP_VERYHIGH_FAULT,
//  },
//  {
//    /* DTC ID 23*/
//    APP_FLT_DTC_PS_INTERNFAULTS1,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_PS_InternFaultS1,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_PS_InternFaultS1,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_PS_INTERNFAULTS1,
//  },
//  {
//    /* DTC ID 24*/
//    APP_FLT_DTC_PS_INTERNFAULTS2,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L2,
//    /*Reset Delta Time*/
//    100,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    10,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_PS_InternFaultS2,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_PS_InternFaultS2,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_PS_INTERNFAULTS2,
//  },
//  {
//    /* DTC ID 25*/
//    APP_FLT_DTC_ACC_COMMWARNING,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACC_CommWarning,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACC_CommWarning,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACC_COMMWARNING,
//  },
//  {
//    /* DTC ID 26*/
//    APP_FLT_DTC_ACC_COMMFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_ACC_CommFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_ACC_CommFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_ACC_COMMFAULT,
//  },
//  {
//    /* DTC ID 27*/
//    APP_FLT_DTC_BAT_COMMWARNING,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_BAT_CommWarning,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_BAT_CommWarning,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_BAT_COMMWARNING,
//  },
//  {
//    /* DTC ID 28*/
//    APP_FLT_DTC_BAT_COMMFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_BAT_CommFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_BAT_CommFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_BAT_COMMFAULT,
//  },
//  {
//    /* DTC ID 29*/
//    APP_FLT_DTC_DCC_COMMWARNING,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_DCC_CommWarning,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_DCC_CommWarning,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_DCC_COMMWARNING,
//  },
//  {
//    /* DTC ID 30*/
//    APP_FLT_DTC_DCC_COMMFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_DCC_CommFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_DCC_CommFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_DCC_COMMFAULT,
//  },
//  {
//    /* DTC ID 31*/
//    APP_FLT_DTC_MCU_COMMWARNING,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_MCU_CommWarning,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_MCU_CommWarning,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_MCU_COMMWARNING,
//  },
//  {
//    /* DTC ID 32*/
//    APP_FLT_DTC_MCU_COMMFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_MCU_CommFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_MCU_CommFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_MCU_COMMFAULT,
//  },
//  {
//    /* DTC ID 33*/
//    APP_FLT_DTC_PST_COMMWARNING,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    5,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_PST_CommWarning,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_PST_CommWarning,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_PST_COMMWARNING,
//  },
//  {
//    /* DTC ID 34*/
//    APP_FLT_DTC_PST_COMMFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_WARNING,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    2,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_PST_CommFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_PST_CommFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_PST_COMMFAULT,
//  },
//  {
//    /* DTC ID 35*/
//    APP_FLT_DTC_SYS_HISIDEDRIVERFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    3,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_SYS_HiSideDriverFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_SYS_HiSideDriverFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_SYS_HISIDEDRIVERFAULT,
//  },
//  {
//    /* DTC ID 36*/
//    APP_FLT_DTC_SYS_LOSIDEDRIVERFAULT,
//    /* DTC Severity*/
//    APP_FLT_DTC_SEV_FAULT_L1,
//    /*Reset Delta Time*/
//    1000,
//    /*Delta Time Counter*/
//    TAPAS_DEFAULT,
//    /*Error Count Limit*/
//    3,
//    /*Error Flag*/
//    TAPAS_FALSE,
//    /*Error Count*/
//    TAPAS_DEFAULT,
//    /*Pointer to the RTE Read Error Set Signal*/
//    RTE_Read_SYS_LoSideDriverFault,
//    /*Pointer to the RTE Write Error Clear Signal*/
//    RTE_Write_FLT_CLR_SYS_LoSideDriverFault,
//    /*Decided severity for the DTC*/
//    APP_FLT_DTC_SEV_NO_ERROR,
//    /*Memory Id*/
//    ECU_MEM_INT_DTC_SYS_LOSIDEDRIVERFAULT,
//  },
//};
//
