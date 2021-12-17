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

char *ft_strjoin(char const *s1, char const *s2)
{
    int i = 0, j = 0;
    char *answer = (char *)malloc( (my_strlen((char *)s1) + my_strlen((char *)s2) + 1) * sizeof(char));
    while (s1[i] != '\0')
    {
        answer[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        answer[i] = s2[j];
        i++;
        j++;
    }
    answer[i] = '\0';
    return answer;
}
