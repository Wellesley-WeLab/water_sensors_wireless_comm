#include "transmitter.h"
#include "uart_ec_ezo.h"


#define ADC_SAMPLE_COUNT  (10)

int32_t ec_value=0, tds_value=0,pH_value=0, sal_value=0;
static ADC_Handle   adc, adc0;
static ADC_Params   adcParams;
static UART_Handle uart;
static UART_Params uartParams;


void transmitterInit () {
    UART_Params_init(&uartParams);

    uartParams.readTimeout = 2000000 / Clock_tickPeriod; //2 seconds; before UART_WAIT_FOREVER
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;

    uart = UART_open(Board_UART0, &uartParams);

    if (uart == NULL) {
#ifdef TRANSMITTER_DEBUG
        printf("[transmitterInit] failed to initialze UART driver");
#endif
      while (1);
    }

    EC_EZO_init (uart);

    ADC_Params_init(&adcParams);
    adc0 = ADC_open(Board_ADC0, &adcParams);
    if (adc0 == NULL) {
#ifdef TRANSMITTER_DEBUG
        printf("[transmitterInit] failed to initialize ADC channel 0");
#endif
        while (1);
    }
    adc = ADC_open(Board_ADC1, &adcParams);

    if (adc == NULL) {
#ifdef TRANSMITTER_DEBUG
        printf("[transmitterInit] failed to initialize ADC channel 1");
#endif
        while (1);
    }
}

/**
 * Read the last measurement available from the sensor.
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

    int waterLevel   = 13;
    int vcc          = 14;
    int conductivity = 15;
    int salinity     = 16;
    int tds          = 17;
    int pH           = 0xffffffff;
    uint8_t *_data = *data;
    memset(_data, 0, PACKET_LEN);

    int_fast16_t res, res0;
    uint16_t adcValue, adcValue0;
    uint32_t adcValue0MicroVolt, adcValueMicroVolt, meanValue=0, meanValue0=0;
    uint8_t j = 0;


    for (j=0; j <= ADC_SAMPLE_COUNT; j++){

        res =  ADC_convert(adc, &adcValue);
        res0 = ADC_convert(adc0, &adcValue0);
        ReadData_EC_EZ0(uart);

        if ((res == ADC_STATUS_SUCCESS)&&(res0 == ADC_STATUS_SUCCESS)) {

            adcValue0MicroVolt = ADC_convertRawToMicroVolts(adc0, adcValue0);
            meanValue0 += adcValue0MicroVolt;
            adcValueMicroVolt = ADC_convertRawToMicroVolts(adc, adcValue);
            meanValue += adcValueMicroVolt;

            if (j >= ADC_SAMPLE_COUNT) {
                meanValue0 = meanValue0 / ADC_SAMPLE_COUNT;
                meanValue = meanValue / ADC_SAMPLE_COUNT;

                conductivity=ec_value;
                tds=tds_value;
                salinity=sal_value;
                waterLevel=meanValue;
                vcc=meanValue0;

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

                meanValue = 0;
                meanValue0 = 0;
            }
        }
    }

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
