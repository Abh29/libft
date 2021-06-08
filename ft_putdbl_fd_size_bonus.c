#include "libft.h"

double ft_pow10(int e)
{
    double out;

    out = 1;
    if (e < 0)
        while (e++ < 0)
            out /= 10;
    else while (e-- > 0)
        out *= 10;
    return (out);
}

void ft_putdbl_fd_size(long double dbl, int fd, size_t *size, t_options options)
{
    int firstpart;
    int secondpart;
    double floatpart;
    t_options ops;
    long double d;
    
    d = dbl;
    if (d < 0)
        d *= -1;
    firstpart = (int)d;
    floatpart = d - (double)firstpart;
    floatpart *= ft_pow10(options.precision);
    secondpart = (int) floatpart;
    floatpart -= secondpart;
    if (floatpart > 0.5)
        secondpart++;
    if (secondpart > ft_pow10(options.precision) - 1)
    {
        firstpart++;
        secondpart = 0;
    }
    if (dbl < 0)
        firstpart *= -1;
    ops = options;
    ops.precision = 0;
    if (!options.l_shift)
    {
        if (options.width > options.precision)
            ops.width -= options.precision;
        if (options.precision != 0 && options.width)
            ops.width--;
        if (options.filler)
            ops.precision = ops.width;
        if (dbl < 0 || options.sign)
            ops.precision--;
        if (firstpart == 0 && options.filler == 0)
            ops.precision = 1;
        options.width = 0;
    }
    else
    {
        ops.width = 0;
        if (firstpart == 0)
        {
            ops.precision = 1;
            options.width--;
        }
        if (options.precision != 0 && options.width)
            options.width--;
    }
    ft_putnbr_fd_size(firstpart, fd, size, ops);
    if (options.precision != 0)
    {
        ft_putchar_fd_size('.', fd, size);
        options.sign = 0;
        if (secondpart != 0)
            options.precision = 0;
        ft_putnbr_fd_size(secondpart, fd, size, options); 
    }   
}
