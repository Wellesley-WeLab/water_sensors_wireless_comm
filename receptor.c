#include "receptor.h"

void doReception () {
    RFCom_init();
    uint8_t *data = malloc(PACKET_LEN);

    while (1) {
        memset(data, 0, PACKET_LEN);
        int dataLen = RFCom_receivePacket(&data);
        if (dataLen != PACKET_LEN) {
#ifdef RECEPTOR_DEBUG
            printf("[taskRx] received invalid data: %d bytes\n", dataLen);
#endif
            continue;
        }
        ToServerCom_write(data, PACKET_LEN);
    }
}
