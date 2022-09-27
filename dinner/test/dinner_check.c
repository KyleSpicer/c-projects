#include <check.h>
#include <stdlib.h>
#include <stdio.h>

#include "../src/dinner.h"

int main (void)
{
    Suite *suite = check_dinner_suite();
    SRunner *runner = srunner_create(suite);

    // Prevents valigrind errors from appearing that could be mistakenly be
	// considered the programmers fault. Will run slower!
    srunner_set_fork_status(runner, CK_NOFORK);

    // Actual Suite Runner command of execution with desired verbosity level
    srunner_run_all(runner, CK_VERBOSE);

    // Extract results for exit code handling
	int no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}