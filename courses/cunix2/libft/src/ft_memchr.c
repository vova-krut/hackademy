#include "../libft.h"

void *ft_memchr(const void *arr, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if ( *((char *)arr + i) == (char)c )
        {
            return (char *)arr + i;
        }
    }
    return NULL;
}
