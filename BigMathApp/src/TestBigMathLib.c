#include <windows.h>
#include <process.h>
#include <stdio.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"
#include "CheckBigMathLibResult.h"
#include "Messages.h"

static void convertNumber(IN OUT p_element number);

void testGcd() {

    printf(TEST_GCD_MESSAGE);

    element a[NUM_SIZE] = {0x12345678};
    element b[NUM_SIZE] = {0x87654321};
    element result[NUM_SIZE];

    printf("a: ");
    printConsoleBE(a);

    printf("b: ");
    printConsoleBE(b);

    gcd(a, b, result);

    printf("result: ");
    printConsoleBE(result);

    return;
}

void testGcdExtended() {

    printf(TEST_GCD_EXTENDED_MESSAGE);

    element a[NUM_SIZE] = { 0x12345678 };
    element b[NUM_SIZE] = { 0x87654321 };
    element x[NUM_SIZE];
    element y[NUM_SIZE];
    element result[NUM_SIZE];

    printf("a: ");
    printConsoleBE(a);

    printf("b: ");
    printConsoleBE(b);

    gcdExtended(a, b, result, x, y);

    printf("result: ");
    printConsoleBE(result);

    printf("x: ");
    printConsoleBE(x);

    printf("y: ");
    printConsoleBE(y);

    printf(CHECK_GCD_EXTENDED_RESULT_MESSAGE);

    BOOL checkResult = checkGcdExtendedResult(a, b, x, y, result);
    proccessCheckResult(checkResult);

    return;
}

void testInverse() {

    printf(TEST_INVERSE_MESSAGE);

    element a[NUM_SIZE] = { 0x12345678 };
    element m[NUM_SIZE] = { 0x87654323 };
    element result[NUM_SIZE];

    printf("a: ");
    printConsoleBE(a);

    printf("m: ");
    printConsoleBE(m);

    inverse(a, m, result);

    printf("result: ");
    printConsoleBE(result);

    printf(CHECK_INVERSE_RESULT_MESSAGE);

    BOOL checkResult = checkInverseResult(a, m, result);
    proccessCheckResult(checkResult);

    return;
}

void testPowerMod() {

    printf(TEST_POWER_MOD_MESSAGE);

    element g[NUM_SIZE];
    element p[NUM_SIZE] = { 0x00000431,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x80000000 };
    element randomNumber[NUM_SIZE];
    element result[NUM_SIZE];

    convertNumber(p);

    ZEROING(g);
    g[0] = 2;

    randInit(time(NULL));
    getRandomNumber(randomNumber);


    printf("base: ");
    printConsoleBE(g);

    printf("power: ");
    printConsoleBE(randomNumber);

    printf("mod: ");
    printConsoleBE(p);

    powerMod(g, randomNumber, p, result);

    printf("result: ");

    printConsoleBE(result);
}

#define THREAD_COUNT 2                                                                  //количество потоков для имитации передачи данных по сети

static volatile unsigned int threadCounter = 0;                                         //счетчик потоков
static volatile BOOL threadSwitch = True;                                               //счетчик потоков


volatile element threadArray[THREAD_COUNT][NUM_SIZE];                                   //имитация среды передачи данных

static RTL_CRITICAL_SECTION processingcriticalSection;                                  //структура критической секции

static int tryToSet(p_element expected, unsigned long expectedSize, p_element value) {
    int i = 0;
    for (i = 0; i < THREAD_COUNT; i++) {
        if (compare(threadArray[i], expected, NUM_SIZE, expectedSize) == 0) {
            COPY(value, threadArray[i]);
            return i;
        }
    }
    return OPERATION_EXCEPTION;
}

int sendAndGet(IN p_element inData, IN void* extendedParams, OUT p_element outData) {  //callback функция, имитирующая передачу данных по сети.

    EnterCriticalSection(&processingcriticalSection);

    threadSwitch = True;

    int index = tryToSet(&zero, ZERO_SIZE, inData);
    if (index < 0) {
        return index;
    }

    threadCounter++;

    LeaveCriticalSection(&processingcriticalSection);

    while (threadSwitch == True) {                                                      //после того, как поток "передал данные", он ожидает, пока второй поток "передаст" данные.
        if (threadCounter == THREAD_COUNT) {
            threadSwitch = False;
        }
    }
    
    EnterCriticalSection(&processingcriticalSection);

    COPY(threadArray[index ^ 1], outData);

    threadCounter--;

    LeaveCriticalSection(&processingcriticalSection);
    return SUCCESSFULLY;
}

VOID CALLBACK threadFunction(PTP_CALLBACK_INSTANCE Instance,                            //callback функция, которая передается в поток для исполнения. Вызывает функция получения обшего ключа. 
                             PVOID Parameter,
                             PTP_WORK  Work) {

    testDiffieHellmanStruct* resultStruct = (testDiffieHellmanStruct*)Parameter;

    element g[NUM_SIZE];
    element p[NUM_SIZE] = { 0x00000431,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x00000000,
                            0x80000000 };
    ZEROING(g);
    g[0] = 2;
    convertNumber(p);

    EnterCriticalSection(&processingcriticalSection);                                   //Входим в критическую секцию для корректного отображения данных. 

    printf("thread %ld\tg: ", GetCurrentThreadId());
    printConsoleBE(g);

    printf("thread %ld\tp: ", GetCurrentThreadId());
    printConsoleBE(p);

    LeaveCriticalSection(&processingcriticalSection);                                   //выходим из критической секции.

    resultStruct->code = processJointKey(g, p, sendAndGet, time(NULL) * GetCurrentThreadId(), NULL, resultStruct->resultNumber);
}

void testDiffieHellman() {

    printf(TEST_DIFFIE_HELLMAN_MESSAGE);

    element result1[NUM_SIZE];
    element result2[NUM_SIZE];
    
    ZEROING(threadArray[0]);
    ZEROING(threadArray[1]);

    testDiffieHellmanStruct resultStruct1 = {SUCCESSFULLY, result1};
    testDiffieHellmanStruct resultStruct2 = {SUCCESSFULLY, result2};

    TP_CALLBACK_ENVIRON CallBackEnviron;
    PTP_POOL pool = NULL;
    PTP_CLEANUP_GROUP cleanupgroup = NULL;
    PTP_WORK_CALLBACK workcallback = threadFunction;

    InitializeThreadpoolEnvironment(&CallBackEnviron);
    pool = CreateThreadpool(NULL);
    SetThreadpoolThreadMaximum(pool, 1);
    SetThreadpoolThreadMinimum(pool, THREAD_COUNT);
    cleanupgroup = CreateThreadpoolCleanupGroup();
    SetThreadpoolCallbackPool(&CallBackEnviron, pool);
    SetThreadpoolCallbackCleanupGroup(&CallBackEnviron, cleanupgroup, NULL);
    PTP_WORK work1 = CreateThreadpoolWork(workcallback, &resultStruct1, &CallBackEnviron);
    PTP_WORK work2 = CreateThreadpoolWork(workcallback, &resultStruct2, &CallBackEnviron);

    InitializeCriticalSection(&processingcriticalSection);

    SubmitThreadpoolWork(work1);
    SubmitThreadpoolWork(work2);

    WaitForThreadpoolWorkCallbacks(work1, FALSE);
    WaitForThreadpoolWorkCallbacks(work2, FALSE);

    DeleteCriticalSection(&processingcriticalSection);

    printf("result code 1: %d\n", resultStruct1.code);
    printf("Key 1: ");

    printConsoleBE(resultStruct1.resultNumber);
    
    printf("result code 2: %d\n", resultStruct1.code);
    printf("Key 2: ");

    printConsoleBE(resultStruct2.resultNumber);

    printf(CHECK_DIFFIE_HELLMAN_RESULT_MESSAGE);

    BOOL checkResult = checkDiffieHellmanResult(&resultStruct1, &resultStruct2);

    proccessCheckResult(checkResult);
}

static void convertNumber(IN OUT p_element number) {                                        //функция для преобразования числа из прямого кода в обратный код
    int i = 0;
    for (i = 0; i < NUM_SIZE; i++) {
        number[i] = ~number[i];
    }
    increment(number);
}

static void fillLrsInitState(unsigned short* a, unsigned int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        a[i] = 22 + i;
    }
}

static void printLrs(unsigned short* a, unsigned int size) {
    int i = 0;
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void testLrs() {
    unsigned int F = 22, i = 0, x = 0;
    unsigned short a[32] = { 0 };
    
    fillLrsInitState(a, 32);
    getLrs(a, F, 0x8F57, 32, 63);

    for (i = 64; i < 96; i++) {
        getLrs(a, F, 0x63, 32, 1);
        printLrs(a, 32);
    }
}