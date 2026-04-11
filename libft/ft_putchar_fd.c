#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

// #include <unistd.h>

// int main(void)
// {
//     // Write "Hello" character by character to stdout
//     ft_putchar_fd('H', 0);
//     ft_putchar_fd('e', 1);
//     ft_putchar_fd('l', 1);
//     ft_putchar_fd('l', 1);
//     ft_putchar_fd('o', 1);
//     ft_putchar_fd('\n', 1);
    
//     // Write error message to stderr
//     ft_putchar_fd('E', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('o', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('\n', 2);
    
//     return 0;
// }