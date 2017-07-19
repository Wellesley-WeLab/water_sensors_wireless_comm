
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Log.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>


#include <ti/drivers/PIN.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/ADC.h>


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Board.h"
#include "easylink/EasyLink.h"
#include "RF_Com.h"
#include "ToServer_Com.h"



#define TASK_RX_STACK_SIZE 1024
#define TASK_RX_PRIO       2

Task_Handle taskHandle;
static uint8_t taskRxStack[TASK_RX_STACK_SIZE];


/**
 * Receives data from the wireless channel and delivers it over serial
 * to server.
 * */
Void taskRx (UArg a, UArg b) {
    RFCom_init();
    const int dataSize = 128;
    uint8_t *data = malloc(dataSize);

    printf("[taskRx] start loop");
    while (1) {
        memset(data, 0, dataSize);
        int dataLen = RFCom_receivePacket(&data);
        ToServerCom_write(data, 31);
    }
}


int main (void) {
    Board_initGeneral();
    ToServerCom_init();
    
    Task_Params taskParams;
    Task_Params_init(&taskParams);
    taskParams.stackSize = TASK_RX_STACK_SIZE;
    taskParams.stack     = &taskRxStack;
    taskHandle           = Task_create(&taskRx, &taskParams, NULL);
    if (taskHandle == NULL) {
        printf("Unable to create taskRx");
        BIOS_exit(1);
    }

    BIOS_start();
    return 0;
}
