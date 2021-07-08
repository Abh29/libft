#include "libft.h"

typedef struct s_putnbr_unsigned_fd_size_bonus
{
	unsigned long	k;
	char			i;
	size_t			j;
	char			*save;
}				t_putnbr_bonus;

static void	ft_putthis(t_options options, size_t *size, \
			int fd, t_putnbr_bonus args)
{
	if (!options.l_shift)
		while (options.width-- > args.j)
			ft_putchar_fd_size(' ', fd, size);
	while (options.precision-- > (size_t)args.i)
		ft_putchar_fd_size('0', fd, size);
	while (args.i-- > 0)
	{
		write (fd, args.save, 1);
		(*size)++;
		args.save--;
	}
	if (options.l_shift)
		while (options.width-- > args.j)
			ft_putchar_fd_size(' ', fd, size);
}

void	ft_putnbr_unsigned_fd_size(int nb, int fd, size_t *size, \
		t_options options)
{
	t_putnbr_bonus	args;
	char			*buff;

	if (nb >= 0)
		ft_putnbr_fd_size(nb, fd, size, options);
	else
	{
		buff = (char *)ft_calloc(12, sizeof(char));
		if (buff == NULL)
			return ;
		args.save = buff;
		args.k = __UINT32_MAX__ + nb + 1;
		args.i = 0;
		while (args.k > 0)
		{
			*args.save++ = (char)(args.k % 10 + '0');
			args.i++;
			args.k /= 10;
		}
		args.save--;
		args.j = FT_MAX((size_t)args.i, options.precision);
		ft_putthis(options, size, fd, args);
		args.save = NULL;
		free(buff);
	}
}
