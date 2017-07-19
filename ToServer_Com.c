#include "ToServer_Com.h"



void ToServerCom_init () {
    UART_init();

    UART_Params params;
    UART_Params_init(&params);
    params.writeDataMode = UART_DATA_BINARY;
    params.readDataMode = UART_DATA_BINARY;
    params.readReturnMode = UART_RETURN_FULL;
    params.readEcho = UART_ECHO_OFF;
    params.baudRate = 9600;
    handle = UART_open(Board_UART0, &params);
    if (handle == NULL) {
#ifdef DEBUG_SRV_COM
        printf("[ToServerCom_write] failed to get UART handle\n");
#endif
    }
}


int ToServerCom_write (uint8_t *data, UInt len) {
    int nrBytes = UART_write(handle, data, len);
    if (nrBytes == UART_ERROR) {
#ifdef DEBUG_SRV_COM
        printf("[ToServerCom_write] failed to write data\n");
#endif
        return nrBytes;
    }

#ifdef DEBUG_SRV_COM
    printf("[ToServerCom_write] %d bytes out of %d have been written\n", nrBytes, len);
#endif

    return nrBytes;
}
