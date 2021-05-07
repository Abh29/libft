#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t 	size;
	char	*s1;
	char	*s2; 

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	size = ft_strlen(haystack);
	while (*haystack && len)
	{
		s1 = (char *)needle;
		s2 = (char *)haystack;
		size = len;
		while (*s1 && size-- && *s2 == *s1)
		{
			s1++;
			s2++;
		}
		if (*s1 == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
