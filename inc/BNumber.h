#ifndef BNUMBER_H
#define BNUMBER_H

#define IN
#define OUT

#ifndef True
#define True 1
#endif

#ifndef False
#define False 0
#endif

#define BYTE_LEN 8
#define NUM_SIZE 2

#define ZERO_SIZE 1
static unsigned int zero = 0;

typedef unsigned int element;
typedef element *p_element;

typedef unsigned char BOOL;

#ifdef BIGMATHLIB_EXPORTS
#define BIGMATHLIB_API __declspec(dllexport)
#else
#define BIGMATHLIB_API __declspec(dllimport)
#endif

#ifdef __cplusplus
#define REF extern "C"
#else
#define REF
#endif

#define LIB(type) REF BIGMATHLIB_API type

#define ZEROING(number) memset(number, 0, NUM_SIZE * sizeof(element))
#define COPY(from, to) memcpy(to, from, NUM_SIZE * sizeof(element))

#endif BNUMBER_H