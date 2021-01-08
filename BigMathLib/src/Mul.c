#include "BNumber.h"
#include "Mul.h"

void multiplication(IN p_element a,
                    IN p_element b, 
                    OUT p_element output) {
    multiplication2(a, NUM_SIZE, b, NUM_SIZE, output);
}

void multiplication2(IN p_element a,
                     IN unsigned int sizeA,
                     IN p_element b,
                     IN unsigned int sizeB,
                     OUT p_element output) {
    unsigned long long d;
    int i, j;
    i = sizeA + sizeB;
    while (--i >= 0) output[i] = 0;
    for (i = 0; i < sizeA; i++) {
        d = 0;
        for (j = 0; j < sizeB; j++) {
            d += (unsigned long long) a[i] * b[j] + output[i + j];
            output[i + j] = d;
            d >>= (sizeof(element) * BYTE_LEN);
        }
        output[i + j] = d;
    }
}