/*
 * FILE: binary_to_srec.h
 * PROJECT: encodeInput Utility
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 02/10/2025
 * DESCRIPTION:
 * This header file declares functions for encoding binary input into Motorola S-Record format.
 */
#ifndef BINARY_TO_SREC_H
#define BINARY_TO_SREC_H

#include <stdio.h>

unsigned char calculate_checksum(int count, int address, unsigned char* data);
int convert_binary_to_srec(FILE *input, FILE *output);

    
#endif