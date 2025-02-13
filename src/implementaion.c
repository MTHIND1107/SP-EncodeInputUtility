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
    
    if (argc > 1) {
        if (!parse_command_line(argc, argv, mode, input_file, output_file)) {
        fprintf(stderr, "Invalid arguments. Usage: %s [-srec | -asm] <input_file>\n", argv[0]);
        return EXIT_FAILURE;
        }
    }
}

