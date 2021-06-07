#include "libft.h"
#include <stdint.h>

void ft_putptr_fd_size(void* ptr, int fd, size_t *size, t_options options)
{
    int i;
    int hold;
    int c;
    uintptr_t p;
    long width;
    
    p = (uintptr_t)ptr;
    width = (long)options.width;
    while (!options.l_shift && width-- > 14)
        ft_putchar_fd_size(' ', fd, size);
    ft_putstr_fd_size("0x", fd, size, OPTIONS(0, INT_MAX, 0, 0, 0, 0));
    hold = 0;
    i = (sizeof(p) << 3) - 4;
    while (i >= 0)
    {
        c = (p >> i) & 0xf;
        if (!hold && c != 0)
            hold = 1;
        if (hold)
        ft_putchar_fd_size(ft_hex_digit(c), fd, size);
        width--;
        i -= 4;
    }
    while (options.l_shift && width-- > -2)
        ft_putchar_fd_size(' ', fd, size);
}
