/** @file websters_main.c
 *
 * @brief This file contains the main function for the websters program. This
 * program requires a user to enter up to ten word:definition combinations and
 * writes the results to an external file called dictionary.txt.
 *
 * @par
 * COPYRIGHT NOTICE (c) 2020 Spicer Group. All rights reserved.
 *
 */

#include "websters.h"

int
main()
{
    char **pp_completed_definitions; // pointer to a pointer of strings
    pp_completed_definitions
        = calloc(C_MAX_COMPLETED_DEFINITIONS, sizeof(char *));

    char *p_complete_definition = NULL;
    int   counter               = 0; // do while loop counter

    do
    {
        char word[C_WORD_BUFF];             // buffer for word entered
        char definition[C_DEFINITION_BUFF]; // buffer for definition entered

        printf("# %d - Enter a word: ", counter + 1);
        fgets(word, C_WORD_BUFF, stdin); // buffered word from input

        if (strcmp(EXIT_PARAM, word) == 0) // checks for exit
        {
            break; // breaks loop if "exit" is entered
        }

        printf("# %d - Enter definition: ", counter + 1);
        fgets(definition, C_DEFINITION_BUFF, stdin); // buff definition from input

        if (strcmp(EXIT_PARAM, definition) == 0) // checks for exit
        {
            break; // breaks loop if "exit" is entered
        }

        word[strcspn(word, "\n")] = 0; // removes newline char from fgets func
        definition[strcspn(definition, "\n")] = 0;

        p_complete_definition = combine_definition(word, definition);
        pp_completed_definitions[counter] = p_complete_definition;

        counter++;

    } while (counter < C_MAX_COMPLETED_DEFINITIONS);

    // prints the list of complete definitions entered by user
    print_completed_definitions(pp_completed_definitions);

    // prompt user to search for definition prior to writing to file.
    user_word_search(pp_completed_definitions, counter);

    // open file and write to and read from it
    create_and_populate_file(pp_completed_definitions);

    printf("\nThanks for using this program!\n");

    // free allocated memory
    for (int idx = 0; idx < C_MAX_COMPLETED_DEFINITIONS; idx++)
    {
        free(pp_completed_definitions[idx]);
    }

    free(pp_completed_definitions);
}

/*** end of file ***/