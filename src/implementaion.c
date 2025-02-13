#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIo.h"
#include "binary_to_srec.h"
#include "binary_to_asm.h"
#include "command_parser.h"
#include "input_handler.h"

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
    else {
    // No arguments provided; switch to interactive mode
    printf("No command-line arguments detected. Switching to interactive mode.\n");
    }
      // Ask for mode
      printf("Enter mode (-srec or -asm): ");
      if (!read_user_input(mode, sizeof(mode))) {
          printf("\nEOF detected. Exiting...\n");
          return EXIT_SUCCESS;
      }

      // Validate mode
      if (strcmp(mode, "-srec") != 0 && strcmp(mode, "-asm") != 0) {
          fprintf(stderr, "Invalid mode. Use -srec or -asm.\n");
          return EXIT_FAILURE;
      }

      // Ask for input file
      printf("Enter input file name: ");
      if (!read_user_input(input_file, sizeof(input_file))) {
          printf("\nEOF detected. Exiting...\n");
          return EXIT_SUCCESS;
      }
    
    printf("Operation successful: %s -> %s\n", input_file, output_file);
    return EXIT_SUCCESS;
}

