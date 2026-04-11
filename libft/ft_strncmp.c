#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while ((s1[i] || s2[i]) && i < n)
    {
        if ((unsigned char) s1[i] != (unsigned char) s2[i])
        {
            return ((unsigned char) s1[i] - (unsigned char) s2[i]);
        }
        i++;
    }
    return (0);
}

// #include <stdio.h>
// #include <string.h>   // for the real strncmp

// int main(void)
// {
//     const char *a = "Hello";
//     const char *b = "Hello";
//     const char *c = "world";
//     int ft_result;
//     int result;

//     ft_result = ft_strncmp(a,b,5);
//     result = strncmp(a,b,5);

//     printf("comparing a and b. ft_strncmp : %d\n", ft_result);
//     printf("comparing a and b. strncmp : %d\n", result);
//     printf("\n");
//     printf("\n");
//     printf("\n");
    
//     ft_result = ft_strncmp(a,c,5);
//     result = strncmp(a,c,5);

//     printf("comparing a and c. ft_strncmp : %d\n", ft_result);
//     printf("comparing a and c. strncmp : %d\n", result);
// }
