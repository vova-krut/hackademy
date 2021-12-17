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

char *ft_strdup(const char *str)
{
    char *new = (char *)malloc( (my_strlen((char *)str) + 1 ) * sizeof(char));
    int i = 0;
    while(str[i] != '\0')
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
