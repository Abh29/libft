#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = malloc(count * size);
	ft_bzero(out, count * size);
	return (out);
}
