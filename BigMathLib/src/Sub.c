#include "BNumber.h"
#include "Sub.h"

void subtraction(IN p_element valueL,
                 IN p_element valueM, 
                 OUT p_element out) {
    subtraction2(valueL, NUM_SIZE, valueM, NUM_SIZE, out);
}

void subtraction2(IN p_element valueL,
                  IN unsigned int valueLSize,
                  IN p_element valueM,
                  IN unsigned int valueMSize,
                  OUT p_element out) {

    int maxNumberSize = valueLSize > valueMSize ? valueLSize : valueMSize;

    int i = maxNumberSize;
    while (--i >= 0) out[i] = 0;
    element d = 1;
    unsigned long long s;
    for (int i = 0; i < maxNumberSize; i++) {

        if (i >= valueLSize) {
            s = (unsigned long long) 0 + ~valueM[i] + d;
        }
        else if (i >= valueMSize) {
            s = (unsigned long long) valueL[i] + ~(0) + d;
        }
        else {
            s = (unsigned long long) valueL[i] + ~valueM[i] + d;
        }
        
        out[i] = s;
        d = s >> sizeof(element) * BYTE_LEN;
    }
}

void decrement(IN OUT p_element valueL) {
    element one[NUM_SIZE];
    element _out[NUM_SIZE];
    ZEROING(one);
    one[0] = 1;
    subtraction(valueL, one, _out);
    COPY(_out, valueL);
}