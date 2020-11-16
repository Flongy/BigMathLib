#include "BNumber.h"
#include "Shift.h"

void shiftLeft(IN p_element data,
               IN unsigned int shift,
               OUT p_element output) {
    element d = 0;

    int i = 0, r1 = shift / (sizeof(element) * BYTE_LEN), r2 = shift % (sizeof(element) * BYTE_LEN);
    long long s = 0;

    ZEROING(output);

    int limit = NUM_SIZE;

    if (r1 != 0) limit = NUM_SIZE - r1;

    for (i = 0; i < limit; i++) {
        s = ((long long)data[i] << r2) | d;
        output[i + r1] = s;
        d = s >> (sizeof(element) * BYTE_LEN);
    }
}

void shiftRight(IN p_element data,
                IN unsigned int shift,
                OUT p_element output) {
    element d = 0;

    int i = 0, r1 = shift / (sizeof(element) * BYTE_LEN), r2 = shift % (sizeof(element) * BYTE_LEN);
    long long s = 0;

    ZEROING(output);

    for (i = NUM_SIZE - 1; i >= r1; i--) {
        output[i - r1] = (data[i] >> r2) | d;
        d = data[i] << (sizeof(element) * BYTE_LEN - r2);
    }
}

int highBit(IN p_element data) {
    int i = 0, x = 0, result = -1;

    for (i = NUM_SIZE - 1; i >= 0; i--) {
        element mask = 1<<(sizeof(element)* BYTE_LEN -1);
        for (x = 0; x < BYTE_LEN*sizeof(element); x++) {
            if (mask & data[i]) {
                result = (i * BYTE_LEN * sizeof(element) + (BYTE_LEN * sizeof(element) - x - 1));
                break;
            }
            mask >>= 1;
        }
        if (result != -1) {
            break;
        }
    }
    return result;
}