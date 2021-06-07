#include "libft.h"


void    ft_putnbr_unsigned_fd_size(int nb, int fd, size_t *size, t_options options)
{
    unsigned long k;
    char *buff;
    char i;
    char *save;
    size_t j;

    if (nb >= 0)
        ft_putnbr_fd_size(nb, fd, size, options);
    else
    {
        buff = (char *)ft_calloc(12, sizeof(char));
        if (buff == NULL)
            return ;
        save = buff;
        k = __UINT32_MAX__ + nb + 1;
        i = 0;
        while (k > 0)
        {
            *save++ = (char)(k % 10 + '0');
            i++;
            k /= 10;
        }
        save--;
        j = FT_MAX((size_t)i, options.precision);
        if(!options.l_shift)
            while (options.width-- > j)
                ft_putchar_fd_size(' ', fd, size);
        while (options.precision-- > (size_t)i)
            ft_putchar_fd_size('0', fd, size);
        while (i-- > 0)
        {
            write (fd, save, 1);
            (*size)++;
            save--;
        }
        if (options.l_shift)
            while (options.width-- > j)
                ft_putchar_fd_size(' ', fd, size);
        save = NULL;
        free(buff);
    }
}
