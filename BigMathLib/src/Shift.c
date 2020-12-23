#include "BNumber.h"
#include "Shift.h"

void shiftLeft(IN p_element data,
               IN unsigned int shift,
               OUT p_element output) {
    shiftLeft2(data, shift, NUM_SIZE, output);
}

void shiftLeft2(IN p_element data,
                IN unsigned int shift,
                IN unsigned int dataSize,
                OUT p_element output) {
    shiftLeft3(data, shift, NUM_SIZE, NUM_SIZE, output);
}

void shiftLeft3(IN p_element data,
                IN unsigned int shift,
                IN unsigned int dataSize,
                IN unsigned int outputSize,
                OUT p_element output) {
    element d = 0;

    int i = 0, r1 = shift / (sizeof(element) * BYTE_LEN), r2 = shift % (sizeof(element) * BYTE_LEN);
    long long s = 0;

    memset(output, 0, outputSize * sizeof(element));

    for (i = 0; i < dataSize; i++) {
        s = ((long long)data[i] << r2) | d;
        output[i + r1] = s;
        d = s >> (sizeof(element) * BYTE_LEN);
    }
    if (i + r1 < outputSize) {
        output[i + r1] = d;
    }
}

void shiftRight(IN p_element data,
                IN unsigned int shift,
                OUT p_element output) {
    shiftRight2(data, shift, NUM_SIZE, output);
}

void shiftRight2(IN p_element data,
                 IN unsigned int shift,
                 IN unsigned int dataSize,
                 OUT p_element output) {
    element d = 0;

    int i = 0, r1 = shift / (sizeof(element) * BYTE_LEN), r2 = shift % (sizeof(element) * BYTE_LEN);
    long long s = 0;

    memset(output, 0, dataSize * sizeof(element));

    for (i = dataSize - 1; i >= r1; i--) {
        output[i - r1] = (data[i] >> r2) | d;
        d = data[i] << (sizeof(element) * BYTE_LEN - r2);
    }
}

int highBit(IN p_element data) {
    highBit2(data, NUM_SIZE);
}

int highBit2(IN p_element data, IN unsigned int size) {
    int i = 0, x = 0, result = -1;

    for (i = size - 1; i >= 0; i--) {
        element mask = 1 << (sizeof(element) * BYTE_LEN - 1);
        for (x = 0; x < BYTE_LEN * sizeof(element); x++) {
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