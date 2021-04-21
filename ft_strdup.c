#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*out;

	if (!s1)
		return (NULL);

	out = (char *)malloc(ft_strlen(s1) + 1);
	if (out != NULL)
	{
		while (*s1)
			*out++ = *s1++;
		*out = '\0';
	}
	return (out);
}
