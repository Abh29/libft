#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

#include <stdio.h>
#include <stdlib.h>
int	ft_atoi(const char *str)
{
	int		sign;
	unsigned long long	out;

	sign = 1;
	out = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		out = out * 10 + *str - 48;
		str++;	
		if (out > 9223372036854775806L)
		{
			if(sign == 1)
				return (-1);
			return (1);
		}
	}

	return ((int)(out * sign));
}

int main()
{
	char *s = "99999999999999999999999999";

	printf("%d\n",ft_atoi(s));
	printf("%d",atoi(s));
}
