#ifndef DIV_H
#define DIV_H

/************************************************************/
/*  Функция деления двух чисел, заданных массивами слов     */
/*                                                          */
/*  int division(IN p_element first,                        */
/*               IN p_element second,                       */
/*               OUT p_element number,                      */
/*               OUT p_element quotient);                   */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element first     - делимое                           */
/*  p_element second    - делитель                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element number    - массив, в который будет           */
/*                        помещено частное                  */
/*  p_element quotient  - массив, в который будет           */
/*                        помещен остаток от деления        */
/*                                                          */
/*  Возвращаемое значение:                                  */
/*                                                          */
/*  -1  - делитель равен нулю                               */
/*   0  - операция деления успешно проведена                */
/*                                                          */
/************************************************************/

LIB(int) division(IN p_element first,
                  IN p_element second,
                  OUT p_element number,
                  OUT p_element quotient);

#endif