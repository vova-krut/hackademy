#include <stdio.h>

int my_atoi(const char *nptr)
{
    int i = 0, result = 0, check = 0, num_counter = 0;
    if (nptr[0] == '-')
    {
        nptr++;
        check = 1;
    }
    while( (nptr[num_counter] >= '0') && (nptr[num_counter] <= '9') )
    {
        num_counter++;
    }
    while(i < num_counter)
    {
        result = result * 10 + nptr[i] - '0';
        i++;
    }
    if (check == 1)
    {
        result *= -1;
    }
    return result;
}
