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

File Name: app_diag.h
Author: Karim Mansour 
E-mail: karim@sigratech.de 
***************************************************************************
***************************************************************************
*/

#ifndef APP_DIAG_H
#define APP_DIAG_H

/* List of diag global defines */
#define APP_DIAG_STATUS_FREE                                    (0)                                           
#define APP_DIAG_STATUS_BUSY                                    (1)


/* List of Service Ids */
#define SID_DIAG_SESSION_CONTROL                                (0x10)
#define SID_ECU_RESET                                           (0x11)
#define SID_CLEAR_DIAGNOSTIC_INFO                               (0x14)
#define SID_READ_DTC_INFORMATION                                (0x19)
#define SID_READ_DATA_BY_IDENTIFIER                             (0x22)
#define SID_READ_MEMORY_BY_ADDRESS                              (0x23)
#define SID_READ_SCALE_DATA_IDENTIFIER                          (0x24)
#define SID_SECURITY_ACCESS                                     (0x27)
#define SID_COMM_CONTROL                                        (0x28)
#define SID_READ_DATA_IDENTIFIER_PERIODIC                       (0x2A)
#define SID_DYNAMIC_DEFINE_DATA_IDENTIFIER                      (0x2C)
#define SID_WRITE_DATA_BY_IDENTIFIER                            (0x2E)
#define SID_IO_CONTROL_BY_IDENTIFIER                            (0x2F)
#define SID_REMOTE_CONTROL                                      (0x31)
#define SID_REQUEST_DOWNLOAD                                    (0x34)
#define SID_REQUEST_UPLOAD                                      (0x35)
#define SID_TRANSFER_DATA                                       (0x36)
#define SID_REQUEST_TRANSFER_EXIT                               (0x37)
#define SID_WRITE_MEMORY_BY_ADDRESS                             (0x3D)
#define SID_TESTER_PRESENT                                      (0x3E)
#define SID_ACCESS_TIME_PARAM                                   (0x83)
#define SID_SECURED_DATA_TRANSMISSION                           (0x84)
#define SID_CONTROL_DTC_SETTINGS                                (0x85)
#define SID_RESPONSE_ON_EVENT                                   (0x86)
#define SID_LINK_CONTROL                                        (0x87)

void APP_DIAG_vdInit(void);
void APP_DIAG_vdMgr(void);

#endif /*APP_DIAG_H*/

