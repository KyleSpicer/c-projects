/**
 * @brief scheduler_driver.c is the main source file for our practical exam.
 * 
 * @param #include "sheduler.h", #include "scheduler_test.h"
 * 
 */
//------------------------------------------------------------------------------
// Practical Exam I (A): job scheduler
//
// Print debug statements: Compile with -D__DEBUG__
//------------------------------------------------------------------------------
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <err.h>
#include <sys/time.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include "scheduler.h"
#include "scheduler_test.h"
#define HALT_DEDUCTION 1
#define TEST_TOTAL 30
#define POINT_TOTAL 114
static const int point[TEST_TOTAL] = {
  6, 1, 6, 1, 6, 1, 1,
  6, 1, 6, 1, 6, 1, 1,
  8, 1, 8, 1, 8, 1, 1,
  11, 1, 11, 1, 11, 1, 1,
  3, 2
};
static int testcount = 0;
static int pass = 0;
static int fail = 0;
struct timespec ts = {0, 1};
int clock_time = 0;
struct
{
  int index;
  int* map_time;
  int* job_time;
  int* end_time;
  int* wait_time;
} test_data;
static const  char* header =
"\n----------------------------------------------------------------------------\
---";
static const  char* section =
"-----------------------------------section------------------------------------\
-";
static const  char* footer =
"------------------------------------------------------------------------------\
-\n\n";
//-------------------------------------------------------------------------------
int cmp(const void* c1, const void* c2)
{
  int x = *(int*)c1;
  int y = *(int*)c2;
  return (x < y) ? -1 : x == y ? 0 : 1;
}
//-------------------------------------------------------------------------------
int* random_job(int n, int t)
{
  // Unordered sequence of n random, non-unique numbers.
  //
  // A job must take more than t=0 time.
  int* a = (int*)malloc(n*sizeof(int));
  srand(clock());
  for (int i = 0; i < n; ++i)
  {
    a[i] = (rand() % t) + 1;
  }
  return a;
}
//-------------------------------------------------------------------------------
int* random_arrival(int n, int t)
{
  // Ordered sequence of n random, non-unique numbers.
  //
  // First arrival at t=0.
  int* a = (int*)malloc(n*sizeof(int));
  a[0] = 0;
  srand(clock());
  for (int i = 1; i < n; ++i)
  {
    a[i] = rand() % t;
  }
  qsort(a, n, sizeof(int), &cmp);
  return a;
}
//-------------------------------------------------------------------------------
void standardize_job(int n, int* j, int* t)
{
  // No gaps between arrival and completion time.
  //
  // Ensure each successive job arrives before the previous completes.
  int sum = 0;
  for (int i = 1; i < n; ++i)
  {
    sum += j[i];
    if (sum < t[i])
    {
      t[i] = sum;
    }
  }
}
//-------------------------------------------------------------------------------
void test_idle(scheduler* s, int t)
{
  printf("Is scheduler idle? %s\n", idle(s) ? "true" : "false");
  if (idle(s) == t)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Empty returned = %d but should %d\n", idle(s), t);
  }
}
//-------------------------------------------------------------------------------
int ticktock()
{
  clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ts, 0);
  return ++clock_time;
}
//-------------------------------------------------------------------------------
void test_job_status(scheduler* s, int t, int w)
{
  int* mt = test_data.map_time;
  int* jt = test_data.job_time;
  int* et = test_data.end_time;
  int* wt = test_data.wait_time;
  int i = test_data.index;
  int success = 1;
  int j = mt[current_job(s)];
  printf("dequeued job %d at time %d with wait time %d\n", j, t, w);
  if (j != jt[i])
  {
    success = 0;
    printf("\tFAIL! Got job %d but should be %d\n", j, jt[i]);
  }
  if (t != et[i])
  {
    success = 0;
    printf("\tFAIL! Got finish time %d but should be %d\n", t, et[i]);
  }
  if (w != wt[i])
  {
    success = 0;
    printf("\tFAIL! Got wait time %d but should be %d\n", w, wt[i]);
  }
  if (success)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  test_data.index = ++i;
}
//-------------------------------------------------------------------------------
void noop(scheduler* s, int t, int w)
{
  (void)s;
  (void)t;
  (void)w;
}
//-------------------------------------------------------------------------------
void report()
{
  puts(header);
  printf("Final Report!\n");
  printf("Completed %d out of %d tests\n", testcount, TEST_TOTAL);
  printf("Total earned points = %d\n", pass);
  printf("Total possible points = %d\n", POINT_TOTAL);
  printf("Final score: %3.2f%%\n", (double)pass/POINT_TOTAL*100);
  puts("");
  printf("Points distribution:\n");
  for (int i = 0; i < TEST_TOTAL; ++i)
  {
    printf("Problem #%d:\t%d points\n", i+1, point[i]);
  }
  puts(footer);
}
//-------------------------------------------------------------------------------
void signal_handler(int signal, siginfo_t* info, void* context)
{
  (void)context;
  puts(header);
  puts("");
  printf("EXECUTION PREMATURELY HALTED!\n");
  printf("Caught signal (%d): %s\n", info->si_signo, strsignal(signal));
  printf("Fail at memory address: %p\n", info->si_addr);
  puts("");

  // Count incomplete tests.
  --testcount;
  int remain = TEST_TOTAL - testcount;

  // Sum up remaining points.
  int skip = POINT_TOTAL - pass;

  // Point status.
  printf("Current points = %d\n", pass);
  printf("Missed points due to %d incomplete test(s) = %d\n", remain, skip);
  if (pass > 0 ) --pass;
  printf("Points after deducting %d point(s) for unexpected error = %d\n",
         HALT_DEDUCTION, pass);

  // Report
  report();
  exit(1);
}
//-------------------------------------------------------------------------------
int main(void)
{
  struct timeval t1;
  struct timeval t2;
  double time = 0.0;
  struct sigaction sa;

  // Signal handling.
  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = signal_handler;
  sigaction(SIGSEGV, &sa, NULL);
  sigaction(SIGABRT, &sa, NULL);
  sigaction(SIGILL, &sa, NULL);
  sigaction(SIGBUS, &sa, NULL);
  sigaction(SIGFPE, &sa, NULL);

  // Declarations specific to this exercise.
  const int BIGN = 10000;
  const int TEST_CASE_TOTAL = 4;
  char numstr[20];
  double awt = 0.0;

  // Test loop.
  struct scheduler_test_case test[4] = {test1, test2, test3, test4};
  int subtest = 0;
  int testcase = 0;
  for (int T = 0; T < TEST_CASE_TOTAL; ++T)
  {
    testcase = T+1;
    subtest = 0;
    const int N = test[T].size;

    // Create job scheduler with capacity N.
    scheduler* js = create(N);


    // New test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Process jobs where all jobs arrive at time t=0\n");

    // Test.
    puts(section);
    clock_time = 0;
    test_data.index = 0;
    test_data.map_time = test[T].job_map_time;
    test_data.job_time = test[T].job_map_time;
    test_data.end_time = test[T].end_time_static;
    test_data.wait_time = test[T].wait_time_static;
    schedule_static(js,
                    N,
                    test[T].job_time,
                    &ticktock,
                    &test_job_status);
  
    // Verify no jobs to process.
    test_idle(js, 1);
    puts(footer);


    // New Test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Report average wait time\n");
    
    // Test.
    puts(section);
    awt = average_wait_time(js);
    sprintf(numstr, "%.2f", awt);
    sscanf(numstr, "%lf", &awt);
  
    // Verify average wait time.
    printf("\tAverage wait time should be %f\n", test[T].awt_static);
	  if (fabs(awt - test[T].awt_static) < DBL_EPSILON)
    {
      ++pass;
      printf("\tPASS!\n");
    }
    else
    {
      ++fail;
      printf("\tFAIL! Average wait time = %f but should %f\n",
             awt, test[T].awt_static);
    }
    puts(footer);
  

    // New test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Process jobs arriving at various times\n");

    // Test.
    puts(section);
    restart(js);

    // First job arrives at t=0.
    clock_time = 0;
    test_data.index = 0;
    test_data.map_time = test[T].job_time;
    test_data.job_time = test[T].job_time;
    test_data.end_time = test[T].end_time_variable;
    test_data.wait_time = test[T].wait_time_variable;
    schedule_variable(js,
                      N,
                      test[T].job_time,
                      test[T].arrival_time,
                      &ticktock,
                      &test_job_status);

    // Verify no jobs to process.
    test_idle(js, 1);
    puts(footer);


    // New Test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Report average wait time\n");

    // Test.
    puts(section);
    printf("Report average wait time\n");
    awt = average_wait_time(js);
    sprintf(numstr, "%.2f", awt);
    sscanf(numstr, "%lf", &awt);
  
    // Verify average wait time.
    printf("\tAverage wait time should be %f\n", test[T].awt_variable);
	  if (fabs(awt - test[T].awt_variable) < DBL_EPSILON)
    {
      ++pass;
      printf("\tPASS!\n");
    }
    else
    {
      ++fail;
      printf("\tFAIL! Average wait time = %f but should %f\n", awt,
             test[T].awt_variable);
    }
    puts(footer);


    // New test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Process jobs arriving at various times with preemption\n");

    // Test.
    puts(section);
    restart(js);

    // First job arrives at t=0.
    clock_time = 0;
    test_data.index = 0;
    test_data.map_time = test[T].job_time;
    test_data.job_time = test[T].job_time_preempt;
    test_data.end_time = test[T].end_time_preempt;
    test_data.wait_time = test[T].wait_time_preempt;
    schedule_preemptive(js,
                        N,
                        test[T].job_time,
                        test[T].arrival_time,
                        &ticktock,
                        &test_job_status);

    // Verify no jobs to process.
    test_idle(js, 1);
    puts(footer);


    // New Test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Report average wait time\n");
  
    // Test.
    puts(section);
    awt = average_wait_time(js);
    sprintf(numstr, "%.2f", awt);
    sscanf(numstr, "%lf", &awt);
  
    // Verify average wait time.
    printf("Average wait time should be %f\n", test[T].awt_preemptive);
	  if (fabs(awt - test[T].awt_preemptive) < DBL_EPSILON)
    {
      ++pass;
      printf("\tPASS!\n");
    }
    else
    {
      ++fail;
      printf("\tFAIL! Average wait time = %f but should %f\n",
             awt, test[T].awt_preemptive);
    }
    puts(footer);


    // New test.
    puts(header);
    printf("Test #%d of Test Case #%d:\n", ++subtest, testcase);
    printf("Destroy scheduler\n");

    // Test.
    puts(section);
    destroy(&js);

    // Verify deletion.
    if (js == 0)
    {
      ++pass;
      printf("\tPASS!\n");
    }
    else
    {
      printf("\tFAIL! Queue exists\n");
    }
    puts(footer);

    // Finishing test loop.
    testcount += subtest;
  }
  

  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);
  printf("Performance tests\n");
  int* big_job_time = random_job(BIGN,40);
  int* big_job_arrival_time = random_arrival(BIGN, 100);
  standardize_job(BIGN, big_job_time, big_job_arrival_time);
  scheduler* js = create(BIGN);

  // Test.
  puts(section);
  printf("Time to schedule %d jobs: static arrival time\n", BIGN);
  clock_time = 0;
  restart(js);
  gettimeofday(&t1, 0);
  schedule_static(js,
                  BIGN,
                  big_job_time,
                  &ticktock,
                  &noop);
  gettimeofday(&t2, 0);
  time = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  printf("Time: %f seconds\n", time);
  if (time < 1.5)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Too slow\n");
  }

  // Test.
  puts(section);
  printf("Time to schedule %d jobs: various arrival time\n", BIGN);
  clock_time = 0;
  restart(js);
  gettimeofday(&t1, 0);
  schedule_variable(js,
                    BIGN,
                    big_job_time,
                    big_job_arrival_time,
                    &ticktock,
                    &noop);
  gettimeofday(&t2, 0);
  time = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  printf("Time: %f seconds\n", time);
  if (time < 1.5)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Too slow\n");
  }

  // Test.
  puts(section);
  printf("Time to schedule %d jobs: with preemption\n", BIGN);
  clock_time = 0;
  restart(js);
  gettimeofday(&t1, 0);
  schedule_preemptive(js,
                      BIGN,
                      big_job_time,
                      big_job_arrival_time,
                      &ticktock,
                      &noop);
  gettimeofday(&t2, 0);
  time = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  printf("Time: %f seconds\n", time);
  if (time < 1.5)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Too slow\n");
  }
  puts(footer);
  destroy(&js);
  free(big_job_time);
  free(big_job_arrival_time);


  // Bonus.
  //
  // Precompute average wait time.
  //
  // Test Case #4:
  int T=3;
  int N = test[T].size;
  
  // New Test.
  puts(header);
  printf("Test #%d:\n", ++testcount);
  printf("Report the predicted (precomputed) average wait time\n");

  // Test.
  puts(section);
  printf("Static arrival time; all jobs start at t=0\n");
  awt = predict_awt_static(test[T].job_time, N);
  sprintf(numstr, "%.2f", awt);
  sscanf(numstr, "%lf", &awt);
  
  // Verify average wait time.
  printf("\tPredicted average wait time should be %f\n", test[T].awt_static);
  if (fabs(awt - test[T].awt_static) < DBL_EPSILON)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Average wait time = %f but should %f\n",
           awt, test[T].awt_static);
  }

  // Test.
  puts(section);
  printf("Variable arrival time\n");
  awt = predict_awt_variable(test[T].job_time, test[T].arrival_time, N);
  sprintf(numstr, "%.2f", awt);
  sscanf(numstr, "%lf", &awt);
  
  // Verify average wait time.
  printf("\tPredicted average wait time should be %f\n",
         test[T].awt_variable);
  if (fabs(awt - test[T].awt_variable) < DBL_EPSILON)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Average wait time = %f but should %f\n",
           awt, test[T].awt_variable);
  }
  puts(footer);


  // End of exercise.
  report();
  
  return 0;
}
/*** end of file ***/
