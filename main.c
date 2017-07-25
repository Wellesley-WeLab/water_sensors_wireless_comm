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
#include <string.h>

#include "Board.h"
#include "receptor.h"
#include "transmitter.h"

#define TASK_STACK_SIZE 2048

Task_Handle taskHandle;
static uint8_t taskStack[TASK_STACK_SIZE];


Void taskRx (UArg a, UArg b) {
    doReception(); // loops forever
}

Void taskTx (UArg a, UArg b) {
    doTransmission(); // loops forever
}

int main (void) {
    Board_initGeneral();
    ToServerCom_init();
    
    Task_Params taskParams;
    Task_Params_init(&taskParams);
    taskParams.stackSize = TASK_STACK_SIZE;
    taskParams.stack     = &taskStack;
    taskHandle           = Task_create(&taskTx, &taskParams, NULL);
    if (taskHandle == NULL) {
        printf("Unable to create taskRx");
        BIOS_exit(1);
    }

    BIOS_start();
    return 0;
}
