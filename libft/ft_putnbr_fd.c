#include "libft.h"

void ft_putnbr_fd(int c, int fd)
{
    if (c == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (c < 0)
    {
        ft_putchar_fd('-', fd);
        c = -c;
    }
    if (c >= 10)
    {
        ft_putnbr_fd(c / 10, fd);
    }
    ft_putchar_fd((c % 10) + '0', fd);
}

// int main(void)
// {
//     ft_putnbr_fd(1,1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(-1,1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(1231223,1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(-2147483648,1);
//     write(1, "\n", 1);
// }