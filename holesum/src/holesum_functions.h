/**
 * @file holesum_functions.h
 * @author CW2 Kyle Spicer
 * @brief holesum.h holds function prototypes for use with holesum.c
 * @version 0.1
 * @date 2022-11-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HOLESUM_FUNCS_H
#define HOLESUM_FUNCS_H

/**
 * @brief prints informative error and program usage statement
 * 
 */
void improper_argc_print_and_exit();

/**
 * @brief displays visual representation and values associated with 2D array
 * 
 * @param array - 2D array with values
 * @param rows - total number of rows (so program knows the size)
 * @param columns - total number of columns (so program knows the size) 
 */
void array_print(int **array, int rows, int columns);

/**
 * @brief frees all allocations associated with 2D array, frees 2D array and
 * sets array memory address to NULL.
 * 
 * @param array - 2D array with values
 * @param rows - total number of rows (so program knows the size)
 */
void array_destroy(int **array, int rows);

/**
 * @brief conducts a depth first search on 2D array (strictly an array with
 * 1's and 0's)
 * 
 * @param array - 2D array with values
 * @param outer - position of current for loop (to traverse each column)
 * @param inner - position of current nested loop (to traverse each row)
 * @param row  - total number of rows (so program knows the size)
 * @param column - total number of columns (so program knows the size)
 * @return int - returns the size of the current hole searched
 */
int dfs(int **array, int outer, int inner, int row, int column);

/**
 * @brief if argv[2] was "all", program is ran so that every holes size, number 
 * of holes, and largest hole size are all via stdout.
 * 
 * @param argv 
 */
void display_all_hole_sizes(char *argv[]);

#endif				/* HOLESUM_FUNCS_H */

/*** end of  file ***/
