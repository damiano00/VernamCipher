//
// Created by Damiano Pasquini on 20/05/2021.
//

#include <stdio.h>
#include "bvernan.h"

int encodeDecode(FILE* keyFilePointer, FILE* inputFilePointer, FILE* outputFilePointer) {
    long inputFileDim = fileBytes(inputFilePointer);
    long keyFileDim = fileBytes(keyFilePointer);
    long totBlocksNum = (inputFileDim/keyFileDim);
    printDim(keyFileDim, inputFileDim);
    if((lengthCheck(inputFileDim, keyFileDim)) == -1) return -1;
    else {
        fseek(inputFilePointer, 0, SEEK_SET);
        if((inputFileDim % keyFileDim) == 0) {
            for (int currentBlock = 0; currentBlock < totBlocksNum; currentBlock++)
                encodeBlock(keyFilePointer, inputFilePointer, outputFilePointer, keyFileDim, currentBlock);
        } else {
            for (int currentBlock = 0; currentBlock < totBlocksNum; currentBlock++)
                encodeBlock(keyFilePointer, inputFilePointer, outputFilePointer, keyFileDim, currentBlock);
            long lastBlockDim = inputFileDim-(keyFileDim*totBlocksNum);
            encodeLastBlock(keyFilePointer,inputFilePointer,outputFilePointer,lastBlockDim,keyFileDim,totBlocksNum);
        }
        return 0;
    }
}

void encodeBlock(FILE *keyFilePointer, FILE *inputFilePointer, FILE *outputFilePointer, long keyFileDim, int currentBlock) {
    fseek(inputFilePointer, 0, SEEK_CUR);
    for (int currentChar = 0; currentChar < keyFileDim; currentChar++) {
        fseek(keyFilePointer, ((currentBlock + currentChar) % keyFileDim), SEEK_SET);
        fputc(encodeChar((char)fgetc(inputFilePointer), (char)fgetc(keyFilePointer)), outputFilePointer);
    }
}

void encodeLastBlock(FILE* keyFilePointer, FILE* inputFilePointer, FILE* outputFilePointer, long lastBlockDim, long keyFileDim, long totBlocksNum){
    fseek(inputFilePointer, 0, SEEK_CUR);
    for(int currentChar = 0; currentChar < lastBlockDim; currentChar++){
        fseek(keyFilePointer, (totBlocksNum + currentChar) % keyFileDim, SEEK_SET);
        fputc(encodeChar((char)fgetc(inputFilePointer), (char)fgetc(keyFilePointer)), outputFilePointer);
    }
}

char encodeChar(char toEncodeChar, char keyChar){
    char encodedChar = (char)( (int)toEncodeChar ^ (int)keyChar );
    return encodedChar;
}

long fileBytes(FILE* filePointer){
    fseek(filePointer, 0, SEEK_END);
    long length = ftell(filePointer);
    return length;
}

void printDim(long keyFile, long inputFile){
    printf("Input file dimension: %ld bytes\nKey file dimension: %ld bytes\n", inputFile,keyFile);
}

int lengthCheck(long inputFileDim, long keyFileDim){
    if((inputFileDim > 0) && (keyFileDim > 0)){
        return 0;
    } else {
        if(inputFileDim == 0) printf("Error: input file dimension is %ld bytes\n", inputFileDim);
        if(keyFileDim == 0) printf("Error: key file dimension is: %ld bytes\n", keyFileDim);
        return -1;
    }
}