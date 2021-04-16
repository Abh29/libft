#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i++ < n && *(unsigned char *)s)
		*(unsigned char *)s++ = 0;
}
