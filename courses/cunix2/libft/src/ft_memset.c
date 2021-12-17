#include "../libft.h"

void *ft_memset(void *destination, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *((char *)destination + i) = (char)c;
    }
    return destination;
}
