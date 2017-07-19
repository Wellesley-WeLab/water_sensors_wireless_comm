#include "RF_Com.h"

void RFCom_init () {

#ifdef DEBUG_RF_COM
    printf("[RFCom_init] Initializing transmission hardware\n");
#endif

    EasyLink_init(RF_COM_CONF);
    EasyLink_setRfPwr(RF_COM_POWER);
}


void RFCom_sendPacket (uint8_t *packet, UInt packetSize) {
    if (packet == NULL) {
#ifdef DEBUG_RF_COM
        printf("[RFCom_sendPacket] null packet\n");
#endif
        return;
    }
    // nr of packets into which the main packet needs to be split
    UInt nrOfPackets = (UInt) ceil(((double)(packetSize))/((double)(RF_COM_MAX_PACKET_SIZE)));

#ifdef DEBUG_RF_COM
    printf("[RFCom_sendPacket] sending %d packet(s)\n", nrOfPackets);
#endif

    // the current byte to send in packet
    int mainPacketCurrentPos = 0, i = 0;

    EasyLink_TxPacket txPacket = {
        {0}, // address of the destination
        0, // absolute time at which we send the packet. 0 => immediate
        RF_COM_MAX_PACKET_SIZE, // size of the data
        {0} // data
    };

    // sending the packets
    for (i = 0; i < nrOfPackets && mainPacketCurrentPos < packetSize; i++) {
        // set the current packet to send
        int k = 0;
        memset(txPacket.payload, 0, RF_COM_MAX_PACKET_SIZE);
        while (k < RF_COM_MAX_PACKET_SIZE && mainPacketCurrentPos < packetSize)
            txPacket.payload[k++] = packet[mainPacketCurrentPos++];

        EasyLink_Status result = EasyLink_transmit(&txPacket); // blocks until it's done
        if (result == EasyLink_Status_Success) {
#ifdef DEBUG_RF_COM
            printf("[RFCom_sendPacket] sent:  %s\n", txPacket.payload);
#endif
        } else {
#ifdef DEBUG_RF_COM
            printf("[RFCom_sendPacket] failed to send packet. Status: %d\n", result);
#endif
        }
    }
#ifdef DEBUG_RF_COM
    printf("[RFCom_sendPacket] sent %d packets\n", nrOfPackets);
#endif

}

int RFCom_receivePacket (uint8_t **packetPtr) {
    if (packetPtr == NULL) {
#ifdef DEBUG_RF_COM
        printf("[RFCom_receivePacket] null packetPtr");
#endif
    }

    uint8_t *packet = *packetPtr;
    EasyLink_RxPacket rxPacket = {0};
    EasyLink_Status result = EasyLink_receive(&rxPacket); // blocks until it's done
    if (result == EasyLink_Status_Success) {
        memcpy(packet, rxPacket.payload, EASYLINK_MAX_DATA_LENGTH);
#ifdef DEBUG_RF_COM
        printf("[RFCom_receivePacket] received %d bytes of data\n", rxPacket.len);
        printf("[RFCom_receivePacket] received %s\n", packet);
#endif
        return (int) rxPacket.len;
    } else {
#ifdef DEBUG_RF_COM
        printf("[RFCom_receivePacket] failed to receive packet. Status %d\n", result);
#endif
        return -1;
    }
}
