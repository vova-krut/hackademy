#include <stdlib.h>
#include <stdio.h>

char* my_itoa(int nmb)
{
    char *str = NULL;
    str = (char*)malloc(32 * sizeof(char));
    int i = 0, neg = 0;
    if (nmb < 0)
    {
        neg = 1;
        nmb *= -1;
    }
    do
    {
        str[i] = nmb % 10 + '0';
        nmb /= 10;
        i++;
    }
    while(nmb > 0);
    if (neg)
    {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    for(int j = 0, x = i-1; j < x; j++, x--)
    {
        char temp = str[j];
        str[j] = str[x];
        str[x] = temp;
    }
    return str;
}
