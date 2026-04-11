#include "libft.h"

void *ft_calloc(size_t num, size_t size)
{
    size_t i;
    unsigned char *temp;

    i = 0;
    temp = malloc(num * size);

    if(!temp)
        return NULL;
    while(i < num * size)
    {
        temp[i++] = 0;
    }
    return temp;
}