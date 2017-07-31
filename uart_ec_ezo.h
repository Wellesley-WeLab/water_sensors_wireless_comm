/*
 * uart_ec_ezo.h
 *
 *  Created on: 06/07/2017
 *      Author: Sónia
 */

#include <ti/drivers/UART.h>
#include "ToServer_Com.h"

#ifndef UART_EC_EZO_H_
#define UART_EC_EZO_H_

#ifdef __cplusplus
extern "C" {
#endif


// baud rate
static const char  EC_EZO_BAUD_9600[] = {'B','a','u','d',',','9','6','0','0',13};
static const char  EC_EZO_BAUD_115200[]={'B','a','u','d',',','1','1','5','2','0','0',13};
static const char  EC_EZO_BAUD_STATUS[]={'B','a','u','d',',','?',13};

// continuous reading mode
static const char  EC_EZO_CRMODE_ON[]  =  {'C',',','1',13}; // enable continuous read
static const char  EC_EZO_CRMODE_OFF[] =  {'C',',','0',13}; // disable continuous read
static const char  EC_EZO_CRMODE_STATUS[]={'C',',','?',13}; // reading mode status

// single reading mode
static const char  EC_EZO_SRMODE[] = {'R',13}; // single read

//  led control
static const char  EC_EZO_LED_ON[] ={'L',',','1',13}; // led on
static const char  EC_EZO_LED_OFF[]={'L',',','0',13}; // led off
static const char  EC_EZO_LED_STATUS[]={'L',',','?',13}; // led status

//  response control
static const char  EC_EZO_RESP_ON[] ={'*','O','K',',','1',13}; // enable response
static const char  EC_EZO_RESP_OFF[]={'*','O','K',',','0',13}; // disable response
static const char  EC_EZO_RESP_STATUS[] ={'*','O','K',',','?',13}; // response status

//  sleep & status
static const char  EC_EZO_SLEEP[]={'S','l','e','e','p',13}; // sleep mode
static const char  EC_EZO_STATUS[]={'S','t','a','t','u','s',13}; // sleep mode

//  enable/disable parameters from output string
static const char  EC_EZO_OEC_ON[] ={'O',',','E','C',',','1',13}; // Conductivity output on
static const char  EC_EZO_OEC_OFF[]={'O',',','E','C',',','0',13}; // Conductivity output off
static const char  EC_EZO_OTDS_ON[] ={'O',',','T','D','S',',','1',13}; // Total dissolved solids output on
static const char  EC_EZO_OTDS_OFF[]={'O',',','T','D','S',',','0',13}; // Total dissolved solids output off
static const char  EC_EZO_OSAL_ON[] ={'O',',','S',',','1',13}; // Salinity output on
static const char  EC_EZO_OSAL_OFF[]={'O',',','S',',','0',13}; // Salinity output off
static const char  EC_EZO_OSG_ON[] ={'O',',','S','G',',','1',13}; // gravity output on
static const char  EC_EZO_OSG_OFF[]={'O',',','S','G',',','0',13}; // gravity output off
static const char  EC_EZO_OUT_STATUS[] ={'O',',','?',13}; // output status

// define probe
static const char  EC_EZO_PROBE_K0_1[] ={'K',',','0','.','1',13}; // K 0.1
static const char  EC_EZO_PROBE_K1_0[] ={'K',',','1','.','0',13}; // K 1.0
static const char  EC_EZO_PROBE_K10[] ={'K',',','1','0',13}; // K 10
static const char  EC_EZO_PROBE_STATUS[] ={'K',',','?',13}; // probe status

// calibration
static const char  EC_EZO_PROBE_CAL_DRY[] ={'C','a','l',',','d','r','y',13}; // K 0.1
static const char  EC_EZO_PROBE_CAL_LOW[] ={'C','a','l',',','l','o','w',',','8','4',13}; // 84
static const char  EC_EZO_PROBE_CAL_HIGH[] ={'C','a','l',',','h','i','g','h',',','1','4','1','3',13}; // 84


//others
static const char  EC_EZO_CR[]={13};


int32_t UART_readUntil(UART_Handle handle, char *buffer, size_t size, char stopChar);
int32_t UART_readUntilOK(UART_Handle handle);
int32_t EC_EZO_init (UART_Handle handle);
void ReadData_EC_EZ0 (UART_Handle handle);

#ifdef __cplusplus
}
#endif

#endif /* UART_EC_EZO_H_ */
