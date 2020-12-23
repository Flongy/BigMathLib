#ifndef DIFFIEHELLMAN_H
#define DIFFIEHELLMAN_H

/************************************************************************************/
/*  Функция получения общего ключа по протоколу                                     */
/*  Диффи-Хелмана                                                                   */
/*                                                                                  */
/*  int processJointKey(IN p_element base,                                          */
/*                      IN p_element mod,                                           */
/*                      IN int (*transferAndGet) (IN p_element, OUT p_element),     */
/*                      IN int randomNumberSeed,                                    */
/*                      IN void* extendedParams,                                    */
/*                      OUT p_element result);                                      */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  p_element base                                       - основание, которое будет */
/*                                                         возведено в степень      */
/*  p_element mod                                        - число, по которому будет */
/*                                                         взять модуль             */
/*  int (*transferAndGet) (IN p_element, OUT p_element)  - указатель на функцию,    */
/*                                                         с помощью которой будут  */
/*                                                         переданы и получены      */
/*                                                         данные между абонентами  */
/*  int randomNumberSeed                                 - параметр, определяющий   */
/*                                                         случайность              */
/*                                                         промежуточного числа     */
/*  void* extendedParams                                 - дополнительные параметры */
/*                                                                                  */
/*  Выходные параметры:                                                             */
/*                                                                                  */
/*  p_element result    - массив, в который будет помещен общий ключ                */
/*                                                                                  */
/************************************************************************************/

LIB(int) processJointKey(IN p_element base, 
                         IN p_element mod,
                         IN int (*transferAndGet) (IN p_element, IN void* extendedParams, OUT p_element),
                         IN int randomNumberSeed,
                         IN void* extendedParams,
                         OUT p_element result);

#endif
