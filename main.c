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

#define RECEPTOR
//#define TRANSMITTER

#ifdef RECEPTOR
Void taskRx (UArg a, UArg b) {
    doReception(); // loops forever
}
#endif

#ifdef TRANSMITTER
Void taskTx (UArg a, UArg b) {
    transmitterInit();
    doTransmission(); // loops forever
}
#endif

int main (void) {
    Board_initGeneral();
#ifdef RECEPTOR
    ToServerCom_init();
#endif
#ifdef TRANSMITTER
    UART_init();
    ADC_init();
#endif
    
    Task_Params taskParams;
    Task_Params_init(&taskParams);
    taskParams.stackSize = TASK_STACK_SIZE;
    taskParams.stack     = &taskStack;
#ifdef RECEPTOR
    taskHandle           = Task_create(&taskRx, &taskParams, NULL);
#endif
#ifdef TRANSMITTER
    taskHandle           = Task_create(&taskTx, &taskParams, NULL);
#endif

    if (taskHandle == NULL) {
        printf("Unable to create taskRx");
        BIOS_exit(1);
    }

    BIOS_start();
    return 0;
}
