#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *out;
    char    *save;

    if (s == NULL)
        return (NULL);
    out = malloc(len + 1);
    if (out == NULL)
        return (NULL);
    while (*s && start--)
        s++;
    save = out;
    while (*s && len--)
        *out++ = *s++;
    *out = '\0';
    return (save);
}