#include "BNumber.h"
#include "Rand.h"
#include <stdlib.h>

void randInit(IN long seed) {
    srand(seed);
}

void getRandomNumber(OUT p_element result) {
    ZEROING(result);
    int i = 0;
    for (i = 0; i < NUM_SIZE; i++)
        result[i] = getOneRandom();
}

void getRandomNumber2(OUT p_element result,
                      IN unsigned int size) {
    ZEROING2(result, size);
    int i = 0;
    for (i = 0; i < size; i++)
        result[i] = getOneRandom();
}

long getOneRandom() {
    long randPart = rand();
    randPart *= rand() * INT_MAX;
    return randPart % INT_MAX;
}