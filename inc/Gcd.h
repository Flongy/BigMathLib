#ifndef GCD_H
#define GCD_H

/************************************************************/
/*  Функция нахождения НОД двух чисел (a, b)                */
/*                                                          */
/*  int gcd(IN p_element a,                                 */
/*          IN p_element b,                                 */
/*          OUT p_element result);                          */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a     - первое число                          */
/*  p_element b     - второе число                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result    - массив, в который будет           */
/*                        помещен НОД                       */
/*                                                          */
/************************************************************/

LIB(int) gcd(IN p_element a,
             IN p_element b,
             OUT p_element result);

/************************************************************/
/*  Функция нахождения множителей чисел, относительно       */
/*  которых находится НОД                                   */
/*                                                          */
/*  решение уравнения: a * x + b * y = (a, b)               */
/*                                                          */
/*  int gcdExtended(IN p_element a,                         */
/*                  IN p_element b,                         */
/*                  OUT p_element result,                   */
/*                  OUT p_element x,                        */
/*                  OUT p_element y);                       */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a         - первое число                      */
/*  p_element b         - второе число                      */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result    - массив, в который будет помещен   */
/*                        НОД                               */
/*  p_element x         - массив, в который будет помещено  */
/*                        найденное число x                 */
/*  p_element y         - массив, в который будет помещено  */
/*                        найденное число y                 */
/*                                                          */
/************************************************************/

LIB(int) gcdExtended(IN p_element a,
                     IN p_element b,
                     OUT p_element result,
                     OUT p_element x,
                     OUT p_element y);

#endif