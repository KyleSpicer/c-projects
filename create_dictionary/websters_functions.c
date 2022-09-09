/** @file websters.c
 * 
 * @brief This file contains the functions and logic for the websters program. 
 * This program requires a user to enter up to ten word:definition combinations 
 * and writes the results to an external file called dictionary.txt.
 * 
 * @par
 * COPYRIGHT NOTICE (c) 2020 Spicer Group. All rights reserved.
 * 
 */

#include "websters.h"

// combines user entered word/definition with separator
char *
combine_definition(char *word, char *definition)
{
    char separator[]       = " : ";
    int  word_length       = strlen(word);
    int  definition_length = strlen(definition);
    int  separator_length  = strlen(separator);

    // need space to store complete definition size
    int   string_size = word_length + definition_length + separator_length + 1;
    char *completed_string = calloc(string_size, sizeof(char));

    // copy strings into dynamically allocated memory
    for (int idx = 0; idx < word_length; idx++)
    {
        completed_string[idx] = word[idx];
    }

    // add separator
    for (int idx = 0; idx < separator_length; idx++)
    {
        completed_string[word_length + idx] = separator[idx];
    }

    // add definition
    for (int idx = 0; idx < definition_length; idx++)
    {
        completed_string[word_length + separator_length + idx]
            = definition[idx];
    }

    completed_string[string_size - 1] = '\0'; // add null terminator to string

    return completed_string; // return completed definition
}

void
user_word_search(char **pp_completed_definitions, int counter)
{
    char word_search[C_WORD_BUFF]; // variable to hold user input
    char valid_search = false; // while loop will continue while false
    while (valid_search == false) 
    {
        printf("\nEnter word to search or exit to continue ==> ");
        fgets(word_search, C_WORD_BUFF, stdin); // send word to word_search
        word_search[strcspn(word_search, "\n")] = 0; // removes newline char

        if (strcmp("exit", word_search) == 0) // checks if user enters exit
        {
            break; // breaks while loop if "exit" is entered
        }

        // validates users word search with definitions entered.
        for (int idx = 0; idx < counter; idx++)
        {
            char *result;
            // checks if word is present in definition strings entered
            result = strstr(pp_completed_definitions[idx], word_search);

            // if found, print the result
            if (result != NULL)
            {
                printf("Definition # %d - %s\n", idx + 1, result);
                break;
            }
            
            // end of array is reached, no positive result. Loop starts again.
            if (idx == counter - 1)
            {
                printf("\n'%s' invalid search. Try again or enter 'exit'.",
                       word_search);
                break;
            }
        }
    }
}

// prints the list of complete definitions entered by user
void
print_completed_definitions(char **pp_completed_definitions)
{
    printf("\nCompleted list of definitions:\n");
    // loop to print all definitions and their index position.
    for (int idx = 0; idx < C_MAX_COMPLETED_DEFINITIONS; idx++)
    {
        if (pp_completed_definitions[idx] != NULL)
        {
            printf("Definition #%d - %s\n",
                   idx + 1,
                   pp_completed_definitions[idx]);
        }
    }
}

// open file and write to and read from it
void
create_and_populate_file(char **pp_completed_definitions)
{
    FILE *p_dictionary = fopen(DICTIONARY, "a+"); // creating file pointer
    if (p_dictionary == NULL) // if file cannot open, display error
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // writing complete definitions to file
    for (int index = 0; index < C_MAX_COMPLETED_DEFINITIONS; index++)
    {
        if (pp_completed_definitions[index] != NULL)
        {
            fputs(pp_completed_definitions[index], p_dictionary);
            fputs("\n", p_dictionary);
        }
    }

    rewind(p_dictionary); // reset file pointer to beginning of file for reading

    // ask user if they'd like to read from the file.
    char answer;
    while (answer != 'y' || answer != 'n')
    {
        printf("\nWould you like to read the file? (y/n) ==> ");
        scanf(" %c", &answer);

        // if yes, read contents of file(line by line) until EOF is reached.
        if (answer == 'y')
        {
            printf("\n------Contents of file-------\n\n");
            char line[C_COMPLETE_DEF_BUFF];
            while (fgets(line, C_COMPLETE_DEF_BUFF, p_dictionary) != NULL)
            {
                fputs(line, stdout);
                usleep(90000);
            }
            printf("\n-----End of file content-----\n");

            break;
        }
        if (answer == 'n')
        {
            printf("%c", answer);
            break;
        }
        printf("'%s' invalid input. Enter 'y' or 'n' to continue.\n", &answer);
    }

    // close the file
    fclose(p_dictionary); // closes file
}

/*** end of file ***/