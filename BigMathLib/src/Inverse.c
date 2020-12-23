#include "BNumber.h"
#include "Inverse.h"
#include "Gcd.h"
#include "Add.h"
#include "Div.h"
#include "Compare.h"
#include "ResultCode.h"

int inverse(IN p_element a,
            IN p_element m,
            OUT p_element result) {

    element _a[NUM_SIZE];
    element x[NUM_SIZE];
    element y[NUM_SIZE];

    ZEROING(_a);
    ZEROING(x);
    ZEROING(y);

    COPY(a, _a);

    if (compare(a, m, NUM_SIZE, NUM_SIZE) == 1) {
        element r[NUM_SIZE];

        ZEROING(r);

        division(a, m, r, _a);
    }

    gcdExtended(_a, m, result, x, y);

    element one = 1;

    if (compare(result, &one, NUM_SIZE, 1) != 0) {
        return OPERATION_EXCEPTION;
    }
    
    if (compare(x, &zero, NUM_SIZE, ZERO_SIZE) == -1) {
        ZEROING(result);
        addition(m, x, result);
    } else {
        ZEROING(result);
        COPY(x, result);
    }
    return SUCCESSFULLY;
}