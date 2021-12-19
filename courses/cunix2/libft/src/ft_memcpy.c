#include "../libft.h"

void *ft_memcpy(void *destination, const void *source, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        *((char *)destination + i) = *((char *)source + i);
    }
    return destination;
}
