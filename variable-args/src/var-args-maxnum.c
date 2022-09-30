#include <stdio.h>
#include <stdarg.h>

int max(int num_args, ...); // accepts variable number of ints

int max(int num_args, ...)
{
    va_list args; // va_list is the type, args is the variable
    
    va_start(args, num_args);
    int max = 0;

    for (int i = 0; i < num_args; i++)
    {
        int x = va_arg(args, int);
        if(i == 0)
        {
            max = x;
        }
        else if(x > max)
        {
            max = x;
        }
    }

    va_end(args);

    return max;
}

int main(void)
{
    int max_num = max(4, 12, 1400, 501, 13); // 4 is num args, remaining are args
    printf("max_num: %d\n", max_num);

    return 0; 
}