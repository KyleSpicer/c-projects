/** @file dinner.h
 *
 * @brief Header file for dinner.c program.
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022. Kyle Spicer. This software is placed in the
 * public domain and may be used for any purpose.
 */

#ifndef DINNER_H
#define DINNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// constants
#define MAX_PEOPLE      50
#define MAX_LINE_LENGTH 100
#define WAITER_TIME     1
#define MAX_FILE_NAME   25

// defining struct for program
typedef struct person_t
{
    char name[MAX_LINE_LENGTH];
    int  time_left;
} person_t;

// function declarations for dinner-funcs.c

// parse line from file and return person struct
person_t *make_person(char *temp_var);

// create loops for the amount of structs created
int waiter_laps(person_t **container, int counter);

// for each loop, calculate how many diners were able to eat
int individual_lap(person_t **container, int counter, int loop_count);

// prints the most efficient loop and which people ate
void display_most_fed_order(person_t **container,
                            int        counter,
                            int        loop_with_most_fed);

// free all memory allocations
void clean_that_memory(struct person_t **container_for_arrays, int counter);

#endif /* DINNER_H */

/*** end of file ***/