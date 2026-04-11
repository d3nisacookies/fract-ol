#include "libft.h"

// Change parameter to const char*
static int to_trim(const char *set, char c)
{
    size_t i;
    i = 0;

    while(set[i])
    {
        if (c == set[i])
            return 1;
        i++;
    }
    return 0;
}

// Change return type to char* (not const char*)
static char *new_str(const char *s1, size_t start, size_t len)
{
    char *str;
    size_t i;

    if(len <= 0 || start >= ft_strlen(s1))
    {
        return(ft_strdup(""));
    }
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
    {
        return NULL;
    }
    i = 0;
    while(i < len)
    {
        str[i] = s1[start + i];
        i++;
    }
    return (str);
}

char *ft_strtrim(const char *s1, const char *set)
{
    size_t i;
    size_t j;
    size_t s1_len;

    if (!s1 || !set)
        return (NULL);
        
    s1_len = ft_strlen(s1);
    if (s1_len == 0)
    {
        return (ft_strdup(""));
    }
    
    i = 0;
    j = s1_len - 1;

    while (to_trim((const char *)set, s1[i]))  // Cast to fix const issue
        i++;
        
    // Check if entire string was trimmed
    if (i > j)
        return (ft_strdup(""));
        
    while (to_trim((const char *)set, s1[j]))  // Cast to fix const issue
        j--;
        
    return(new_str(s1, i, (j - i) + 1));  // Fixed the length calculation
}