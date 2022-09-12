/**
 * Exercise 2
 * Write a program that prompts for three numbers.
 * Print the sum of the three numbers.
 * The program must use pointers to calculate the sum.
 **/


#include <stdio.h>

int
main()
{
    int one, two, three, total;
    int *p_one, *p_two, *p_three;

    printf("Enter three numbers separated by a space: ");
    scanf("%d %d %d", &one, &two, &three);

    p_one = &one;
    p_two = &two;
    p_three = &three;

    total = *p_one + *p_two + *p_three;

    printf("%d+%d+%d = %d\n", one, two, three, total);
}