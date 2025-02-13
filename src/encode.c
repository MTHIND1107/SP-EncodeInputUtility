/*
 * FILE: encode.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: BHAWANJEET KAUR GILL (STUDENT ID: 8958829)
 * FIRST VERSION: 02/11/2025
 * DESCRIPTION:
 * This header file creates all the functions for encoding the functions altogether.
 */
#include "../inc/binary_to_asm.h"
#include "../inc/binary_to_srec.h"
#include "../inc/command_parser.h"
#include "../inc/fileIO.h"
#include "../inc/encode.h"
#include "binary_to_asm.c"
#include "binary_to_srec.c"
#include "command_parser.c"
#include "fileIO.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Name    : handleArguments
 * Purpose : selects the conversion format (ASM or SREC), and handles help requests.
 * Input   : int argc, char* argv 
 * Returns : int - Returns 0 on success, 1 if help is requested.
 */
int handleArguments(int argc, char *argv[]) {
    char* inputFilename = NULL;
    char* outputFilename = NULL;
    int srec = 0; //The value of srec is 0 by default and this will be directing to the asm conversion.
    int showHelp = 0; //By default is 0 but if asked for the help by the user, then converts to 1.
    int checkInputName = 0;
    int checkOutputName = 0;

    for(int i = 1; i < argc; i++){
        if(strncmp(argv[i], "-i", 2) == 0){
            inputFilename = argv[i] + 2;
            checkInputName = 1;
        }
        else if(strncmp(argv[i], "-o", 2) == 0){
            outputFilename = argv[i] + 2;
            checkOutputName = 1;
        }
        else if(strcmp(argv[i], "-srec") == 0){
            srec = 1; //To be converted to srec file.
        }
        else if(strcmp(argv[i], "-h") == 0)
        {
            printf("Usage: encodeInput [-iINPUTFILENAME] [-oOUTPUTFILENAME] [-srec] [-h]\n");
            return 1;
        }
        else {  // Invalid argument
            fprintf(stderr, "Error: Invalid option '%s'\n", argv[i]);
            printf("Usage: encodeInput [-i inputfile] [-o outputfile] [-srec] [-h]\n");
            return 1;
        }
    }
    dataSending(inputFilename, outputFilename, srec);
    return 0;
}
/*
 * Name    : dataSending
 * Purpose : Validates input and output file paths, opens the files, and 
 *           calls the conversion functions (ASM or SREC).
 * Input   : Nothing
 * Returns : void
 */
void dataSending(char* inputFilename, char* outputFilename, int srec){
    if(inputFilename != NULL && outputFilename == NULL){
        char baseName[256];  // Buffer to store the base name
        strncpy(baseName, inputFilename, sizeof(baseName) - 1);
        baseName[sizeof(baseName) - 1] = '\0';

        char *dot = strrchr(baseName, '.'); 
        if (dot != NULL) {
            *dot = '\0';
        }
        strcpy(outputFilename, inputFilename);
        strcat(outputFilename, srec ? ".srec":".asm");

    }
    FILE* inputData = inputFileValidation(inputFilename);
    FILE* outputData = outputFileValidation(outputFilename);
    if(srec){
        convert_binary_to_srec(inputData, outputData);
    }
    else{
        convert_binary_to_asm(inputData, outputData);
    }
}