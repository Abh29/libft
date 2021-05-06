#include "libft.h"

int	ft_tolower(int c)
{
	unsigned int uc;

	uc = (unsigned int)c;
	if (uc > 0x40 && uc < 0x5B)
		return (uc - 'A' + 'a');
	return (uc);
}
