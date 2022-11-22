#define _POSIX_C_SOURCE 200809L

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
#define HALT_DEDUCTION 1
#define TEST_TOTAL 7
#define POINT_TOTAL 22
static const int point[TEST_TOTAL] = {2,2,2,2,2,2,10};
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
void verify_hole_number(int s, int sz)
{
  if (s == sz)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Number of holes = %d but should %d\n", s, sz);
  }
}
//-------------------------------------------------------------------------------
void verify_hole_size(int s, int sz)
{
  if (s == sz)
  {
    ++pass;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Size of largest hole = %d but should %d\n", s, sz);
  }
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
  int total = 0;
  int size = 0;
  FILE* f;
  char* l = 0;
  size_t s = 0;
  int rv = 0;

  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test1", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 5);
  verify_hole_number(total, 5);
  
  printf("Verify largest hole size is:\t%d\n", 4);
  verify_hole_size(size, 4);
  pclose(f);
  free(l);
  puts(footer);

  
  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test2", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 4);
  verify_hole_number(total, 4);
  
  printf("Verify largest hole size is:\t%d\n", 12);
  verify_hole_size(size, 12);
  pclose(f);
  free(l);
  puts(footer);


  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test3", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 4);
  verify_hole_number(total, 4);
  
  printf("Verify largest hole size is:\t%d\n", 12);
  verify_hole_size(size, 12);
  pclose(f);
  free(l);
  puts(footer);


  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test4", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 11);
  verify_hole_number(total, 11);
  
  printf("Verify largest hole size is:\t%d\n", 21);
  verify_hole_size(size, 21);
  pclose(f);
  free(l);
  puts(footer);


  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test_all_ones_50x10", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 0);
  verify_hole_number(total, 0);
  
  printf("Verify largest hole size is:\t%d\n", 0);
  verify_hole_size(size, 0);
  pclose(f);
  free(l);
  puts(footer);


  // New test.
  puts(header);
  printf("Test #%d:\n", ++testcount);

  // Test.
  puts(section);
  f = popen("./holesum test/test_all_zeros_50x10", "r");
  l = 0;
  s = 0;
  total = 0;
  size = 0;

  // Read first line and get total count.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  if (getline(&l, &s, f) == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 1);
  verify_hole_number(total, 1);
  
  printf("Verify largest hole size is:\t%d\n", 500);
  verify_hole_size(size, 500);
  pclose(f);
  free(l);
  puts(footer);


  // New test.
  //
  // NOTE: Should test against reference implementation.
  puts(header);
  printf("Test #%d:\n", ++testcount);
  printf("Performance test\n");

  // Test.
  puts(section);
  printf("Elapsed time to count and sum holes\n");
  l = 0;
  s = 0;
  total = 0;
  size = 0;
  gettimeofday(&t1, 0);
  f = popen("./holesum test/test_100000x1000", "r");
  rv = getline(&l, &s, f);
  gettimeofday(&t2, 0);
  time = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  printf("Time: %f seconds\n", time);
  if (time < 10)
  {
    pass+=8;
    printf("\tPASS!\n");
  }
  else
  {
    ++fail;
    printf("\tFAIL! Too slow\n");
  }

  // Read first line and get total count.
  if (rv == -1)
  {
    ++fail;
    printf("\tFAIL! Could not get output\n");
  }
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &total);

  // Read second line and get largest size.
  rv = getline(&l, &s, f);
  strtok(l, "\t");
  sscanf(strtok(0, "\n"), "%d", &size);

  // Verify output.
  printf("Verify number of holes is:\t%d\n", 6594662);
  verify_hole_number(total, 6594662);
  
  printf("Verify largest hole size is:\t%d\n", 1031);
  verify_hole_size(size, 1031);
  pclose(f);
  free(l);
  puts(footer);
  
  // End of exercise.
  report();
  
  return 0;
}