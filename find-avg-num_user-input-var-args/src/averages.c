/* program to accept variable amount of args and find the average*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h>

int find_average(int num_args, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, num_args);
    printf("argv = %s\n", &arg_ptr);
    int arg_sum = 0;

    for (int i = 0; i < num_args; i++)
    {
        int x = va_arg(arg_ptr, int);
        arg_sum += x;       
    }
    
    int average = (arg_sum / num_args - 1);
    
    va_end(arg_ptr);

    return average;
}

// void parse_string_to_ints(int argc, char *argv[])
// {
//     while(argc)
//     {
//         printf("argv = %s\t argc = %d\n", argv[argc], argc);
//     }
// }

int main(int argc, char *argv[])
{
    printf("argv = %s\n", *argv);

    // int numbers_from_input = parse_string_to_ints(argc, *argv);    
    int average = find_average((argc - 1), *argv);
    printf("Average = %d\n", average);
}