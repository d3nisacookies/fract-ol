#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    unsigned int i;
    char *result;
    char j;

    j = (char)c;

    result = NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == j)
        {
            result = (char *) &s[i];
        }
        i++;
    }
    if (s[i] == j)
    {
        result = (char *) &s[i];
    }
    return (result);
}

// #include <stdio.h>
// #include <string.h>  // for the real strrchr

// int main(void)
// {
//     const char *str = "Hello World!";
//     int tests[] = { 'o', 'l', 'H', '!', 'x', '\0' };
//     int n = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < n; i++)
//     {
//         int c = tests[i];
//         char *std = strrchr(str, c);
//         char *mine = ft_strrchr(str, c);

//         printf("Test %d: searching for '%c' (ASCII %d)\n", i+1, (c ? c : '0'), c);
//         printf("  strrchr   -> %s\n", std ? std : "NULL");
//         printf("  ft_strrchr-> %s\n\n", mine ? mine : "NULL");
//     }

//     return 0;
// }
