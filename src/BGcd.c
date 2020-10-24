#include "BNumber.h"
#include "BGcd.h"
#include "Compare.h"
#include "BDiv.h"
#include "BMul.h"
#include "BSub.h"
#include "BDiv.h"

/************************************************************/
/*	Начало блока static функций								*/
/************************************************************/

/************************************************************/
/*	Функция нахождения НОД двух чисел (a, b) рекурсивно		*/
/*															*/
/*	void Gcd(IN p_element a,								*/
/*			 IN p_element b,								*/
/*			 OUT p_element result);							*/
/*															*/
/*	Входные параметры:										*/
/*															*/
/*	p_element a 	- первое число							*/
/*	p_element b		- второе число							*/
/*															*/
/*	Выходные параметры:										*/
/*															*/
/*	p_element result	- массив, в который будет 			*/
/*						  помещен НОД						*/
/*															*/
/************************************************************/

static void GcdR(IN p_element a,
		  		 IN p_element b,
				 OUT p_element result);

/************************************************************/
/*	Функция рекурсивного выполнения расширенного алогритма	*/
/*	Евклида													*/
/*															*/
/*	решение уравнения: a * x + b * y = (a, b)				*/
/*															*/
/*	void GcdExtendedR(IN p_element a,						*/
/*					  IN p_element b,						*/
/*					  OUT p_element result,					*/
/*					  OUT p_element x,						*/
/*					  OUT p_element y);						*/
/*															*/
/*	Входные параметры:										*/
/*															*/
/*	p_element a 		- первое число						*/
/*	p_element b			- второе число						*/
/*															*/
/*	Выходные параметры:										*/
/*															*/
/*	p_element result	- массив, в который будет помещен	*/
/*						  НОД								*/
/*	p_element x			- массив, в который будет помещено 	*/
/*						  найденное число x					*/
/*	p_element y			- массив, в который будет помещено	*/
/*						  найденное число y					*/
/*															*/
/************************************************************/

static void GcdExtendedR(IN p_element a,
						 IN p_element b,
						 OUT p_element result,
						 OUT p_element x,
						 OUT p_element y);

/************************************************************/
/*	Конец блока static функций								*/
/************************************************************/

void Gcd(IN p_element a,
		 IN p_element b,
		 OUT p_element result)  {
	
	element _a[NUM_SIZE];
	element _b[NUM_SIZE];

	memset(_a, 0, NUM_SIZE * sizeof(element));
	memset(_b, 0, NUM_SIZE * sizeof(element));

	memcpy(_a, a, NUM_SIZE * sizeof(element));
	memcpy(_b, b, NUM_SIZE * sizeof(element));

	CompareAndSwap(_a, _b);

	GcdR(_a, _b, result);
}

void GcdExtended(IN p_element a,
			     IN p_element b,
				 OUT p_element result,
				 OUT p_element x,
				 OUT p_element y) {

	element _a[NUM_SIZE];
	element _b[NUM_SIZE];

	memset(_a, 0, NUM_SIZE * sizeof(element));
	memset(_b, 0, NUM_SIZE * sizeof(element));

	memcpy(_a, a, NUM_SIZE * sizeof(element));
	memcpy(_b, b, NUM_SIZE * sizeof(element));

	BOOL swapResult = CompareAndSwap(_a, _b);

	GcdExtendedR(_a, _b, result, x, y);

	if (swapResult == True) {
		Swap(x, y);
	}
}

/************************************************************/
/*	Начало блока static функций								*/
/************************************************************/

static void GcdR(IN p_element a,
	IN p_element b,
	OUT p_element result) {
	element r[NUM_SIZE];
	element q[NUM_SIZE];

	unsigned int zero = 0;

	int i = 0;

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, 1) == 0) {
		memset(result, 0, NUM_SIZE * sizeof(element));
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	GcdR(b, q, result);
}

static void GcdExtendedR(IN p_element a,
						 IN p_element b,
						 OUT p_element result,
						 OUT p_element x,
 						 OUT p_element y) {

	element r[NUM_SIZE];
	element q[NUM_SIZE];
	element tmp[NUM_SIZE * 2];
	element newX[NUM_SIZE];

	unsigned int zero = 0;

	memset(tmp, 0, NUM_SIZE * sizeof(element));
	memset(newX, 0, NUM_SIZE * sizeof(element));

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, 1) == 0) {
		memset(result, 0, NUM_SIZE * sizeof(element));
		memset(x, 0, NUM_SIZE * sizeof(element));
		memset(y, 0, NUM_SIZE * sizeof(element));
		x[0] = 0;
		y[0] = 1;
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	GcdExtendedR(b, q, result, x, y);

	memcpy(newX, y, NUM_SIZE * sizeof(element));
	Mul(y, r, tmp);
	Sub(x, tmp, y);
	memcpy(x, newX, NUM_SIZE * sizeof(element));
	return;
}

/************************************************************/
/*	Конец блока static функций								*/
/************************************************************/