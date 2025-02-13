#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIo.h"
#include "binary_to_srec.h"
#include "binary_to_asm.h"
#include "command_parser.h"

int main(int argc, char *argv[]) { 
    if (handleArguments (argc, argv) != 0) { 
         return EXIT_FAILURE; 
    } 
    return EXIT_SUCCESS; 
} 
