/** @file splitter.h
 *
 * @brief splitter.h is the header file that contains all libraries, constants,
 * and function declarations (prototypes) for splitter.c program
 *
 * @par COPYRIGHT NOTICE (c) 2022 Kyle Spicer.
 *
 */

#ifndef SPLITTER_H
#define SPLITTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 500
#define MAX_LINE_LENGTH  128
#define NUM_ASCII_CHARS  128

/* displays proper usage of program and exits */
void display_error_message();

/* error message for invalid string */
void display_invalid_string(char *string);

/* accepts second argument to use with program */
void file_provided(char argv[]);

/* with no CL arg passed, prompts for user input */
void user_input_for_program();

/* validates proper string input */
bool string_validation(char *string);

/* splits each string into two sections at each index for use in program */
void string_splitter(char *string);

/* count unique chars on left and right side of pointer */
bool compare_that_split_string(char *left_side, char *right_side);

/* calculates unique number of characters from two substrings */
int unique_character_count(char *split_string_side);

#endif /* SPLITTER_H */

/*** end of file ***/