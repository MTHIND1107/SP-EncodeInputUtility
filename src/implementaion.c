#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIo.h"
#include "binary_to_srec.h"
#include "binary_to_asm.h"
#include "command_parser.h"

int main(int argc, char *argv[]) {
    // Parse command-line arguments
    char mode[10];
    char input_file[256];
    char output_file[256];
    
    if (!parse_command_line(argc, argv, mode, input_file, output_file)) {
        fprintf(stderr, "Invalid arguments. Usage: %s [-srec | -asm] <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Generate output file name based on mode
    strcpy(output_file, input_file);
    char *dot = strrchr(output_file, '.');
    if (dot) {
        *dot = '\0'; // Remove existing extension
    }
    strcat(output_file, (strcmp(mode, "-srec") == 0) ? ".s19" : ".asm");
    
    // Open input file
    FILE *input_fp = open_file(input_file, "rb");
    if (!input_fp) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return EXIT_FAILURE;
    }
    
    // Read file content
    size_t file_size;
    unsigned char *data = read_file_content(input_fp, &file_size);
    close_file(input_fp);
    
    if (!data) {
        fprintf(stderr, "Error reading file content: %s\n", input_file);
        return EXIT_FAILURE;
    }
    
    // Open output file
    FILE *output_fp = open_file(output_file, "w");
    if (!output_fp) {
        fprintf(stderr, "Error creating output file: %s\n", output_file);
        free(data);
        return EXIT_FAILURE;
    }
    
    // Perform the conversion
    if (strcmp(mode, "-srec") == 0) {
        convert_binary_to_srec(data, file_size, output_fp);
    } else if (strcmp(mode, "-asm") == 0) {
        convert_binary_to_asm(data, file_size, output_fp);
    } else {
        fprintf(stderr, "Unsupported mode: %s\n", mode);
        free(data);
        close_file(output_fp);
        return EXIT_FAILURE;
    }
    
    // Cleanup
    free(data);
    close_file(output_fp);
    
    printf("Operation successful: %s -> %s\n", input_file, output_file);
    return EXIT_SUCCESS;
}
