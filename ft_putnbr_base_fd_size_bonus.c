#include "libft.h"


static void ft_print_nbr_base(unsigned int nb, const char *base, int base_size, char *buff, int fd, size_t *size, t_options options)
{
    int i;
    size_t j;
    
    i = 0;
    while (nb > 0)
    {
        buff[i++] = base[nb % base_size];
        nb /= base_size;
    }
    j = FT_MAX((size_t)i, options.precision);
    if (options.prefix)
        j += ft_strlen(options.prefix);
    if (!options.l_shift)
        while (options.width-- > j)
            ft_putchar_fd_size(' ', fd, size);
    if (options.prefix)
    {
        ft_putstr_fd_size(options.prefix, fd, size, OPTIONS(0, INT_MAX, 0, 0, 0, NULL));
        if (ft_strncmp("0", options.prefix, 2) == 0 && options.precision > 0 && j-- > 0)
            options.precision--;
    }   
    while (options.precision-- > (size_t)i)
        ft_putchar_fd_size(base[0], fd, size);
    while (i > 0)
        ft_putchar_fd_size(buff[--i], fd, size);
    if (options.l_shift)
        while (options.width-- > j)
            ft_putchar_fd_size(' ', fd, size);
}

static void ft_handle_null(const char *base, int fd, size_t *size, t_options options)
{
    char *s;
    size_t i;

    if (options.precision == 0)
        return ft_putstr_fd_size("", fd, size, OPTIONS(0, INT_MAX, options.width, base[0], options.l_shift, NULL));
    s = (char *)ft_calloc(options.precision + 1, sizeof(char));
    if (s == NULL)
        return;
    i = 0;
    while (i < options.precision)
        s[i++] = base[0];
    ft_putstr_fd_size(s, fd, size, OPTIONS(0, INT_MAX, options.width, base[0], options.l_shift, NULL));
    free(s);
    return ;
}


void    ft_putnbr_base_fd_size(int nb, const char *base, int fd, size_t *size, t_options options)
{
    int     base_size;
    char    *out;

    if (base == NULL)
        return ;
    base_size = ft_strlen(base);
    if (base_size < 2)
        return ;
    if (nb == 0)
        return ft_handle_null(base, fd, size, options);
    if (nb < 0)
        nb = (unsigned)(__UINT32_MAX__ + nb + 1);
    out = malloc (33);
    if (out == NULL)
        return ;
    ft_print_nbr_base((unsigned int)nb, base, base_size, out, fd, size, options);
    free(out);
    return ;
}
