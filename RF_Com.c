#include "RF_Com.h"

void RFCom_init () {

#ifdef DEBUG_RF_COM
    printf("[RFCom_init] Initializing transmission hardware\n");
#endif

    EasyLink_init(RF_COM_CONF);
    EasyLink_setRfPwr(RF_COM_POWER);
}

void printHexString (uint8_t *string) {
    uint8_t *s = string;
    printf("0x");
    while (*s) {
        printf("%02x", *s++);
    }
    printf("\n");
}


void RFCom_sendPacket (uint8_t *packet, UInt packetSize) {

    if (packet == NULL) {
#ifdef DEBUG_RF_COM
        printf("[RFCom_sendPacket] null packet\n");
#endif
        return;
    }
    else if (packetSize > RF_COM_MAX_PACKET_SIZE) {
#ifdef DEBUG_RF_COM
        printf("[RFCom_sendPacket] packet too big. Max size supported is %d\n", RF_COM_MAX_PACKET_SIZE);
#endif
        return;
    }

    EasyLink_TxPacket txPacket = {
        {0}, // address of the destination
        0, // absolute time at which we send the packet. 0 => immediate
        packetSize, // size of the data
        {0} // data
    };

    // set the data to send
    memcpy(txPacket.payload, packet, packetSize);

    EasyLink_Status result = EasyLink_transmit(&txPacket); // blocks until it's done

    if (result == EasyLink_Status_Success) {
#ifdef DEBUG_RF_COM
        printf("[RFCom_sendPacket] packet sent\n");
#endif
    } else {
#ifdef DEBUG_RF_COM
        printf("[RFCom_sendPacket] failed to send packet. Status: %d\n", result);
#endif
    }

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
        memcpy(packet, rxPacket.payload, rxPacket.len);
#ifdef DEBUG_RF_COM
        printf("[RFCom_receivePacket] received %d bytes of data\n", rxPacket.len);
        printf("[RFCom_receivePacket] received ");
        int i = 0;
        while (i < rxPacket.len) {
            printf("%02x", packet[i++]);
        }
        printf("\n");
#endif
        return (int) rxPacket.len;
    } else {
#ifdef DEBUG_RF_COM
        printf("[RFCom_receivePacket] failed to receive packet. Status %d\n", result);
#endif
        return -1;
    }
}
