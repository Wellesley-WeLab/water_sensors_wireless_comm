#include "transmitter.h"

/**
 * Read the last measurement available from the sensor. Loops forever.
 * @param data the buffer where to put the measurement paramenters. Should hava
 *             at least PACKET_LEN bytes of size
 * */
void readSensorData (uint8_t **data) {
    static int packetNo = 0;

    if (packetNo == (int) pow(2, PACKET_NO_FIELD_LEN*8)) {
        packetNo = 0;
#ifdef TRANSMITTER_DEBUG
        printf("[readSensorData] packet Number reinitialized\n");
#endif
    }

    int reservoirId  = THIS_RESERVOIR_ID;
    // TODO: read actual data
    int waterLevel   = 0;
    int vcc          = 0;
    int conductivity = 0;
    int salinity     = 0;
    int tds          = 0;
    int pH           = 0xffffffff;
    uint8_t *_data = *data;
    memset(_data, 0, PACKET_LEN);

    _data[0] = (packetNo >> 24) & 0xff;
    _data[1] = (packetNo >> 16) & 0xff;
    _data[2] = (packetNo >> 8)  & 0xff;
    _data[3] = packetNo         & 0xff;

    _data[4] = reservoirId & 0xff;

    _data[5] = (waterLevel >> 24) & 0xff;
    _data[6] = (waterLevel >> 16) & 0xff;
    _data[7] = (waterLevel >> 8)  & 0xff;
    _data[8] = waterLevel         & 0xff;

    _data[9]  = (vcc >> 24) & 0xff;
    _data[10] = (vcc >> 16) & 0xff;
    _data[11] = (vcc >> 8)  & 0xff;
    _data[12] = vcc         & 0xff;

    _data[13] = (conductivity >> 24) & 0xff;
    _data[14] = (conductivity >> 16) & 0xff;
    _data[15] = (conductivity >> 8)  & 0xff;
    _data[16] = conductivity         & 0xff;

    _data[17] = (salinity >> 24) & 0xff;
    _data[18] = (salinity >> 16) & 0xff;
    _data[19] = (salinity >> 8)  & 0xff;
    _data[20] = salinity         & 0xff;

    _data[21] = (tds >> 24) & 0xff;
    _data[22] = (tds >> 16) & 0xff;
    _data[23] = (tds >> 8)  & 0xff;
    _data[24] = tds         & 0xff;

    _data[25] = (pH >> 24) & 0xff;
    _data[26] = (pH >> 16) & 0xff;
    _data[27] = (pH >> 8)  & 0xff;
    _data[28] = pH         & 0xff;


    packetNo++;
}


void doTransmission () {
    uint8_t *data = malloc(PACKET_LEN);
    while (1) {
        readSensorData(&data);
        RFCom_init();
        RFCom_sendPacket(data, PACKET_LEN);
        Task_sleep(SLEEP_TIME);
    }
}
