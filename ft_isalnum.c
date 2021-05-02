#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha((char)c) || ft_isdigit((char)c));
}
