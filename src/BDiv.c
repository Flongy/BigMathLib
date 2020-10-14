#include "BNumber.h"
#include "BDiv.h"
#include "Compare.h"
#include "BShift.h"
#include "BSub.h"
#include "BSum.h"

#include <string.h>

void Div(IN p_element first,
		 IN p_element second,
		 OUT p_element number,
		 OUT p_element quotient)
{
	memset(number, 0, sizeof(element) * NUM_SIZE);
	memset(quotient, 0, sizeof(element) * NUM_SIZE);

	element tmp_O = 0;

	if (Compare(first, second, NUM_SIZE, NUM_SIZE) == -1)
	{ 
		return;
	}
	else if (Compare(second, &tmp_O, NUM_SIZE, 1) == 0)
	{
		return;
	}

	memcpy(quotient, first, NUM_SIZE * sizeof(element));

	int DividerHighBit = HighBit(second, NUM_SIZE), DividendHighBit = 0, compareResult = 0;

	element target[NUM_SIZE];
	memset(target, 0, NUM_SIZE * sizeof(element));
	target[0] = 1;

	do
	{
		DividendHighBit = HighBit(quotient, NUM_SIZE);

		p_element shftmp = (p_element)calloc(NUM_SIZE, sizeof(element));
		memset(shftmp, 0, NUM_SIZE * sizeof(element));

		ShiftLeft(second, (DividendHighBit - DividerHighBit), shftmp);

		while (Compare(quotient, shftmp, NUM_SIZE, NUM_SIZE) == -1)
		{
			p_element shfRtmp = (p_element)calloc(NUM_SIZE, sizeof(element));
			memset(shfRtmp, 0, NUM_SIZE * sizeof(element));

			ShiftRight(shftmp, 1, shfRtmp);
			DividendHighBit--;

			memcpy(shftmp, shfRtmp, NUM_SIZE * sizeof(element));
			free(shfRtmp);
		}

		p_element result = (p_element)calloc((NUM_SIZE + 1), sizeof(element));
		memset(result, 0, (NUM_SIZE + 1) * sizeof(element));

		Sub(quotient, shftmp, result);
		memcpy(quotient, result, (NUM_SIZE) * sizeof(element));

		memset(result, 0, (NUM_SIZE + 1) * sizeof(element));
		memset(shftmp, 0, NUM_SIZE * sizeof(element));

		ShiftLeft(target, (DividendHighBit - DividerHighBit), shftmp);

		Sum(number, shftmp, result);
		memcpy(number, result, (NUM_SIZE) * sizeof(element));

		free(shftmp);
		free(result);

		compareResult = Compare(quotient, second, NUM_SIZE, NUM_SIZE);
	}
	while (compareResult == 1 || compareResult == 0);

	return;
}