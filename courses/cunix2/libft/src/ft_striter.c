#include "../libft.h"

unsigned int my_strlen(char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

void ft_striter(char *s, void (*f)(char *))
{
    for (int i = 0, len = my_strlen(s); i < len; i++)
    {
        f((char *)s + i);
    }
}
