#include "BNumber.h"
#include "LRS.h"

LIB(void) getLrs(IN OUT unsigned short* a,
                 IN unsigned int F,
                 IN unsigned int f,
                 IN unsigned short size,
                 IN unsigned int count){
    unsigned int i = 0, x = 0;
    for (i = 0; i < count; i++) {
        unsigned int newLrsValue = a[0];
        if ((a[F - 1] & 0x80) == 1) {
            newLrsValue ^= (a[F - 1] << 1) % f;
        }
        else {
            newLrsValue ^= a[F - 1] << 1;
        }
        for (x = 0; x < size - 1; x++) {
            a[x] = a[x + 1];
        }
        a[size - 1] = newLrsValue;
    }
}