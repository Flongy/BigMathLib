#ifndef BDIV_H
#define BDIV_H

/************************************************************/
/*  функция деления двух чисел, заданных массивами слов     */
/*                                                          */
/*  void Div(IN p_element first,                            */
/*           IN p_element second,                           */
/*           OUT p_element number,                          */
/*           OUT p_element quotient);                       */
/*                                                          */
/*  входные параметры:                                      */
/*                                                          */
/*  p_element first     - делимое                           */
/*  p_element second    - делитель                          */
/*                                                          */
/*  выходные параметры:                                     */
/*                                                          */
/*  p_element number    - массив, в который будет           */
/*                        помещено частное                  */
/*  p_element quotient  - массив, в который будет           */
/*                        помещен остаток от деления        */
/*                                                          */
/************************************************************/

LIB(void) Div(IN p_element first,
              IN p_element second,
              OUT p_element number,
              OUT p_element quotient);

#endif