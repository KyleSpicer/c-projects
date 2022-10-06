/** @file splitter.h
 *
 * @brief splitter program receives a string of alphabet characters. Splits the
 * string and displays which substrings contain an even amount of unique
 * characters. (ex. ababab: aba, bab ab, abab, abab, ab
 *
 * @par COPYRIGHT NOTICE (c) 2022 Kyle Spicer.
 *
 */

#include "splitter.h"

int
main(int argc, char *argv[])
{
    if (argc == 2)
    {
        file_provided(argv[1]);
    }

    else if (argc > 2)
    {
        printf("\nToo many command line arguments provided.\n");
        display_error_message();
    }

    else
    {
        user_input_for_program();
    }
}

/* end of file */