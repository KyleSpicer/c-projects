/**
 * Exercise 4
 * Write a function with the following signature:
 * int calculateLength(char *);
 * which accepts a string from the console and prints the string length.
 * The function should determine the length by counting the characters 
 * using pointers.
 * 
 */

#include <stdio.h>
#include <string.h>

int calculateLength(char *string);

int calculateLength(char *string)
{
    int ctr = 0; // counter
    while(*string != '\0') // string = base addy of string array (string[0])
    {
        ctr++;
        string++;
    }
    return ctr;
}

int
main()
{
    char string[25];
    int  str_length;

    printf("Input a string (up to 25 characters): ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0;

    str_length = calculateLength(string);
    printf("The length of the '%s' is %d characters.\n", string, str_length);
}