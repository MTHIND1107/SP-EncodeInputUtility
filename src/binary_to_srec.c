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

    fprintf(output, "S007000053524543D1\n");

    while ((bytesRead = fread(buffer, 1, 16, input)) > 0) {
        int count = bytesRead + 3;
        unsigned char checksum = calculate_checksum(count, address, buffer);

        fprintf(output, "S1%02X%04X", count, address);
        for (size_t i = 0; i < bytesRead; i++) {
            fprintf(output, "%02X", buffer[i]);
        }
        fprintf(output, "%02X\n", checksum);

        address += 16;
    }

    fprintf(output, "S9030000FC\n");

    if (ferror(input)) {
        fprintf(stderr, "Error: Reading from input file failed.\n");
    }

    fclose(output);
}