#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char *dest_tmp;
    unsigned char *src_tmp;

    if (!dest && !src)
    {
        return (NULL);
    }
    dest_tmp = (unsigned char *)dest;
    src_tmp = (unsigned char *)src;
    if(dest_tmp < src_tmp)
    {
        while (len--)
        {
            *dest_tmp++ = *src_tmp++;
        }
    }else
    {
        dest_tmp += len;
        src_tmp += len;
        while(len--)
        {
            *--dest_tmp = *--src_tmp;
        }
    } 
    return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char str1[] = "Hello World!";
//     char str2[] = "Hello World!";

//     ft_memmove(str1 + 7, str1, 5);
//     memmove(str2 + 7, str2, 5);

//     printf("ft_memmove : %s\n", str1);
//     printf("memmove : %s\n", str2);

//     return 0;
// }