/** @file dinner-funcs.c
 *
 * @brief Contains logic for all functions declared in dinner.h
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Kyle Spicer. All rights reserved.
 */

#include "dinner.h"

// parse line from file and pack person
person_t *
make_person(char *temp_var)
{
    char temp_name[MAX_LINE_LENGTH];
    int  time_left = 0;

    // parse strings from file and
    temp_var[strcspn(temp_var, "\n")] = 0; // removes newline from fgets
    sscanf(temp_var, "%[^0-9] %d", temp_name, &time_left);

    person_t *person
        = calloc(1, sizeof(person_t)); // allocate memory for the struct

    if (!person)
    {
        perror("Unable to allocate array memory for struct.\n");
    }

    // copy temp variable name into struct
    strncpy(person->name, temp_name, sizeof(temp_name));
    
    // pack struct->time variable with info 
    person->time_left = time_left;

    return person;
}

// create loops for the amount of structs created
int
waiter_laps(person_t **container, int counter)
{
    char total_ate_per_loop[MAX_PEOPLE]; // variable to hold highest count
    int  total_loops = { 0 }; // loop counter

    // loop through all people, changing starting index each time
    //  records how many people were able to eat per loop
    for (int loop_count = 0; loop_count < counter; loop_count++)
    {
        total_ate_per_loop[loop_count]
            = individual_lap(container, counter, loop_count);
        total_loops++;
    }

    // loops through all totals and assigns the highest amount to variable
    int loop_with_most_fed = 0;
    for (int idx = 0; idx < total_loops; idx++)
    {
        if (total_ate_per_loop[idx] > loop_with_most_fed)
        {
            loop_with_most_fed = idx;
        }
    }
    return loop_with_most_fed;
}

// for each loop, calculate how many diners were able to eat during loop
int
individual_lap(person_t **container, int counter, int loop_count)
{
    int head_count  = 0; // keep count of who is done
    int total_ate    = 0; // record total people who ate
    int waiter_total = 0; // keep track of waiter time throughout loop

    // start comparing persons time with waiters time, determines who finished
    for (int idx = 0 + loop_count; idx < counter; idx++)
    {
        if (container[idx]->time_left <= waiter_total)
        {
            total_ate++; // records who was able to finish
        }
        waiter_total++; // add +1 minute to waiter total for each person
        head_count++; 
    }

    int difference = counter - head_count; // diff is needed to complete loop
    
    if (difference < counter) // loops for remaining diners
    {
        // loop to compare remaining diners to waiter total for loop
        for (int remaining = 0; remaining < difference; remaining++)
        {
            if (container[remaining]->time_left <= waiter_total)
            {
                total_ate++;
            }
            waiter_total++;
        }
    }
    return total_ate;
}

// prints the most efficient loop and which people ate
void
display_most_fed_order(person_t **container,
                       int        counter,
                       int        loop_with_most_fed)
{
    // formatted print statement for starting index for best loop
    printf("%s \t %d\n\n",
           container[loop_with_most_fed]->name,
           container[loop_with_most_fed]->time_left);

    int print_count  = 0;
    int total_ate    = 0;
    int waiter_total = 0;

    //keeping track and printing all diners who ate in the best loop
    for (int idx = loop_with_most_fed; idx < counter; idx++)
    {
        if (container[idx]->time_left <= waiter_total)
        {
            printf(
                "%s \t %d\n", container[idx]->name, container[idx]->time_left);
            total_ate++;
        }
        waiter_total++;
        print_count++;
    }

    // continues loop when last index is reached.
    int difference = counter - print_count; // diff is amount need to print
    if (difference < counter)
    {
        for (int remaining = 0; remaining < difference; remaining++)
        {
            if (container[remaining]->time_left <= waiter_total)
            {
                printf("%s \t %d\n",
                       container[remaining]->name,
                       container[remaining]->time_left);
                total_ate++;
            }
            waiter_total++;
        }
    }
}

// free individual allocations
void
clean_that_memory(struct person_t **container_for_arrays, int counter)
{
    // loops through and frees all allocated memory in container
    for (int idx = 0; idx < counter; idx++)
    {
        free(&(container_for_arrays[idx])->name);
    }

    // frees container's allocated memory
    free(container_for_arrays);
}

/*** end of file ***/