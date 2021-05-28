#include "libft.h"

static void ft_print_nbr_base(unsigned int nb, const char *base, int base_size, char *buff, int fd, size_t *size)
{
    int i;
    
    i = 0;
    while (nb > 0)
    {
        buff[i++] = base[nb % base_size];
        nb /= base_size;
    }
    while (i > 0)
    {
        write (fd, &buff[--i], 1);
        (*size)++;
    } 
}

void    ft_putnbr_base_fd_size(int nb, const char *base, int fd, size_t *size)
{
    int     base_size;
    char    *out;
    
    if (base == NULL)
        return ;
    base_size = ft_strlen(base);
    if (base_size < 2)
        return ;
    if (nb == 0)
    {
        write (fd, "0", 1);
        (*size)++;
        return ;
    }
    if (nb < 0)
        nb = (unsigned)(__UINT32_MAX__ + nb + 1);
    out = malloc (33);
    if (out == NULL)
        return ;
    ft_print_nbr_base((unsigned int)nb, base, base_size, out, fd, size);
    free(out);
    return ;
}