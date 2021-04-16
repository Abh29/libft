#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- && *(unsigned char *)src)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		if (*(unsigned char *)(src - 1) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
