#include <unistd.h>

unsigned int my_strlen(const char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

int my_puts(const char *s)
{
    int len = my_strlen(s);
    write(1, s, len);
    write(1, "\n", 1);
    return 0;
}
