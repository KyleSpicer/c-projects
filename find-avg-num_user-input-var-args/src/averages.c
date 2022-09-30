/* program to accept variable amount of args and find the average*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int find_average(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int arg_sum = 0;

    for (int i = 0; i < num_args; i++)
    {
        int x = va_arg(args, int);
        arg_sum += x;       
    }
    
    int average = (arg_sum / num_args);
    
    va_end(args);

    return average;
}


int main()
{
    int average = find_average(3, 10, 15, 5);
    printf("average = %d\n", average);
    
    // if (argc < 2)
    // {
    //     printf("Usage: ./averages 2 4 6\n");
    //     exit(1);
    // }
    // else
    // {
        // printf("argc = %d \t argv = %s\n\n\n", argc, argv);
        // int average = find_average(argc, argv);
        // printf("average = %d\n", average);
    // }
}