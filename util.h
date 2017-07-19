/**
 * Utility functions
 */

#ifndef _UTIL_H__
#define _UTIL_H__

#include <stdint.h>

/**
 * Sets the nth byte of target with the value of val
 * @param target the number to change
 * @param val the byte to put in target
 * @param n position where to put val
 */
void Util_setByte (unsigned int target, uint8_t val, unsigned int n);

/**
 * To change an unsigned integer to a byte array of its bytes
 * @param source the integer to split
 * @param target the byte array where to store the data. this array should have at least sizeof(int) bytes of size
 */
void Util_uintToByteArray (unsigned int source, uint8_t *target);


#endif // _UTIL_H__
