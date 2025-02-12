/*
 * FILE: binary_to_asm.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 01/26/2025
 * DESCRIPTION:
 * This file contains the implementation of a function that converts binary data 
 * into an assembly-formatted string using the "DB" directive.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_to_asm.h"

/*
 * Name    : convert_binary_to_asm
 * Purpose : Converts binary data from an input file into assembly format and writes to an output file.
 * Input   : input  - FILE* - Pointer to the binary input file
 *           output - FILE* - Pointer to the assembly output file
 * Outputs : Writes assembly-formatted data to the output file.
 * Returns : void
 */
int convert_binary_to_asm(FILE *input, FILE *output) {
    if (!input || !output) {  // Check for valid file pointers
        fprintf(stderr, "Error: Invalid file pointers provided.\n");
        return;
    }

    unsigned char byte;
    
    // Read each byte from the binary file and convert to assembly DB directive
    while (fread(&byte, 1, 1, input)) {
        if(fprintf(output, "DB 0x%02X\n", byte) < 0) {  // Write to output file
            fprintf(stderr, "Error: Writing to output file failed.\n");
            return;
        }  
    }

    if (ferror(input)) {  // Check if file reading had an error
        fprintf(stderr, "Error: Reading from input file failed.\n");
    }    
}