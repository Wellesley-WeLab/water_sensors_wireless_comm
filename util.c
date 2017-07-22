#include "util.h"

void Util_setBytes (uint8_t **target, unsigned int value, int offset, int bytes) {
    uint8_t *_target = *target;
    int i = offset;
    int shift = bytes - 1;
    while (i < offset + bytes) {
        _target[i] = (value >> (shift*8)) & 0xff;
        shift--; i++;
    }
}

