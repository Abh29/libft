#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*save;

	save = b;
	while (len--)
		*(unsigned char *)b++ = (unsigned char) c;
	return (save);
}
