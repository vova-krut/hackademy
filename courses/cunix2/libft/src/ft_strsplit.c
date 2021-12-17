#include "../libft.h"

char **ft_strsplit(char const *s, char c)
{
    int count = 1, i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            i++;
        }
        else
        {
            count++;
            while (s[i] != c && s[i] != '\0')
            {
                i++;
            }
        }
    }
    char **words;
    if ( !(words = (char **)malloc(count * sizeof(char*))) )
    {
        return NULL;
    }
    i = 0;
    int length = 0, j = 0;
    while (s[j] != '\0')
    {
        if (s[j] == c)
        {
            j++;
        }
        else
        {
            length = 0;
            int x = j;
            while (s[x] != c && s[x] != '\0')
            {
                length++;
                x++;
            }
            char *word = (char *)malloc( (length + 1) * sizeof(char) );
            int temp = 0;
            while (temp < length)
            {
                word[temp] = s[j++];
                temp++;
            }
            word[length] = '\0';
            words[i] = word;
            i++;
        }
    }
    words[count - 1] = NULL;
    return words;
}
