/**
 * @brief scheduler_test.h holds the declarations for the structs and functions
 * for use within scheduler_driver.c
 * 
 * @param to be included with scheduler_test.h
 */

//------------------------------------------------------------------------------
// Practical Exam I: job scheduler
//------------------------------------------------------------------------------
#ifndef __SCHEDULER_TEST_H
#define __SCHEDULER_TEST_H
#define JOBCOUNT 10

struct scheduler_test_case
{
  int size;
  int arrival_time[JOBCOUNT];
  int job_time[JOBCOUNT];
  int job_map_time[JOBCOUNT]; 
  int job_time_preempt[JOBCOUNT];
  int end_time_static[JOBCOUNT];
  int end_time_variable[JOBCOUNT];
  int end_time_preempt[JOBCOUNT];
  int wait_time_static[JOBCOUNT];
  int wait_time_variable[JOBCOUNT];
  int wait_time_preempt[JOBCOUNT];
  double awt_static;
  double awt_variable;
  double awt_preemptive;
};
struct scheduler_test_case test1 = {
  5,
  {0,4,5,6,6},
  {4,5,2,3,1},
  {1,2,3,4,5},
  {4,2,1,3,5},
  {1,3,6,10,15},
  {4,9,11,14,15},
  {4,7,8,11,15},
  {0,1,3,6,10},
  {0,0,4,5,8},
  {0,0,1,2,6},
  4.00,
  3.40,
  1.80
};
struct scheduler_test_case test2 = {
  5,
  {0,1,2,4,5},
  {3,8,6,4,2},
  {2,3,4,6,8},
  {3,2,4,6,8},
  {2,5,9,15,23},
  {3,11,17,21,23},
  {3,7,10,15,23},
  {0,2,5,9,15},
  {0,2,9,13,16},
  {0,0,2,7,14},
  6.20,
  8.00,
  4.60
};
struct scheduler_test_case test3 = {
  7,
  {0,2,4,4,5,5,5},
  {2,8,3,6,2,1,4},
  {1,2,2,3,4,6,8},
  {2,1,3,2,4,8,6},
  {1,3,5,8,12,18,26},
  {2,10,13,19,21,22,26},
  {2,6,8,10,14,20,26},
  {0,1,3,5,8,12,18},
  {0,0,6,9,14,16,17},
  {0,0,1,3,5,10,16},
  6.71,
  8.86,
  5.00
};
struct scheduler_test_case test4 = {
  10,
  {0,2,3,4,4,6,6,7,12,27},
  {2,14,12,2,9,3,16,1,1,2},
  {1,1,2,2,2,3,9,12,14,16},
  {2,2,1,3,1,9,2,12,14,16},
  {1,2,4,6,8,11,20,32,46,62},
  {2,16,28,30,39,42,58,59,60,62},
  {2,6,8,10,13,20,29,33,46,62},
  {0,1,2,4,6,8,11,20,32,46},
  {0,0,13,24,26,33,36,51,47,33},
  {0,0,0,1,0,7,0,18,30,40},
  13.00,
  26.30,
  9.60
};
#endif

/*** end of file ***/