 /*
 * FILE: input_handler.c
 * PROJECT: encodeInput
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 01/26/2025
 * DESCRIPTION:
 * This file contains the implementation of a function to handle user input,
 * detecting when CTRL-D is pressed at the beginning of a new line.
 */
 #include <stdio.h>
 #include <string.h>
 #include "../inc/input_handler.h"
 
/*
 * Name    : read_user_input
 * Purpose : Reads user input while properly handling the EOF (CTRL-D) condition.
 * Input   : buffer - char* - Buffer to store user input
 *           max_length - int - Maximum length of the input
 * Outputs : buffer is modified to store user input
 * Returns : int - 1 if input is successfully read, 0 if EOF is detected
 */
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
 