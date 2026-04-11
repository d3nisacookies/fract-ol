#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char *ptr;

    ptr = (char *)s;

    while (n > 0)
    {
        *(ptr++) = 0;
        n--;
    }
}

// #include <stdio.h>

// int main(void)
// {
//     char buffer[10];

//     ft_bzero(buffer, sizeof(buffer));

//     for (size_t i = 0; i < sizeof(buffer); i++)
//     {
//         printf("%c ", buffer[i]);
//     }
//     return 0;
// }