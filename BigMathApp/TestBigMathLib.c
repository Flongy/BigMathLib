#include <stdio.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"

void TestGcd() {

	printf("Тестирование функции поиска НОД\n");

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