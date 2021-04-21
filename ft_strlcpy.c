#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	save;

	save = dstsize;
	while (dstsize-- && *src)
		*dst++ = *src;
	*dst = 0;
	return (save - dstsize + 1);
}
