#ifndef _RF_COM_H__
#define _RF_COM_H__

#include "easylink/EasyLink.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

/* configuration (frequency and modulation) for the hardware */
#define RF_COM_CONF EasyLink_Phy_50kbps2gfsk
/* power configuration to use */
#define RF_COM_POWER 14 // dB
/* max data size to send each time */
#define RF_COM_MAX_PACKET_SIZE EASYLINK_MAX_DATA_LENGTH // bytes

#define DEBUG_RF_COM

/* main funcions */
/** To initialize the hardware. should be called before any send/receive operation */
void RFCom_init ();
/**
 * @param packet the data packet to send
 * @param packetSize the size, in bytes, of packet
 * */
void RFCom_sendPacket (uint8_t *packet, UInt paketSize);
/**
 * @param packetPtr pointer to a memory location where to put the data.
 *        The allocated size should be at least 128 bytes
 * @return nr of bytes returned. -1 if error
 * */
int RFCom_receivePacket (uint8_t **packetPtr);

#endif // _RF_COM_H__
