#include "libft.h"

char *ft_strmapi(char *s, char (*f)(unsigned int ,char))
{
    unsigned int    i;
    char            *result;
    size_t          s_len;

    if (!s || !f)
        return (NULL);
    s_len = ft_strlen(s);
    result = malloc((s_len + 1) * sizeof(char));
    if (!result)
    {
        return (NULL);
    }
    i = 0;
    while (i < s_len)
    {
        result[i] = (*f)(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return result;
}
