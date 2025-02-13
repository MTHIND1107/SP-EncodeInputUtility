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
        return -1;
    }

    unsigned char buffer[16];  // Buffer for grouping bytes
    size_t bytes_read;
    
    // Read up to 16 bytes at a time
    while ((bytes_read = fread(buffer, 1, 16, input)) > 0) {
        // Write directive and tab
        if (fprintf(output, "dc.b\t") < 0) {
            fprintf(stderr, "Error: Writing to output file failed.\n");
            return -1;
        }
        
        // Write bytes with proper formatting
        for (size_t i = 0; i < bytes_read; i++) {
            // Add comma and space between values, except for first value
            if (i > 0) {
                if (fprintf(output, ", ") < 0) {
                    fprintf(stderr, "Error: Writing to output file failed.\n");
                    return -1;
                }
            }
            
            // Write the byte in hex format with $ prefix
            if (fprintf(output, "$%02X", buffer[i]) < 0) {
                fprintf(stderr, "Error: Writing to output file failed.\n");
                return -1;
            }
        }
        
        // End the line
        if (fprintf(output, "\n") < 0) {
            fprintf(stderr, "Error: Writing to output file failed.\n");
            return -1;
        }
    }

    if (ferror(input)) {
        fprintf(stderr, "Error: Reading from input file failed.\n");
        return -1;
    }
    
    return 0;
}