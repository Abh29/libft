#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c > 9 && c < 14));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	out;

	sign = 1;
	out = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str++ == '-')
		sign = -1;
	while (*str && ft_isdigit(*str))
	{
		out = out * 10 + *str - 48;
		str++;
	}
	return (out * sign);
}
