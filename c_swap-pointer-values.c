/**
 * Exercise 3
 * Write a program that contains a function to swap two integers and another 
 * that swaps two characters.
 * The program should print the before and after values to verify the swap occurred.
 * The program must use pointers.
 **/

#include <stdio.h>

void swap_int(int *x, int *y);
void swap_char(char *first, char *second);

void swap_int(int *x, int *y)
{
    int temp;
    temp = *x;
    *x   = *y;
    *y   = temp;
}

void swap_char(char *first, char *second)
{
    char temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int 
main()
{
    int  num1, num2;
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);
    printf("BEFORE: num1 = %d num2 = %d\n", num1, num2);
    swap_int(&num1, &num2);
    printf(" AFTER: num1 = %d num2 = %d\n\n", num1, num2);

    char charone, chartwo;
    printf("Enter two characters separated by a space: ");
    scanf(" %c %c", &charone, &chartwo);
    printf("BEFORE: charone = %c chartwo = %c\n", charone, chartwo);
    swap_char(&charone, &chartwo);
    printf(" AFTER: charone = %c chartwo = %c\n", charone, chartwo);
}