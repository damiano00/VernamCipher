//
// Created by Damiano Pasquini on 20/05/2021.
//

#ifndef VERNAMCIPHER_BVERNAN_H
#define VERNAMCIPHER_BVERNAN_H

/**
 * Function used to encode/decode an entire file
 * @param keyFile key file in input
 * @param inputFile file to encode/decode
 * @param outputFile output file where return the encoded or decoded function
 */
int encodeDecode(FILE* keyFile, FILE* inputFile, FILE* outputFile);

/**
 * Function used to encode/decode a single block
 * @param keyFile key file in input
 * @param inputFile file to encode/decode
 * @param outputFile output file where return the encoded or decoded function
 * @param currentBlock index used to obtain the current block to encode
 */
void encodeBlock(FILE* keyFile, FILE* inputFile, FILE* outputFile, long keyFileDim, int currentBlock);

/**
 * Function used to encode/decode a single last-block
 * @param keyFile key file in input
 * @param inputFile file to encode/decode
 * @param outputFile output file where return the encoded or decoded function
 * @param lastBlockDim dimension of the latest block in the input file (which could be less then a normal block)
 * @param totBlocksNum total number of blocks
 */
void encodeLastBlock(FILE* keyFile, FILE* inputFile, FILE* outputFile, long lastBlockDim, long keyFileDim, long totBlocksNum);

/**
 * Function that executes XOR logic operation between a char (from input) and another char (from key)
 * @param charToEncode character, given in input from the input file, to encode
 * @param keyChar character given in input to the function from key file, used to encode
 * @return the encoded character
 */
char encodeChar(char charToEncode, char keyChar);

/**
 * Function used to obtain file's size in bytes
 * @param filePointer file pointer given in input
 * @return long number
 */
long fileBytes(FILE* filePointer);

/**
 * Function that given in input all three file, check if is possible to encode/decode
 * @param keyFile
 * @param inputFile
 * @return 0 if length is ok, or -1 if is not ok
 */
int lengthCheck(long inputFileDim, long keyFileDim);

/**
 * Print key file and input file dimensions before the program execution
 * @param keyFile key file dimension
 * @param inputFile input file dimension
 */
void printDim(long keyFile, long inputFile);

#endif