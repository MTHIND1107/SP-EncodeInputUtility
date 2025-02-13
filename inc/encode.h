/*
 * FILE: encode.h
 * PROJECT: encodeInput Utility
 * PROGRAMMER: BHAWANJEET KAUR GILL (STUDENT ID: 8958829)
 * FIRST VERSION: 02/11/2025
 * DESCRIPTION:
 * This header file declares the functions for encoding the functions altogether.
 */
#include "binary_to_asm.h"
#include "binary_to_srec.h"
#include "command_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handleArguments(int argc, char *argv[]);
void dataSending(char* inputFilename, char* outputFilename, int srec);
