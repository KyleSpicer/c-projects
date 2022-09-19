#include "budget.h"

int
main()
{
    // allocating space for container
    budget_t **pp_array_expenses = calloc(MAX_ENTRIES, sizeof(budget_t *));

    // errors if memory couldn't be allocated
    if (!pp_array_expenses)
    {
        perror("Unable to allocate array memory.\n");
        return 1;
    }

    // displays program intent to console/user
    introduction_script();

    int counter = 0; // track num of created elements

    // creates struct for each index in container (expense/amount)
    for (int idx = 0; idx < MAX_ENTRIES; idx++)
    {

        pp_array_expenses[idx] = make_expense(idx);
        if (!pp_array_expenses[idx])
        {
            break;
        }
        // recording num elements to utilize throughout program
        counter++;
    }

    // display all entered expenses and amounts
    display_all_expenses_amounts(pp_array_expenses, counter);

    // sum and print all user entered expenses
    float total_expenses = sum_and_print_expenses(pp_array_expenses, counter);
    printf("\n\t\t\t\t    Total: $%.2f\n", total_expenses);
    line_breaker();

    // get user income to use with program
    float user_income = user_income = create_user_income_for_budget();
    printf("\nTotal income for budget: $%.2f\n", user_income);
    line_breaker();

    // diff between budget and expenses
    float remaining_balance = budget_expense_diff(user_income, total_expenses);
    printf("\nRemaining balance after deductions: $%.2f\n", remaining_balance);
    line_breaker();

    // free individual allocations and container
    clean_that_memory(pp_array_expenses, counter);

    printf("Thanks for using this budget tool!\n\n");
}

/** end of file **/