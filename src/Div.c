#include "BNumber.h"
#include "Div.h"
#include "Compare.h"
#include "Shift.h"
#include "Sub.h"
#include "Add.h"

#include <string.h>

void division(IN p_element first,
              IN p_element second,
              OUT p_element number,
              OUT p_element quotient) {

    ZEROING(number);
    ZEROING(quotient);

    if (compare(first, second, NUM_SIZE, NUM_SIZE) == -1) {
        COPY(first, quotient);
        return;
    } else if (compare(second, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
        return;
    }

    COPY(first, quotient);

    element target[NUM_SIZE], shftmp[NUM_SIZE], shfRtmp[NUM_SIZE];

    int DividerHighBit = highBit(second, NUM_SIZE), DividendHighBit = 0, compareResult = 0;

    ZEROING(target);
    target[0] = 1;

    do {
        DividendHighBit = highBit(quotient, NUM_SIZE);

        ZEROING(shftmp);

        shiftLeft(second, (DividendHighBit - DividerHighBit), shftmp);

        while (compare(quotient, shftmp, NUM_SIZE, NUM_SIZE) == -1) {
            ZEROING(shfRtmp);

            shiftRight(shftmp, 1, shfRtmp);
            DividendHighBit--;

            COPY(shfRtmp, shftmp);
        }

        element result[NUM_SIZE + 1];
        memset(result, 0, (NUM_SIZE + 1) * sizeof(element));

        subtraction(quotient, shftmp, result);

        COPY(result, quotient);

        memset(result, 0, (NUM_SIZE + 1) * sizeof(element));
        ZEROING(shftmp);

        shiftLeft(target, (DividendHighBit - DividerHighBit), shftmp);

        addition(number, shftmp, result);
        COPY(result, number);

        compareResult = compare(quotient, second, NUM_SIZE, NUM_SIZE);

    } while (compareResult == 1 || compareResult == 0);

    return;
}