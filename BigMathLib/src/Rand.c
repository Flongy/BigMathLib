#include "BNumber.h"
#include "Rand.h"
#include <stdlib.h>

void randInit(IN long seed) {
    srand(seed);
}

void getRandomNumber(OUT p_element result) {
    ZEROING(result);
    int i = 0;
    for (i = 0; i < NUM_SIZE; i++) {
        long randPart = rand();
        randPart *= rand() * INT_MAX;
        result[i] = randPart % INT_MAX;
    }
}