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

char *ft_strtrim(char const *s)
{
    int len = my_strlen((char *)s), counter = 0;
    while (*s == ' ' || *s == '\n' || *s == '\t')
    {
        counter++;
        s++;
    }
    len -= counter;
    if (len != 0)
    {
        while (s[len - 1]  == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
        {
            len--;
        }   
    }
    char *answer = (char *)malloc((len + 1) * sizeof(char));
    answer[len] = '\0';
    for (int j = 0; j < len; j++)
    {
        *((char *)answer + j) = *((char *)s + j);
    }
    return answer;
}
