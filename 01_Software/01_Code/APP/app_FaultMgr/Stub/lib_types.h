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

File Name: lib_types.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef LIB_TYPES_H
#define LIB_TYPES_H


#define TAPAS_FALSE                          (0)
#define TAPAS_TRUE                           (1)

#define TAPAS_DEFAULT                        (0)

#define TAPAS_NULL                           (void *)0



typedef enum STATUSTemplate
{
   STATUS_OK = 0x00,
	 STATUS_NOK = 0xFF,
	 STATUS_BUSY = 0xFE,
} STATUS_t;

typedef enum TapasBitOrderTemplate
{
   TAPAS_BIG_ENDIAN = 0x00,
	 TAPAS_LITTLE_ENDIAN = 0x01,
} TapasBitOrder_t;


typedef   signed char   int8_t;
typedef unsigned char  uint8_t;
typedef          short  int16_t;
typedef unsigned short uint16_t;
typedef          int    int32_t;
//typedef unsigned int   uint32_t;
typedef          long long  int64_t;
typedef unsigned long long  uint64_t;
typedef unsigned long uint32_t;



#define VARIABLE_NOT_USED(x) x=x

#endif /*LIB_TYPES_H*/
