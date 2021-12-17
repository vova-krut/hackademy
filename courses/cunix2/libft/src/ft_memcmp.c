#include "../libft.h"

int my_abs(int x)
{
    return x > 0 ? x : x * -1;
}

int ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if ( *((char *)buf1 + i) != *((char *)buf2 + i) )
        {
            return my_abs( (int)*((char *)buf1 + i) ) - my_abs( (int)*((char *)buf2 + i) );
        }
    }
    return 0;
}
