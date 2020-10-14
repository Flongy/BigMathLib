#ifndef COMPARE_H
#define COMPARE_H

/************************************************************/
/*	 Функция сравнения двух чисел, заданных массивами слов	*/
/*															*/
/*	 int Compare(IN p_element valueL,						*/
/*				 IN p_element valueM,						*/
/*				 IN unsigned int sizeL,						*/
/*				 IN unsigned int sizeM);					*/
/*															*/
/*	Входные параметры:										*/
/*															*/
/*	p_element valueL 		- первый операнд				*/
/*	p_element valueM		- второй операнд				*/
/*	unsigned int  sizeL		- длина первого операнда		*/
/*	unsigned int  sizeM		- длина второго операнда		*/
/*															*/
/*	Возвращаемое значение:									*/
/*															*/
/*	-1	- второй операнд больше первого операнда			*/
/*	 0	- первый и второй операнд равны						*/
/*	 1	- первый операнд больше второго операнда			*/
/*															*/
/************************************************************/

LIB(int) Compare(p_element valueL, p_element valueM, unsigned int sizeL, unsigned int sizeM);


#endif