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


char *ft_strstr(const char *strB, const char *strA)
{
    int length1 = my_strlen(strA), length2 = my_strlen(strB), i = 0;
    while (length1 + i <= length2)
    {
        if (my_strncmp((strB + i), strA, length1) == 0)
        {
            return (char *)(strB + i);
        }
        i++;
    }   
    return NULL;
}
