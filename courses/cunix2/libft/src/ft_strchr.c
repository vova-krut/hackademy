#include "../libft.h"

char *ft_strchr(const char *string, int symbol)
{
    do
    {
        if (*string == (char)symbol)
        {
            return (char *)string;
        }
    }
    while (*string++ != '\0');
    return NULL;
}
