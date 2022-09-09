/** @file websters.h
 * 
 * @brief This header file contains includes, defines, and function declarations
 * for use within the program websters.
 * 
 * @par
 * COPYRIGHT NOTICE (c) 2020 Spicer Group. All rights reserved.
 * 
 */

#ifndef WEBSTERS_H
#define WEBSTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define DICTIONARY "my_dictionary.txt" // name of file to write to
#define EXIT_PARAM "exit\n"         // to exit loop if user enters "exit"

#define C_MAX_COMPLETED_DEFINITIONS 10  // max number of
#define C_WORD_BUFF                 25  // max length of word entered
#define C_DEFINITION_BUFF           250 // max length of definition entered
#define C_COMPLETE_DEF_BUFF         280 // WORD + DELIMINATOR + DEFINITION

// functions located in websters.c
// combines user entered word/definition with separator
char *combine_definition(char *word, char *definition);

// allows user to enter a word and returns completed definition
void user_word_search(char **pp_completed_definitions, int counter);

// prints the list of complete definitions entered by user
void print_completed_definitions(char **pp_completed_definitions);

// open file and write to and read from it
void create_and_populate_file(char **pp_completed_definitions);

#endif /* WEBSTERS_H */

/*** end of file ***/