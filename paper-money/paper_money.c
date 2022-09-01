/** @file paper_money.c
 * 
 * @brief paper_money.c  -  This program identifies the amount of each 
 * denomintations to be returned. The denominations accounted for are 
 * 1, 2, 5, 10, 20, 50, and 100 dollar bills.
 * 
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Kyle Spicer. All rights reserved.
 */

#include <stdio.h>
#include <string.h>

#include "paper_money.h"



int denoms[] = { 100, 50, 20, 10, 5, 2, 1 }; // global var for denominations

int
main ()
{
    // calling first function to begin program
    generate_dollar_amounts(1);
}

/*!
 * @brief generate_dollar_amounts accepts an integer and will complete an
 *equation 21 times to achieve the repitition results required by the exam.  
 *
 * @param (int n) An integer passed that acts as the starting dollar amount. 
 */

void
generate_dollar_amounts (int n)
{
    int money_array[21];
    do
    {
        int num        = n * (99 + n);
        money_array[n] = num;
        n              = n + 1;

    } while (n < 22); // n goes to 21

    for (int i = 1; i < 22; i++)
    {
        dollar_breakdown_and_print(money_array[i]);
    }
} /* generate_dollow_amounts(int n) */

/*!
 * @brief dollar_breakdown_and_print(int num) receives an integer and calculates
 * the change, in correct bill denominations, and prints the number passed
 * and the correct number of bills for each denomination.
 *
 * @param (int n) An integer passed that represents a dollar amount.
 *
 */
void
dollar_breakdown_and_print (int num)
{
    printf("Given %d, you get back :\n", num);

    int num_chars = sizeof(denoms) / sizeof(int);

    for (int i = 0; i < num_chars; i++)
    {
        int remainder          = num / denoms[i];
        int amount_to_subtract = remainder * denoms[i];
        num                    = num - amount_to_subtract;
        if (remainder > 0)
            printf("%d $%d bills\n", remainder, denoms[i]);
    }
    printf("\n");

} /* dollar_breakdown_and_print */

/*** end of file ***/