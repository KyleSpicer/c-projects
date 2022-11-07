/**
 * @brief scheduler.h holds the function declarations for use within scheduler.c
 * @brief Practical Exam I (A): job scheduler
 *
 * @param use with scheduler.c
 */

//------------------------------------------------------------------------------
// Practical Exam I (A): job scheduler
//------------------------------------------------------------------------------
#ifndef __SCHEDULER_H
#define __SCHEDULER_H

typedef struct queue_t queue_t;

queue_t * queue_create(int size);

void queue_destroy(queue_t ** queue);

queue_t * queue_enqueue(queue_t * queue, int value);

int queue_dequeue(queue_t * queue);

struct scheduler
{
    // Data structure for storing and managing jobs.
    queue_t * queue;

    // Each job is identified by the count in which it was added.
    int job_id;

    // Total overall count of jobs, not the current number of jobs.
    int job_count; // do not modigy

    // Total count of processed jobs.
    int finish_count;

    // Sum totals.
    int sum_job_time;
    int sum_arrival_time;
    int sum_end_time;
    int sum_wait_time;
};

typedef struct scheduler scheduler;

// Interface.
scheduler * create(int); // create scheduler

void destroy(scheduler ** scheduler);

void restart_queue(queue_t * queue);

void restart(scheduler * scheduler);

queue_t * queue_enqueue(queue_t * queue, int value);

// Add a job from static entry
void add(scheduler *, int number);

// Empty status; waiting for job.
int idle(scheduler * scheduler);

// Return current job ID.
int current_job(scheduler * scheduler);

// Compute and return the average wait time.
double average_wait_time(scheduler * scheduler);

// insertion sort for array
void sort_array(int array[], int array_size);

// All jobs arrive at time t=0.
//
// Input:
// 1) total number of jobs
// 2) array of job times
// 3) clock function that returns clock ticks
// 4) status function that takes the current clock tick and job wait time; calls
//    the current job function
void schedule_static(scheduler * scheduler,
                     int         total_num_jobs,
                     int *       array_jobs,
                     int (*ticktock)(),
                     void (*report)(struct scheduler *,
                                    int current_tick,
                                    int job_wait_time));

// Jobs arrive at variable times.
//
// Input:
// 1) total number of jobs
// 2) array of job times
// 3) array of arrival times
// 4) clock function that returns clock ticks
// 5) status function that takes the current clock tick and job wait time; calls
//    the current job function
void schedule_variable(scheduler * scheduler,
                       int         total_num_jobs,
                       int *       array_job_times,
                       int *       array_arrival_times,
                       int (*ticktock)(),
                       void (*report)(struct scheduler *,
                                      int current_tick,
                                      int job_wait_time));

// Jobs arrive at variable times with preemption.
//
// Input:
// 1) total number of jobs
// 2) array of job times
// 3) array of arrival times
// 4) clock function that returns clock ticks
// 5) status function that takes the current clock tick and job wait time; calls
//    the current job function
void schedule_preemptive(scheduler *,
                         int   total_num_jobs,
                         int * array_job_times,
                         int * array_arrival_times,
                         int (*ticktock)(void *),
                         void (*)(scheduler *,
                                  int current_tick,
                                  int job_wait_time));

// Pre-compute average wait time.
//
// Input:
// 1) array of job times
// 2) number of jobs.
double predict_awt_static(int *, int);

// Pre-compute average wait time.
//
// Input:
// 1) array of job times
// 2) array of arrival times
// 3) number of jobs.
double predict_awt_variable(int *, int *, int);

#endif /* _SCHEDULER_H */

/*** end of file ***/
