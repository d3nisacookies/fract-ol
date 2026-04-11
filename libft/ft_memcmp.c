#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    i = 0;

    while (i < n)
    {
        if ((unsigned char) str1[i] != (unsigned char) str2[i])
        {
            return ((unsigned char)str1[i] - (unsigned char)str2[i]);
        }
        i++;
    }
    return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     const char *a = "Hello";
//     const char *b = "Hello";
//     const char *c = "world";
//     int ft_result;
//     int result;

//     ft_result = ft_memcmp(a,b,5);
//     result = memcmp(a,b,5);

//     printf("comparing a and b. ft_strncmp : %d\n", ft_result);
//     printf("comparing a and b. strncmp : %d\n", result);
//     printf("\n");
//     printf("\n");
//     printf("\n");
    
//     ft_result = ft_memcmp(a,c,3);
//     result = memcmp(a,c,3);

//     printf("comparing a and c. ft_strncmp : %d\n", ft_result);
//     printf("comparing a and c. strncmp : %d\n", result);
// }