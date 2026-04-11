#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    unsigned int i;
    char j;
    
    j = (char)c;
    i = 0;

    while(s[i])
    {
        if(s[i] == j)
        {
            return ((char *) &s[i]);
        }
        i++;
    }
    if (s[i] == j)
    {
        return ((char *) &s[i]);
    }
    return NULL;
}