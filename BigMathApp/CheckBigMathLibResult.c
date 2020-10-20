#include "BigMathLib.h"
#include "CheckBigMathLibResult.h"

BOOL checkGcdExtendedResult(IN p_element a,
							IN p_element b,
							IN p_element x,
							IN p_element y,
							IN p_element d) {
	element tmp_1[NUM_SIZE*2];
	element tmp_2[NUM_SIZE*2];
	element tmp_3[NUM_SIZE];

	memset(tmp_1, 0, NUM_SIZE * sizeof(element));
	memset(tmp_2, 0, NUM_SIZE * sizeof(element));
	memset(tmp_3, 0, NUM_SIZE * sizeof(element));

	Mul(a, x, tmp_1);
	Mul(b, y, tmp_2);
	Sum(tmp_1, tmp_2, tmp_3);

	unsigned int result = Compare(tmp_3, d, NUM_SIZE, NUM_SIZE);

	if (result == 0) return True;
	return False;
}

void proccessCheckResult(IN BOOL checkResult) {
	if (checkResult == True) {
		printf(CHECK_PASSED);
	}
	else {
		printf(CHECK_NOT_PASSED);
	}
}