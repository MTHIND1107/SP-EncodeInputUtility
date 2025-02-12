/*
 * FILE: fileIO.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: BHAWANJEET KAUR GILL (STUDENT ID: 8958829)
 * FIRST VERSION: 02/11/2025
 * DESCRIPTION: To validate the input and output files along with having
 *              the file's default to be stdin and stdout.
 */
#include "../inc/binary_to_asm.h"
#include "../inc/binary_to_srec.h"
#include "../inc/command_parser.h"
#include "../inc/fileIO.h"
#include "../inc/encode.h"
#include "binary_to_asm.c"
#include "binary_to_srec.c"
#include "command_parser.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Name    : inputFileValidation
 * Purpose : Validates and opens the input file for reading in binary mode.
 * Input   : char* inputFilename
 * Outputs : Prints an error message if the file cannot be opened.
 * Returns : FILE*
 */
FILE *inputFileValidation(char* inputFilename){
    FILE *inputFile = stdin;
    if (inputFilename) {
        inputFile = fopen(inputFilename, "rb");
        if (!inputFile) {
            fprintf(stderr, "Error: Cannot open input file %s\n", inputFilename);
            return NULL;
        }
    }
    return inputFile;
}
/*
 * Name    : outputFileValidation
 * Purpose : Validates and opens the output file for reading in binary mode.
 * Input   : char* outputFileValidation
 * Outputs : Prints an error message if the file cannot be opened.
 * Returns : FILE*
 */
FILE *outputFileValidation(char* outputFilename){
    FILE *outputFile = stdout;
    if (outputFilename){
        outputFile = fopen(outputFilename, "w");
        if (!outputFile) {
            fprintf(stderr, "Error: Cannot open output file %s\n", outputFilename);
            return NULL;
        }
    }
    return outputFile;
}