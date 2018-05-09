/**
 *  \file   emac.c
 *
 *  \brief  EMAC APIs.
 *
 *   This file contains the device abstraction layer APIs for EMAC.
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
/* structure of EMAC registers*/

/* USER CODE END */

#include "emac.h"
#include "sys_vim.h"

/* USER CODE BEGIN (1) */
UC_EMAC_eDuplexMode_t UC_EMAC_eDuplexMode = UC_EMAC_MODE_NOT_INITIALIZED;

//UC_EMAC_strBufferDescriptor_t *UC_EMAC_strTransmitBufferDescriptorLinkedList;
UC_EMAC_strBufferDescriptor_t *UC_EMAC_strHelperTransmit;
UC_EMAC_strBufferDescriptor_t *UC_EMAC_strHelperTransmit2;
UC_EMAC_strBufferDescriptor_t *UC_EMAC_strTransmitBufferDescriptorLinkedList = (UC_EMAC_strBufferDescriptor_t*)(0xFC520000);
UC_EMAC_strActiveNodeHolder_t UC_EMAC_strActiveNodeHelper = {TAPAS_NULL};
STATUS_t UC_EMAC_ePhyIsAlive = STATUS_NOK;
STATUS_t UC_EMAC_ePhyIsLinked = STATUS_NOK;
STATUS_t UC_EMAC_eEmacIsInitialized = STATUS_NOK;
void update_reg(uint32_t u32RegAdd, uint8_t u8BitValue, uint8_t u8BitShift);
STATUS_t local_UC_EMAC_eReadPhyRegData(uint8_t PhyRegAdd, uint16_t *pu16Data);
STATUS_t local_UC_EMAC_eWritePhyRegData(uint8_t PhyRegAdd, uint16_t *pu16Data);
STATUS_t local_UC_EMAC_eIsPhyAlive(void);
STATUS_t local_UC_EMAC_eIsPhyLinked(void);
STATUS_t local_UC_EMAC_eReadAutoNegotiationResults(void);

/* USER CODE END */

/* Defining interface for all the emac instances */
hdkif_t hdkif_data[MAX_EMAC_INSTANCE];
/*SAFETYMCUSW 25 D MR:8.7 <APPROVED> "Statically allocated memory needs to be available to entire application." */
static uint8_t pbuf_array[MAX_RX_PBUF_ALLOC][MAX_TRANSFER_UNIT];
/*******************************************************************************
*                       INTERNAL MACRO DEFINITIONS
*******************************************************************************/
#define EMAC_CONTROL_RESET             (0x01U)
#define EMAC_SOFT_RESET                (0x01U)
#define EMAC_MAX_HEADER_DESC           (8U)
#define EMAC_UNICAST_DISABLE           (0xFFU)

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/
/**
 * \brief   Enables the TXPULSE Interrupt Generation.
 *
 * \param   emacBase      Base address of the EMAC Module registers.
 * \param   emacCtrlBase  Base address of the EMAC CONTROL module registers
 * \param   ctrlCore      Channel number for which the interrupt to be enabled in EMAC Control module
 * \param   channel       Channel number for which interrupt to be enabled
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_001 */
/* DesignId : ETH_DesignId_001*/
/* Requirements : HL_ETH_SR15 */
void EMACTxIntPulseEnable(uint32 emacBase, uint32 emacCtrlBase, uint32 ctrlCore, uint32 channel)
{
    HWREG(emacBase + EMAC_TXINTMASKSET) |= ((uint32)1U << channel);

    HWREG(emacCtrlBase + EMAC_CTRL_CnTXEN(ctrlCore)) |= ((uint32)1U << channel);
}

/**
 * \brief   Disables the TXPULSE Interrupt Generation.
 *
 * \param   emacBase      Base address of the EMAC Module registers.
 * \param   emacCtrlBase  Base address of the EMAC CONTROL module registers
 * \param   ctrlCore      Channel number for which the interrupt to be enabled in EMAC Control module
 * \param   channel       Channel number for which interrupt to be disabled
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_002 */
/* DesignId : ETH_DesignId_002*/
/* Requirements : HL_ETH_SR15 */ 
void EMACTxIntPulseDisable(uint32 emacBase, uint32 emacCtrlBase, uint32 ctrlCore, uint32 channel)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_TXINTMASKCLEAR) |= ((uint32)1U << channel);

    HWREG(emacCtrlBase + EMAC_CTRL_CnTXEN(ctrlCore)) &= (~((uint32)1U << channel));
}

/**
 * \brief   Enables the RXPULSE Interrupt Generation.
 *
 * \param   emacBase      Base address of the EMAC Module registers.
 * \param   emacCtrlBase  Base address of the EMAC CONTROL module registers
 * \param   ctrlCore      Control core for which the interrupt to be enabled.
 * \param   channel       Channel number for which interrupt to be enabled
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_003 */
/* DesignId : ETH_DesignId_003*/
/* Requirements : HL_ETH_SR15 */
void EMACRxIntPulseEnable(uint32 emacBase, uint32 emacCtrlBase, uint32 ctrlCore, uint32 channel)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_RXINTMASKSET) |= ((uint32)1U << channel);

    HWREG(emacCtrlBase + EMAC_CTRL_CnRXEN(ctrlCore)) |= ((uint32)1U << channel);
}

/**
 * \brief   Disables the RXPULSE Interrupt Generation.
 *
 * \param   emacBase      Base address of the EMAC Module registers.
 * \param   emacCtrlBase  Base address of the EMAC CONTROL module registers
 * \param   ctrlCore      Control core for which the interrupt to be disabled.
 * \param   channel       Channel number for which interrupt to be disabled
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_004 */
/* DesignId : ETH_DesignId_004*/
/* Requirements : HL_ETH_SR15 */
void EMACRxIntPulseDisable(uint32 emacBase, uint32 emacCtrlBase, uint32 ctrlCore, uint32 channel)
{
    HWREG(emacBase + EMAC_RXINTMASKCLEAR) |= ((uint32)1U << channel);

    HWREG(emacCtrlBase + EMAC_CTRL_CnRXEN(ctrlCore)) &= (~((uint32)1U << channel));
}
/**
 * \brief   This API sets the RMII speed. The RMII Speed can be 10 Mbps or 
 *          100 Mbps
 *
 * \param   emacBase     Base address of the EMAC Module registers.
 * \param   speed        speed for setting.
 *          speed can take the following values. \n
 *                EMAC_RMIISPEED_10MBPS - 10 Mbps \n
 *                EMAC_RMIISPEED_100MBPS - 100 Mbps. 
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_005 */
/* DesignId : ETH_DesignId_005*/
/* Requirements : HL_ETH_SR19 */
void EMACRMIISpeedSet(uint32 emacBase, uint32 speed)
{
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_RMIISPEED);
    
    HWREG(emacBase + EMAC_MACCONTROL) |= speed;
}
/* SourceId : ETH_SourceId_006 */
/* DesignId : ETH_DesignId_006*/
/* Requirements : HL_ETH_SR18 */
/**
 * \brief   This API set the GMII bit, RX and TX are enabled for receive and transmit.
 *          Note: This is not the API to enable MII. 
 * \param   emacBase     Base address of the EMAC Module registers.
 *
 * \return  None
 *
 **/
void EMACMIIEnable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_GMIIEN;
}

/**
 * \brief   This API clears the GMII bit, Rx and Tx are held in reset.
 *          Note: This is not the API to disable MII. 
 * \param   emacBase     Base address of the EMAC Module registers.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_007 */
/* DesignId : ETH_DesignId_007*/
/* Requirements : HL_ETH_SR18 */
void EMACMIIDisable(uint32 emacBase)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_GMIIEN);
}

/**
 * \brief   This API sets the duplex mode of operation(full/half) for MAC.
 *
 * \param   emacBase     Base address of the EMAC Module registers.
 * \param   duplexMode   duplex mode of operation.
 *          duplexMode can take the following values. \n
 *                EMAC_DUPLEX_FULL - Full Duplex  \n
 *                EMAC_DUPLEX_HALF - Half Duplex.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_008 */
/* DesignId : ETH_DesignId_008*/
/* Requirements : HL_ETH_SR21 */
void EMACDuplexSet(uint32 emacBase, uint32 duplexMode)
{
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_FULLDUPLEX);
    
    HWREG(emacBase + EMAC_MACCONTROL) |= duplexMode;
}

/**
 * \brief   API to enable the transmit in the TX Control Register
 *          After the transmit is enabled, any write to TXHDP of
 *          a channel will start transmission
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_009 */
/* DesignId : ETH_DesignId_009*/
/* Requirements : HL_ETH_SR21 */
void EMACTxEnable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_TXCONTROL) = EMAC_TXCONTROL_TXEN;
}

/**
 * \brief   API to disable the transmit in the TX Control Register
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_010 */
/* DesignId : ETH_DesignId_010*/
/* Requirements : HL_ETH_SR21 */
void EMACTxDisable(uint32 emacBase)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_TXCONTROL) = EMAC_TXCONTROL_TXDIS;
}

/**
 * \brief   API to enable the receive in the RX Control Register
 *          After the receive is enabled, and write to RXHDP of
 *          a channel, the data can be received in the destination
 *          specified by the corresponding RX buffer descriptor.
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_011*/
/* DesignId : ETH_DesignId_011*/
/* Requirements : HL_ETH_SR21 */
void EMACRxEnable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_RXCONTROL) = EMAC_RXCONTROL_RXEN;
}

/**
 * \brief   API to disable the receive in the RX Control Register
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_012*/
/* DesignId : ETH_DesignId_012*/
/* Requirements : HL_ETH_SR21 */
void EMACRxDisable(uint32 emacBase)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_RXCONTROL) = EMAC_RXCONTROL_RXDIS;
}

/**
 * \brief   API to write the TX HDP register. If transmit is enabled,
 *          write to the TX HDP will immediately start transmission.
 *          The data will be taken from the buffer pointer of the TX buffer
 *          descriptor written to the TX HDP
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.\n
 * \param   descHdr       Address of the TX buffer descriptor
 * \param   channel       Channel Number
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_013*/
/* DesignId : ETH_DesignId_013*/
/* Requirements : HL_ETH_SR16 */
void EMACTxHdrDescPtrWrite(uint32 emacBase, uint32 descHdr,
                           uint32 channel)
{
    HWREG(emacBase + EMAC_TXHDP(channel)) = descHdr;
}

/**
 * \brief   API to write the RX HDP register. If receive is enabled,
 *          write to the RX HDP will enable data reception to point to
 *          the corresponding RX buffer descriptor's buffer pointer.
 *
 * \param   emacBase      Base Address of the EMAC Module Registers.\n
 * \param   descHdr       Address of the RX buffer descriptor
 * \param   channel       Channel Number
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_014 */
/* DesignId : ETH_DesignId_014*/
/* Requirements : HL_ETH_SR16 */
void EMACRxHdrDescPtrWrite(uint32 emacBase, uint32 descHdr, uint32 channel)
{
    HWREG(emacBase + EMAC_RXHDP(channel)) = descHdr;
}

/**
 * \brief   This API Initializes the EMAC and EMAC Control modules. The
 *          EMAC Control module is reset, the CPPI RAM is cleared. also,
 *          all the interrupts are disabled. This API does not enable any
 *          interrupt or operation of the EMAC.
 *
 * \param   emacCtrlBase      Base Address of the EMAC Control module
 *                            registers.\n
 * \param   emacBase          Base address of the EMAC module registers
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_015 */
/* DesignId : ETH_DesignId_015*/
/* Requirements : HL_ETH_SR6 */
void EMACInit(uint32 emacCtrlBase, uint32 emacBase)
{
    uint32 cnt;

    /* Reset the EMAC Control Module. This clears the CPPI RAM also */
    HWREG(emacCtrlBase + EMAC_CTRL_SOFTRESET) = EMAC_CONTROL_RESET;

    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    while((HWREG(emacCtrlBase + EMAC_CTRL_SOFTRESET) & EMAC_CONTROL_RESET) == EMAC_CONTROL_RESET)
    { 
    } /* Wait */

    /* Reset the EMAC Module. This clears the CPPI RAM also */
    HWREG(emacBase + EMAC_SOFTRESET) = EMAC_SOFT_RESET;

    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    while((HWREG(emacBase + EMAC_SOFTRESET) & EMAC_SOFT_RESET) == EMAC_SOFT_RESET )
    { 
    } /* Wait */

    HWREG(emacBase + EMAC_MACCONTROL)= 0U;
    HWREG(emacBase + EMAC_RXCONTROL)= 0U;
    HWREG(emacBase + EMAC_TXCONTROL)= 0U;

    /* Initialize all the header descriptor pointer registers */
    for(cnt =  0U; cnt< EMAC_MAX_HEADER_DESC; cnt++)
    {
        HWREG(emacBase + EMAC_RXHDP(cnt)) = 0U;
        HWREG(emacBase + EMAC_TXHDP(cnt)) = 0U;
        HWREG(emacBase + EMAC_RXCP(cnt)) = 0U;
        HWREG(emacBase + EMAC_TXCP(cnt)) = 0U;
        HWREG(emacBase + EMAC_RXFREEBUFFER(cnt)) = 0xFFU;
    }
    /* Clear the interrupt enable for all the channels */
    HWREG(emacBase + EMAC_TXINTMASKCLEAR) = 0xFFU;
    HWREG(emacBase + EMAC_RXINTMASKCLEAR) = 0xFFU;

    HWREG(emacBase + EMAC_MACHASH1) = 0U;
    HWREG(emacBase + EMAC_MACHASH2) = 0U;

    HWREG(emacBase + EMAC_RXBUFFEROFFSET) = 0U;
}

/**
 * \brief   Sets the MAC Address in MACSRCADDR registers.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   macAddr       Start address of a MAC address array.
 *                        The array[0] shall be the LSB of the MAC address
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_016 */
/* DesignId : ETH_DesignId_016*/
/* Requirements : HL_ETH_SR7 */
void  EMACMACSrcAddrSet(uint32 emacBase, uint8 macAddr[6])
{
    HWREG(emacBase + EMAC_MACSRCADDRHI) = ((uint32)macAddr[5U] |((uint32)macAddr[4U] << 8U)
                                     |((uint32)macAddr[3U] << 16U) |((uint32)macAddr[2U] << 24U));
    HWREG(emacBase + EMAC_MACSRCADDRLO) = ((uint32)macAddr[1U] | ((uint32)macAddr[0U] << 8U));
}

/**
 * \brief   Sets the MAC Address in MACADDR registers.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number
 * \param   matchFilt     Match or Filter
 * \param   macAddr       Start address of a MAC address array.
 *                        The array[0] shall be the LSB of the MAC address
 *          matchFilt can take the following values \n
 *          EMAC_MACADDR_NO_MATCH_NO_FILTER - Address is not used to match
 *                                             or filter incoming packet. \n
 *          EMAC_MACADDR_FILTER - Address is used to filter incoming packets \n
 *          EMAC_MACADDR_MATCH - Address is used to match incoming packets \n
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_017 */
/* DesignId : ETH_DesignId_017*/
/* Requirements : HL_ETH_SR7 */
void EMACMACAddrSet(uint32 emacBase, uint32 channel, uint8 macAddr[6], uint32 matchFilt)
{
    HWREG(emacBase + EMAC_MACINDEX) = channel;

    HWREG(emacBase + EMAC_MACADDRHI) = ((uint32)macAddr[5U] |((uint32)macAddr[4U] << 8U)
                                     |((uint32)macAddr[3U] << 16U) |((uint32)macAddr[2U] << 24U));
    HWREG(emacBase + EMAC_MACADDRLO) = ((uint32)macAddr[1U] | ((uint32)macAddr[0U] << 8U)
                                     | matchFilt | (channel << 16U));
}

/**
 * \brief   Acknowledges an interrupt processed to the EMAC Control Core.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   eoiFlag       Type of interrupt to acknowledge to the EMAC Control
 *                         module.
 *          eoiFlag can take the following values \n
 *             EMAC_INT_CORE0_TX - Core 0 TX Interrupt
 *             EMAC_INT_CORE1_TX - Core 1 TX Interrupt
 *             EMAC_INT_CORE2_TX - Core 2 TX Interrupt
 *             EMAC_INT_CORE0_RX - Core 0 RX Interrupt
 *             EMAC_INT_CORE1_RX - Core 1 RX Interrupt
 *             EMAC_INT_CORE2_RX - Core 2 RX Interrupt
 * \return  None
 * 
 **/
/* SourceId : ETH_SourceId_018 */
/* DesignId : ETH_DesignId_018*/
/* Requirements : HL_ETH_SR15 */
void EMACCoreIntAck(uint32 emacBase, uint32 eoiFlag)
{
    /* Acknowledge the EMAC Control Core */
    HWREG(emacBase + EMAC_MACEOIVECTOR) = eoiFlag;
}

/**
 * \brief   Writes the the TX Completion Pointer for a specific channel
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 * \param   comPtr        Completion Pointer Value to be written
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_019 */
/* DesignId : ETH_DesignId_019*/
/* Requirements : HL_ETH_SR27 */
void EMACTxCPWrite(uint32 emacBase, uint32 channel, uint32 comPtr)
{
    HWREG(emacBase + EMAC_TXCP(channel)) = comPtr;
}

/**
 * \brief   Writes the the RX Completion Pointer for a specific channel
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 * \param   comPtr        Completion Pointer Value to be written
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_020 */
/* DesignId : ETH_DesignId_020*/
/* Requirements : HL_ETH_SR27 */
void EMACRxCPWrite(uint32 emacBase, uint32 channel, uint32 comPtr)
{
    HWREG(emacBase + EMAC_RXCP(channel)) = comPtr;
}

/**
 * \brief   Enables a specific channel to receive broadcast frames
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_021 */
/* DesignId : ETH_DesignId_021*/
/* Requirements : HL_ETH_SR28 */
void EMACRxBroadCastEnable(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXBROADCH);

    HWREG(emacBase + EMAC_RXMBPENABLE) |= ((uint32)EMAC_RXMBPENABLE_RXBROADEN | ((uint32)channel << (uint32)EMAC_RXMBPENABLE_RXBROADCH_SHIFT));
}

/**
 * \brief   Disables a specific channel to receive broadcast frames
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_022 */
/* DesignId : ETH_DesignId_022*/
/* Requirements : HL_ETH_SR28 */
void EMACRxBroadCastDisable(uint32 emacBase, uint32 channel)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXBROADCH);
    /* Broadcast Frames are filtered. */
    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXBROADEN);
}

/**
 * \brief   Enables a specific channel to receive multicast frames
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_023 */
/* DesignId : ETH_DesignId_023*/
/* Requirements : HL_ETH_SR28 */
void EMACRxMultiCastEnable(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXMULTCH);

    HWREG(emacBase + EMAC_RXMBPENABLE) |= ((uint32)EMAC_RXMBPENABLE_RXMULTEN |(channel));
}

/**
 * \brief   Disables a specific channel to receive multicast frames
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_024 */
/* DesignId : ETH_DesignId_024*/
/* Requirements : HL_ETH_SR28 */
void EMACRxMultiCastDisable(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXMULTCH);

    HWREG(emacBase + EMAC_RXMBPENABLE) &= (~(uint32)EMAC_RXMBPENABLE_RXMULTEN);
}

/**
 * \brief   Enables unicast for a specific channel
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_025 */
/* DesignId : ETH_DesignId_025*/
/* Requirements : HL_ETH_SR14 */
void EMACRxUnicastSet(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_RXUNICASTSET) |= ((uint32)1U << channel);
}

/**
 * \brief   Disables unicast for a specific channel
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_026 */
/* DesignId : ETH_DesignId_026*/
/* Requirements : HL_ETH_SR14 */
void EMACRxUnicastClear(uint32 emacBase, uint32 channel)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    HWREG(emacBase + EMAC_RXUNICASTCLEAR) |= ((uint32)1U << channel);
}


/**
 * \brief   Set the free buffers for a specific channel
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 * \param   nBuf          Number of free buffers
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_027 */
/* DesignId : ETH_DesignId_027*/
/* Requirements : HL_ETH_SR20 */
void EMACNumFreeBufSet(uint32 emacBase, uint32 channel,
                       uint32 nBuf)
{
    HWREG(emacBase + EMAC_RXFREEBUFFER(channel)) = nBuf;
}

/**
 * \brief   Gets the interrupt vectors of EMAC, which are pending
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 *
 * \return  Vectors
 *
 **/
/* SourceId : ETH_SourceId_028 */
/* DesignId : ETH_DesignId_028*/
/* Requirements : HL_ETH_SR15 */
uint32 EMACIntVectorGet(uint32 emacBase)
{
    return (HWREG(emacBase + EMAC_MACINVECTOR));
}



/**
* Function to setup the instance parameters inside the interface
* @param   hdkif Network interface structure
* @return  none.
*/
/* SourceId : ETH_SourceId_029 */
/* DesignId : ETH_DesignId_029*/
/* Requirements : HL_ETH_SR6 */
void EMACInstConfig(hdkif_t *hdkif)
{
    hdkif->emac_base = EMAC_0_BASE;
    hdkif->emac_ctrl_base = EMAC_CTRL_0_BASE;
    hdkif->emac_ctrl_ram = EMAC_CTRL_RAM_0_BASE;
    hdkif->mdio_base = MDIO_BASE;
    hdkif->phy_addr = 1U;
    /* (MISRA-C:2004 10.1/R) MISRA error reported with Code Composer Studio MISRA checker.  */
    hdkif->phy_autoneg = &Dp83640AutoNegotiate;
    hdkif->phy_partnerability = &Dp83640PartnerAbilityGet;
}

/**
* Function to setup the link. AutoNegotiates with the phy for link
* setup and set the EMAC with the result of autonegotiation.
* @param  hdkif Network interface structure.
* @return ERR_OK if everything passed
*         others if not passed
*/
/* SourceId : ETH_SourceId_030 */
/* DesignId : ETH_DesignId_030*/
/* Requirements : HL_ETH_SR6 */
uint32 EMACLinkSetup(hdkif_t *hdkif) {
  uint32 linkstat = EMAC_ERR_CONNECT;
  uint16 partnr_ablty = 0U;
  uint32 phyduplex = EMAC_DUPLEX_HALF;
  volatile uint32 delay = 0xFFFFFU;

    if(Dp83640AutoNegotiate((uint32)hdkif->mdio_base, (uint32)hdkif->phy_addr,
                             (uint16)((uint16)DP83640_100BTX | (uint16)DP83640_100BTX_FD
                              | (uint16)DP83640_10BT | (uint16)DP83640_10BT_FD)) == TRUE) {
      linkstat = EMAC_ERR_OK;
      /* (MISRA-C:2004 10.1/R) MISRA error reported with Code Composer Studio MISRA checker (due to use of & ?)  */
      (void)Dp83640PartnerAbilityGet(hdkif->mdio_base, hdkif->phy_addr,
                                &partnr_ablty);

      /* Check for 100 Mbps and duplex capability */
      if((partnr_ablty & DP83640_100BTX_FD) != 0U) {
        phyduplex = EMAC_DUPLEX_FULL;
      }
    }


  else {
    linkstat = EMAC_ERR_CONNECT;
  }

  /* Set the EMAC with the negotiation results if it is successful */
  if(linkstat == EMAC_ERR_OK) {
    EMACDuplexSet(hdkif->emac_base, phyduplex);
  }

  /* Wait for the MII to settle down */
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  while(delay != 0U)
  {
    delay--;
  }

  return linkstat;
}

/**
 * \brief   Perform a transmit queue teardown, that is, transmission is aborted.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_031 */
/* DesignId : ETH_DesignId_031*/
/* Requirements : HL_ETH_SR22 */
void EMACTxTeardown(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_TXTEARDOWN) &= (channel);
}

/**
 * \brief   Perform a receive queue teardown, that is, reception is aborted.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_032 */
/* DesignId : ETH_DesignId_032*/
/* Requirements : HL_ETH_SR22 */
void EMACRxTeardown(uint32 emacBase, uint32 channel)
{
    HWREG(emacBase + EMAC_RXTEARDOWN) &= (channel);
}


/**
 * \brief   Perform multicast frame filtering using the MAC Hash Registers.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   hashTable     The hash table which specifies which bits are to be accepted.
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_033 */
/* DesignId : ETH_DesignId_033*/
/* Requirements : HL_ETH_SR24 */
void EMACFrameSelect(uint32 emacBase, uint64 hashTable)
{
    HWREG(emacBase + EMAC_MACHASH1) = (uint32)(hashTable & 0xFFFFFFFFU);
    HWREG(emacBase + EMAC_MACHASH2) = (uint32)(hashTable >> 32U);
}


/**
 * \brief   Sets the Transmit Queue Priority type in the MACCONTROL Register
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   txPType       The Transmit Queue Priority Type.
 *                        0 results in a round-robin scheme being used to select the next channel, while 1 results
 *                        in a fixed-priority scheme( channel 7 highest priority).
 *
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_034 */
/* DesignId : ETH_DesignId_034*/
/* Requirements : HL_ETH_SR25 */
void EMACTxPrioritySelect(uint32 emacBase, uint32 txPType)
{

    /* 1- The queue uses a fixed-priority (channel 7 highest priority) scheme */
    if(txPType == 1U)
    {
        HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)(EMAC_MACCONTROL_TXPTYPE));
        HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_TXPTYPE;
    }
    else
    {
        HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)(EMAC_MACCONTROL_TXPTYPE));
    }
}


/**
 * \brief   Performs a soft reset of the EMAC and EMAC Control Modules.
 *
 * \param   emacCtrlBase  Base address of the EMAC CONTROL module registers
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_035 */
/* DesignId : ETH_DesignId_035*/
/* Requirements : HL_ETH_SR26 */
void EMACSoftReset(uint32 emacCtrlBase, uint32 emacBase)
{
    /* Reset the EMAC Control Module. This clears the CPPI RAM also */
    HWREG(emacCtrlBase + EMAC_CTRL_SOFTRESET) = EMAC_CONTROL_RESET;

    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    while((HWREG(emacCtrlBase + EMAC_CTRL_SOFTRESET) & EMAC_CONTROL_RESET) == EMAC_CONTROL_RESET)
    {
        /* Wait for the reset to complete */
    } 

    /* Reset the EMAC Module. */
    HWREG(emacBase + EMAC_SOFTRESET) = EMAC_SOFT_RESET;

    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    while((HWREG(emacBase + EMAC_SOFTRESET) & EMAC_SOFT_RESET) == EMAC_SOFT_RESET )
    {
        /* Wait for the Reset to complete */
    } 

}

/**
 * \brief   Enable Idle State of the EMAC Module.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_036 */
/* DesignId : ETH_DesignId_036*/
/* Requirements : HL_ETH_SR32 */
void EMACEnableIdleState(uint32 emacBase)
{
        HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_CMDIDLE;
}

/**
 * \brief   Disable Idle State of the EMAC Module.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_037 */
/* DesignId : ETH_DesignId_037*/
/* Requirements : HL_ETH_SR32 */
void EMACDisableIdleState(uint32 emacBase)
{
        HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)(EMAC_MACCONTROL_CMDIDLE));
}

/**
 * \brief   Enables Loopback Mode.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_038 */
/* DesignId : ETH_DesignId_038*/
/* Requirements : HL_ETH_SR50 */
void EMACEnableLoopback(uint32 emacBase)
/*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "LDRA Tool issue." */
{
    uint32 GMIIENval=0U;
    /*Store the value of GMIIEN bit before deasserting it */
    GMIIENval = HWREG(emacBase + EMAC_MACCONTROL) & EMAC_MACCONTROL_GMIIEN;
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_GMIIEN);

    /*Enable Loopback */
    HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_LOOPBACK;

    /*Restore the value of GMIIEN bit */
    HWREG(emacBase + EMAC_MACCONTROL) |= GMIIENval;
}

/**
 * \brief   Disables Loopback Mode.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_039 */
/* DesignId : ETH_DesignId_039*/
/* Requirements : HL_ETH_SR50 */
void EMACDisableLoopback(uint32 emacBase)
{
    uint32 GMIIENval=0U;

    /*Store the value of GMIIEN bit before deasserting it */
    GMIIENval = HWREG(emacBase + EMAC_MACCONTROL) & EMAC_MACCONTROL_GMIIEN;
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_GMIIEN);

    /*Disable Loopback */
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_LOOPBACK);

    /*Restore the value of GMIIEN bit */
    HWREG(emacBase + EMAC_MACCONTROL) |= GMIIENval;
}

/**
 * \brief   Enable Transmit Flow Control.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_040 */
/* DesignId : ETH_DesignId_040*/
/* Requirements : HL_ETH_SR20 */
void EMACTxFlowControlEnable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_TXFLOWEN;
}

/**
 * \brief   Disable Transmit Flow Control.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_041 */
/* DesignId : ETH_DesignId_041*/
/* Requirements : HL_ETH_SR20 */
void EMACTxFlowControlDisable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_TXFLOWEN);
}

/**
 * \brief   Enable Receive Flow Control.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_042 */
/* DesignId : ETH_DesignId_042*/
/* Requirements : HL_ETH_SR20 */
void EMACRxFlowControlEnable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_MACCONTROL) |= EMAC_MACCONTROL_RXBUFFERFLOWEN;
}

/**
 * \brief   Disable Receive Flow Control.
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_043 */
/* DesignId : ETH_DesignId_043*/
/* Requirements : HL_ETH_SR20 */
void EMACRxFlowControlDisable(uint32 emacBase)
{
    HWREG(emacBase + EMAC_MACCONTROL) &= (~(uint32)EMAC_MACCONTROL_RXBUFFERFLOWEN);
}

/**
 * \brief   Receive flow threshold. These bits contain the threshold value for issuing flow control on incoming frames for channel n (when enabled).
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number
 * \param   threshold     threshold value for issuing flow control on incoming frames for the given channel
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_044 */
/* DesignId : ETH_DesignId_044*/
/* Requirements : HL_ETH_SR20 */
void EMACRxSetFlowThreshold(uint32 emacBase, uint32 channel, uint32 threshold)
{
    HWREG(emacBase + EMAC_RXFLOWTHRESH(channel)) &= (0x0U);
    HWREG(emacBase + EMAC_RXFLOWTHRESH(channel)) |= threshold;
}

/**
 * \brief               This function reads the contents of the 36 network statistics registers that are present in the module.
 * \param   emacBase    Base Address of the EMAC module registers.
 * \param   statRegNo   The number of the register with RXGOODFRAMES (Offset= 0x200) being 0. Refer the Technical Reference Manual for the list of registers and their contents.
 * \return  uint32
 **/
/* SourceId : ETH_SourceId_045 */
/* DesignId : ETH_DesignId_045*/
/* Requirements : HL_ETH_SR29 */
uint32 EMACReadNetStatRegisters(uint32 emacBase, uint32 statRegNo)
{
    return HWREG(emacBase + EMAC_NETSTATREGS(statRegNo));
}


/**
 * \brief   Function to read values of Transmit Interrupt Status registers (TXINTSTATMASKED and TXINTSTATRAW)
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number
 * \param   txintstat     pointer to the emac_tx_int_status Structure that will store the register values that have been read
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_046 */
/* DesignId : ETH_DesignId_046*/
/* Requirements : HL_ETH_SR23 */
void EMACTxIntStat(uint32 emacBase, uint32 channel, emac_tx_int_status_t *txintstat)
{
    txintstat->intstatmasked = (HWREG(emacBase + EMAC_TXINTSTATMASKED) & ((uint32)1U << channel));
    txintstat->intstatraw = (HWREG(emacBase + EMAC_TXINTSTATRAW) & ((uint32)1U << channel));
}


/**
 * \brief   Function to read values of Receive Interrupt Status registers (RXINTSTATMASKED, RXINTSTATRAW)
 *
 * \param   emacBase      Base Address of the EMAC module registers.
 * \param   channel       Channel Number
 * \param  rxintstat      pointer to the emac_rx_int_status Structure that will store the register values that have been read.
 * \return  None
 **/
/* SourceId : ETH_SourceId_047 */
/* DesignId : ETH_DesignId_047*/
/* Requirements : HL_ETH_SR23 */
void EMACRxIntStat(uint32 emacBase, uint32 channel, emac_rx_int_status_t *rxintstat)
{
    rxintstat->intstatmasked_pend = (HWREG(emacBase + EMAC_RXINTSTATMASKED) & ((uint32)0x1U << (uint32)(channel)));
    rxintstat->intstatmasked_threshpend = (HWREG(emacBase + EMAC_RXINTSTATMASKED) & ((uint32)0x1U << ((uint32)0x8U + (uint32)(channel))));

    rxintstat->intstatraw_pend = (HWREG(emacBase + EMAC_RXINTSTATRAW) & ((uint32)0x1U << (uint32)(channel)));
    rxintstat->intstatraw_threshpend = (HWREG(emacBase + EMAC_RXINTSTATRAW) & ((uint32)0x1U << ((uint32)0x8U + (uint32)(channel))));
}


/**
 * \brief   Tx and Rx Buffer Descriptors are initialized. Buffer pointers are allocated to the Rx Descriptors.
 *
 * \param   hdkif   network interface structure
 * \return  None
 *
 **/
/* SourceId : ETH_SourceId_048 */
/* DesignId : ETH_DesignId_048*/
/* Requirements : HL_ETH_SR17,HL_ETH_SR30 */
void EMACDMAInit(hdkif_t *hdkif)
{

      uint32 num_bd, pbuf_cnt = 0U;
      volatile emac_tx_bd_t *curr_txbd, *last_txbd;
      volatile emac_rx_bd_t *curr_bd, *last_bd;
      txch_t *txch_dma;
      rxch_t *rxch_dma;
      uint8_t *p;

      txch_dma = &(hdkif->txchptr);

      /**
      * Initialize the Descriptor Memory For TX and RX
      * Only single channel is supported for both TX and RX
      */
      /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      txch_dma->free_head = (volatile emac_tx_bd_t*)(hdkif->emac_ctrl_ram);
      txch_dma->next_bd_to_process = txch_dma->free_head;
      txch_dma->active_tail = NULL;

      /* Set the number of descriptors for the channel */
      num_bd = (SIZE_EMAC_CTRL_RAM >> 1U) / sizeof(emac_tx_bd_t);

      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      curr_txbd = txch_dma->free_head;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      last_txbd = curr_txbd;

      /* Initialize all the TX buffer Descriptors */
      while(num_bd != 0U) {
        /*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Struct pointer used for linked list is incremented." */
        curr_txbd->next = curr_txbd + 1U;
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
        curr_txbd->flags_pktlen = 0U;
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
        last_txbd = curr_txbd;
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
        curr_txbd = curr_txbd->next;
        num_bd--;
      }
      /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      last_txbd->next = txch_dma->free_head;

      /* Initialize the descriptors for the RX channel */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      rxch_dma = &(hdkif->rxchptr);
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      /*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Struct pointer used for linked list is incremented." */
      curr_txbd++;
      /*SAFETYMCUSW 94 S MR:11.1,11.2,11.4 <APPROVED> "Linked List pointer needs to be assigned." */
      /*SAFETYMCUSW 95 S MR:11.1,11.4 <APPROVED> "Linked List pointer needs to be assigned." */
      /*SAFETYMCUSW 344 S MR:11.5 <APPROVED> "Linked List pointer needs to be assigned to a different structure." */      
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      rxch_dma->active_head = (volatile emac_rx_bd_t *)curr_txbd;

      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */         
      rxch_dma->free_head = NULL;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      curr_bd = rxch_dma->active_head;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      last_bd = curr_bd;


      /*
      **  Static allocation of a specific number of packet buffers as specified by MAX_RX_PBUF_ALLOC, whose value is entered by the user in  HALCoGen GUI.
      */

      /*Commented part of allocation of pbufs need to check whether its true*/

      for(pbuf_cnt = 0U;pbuf_cnt < MAX_RX_PBUF_ALLOC;pbuf_cnt++)
        {
         /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */  
         p = pbuf_array[pbuf_cnt];
         /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "RHS is a pointer value required to be stored. - Advisory as per MISRA" */
         /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
         curr_bd->bufptr = (uint32)p;
         /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */  
         curr_bd->bufoff_len = MAX_TRANSFER_UNIT;
         /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
         curr_bd->flags_pktlen = EMAC_BUF_DESC_OWNER;
         if (pbuf_cnt == (MAX_RX_PBUF_ALLOC - 1U))
         {
             /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */  
             curr_bd->next = NULL;
             /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */              
             last_bd = curr_bd;

         }
         else
         {
             /*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Struct pointer used for linked list is incremented." */
             curr_bd->next = (curr_bd + 1U);
             /*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Struct pointer used for linked list is incremented." */
             curr_bd++;
             /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */  
             last_bd = curr_bd;
         }
       }
      
      /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */         
      last_bd->next = NULL;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      rxch_dma->active_tail = last_bd;
}


/**
 * \brief   Initializes the EMAC module for transmission and reception.
 *
 * \param   macaddr    MAC Address of the Module.
 * \param   channel       Channel Number.
 *
 * \return  EMAC_ERR_OK if everything gets initialized
 *          EMAC_ERR_CONN in case of an error in connecting.
 *
 **/
/* SourceId : ETH_SourceId_049 */
/* DesignId : ETH_DesignId_049*/
/* Requirements : HL_ETH_SR6 */
uint32 EMACHWInit(uint8_t macaddr[6U])
{
  uint32 temp, channel;
  volatile uint32 phyID=0U;
  volatile uint32 delay = 0xFFFU;
  uint32 phyIdReadCount = 0xFFFFU;
  volatile uint32 phyLinkRetries = 0xFFFFU;
  hdkif_t *hdkif;
  rxch_t *rxch;
  uint32 retVal = EMAC_ERR_OK;
  uint32 emacBase = 0U;
#if(EMAC_MII_ENABLE == 0U)
  uint16 partnr_spd;
#endif

  hdkif = &hdkif_data[0U];
  EMACInstConfig(hdkif);
  /* set MAC hardware address */
  for(temp = 0U; temp < EMAC_HWADDR_LEN; temp++) {
    hdkif->mac_addr[temp] = macaddr[(EMAC_HWADDR_LEN - 1U) - temp];
  }
  /*Initialize the EMAC, EMAC Control and MDIO modules. */
  EMACInit(hdkif->emac_ctrl_base, hdkif->emac_base);
  MDIOInit(hdkif->mdio_base, MDIO_FREQ_INPUT, MDIO_FREQ_OUTPUT);
  
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  while(delay != 0U)
  {
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    delay--;
  }

  /* Set the MAC Addresses in EMAC hardware */
  emacBase = hdkif->emac_base; /* MISRA Code Fix (12.2) */
  EMACMACSrcAddrSet(emacBase, hdkif->mac_addr);
  for(channel = 0U; channel < 8U; channel++) {
       emacBase = hdkif->emac_base;
       EMACMACAddrSet(emacBase, channel, hdkif->mac_addr, EMAC_MACADDR_MATCH);
  }

  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  while ((phyID == 0U) && (phyIdReadCount > 0U)) {
      phyID = Dp83640IDGet(hdkif->mdio_base,hdkif->phy_addr);
      phyIdReadCount--;
  }

  if (0U == phyID) {
      retVal = EMAC_ERR_CONNECT;
  } else {

  }

  if((uint32)0U == ((MDIOPhyAliveStatusGet(hdkif->mdio_base)
        >> hdkif->phy_addr) & (uint32)0x01U )) {
    retVal = EMAC_ERR_CONNECT;
  } else {

  }

#if(EMAC_MII_ENABLE == 0U)
	  
	Dp83640PartnerSpdGet(hdkif->mdio_base, hdkif->phy_addr, &partnr_spd);
	if((partnr_spd & 2U)==0U)
	{
		EMACRMIISpeedSet(hdkif->emac_base, EMAC_MACCONTROL_RMIISPEED);
	}
#endif

  if(!Dp83640LinkStatusGet(hdkif->mdio_base, (uint32)EMAC_PHYADDRESS, (uint32)phyLinkRetries)) {
      retVal = EMAC_ERR_CONNECT;
  } else {

  }

  if(EMACLinkSetup(hdkif) != EMAC_ERR_OK) {
    retVal = EMAC_ERR_CONNECT;
  } else {

  }

  /* The transmit and receive buffer descriptors are initialized here. 
   * Also, packet buffers are allocated to the receive buffer descriptors.
   */

  //EMACDMAInit(hdkif);
  uint32_t u32CppiRamAddress;
  volatile UC_EMAC_strBufferDescriptor_t *tempBufferDescriptor;
  u32CppiRamAddress = UC_EMAC_CPPI_RAM_BASE_ADDRESS;
  UC_EMAC_strActiveNodeHelper.ActiveNode = (UC_EMAC_strBufferDescriptor_t*)(u32CppiRamAddress);
  tempBufferDescriptor = UC_EMAC_strActiveNodeHelper.ActiveNode;
  while (u32CppiRamAddress < UC_EMAC_CPPI_RAM_MID_ADDRESS)
  {
    tempBufferDescriptor->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t* )tempBufferDescriptor + 1U;
    tempBufferDescriptor->PacketFlagsAndLength = 0U;
    tempBufferDescriptor = tempBufferDescriptor->pstrNextBufferDescriptor;
//    pu32HeadAddress = (uint32_t *)u32CppiRamAddress;
//    *((UC_EMAC_strBufferDescriptor_t*)pu32HeadAddress) = tempBufferDescriptor;
    u32CppiRamAddress = u32CppiRamAddress + (4U * 4U);
//    ((UC_EMAC_strBufferDescriptor_t*)pu32HeadAddress)->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t *)u32CppiRamAddress;
  }
  tempBufferDescriptor->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t*)UC_EMAC_strActiveNodeHelper.ActiveNode;

  /* Acknowledge receive and transmit interrupts for proper interrupt pulsing*/
  EMACCoreIntAck(hdkif->emac_base, (uint32)EMAC_INT_CORE0_RX);
  EMACCoreIntAck(hdkif->emac_base, (uint32)EMAC_INT_CORE0_TX);

  /* Enable GMII bit in the MACCONTROL Rgister*/
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
  EMACMIIEnable(hdkif->emac_base);

  /* Enable Broadcast if enabled in the GUI. */
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
#if(EMAC_BROADCAST_ENABLE)
      EMACRxBroadCastEnable(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER);
#else
   /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */
   /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */
      EMACRxBroadCastDisable(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER);
#endif
  
  /* Enable Broadcast if enabled in the GUI. */
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
#if(EMAC_UNICAST_ENABLE)
      EMACRxUnicastSet(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER);
#else
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */
      EMACRxUnicastClear(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER);
#endif

  /*Enable Full Duplex or Half-Duplex mode based on GUI Input. */
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
#if (EMAC_FULL_DUPLEX_ENABLE)
        EMACDuplexSet(EMAC_0_BASE, (uint32)EMAC_DUPLEX_FULL);
#else
        /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition arameter is taken as input from GUI." */
        EMACDuplexSet(EMAC_0_BASE, (uint32)EMAC_DUPLEX_HALF);
#endif

  /* Enable Loopback based on GUI Input */ 
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
#if(EMAC_LOOPBACK_ENABLE)
      EMACEnableLoopback(hdkif->emac_base);
#else
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */  
      EMACDisableLoopback(hdkif->emac_base);
#endif

  /* Enable Transmit and Transmit Interrupt */ 
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI." */
#if(EMAC_TX_ENABLE)
      EMACTxEnable(hdkif->emac_base);
      EMACTxIntPulseEnable(hdkif->emac_base, hdkif->emac_ctrl_base, (uint32)EMAC_CHANNELNUMBER, (uint32)EMAC_CHANNELNUMBER);
#else
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI." */
      EMACTxDisable(hdkif->emac_base);
      EMACTxIntPulseDisable(hdkif->emac_base, hdkif->emac_ctrl_base, (uint32)EMAC_CHANNELNUMBER, (uint32)EMAC_CHANNELNUMBER);     
#endif

/*
      /* Enable Receive and Receive Interrupt. Then start receiving by writing to the HDP register.
  /*SAFETYMCUSW 139 S MR:13.7 <APPROVED> "Parameter is taken as input from GUI."
#if(EMAC_RX_ENABLE)
      EMACNumFreeBufSet(hdkif->emac_base,(uint32)EMAC_CHANNELNUMBER , (uint32)MAX_RX_PBUF_ALLOC);
      EMACRxEnable(hdkif->emac_base);
      EMACRxIntPulseEnable(hdkif->emac_base, hdkif->emac_ctrl_base, (uint32)EMAC_CHANNELNUMBER, (uint32)EMAC_CHANNELNUMBER);
      rxch = &(hdkif->rxchptr);
      /* Write to the RX HDP for channel 0 */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver"
      EMACRxHdrDescPtrWrite(hdkif->emac_base, (uint32)rxch->active_head, (uint32)EMAC_CHANNELNUMBER);
#else
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI."
      /*SAFETYMCUSW 1 J MR:14.1 <APPROVED> "If condition parameter is taken as input from GUI."
      EMACRxDisable(hdkif->emac_base);
      EMACRxIntPulseDisable(hdkif->emac_base, hdkif->emac_ctrl_base, (uint32)EMAC_CHANNELNUMBER, (uint32)EMAC_CHANNELNUMBER);     
#endif
*/
  return retVal;
}

void InitAsIAR()
{
    uint32 u32RegData;
  // signal multiplexing
    // MDIO_CLK p.1529 for selecting EMAC/MDIO signal // 7
    u32RegData = *(uint32_t*)0xFFFFEB2C;
    u32RegData &= (0xFFFF00FF);
    u32RegData |= (0x00000400);
    *(uint32_t*)0xFFFFEB2C = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 8
    u32RegData = *(uint32_t*)0xFFFFEB30;
    u32RegData &= (0xFFFF00FF);
    u32RegData |= (0x00000400);
    *(uint32_t*)0xFFFFEB30 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 17
    u32RegData = *(uint32_t*)0xFFFFEB54;
    u32RegData &= (0xFFFFFF00);
    u32RegData |= (0x00000002);
    *(uint32_t*)0xFFFFEB54 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 14
    u32RegData = *(uint32_t*)0xFFFFEB48;
    u32RegData &= (0xFFFFFF00);
    u32RegData |= (0x00000004);
    *(uint32_t*)0xFFFFEB48 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 13
    u32RegData = *(uint32_t*)0xFFFFEB44;
    u32RegData &= (0x00FFFFFF);
    u32RegData |= (0x04000000);
    *(uint32_t*)0xFFFFEB44 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 13
    u32RegData = *(uint32_t*)0xFFFFEB44;
    u32RegData &= (0xFFFF00FF);
    u32RegData |= (0x00000400);
    *(uint32_t*)0xFFFFEB44 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 13
    u32RegData = *(uint32_t*)0xFFFFEB44;
    u32RegData &= (0xFFFFFF00);
    u32RegData |= (0x00000040);
    *(uint32_t*)0xFFFFEB44 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 13
    u32RegData = *(uint32_t*)0xFFFFEB44;
    u32RegData &= (0xFF00FFFF);
    u32RegData |= (0x00040000);
    *(uint32_t*)0xFFFFEB44 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 20
    u32RegData = *(uint32_t*)0xFFFFEB60;
    u32RegData &= (0xFF00FFFF);
    u32RegData |= (0x00040000);
    *(uint32_t*)0xFFFFEB60 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 17
    u32RegData = *(uint32_t*)0xFFFFEB54;
    u32RegData &= (0xFF00FFFF);
    u32RegData |= (0x00020000);
    *(uint32_t*)0xFFFFEB54 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 14
    u32RegData = *(uint32_t*)0xFFFFEB48;
    u32RegData &= (0xFFFF00FF);
    u32RegData |= (0x00000200);
    *(uint32_t*)0xFFFFEB48 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 12
    u32RegData = *(uint32_t*)0xFFFFEB40;
    u32RegData &= (0x00FFFFFF);
    u32RegData |= (0x04000000);
    *(uint32_t*)0xFFFFEB40 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 12
    u32RegData = *(uint32_t*)0xFFFFEB40;
    u32RegData &= (0xFF00FFFF);
    u32RegData |= (0x00040000);
    *(uint32_t*)0xFFFFEB40 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 12
    u32RegData = *(uint32_t*)0xFFFFEB40;
    u32RegData &= (0xFFFFFF00);
    u32RegData |= (0x00000002);
    *(uint32_t*)0xFFFFEB40 = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 11
    u32RegData = *(uint32_t*)0xFFFFEB3C;
    u32RegData &= (0x00FFFFFF);
    u32RegData |= (0x04000000);
    *(uint32_t*)0xFFFFEB3C = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 19
    u32RegData = *(uint32_t*)0xFFFFEB5C;
    u32RegData &= (0xFFFF00FF);
    u32RegData |= (0x00000200);
    *(uint32_t*)0xFFFFEB5C = u32RegData;
    // MDIO_D p.1529 for selecting EMAC/MDIO signal // 10
    u32RegData = *(uint32_t*)0xFFFFEB38;
    u32RegData &= (0xFFFFFF00);
    u32RegData |= (0x00000002);
    *(uint32_t*)0xFFFFEB38 = u32RegData;



  hdkif_t *hdkif;
  uint8_t u8Counter;
  volatile uint32 phyID=0U;
  volatile uint32 delay = 0xFFFU;
  uint32 phyIdReadCount = 0xFFFFU;
  volatile uint32 phyLinkRetries = 0xFFFFU;
  uint32 retVal = EMAC_ERR_OK;
  hdkif = &hdkif_data[0U];
  EMACInstConfig(hdkif);
  // soft reset of emac control
  *(uint32_t *)0xFCF78800 = 0x1;
  while (*(uint32_t *)0xFCF78800 == 0x1)
    {
      // wait till reset is finished
    }
  // soft reset of emac
  *(uint32_t *)0xFCF78174 = 0x1;
  while (*(uint32_t *)0xFCF78174 == 0x1)
    {
      // wait till reset is finished
    }
  // zeros to mac control
  *(uint32_t*)0xFCF78160 = (uint32_t)0;
  // zeros to rx control
  *(uint32_t*)0xFCF78014 = (uint32_t)0;
  // zeros to tx control
  *(uint32_t*)0xFCF78004 = (uint32_t)0;
  // zeros to TX0HDP
  *(uint32_t*)0xFCF78600 = (uint32_t)0;
  // zeros to TX1HDP
  *(uint32_t*)0xFCF78604 = (uint32_t)0;
  // zeros to TX2HDP
  *(uint32_t*)0xFCF78608 = (uint32_t)0;
  // zeros to TX3HDP
  *(uint32_t*)0xFCF7860C = (uint32_t)0;
  // zeros to TX4HDP
  *(uint32_t*)0xFCF78610 = (uint32_t)0;
  // zeros to TX5HDP
  *(uint32_t*)0xFCF78614 = (uint32_t)0;
  // zeros to TX6HDP
  *(uint32_t*)0xFCF78618 = (uint32_t)0;
  // zeros to TX7HDP
  *(uint32_t*)0xFCF7861C = (uint32_t)0;
  // zeros to RX0HDP
  *(uint32_t*)0xFCF78620 = (uint32_t)0;
  // zeros to RX1HDP
  *(uint32_t*)0xFCF78624 = (uint32_t)0;
  // zeros to RX2HDP
  *(uint32_t*)0xFCF78628 = (uint32_t)0;
  // zeros to RX3HDP
  *(uint32_t*)0xFCF7862C = (uint32_t)0;
  // zeros to RX4HDP
  *(uint32_t*)0xFCF78630 = (uint32_t)0;
  // zeros to RX5HDP
  *(uint32_t*)0xFCF78634 = (uint32_t)0;
  // zeros to RX6HDP
  *(uint32_t*)0xFCF78638 = (uint32_t)0;
  // zeros to RX7HDP
  *(uint32_t*)0xFCF7863C = (uint32_t)0;
  // zeros to TX0CP
  *(uint32_t*)0xFCF78640 = (uint32_t)0;
  // zeros to TX1CP
  *(uint32_t*)0xFCF78644 = (uint32_t)0;
  // zeros to TX2CP
  *(uint32_t*)0xFCF78648 = (uint32_t)0;
  // zeros to TX3CP
  *(uint32_t*)0xFCF7864C = (uint32_t)0;
  // zeros to TX4CP
  *(uint32_t*)0xFCF78650 = (uint32_t)0;
  // zeros to TX5CP
  *(uint32_t*)0xFCF78654 = (uint32_t)0;
  // zeros to TX6CP
  *(uint32_t*)0xFCF78658 = (uint32_t)0;
  // zeros to TX7CP
  *(uint32_t*)0xFCF7865C = (uint32_t)0;
  // zeros to RX0CP
  *(uint32_t*)0xFCF78660 = (uint32_t)0;
  // zeros to RX1CP
  *(uint32_t*)0xFCF78664 = (uint32_t)0;
  // zeros to RX2CP
  *(uint32_t*)0xFCF78668 = (uint32_t)0;
  // zeros to RX3CP
  *(uint32_t*)0xFCF7866C = (uint32_t)0;
  // zeros to RX4CP
  *(uint32_t*)0xFCF78670 = (uint32_t)0;
  // zeros to RX5CP
  *(uint32_t*)0xFCF78674 = (uint32_t)0;
  // zeros to RX6CP
  *(uint32_t*)0xFCF78678 = (uint32_t)0;
  // zeros to RX7CP
  *(uint32_t*)0xFCF7867C = (uint32_t)0;
  // zeros to RX0FREEBUFFER
  *(uint32_t*)0xFCF78140 = (uint32_t)0XFF;
  // zeros to RX1FREEBUFFER
  *(uint32_t*)0xFCF78144 = (uint32_t)0XFF;
  // zeros to RX2FREEBUFFER
  *(uint32_t*)0xFCF78148 = (uint32_t)0XFF;
  // zeros to RX3FREEBUFFER
  *(uint32_t*)0xFCF7814C = (uint32_t)0XFF;
  // zeros to RX4FREEBUFFER
  *(uint32_t*)0xFCF78150 = (uint32_t)0XFF;
  // zeros to RX5FREEBUFFER
  *(uint32_t*)0xFCF78154 = (uint32_t)0XFF;
  // zeros to RX6FREEBUFFER
  *(uint32_t*)0xFCF78158 = (uint32_t)0XFF;
  // zeros to RX7FREEBUFFER
  *(uint32_t*)0xFCF7815C = (uint32_t)0XFF;
  // clears all 36 statistics registers
  *(uint32_t*)0xFCF78200 = (uint32_t)0;
  *(uint32_t*)0xFCF78204 = (uint32_t)0;
  *(uint32_t*)0xFCF78208 = (uint32_t)0;
  *(uint32_t*)0xFCF7820C = (uint32_t)0;
  *(uint32_t*)0xFCF78210 = (uint32_t)0;
  *(uint32_t*)0xFCF78214 = (uint32_t)0;
  *(uint32_t*)0xFCF78218 = (uint32_t)0;
  *(uint32_t*)0xFCF7821C = (uint32_t)0;
  *(uint32_t*)0xFCF78220 = (uint32_t)0;
  *(uint32_t*)0xFCF78224 = (uint32_t)0;
  *(uint32_t*)0xFCF78228 = (uint32_t)0;
  *(uint32_t*)0xFCF7822C = (uint32_t)0;
  *(uint32_t*)0xFCF78230 = (uint32_t)0;
  *(uint32_t*)0xFCF78234 = (uint32_t)0;
  *(uint32_t*)0xFCF78238 = (uint32_t)0;
  *(uint32_t*)0xFCF7823C = (uint32_t)0;
  *(uint32_t*)0xFCF78240 = (uint32_t)0;
  *(uint32_t*)0xFCF78244 = (uint32_t)0;
  *(uint32_t*)0xFCF78248 = (uint32_t)0;
  *(uint32_t*)0xFCF7824C = (uint32_t)0;
  *(uint32_t*)0xFCF78250 = (uint32_t)0;
  *(uint32_t*)0xFCF78254 = (uint32_t)0;
  *(uint32_t*)0xFCF78258 = (uint32_t)0;
  *(uint32_t*)0xFCF7825C = (uint32_t)0;
  *(uint32_t*)0xFCF78260 = (uint32_t)0;
  *(uint32_t*)0xFCF78264 = (uint32_t)0;
  *(uint32_t*)0xFCF78268 = (uint32_t)0;
  *(uint32_t*)0xFCF7826C = (uint32_t)0;
  *(uint32_t*)0xFCF78270 = (uint32_t)0;
  *(uint32_t*)0xFCF78274 = (uint32_t)0;
  *(uint32_t*)0xFCF78278 = (uint32_t)0;
  *(uint32_t*)0xFCF7827C = (uint32_t)0;
  *(uint32_t*)0xFCF78280 = (uint32_t)0;
  *(uint32_t*)0xFCF78284 = (uint32_t)0;
  *(uint32_t*)0xFCF78288 = (uint32_t)0;
  *(uint32_t*)0xFCF7828C = (uint32_t)0;
  // DISABLE INTERRUPTS
  *(uint32_t*)0xFCF780AC = (uint32_t)0;
  *(uint32_t*)0xFCF7808C = (uint32_t)0;
  // DISABLE MACHASH
  *(uint32_t*)0xFCF781D8 = (uint32_t)0;
  *(uint32_t*)0xFCF781DC = (uint32_t)0;
  // BUFFER OFFSET
  *(uint32_t*)0xFCF78110 = (uint32_t)0;
  // DISABLE MDIO
  *(uint32_t*)0xFCF78904 = (uint32_t)0;
  // set MDIO clock to run at 1Mhz (typical operation p.1544)
  *(uint32_t*)0xFCF78904 = 0x5A;
  // phy address of dp83640 is 1 by default (dp83640.pdf p.45 & tms570ls3_hdk_schematics p.19)

  update_reg(0xFCF78980,1,16);
  update_reg(0xFCF78980,0,17);
  update_reg(0xFCF78980,0,18);
  update_reg(0xFCF78980,0,19);
  update_reg(0xFCF78980,0,20);
  // phy address of dp83640 is 1 by default (dp83640.pdf p.45 & tms570ls3_hdk_schematics p.19)

  update_reg(0xFCF78984,1,0);
  // fault enable in MDIO module

  update_reg(0xFCF78904,1,18);
  update_reg(0xFCF78904,1,20);
  update_reg(0xFCF78904,1,30);
  // update MAC ADDRESS
  *(uint32_t*)0xFCF781D4 = 0x5A;
  for (u8Counter = 0; u8Counter < 8; u8Counter++)
  {
    *(uint32_t*)0xFCF78508 = u8Counter;
    *(uint32_t*)0xFCF78504 = 0X5A;
  }

  local_UC_EMAC_eReadAutoNegotiationResults();

  uint32_t u32CppiRamAddress;
    volatile UC_EMAC_strBufferDescriptor_t *tempBufferDescriptor;
    u32CppiRamAddress = UC_EMAC_CPPI_RAM_BASE_ADDRESS;
    UC_EMAC_strActiveNodeHelper.ActiveNode = (UC_EMAC_strBufferDescriptor_t*)(u32CppiRamAddress);
    tempBufferDescriptor = UC_EMAC_strActiveNodeHelper.ActiveNode;
    while (u32CppiRamAddress < UC_EMAC_CPPI_RAM_MID_ADDRESS)
    {
      tempBufferDescriptor->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t* )tempBufferDescriptor + 1U;
      tempBufferDescriptor->PacketFlagsAndLength = 0U;
      tempBufferDescriptor = tempBufferDescriptor->pstrNextBufferDescriptor;
  //    pu32HeadAddress = (uint32_t *)u32CppiRamAddress;
  //    *((UC_EMAC_strBufferDescriptor_t*)pu32HeadAddress) = tempBufferDescriptor;
      u32CppiRamAddress = u32CppiRamAddress + (4U * 4U);
  //    ((UC_EMAC_strBufferDescriptor_t*)pu32HeadAddress)->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t *)u32CppiRamAddress;
    }
    tempBufferDescriptor->pstrNextBufferDescriptor = (UC_EMAC_strBufferDescriptor_t*)UC_EMAC_strActiveNodeHelper.ActiveNode;

    // acknowledge interrupts processed to emac control for core0_rx
      update_reg(0xFCF78094,1,0);
    // acknowledge interrupts processed to emac control for core0_tx
      update_reg(0xFCF78094,1,1);
    // enable broadcast
      update_reg(0xFCF78100,1,13);
//      // enable full duplex
//      update_reg(0xFCF78160,1,0);
      // enable tx control
      update_reg(0xFCF78004,1,0);
      // enable tx pulse interrupt generation
      update_reg(0xFCF78088,1,0);
      update_reg(0xFCF78818,1,0);
      // set gmii bit
      update_reg(0xFCF78160,1,5);
}

void update_reg(uint32_t u32RegAdd, uint8_t u8BitValue, uint8_t u8BitShift)
{
    // updates specific bits in register
    uint32_t u32RegVal = *(uint32_t*)u32RegAdd;
    uint32_t u32Temp = (uint32_t)0;
    u32Temp |= (1U << u8BitShift);
    if (u8BitValue == 1)
    {
        u32RegVal |= u32Temp;
    }
    else
    {
        u32RegVal &= ~(u32Temp);
    }
    *(uint32_t*)u32RegAdd = u32RegVal;

}

STATUS_t local_UC_EMAC_eReadAutoNegotiationResults(void)
{
  STATUS_t eStatus = STATUS_NOK;
  uint16_t u16BMCRdata;
  uint16_t u16ANLPARdata;
  uint16_t u16BMSRdata;
  // check if phy chip is detected by mdio
  UC_EMAC_ePhyIsAlive = local_UC_EMAC_eIsPhyAlive();
  // check if phy chip is linked
  UC_EMAC_ePhyIsLinked = local_UC_EMAC_eIsPhyLinked();
  // reads results of auto-negotiation & update values
  if (UC_EMAC_ePhyIsAlive == STATUS_OK && UC_EMAC_ePhyIsLinked == STATUS_OK)
  {
    // restart auto-negotiation as in halcogen
    eStatus = local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipBMCR,&u16BMCRdata);
    if (eStatus == STATUS_OK)
    {
      // enable auto-neg
      u16BMCRdata |= (0x1000U);
      eStatus = local_UC_EMAC_eWritePhyRegData(UC_EMAC_u8PhyChipBMCR,&u16BMCRdata);
      if (eStatus == STATUS_OK)
      {
        eStatus = local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipBMCR,&u16BMCRdata);
        if (eStatus == STATUS_OK)
        {
          // read auto-negotiation caps
          eStatus = local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipANLPAR, &u16ANLPARdata);
          if (eStatus == STATUS_OK)
          {
            u16ANLPARdata &= (uint16_t)(~0xff10U);
            u16ANLPARdata |= (0x0080U);
            u16ANLPARdata |= (0x0100U);
            u16ANLPARdata |= (0x0020U);
            u16ANLPARdata |= (0x0040U);
            eStatus = local_UC_EMAC_eWritePhyRegData(UC_EMAC_u8PhyChipANLPAR, &u16ANLPARdata);
            if (eStatus == STATUS_OK)
            {
              u16BMCRdata |= (0x0200U);
              eStatus = local_UC_EMAC_eWritePhyRegData(UC_EMAC_u8PhyChipBMCR,&u16BMCRdata);
              if (eStatus == STATUS_OK)
              {
                // get auto-negotiation result
                // read BMSR register
                eStatus = local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipBMSR, &u16BMSRdata);
                if (eStatus == STATUS_OK)
                {
                  while (((u16BMSRdata & 0x0020) >> 5U) != 1U)
                  {
                    local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipBMSR, &u16BMSRdata);
                    // wait till auto negotiation is complete
                  }
                  // check speed and duplex capability -- as in halcogen
                  // read ANLPAR register
                  eStatus = local_UC_EMAC_eReadPhyRegData(UC_EMAC_u8PhyChipANLPAR, &u16ANLPARdata);
                  if (eStatus == STATUS_OK)
                  {
                    // check TX_FD bit (dp83640.pdf p.70)
                    if (((u16ANLPARdata & 0x0100U) >> 8U) == 1U)
                    {
                      UC_EMAC_eDuplexMode = (UC_EMAC_eDuplexMode_t)0x01U;
                      //UC_EMAC_eSpeedMode = (UC_EMAC_eSpeedMode_t)0x01U;
                      // set speed and mode
                      // enable full duplex
                            update_reg(0xFCF78160,1,0);
                      //UC_EMAC_strObj.pEMAC_MACCONTROL_bit->FULLDUPLEX = UC_EMAC_eDuplexMode;
                      //UC_EMAC_strObj.pEMAC_MACCONTROL_bit->RMIISPEED = UC_EMAC_eSpeedMode;
                      eStatus = STATUS_OK;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return eStatus;
}

STATUS_t local_UC_EMAC_eReadPhyRegData(uint8_t PhyRegAdd, uint16_t *pu16Data)
{
  STATUS_t eStatus = STATUS_NOK;
  uint32_t u32d;
  // check if state machine is free
  while (((*(uint32_t*)0xFCF78904) >> 31) == 1)
  {
    // pass
  }
  // read operation
  update_reg(0xFCF78980,0,30);
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->WRITE = 0U;
  // fill phy reg address
  uint32_t u32regval = *(uint32_t*)0xFCF78980;
  u32regval &= ~(0x01F00000);
  u32regval |= (PhyRegAdd << 21U);
  *(uint32_t*)0xFCF78980 = u32regval;
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->REGADR = PhyRegAdd;
  // phy address of dp83640 is 1 by default (dp83640.pdf p.45 & tms570ls3_hdk_schematics p.19)
  // phy address whose link status is to be monitored
  update_reg(0xFCF78984,1,0);
  //UC_EMAC_strObj.pMDIO_USERPHYSEL0_bit->PHYADRMON = (UC_EMAC_PHY_CHIP_ADDRESS);
  // start operation
  update_reg(0xFCF78980,1,31);
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->GO = 1;
  // check if phy acknowledged the read transaction
  u32d = *(uint32_t*)0xFCF78980;
  while (((u32d >> 29) & 0x01) != 1)
  {
      u32d = *(uint32_t*)0xFCF78980;
    // wait till acknowledged
  }
  u32d = *(uint32_t*)0xFCF78980;
  while (((u32d >> 31) & 0x01) == 1)
  {
      u32d = *(uint32_t*)0xFCF78980;
    // wait till data is received
  }
  eStatus = STATUS_OK;
  // read data from reg
  u32d = *(uint32_t*)0xFCF78980;
  *pu16Data = (uint16_t)(u32d & 0x0000FFFF);
//  *pu16Data = UC_EMAC_strObj.pMDIO_USERACCESS0_bit->DATA;
  return eStatus;
}

STATUS_t local_UC_EMAC_eWritePhyRegData(uint8_t PhyRegAdd, uint16_t *pu16Data)
{
  STATUS_t eStatus = STATUS_NOK;
  uint32_t u32d;
  // check if state machine is free
  while (((*(uint32_t*)0xFCF78904) >> 31) == 1)
  {
    // pass
  }
  // read operation
  update_reg(0xFCF78980,1,30);
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->WRITE = 1U;
  // fill phy reg address
  uint32_t u32regval = *(uint32_t*)0xFCF78980;
  u32regval  &= ~(0x01F00000);
  u32regval  |= (PhyRegAdd << 21U);
  *(uint32_t*)0xFCF78980 = u32regval;
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->REGADR = PhyRegAdd;
  // phy address of dp83640 is 1 by default (dp83640.pdf p.45 & tms570ls3_hdk_schematics p.19)
  // phy address whose link status is to be monitored
  update_reg(0xFCF78984,1,0);
//  UC_EMAC_strObj.pMDIO_USERPHYSEL0_bit->PHYADRMON = (UC_EMAC_PHY_CHIP_ADDRESS);
  // write data to reg
  u32regval = *(uint32_t*)0xFCF78980;
  u32regval  &= (0xFFFF0000);
  u32regval  |= *pu16Data;
  (*(uint32_t*)0xFCF78980) = u32regval;
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->DATA = *pu16Data;
  // start operation
  update_reg(0xFCF78980,1,31);
//  UC_EMAC_strObj.pMDIO_USERACCESS0_bit->GO = 1;
  // check if phy acknowledged the read transaction
  u32d = *(uint32_t*)0xFCF78980;
  while (((u32d >> 29) & 0x01) != 1)
  {
      u32d = *(uint32_t*)0xFCF78980;
    // wait till acknowledged
  }
  u32d = *(uint32_t*)0xFCF78980;
  while (((u32d >> 31) & 0x01) == 1)
  {
      u32d = *(uint32_t*)0xFCF78980;
    // wait till data is received
  }
  eStatus = STATUS_OK;
  return eStatus;
}


STATUS_t local_UC_EMAC_eIsPhyAlive(void)
{
  // check on alive bit to know if phy device is detected
  STATUS_t eStatus = STATUS_NOK;
  uint32_t *pu32AliveRegister = (uint32_t*)UC_EMAC_AliveRegisterAddress;
  if (((*pu32AliveRegister >> UC_EMAC_PHY_CHIP_ADDRESS) | UC_EMAC_PHY_CHIP_ADDRESS) == 1)
  {
    eStatus = STATUS_OK;
  }
  return eStatus;
}

STATUS_t local_UC_EMAC_eIsPhyLinked(void)
{
  // check on link bit phy device monitored is still active
  STATUS_t eStatus = STATUS_NOK;
  uint32_t *pu32LinkRegister = (uint32_t*)UC_EMAC_LinkeRegisterAddress;
  if (((*pu32LinkRegister >> UC_EMAC_PHY_CHIP_ADDRESS) | UC_EMAC_PHY_CHIP_ADDRESS) == 1)
  {
    eStatus = STATUS_OK;
  }
  return eStatus;
}
void tt(hdkif_t *hdkif, pbuf_t *pbuf)
{
  uint8 i;
  uint32_t u32PacketFlags = (uint32_t)0;
  uint32_t u32PacketFlagsPlusLength = 0;
  volatile UC_EMAC_strBufferDescriptor_t *tempBufferDescriptor;
  u32PacketFlags |= (1U << UC_EMAC_DSC_FLAG_SOP_SHIFT);
  u32PacketFlags |= (1U << UC_EMAC_DSC_FLAG_EOP_SHIFT);
  u32PacketFlags |= (1U << UC_EMAC_DSC_FLAG_OWNER_SHIFT);
  u32PacketFlags |= (0U << UC_EMAC_DSC_FLAG_EOQ_SHIFT);
  u32PacketFlags |= (0U << UC_EMAC_DSC_FLAG_TDOWNCMPLT_SHIFT);
  u32PacketFlags |= (0U << UC_EMAC_DSC_FLAG_PASSCRC_SHIFT);
  uint8_t data[150];
  // insert destination mac address
  for (i = 0; i< 6; i++)
  {
    data[i] = 0xFFU;
  }
  // insert source mac address
  for (i = 0; i< 6; i++)
  {
    data[i+6] = 0xAAU;
  }
  // insert length
  data[12] = 0x00;
  data[13] = 80U;
  for (i = 0; i< 150; i++)
  {
    data[i+14] = i;
  }
  u32PacketFlagsPlusLength = u32PacketFlags | ((uint16_t)130);
  tempBufferDescriptor = UC_EMAC_strActiveNodeHelper.ActiveNode;

  tempBufferDescriptor->PacketFlagsAndLength &= (~((uint32_t)0xFFFFU));
  tempBufferDescriptor->PacketFlagsAndLength |= (uint32_t)(80U);
  tempBufferDescriptor->PacketFlagsAndLength |= (0x80000000U | 0x20000000U);
  tempBufferDescriptor->BufferOffsetAndLength = ((uint32_t)(80U) & 0xFFFFU);
//  uint32_t* pu32DataAdd = (uint32_t)&data[0];
  tempBufferDescriptor->pDataBuffer = (uint32_t)&data[0];
  tempBufferDescriptor->pstrNextBufferDescriptor = TAPAS_NULL;
  tempBufferDescriptor->PacketFlagsAndLength |= (0x40000000U);
//  tempBufferDescriptor->pDataBuffer = (uint32_t*)&data[0];
//  tempBufferDescriptor->PacketFlagsAndLength = u32PacketFlagsPlusLength;
//  tempBufferDescriptor->BufferOffsetAndLength = 80U;
   uint32_t* pu32DataAdd = (uint32_t*)&UC_EMAC_strActiveNodeHelper.ActiveNode;
   *(uint32_t*)0xFCF78600 = (uint32_t)*pu32DataAdd;
  //(UC_EMAC_strTransmitBufferDescriptorLinkedList->pstrNextBufferDescriptor) = (UC_EMAC_strBufferDescriptor_t*)(0xFC520010);
//  UC_EMAC_strTransmitBufferDescriptorLinkedList = (UC_EMAC_strBufferDescriptor_t*)(0xFC520000);
//  UC_EMAC_strTransmitBufferDescriptorLinkedList->pstrNextBufferDescriptor = TAPAS_NULL;
//  UC_EMAC_strTransmitBufferDescriptorLinkedList->pDataBuffer = &data[0];
//  UC_EMAC_strTransmitBufferDescriptorLinkedList->PacketFlagsAndLength = u32PacketFlagsPlusLength;
//  UC_EMAC_strTransmitBufferDescriptorLinkedList->BufferOffsetAndLength = 80U;
//  UC_EMAC_strHelperTransmit = UC_EMAC_strTransmitBufferDescriptorLinkedList;
//  UC_EMAC_TransmitBufferDescriptor.pDataBuffer = &data[0];
//  UC_EMAC_TransmitBufferDescriptor.BufferOffsetAndLength = 130U;
//  UC_EMAC_TransmitBufferDescriptor.PacketFlagsAndLength = u32PacketFlagsPlusLength;
//  UC_EMAC_TransmitBufferDescriptor.pstrNextBufferDescriptor = NULL;
//  *(uint32_t*)0xFCF78600 = (uint32_t)*UC_EMAC_strTransmitBufferDescriptorLinkedList;
//  EMACTxHdrDescPtrWrite(hdkif->emac_base, (uint32)(&UC_EMAC_strHelperTransmit), (uint32)EMAC_CHANNELNUMBER);
  return;
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf might be
 * chained. That is, one pbuf can span more than one tx buffer descriptors
 *
 * @param hdkif network interface structure
 * @param pbuf  the pbuf structure which contains the data to be sent using EMAC
 * @return boolean. 
 *        -Returns FALSE if a Null pointer was passed for transmission
 *        -Returns TRUE if valid data is sent and is transmitted.
 */
/* SourceId : ETH_SourceId_050 */
/* DesignId : ETH_DesignId_050*/
/* Requirements : HL_ETH_SR31 */
boolean EMACTransmit(hdkif_t *hdkif, pbuf_t *pbuf)
{
    
  txch_t *txch;
  pbuf_t *q;
  uint16 totLen;
  uint16 qLen;
  volatile emac_tx_bd_t *curr_bd,*active_head, *bd_end;
  boolean retValue = FALSE;
  if((pbuf != NULL) && (hdkif != NULL))
  {
  txch = &(hdkif->txchptr);

  /* Get the buffer descriptor which is free to transmit */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  curr_bd = txch->free_head;
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  bd_end = curr_bd;
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  active_head = curr_bd;

  /* Update the total packet length */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */       
  curr_bd->flags_pktlen &= (~((uint32)0xFFFFU));
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  totLen = pbuf->tot_len;
  curr_bd->flags_pktlen |= (uint32)(totLen);

  /* Indicate the start of the packet */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  curr_bd->flags_pktlen |= (EMAC_BUF_DESC_SOP | EMAC_BUF_DESC_OWNER);


  /* Copy pbuf information into TX buffer descriptors */
    q = pbuf;
    while(q != NULL)
    {
    /* Initialize the buffer pointer and length */
    /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "RHS is a pointer value required to be stored. - Advisory as per MISRA" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd->bufptr = (uint32)(q->payload);
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */
    qLen = q->len;
    curr_bd->bufoff_len = ((uint32)(qLen) & 0xFFFFU);
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */      
    bd_end = curr_bd;
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd = curr_bd->next;
    q = q->next;
    }


  /* Indicate the start and end of the packet */
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */       
  bd_end->next = NULL;
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  bd_end->flags_pktlen |= EMAC_BUF_DESC_EOP;

  /*SAFETYMCUSW 71 S MR:17.6 <APPROVED> "Assigned pointer value has required scope." */
  txch->free_head = curr_bd;

  /* For the first time, write the HDP with the filled bd */
  if(txch->active_tail == NULL) {
    /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "Address stored in pointer is passed as as an int parameter. - Advisory as per MISRA" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */      
    EMACTxHdrDescPtrWrite(hdkif->emac_base, (uint32)(active_head), (uint32)EMAC_CHANNELNUMBER);
  }

  /*
   * Chain the bd's. If the DMA engine, already reached the end of the chain,
   * the EOQ will be set. In that case, the HDP shall be written again.
   */
  else {
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd = txch->active_tail;
    /* Wait for the EOQ bit is set */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    while (EMAC_BUF_DESC_EOQ != (curr_bd->flags_pktlen & EMAC_BUF_DESC_EOQ))
    {
    }
    /* Don't write to TXHDP0 until it turns to zero */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    while (((uint32)0U != *((uint32 *)0xFCF78600U)))
    {
    }
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd->next = active_head;
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */      
    if (EMAC_BUF_DESC_EOQ == (curr_bd->flags_pktlen & EMAC_BUF_DESC_EOQ)) {
      /* Write the Header Descriptor Pointer and start DMA */
      /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "Address stored in pointer is passed as as an int parameter. - Advisory as per MISRA" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      EMACTxHdrDescPtrWrite(hdkif->emac_base, (uint32)(active_head), (uint32)EMAC_CHANNELNUMBER);
    }
  }
   
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  txch->active_tail = bd_end;
  retValue = TRUE;
  }
  else
  {
    retValue = FALSE;
  }
  return retValue;
}


/**
 * Function for processing Tx buffer descriptors.
 *
 * @param hdkif interface structure
 * @return none
 */
/* SourceId : ETH_SourceId_051 */
/* DesignId : ETH_DesignId_051*/
/* Requirements : HL_ETH_SR15 */
void EMACTxIntHandler(hdkif_t *hdkif)
{
  txch_t *txch_int;
  volatile emac_tx_bd_t *curr_bd, *next_bd_to_process;

  txch_int = &(hdkif->txchptr);

  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */        
  next_bd_to_process = txch_int->next_bd_to_process;
  
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */        
  curr_bd = next_bd_to_process;

  /* Check for correct start of packet */
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */        
  while(((curr_bd->flags_pktlen) & EMAC_BUF_DESC_SOP) == EMAC_BUF_DESC_SOP) {

    /* Make sure that the transmission is over */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    while(((curr_bd->flags_pktlen) & EMAC_BUF_DESC_OWNER) == EMAC_BUF_DESC_OWNER)
    {
    }

    /* Traverse till the end of packet is reached */
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    while(((curr_bd->flags_pktlen) & EMAC_BUF_DESC_EOP) != EMAC_BUF_DESC_EOP) {
       curr_bd = curr_bd->next;
    }

    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    next_bd_to_process->flags_pktlen &= ~(EMAC_BUF_DESC_SOP);
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd->flags_pktlen &= ~(EMAC_BUF_DESC_EOP);

    /**
     * If there are no more data transmitted, the next interrupt
     * shall happen with the pbuf associated with the free_head
     */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
    if(curr_bd->next == NULL) {
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */        
      txch_int->next_bd_to_process = txch_int->free_head;
    }

    else {
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */        
      txch_int->next_bd_to_process = curr_bd->next;
    }

    /* Acknowledge the EMAC and free the corresponding pbuf */
    /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "Address stored in pointer is passed as as an int parameter. - Advisory as per MISRA" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    /*SAFETYMCUSW 344 S MR:11.5 <APPROVED> "Address stored in pointer is passed as as an int parameter." */
    EMACTxCPWrite(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER, (uint32)curr_bd);
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    next_bd_to_process = txch_int->next_bd_to_process;
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    curr_bd = next_bd_to_process;

  }

}


/**
 * Function for processing received packets.
 *
 * @param hdkif interface structure
 * @return none
 */
/* SourceId : ETH_SourceId_052 */
/* DesignId : ETH_DesignId_052*/
/* Requirements : HL_ETH_SR31 */
void EMACReceive(hdkif_t *hdkif)
{
  rxch_t *rxch_int;
  volatile emac_rx_bd_t *curr_bd, *curr_tail, *last_bd;

  /* The receive structure that holds data about a particular receive channel */
  rxch_int = &(hdkif->rxchptr);

  /* Get the buffer descriptors which contain the earliest filled data */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  curr_bd = rxch_int->active_head;
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  last_bd = rxch_int->active_tail;

  /**
   * Process the descriptors as long as data is available
   * when the DMA is receiving data, SOP flag will be set
  */
  /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Hardware status bit read check" */
  /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
  /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
  while((curr_bd->flags_pktlen & EMAC_BUF_DESC_SOP) == EMAC_BUF_DESC_SOP) {


    /* Start processing once the packet is loaded */
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
    /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
    if((curr_bd->flags_pktlen & EMAC_BUF_DESC_OWNER)
       != EMAC_BUF_DESC_OWNER) {

      /* this bd chain will be freed after processing */
      /*SAFETYMCUSW 71 S MR:17.6 <APPROVED> "Assigned pointer value has required scope." */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */
      rxch_int->free_head = curr_bd;

      /* Get the total length of the packet. curr_bd points to the start
       * of the packet.
       */

      /* 
       * The loop runs till it reaches the end of the packet.
       */
      /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
      while((curr_bd->flags_pktlen & EMAC_BUF_DESC_EOP)!= EMAC_BUF_DESC_EOP)
      {
        /*Update the flags for the descriptor again and the length of the buffer*/
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        curr_bd->flags_pktlen = (uint32)EMAC_BUF_DESC_OWNER;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        curr_bd->bufoff_len = (uint32)MAX_TRANSFER_UNIT;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        last_bd = curr_bd;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        curr_bd = curr_bd->next;
      }

      /* Updating the last descriptor (which contained the EOP flag) */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */          
        curr_bd->flags_pktlen = (uint32)EMAC_BUF_DESC_OWNER;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        curr_bd->bufoff_len = (uint32)MAX_TRANSFER_UNIT;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        last_bd = curr_bd;
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        curr_bd = curr_bd->next;

      /* Acknowledge that this packet is processed */
      /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "Address stored in pointer is passed as as an int parameter. - Advisory as per MISRA" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      EMACRxCPWrite(hdkif->emac_base, (uint32)EMAC_CHANNELNUMBER, (uint32)last_bd);

      /* The next buffer descriptor is the new head of the linked list. */
      /*SAFETYMCUSW 71 S MR:17.6 <APPROVED> "Assigned pointer value has required scope." */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      rxch_int->active_head = curr_bd;

      /* The processed descriptor is now the tail of the linked list. */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      curr_tail = rxch_int->active_tail;
    /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      curr_tail->next = rxch_int->free_head;

      /* The last element in the already processed Rx descriptor chain is now the end of list. */
      /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */     
      last_bd->next = NULL;


        /**
         * Check if the reception has ended. If the EOQ flag is set, the NULL
         * Pointer is taken by the DMA engine. So we need to write the RX HDP
         * with the next descriptor.
         */
        /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */ 
        /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
      /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */            
        if((curr_tail->flags_pktlen & EMAC_BUF_DESC_EOQ) == EMAC_BUF_DESC_EOQ) {
          /*SAFETYMCUSW 439 S MR:11.3 <APPROVED> "Address stored in pointer is passed as as an int parameter. - Advisory as per MISRA" */
          /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */             
          EMACRxHdrDescPtrWrite(hdkif->emac_base, (uint32)(rxch_int->free_head), (uint32)EMAC_CHANNELNUMBER);
        }

        /*SAFETYMCUSW 71 S MR:17.6 <APPROVED> "Assigned pointer value has required scope." */
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are assigned in this driver" */   
        rxch_int->free_head  = curr_bd;
        rxch_int->active_tail = last_bd;
      }
    }
}


/** @fn void EMACGetConfigValue(emac_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the configuration registers
*
*   @param[in] *config_reg: pointer to the struct to which the initial or current 
*                           value of the configuration registers need to be stored
*   @param[in] type:    whether initial or current value of the configuration registers need to be stored
*                       - InitialValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*                       - CurrentValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*
*   This function will copy the initial or current value (depending on the parameter 'type') 
*   of the configuration registers to the struct pointed by config_reg
*
*/
/* SourceId : ETH_SourceId_053 */
/* DesignId : ETH_DesignId_053*/
/* Requirements : HL_ETH_SR52 */
void EMACGetConfigValue(emac_config_reg_t *config_reg, config_value_type_t type)
{
    if (type == InitialValue)
    {
        config_reg->TXCONTROL = EMAC_TXCONTROL_CONFIGVALUE;
        config_reg->RXCONTROL = EMAC_RXCONTROL_CONFIGVALUE;
        config_reg->TXINTMASKSET = EMAC_TXINTMASKSET_CONFIGVALUE;
        config_reg->TXINTMASKCLEAR = EMAC_TXINTMASKCLEAR_CONFIGVALUE;
        config_reg->RXINTMASKSET = EMAC_RXINTMASKSET_CONFIGVALUE;
        config_reg->RXINTMASKCLEAR = EMAC_RXINTMASKCLEAR_CONFIGVALUE;
        config_reg->MACSRCADDRHI = EMAC_MACSRCADDRHI_CONFIGVALUE;
        config_reg->MACSRCADDRLO = EMAC_MACSRCADDRLO_CONFIGVALUE;   
        config_reg->MDIOCONTROL = EMAC_MDIOCONTROL_CONFIGVALUE;
        config_reg->C0RXEN = EMAC_C0RXEN_CONFIGVALUE;
        config_reg->C0TXEN = EMAC_C0TXEN_CONFIGVALUE;
    }
    else
    {
        config_reg->TXCONTROL = HWREG(EMAC_0_BASE + EMAC_TXCONTROL);
        config_reg->RXCONTROL = HWREG(EMAC_0_BASE + EMAC_RXCONTROL);
        config_reg->TXINTMASKSET = HWREG(EMAC_0_BASE + EMAC_TXINTMASKSET);
        config_reg->TXINTMASKCLEAR = HWREG(EMAC_0_BASE + EMAC_TXINTMASKCLEAR);
        config_reg->RXINTMASKSET = HWREG(EMAC_0_BASE + EMAC_RXINTMASKSET);
        config_reg->RXINTMASKCLEAR = HWREG(EMAC_0_BASE + EMAC_RXINTMASKCLEAR);
        config_reg->MACSRCADDRHI = HWREG(EMAC_0_BASE + EMAC_MACSRCADDRHI);
        config_reg->MACSRCADDRLO = HWREG(EMAC_0_BASE + EMAC_MACSRCADDRLO);      
        config_reg->MDIOCONTROL = HWREG(MDIO_0_BASE + MDIO_CONTROL);
        config_reg->C0RXEN = HWREG(EMAC_CTRL_0_BASE + EMAC_CTRL_CnRXEN(0U));
        config_reg->C0TXEN = HWREG(EMAC_CTRL_0_BASE + EMAC_CTRL_CnTXEN(0U));
    }
    
}



/* USER CODE BEGIN (2) */
/* USER CODE END */

/***************************** End Of File ***********************************/
