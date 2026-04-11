#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *result;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;

    result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
    if (!result)
    {
        return NULL;
    }
    while (s1[i])
    {
        result[j++] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        result[j++] = s2[i];
        i++;
    }
    result[j] = '\0';
    return (result);
}