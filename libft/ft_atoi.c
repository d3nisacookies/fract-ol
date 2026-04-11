#include "libft.h"

static int isspace(int c)
{
    if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
    {
        return (1);
    }
    return (0);
}

int ft_atoi(const char *str)
{
    int result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;

    while(isspace(str[i]))
        i++;
    if(str[i] == '+' && str[i + 1] != '-')
    {
        i++;
    }
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i] && str[i] >= 48 && str[i] <= 57)
    {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    result *= sign;
    return (result);
}

// #include <stdio.h>
// #include <stdlib.h>   // for the real atoi

// int main(void)
// {
//     const char *tests[] = {
//         "42",
//         "   123",
//         "\t\n\v\f\r 456",   // with whitespace
//         "-789",
//         "+1011",
//         "   -0012",
//         "999999999",
//         "abc42",            // non-digit start
//         "42abc",            // digits then letters
//         "",
//         "   + 12",          // tricky case: plus with space
//     };

//     int n = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < n; i++)
//     {
//         int std = atoi(tests[i]);
//         int mine = ft_atoi(tests[i]);

//         printf("Test %2d: \"%s\"\n", i+1, tests[i]);
//         printf("  atoi    -> %d\n", std);
//         printf("  ft_atoi -> %d\n\n", mine);
//     }

//     return 0;
// }
