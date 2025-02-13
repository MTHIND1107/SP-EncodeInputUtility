 #include <stdio.h>
 #include <string.h>
 #include "../inc/input_handler.h"
 
 int read_user_input(char *buffer, int max_length) {
     // Prompt user for input
     printf("Enter input (CTRL-D to exit): ");
 
     // Read a line from standard input
     if (fgets(buffer, max_length, stdin) == NULL) {
         // CTRL-D detected at the beginning of a line
         return 0;  // Indicate EOF condition
     }
 
     // Remove newline character if present
     buffer[strcspn(buffer, "\n")] = '\0';
 
     return 1;  // Successful input read
 }
 