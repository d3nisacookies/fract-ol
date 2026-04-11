#include "libft.h"

int ft_toupper(int c)
{
    if(c >= 'a' && c <= 'z')
        return(c - 32);
    return (c);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("toupper z: %c\n ", ft_toupper('z'));
//     return 0;    
// }