#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	save;

	save = dstsize;
	while (dstsize-- && *src)
		*dst++ = *src++;
	if (dstsize--)
		dst++;
	*dst = 0;
	return (save - dstsize + 1);
}
