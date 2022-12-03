/**
 * @file holesum.c
 * @author CW2 Kyle Spicer
 * @brief holesum.c is a program to complete the tests from the holesum_driver
 * program. The goal of this holesum program is to read a file and identify
 * the "holes" in the data file. The file consists of an M x N matrix of ascii
 * characters. The grid consists of only 1's and 0's. We are to filter out the 
 * excess characters to create this grid, identify the amount of holes (0's) and 
 * report the amount of holes and the largest hole recorded for each file
 * executed.
 * @date 2022-11-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "holesum_functions.h"

int main(int argc, char *argv[])
{
	/* if argv[2] is "all", program displays all hole sizes, largest hole, and
	   number of holes from file */
	if (argc == 3) {
		int result = strcmp("all", argv[2]);
		if (result == 0) {
			display_all_hole_sizes(argv + 1);
		} else {
			improper_argc_print_and_exit();
			exit(1);
		}
	}

	/* verify argc is 2, else exit program */
	else if (argc != 2) {
		improper_argc_print_and_exit();
		exit(1);
	}

	else {
		/* attempt to open argv[1] provided */
		FILE *fp = fopen(argv[1], "r");

		/*if file doesn't open, print error message, return 0 */
		if (!fp) {
			printf("Could not open \"%s\"\n\n", argv[1]);
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
			if(0 == total_nodes && '\0' == buffer){
				printf("Thanks for checking /dev/zero\n");
				exit(1);
			}
			if ('\n' == buffer && '\n' == previous) {
				goto NEXT_ROUND;
			}
			if ('1' == buffer || '0' == buffer) {
				total_nodes++;
			}
			if ('\n' == buffer) {
				rows++;
			}
			if (EOF == buffer && '\n' != previous) {
				rows++;
			}
 			NEXT_ROUND:
			previous = buffer;

		} while (EOF != buffer);

		/* determine number of columns */
		columns = total_nodes / rows;

		/* checking to ensure columns and rows create proper matrix */
		if (total_nodes != (columns * rows) || !rows || !columns) {
			printf("Invalid input detected.\n");
			exit(1);
		}

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
			array[i] = calloc(columns, sizeof( *(array[i])));
			if (!array[i]) {
				printf
				    ("Unable to allocate space for columns.\n");
				free(array);
				exit(1);
			}
		}

		rewind(fp);	// reset file pointer to beginning

		// iterate through input and populate 2D array with 1's and 0's
		char chr = '\0';	// store char from fgetc
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

		for (int outer = 0; outer < rows; outer++) {
			for (int inner = 0; inner < columns; inner++) {
				if (array[outer][inner] == '0') {
					num_holes++;
					hole_size =
					    dfs(array, outer, inner, rows,
						columns);
					if (hole_size > largest_hole) {
						largest_hole = hole_size;
					}
				}
			}
		}

		// /* free allocated memory */
		array_destroy(array, rows);

		/* answers to return to driver */
		printf("Total holes =\t%d\n", num_holes);
		printf("Largest hole =\t%d\n", largest_hole);
	}
	return 0;
}

/*** end of  file ***/
