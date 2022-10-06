/** @file splitter.h
 *
 * @brief splitter-funcs.c holds all the function definitions for use within the
 * splitter program.
 *
 * @par COPYRIGHT NOTICE (c) 2022 Kyle Spicer.
 *
 */

#include "splitter.h"

/* displays proper usage of program and exits */
void
display_error_message()
{
    printf("\nUsage: ./splitter <file.txt> or ./splitter\n");
    printf("\nExiting program.\n\n");
    exit(1);
}

/* error message for invalid string */
void
display_invalid_string(char *string)
{
    printf("\n\"%s\" is an invalid input.\n", string);
    printf("valid input is a maximum of 128 alphabetic characters only.\n\n");
}

/* accepts second argument to use with program */
void
file_provided(char argv[])
{
    FILE *p_file;              // file pointer for user provided file
    p_file = fopen(argv, "r"); // open file

    char line_from_file[MAX_INPUT_LENGTH]; // place holder for each line

    if (!p_file)
    {
        printf("Error opening file\n");
        display_error_message();
    }

    else
    {
        // start loop for reading lines
        while ((fgets(line_from_file, MAX_INPUT_LENGTH, p_file)) != NULL)
        {
            line_from_file[strcspn(line_from_file, "\n")] = 0; // removes
                                                               // newline
            int line_length = strlen(line_from_file);

            if (string_validation(line_from_file) == false
                || line_length > MAX_LINE_LENGTH)
            {
                display_invalid_string(line_from_file);
            }

            else
            {
                string_splitter(line_from_file);
                printf("\n");
            }
        }
    }

    fclose(p_file); // close file
}

/* with no CL arg passed, prompts for user input */
void
user_input_for_program()
{
    char user_input[MAX_INPUT_LENGTH];

    printf("Please enter a sequence of notes to find good splits: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // removes newline

    // if invalid string, exit program with message
    if (string_validation(user_input) == false)
    {
        display_invalid_string(user_input);
        exit(1);
    }

    // if string is valid, continue program
    else
    {
        string_splitter(user_input);
    }
}

/* validates proper string input */
bool
string_validation(char *string)
{
    int length = strlen(string); // number of chars in string

    if (length < 1)
    {
        return false;
    }

    for (int idx = 0; idx < length; idx++)
    {
        if (isspace(string[idx]) || isblank(string[idx]))
        {
            return false;
        }
        else if (isalpha(string[idx]) == false)
        {
            return false;
        }
    }

    return true;
}

/* split input with a comma */
void
string_splitter(char *string)
{
    int   length = strnlen(string, MAX_INPUT_LENGTH);
    char *left_side;
    char *right_side;
    int   ptr         = 0;
    bool  good_string = false;

    printf("%s: ", string); // display entire string for output

    for (int idx = 0; idx < length - 1; idx++)
    {
        left_side  = strndup(string, idx + 1);
        right_side = &string[ptr + 1];

        if ((good_string = compare_that_split_string(left_side, right_side)))
        {
            printf("%s,", left_side);
            printf("%s  ", right_side);
        }
        ptr++;

        free(left_side); // free allocated memory from duplication
    }

    printf("\n"); // clean up printed output for readibility
}

/* count unique chars on left and right side of pointer */
bool
compare_that_split_string(char *left_side, char *right_side)
{
    int left_uniques  = unique_character_count(left_side);
    int right_uniques = unique_character_count(right_side);

    // compares the difference of unique chars
    int compare = left_uniques - right_uniques;

    if (compare == 0)
    {
        return true;
    }

    return false;
}

int
unique_character_count(char *split_string_side)
{
    int length                   = strlen(split_string_side);
    int uniques[NUM_ASCII_CHARS] = { 0 }; // track unique chars in string
    int unique_count             = 0;     // counter for unique chars

    for (int idx = 0; idx < length; idx++)
    {
        uniques[(int)split_string_side[idx]]
            = 1; // assign 1 to idx if char exists
    }

    // count number of 1's in array
    for (int idx = 0; idx < NUM_ASCII_CHARS; idx++)
    {
        unique_count += uniques[idx];
    }

    return unique_count;
}

/* end of file */