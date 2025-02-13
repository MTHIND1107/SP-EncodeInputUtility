/*
 * FILE: binary_to_srec.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 02/10/2025
 * DESCRIPTION:
 * This file contains the implementation of functions that convert binary data into Motorola S-Record format. 
 * It ensures correct formatting, checksum calculation, and record structuring for valid SREC output.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_to_srec.h"

unsigned char calculate_checksum(int count, int address, unsigned char* data) {
    int sum = count + ((address >> 8) & 0xFF) + (address & 0xFF);
    for (int i = 0; i < count - 3; i++) {
        sum += data[i];
    }
    return (~sum) & 0xFF;
}

int convert_binary_to_srec(FILE *input, FILE *output) {
    if (!input || !output) {
        fprintf(stderr, "Error: Invalid file pointers provided.\n");
        return;
    }

    unsigned char buffer[16];
    int address = 0x0000;
    size_t bytesRead;
    int s1_record_count = 0;

     // Write S0 record
     int s0_count = 3 + 2;  // 2 bytes for address, 1 for checksum
     int s0_sum = s0_count + (0x0000 >> 8) + (0x0000 & 0xFF);
     unsigned char s0_checksum = (~s0_sum) & 0xFF;
     
     fprintf(output, "S0%02X0000%02X\n", s0_count, s0_checksum);

    while ((bytesRead = fread(buffer, 1, 16, input)) > 0) {
        int count = bytesRead + 3;
        unsigned char checksum = calculate_checksum(count, address, buffer);

        fprintf(output, "S1%02X%04X", count, address);
        for (size_t i = 0; i < bytesRead; i++) {
            fprintf(output, "%02X", buffer[i]);
        }
        fprintf(output, "%02X\n", checksum);

        address += bytesRead; 
        s1_record_count++;
    }


    if (ferror(input)) {
        fprintf(stderr, "Error: Reading from input file failed.\n");
        return -1;
    }

    // Write S5 record (count of S1 records)
    int s5_count = 3 + 2;  
    unsigned char s5_checksum = (~(s5_count + (s1_record_count >> 8) + (s1_record_count & 0xFF))) & 0xFF;
    fprintf(output, "S5%02X%04X%02X\n", s5_count, s1_record_count, s5_checksum);

    //Write S9 termination record
    fprintf(output, "S9030000FC\n");

    return 0;
}