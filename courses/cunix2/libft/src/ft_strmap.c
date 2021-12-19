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

char *ft_strmap(char const *s, char (*f)(char))
{
    int len = my_strlen((char *)s);
    char *result = (char *)malloc( (len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        *(result + i) = f(*(s + i));
    }
    result[len] = '\0';
    return result;
}
