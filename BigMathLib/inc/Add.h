#ifndef ADD_H
#define ADD_H

/************************************************************/
/*  Функция сложения чисел                                  */
/*                                                          */
/*  void addition(IN p_element valueL,                      */
/*                IN p_element valueM,                      */
/*                OUT p_element out);                       */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL    - первое слагаемое                  */
/*  p_element valueM    - второе слагаемое                  */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element out    - массив, в который будет помещен      */
/*                     результат сложения                   */
/*                                                          */
/************************************************************/

LIB(void) addition(IN p_element valueL,
                   IN p_element valueM,
                   OUT p_element out);

/************************************************************/
/*  Функция сложения чисел                                  */
/*                                                          */
/*  void addition2(IN p_element valueL,                     */
/*                 IN unsigned int valueLSize,              */
/*                 IN p_element valueM,                     */
/*                 IN unsigned int valueMSize,              */
/*                 OUT p_element out);                      */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL            - первое слагаемое          */
/*  p_element valueM            - второе слагаемое          */
/*  unsigned int valueLSize     - длина числа valueL        */
/*  unsigned int valueMSize     - длина числа valueM        */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element out    - массив, в который будет помещен      */
/*                     результат сложения                   */
/*                                                          */
/************************************************************/

LIB(void) addition2(IN p_element valueL,
                    IN unsigned int valueLSize,
                    IN p_element valueM,
                    IN unsigned int valueMSize,
                    OUT p_element out);

/************************************************************/
/*  Функция прибвляет 1 к заданному числу                   */
/*                                                          */
/*  void increment(IN OUT p_element valueL);                */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL    - первое слагаемое                  */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element valueL - массив, в который будет помещен      */
/*                     результат инкрементирования          */
/*                                                          */
/************************************************************/

LIB(void) increment(IN OUT p_element valueL);

#endif