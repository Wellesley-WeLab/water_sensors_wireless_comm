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

#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>

// undefine when deploying
#define TRANSMITTER_DEBUG
// time to wait between measurements
#define SLEEP_TIME 1000000/Clock_tickPeriod // 1 second

/**
 * Gets the measurement and sends to the reception module. Loops forever.
 * */
void doTransmission ();


#endif // _TRANSMITTER_H__
