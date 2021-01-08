#include "BNumber.h"
#include "DiffieHellman.h"
#include "Mod.h"
#include "Rand.h"
#include "ResultCode.h"

#include <stdio.h>

int processJointKey(IN p_element base,
                    IN p_element mod,
                    IN int (*transferAndGet) (IN p_element, IN void *extendedParams, OUT p_element),
                    IN int randomNumberSeed,
                    IN void * extendedParams,
                    OUT p_element result) {
    
    element modResult[NUM_SIZE];
    element resultAfterTransaction[NUM_SIZE];
    element randomNumber[NUM_SIZE];
    ZEROING(modResult);
    ZEROING(randomNumber);
    ZEROING(resultAfterTransaction);
    ZEROING(result);

    randInit(randomNumberSeed);
    getRandomNumber(randomNumber);

    powerMod(base, randomNumber, mod, modResult);

    int transactionResult = transferAndGet(modResult, extendedParams, resultAfterTransaction);

    if (transactionResult != SUCCESSFULLY) {
        return transactionResult;
    }

    powerMod(resultAfterTransaction, randomNumber, mod, result);

    return SUCCESSFULLY;
}