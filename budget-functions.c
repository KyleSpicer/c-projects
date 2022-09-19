#include "budget.h"

// displays program intent to console/user
void
introduction_script()
{
    printf("\n\nWelcome to the basic budget tool!\n");
    printf("You can enter up to %d name/amount combinations.\n", MAX_ENTRIES);
    printf("If you are done making entries, enter 'done' to continue.\n");
}

// creates struct for each index in container (expense/amount)
budget_t *
make_expense(int counter)
{
    char  name[MAX_EXPENSE_LEN];   // temp variable for user input
    char  amount[MAX_EXPENSE_LEN]; // temp variable for user input
    float act_amount = 0;          // temp variable to house converted int

    printf("\nEnter expense #%d (up to 20 characters): ",
           counter + 1);                 // enter expense name
    fgets(name, MAX_EXPENSE_LEN, stdin); // places user input in temp variable
    fflush(stdin);                       // cleans stdin

    // if user enters done, program will break and return to main
    if (strncmp(name, "done\n", sizeof("done\n")) == 0)
    {
        return NULL;
    }

    printf("Enter expense #%d amount: ", counter + 1); // enter expense amount
    fgets(amount, MAX_EXPENSE_LEN, stdin); // places user input in temp variable
    act_amount = atof(amount);             // converts fgets string to float

    budget_t *expense
        = calloc(1, sizeof(budget_t)); // allocate memory for the struct
    name[strcspn(name, "\n")] = 0;     // removes newline from fgets func
    strncpy(
        expense->expense_label, name, strlen(name)); // copy name into struct
    expense->amount = act_amount; // assign actual integer to struct amount

    printf("\n%d) name: %s\n", counter + 1, expense->expense_label);
    printf("%d) amount: $%.2f\n", counter + 1, expense->amount);

    return expense;
}

// display all entered expenses and amounts
void
display_all_expenses_amounts(struct budget_t **container_for_arrays,
                             int counter)
{
    line_breaker();
    printf("\nExpenses  \t\t\t\t   Amount\n");
    printf("---------   \t\t\t\t   ------");

    for (int idx = 0; idx < counter; idx++)
    {
        printf("\nExpense #%d: %-30s $%.2f\n",
               idx + 1,
               container_for_arrays[idx]->expense_label,
               container_for_arrays[idx]->amount);
    }
}

// sum and print all user entered expenses
float
sum_and_print_expenses(struct budget_t **container_for_arrays, int counter)
{
    float total_expenses = 0;

    for (int idx = 0; idx < counter; idx++)
    {
        total_expenses += container_for_arrays[idx]->amount;
    }

    return total_expenses;
}

// retrieve user income for budget
float create_user_income_for_budget()
{
    char temp[MAX_USER_INCOME];
    float user_income;

    printf("\nEnter income amount: ");
    fgets(temp, MAX_USER_INCOME, stdin);
    
    user_income = atof(temp);
    return user_income;
}

// free individual allocations
void
clean_that_memory(struct budget_t **container_for_arrays, int counter)
{
    for (int idx = 0; idx < counter; idx++)
    {
        free(&(container_for_arrays[idx])->expense_label);
    }

    free(container_for_arrays);
}

// prints a line of '-' for display purposes
void
line_breaker()
{
    printf("\n-----------------------------------------------------------\n");
}

// calculate remaining balance from user income minus budget expense
float budget_expense_diff(float budget, float total_expenses)
{
    float remaining = budget - total_expenses;

    return remaining;
}

// realloc
// switch statement

/** end of file **/