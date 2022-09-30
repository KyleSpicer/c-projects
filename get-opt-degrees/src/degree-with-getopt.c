#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage()
{
    printf("Usage: ./degrees temp -c <temp> | temp -f <temp>\n");
    exit(2);
}

void print_farenheit(float temp)
{
    float f = ((temp * 9) / 5) +32;
    printf("%.2f centigrade is %.2f farenheit\n", temp, f);
}

void print_centigrade(float temp)
{
    float c = ((temp - 32) * 5) / 9;
    printf("%.2f farenheit is %.2f centigrade\n", temp, c);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage();
    }

    int option;
    int cflag = 0; // sets flag to 0 for no value
    int fflag = 0; // sets flag to 0 for no value
    
    // loops for -c or -f, everything else is invalid
    // keep looping until getopt reports -1 (means no more options)
    while((option = getopt(argc, argv, "c:f:")) != -1)
    {
        switch(option)
        {
            case 'c' : 
                if(cflag) // if cflag has a value, exit program
                {
                    print_usage();
                }
                else // else increment both variables, allowing only one option
                {
                    cflag++;
                    fflag++;
                }
                print_farenheit(atof(optarg));
                break;

            case 'f' : 
                if (fflag) // if fflag has a value, exit program
                {
                    print_usage();
                }
                else // else increment both variables, allowing only one option
                {
                    fflag++;
                    cflag++;
                }
                print_centigrade(atof(optarg));
                break;

            default :
                exit(1);
        }
    }
}

/* end of file */