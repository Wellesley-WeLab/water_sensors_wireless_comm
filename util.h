/**
 * Utility functions
 */

#ifndef _UTIL_H__
#define _UTIL_H__

#include <stdint.h>

/**
 * Sets the the bytes from offset to (offset + bytes) in target with bytes from value
 * @param target the array where to put the bytes
 * @param value the integer where to take the values
 * @param offset the position in target where to start putting values
 * @param bytes the number of bytes to take from value and put in target
 */
void Util_setBytes (uint8_t **target, unsigned int value, int offset, int bytes);



#endif // _UTIL_H__
