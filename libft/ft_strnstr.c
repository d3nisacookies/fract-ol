#include "libft.h"
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;

    if(needle[0] == 0)
    {
        return (char *) haystack;
    }
    while (haystack[i] && i < len)
    {
        while(haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
        {
            j++;
            if(needle[j] == 0)
            {
                return((char *)haystack + i);
            }
        }
        i++;
        j = 0;
    }
    return (0);
}

// #include <stdio.h>
// #include <string.h>   // for strnstr

// int main(void)
// {
//     const char *haystack = "Hello world, welcome!";
//     const char *needle1 = "world";
//     const char *needle2 = "welcome";
//     const char *needle3 = "nope";
//     const char *needle4 = "";
    
//     struct {
//         const char *needle;
//         size_t len;
//     } tests[] = {
//         {needle1, 20},   // should find "world"
//         {needle2, 20},   // should find "welcome"
//         {needle2, 10},   // too short, should return NULL
//         {needle3, 20},   // not found
//         {needle4, 20},   // empty needle
//     };

//     int n = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < n; i++)
//     {
//         char *mine = ft_strnstr(haystack, tests[i].needle, tests[i].len);

//         printf("Test %d: searching \"%s\" in \"%s\" (len=%zu)\n",
//                i+1, tests[i].needle, haystack, tests[i].len);
//         printf("  ft_strnstr -> %s\n\n", mine ? mine : "NULL");
//     }

//     return 0;
// }
