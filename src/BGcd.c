#include "BNumber.h"
#include "BGcd.h"
#include "Compare.h"
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
	element zero[NUM_SIZE];
	
	int i = 0;
	memset(zero, 0, NUM_SIZE * sizeof(element));

	Div(a, b, r, q);

	if (Compare(q, zero, NUM_SIZE, NUM_SIZE) == 0) {
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	Gcd(b, q, result);
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