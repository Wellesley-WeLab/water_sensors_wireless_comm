/**
 * Definitions of the functions to communicate the reception
 * side with the server that saves the data.
 * The communication with the server is done using UART.
 */

#ifndef _TOSERVER_COM__
#define _TOSERVER_COM__

#include <ti/drivers/UART.h>
#include <xdc/runtime/Log.h>
#include <stdio.h>

#include "util.h"
#include "Board.h"

// #define DEBUG_SRV_COM

/* parameters the configure the UART driver */
static UART_Params params;
/* to use the UART device */
static UART_Handle handle;


/**
 * To initialize the UART driver. Should be called before any ohter function in this module.
 */
void ToServerCom_init ();

/**
 * Write data to the server, with UART.
 * @param data the bytes to send
 * @param len the number of bytes in data
 * @return the number of bytes that have been written
 *
 */
int ToServerCom_write (uint8_t *data, UInt len);


#endif // _TOSERVER_COM__
