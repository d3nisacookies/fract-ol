#include "libft.h"

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
    {
        return (c + 32);
    }
    return (c);
}

// #include <stdio.h>
// int main(){
//     printf("tolower Z :  %c\n", ft_tolower('Z'));
//     return 0;
// }