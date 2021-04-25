#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n--)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 > c2)
			return (1);
		if (c1 < c2)
			return (-1);
		if (*s1 == '\0' || *s2 == '\0')
			break ;
	}
	return (0);
}
