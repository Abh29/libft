#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*sdst;
	const void	*ssrc;

	sdst = dst;
	ssrc = src;
	while (n-- && *(unsigned char *)ssrc)
		*(unsigned char *)sdst++ = *(unsigned char *)ssrc++;
	return (dst);
}
