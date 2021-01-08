#include "BNumber.h"
#include "Sqrt.h"
#include "Mul.h"
#include "Add.h"
#include "Shift.h"
#include "Compare.h"

#include <string.h>

void squareRoot(IN p_element value,
                OUT p_element output) {

    element left[NUM_SIZE],
            right[NUM_SIZE],
            range[NUM_SIZE],
            dividend[NUM_SIZE],
            intermediateVar[NUM_SIZE * 2];

    ZEROING(left);
    ZEROING(right);

    COPY(value, right);

    while (True) {
        ZEROING(range);
        ZEROING(dividend);
        memset(intermediateVar, 0, NUM_SIZE * 2 * sizeof(element));

        addition(right, left, range);
        shiftRight(range, 1, dividend);

        if (compare(dividend, left, NUM_SIZE, NUM_SIZE) == 0) {
            break;
        }

        multiplication(dividend, dividend, intermediateVar);

        int compare_result = compare(value, intermediateVar, NUM_SIZE, NUM_SIZE * 2);

        if (compare_result == 1) {
            ZEROING(left);
            COPY(dividend, left);
        } else if (compare_result == -1) {
            ZEROING(right);
            COPY(dividend, right);
        } else if (compare_result == 0) {
            break;
        }
    }
    ZEROING(output);
    COPY(dividend, output);
}


BOOL isSquareRoot(IN p_element value) {
    BOOL retValue = False;

    element result[NUM_SIZE];
    element originalValue[NUM_SIZE*2];

    squareRoot(value, result);
    multiplication(result, result, originalValue);

    if (compare(value, originalValue, NUM_SIZE, NUM_SIZE*2) == 0) {
        retValue = True;
    }

    return retValue;
}