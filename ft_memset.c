#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	void			*save;

	i = 0;
	save = b;
	while (i++ < len && *(unsigned char *)b)
		*(unsigned char *)b++ = (unsigned char) c;
	return (save);
}
