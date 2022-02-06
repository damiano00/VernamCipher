//
// Created by Damiano Pasquini on 20/05/2021.
//

#include <stdio.h>
#include <time.h>
#include "bvernan.h"

int main(int argumentsNum, char** argumentPointer) {
    double timeSpentInSeconds = 0.0;
    clock_t startCalculateTime = clock();
    if(argumentsNum != 4) {
        printf("Wrong number of parameters (%d)\nExpected: bvernan keyfile inputfile outputfile\n", argumentsNum);
        clock_t stopCalculateTime = clock();
        timeSpentInSeconds += (double)(stopCalculateTime - startCalculateTime) / CLOCKS_PER_SEC;
        printf("The execution time is %f seconds\n", timeSpentInSeconds);
        return -1;
    }
    FILE* keyFilePointer = fopen(argumentPointer[1], "r");
    FILE* inputFilePointer = fopen(argumentPointer[2], "r");
    FILE* outputFilePointer = fopen(argumentPointer[3], "w");
    if (encodeDecode(keyFilePointer, inputFilePointer, outputFilePointer) == -1) {
        printf("File is not encrypted\n");
        clock_t stopCalculateTime = clock();
        timeSpentInSeconds += (double)(stopCalculateTime - startCalculateTime) / CLOCKS_PER_SEC;
        printf("The execution time is %f seconds\n", timeSpentInSeconds);
        return -1;
    } else {
        fclose(keyFilePointer);
        fclose(inputFilePointer);
        fclose(outputFilePointer);
        printf("The file is encrypted in: %s \n", argumentPointer[3]);
        clock_t stopCalculateTime = clock();
        timeSpentInSeconds += (double)(stopCalculateTime - startCalculateTime) / CLOCKS_PER_SEC;
        printf("The execution time is %f seconds\n", timeSpentInSeconds);
        return 0;
    }
}