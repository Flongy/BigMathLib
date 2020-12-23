#ifndef MOD_H
#define MOD_H

/************************************************************/
/*  Функция возведения в степень по модулю                  */
/*                                                          */
/*  LIB(void) powerMod(IN p_element base,                   */
/*                     IN p_element power,                  */
/*                     IN p_element mod,                    */
/*                     OUT p_element result);               */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element base    - основание                           */
/*  p_element power   - степень                             */
/*  p_element mod     - модуль                              */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element result    - массив, в который будет помещен   */
/*                        результат возведения в степень    */
/*                        по модулю                         */
/*                                                          */
/************************************************************/


LIB(void) powerMod(IN p_element base, 
                   IN p_element power,
                   IN p_element mod, 
                   OUT p_element result);

#endif