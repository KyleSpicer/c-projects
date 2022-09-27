/** @file dinner.c
 *
 * @brief Contains the main function logic for dinner program. Reads in a file,
 * creates memory allocated structs for each individual read in, determines the
 * most efficient loop iteration to let diners finish their meals before a
 * waiter collects their plates.
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Kyle Spicer. All rights reserved.
 */

#include "dinner.h"

int
main(int argc, char *argv[])
{
    // create file pointer, open, read from argv[1]
    FILE *p_file;

    if (argc != 2) // checks for valid file and argc #
    {
        char valid_file = false; // variable for while loop

        while (!valid_file) // loop for valid input
        {
            char user_file[MAX_FILE_NAME]; // temp var for user input
            printf("Enter a file name or exit to quit: ");
            fgets(user_file, MAX_FILE_NAME, stdin);  // receive stdin info
            user_file[strcspn(user_file, "\n")] = 0; // removes newline char
            p_file = fopen(user_file, "r"); // opens file from user input

            // exit loop condition
            if (strncmp(user_file, "exit", sizeof("exit")) == 0)
            {
                printf("\nYou have exited the program.\n");
                exit(EXIT_SUCCESS);
            }
            // if user input is still invalid, loop again
            if (!p_file)
            {
                perror("\nError opening file");
                valid_file = false;
            }
            // if user input is valid, break and continue with program
            else
            {
                valid_file = true;
            }
        }
    }
    else
    {
        // if arvg[1] was passed, utilize it as the file
        p_file = fopen(argv[1], "r");
    }

    // allocating space for container to hold struct pointers
    person_t **pp_dinner_roster = calloc(MAX_PEOPLE, sizeof(person_t *));

    // errors if memory couldn't be allocated
    if (!pp_dinner_roster)
    {
        perror("Unable to allocate array memory.\n");
        return 1;
    }

    // parse line from file and pack person struct
    char temp_name[MAX_LINE_LENGTH]; // temp var to hold line information
    int  counter = 0;                // keep count of structs

    //retrieves line as long as it's not NULL and less than 50
    while (fgets(temp_name, MAX_LINE_LENGTH, p_file) != NULL
           && (counter < MAX_PEOPLE))
    {
        // creating and packing structs
        pp_dinner_roster[counter] = make_person(temp_name);

        if (!pp_dinner_roster[counter])
        {
            break;
        }
        counter++;
    }

    // close file
    fclose(p_file);

    // variable for most efficient starting index
    int loop_idx_with_most_fed = waiter_laps(pp_dinner_roster, counter);

    // prints the most efficient loop and which people ate
    display_most_fed_order(pp_dinner_roster, counter, loop_idx_with_most_fed);

    // free all memory allocations
    clean_that_memory(pp_dinner_roster, counter); // free all allocated memory
}

/*** end of file ***/