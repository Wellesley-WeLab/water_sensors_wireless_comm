/*
 * uart_ec_ezo.c
 *
 *  Created on: 07/07/2017
 *      Author: Sónia
 */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <string.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>


/* Example/Board Header files */
#include "Board.h"
#include "uart_ec_ezo.h"
#include "transmitter.h"


//extern int32_t ret,ec_value, tds_value,pH_value, sal_value;

int32_t UART_readUntil(UART_Handle handle, char *buffer, size_t size, char stopChar){
    int32_t ret=0;
    size_t i=0;
    char ch;

    while(i<size){
        ret = UART_read(handle, &ch, 1);
        if (ret!=1 || ch==13) break;
        buffer[i]=ch;
        i++;
    }
    buffer[i]='\0';

    return i;
}

int32_t UART_readUntilOK(UART_Handle handle){
    int32_t ret=0;
    char buffer[40]={0};
    while (1) {
        ret = UART_readUntil(handle, buffer, 40, 13);
        if ((ret==0) || (ret==3 && buffer[0]=='*' && buffer[1]=='O' && buffer[2]=='K')) break;
    }
    return ret;
}

int32_t EC_EZO_init (UART_Handle handle){

    int32_t ret=0;
    // Initialize Read/Write UART, clear buffer
    UART_write(handle, EC_EZO_CR, sizeof(EC_EZO_CR));
//    Task_sleep(500000/Clock_tickPeriod);
    ret = UART_readUntilOK(handle);
    if (ret==0) while ((ret = UART_readUntilOK(handle))!=0);

 /*   // calibration

    for (i = 0; i < 5; i++){
        UART_write(uart, EC_EZO_PROBE_CAL_DRY, sizeof(EC_EZO_PROBE_CAL_DRY));
        ret = UART_readUntilOK(uart);
    }
    for (i = 0; i < 5; i++){
        UART_write(uart, EC_EZO_PROBE_CAL_LOW, sizeof(EC_EZO_PROBE_CAL_LOW));
        ret = UART_readUntilOK(uart);
    }
    for (i = 0; i < 5; i++){
        UART_write(uart, EC_EZO_PROBE_CAL_HIGH, sizeof(EC_EZO_PROBE_CAL_HIGH));
        ret = UART_readUntilOK(uart);
    }
*/    // end calibration

    UART_write(handle, EC_EZO_RESP_ON, sizeof(EC_EZO_RESP_ON));
    ret = UART_readUntilOK(handle);

    UART_write(handle, EC_EZO_PROBE_K0_1, sizeof(EC_EZO_PROBE_K0_1));
    ret = UART_readUntilOK(handle);

    UART_write(handle, EC_EZO_CRMODE_OFF, sizeof(EC_EZO_CRMODE_OFF));
    ret = UART_readUntilOK(handle);

    UART_write(handle, EC_EZO_OEC_ON, sizeof(EC_EZO_OEC_ON));
    ret = UART_readUntilOK(handle);
    UART_write(handle, EC_EZO_OTDS_ON, sizeof(EC_EZO_OTDS_ON));
    ret = UART_readUntilOK(handle);
    UART_write(handle, EC_EZO_OSAL_ON, sizeof(EC_EZO_OSAL_ON));
    ret = UART_readUntilOK(handle);
    UART_write(handle, EC_EZO_OSG_ON, sizeof(EC_EZO_OEC_ON));
    ret = UART_readUntilOK(handle);
    if (ret==0) {
        /* Error */
        while(1);
    }
}

//  read data from quality sensor
void ReadData_EC_EZ0 (UART_Handle handle){
    char *pch;
    int32_t ret=0; // ec_value=0, tds_value=0,pH_value=0, sal_value=0;
    int32_t sg_value=0; //maybe will be needed
    int i, ECDATA_LENGTH = 40;
    char input[40]={0};
    char input_data[40]={0};


    UART_write(handle, EC_EZO_SRMODE, sizeof(EC_EZO_SRMODE));
    ret = UART_readUntil(handle, input, sizeof(input), 13);
    if (ret>0 && input[0]=='*')
        ret = UART_readUntil(handle, input, sizeof(input), 13);
    if (ret>4) {
        for (i=0; i<ECDATA_LENGTH; i++) input_data[i] = input[i];
    }
    ec_value = 1000 * atof(input_data);
    pch = strchr(input_data,',');
    if (pch!=NULL) {
        pch++; //jump comma
        tds_value = 1000 * atof(pch);
        pch = strchr(pch,',');

        if (pch!=NULL) {
            pch++; //jump comma
            sal_value = 1000 * atof(pch);
            pch = strchr(pch,',');

            if (pch!=NULL) {
                pch++; //jump comma
                sg_value = 1000 * atof(pch);
            }
        }
    }

}

