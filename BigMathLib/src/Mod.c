#include "BNumber.h"
#include "Add.h"
#include "Sub.h"
#include "Mod.h"
#include "Div.h"
#include "Mul.h"
#include "Shift.h"
#include "Compare.h"
#include "NumIO.h"

static void mulitplicationAndMod(IN p_element mul1, 
                                 IN p_element mul2, 
                                 IN p_element mod, 
                                 OUT p_element result);

void powerMod(IN p_element base,
              IN p_element power,
              IN p_element mod,
              OUT p_element result) {
    element _base[NUM_SIZE];
    element currentNumber[NUM_SIZE];
    element currentNumber2[NUM_SIZE];
    ZEROING(_base);
    ZEROING(result);
    COPY(base, _base);
    result[0] = 1;

    if (compare(base, result, NUM_SIZE, NUM_SIZE) == 0) {
        return;
    }

    int i = 0, x = 0, highBitValue = highBit(power);

    COPY(power, currentNumber);

    for (i = 0; i < NUM_SIZE; i++) {
        for (x = 0; x < BYTE_LEN * sizeof(element); x++) {
            int position = i * BYTE_LEN * sizeof(element) + x;
            if (position > highBitValue) {
                return;
            }
            if (((power[i] >> x) & 1) == 1) {
                mulitplicationAndMod(_base, result, mod, result);
            }
            mulitplicationAndMod(_base, _base, mod, _base);
        }
    }
}

static void mulitplicationAndMod(IN p_element mul1, 
                                 IN p_element mul2, 
                                 IN p_element mod, 
                                 OUT p_element result) {
    element multiplicationResult[NUM_SIZE * 2];
    element quotient[NUM_SIZE * 2];
    element remainder[NUM_SIZE * 2];
    multiplication(mul1, mul2, multiplicationResult);
    division2(multiplicationResult, NUM_SIZE * 2, mod, NUM_SIZE, quotient, remainder);
    COPY(remainder, result);
}

void addMod(IN p_element a,
            IN p_element b,
            IN p_element mod,
            OUT p_element result) {
    addition(a, b, result);
    element result_temp[NUM_SIZE];
    while (compare(result, mod, NUM_SIZE, NUM_SIZE) >= 0) {
        subtraction(result, mod, result_temp);
        COPY(result_temp, result);
    }
}

