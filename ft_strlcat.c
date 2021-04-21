#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		save;

	save = dstsize;
	while (dstsize-- && *dst)
		dst++;
	if (dstsize)
	{
		dstsize++;
		while (dstsize-- && *src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = 0;
	}
	return (save - dstsize + 1);
}
