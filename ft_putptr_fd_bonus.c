#include "libft.h"
#include <stdint.h>


char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

void ft_putptr_fd(void* ptr, int fd) {
    int i;
    int hold;
    int c;
    uintptr_t p;
    
    p = (uintptr_t)ptr;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    hold = 0;
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        c = (p >> i) & 0xf;
        if (!hold && c != 0)
            hold = 1;
        if (hold)
        ft_putchar_fd(hex_digit(c), fd);
    }
}
