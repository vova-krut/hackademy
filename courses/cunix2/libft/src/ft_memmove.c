#include "../libft.h"

void *ft_memmove(void *destination, const void *source, size_t count)
{
    char *copied = (char *)malloc(count * sizeof(char));
    for (size_t i = 0; i < count; i++)
    {
        *(char *)(copied + i) = *(char *)(source + i);//stupid 4th test requires info to be copied first
    }
    for (size_t i = 0; i < count; i++)
    {
        *(char *)(destination + i) = *(char *)(copied + i);
    }
    free(copied);
    return destination;
}
