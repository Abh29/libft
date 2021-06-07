#include "libft.h"

void    ft_putnbr_unsigned_fd_size(int nb, int fd, size_t *size)
{
    unsigned long k;
    char *buff;
    char i;
    char *save;

    if (nb >= 0)
        ft_putnbr_fd_size(nb, fd, size, NULLOPTION);
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
        while (i-- > 0)
        {
            write (fd, save, 1);
            (*size)++;
            save--;
        }
        save = NULL;
        free(buff);
    }
}
