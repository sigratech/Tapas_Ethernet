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

File Name: ecu_mem_cfg.h
Author: Hany elShahawy 
E-mail: shany@sigratech.de
***************************************************************************
***************************************************************************
*/


#ifndef ECU_MEM_CFG_H
#define ECU_MEM_CFG_H

#define ECU_MEM_MODULE_ENABLE

#undef ECU_MEM_EXT_MODULE_ENABLE
#define ECU_MEM_INT_MODULE_ENABLE
#undef ECU_MEM_CODE_MODULE_ENABLE

#ifdef ECU_MEM_CODE_MODULE_ENABLE
#define ECU_MEM_CODE_MAX_PAGE_SIZE_IN_BYTES          (256)
#endif

#ifdef ECU_MEM_EXT_MODULE_ENABLE
#define ECU_MEM_EXT_SPI_BUS_ID                        UC_SPI_MODULE_INDEX_0
#define ECU_MEM_EXT_SPI_DEVICE_ID                     UC_SPI_INDEX0_DEV_1
#define ECU_MEM_EXT_EEP_HLD_PIN                       UC_DIO_OUTPUT_GIO4
#define ECU_MEM_EXT_EEP_WP_PIN                        UC_DIO_OUTPUT_GIO3
#define ECU_MEM_EXT_DATA_NUM                          (35)
#define ECU_MEM_EXT_DATA_ID0                          (0)
#define ECU_MEM_EXT_DATA_ID1                          (1)
#define ECU_MEM_EXT_DATA_ID2                          (2)
#define ECU_MEM_EXT_DATA_ID3                          (3)
#define ECU_MEM_EXT_DATA_ID4                          (4)
#define ECU_MEM_EXT_DATA_ID5                          (5)
#define ECU_MEM_EXT_DATA_ID6                          (6)
#define ECU_MEM_EXT_DATA_ID7                          (7)
#define ECU_MEM_EXT_DATA_ID8                          (8)
#define ECU_MEM_EXT_DATA_ID9                          (9)
#define ECU_MEM_EXT_DATA_ID10                         (10)
#define ECU_MEM_EXT_DATA_ID11                         (11)
#define ECU_MEM_EXT_DATA_ID12                         (12)
#define ECU_MEM_EXT_DATA_ID13                         (13)
#define ECU_MEM_EXT_DATA_ID14                         (14)
#define ECU_MEM_EXT_DATA_ID15                         (15)
#define ECU_MEM_EXT_DATA_ID16                         (16)
#define ECU_MEM_EXT_DATA_ID17                         (17)
#define ECU_MEM_EXT_DATA_ID18                         (18)
#define ECU_MEM_EXT_DATA_ID19                         (19)
#define ECU_MEM_EXT_DATA_ID20                         (20)
#define ECU_MEM_EXT_DATA_ID21                         (21)
#define ECU_MEM_EXT_DATA_ID22                         (22)
#define ECU_MEM_EXT_DATA_ID23                         (23)
#define ECU_MEM_EXT_DATA_ID24                         (24)
#define ECU_MEM_EXT_DATA_ID25                         (25)
#define ECU_MEM_EXT_DATA_ID26                         (26)
#define ECU_MEM_EXT_DATA_ID27                         (27)
#define ECU_MEM_EXT_DATA_ID28                         (28)
#define ECU_MEM_EXT_DATA_ID29                         (29)
#define ECU_MEM_EXT_DATA_ID30                         (30)
#define ECU_MEM_EXT_DATA_ID31                         (31)
#define ECU_MEM_EXT_DATA_ID32                         (32)
#define ECU_MEM_EXT_DATA_ID33                         (33)
#define ECU_MEM_EXT_DATA_ID34                         (34)
#define ECU_MEM_EXT_CS_HIGH_TIME_NS         (25000) 
#define ECU_MEM_EXT_PRECISION_FACTOR        (100)
#endif

#ifdef ECU_MEM_INT_MODULE_ENABLE


#define ECU_MEM_INT_SECTOR                         ECU_MEM_INT_SECTOR_1
#define ECU_MEM_INT_BOOT_SECTOR                    ECU_MEM_INT_SECTOR_0

#define ECU_MEM_INT_DATA_NUM                          (8)
#define ECU_MEM_INT_APP_VALID                         (0)
#define ECU_MEM_INT_WDG_ENABLE                        (1)
#define ECU_MEM_INT_DATA_ID1                          (2)
#define ECU_MEM_INT_DATA_ID2                          (3)
#define ECU_MEM_INT_DATA_ID3                          (4)
#define ECU_MEM_INT_DTC_ID1                           (5)
#define ECU_MEM_INT_DTC_ID2                           (6)
#define ECU_MEM_INT_DTC_ID3                           (7)

#endif

/* Active Interface */
#define ECU_MEM_eWriteSignalValue ECU_MEM_INT_eWriteSignalValue
#define ECU_MEM_eReadSignalValue ECU_MEM_INT_eReadSignalValue


#endif /*ECU_MEM_CFG_H*/

