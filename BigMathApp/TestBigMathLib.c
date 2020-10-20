#include <stdio.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"
#include "CheckBigMathLibResult.h"

#define TEST_GCD_MESSAGE "Тестирование функции поиска НОД\n"
#define TEST_GCD_EXTENDED_MESSAGE "Тестирование расширенной функции поиска НОД\n"
#define CHECK_GCD_EXTENDED_RESULT_MESSAGE "Проверка результата работы расширенной функции поиска НОД (решение уравнения a * x + b * y = (a, b)).\n"

void TestGcd() {

	printf(TEST_GCD_MESSAGE);

	element a[NUM_SIZE] = {0x12345678};
	element b[NUM_SIZE] = {0x87654321};
	element result[NUM_SIZE];

	printf("a: ");
	printConsoleBE(a);

	printf("b: ");
	printConsoleBE(b);

	Gcd(a, b, result);

	printf("result: ");
	printConsoleBE(result);

	return;
}

void TestGcdExtended() {

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

	GcdExtended(a, b, result, x, y);

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