/** @file check_splitter.c
 * 
 * @brief check_splitter.c is a unit testing program to test all functions that 
 * return something other than void.
 * 
 * @par COPYRIGHT NOTICE (c) 2022 Kyle Spicer.
 * 
 */

#include "../src/splitter.h"
#include <check.h>
 
START_TEST(test_valid_string_validation)
{
    char valid_string[MAX_INPUT_LENGTH] = "aabbcc";
    ck_assert(string_validation(valid_string));
} 
END_TEST

START_TEST(test_invalid_string_validation)
{
    char invalid_string[MAX_INPUT_LENGTH] = "1234aa   b b\\cc ";
    ck_assert(!string_validation(invalid_string));
} 
END_TEST

START_TEST(test_valid_compare_that_split_string)
{
    char left_split[MAX_INPUT_LENGTH] = "aba";
    char right_split[MAX_INPUT_LENGTH] = "bab";
    ck_assert(compare_that_split_string(left_split, right_split));
} 
END_TEST

START_TEST(test_invalid_compare_that_split_string)
{
    char left_split[MAX_INPUT_LENGTH] = "aa";
    char right_split[MAX_INPUT_LENGTH] = "ccbab";
    ck_assert(!compare_that_split_string(left_split, right_split));
} 
END_TEST

START_TEST(test_valid_unique_character_count)
{
    char word[MAX_INPUT_LENGTH] = "hello";
    ck_assert(unique_character_count(word) == 4);
} 
END_TEST

Suite *check_splitter(void)
{
    Suite *suite;
    TCase *tc_core;

    /* creates intial suite */
    suite = suite_create("splitter_test");

    /* confirms successful creation/deletion of structure before continuing*/
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_valid_string_validation);
    tcase_add_test(tc_core, test_invalid_string_validation);
    tcase_add_test(tc_core, test_valid_compare_that_split_string);
    tcase_add_test(tc_core, test_invalid_compare_that_split_string);
    tcase_add_test(tc_core, test_valid_unique_character_count);

    suite_add_tcase(suite, tc_core);

    return suite;
}


int main()
{
    /* creating Suite*/
    Suite *suite = check_splitter();
	SRunner *runner = srunner_create(suite);
    
    /* prevents confusing valgrind errors from displaying */
    srunner_set_fork_status(runner, CK_NOFORK);
    
    /* actual Suite Runner execution with desired verbosity level */
    srunner_run_all(runner, CK_VERBOSE);
    
    /* extracts results for exit code handling */
    int no_failed = srunner_ntests_failed(runner);
    
    /* free memory */
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
/*** end of file***/
