#include "libft.h"

static int  ft_numsize(int *n, int fd, size_t *fsize, t_options options)
{
    int size;
    int save;
    int neg;

    size = 0;
    neg = 0;
    if (*n < 0)
    {
        *n *= -1;
        neg = 1;
        if (options.width > 0)
            options.width--;
        if (options.precision > 0)
            options.precision--;
    }
    save = *n;
    while (save && size++ > -1)
        save /= 10;
    while (options.width-- > FT_MAX(options.precision, (size_t)size))
        ft_putchar_fd_size(' ', fd, fsize);
    if (neg)
        ft_putchar_fd_size('-', fd, fsize);
    else if (options.sign)
        ft_putchar_fd_size('+', fd, fsize);
    if (options.precision == (size_t)-1)
        options.precision = 0;
    while (options.precision-- > (size_t)size)
        ft_putchar_fd_size('0', fd, fsize);
    return (size);
}

void        ft_putnbr_fd_size(int n, int fd, size_t *size, t_options options)
{
    char        s[11];
    size_t      i;
    long      width;
    
    i = 0;
    width = 0;
    if (options.sign && options.width > 0)
        options.width--;
    if (options.filler == ' ' && n > 0)
    {
        ft_putchar_fd_size(' ', fd, size);
        if (options.width > 0)
            options.width--;
    }
    else if (options.filler == '0')
        options.precision = FT_MAX(options.width, options.precision);
    if (options.l_shift)
    {
       width = options.width;
       options.width = 0;
    }
    if (n == -2147483648)
    {
        while (options.width-- > FT_MAX(options.precision, (size_t)10))
            ft_putchar_fd_size(' ', fd, size);
        ft_putchar_fd_size('-', fd, size);
        while (width-- > 10)
            ft_putchar_fd_size('0', fd, size);
        ft_putstr_fd_size("2147483648", fd, size,  OPTIONS(0, INT_MAX, 0, 0, 0, NULL));
        return ;
    }
    if (n == 0)
    {
        while (options.width-- > FT_MAX(options.precision, (size_t)1))
            ft_putchar_fd_size(' ', fd, size);
        if (options.sign && width-- > 1)
            ft_putchar_fd_size('+', fd, size);
        else if (options.precision == 0 && width-- > 1)
            ft_putchar_fd_size(' ', fd, size);
        while (i < options.precision-- && width-- > 1)
            ft_putchar_fd_size('0', fd, size);
    }
    else
    {
        i = ft_numsize(&n, fd, size, options);
        s[i--] = 0;
        while (n && (s[i--] = n % 10 + '0') > -1)
            n /= 10;
        i = ft_strlen(s);
        *size += i;
        width -= FT_MAX(i, options.precision);
        write (fd, s, i);
    }
    if (options.l_shift)
    {
        while (width-- > 0)
        {
           ft_putchar_fd_size(' ', fd, size);
        }
        
    }
}
