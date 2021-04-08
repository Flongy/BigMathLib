#ifndef TESTBIGMATHLIB_H
#define TESTBIGMATHLIB_H

//структура для передачи данных и получения результата выполнения функции получения общего ключа

typedef struct {
    ResultCode code;
    p_element resultNumber;
} testDiffieHellmanStruct, *p_testDiffieHellmanStruct;

void testGcd();
void testGcdExtended();
void testInverse();
void testPowerMod();
void testAddMod();
void testSubMod();
void testDiffieHellman();

#endif