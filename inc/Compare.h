#ifndef COMPARE_H
#define COMPARE_H

#define SIGN_BIT_MASK 0x80000000
#define SIGN_BIT_SHIFT 31

/************************************************************/
/*  Функция сравнения двух чисел, заданных массивами слов   */
/*                                                          */
/*  int Compare(IN p_element valueL,                        */
/*              IN p_element valueM,                        */
/*              IN unsigned int sizeL,                      */
/*              IN unsigned int sizeM);                     */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL        - первый операнд                */
/*  p_element valueM        - второй операнд                */
/*  unsigned int  sizeL     - длина первого операнда        */
/*  unsigned int  sizeM     - длина второго операнда        */
/*                                                          */
/*  Возвращаемое значение:                                  */
/*                                                          */
/*  -1  - второй операнд больше первого операнда            */
/*   0  - первый и второй операнд равны                     */
/*   1  - первый операнд больше второго операнда            */
/*                                                          */
/************************************************************/

LIB(int) Compare(p_element valueL,
                 p_element valueM,
                 unsigned int sizeL,
                 unsigned int sizeM);

/************************************************************/
/*  функция сравения и замены чисел                         */
/*                                                          */
/*  BOOL CompareAndSwap(IN OUT p_element a,                 */
/*                      IN OUT p_element b);                */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a     - первое число                          */
/*  p_element b     - второе число                          */
/*                                                          */
/*  Возвращаемое значение:                                  */
/*                                                          */
/*  True, если была произведена замена, или False, если     */
/*  замена не была произведена                              */
/*                                                          */
/*  Заметки:                                                */
/*                                                          */
/*  - если "b" больше "a", то "a" будет помещено            */
/*    в "b", а "b" будет помещено в "a"                     */
/*  - если "a" больше "b", то никаких изменений не будет    */
/*    произведено                                           */
/*                                                          */
/************************************************************/

LIB(BOOL) CompareAndSwap(IN OUT p_element a,
                         IN OUT p_element b);

/************************************************************/
/*  Функция замены чисел                                    */
/*                                                          */
/*  void Swap(IN OUT p_element a,                           */
/*            IN OUT p_element b);                          */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element a     - первое число                          */
/*  p_element b     - второе число                          */
/*                                                          */
/************************************************************/

LIB(void) Swap(IN OUT p_element a,
               IN OUT p_element b);

#endif