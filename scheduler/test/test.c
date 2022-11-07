/**
 * @file test.c
 * @author CW2 Kyle Spicer
 * @brief test.c will provide unit testing for functions created in scheduler.c
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// #include "../src/scheduler.c" // added .c before .h for opaque data type access
#include "../src/scheduler.h"


#include <stdio.h>
#include <stdlib.h>
#include <check.h>

START_TEST(test_valid_idle)
{
    // verifies idle function return -1 if job count is not 0
    scheduler * test_scheduler;
    test_scheduler = create(4);
    test_scheduler->job_count = 0;
    ck_assert(idle(test_scheduler) == 0);

}END_TEST

START_TEST(test_invalid_idle)
{
    // verifies idle function return 1 if job count is not 0
    scheduler * test_scheduler;
    test_scheduler = create(4);
    ck_assert(idle(test_scheduler) == 1);

}END_TEST

START_TEST(test_valid_queue_create)
{
    // verifies queue_create was successful by checking test_queue != NULL
    queue_t * test_queue;
    test_queue = queue_create(2);
    ck_assert(test_queue != NULL);

}END_TEST

START_TEST(test_invalid_queue_create)
{
    // verifies queue_create was unsuccessful by checking test_queue == NULL
    queue_t * test_queue;
    test_queue = queue_create(0);
    ck_assert(test_queue == NULL);

}END_TEST

START_TEST(test_valid_scheduler_create)
{
    // verifies scheduler was created with valid input
    scheduler * test_scheduler;
    test_scheduler = create(5);
    ck_assert(test_scheduler != NULL);

}END_TEST

START_TEST(test_invalid_scheduler_create)
{
    // verifies scheduler was not created with invalid input

    scheduler * test_scheduler;
    test_scheduler = create(0);
    ck_assert(test_scheduler == NULL);
    
}END_TEST

START_TEST(test_valid_queue_enqueue)
{
    // verifies queue did not return NULL with valid input
    queue_t * test_queue;
    test_queue = queue_create(4);
    queue_enqueue(test_queue, 4);
    ck_assert(test_queue != NULL);
}END_TEST

START_TEST(test_invalid_queue_enqueue)
{
    // verifies queue function returned NULL with invalid input
    queue_t * test_queue;
    test_queue = queue_create(4);
    ck_assert(queue_enqueue(test_queue, -1) == NULL);
    printf("test_invalid_queue_enqueue: returned print statment \"bad value\"\n\n");
}END_TEST

START_TEST(test_valid_queue_dequeue)
{
    // verifies dequeue function does not return NULL on valid input
    queue_t * test_queue;
    test_queue = queue_create(4);
    queue_enqueue(test_queue, 2);
    ck_assert(queue_dequeue(test_queue) != NULL);
}END_TEST

START_TEST(test_invalid_queue_dequeue)
{
    // verifies dequeue function returns NULL on invalid input
    queue_t * test_queue;
    test_queue = queue_create(4);
    queue_enqueue(test_queue, 0);
    ck_assert(queue_dequeue(test_queue) == NULL);
}END_TEST

START_TEST(test_valid_current_job)
{
    // verify current job function returns current job
    scheduler * test_scheduler;
    test_scheduler = create(4);
    test_scheduler->finish_count = 4;
    ck_assert(current_job(test_scheduler) == 4);
}END_TEST

START_TEST(test_valid_awt)
{
    // verifies awt function calculates properly
    scheduler * test_scheduler;
    test_scheduler = create(4);
    test_scheduler->sum_wait_time = 20;
    test_scheduler->finish_count = 4;
    ck_assert(average_wait_time(test_scheduler) == 5.0);
}END_TEST

Suite * check_scheduler_suite(void)
{
    Suite * suite;
    TCase * tc_core;

    // creates initial suite
    suite = suite_create("scheduler_test");

    // confirms successful creation/deletion of structures
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_valid_idle);
    tcase_add_test(tc_core, test_invalid_idle);
    tcase_add_test(tc_core, test_valid_queue_create);
    tcase_add_test(tc_core, test_invalid_queue_create);
    tcase_add_test(tc_core, test_valid_scheduler_create);
    tcase_add_test(tc_core, test_invalid_scheduler_create);
    tcase_add_test(tc_core, test_valid_queue_enqueue);
    tcase_add_test(tc_core, test_invalid_queue_enqueue);
    tcase_add_test(tc_core, test_valid_queue_dequeue);
    tcase_add_test(tc_core, test_valid_current_job);
    tcase_add_test(tc_core, test_valid_awt);




    


    


    suite_add_tcase(suite, tc_core);
	return suite;
}

int main(void)
{
    // creating Suite
    Suite * suite = check_scheduler_suite();
	SRunner * runner = srunner_create(suite);

    // prevents confusing valgrind errors from displaying
    srunner_set_fork_status(runner, CK_NOFORK);

    // actual suite runner execution with desired verbosity level
    srunner_run_all(runner, CK_VERBOSE);

    // extracts results from exit code handling
    int no_failed = srunner_ntests_failed(runner);

    // free memory
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/*** end of file ***/ 