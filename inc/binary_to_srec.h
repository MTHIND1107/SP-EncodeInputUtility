#ifndef BINARY_TO_SREC_H
#define BINARY_TO_SREC_H

#include <stdio.h>

unsigned char calculate_checksum(int count, int address, unsigned char* data);
int convert_binary_to_srec(FILE *input, FILE *output);

    
#endif