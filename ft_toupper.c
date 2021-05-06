#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 0x61 && c <= 0x7C)
		return (c - 'a' + 'A');
	return (c);
}
