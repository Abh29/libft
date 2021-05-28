#include "libft.h"
#include <stdint.h>

void ft_putptr_fd_size(void* ptr, int fd, size_t *size)
{
    int i;
    int hold;
    int c;
    uintptr_t p;
    
    p = (uintptr_t)ptr;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    (*size) += 2;
    hold = 0;
    i = (sizeof(p) << 3) - 4;
    while (i >= 0)
    {
        c = (p >> i) & 0xf;
        if (!hold && c != 0)
            hold = 1;
        if (hold)
        ft_putchar_fd_size(ft_hex_digit(c), fd, size);
        i -= 4;
    }
}
