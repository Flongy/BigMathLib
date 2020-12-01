#ifndef RESULTCODE_H
#define RESULTCODE_H

typedef enum {
    SUCCESSFULLY = 0,
    INVALID_INPUT_PARAMS = -1,
    OPERATION_EXCEPTION = -2,
    RUNTIME_ERROR = -3
} resultCode;

#endif
