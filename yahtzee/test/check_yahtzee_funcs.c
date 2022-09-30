#include <check.h>

#include "../src/yahtzee.h"

START_TEST(test_valid_die_roll)
{
    ck_assert_int_gt(7, die_roll());
    ck_assert_int_lt(0, die_roll());

}
END_TEST

START_TEST(test_valid_how_many_players) 
{
    
}
END_TEST

Suite *check_yahtzee_funcs(void)
{
    Suite *suite;
    TCase *tc_core; // test case __ core

	suite = suite_create("yahtzee_tests");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_valid_die_roll);
    tcase_add_test(tc_core, test_valid_how_many_players);

	suite_add_tcase(suite, tc_core);

    return suite;
}

int main(void)
{
    Suite *suite = check_yahtzee_funcs();
    SRunner *runner = srunner_create(suite); //Holds state for a running test suite

    // Prevents valigrind errors from appearing that could be mistakenly be
	// considered the programmers fault. Will run slower! For details, see:
    
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_VERBOSE);

    // Extract results for exit code handling
	int no_failed = srunner_ntests_failed(runner);

    // free() all resources used for execution of Suite Runner.
    srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* end of file */