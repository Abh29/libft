#include "libft.h"

void ft_add_one_size(char *str, int idx)
{
    while (str[idx] == '9')
    {
        str[idx] = '0';
        idx--;
    }
    if (str[idx] == '.')
        idx--;
    str[idx]++;
}

void ft_putdbl_fd_size(double f, int fd, size_t precision, size_t *fsize)
{
    int correctpart;
    int intpart;
    double floatpart;
    char *out;
    int idx;
    size_t j;
    

    
    out = (char *)calloc(100, sizeof(char));
    if (out == NULL)
        return ;
    if (f < 0)
    {
        ft_putchar_fd_size('-', fd, fsize);
        f *= -1;
    }
    correctpart = (int)f;
    floatpart = f - ((double)correctpart);
    out[0] = '0';
    idx = 1;
    out[idx++] = '.';
    floatpart *= 10;
    j = 0;
    intpart = (int)(floatpart);
    while (floatpart != 0 && j < precision)
    {
        out[idx++] = intpart + '0';
        floatpart = floatpart - ((double)intpart);
        floatpart *= 10;
        intpart = (int)(floatpart);
        j++;
    }
    while (j < precision)
    {
        out[idx++] = '0';
        intpart = 0;
        j++;
    }
    if (intpart > 5)
        ft_add_one_size(out, idx - 1);
    if (out[0] == '1')
        correctpart++;
    ft_putnbr_fd_size(correctpart, fd, fsize, NULLOPTION);
    if (precision != 0)
        ft_putchar_fd_size('.', fd, fsize);
    idx = 1;
    while (out[idx++])
        ft_putchar_fd_size(out[idx], fd, fsize);
    
    free(out);
}
