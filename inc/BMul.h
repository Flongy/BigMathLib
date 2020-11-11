#ifndef	BMUL_H
#define	BMUL_H

/************************************************************/
/*  Функция умножения чисел                                 */
/*                                                          */
/*  void Mul(IN p_element a,                                */
/*          (IN p_element b,                                */
/*           OUT p_element output);                         */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a     - первое слагаемое                      */
/*  p_element b     - второе слагаемое                      */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element output - массив, в который будет помещен      */
/*                     результат умножения                  */
/*                                                          */
/************************************************************/

LIB(void) Mul(IN p_element a,
              IN p_element b,
              OUT p_element output);

#endif