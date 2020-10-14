#include <stdio.h>
#include <locale.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"

static void test();

int main()
{
    setlocale(LC_ALL, "");
    test();
    return 0;
}

void test() {
    TestGcd();
}