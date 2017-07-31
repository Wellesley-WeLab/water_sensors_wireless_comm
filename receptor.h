/**
 * This file implements the reception module specific functionality - receive data and send to server
 * */

#ifndef _RECEPTOR_H__
#define _RECEPTOR_H__

#include "RF_Com.h"
#include "ToServer_Com.h"
#include "protocol.h"

#include <stdio.h>
#include <stdlib.h>

// undefine when deploying
// #define RECEPTOR_DEBUG

/**
 * Loops infinitly, receiving data and sending it to server.
 * */
void doReception ();


#endif // _RECEPTOR_H__
