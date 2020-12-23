#ifndef RAND_H
#define RAND_H

/************************************************************/
/*  Функция инициализации модуля получения случайных чисел  */
/*                                                          */
/*  LIB(void) randInit(IN long seed);                       */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  long seed    - число, отвечающее за факт случайности    */
/*                 генерируемых чисел                       */
/*                                                          */
/************************************************************/

LIB(void) randInit(IN long seed);

/************************************************************/
/*  Функция генерации случайного числа                      */
/*                                                          */
/*  LIB(void) getRandomNumber(OUT p_element result);        */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result   - число, в которое будет помещено    */
/*                       сгенерированное случайное число    */
/*                                                          */
/************************************************************/

LIB(void) getRandomNumber(OUT p_element result);

#endif