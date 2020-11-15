#include "BigMathLib.h"
#include "CheckBigMathLibResult.h"
#include "Messages.h"

BOOL checkGcdExtendedResult(IN p_element a,
                            IN p_element b,
                            IN p_element x,
                            IN p_element y,
                            IN p_element d) {
    element tmp_1[NUM_SIZE*2];
    element tmp_2[NUM_SIZE*2];
    element tmp_3[NUM_SIZE];

    memset(tmp_1, 0, NUM_SIZE * 2 * sizeof(element));
    memset(tmp_2, 0, NUM_SIZE * 2 * sizeof(element));
    ZEROING(tmp_3);

    multiplication(a, x, tmp_1);
    multiplication(b, y, tmp_2);
    addition(tmp_1, tmp_2, tmp_3);

    unsigned int result = compare(tmp_3, d, NUM_SIZE, NUM_SIZE);

    if (result == 0) {
        return True;
    } else {
        return False;
    }
}

BOOL checkInverseResult(IN p_element a,
                        IN p_element m,
                        IN p_element result) {
    element tmp[NUM_SIZE];

    ZEROING(tmp);

    if (compare(result, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
        return True;
    }

    inverse(result, m, tmp);

    if (compare(tmp, a, NUM_SIZE, NUM_SIZE) == 0) {
        return True;
    } else {
        return False;
    }
}

void proccessCheckResult(IN BOOL checkResult) {
    if (checkResult == True) {
        printf(CHECK_PASSED);
    } else {
        printf(CHECK_NOT_PASSED);
    }
}