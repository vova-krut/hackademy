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

char *ft_strrchr(const char *string, int symbol)
{
    if (symbol == 0)
    {
        return (char *)string + my_strlen((char *)string);
    }
    char *adress = NULL;
    while (*string != '\0')
    {
        if (*string == (char)symbol)
        {
            adress = (char *)string;
        }
        string++;
    }
    return adress;
}
