#include "libft.h"


void ft_putdbl_exp_fd_size(double dbl, int fd, size_t *size, t_options options)
{
    double ld;
    int exp;
    
    exp = 0;
    ld = dbl;

    if (ld < 0)
        ld *= -1;

    if (ld < 1)
        while (ld < 1 && exp-- < 10)
            ld *= 10;
    else if (ld > 10)
        while (ld > 10 && exp++ > -1)
            ld /= 10;
    if (dbl < 0)
        ld *= -1;
    ft_putdbl_fd_size((double)ld, fd, size, options);
    ft_putchar_fd_size('e', fd, size);
    ft_putnbr_fd_size(exp, fd, size, OPTIONS(1, 2, 1, 0, 0, NULL));
}
