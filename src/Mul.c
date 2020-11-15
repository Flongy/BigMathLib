#include "BNumber.h"
#include "Mul.h"

void multiplication(IN p_element a,
                    IN p_element b, 
                    OUT p_element output) {
    int n = NUM_SIZE;
    unsigned long long d;
    int i,j;
    i = 2*n;
    while (--i >= 0) output[i] = 0;
    for(i = 0; i < n; i++) {
        d = 0;
        for(j = 0; j < n; j++) {
            d += (unsigned long long) a[i] * b[j] + output[i+j];
            output[i+j] = d;
            d >>= (sizeof(element) * BYTE_LEN);
        }
        output[i+j] = d;
    }
}