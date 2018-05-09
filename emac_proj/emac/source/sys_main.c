/** @file sys_main.c 
*   @brief Application main file
*   @date 07-July-2017
*   @version 04.07.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2016 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "system.h"
/* USER CODE BEGIN (1) */
#include "emac.h"
#include "hw_reg_access.h"
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */

/* USER CODE END */

uint8	emacAddress[6U] = 	{0xAAU, 0xAAU, 0xAAU, 0xAAU, 0xAAU, 0xAAU};
uint32 	emacPhyAddress	=	1U;

extern hdkif_t hdkif_data[1];
pbuf_t pack[1];
static uint8 data[100];
uint32 size1 = 470,size2=94;

void create_packet()
{
	int i,j;

	for(i=0;i<1;i++)
	{
	pack[i].tot_len = 80;
	pack[i].len = 80;
	for(j=0;j<6;j++)
	{
		data[j] = 0xffu;

	}
	for(j=0;j<6;j++)
	{
		data[j+6]= emacAddress[j];

	}

	data[12] = 0;
	data[13] = 80;

	for(j=0;j<80;j++)
	{
		data[j+14] = i+5;
	}

	pack[i].payload = &data[0];
//	if(i!=4)
//	pack[i].next = &pack[i+1];
	}
	pack[i].next= NULL;
}

int main(void)
{
/* USER CODE BEGIN (3) */
/* USER CODE END */
    //_enable_IRQ();
    //EMACHWInit(emacAddress);
    InitAsIAR();
    while(1)
    {
        create_packet();
//        EMACTransmit(&hdkif_data[0], &pack[0]);
        tt(&hdkif_data[0], &pack[0]);
        //size1=600;
        //size2=120;
        //create_packet();
        //EMACTransmit(&hdkif_data[0], &pack[0]);
    }
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
