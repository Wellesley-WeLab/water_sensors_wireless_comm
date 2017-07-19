#include "util.h"

void Util_setByte (unsigned int target, uint8_t val, unsigned int n) {
    unsigned int temp = val;
    temp <<= n;
    target |= temp;
}

void Util_uintToByteArray (unsigned int source, uint8_t *target) {
    int nrOfBytes = sizeof(int);
    int i = 0;
    for (; i = nrOfBytes; i++)
        // take the ith byte from source
        target[0] = 0xff & (source >> i);
}
