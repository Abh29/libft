#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha((char)c) != 0 || ft_isdigit((char)c)) != 0;
}
