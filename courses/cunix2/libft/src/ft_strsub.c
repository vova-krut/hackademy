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

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    if (start > my_strlen((char *)s) || len <= 0)
    {
        char *substring = (char *)malloc(sizeof(char));
        *substring = '\0';
        return substring;
    }
    if (start + len > my_strlen((char *)s))
    {
        len = my_strlen((char *)s) - start;
    }
    size_t i;
    char *substring = (char *)malloc((len + 1) * sizeof(char));
    for (i = 0; i < len; i++)
    {
        substring[i] = *(s + start + i);
    }
    substring[i] = '\0';
    return substring;
}
