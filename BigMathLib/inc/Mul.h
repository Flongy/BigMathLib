#ifndef	MUL_H
#define	MUL_H

/************************************************************/
/*  Функция умножения чисел                                 */
/*                                                          */
/*  void multiplication(IN p_element a,                     */
/*                      IN p_element b,                     */
/*                      OUT p_element output);              */
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

LIB(void) multiplication(IN p_element a,
                         IN p_element b,
                         OUT p_element output);

/************************************************************/
/*  Функция умножения чисел                                 */
/*                                                          */
/*  void multiplication2(IN p_element a,                    */
/*                       IN unsigned int sizeA,             */
/*                       IN p_element b,                    */
/*                       IN unsigned int sizeB,             */
/*                       OUT p_element output);             */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a            - первое слагаемое               */
/*  p_element b            - второе слагаемое               */
/*  unsigned int sizeA     - длина первого слагаемого       */
/*  unsigned int sizeB     - длина второго слагаемого       */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element output - массив, в который будет помещен      */
/*                     результат умножения                  */
/*                                                          */
/************************************************************/

LIB(void) multiplication2(IN p_element a,
                          IN unsigned int sizeA,
                          IN p_element b,
                          IN unsigned int sizeB,
                          OUT p_element output);


#endif