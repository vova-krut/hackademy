#include "../ft_printf.h"

char* my_itoa(int nmb)
{
    long long num = (long long)nmb;
    char *str = NULL;
    str = (char*)malloc(32 * sizeof(char));
    int i = 0, neg = 0;
    if (num < 0)
    {
        neg = 1;
        num *= -1;
    }
    do
    {
        str[i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    while(num > 0);
    if (neg)
    {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    for(int j = 0, x = i-1; j < x; j++, x--)
    {
        char temp = str[j];
        str[j] = str[x];
        str[x] = temp;
    }
    return str;
}

int my_atoi(const char *nptr)
{
    int i = 0, result = 0, check = 0, num_counter = 0;
    if (nptr[0] == '-')
    {
        nptr++;
        check = 1;
    }
    while( (nptr[num_counter] >= '0') && (nptr[num_counter] <= '9') )
    {
        num_counter++;
    }
    while(i < num_counter)
    {
        result = result * 10 + nptr[i] - '0';
        i++;
    }
    if (check == 1)
    {
        result *= -1;
    }
    return result;
}

unsigned int my_strlen(const char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

void ft_printf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    int len = my_strlen(format);
    int zero = 0, minus = 0, plus = 0, space = 0;
    for (int i = 0; i < len; i++)
    {
        while (format[i] != '%' && i < len)
        {
            write(1, &format[i], 1);
            i++;
        }
        if (format[i] == '%')
        {
            i++;
            while (format[i] == '0' || format[i] == '-' || format[i] == '+' || format[i] == ' ')
            {
                switch (format[i])
                {
                    case '0':
                        zero = 1;
                        break;
                    case '-':
                        minus = 1;
                        zero = 0;
                        break;
                    case '+':
                        plus = 1;
                        break;
                    case ' ':
                        plus == 1 ? (space = 0) : (space = 1);
                        break;
                }
                i++;
            }
            int field_width = 0;
            while (format[i] >= '0' && format[i] <= '9')
            {
                char *digit = (char *)malloc(2 * sizeof(char));
                digit[0] = format[i];
                digit[1] = '\0';
                field_width = field_width * 10 + my_atoi(digit);
                free(digit);
                i++;
            }
            if (format[i] == '%')
            {
                write(1, "%", 1);
            }
            else
            {
                char *temp = NULL;
                if (format[i] == 's')
                {
                    temp = va_arg(arg, char *);
                }
                if (format[i] == 'c')
                {
                    temp = (char *)malloc(2 * sizeof(char));
                    temp[0] = va_arg(arg, int);
                    temp[1] = '\0';
                }
                if (format[i] == 'i' || format[i] == 'd')
                {
                    int nmb = va_arg(arg, int);
                    temp = my_itoa(nmb);
                    if (plus)
                    {
                        if (nmb >= 0)
                        {
                            write(1, "+", 1);
                        }
                        field_width--;
                    }
                    if (space && nmb >= 0)
                    {
                        write(1, " ", 1);
                        field_width--;
                    }
                }
                if (temp == NULL)
                {
                    temp = "(null)";
                }
                if (field_width != 0)
                {
                    int temp_len = (format[i] == 'c' && temp[0] == 0 ? 1 : my_strlen(temp));
                    int fill = field_width - temp_len;
                    if (fill > 0)
                    {
                        char *to_fill = (char *)malloc(2 * sizeof(char));
                        to_fill[0] = zero ? '0' : ' ';
                        to_fill[1] = '\0';
                        if (minus)
                        {
                            write(1, temp, my_strlen(temp));
                            while (fill-- > 0)
                            {
                                write(1, to_fill, 1);
                            }
                        }
                        else
                        {
                            if (my_atoi(temp) < 0 && zero)
                            {
                                write(1, "-", 1);
                                temp = my_itoa(my_atoi(temp) * -1);
                                temp_len--;
                            }
                            while (fill-- > 0)
                            {
                                write(1, to_fill, 1);
                            }
                            write(1, temp, my_strlen(temp));
                        }
                        free(to_fill);
                    }
                    else
                    {
                        write(1, temp, my_strlen(temp));
                    }
                }
                else
                {
                    write(1, temp, my_strlen(temp));
                }
                if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i')
                {
                    free(temp);
                }
            }
        }
    }
    va_end(arg);
}
