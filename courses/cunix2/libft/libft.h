#include <stdlib.h>
#include <stddef.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *str);
int ft_strncmp(const char *string1, const char *string2, size_t num);
char *ft_strchr(const char *string, int symbol);
char *ft_strrchr(const char *string, int symbol);
int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isascii(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);
int ft_abs(int x);
div_t ft_div(int numer, int denom);
char *ft_strstr(const char *strB, const char *strA);
char *ft_strnstr(const char *strB, const char *strA, size_t len);
void *ft_memset(void *destination, int c, size_t n);
void *ft_memcpy(void *destination, const void *source, size_t count);
void *ft_memccpy(void *destination, const void *source, int c, size_t count);
void *ft_memmove(void *destination, const void *source, size_t count);
void *ft_memchr(const void *arr, int c, size_t n);
int ft_memcmp(const void *buf1, const void *buf2, size_t count);
void ft_striter(char *s, void (*f)(char *));
char *ft_strmap(char const *s, char (*f)(char));
char *ft_strsub(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);
