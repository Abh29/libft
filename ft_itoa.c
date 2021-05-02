#include "libft.h"

static int  ft_numsize(int n)
{
    int size;

    size = 0;
    if (n < 0)
        size++;
    while (n && size++ > -1)
        n /= 10;
    return (size);
}

char    *ft_itoa(int n)
{
    int     size;
    char    *out;

    if (n == -2147483648)
    {
        out = ft_strdup("-2147483648");
        return (out);
    }
    if (n == 0)
    {
        out = ft_strdup("0");
        return (out);
    }
    size = ft_numsize(n);
    out = malloc (size + 1);
    if (out == NULL)
        return (NULL);
    if (n < 0)
    {
        out[0] = '-';
        n *= -1;
    }
    out[size--] = 0;
    while (n && (out[size--] = n % 10 + '0') > -1)
         n /= 10;
    return (out);
}
