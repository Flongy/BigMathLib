#include "BNumber.h"
#include "BSub.h"

void Sub(IN p_element valueL, 
         IN p_element valueM, 
         OUT p_element out)
{
    int i = NUM_SIZE;
    while (--i >= 0) out[i] = 0;
    element d = 1;
    unsigned long long s;
    for (int i = 0; i < NUM_SIZE; i++)
    {
        s = (unsigned long long) valueL[i] + ~valueM[i] + d;
        out[i] = s;
        d = s >> sizeof(element) * BYTE_LEN;
    }
}

void Decrement(IN OUT p_element valueL)
{
    element one[NUM_SIZE];
    element _out[NUM_SIZE];
    ZEROING(one);
    one[0] = 1;
    Sub(valueL, one, _out);
    COPY(_out, valueL);
}