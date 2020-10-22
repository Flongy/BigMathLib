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
/*	 Функция сравения и замены чисел						*/
/*															*/
/*	 static void CompareAndSwitch(IN OUT p_element a,		*/
/*								  IN OUT p_element b);		*/
/*															*/
/*	Входные параметры:										*/
/*															*/
/*	p_element a		- первое число							*/
/*	p_element b		- второе число							*/
/*															*/
/*	Заметки:												*/
/*															*/
/*	- Если b больше a, то a будет помещено					*/
/*	  в b, а b будет помещено в a							*/
/*	- Если a больше b, то никаких изменений не будет		*/
/*	  произведено											*/
/*															*/
/************************************************************/

static void CompareAndSwitch(IN OUT p_element a,
							 IN OUT p_element b);

/************************************************************/
/*	Конец блока static функций								*/
/************************************************************/

void Gcd(IN p_element a,
		 IN p_element b,
		 OUT p_element result)  {
	
	CompareAndSwitch(a, b);

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

	Gcd(b, q, result);
}

void GcdExtended(IN p_element a,
			     IN p_element b,
				 OUT p_element result,
				 OUT p_element x,
				 OUT p_element y) {

	CompareAndSwitch(a, b);

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
	
	GcdExtended(b, q, result, x, y);

	memcpy(newX, y, NUM_SIZE * sizeof(element));
	Mul(y, r, tmp);
	Sub(x, tmp, y);
	memcpy(x, newX, NUM_SIZE * sizeof(element));
	return;
}

/************************************************************/
/*	Начало блока static функций								*/
/************************************************************/

static void CompareAndSwitch(IN OUT p_element a,
							 IN OUT p_element b) {
	int result = Compare(a, b, NUM_SIZE, NUM_SIZE);

	if (result == -1) {
		int i = 0;
		for (i = 0; i < NUM_SIZE; i++) {
			a[i] ^= b[i] ^= a[i] ^= b[i];
		}
	}
}

/************************************************************/
/*	Конец блока static функций								*/
/************************************************************/