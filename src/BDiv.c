#include "BNumber.h"
#include "BDiv.h"
#include "Compare.h"
#include "BShift.h"
#include "BSub.h"
#include "BSum.h"

#include <string.h>

void Div(IN p_element first,
         IN p_element second,
         OUT p_element number,
         OUT p_element quotient)
{
    ZEROING(number);
    ZEROING(quotient);


    if (Compare(first, second, NUM_SIZE, NUM_SIZE) == -1)
    {
        COPY(first, quotient);
        return;
    }
    else if (Compare(second, &zero, NUM_SIZE, ZERO_SIZE) == 0)
    {
    return;
    }

    COPY(first, quotient);

    element target[NUM_SIZE], shftmp[NUM_SIZE], shfRtmp[NUM_SIZE];

    int DividerHighBit = HighBit(second, NUM_SIZE), DividendHighBit = 0, compareResult = 0;

    ZEROING(target);
    target[0] = 1;

    do
    {
        DividendHighBit = HighBit(quotient, NUM_SIZE);

        ZEROING(shftmp);

        ShiftLeft(second, (DividendHighBit - DividerHighBit), shftmp);

        while (Compare(quotient, shftmp, NUM_SIZE, NUM_SIZE) == -1)
        {
            ZEROING(shfRtmp);

            ShiftRight(shftmp, 1, shfRtmp);
            DividendHighBit--;

            COPY(shfRtmp, shftmp);
        }

        element result[NUM_SIZE + 1];
        memset(result, 0, (NUM_SIZE + 1) * sizeof(element));

        Sub(quotient, shftmp, result);

        COPY(result, quotient);

        memset(result, 0, (NUM_SIZE + 1) * sizeof(element));
        ZEROING(shftmp);

        ShiftLeft(target, (DividendHighBit - DividerHighBit), shftmp);

        Sum(number, shftmp, result);
        COPY(result, number);

        compareResult = Compare(quotient, second, NUM_SIZE, NUM_SIZE);
    }
    while (compareResult == 1 || compareResult == 0);

    return;
}