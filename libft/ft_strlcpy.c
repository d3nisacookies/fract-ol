#include "libft.h"

size_t ft_strlcpy(char *dest, char *src, size_t dstsize)
{
    size_t src_len;
    size_t i;

    src_len = 0;
    while(src[src_len])
    {
        src_len++;
    }
    if(dstsize == 0)
    {
        return(src_len);
    }
    i = 0;
    while(src[i] && i < (dstsize - 1))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return src_len;
}

// #include <stdio.h>

// int main()
// {
//     char src[] = "Hello, World!";
//     char dest[10];
//     size_t result;

//     result = ft_strlcpy(dest, src, sizeof(dest));

//     printf("destination: '%s'\n", dest);
//     printf("length: %zu\n", result);
//     printf("truncated: %s\n", result > sizeof(dest) - 1 ? "Yes" : "No");
//     return 0;
// }