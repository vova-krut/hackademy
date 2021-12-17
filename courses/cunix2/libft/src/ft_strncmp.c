#include "../libft.h"

int ft_strncmp(const char *string1, const char *string2, size_t num)
{
    for (size_t i = 0; i < num; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] - string2[i];
        }
    }
    return 0;
}
