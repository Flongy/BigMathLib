#include "BNumber.h"
#include "Gcd.h"
#include "Compare.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"
#include "ResultCode.h"

/************************************************************/
/*  Начало блока static функций                             */
/************************************************************/

/************************************************************/
/*  Функция нахождения НОД двух чисел (a, b) рекурсивно     */
/*                                                          */
/*  int gcd(IN p_element a,                                 */
/*          IN p_element b,                                 */
/*          OUT p_element result);                          */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a     - первое число                          */
/*  p_element b     - второе число                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result    - массив, в который будет           */
/*                        помещен НОД                       */
/*                                                          */
/************************************************************/

static int gcdR(IN p_element a,
                IN p_element b,
                OUT p_element result);

/************************************************************/
/*  Функция рекурсивного выполнения расширенного алогритма  */
/*  Евклида                                                 */
/*                                                          */
/*  решение уравнения: a * x + b * y = (a, b)               */
/*                                                          */
/*  int gcdExtendedR(IN p_element a,                        */
/*                   IN p_element b,                        */
/*                   OUT p_element result,                  */
/*                   OUT p_element x,                       */
/*                   OUT p_element y);                      */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a         - первое число                      */
/*  p_element b         - второе число                      */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result    - массив, в который будет помещен   */
/*                        НОД                               */
/*  p_element x         - массив, в который будет помещено  */
/*                        найденное число x                 */
/*  p_element y         - массив, в который будет помещено  */
/*                        найденное число y                 */
/*                                                          */
/************************************************************/

static int gcdExtendedR(IN p_element a,
                        IN p_element b,
                        OUT p_element result,
                        OUT p_element x,
                        OUT p_element y);

/************************************************************/
/*  Конец блока static функций                              */
/************************************************************/

int gcd(IN p_element a,
        IN p_element b,
        OUT p_element result) {

    element _a[NUM_SIZE];
    element _b[NUM_SIZE];

    ZEROING(_a);
    ZEROING(_b);

    COPY(a, _a);
    COPY(b, _b);

    compareAndSwap(_a, _b);

    return gcdR(_a, _b, result);
}

int gcdExtended(IN p_element a,
                IN p_element b,
                OUT p_element result,
                OUT p_element x,
                OUT p_element y) {
    element _a[NUM_SIZE];
    element _b[NUM_SIZE];

    ZEROING(_a);
    ZEROING(_b);

    COPY(a, _a);
    COPY(b, _b);

    BOOL swapResult = compareAndSwap(_a, _b);

    int resultCode = gcdExtendedR(_a, _b, result, x, y);

    if (result != SUCCESSFULLY) {
        return resultCode;
    }

    if (swapResult == True) {
        swap(x, y);
    }

    return resultCode;
}

/************************************************************/
/*  Начало блока static функций                             */
/************************************************************/

static int gcdR(IN p_element a,
                IN p_element b,
                OUT p_element result) {

    element r[NUM_SIZE];
    element q[NUM_SIZE];

    int i = 0;
    int resultCode = SUCCESSFULLY;

    resultCode = division(a, b, r, q);

    if (resultCode != SUCCESSFULLY) {
        return resultCode;
    }

    if (compare(q, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
        ZEROING(result);
        COPY(b, result);
        return SUCCESSFULLY;
    }

    return gcdR(b, q, result);
}

static int gcdExtendedR(IN p_element a,
                        IN p_element b,
                        OUT p_element result,
                        OUT p_element x,
                        OUT p_element y) {

    element r[NUM_SIZE];
    element q[NUM_SIZE];
    element tmp[NUM_SIZE * 2];
    element newX[NUM_SIZE];

    memset(tmp, 0, NUM_SIZE * 2 * sizeof(element));
    ZEROING(newX);

    int resultCode = SUCCESSFULLY;

    resultCode = division(a, b, r, q);

    if (resultCode != SUCCESSFULLY) {
        return resultCode;
    }

    if (compare(q, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
        ZEROING(result);
        ZEROING(x);
        ZEROING(y);
        x[0] = 0;
        y[0] = 1;
        COPY(b, result);
        return SUCCESSFULLY;
    }

    resultCode = gcdExtendedR(b, q, result, x, y);

    if (resultCode != SUCCESSFULLY) {
        return resultCode;
    }

    COPY(y, newX);
    multiplication(y, r, tmp);
    subtraction(x, tmp, y);
    COPY(newX, x);
    return resultCode;
}

/************************************************************/
/*  Конец блока static функций                              */
/************************************************************/