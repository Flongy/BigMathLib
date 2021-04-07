#ifndef LRS_H
#define LRS_H

/************************************************************/
/*  Функция получения новых членов рекурентной              */
/*  последовательности                                      */
/*                                                          */
/*                                                          */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*                                                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*                                                          */
/*                                                          */
/************************************************************/


LIB(void) getLrs(IN OUT unsigned short *a,
                 IN unsigned int F,
                 IN unsigned int f,
                 IN unsigned short size,
                 IN unsigned int count);

#endif