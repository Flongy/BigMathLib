#include "BNumber.h"
#include "Inverse.h"
#include "BGcd.h"
#include "BSum.h"
#include "BDiv.h"
#include "Compare.h"

void inverse(IN p_element a,
             IN p_element m,
             OUT p_element result) {

    element _a[NUM_SIZE];
    element x[NUM_SIZE];
    element y[NUM_SIZE];

    ZEROING(_a);
    ZEROING(x);
    ZEROING(y);

    COPY(a, _a);

    if (Compare(a, m, NUM_SIZE, NUM_SIZE) == 1) {
        element r[NUM_SIZE];

        ZEROING(r);

        Div(a, m, r, _a);
    }

    GcdExtended(_a, m, result, x, y);

    element one = 1;

    if (Compare(result, &one, NUM_SIZE, 1) != 0) {
        ZEROING(result);
        return;
    }
    
    if (Compare(x, &zero, NUM_SIZE, ZERO_SIZE) == -1) {
        ZEROING(result);
        Sum(m, x, result);
    } else {
        ZEROING(result);
        COPY(x, result);
    }
}