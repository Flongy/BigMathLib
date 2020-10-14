#ifndef BGCD_H
#define BGCD_H

/************************************************************/
/*	Функция нахождения НОД двух чисел						*/
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

LIB(void) Gcd(IN p_element a,
			  IN p_element b,
			  OUT p_element result);

#endif