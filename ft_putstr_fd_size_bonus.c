#include "libft.h"

void    ft_putstr_fd_size(char *s, int fd, size_t *size, t_options options)
{
    size_t i;
    long width;

    width = options.width;
    if (options.l_shift)
        options.width = 0;
    if (s == NULL)
        return ;
    i = FT_MIN(ft_strlen(s), options.precision);
    width -= i;
    while (i < options.width--)
        ft_putchar_fd_size(' ', fd, size);
    write (fd, s, i);
    (*size) += i;
    if (options.l_shift)
        while (width-- > 0)
            ft_putchar_fd_size(' ', fd, size);
}
