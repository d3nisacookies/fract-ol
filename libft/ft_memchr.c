#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *i;
    unsigned char j;
    size_t counter;

    i = (unsigned char *)s;
    j = (unsigned char)c;
    counter = 0;

    while (counter < n)
    {
        if (i[counter] == j)
        {
            return ((void *) &i[counter]);
        }
        counter++;
    }
    return (NULL);
}