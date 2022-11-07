/**
 * @brief scheduler.c is the source file that contains the logic for functions
 * declared in scheduler.h.
 *
 * @param  #include "scheduler.h"
 */

#include "scheduler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief structure for queue
 */
struct queue_t
{
    int   head;
    int   tail;
    int   size;
    int * data;
};

/**
 * @brief creates queue struct for size passed as an argument
 *
 * @param int size - total amount of jobs to create space in the queue for
 */
queue_t *
queue_create(int size)
{
    if (size < 1)
    {
        return NULL;
    }
    queue_t * queue = calloc(1, sizeof(*queue));
    if (queue)
    {
        queue->size = size;
        queue->data = calloc(size, sizeof(int));
        if (!queue->data)
        {
            free(queue);
            queue = NULL;
        }
    }
    return queue;
}

/**
 * @brief frees all allocated memory within and including the queue
 *
 * @param queue_t **queue - double pointer to the actual queue
 */
void
queue_destroy(queue_t ** queue)
{
    if (!queue || !*queue)
    {
        return;
    }

    free((*queue)->data);
    free(*queue);
    *queue = NULL;
}

// Interface.
/**
 * @brief creates scheduler struct to house jobs
 *
 * @param int job_capacity - total number of jobs for scheduler
 */
scheduler *
create(int job_capacity)
{
    struct scheduler * scheduler = NULL;

    if (!job_capacity)
    {
        return NULL;
    }

    scheduler = calloc(1, sizeof(*scheduler));
    if (scheduler)
    {
        scheduler->queue
            = queue_create(job_capacity); // creates queue mem for # of jobs
        scheduler->job_count = job_capacity;
    }

    return scheduler;
}

/**
 * @brief frees all allocated memory within and including the scheduler
 *
 * @param scheduler ** scheduler - double pointer to scheduler struct
 */
void
destroy(scheduler ** scheduler)
{
    if (!scheduler)
    {
        return;
    }
    // TODO: destroy queue
    queue_destroy(&(*scheduler)->queue);
    free(*scheduler);
    *scheduler = NULL;
}

/**
 * @brief resets all values in queue to zero
 * 
 * @param queue 
 */
void
restart_queue(queue_t * queue)
{
    if (!queue)
    {
        return;
    }
    queue->head = 0;
    queue->tail = 0;
}

/**
 * @brief restart the scheduler
 *
 * @param scheduler* scheduler - pointer to scheduler struct
 */
void
restart(scheduler * scheduler)
{
    if (!scheduler)
    {
        return;
    }

    restart_queue(scheduler->queue);
    scheduler->job_id           = 0;
    scheduler->finish_count     = 0;
    scheduler->sum_arrival_time = 0;
    scheduler->sum_end_time     = 0;
    scheduler->sum_job_time     = 0;
    scheduler->sum_wait_time    = 0;
}

/**
 * @brief adds value to end of queue
 *
 * @param queue_t * queue - pointer to queue struct
 * @param int value - value being added to the queue
 */
queue_t *
queue_enqueue(queue_t * queue, int value)
{
    // avoids negative numbers, or max capacity reached
    if (!queue || value < 0 || queue->tail == queue->size)
    {
        if (!queue)
        {
            printf("bad queue\n");
        }
        else if (value < 0)
        {
            printf("bad value\n");
        }
        else
        {
            printf("%d == %d\n", queue->tail, queue->size);
        }
        return NULL;
    }

    queue->data[queue->tail++] = value;

    return queue;
}

/**
 * @brief removes first element in queue
 *
 * @param queue_t * queue - pointer to queue struct
 */
int
queue_dequeue(queue_t * queue)
{
    if (!queue || queue->head == queue->tail)
    {
        return -1;
    }

    return queue->data[queue->head++];
}

/**
 * @brief adds a job to the queue
 *
 * @param scheduler * scheduler - pointer to scheduler struct
 * @param int number - value being added to queue
 */
void
add(scheduler * scheduler, int number)
{
    if (!queue_enqueue(scheduler->queue, number))
    {
        fprintf(stderr, "Failed to queue: %d\n", number);
    }
}

/**
 * @brief empty status; waiting for job
 *
 * @param scheduler * scheduler - pointer to scheduler struct
 */
int
idle(scheduler * scheduler)
{
    if (!scheduler)
    {
        return -1;
    }

    if (scheduler->job_count == 0)
    {
        return 0;
    }

    return 1;
}

/**
 * @brief Return current job ID.
 *
 * @param scheduler * scheduler - pointer to scheduler struct
 */
int
current_job(scheduler * scheduler)
{
    if (!scheduler)
    {
        return 1;
    }
    return scheduler->finish_count;
}

/**
 * @brief Compute and return the average wait time.
 *
 * @param scheduler * scheduler - pointer to scheduler struct
 */
double
average_wait_time(scheduler * scheduler)
{
    double avg_wait_time = 0;
    if (!scheduler)
    {
        return 1;
    }

    avg_wait_time = scheduler->sum_wait_time / (double)scheduler->finish_count;
    return avg_wait_time;
}

/**
 * @brief compares data1 to data2
 *
 * @param const void *data1 - first value to compare
 * @param const void *data2 - second value to compare against first
 */
int
array_int_sort(const void * data1, const void * data2)
{
    if (!data1 || !data2)
    {
        printf("insufficient data entered.\n");
        return 1;
    }
    return *(int *)data1 - *(int *)data2;
}

/**
 * @brief All jobs arrive at time t=0.
 *
 * @param scheduler * scheduler - pointer to scheduler structure
 * @param int total_num_jobs - total number of jobs
 * @param int array_jobs - array of jobs
 * @param int(*ticktock)() - clock function that returns clock ticks
 * @param void(*report)(struct scheduler*, int current_tick, int job_wait_time
 * - status function that takes the current clock tick and job wait time; calls
 * the current job function
 */
void
schedule_static(scheduler * scheduler,
                int         total_num_jobs,
                int *       array_jobs,
                int (*ticktock)(),
                void (*report_status)(struct scheduler *,
                                      int current_tick,
                                      int job_wait_time))
{
    // ABCs
    if (!scheduler || !total_num_jobs || !array_jobs || !ticktock
        || !report_status)
    {
        printf("Insufficient arguments passed through static function\n");
        return;
    }

    // receive jobs array
    scheduler->job_count = total_num_jobs;

    // sort jobs array
    int * copy = calloc(total_num_jobs, sizeof(int));
    for (int i = 0; i < total_num_jobs; ++i)
    {
        copy[i] = array_jobs[i];
    }
    qsort(copy, total_num_jobs, sizeof(int), array_int_sort);

    // add to queue
    for (int i = 0; i < total_num_jobs; i++)
    {
        add(scheduler, copy[i]);
    }

    int current_job     = queue_dequeue(scheduler->queue);
    scheduler->job_id   = current_job;
    int tick            = 0;
    int total_wait_time = 0; // will be used to calculate average wait

    while (scheduler->finish_count < scheduler->job_count)
    {
        tick = ticktock();
        current_job--;

        if (0 == current_job)
        {
            report_status(scheduler, tick, scheduler->sum_job_time);

            total_wait_time += scheduler->sum_job_time;
            scheduler->sum_job_time += scheduler->job_id;
            scheduler->sum_end_time += tick;
            scheduler->finish_count++;
            current_job       = queue_dequeue(scheduler->queue);
            scheduler->job_id = current_job;
        }
    }
    scheduler->sum_wait_time = total_wait_time;
    average_wait_time(scheduler);

    free(copy);
    printf("\n\n");
}

/**
 * @brief Jobs arrive at variable times with preemption.
 *
 * @param scheduler * scheduler - pointer to scheduler structure
 * @param int total_num_jobs - total number of jobs
 * @param int array_jobs - array of jobs
 * @param int array_arrival_times - array of arrival times
 * @param int (*ticktock)(void *) - clock function that returns clock ticks
 * @param void(*report)(struct scheduler*, int current_tick, int job_wait_time
 * - status function that takes the current clock tick and job wait time; calls
 * the current job function
 */
void
schedule_preemptive(scheduler * scheduler,
                    int         total_num_jobs,
                    int *       array_job_times,
                    int *       array_arrival_times,
                    int (*ticktock)(void *),
                    void (*report)(struct scheduler *, int, int))
{
    ;
}

/**
 * @brief Jobs arrive at variable times.
 *
 * @param scheduler * scheduler - pointer to scheduler structure
 * @param int total_num_jobs - total number of jobs
 * @param int array_jobs - array of jobs
 * @param int array_arrival_times - array of arrival times
 * @param int (*ticktock)(void *) - clock function that returns clock ticks
 * @param void(*report)(struct scheduler*, int current_tick, int job_wait_time
 * - status function that takes the current clock tick and job wait time; calls
 * the current job function
 */
void
schedule_variable(scheduler * scheduler,
                  int         total_num_jobs,
                  int *       array_job_times,
                  int *       array_arrival_times,
                  int (*ticktock)(),
                  void (*report)(struct scheduler *,
                                 int current_tick,
                                 int job_wait_time))
{
    // ABCs
    if (!scheduler || !total_num_jobs || !array_job_times
        || !array_arrival_times || !ticktock || !report)
    {
        printf(
               "Insufficient arguments passed through variable function.\n");
        return;
    }

    // receive jobs array
    scheduler->job_count = total_num_jobs;

    int * copy = calloc(total_num_jobs, sizeof(int));
    for (int i = 0; i < total_num_jobs; ++i)
    {
        copy[i] = array_job_times[i];
    }

    // add to queue
    for (int i = 0; i < total_num_jobs; i++)
    {
        add(scheduler, copy[i]);
    }

    int current_job = queue_dequeue(scheduler->queue);

    scheduler->job_id = current_job;

    int ticks         = 0; // keep track of ticks
    int job_wait_time = 0; // tick count - arrival time - job size
    int index         = 0;

    while (scheduler->finish_count < scheduler->job_count)
    {
        ticks = ticktock();
        current_job--;

        if (0 == current_job)
        {
            job_wait_time
                = ticks - array_arrival_times[index] - array_job_times[index];
            scheduler->sum_wait_time += job_wait_time;
            report(scheduler, ticks, job_wait_time);
            scheduler->finish_count++;
            current_job       = queue_dequeue(scheduler->queue);
            scheduler->job_id = current_job;
            index++;
        }
        average_wait_time(scheduler);
    }
    free(copy);
    printf("\n\n");
}

/**
 * @brief Pre-compute average wait time.
 *
 * @param array_job_times - array of job times
 * @param total_num_jobs - number of jobs
 * @return double
 */
double
predict_awt_static(int * array_job_times, int total_num_jobs)
{
    if (!array_job_times || !total_num_jobs)
    {
        printf(
               "Insufficient arguments passed through predict_awt_static "
               "function\n");
        return 0.0;
    }
    int sum_times = 0;

    for (int i = 0; i < total_num_jobs; i++)
    {
        sum_times += array_job_times[i];
    }

    return sum_times / (double)total_num_jobs;
}

/**
 * @brief Pre-compute average wait time.
 *
 * @param array_job_times - array of job times
 * @param array_arrival_times - array of arrival times
 * @param total_num_jobs - number of jobs
 * @return double
 */
double
predict_awt_variable(int * array_job_times,
                     int * array_arrival_times,
                     int   total_num_jobs)
{
    if (!array_job_times || !array_arrival_times || !total_num_jobs)
    {
        printf("Incorrect arguments passed in predict_awt_variable function.\n");
        return 0.0;
    }
    return 1.0;
}
/*** end of file ***/