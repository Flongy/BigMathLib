#include <stdio.h>
#include "BNumber.h"
#include "NumIO.h"

int _scanFile(IN char* path, 
              OUT p_element numptr) {

    int i;
    FILE* ptr = fopen(path, "r");

    if (ptr == NULL) {
        return -1;
    }

    for (i = NUM_SIZE - 1; i >= 0; i--) {
        fscanf_s(ptr, "%X", &numptr[i]);
    }

    fclose(ptr);

    return 0;
}


int _printFile(IN char* path,
               IN p_element numptr) {

    FILE* fptr = fopen(path,"a");
    if (fptr == NULL)
        return -1;

    for (int i = NUM_SIZE - 1; i >= 0; i--) {
        fprintf(fptr, "%.8X ", numptr[i]);
    }
    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

void printConsoleLE(IN p_element numptr) {
    printConsoleLE2(numptr, NUM_SIZE);
}

void printConsoleLE2(IN p_element numptr, unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("%.8X ", numptr[i]);
    }
    printf("\n");
}

void printConsoleBE(IN p_element numptr) {
    printConsoleBE2(numptr, NUM_SIZE);
}

void printConsoleBE2(IN p_element numptr, unsigned int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%.8X ", numptr[i]);
    }
    printf("\n");
}