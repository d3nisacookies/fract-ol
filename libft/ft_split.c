#include "libft.h"

char **ft_split(const char *s, char c);
static int is_delim(char c, char delim);
static int word_count(const char *s, char delim);
static char *allo_word(const char *s, char delim);
static void free_all(char **result, int i);

char **ft_split(const char *s, char c)
{
    char **result;
    size_t i;

    i = 0;
    if(!s)
        return NULL;

    result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
    if(!result)
        return NULL;
    while (*s)
    {
        while(*s && is_delim(*s, c)) // skipping all delimiters
        {
            s++;
        }
        if(*s)
        {
            result[i] = allo_word(s, c);
            if (!result[i])
            {
                return (free_all(result, i - 1),NULL);
            }
            i++;
            while(*s && !is_delim(*s, c))
            {
                s++;
            }
        }
    }
    result[i] = NULL;
    return (result);
}

static int is_delim(char c, char delim)
{
    return(c == delim);
}

static int word_count(const char *s,char delim)
{
    size_t count;

    count = 0;

    while(*s) //while going through the words
    {
        while(*s && is_delim(*s, delim)) //increment till the delimiter (this mainly skips the first white spaces just in case.)
        {
            s++;
        }
        if(*s) //if not a delimiter
        {
            count++; //add a word to count
            while(*s && !is_delim(*s, delim)) //skip all characters till the delimiter
            {
                s++;
            }
            //repeat
        }
    }
    return (count);
}

static char *allo_word(const char *s, char delim)
{
    size_t  len;
    char    *word;
    size_t  i;

    len = 0;
    i = 0;

    while (s[len] && !is_delim(s[len], delim)) // goes through the word till the delim
    {
        len++;
    }
    word = (char *)malloc((len + 1) * sizeof(char)); //allocates memory for the word with the size of a char
    if (!word) // in case it is empty
    {
        return (NULL);
    }
    while (i < len) // copy the word in to the allocated memory
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0'; // adds null terminator
    return word;
}

static void free_all(char **result, int i) //this is to free all the allocated memory after using the functions.
{
    while(i >= 0)
    {
        free(result[i]);
        i--;
    }
    free(result);
}

// #include <stdio.h>
// int main(void)
// {
//     // Test cases
//     const char *test_strings[] = {
//         "hello world test",
//         "  leading spaces",
//         "trailing spaces  ",
//         "  multiple   spaces  ",
//         "single",
//         "",
//         "   ",
//         "a b c d e",
//         "split,with,commas",
//         NULL
//     };
    
//     char delimiters[] = {' ', ','};
    
//     printf("=== Testing ft_split ===\n\n");
    
//     // Test with space delimiter
//     for (int i = 0; test_strings[i] != NULL; i++)
//     {
//         printf("Test %d: \"%s\"\n", i + 1, test_strings[i]);
        
//         char **result = ft_split(test_strings[i], ' ');
        
//         if (result == NULL)
//         {
//             printf("  Result: NULL\n\n");
//             continue;
//         }
        
//         printf("  Words: ");
//         for (int j = 0; result[j] != NULL; j++)
//         {
//             printf("[%s] ", result[j]);
//         }
//         printf("\n");
        
//         // Count words for freeing
//         int word_count = 0;
//         while (result[word_count] != NULL)
//             word_count++;
        
//         free_all(result, word_count - 1);
//         printf("\n");
//     }
    
    
//     // Test with comma delimiter
//     printf("=== Testing with comma delimiter ===\n");
//     const char *comma_test = "one,two,three,four";
//     printf("String: \"%s\"\n", comma_test);
    
//     char **comma_result = ft_split(comma_test, ',');
    
//     if (comma_result != NULL)
//     {
//         printf("Words: ");
//         for (int j = 0; comma_result[j] != NULL; j++)
//         {
//             printf("[%s] ", comma_result[j]);
//         }
//         printf("\n");
        
//         // Count words for freeing
//         int word_count = 0;
//         while (comma_result[word_count] != NULL)
//             word_count++;
        
//         free_all(comma_result, word_count - 1);
//     }
    
//     // Test NULL input
//     printf("\n=== Testing NULL input ===\n");
//     char **null_result = ft_split(NULL, ' ');
//     printf("NULL input result: %s\n", (null_result == NULL) ? "NULL" : "Not NULL");
    
//     return 0;
// }