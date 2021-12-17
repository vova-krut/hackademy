#include "../libft.h"

div_t ft_div(int numer, int denom)
{
    div_t output;
    output.quot = numer / denom;
    output.rem = numer % denom;
    return output;
}
