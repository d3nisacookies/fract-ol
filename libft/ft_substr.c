#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *dest;
    size_t i;

    if(!s)
    {
        return NULL;
    }
    if(start > ft_strlen(s))
    {
        return(ft_strdup(""));
    }
    if(len > ft_strlen(s) + start)
    {
        len = ft_strlen(s) + start;
    }
    dest = ft_calloc(len + 1, sizeof(char));
    if (!dest)
    {
        return NULL;
    }
    i = 0;
    while(i < len)
    {
        dest[i] = s[start + i];
        i++;
    }
    return dest;
}