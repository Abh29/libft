#include "libft.h"

void    ft_putstr_fd_size(char *s, int fd, size_t *size)
{
    int i;

    if (s == NULL)
        return ;
    i = ft_strlen(s);
    write (fd, s, i);
    (*size) += i;
}
