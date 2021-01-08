#include "Bnumber.h"
#include "Div.h"
#include "Compare.h"
#include "Shift.h"
#include "Sub.h"
#include "Add.h"
#include "ResultCode.h"

#include <string.h>

int division(IN p_element first,
             IN p_element second,
             OUT p_element quotient,
             OUT p_element remainder) {
    return division2(first, NUM_SIZE, second, NUM_SIZE, quotient, remainder);
}

int division2(IN p_element first,
              IN unsigned int firstSize,
              IN p_element second,
              IN unsigned int secondSize,
              OUT p_element quotient,
              OUT p_element remainder) {

    int maxNumberSize = firstSize > secondSize ? firstSize : secondSize;

    memset(quotient, 0, maxNumberSize * sizeof(element));
    memset(remainder, 0, maxNumberSize * sizeof(element));

    if (compare(first, second, firstSize, secondSize) == -1) {
        memcpy(remainder, first, firstSize * sizeof(element));
        return SUCCESSFULLY;
    }
    else if (compare(second, &zero, secondSize, ZERO_SIZE) == 0) {
        return INVALID_INPUT_PARAMS;
    }

    memcpy(remainder, first, firstSize * sizeof(element));

    int DividerHighBit = highBit2(second, secondSize), DividendHighBit = 0, compareResult = 0;

    element target = 1;
    p_element shftmp = (p_element)calloc(maxNumberSize, sizeof(element));
    p_element shfRtmp = (p_element)calloc(maxNumberSize, sizeof(element));
    p_element result = (p_element)calloc(maxNumberSize + 1, sizeof(element));

    do {

        DividendHighBit = highBit2(remainder, maxNumberSize);

        memset(shftmp, 0, maxNumberSize * sizeof(element));

        shiftLeft3(second, (DividendHighBit - DividerHighBit), secondSize, maxNumberSize, shftmp);

        if (compare(remainder, shftmp, maxNumberSize, maxNumberSize) == -1) {
            memset(shfRtmp, 0, maxNumberSize * sizeof(element));

            shiftRight2(shftmp, 1, maxNumberSize, shfRtmp);
            DividendHighBit--;

            memcpy(shftmp, shfRtmp, maxNumberSize * sizeof(element));
        }

        memset(result, 0, (maxNumberSize + 1) * sizeof(element));

        subtraction2(remainder, maxNumberSize, shftmp, maxNumberSize, result);

        memcpy(remainder, result, maxNumberSize * sizeof(element));

        memset(result, 0, (maxNumberSize + 1) * sizeof(element));
        memset(shftmp, 0, maxNumberSize * sizeof(element));

        shiftLeft3(&target, (DividendHighBit - DividerHighBit), 1, maxNumberSize, shftmp);

        addition2(quotient, maxNumberSize, shftmp, maxNumberSize, result);

        memcpy(quotient, result, maxNumberSize * sizeof(element));

        compareResult = compare(remainder, second, maxNumberSize, secondSize);

    } while (compareResult == 1 || compareResult == 0);

    free(shftmp);
    free(shfRtmp);
    free(result);

    return SUCCESSFULLY;
}