#include "../libft.h"

void *ft_memccpy(void *destination, const void *source, int c, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        *((char *)destination + i) = *((char *)source + i);
        if ( *((char *)destination + i) == (char)c)
        {
            return (char *)destination + i + 1;
        }
    }
    return NULL;
}
