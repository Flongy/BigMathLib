#ifndef DIV_H
#define DIV_H

/************************************************************/
/*  Функция деления двух чисел, заданных массивами слов     */
/*                                                          */
/*  int division(IN p_element first,                        */
/*               IN p_element second,                       */
/*               OUT p_element quotient,                    */
/*               OUT p_element remainder);                  */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element first     - делимое                           */
/*  p_element second    - делитель                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element quotient   - массив, в который будет          */
/*                        помещено частное                  */
/*  p_element remainder  - массив, в который будет          */
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
                  OUT p_element quotient,
                  OUT p_element remainder);

/************************************************************/
/*  Функция деления двух чисел, заданных массивами слов     */
/*                                                          */
/*  int division2(IN p_element first,                       */
/*                IN unsigned int firstSize,                */
/*                IN p_element second,                      */
/*                IN unsigned int secondSize,               */
/*                OUT p_element quotient,                   */
/*                OUT p_element remainder);                 */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element first             - делимое                   */
/*  p_element second            - делитель                  */
/*  unsigned int firstSize      - длина делимого            */
/*  unsigned int secondSize     - длина делителя            */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element quotient   - массив, в который будет          */
/*                        помещено частное                  */
/*  p_element remainder  - массив, в который будет          */
/*                        помещен остаток от деления        */
/*                                                          */
/*  Возвращаемое значение:                                  */
/*                                                          */
/*  -1  - делитель равен нулю                               */
/*   0  - операция деления успешно проведена                */
/*                                                          */
/************************************************************/

LIB(int) division2(IN p_element first,
                   IN unsigned int firstSize,
                   IN p_element second,
                   IN unsigned int secondSize,
                   OUT p_element quotient,
                   OUT p_element remainder);

#endif