/**
 * @file holesum_functions.c
 * @author CW2 Kyle Spicer
 * @brief holesum_functions.c has the logic for functions declared in
 * holesum_functions.h.
 * @version 0.1
 * @date 2022-11-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "holesum_functions.h"

#include <stdio.h>
#include <stdlib.h>

void improper_argc_print_and_exit()
{
	printf("Error: incorrect commandline argument format\n");
	printf("Usage: ./holesum <filename>\n\n");
	printf("To see size of every hole in file use following format: \n");
	printf("Usage: ./holesum <filename> <all> \n\n");

}

void array_print(int **array, int rows, int columns)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("row[%d] column [%d] = %c\n", i, j, array[i][j]);
		}
		printf("\n");
	}
}

void array_destroy(int **array, int rows)
{
	for (int i = 0; i < rows; i++) {
		free(array[i]);
	}

	free(array);
	array = NULL;
}

int dfs(int **array, int outer, int inner, int row, int column)
{
	int hole_size = 0;
	/* keep track for out of bounds */
	if (outer < 0 || outer >= row || inner < 0 || inner >= column
	    || array[outer][inner] == '1') {
		return 0;
	}

	hole_size++;
	array[outer][inner] = '1';	// mark it as visited

	hole_size += dfs(array, outer, inner - 1, row, column);	// look left
	hole_size += dfs(array, outer - 1, inner, row, column);	// look above
	hole_size += dfs(array, outer, inner + 1, row, column);	// look right
	hole_size += dfs(array, outer + 1, inner, row, column);	// look below

	return hole_size;
}

/**
 * @brief if third commandline argument was "all", then program runs and
 * displays all hole sizes, number of holes, and largest hole.
 * 
 * @param argv 
 */
void display_all_hole_sizes(char *argv[])
{
	/* attempt to open argv[1] provided */
	FILE *fp = fopen(argv[0], "r");

	/*if file doesn't open, print error message, return 0 */
	if (!fp) {
		printf("Could not open \"%s\"\n\n", argv[0]);
		exit(1);
	}

	/* get total nodes, rows, and columns */
	int rows = 0;
	int total_nodes = 0;
	int columns = 0;

	/* get size of line */
	char buffer;
	char previous;
	do {
		buffer = fgetc(fp);
		// printf("%c ", buffer);
		if ('1' == buffer || '0' == buffer) {
			total_nodes++;
		}
		if ('\n' == buffer) {
			rows++;
		}
		if (EOF == buffer && '\n' != previous) {
			rows++;
		}
		previous = buffer;

	} while (EOF != buffer);

	columns = total_nodes / rows;

	/* create initial 2D array */
	int **array;

	/* allocatting memory for each row */
		array = calloc(rows, sizeof(*array));
		if (!array) {
			printf("Unable to allocate array for rows.\n");
			exit(1);
		}

		for (int i = 0; i < rows; i++) {
			/* allocatting memory for each node in each row */
			array[i] = calloc(columns, sizeof *(array[i]));
			if (!array[i]) {
				printf
				    ("Unable to allocate space for columns.\n");
				free(array);
				exit(1);
			}
		}

	rewind(fp);		// reset file pointer to beginning

	// iterate through input and populate 2D array with 1's and 0's
	int chr;		// store char from fgetc
	int r_track = 0;	// keep track of row count inside do while loop
	int c_track = 0;	// keep track of column count inside do while loop

	do {
		chr = fgetc(fp);

		if ('1' == chr || '0' == chr) {
			if (r_track < rows) {
				array[r_track][c_track] = chr;
				c_track++;
			}
			if (columns == c_track) {
				c_track = 0;
				r_track++;
			}
		}

	} while (EOF != chr);

	/* close file prior to exiting */
	fclose(fp);

	int num_holes = 0;
	int hole_size = 0;
	int largest_hole = 0;
	int current_hole = 1;

	for (int outer = 0; outer < rows; outer++) {
		for (int inner = 0; inner < columns; inner++) {
			if (array[outer][inner] == '0') {
				num_holes++;
				hole_size =
				    dfs(array, outer, inner, rows, columns);
				if (hole_size > 1) {
					printf("Hole #%d has %d holes.\n",
					       current_hole, hole_size);
				} else {
					printf("Hole #%d has %d hole.\n",
					       current_hole, hole_size);
				}
				current_hole++;
				if (hole_size > largest_hole) {
					largest_hole = hole_size;
				}
			}
		}
	}

	// /* free allocated memory */
	array_destroy(array, rows);

	/* answers to return to driver */
	printf("\nTotal holes =\t%d\n", num_holes);
	printf("Largest hole =\t%d\n", largest_hole);
}

/*** end of  file ***/
