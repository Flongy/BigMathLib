#include <stdio.h>
#include "BNumber.h"
#include "BNumIO.h"

int scanFile(IN char* path, 
             OUT p_element numptr)
{
    int i;
    FILE* ptr = fopen(path, "r");

    if (ptr == NULL)
    {
        return -1;
    }

    for (i = NUM_SIZE - 1; i >= 0; i--)
    {
        fscanf_s(ptr, "%X", &numptr[i]);
    }

    fclose(ptr);


    return 0;
}


int printFile(IN char* path,
              IN p_element numptr)
{
    FILE* fptr = fopen(path,"a");
    if (fptr == NULL)
        return -1;

    for (int i = NUM_SIZE - 1; i >= 0; i--)
    {
        fprintf(fptr, "%.8X ", numptr[i]);
    }
    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}


void printConsoleLE(IN p_element numptr) 
{
    for (int i = 0; i < NUM_SIZE; i++)
    {
        printf("%.8X ", numptr[i]);
    }
    printf("\n");
}

void printConsoleBE(IN p_element numptr)
{
    for (int i = NUM_SIZE - 1; i >= 0; i--)
    {
        printf("%.8X ", numptr[i]);
    }
    printf("\n");
}