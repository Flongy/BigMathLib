#ifndef CHECKBIGMATHLIBRESULT_H
#define CHECKBIGMATHLIBRESULT_H

#define CHECK_PASSED "Проверка пройдена\n"
#define CHECK_NOT_PASSED "Проверка не пройдена\n"

BOOL checkGcdExtendedResult(IN p_element a, 
                            IN p_element b, 
                            IN p_element x, 
                            IN p_element y, 
                            IN p_element d);

BOOL checkInverseResult(IN p_element a,
                        IN p_element m,
                        IN p_element result);

BOOL checkDiffieHellmanResult(IN p_testDiffieHellmanStruct resultStruct1,
                              IN p_testDiffieHellmanStruct resultStruct2);



void proccessCheckResult(IN BOOL checkResult);

#endif