#include <stdio.h>
#include <locale.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"

static void test();

int main()
{
    setlocale(LC_CTYPE, "ru_RU.UTF-8");
    test();
    return 0;
}

void test() {
    testGcd();
    testGcdExtended();
    testInverse();
    testPowerMod();
    testDiffieHellman();
    testLrs();
}