#include "libft.h"

static int  ft_containchar(const char *s, char c)
{
    while (*s)
        if (c == (char)*s++)
            return (1);
    return (0);
}

char        *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int size;

    if (s1 == NULL || set == NULL)
        return (NULL);
    size = ft_strlen(s1);
    start = 0;
    while (ft_containchar(set, s1[start]))
        start++;
    while (start < size && ft_containchar(set, s1[size - 1]))
        size--;
    if (start < size)
        return (ft_substr(s1, start, size - start));
    return ("\0");
}