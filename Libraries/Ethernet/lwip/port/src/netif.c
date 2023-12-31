/**
 * \file netif.c
 * \brief Source file of lwIP low level and netif functions
 *
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/**
 * This file is a skeleton for developing Ethernet network interface
 * drivers for lwIP. Add code to the low_level functions and do a
 * search-and-replace for the word "ethernetif" to replace it with
 * something that better describes your network interface.
 */

#include "lwip/opt.h"

#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include <lwip/stats.h>
#include <lwip/snmp.h>
#include "netif/etharp.h"
#include "netif/ppp/pppoe.h"

#include "IfxGeth_Eth.h"
#include "Ifx_Lwip.h"
#include "Ifx_Netif.h"
#include "IfxGeth_Phy_Rtl8211f.h"
#include "Configuration.h"
#include <string.h>

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
struct ethernetif
{
    eth_addr_t *ethaddr;
    /* Add whatever per-interface state that is needed here. */
};

/* pin configuration RTL8211F */
const IfxGeth_Eth_RgmiiPins rtl8211f_pins = {
                                   .txClk = &ETH_TXCLK_PIN,     /* TXCLK */
                                   .txd0 = &ETH_TXD0_PIN,       /* TXD0 */
                                   .txd1 = &ETH_TXD1_PIN,       /* TXD1 */
                                   .txd2 = &ETH_TXD2_PIN,       /* TXD2 */
                                   .txd3 = &ETH_TXD3_PIN,       /* TXD3 */
		                           .txCtl = &ETH_TXCTL_PIN,     /* TXCTL */
		                           .rxClk = &ETH_RXCLK_PIN,     /* RXCLK */
                                   .rxd0 = &ETH_RXD0_PIN,       /* RXD0 */
								   .rxd1 = &ETH_RXD1_PIN,       /* RXD1 */
								   .rxd2 = &ETH_RXD2_PIN,       /* RXD2 */
								   .rxd3 = &ETH_RXD3_PIN,       /* RXD3 */
								   .rxCtl = &ETH_RXCTL_PIN,     /* RXCTL */
                                   .mdc = &ETH_MDC_PIN,         /* MDC */
                                   .mdio = &ETH_MDIO_PIN,       /* MDIO */
		                           .grefClk = &ETH_GREFCLK_PIN  /* GREFCLK */
};

/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void low_level_init(netif_t *netif)
{
	IfxGeth_Eth *ethernetif = netif->state;
    int     i;

    /* set MAC hardware address length */
    netif->hwaddr_len = ETHARP_HWADDR_LEN;

    /* set MAC hardware address */
    for (i = 0; i < ETHARP_HWADDR_LEN; i++)
    {
        netif->hwaddr[i] = g_Lwip.eth_addr.addr[i];
    }

    /* maximum transfer unit */
    netif->mtu = 1500;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    /* we don't set the LINK_UP flag because we don't say when it is linked */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_IGMP;

    /* Do whatever else is needed to initialize interface. */
    {
    	IfxGeth_Eth_Config GethConfig;

    	IfxGeth_Eth_initModuleConfig(&GethConfig, &MODULE_GETH);
   		// this is our RTL8211F
   		GethConfig.phyInterfaceMode = IfxGeth_PhyInterfaceMode_rgmii;
        GethConfig.pins.rgmiiPins = &rtl8211f_pins;
       	GethConfig.mac.lineSpeed = IfxGeth_LineSpeed_100Mbps;
    	// MAC core configuration
    	GethConfig.mac.loopbackMode = IfxGeth_LoopbackMode_disable;
    	GethConfig.mac.macAddress[0] = netif->hwaddr[0];
    	GethConfig.mac.macAddress[1] = netif->hwaddr[1];
    	GethConfig.mac.macAddress[2] = netif->hwaddr[2];
    	GethConfig.mac.macAddress[3] = netif->hwaddr[3];
    	GethConfig.mac.macAddress[4] = netif->hwaddr[4];
    	GethConfig.mac.macAddress[5] = netif->hwaddr[5];

    	// MTL configuration
    	GethConfig.mtl.numOfTxQueues = 1;
    	GethConfig.mtl.numOfRxQueues = 1;
    	GethConfig.mtl.txQueue[0].txQueueSize = IfxGeth_QueueSize_2560Bytes;
    	GethConfig.mtl.txQueue[0].storeAndForward = TRUE;
    	GethConfig.mtl.rxQueue[0].rxQueueSize = IfxGeth_QueueSize_2560Bytes;
    	GethConfig.mtl.rxQueue[0].rxDmaChannelMap = IfxGeth_RxDmaChannel_0;
    	GethConfig.mtl.rxQueue[0].storeAndForward = TRUE;

    	GethConfig.dma.numOfTxChannels = 1;
    	GethConfig.dma.numOfRxChannels = 1;
    	GethConfig.dma.txChannel[0].channelId = IfxGeth_TxDmaChannel_0;
    	GethConfig.dma.txChannel[0].txDescrList = (IfxGeth_TxDescrList*)&IfxGeth_Eth_txDescrList[0];
    	GethConfig.dma.txChannel[0].txBuffer1StartAddress = (uint32 *)&channel0TxBuffer1[0][0]; // user buffer
    	GethConfig.dma.txChannel[0].txBuffer1Size = IFXGETH_MAX_TX_BUFFER_SIZE; // used to calculate the next descriptor  buffer offset

    	GethConfig.dma.rxChannel[0].channelId = IfxGeth_RxDmaChannel_0;
    	GethConfig.dma.rxChannel[0].rxDescrList = (IfxGeth_RxDescrList *)&IfxGeth_Eth_rxDescrList[0];
    	GethConfig.dma.rxChannel[0].rxBuffer1StartAddress = (uint32 *)&channel0RxBuffer1[0][0]; // user buffer
    	GethConfig.dma.rxChannel[0].rxBuffer1Size = IFXGETH_MAX_RX_BUFFER_SIZE; // user defined variable

    	IfxSrc_Tos gethIsrProvider;

        if (CPU_WHICH_SERVICE_ETHERNET) gethIsrProvider = (IfxSrc_Tos)(CPU_WHICH_SERVICE_ETHERNET+1);
        else  gethIsrProvider = (IfxSrc_Tos)CPU_WHICH_SERVICE_ETHERNET;

    	GethConfig.dma.txInterrupt[0].channelId = IfxGeth_DmaChannel_0;
    	GethConfig.dma.txInterrupt[0].priority = ISR_PRIORITY_GETH_TX;	// priority
    	GethConfig.dma.txInterrupt[0].provider = gethIsrProvider;
    	GethConfig.dma.rxInterrupt[0].channelId = IfxGeth_DmaChannel_0;
    	GethConfig.dma.rxInterrupt[0].priority = ISR_PRIORITY_GETH_RX;	// priority
    	GethConfig.dma.rxInterrupt[0].provider = gethIsrProvider;


    	/* first we reset our phy manually, to make sure that the phy is ready when we init our module */
        {
        	IfxGeth_enableModule(&MODULE_GETH);
        	IfxPort_setPinModeOutput(ETH_MDC_PIN.pin.port, ETH_MDC_PIN.pin.pinIndex, IfxPort_OutputMode_pushPull, ETH_MDC_PIN.select);
            GETH_GPCTL.B.ALTI0  = ETH_MDIO_PIN.inSelect;

            while (GETH_MAC_MDIO_ADDRESS.B.GB) {};
            // first we wait that we are able to communicate with the Phy
            do
            {
            	GETH_MAC_MDIO_ADDRESS.U = (0 << 21) | (0 << 16) | (0 << 8) | (3 << 2) | (1 << 0);
                while (GETH_MAC_MDIO_ADDRESS.B.GB) {};
            } while (GETH_MAC_MDIO_DATA.U & 0x8000);                                                      // wait for reset to finish
            // reset PHY
            // put data
        	GETH_MAC_MDIO_DATA.U = 0x8000;
            GETH_MAC_MDIO_ADDRESS.U = (0 << 21) | (0 << 16) | (0 << 8) |  (1 << 2) | (1 << 0);
            while (GETH_MAC_MDIO_ADDRESS.B.GB) {};

            do
            {
            	GETH_MAC_MDIO_ADDRESS.U = (0 << 21) | (0 << 16) | (0 << 8) | (3 << 2) | (1 << 0);
                while (GETH_MAC_MDIO_ADDRESS.B.GB) {};
            } while (GETH_MAC_MDIO_DATA.U & 0x8000);                                                      // wait for reset to finish
        }

        // initialize the module
    	IfxGeth_Eth_initModule(ethernetif, &GethConfig);

   		IfxGeth_Eth_Phy_Rtl8211f_init();

    	// and enable transmitter/receiver
    	IfxGeth_Eth_startTransmitters(ethernetif, 1);
    	IfxGeth_Eth_startReceivers(ethernetif, 1);

    	// The ETH is ready for use now!
        /* we set the LINK_UP flag if we have a valid link */
    	if (GETH_MAC_PHYIF_CONTROL_STATUS.B.LNKSTS == 1)
    	{
    		// we have a valid link
    		netif->flags |= NETIF_FLAG_LINK_UP;
    		// we set the correct duplexMode
    		if (GETH_MAC_PHYIF_CONTROL_STATUS.B.LNKMOD == 1)
    			IfxGeth_mac_setDuplexMode(ethernetif->gethSFR, IfxGeth_DuplexMode_fullDuplex);
    		else
    			IfxGeth_mac_setDuplexMode(ethernetif->gethSFR, IfxGeth_DuplexMode_halfDuplex);
    		// we set the correct speed
    		if (GETH_MAC_PHYIF_CONTROL_STATUS.B.LNKSPEED == 0)
    			// 10MBit speed
    			IfxGeth_mac_setLineSpeed(ethernetif->gethSFR, IfxGeth_LineSpeed_10Mbps);
    		else
        		if (GETH_MAC_PHYIF_CONTROL_STATUS.B.LNKSPEED == 1)
        			// 100MBit speed
        			IfxGeth_mac_setLineSpeed(ethernetif->gethSFR, IfxGeth_LineSpeed_100Mbps);
        		else
        			// 1000MBit speed
        			IfxGeth_mac_setLineSpeed(ethernetif->gethSFR, IfxGeth_LineSpeed_1000Mbps);
    	}
    }
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */
static err_t low_level_output(netif_t *netif, pbuf_t *p)
{
	IfxGeth_Eth      *ethernetif = netif->state;
    struct pbuf *q;

    u16_t        length = p->tot_len;
    LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("low_level_output (p=%#x)\n", p));

#if ETH_PAD_SIZE
    pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif

    if ((p->type_internal == PBUF_REF) || (p->type_internal == PBUF_ROM))
    {
        // if PBUF_REF or PBUF_ROM, no copy into ethernet RAM buffer is needed.
        // see pbuf_alloc_special()
    	IfxGeth_Eth_sendTransmitBuffer(ethernetif, p->tot_len, IfxGeth_TxDmaChannel_0);
    }
    else
    {
        //initiate transfer();
        u8_t *tbuf = IfxGeth_Eth_waitTransmitBuffer(ethernetif, IfxGeth_TxDmaChannel_0);
        u16_t l    = 0;

        for (q = p; q != NULL; q = q->next)
        {
            /* Send the data from the pbuf to the interface, one pbuf at a
             * time. The size of the data in each pbuf is kept in the ->len
             * variable. */
            memcpy((u8_t *)&tbuf[l], q->payload, q->len);
            l = l + q->len;
            LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("low_level_output: data=%#x, %d\n", q->payload, q->len));
            LWIP_ASSERT("low_level_output: length overflow the buffer\n", (l < 2048));
        }
        /* we correct the buffer 1 size (maybe overwritten in earlier packet */
        IfxGeth_TxDescr *pactTxDescriptor;
        pactTxDescriptor = (IfxGeth_TxDescr *)IfxGeth_Eth_getActualTxDescriptor(ethernetif, IfxGeth_TxDmaChannel_0);
        /* set the buffer length to the max. available */
        pactTxDescriptor->TDES2.R.B1L = IFXGETH_MAX_TX_BUFFER_SIZE;
		IfxGeth_Eth_sendTransmitBuffer(ethernetif, l, IfxGeth_TxDmaChannel_0);
    }

    LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("low_level_output: signal length: %d\n", length));

#if ETH_PAD_SIZE
    pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

    LINK_STATS_INC(link.xmit);

    LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("low_level_output: return OK\n"));

    return ERR_OK;
}

static uint16 GetRxFrameSize(IfxGeth_RxDescr *descr)
{
  uint16 len;

  uint32 rdes3 = descr->RDES3.U;
  uint32 rdes1 = descr->RDES1.U;

  if (((rdes3 & (1UL << 15)) != 0U) ||
	  ((rdes1 & (1UL << 7)) != 0U) ||
	  ((rdes3 & (1UL << 28)) == 0U))
  {
	/* Error, this block is invalid */
	len = 0xFFFFU;
  }
  else
  {
    /* Subtract CRC */
	len = (rdes3 & 0x7FFF) - 4U;
  }

  return len;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static pbuf_t *low_level_input(netif_t *netif)
{
	IfxGeth_Eth *ethernetif = netif->state;
    pbuf_t *p, *q;
    u16_t   len;

    len = 0;
    if (IfxGeth_Eth_isRxDataAvailable(ethernetif, IfxGeth_RxDmaChannel_0) != FALSE)
    {
        len = GetRxFrameSize((IfxGeth_RxDescr *)IfxGeth_Eth_getActualRxDescriptor(ethernetif, IfxGeth_RxDmaChannel_0));
    }

    if (len == 0)
    {
        return (pbuf_t *)0;
    }

#if ETH_PAD_SIZE
    len += ETH_PAD_SIZE; /* allow room for Ethernet padding */
#endif

    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

    if (p != NULL)
    {
#if ETH_PAD_SIZE
        pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif

        u8_t *src = IfxGeth_Eth_getReceiveBuffer(ethernetif, IfxGeth_RxDmaChannel_0);

        /* We iterate over the pbuf chain until we have read the entire
         * packet into the pbuf. */
        for (q = p; ((q != NULL) && (src != NULL)); q = q->next)
        {
            /* Read enough bytes to fill this pbuf in the chain. The
             * available data in the pbuf is given by the q->len
             * variable.
             * This does not necessarily have to be a memcpy, you can also preallocate
             * pbufs for a DMA-enabled MAC and after receiving truncate it to the
             * actually received size. In this case, ensure the tot_len member of the
             * pbuf is the sum of the chained pbuf len members.
             */
            //read data into(q->payload, q->len);
            memcpy(q->payload, src, q->len);
            src = &src[q->len];

            LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("low_level_input: payload=0x%x, len=%d\n", q->payload, q->len));
        }

        //acknowledge that packet has been read();
        IfxGeth_Eth_freeReceiveBuffer(ethernetif, IfxGeth_RxDmaChannel_0);

#if ETH_PAD_SIZE
        pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

        LINK_STATS_INC(link.recv);
    }
    else
    {
        //TODO: drop packet();
        LINK_STATS_INC(link.memerr);
        LINK_STATS_INC(link.drop);
    }

    return p;
}


/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
err_t ifx_netif_input(netif_t *netif)
{
    //Ifx_GETH *ethernetif = netif->state;
    eth_hdr_t *ethhdr;
    pbuf_t    *p;

    /* move received packet into a new pbuf */
    p = low_level_input(netif);

    /* no packet could be read, silently ignore this */
    if (p == NULL)
    {
        //LWIP_DEBUGF(NETIF_DEBUG, ("ifx_netif_input: p == NULL!\n"));
        return ERR_OK;
    }

    /* points to packet payload, which starts with an Ethernet header */
    ethhdr = p->payload;

    switch (htons(ethhdr->type))
    {
    /* IP or ARP packet? */
    case ETHTYPE_IP:
    case ETHTYPE_ARP:
    case ETHTYPE_VLAN:
#if PPPOE_SUPPORT
    /* PPPoE packet? */
    case ETHTYPE_PPPOEDISC:
    case ETHTYPE_PPPOE:
#endif /* PPPOE_SUPPORT */

        /* full packet send to tcpip_thread to process */
        if (netif->input(p, netif) != ERR_OK)
        {
            LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_STATE, ("ifx_netif_input: IP input error\n"));
            pbuf_free(p);
            p = NULL;
        }

        break;

    default:
        LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_STATE, ("ifx_netif_input: type unknown\n"));
        pbuf_free(p);
        p = NULL;
        break;
    }

    return ERR_OK;
}


/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t ifx_netif_init(netif_t *netif)
{
	IfxGeth_Eth *ethernetif;

    LWIP_ASSERT("netif != NULL", (netif != NULL));
    LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE, ("ifx_netif_init ( %#x)\n", netif));

    ethernetif = IfxGeth_get();

    if (ethernetif == NULL)
    {
        LWIP_DEBUGF(NETIF_DEBUG, ("ifx_netif_init: out of memory\n"));
        return ERR_MEM;
    }

#if LWIP_NETIF_HOSTNAME
    /* Initialize interface hostname */
    netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

    /*
     * Initialize the snmp variables and counters inside the struct netif.
     * The last argument should be replaced with your link speed, in units
     * of bits per second.
     */
    //NETIF_INIT_SNMP(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);

    netif->state      = ethernetif;
    netif->name[0]    = IFNAME0;
    netif->name[1]    = IFNAME1;
    /* We directly use etharp_output() here to save a function call.
     * You can instead declare your own function an call etharp_output()
     * from it if you have to do some checks before sending (e.g. if link
     * is available...) */
    netif->output     = etharp_output;
    netif->linkoutput = low_level_output;

    /* initialize the hardware */
    low_level_init(netif);

    return ERR_OK;
}
