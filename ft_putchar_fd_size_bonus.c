#include "libft.h"

void	ft_putchar_fd_size(char c, int fd, size_t *size)
{
	write(fd, &c, 1);
	(*size)++;
}

void	ft_putchar_fd_size_options(char c, int fd, size_t *size, \
		t_options options)
{
	if (options.width > 0 && options.l_shift == 0)
		while (options.width-- > 1)
			ft_putchar_fd_size(' ', fd, size);
	ft_putchar_fd_size(c, fd, size);
	if (options.width > 0 && options.l_shift == 1)
		while (options.width-- > 1)
			ft_putchar_fd_size(' ', fd, size);
}
