#ifndef BUDGET_H
#define BUDGET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* parameters */
#define MAX_ENTRIES     10 // max expense/amount combos
#define MAX_EXPENSE_LEN 20 // max length of expense name
#define MAX_USER_INCOME 10

/* defining budget struct */
typedef struct budget_t
{
    char  expense_label[MAX_EXPENSE_LEN];
    float amount;
} budget_t;

/* function prototypes located in budget-functions.c */

// displays program intent to console/user
void introduction_script();

// creates struct for each index in container (expense/amount)
budget_t *make_expense(int counter);

// sum up all the expenses
float sum_and_print_expenses(struct budget_t **container_for_arrays,
                            int counter);

void
line_breaker();

float create_user_income_for_budget();

// display all entered expenses and amounts
void display_all_expenses_amounts(struct budget_t **container_for_arrays,
                                  int counter);

// calculate remaining balance from user income minus budget expense
float budget_expense_diff(float budget, float total_expenses);

// free individual allocations
void clean_that_memory(struct budget_t **container_for_arrays, int counter);

#endif /* BUDGET_H */

/** end of file **/