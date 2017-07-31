/**
 * This file implements the transmitter module specific functionality - read sensor data and send it
 * over the wireless channel.
 * */


#ifndef _TRANSMITTER_H__
#define _TRANSMITTER_H__


#include "RF_Com.h"
#include "protocol.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/ADC.h>

// undefine when deploying
// #define TRANSMITTER_DEBUG
// time to wait between measurements
#define SLEEP_TIME 1000000/Clock_tickPeriod // 1 second
extern int32_t ec_value, tds_value,pH_value, sal_value;

/**
 * Initialize variables used in doTransmission
 * */
void transmitterInit ();


/**
 * Gets the measurement and sends to the reception module. Loops forever.
 * */
void doTransmission ();


#endif // _TRANSMITTER_H__
