#include "../libft.h"
 
unsigned int my_strlen(const char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
 
int my_strncmp(const char *string1, const char *string2, size_t num)
{
    for (size_t i = 0; i < num; i++)
    {
        if (string1[i] == string2[i])
        {
            continue;
        }
        else
        {
            return string1[i] - string2[i];
        }
    }
    return 0;
}
 
 
char *ft_strnstr(const char *strB, const char *strA, size_t len)
{
    int length1 = my_strlen(strA), i = 0;
    while ((size_t)length1 + i <= len)
    {
        if (my_strncmp(strB, strA, length1) == 0)
        {
            return (char *)strB;
        }
        else if (*(strB++) == '\0')
        {
            break;
        }
        i++;
    }
    return NULL;
}
