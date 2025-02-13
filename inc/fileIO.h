/*
 * FILE: fileIO.h
 * PROJECT: encodeInput Utility
 * PROGRAMMER: BHAWANJEET KAUR GILL (STUDENT ID: 8958829)
 * FIRST VERSION: 02/11/2025
 * DESCRIPTION: Header file for the file input output validation
 */
#include "binary_to_asm.h"
#include "binary_to_srec.h"
#include "command_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
FILE *inputFileValidation(char* inputFile);
FILE *outputFileValidation(char* outputFile);