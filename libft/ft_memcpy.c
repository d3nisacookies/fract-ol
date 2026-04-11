#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *tmp;
    unsigned char *src_tmp;

    if (dest == NULL && src == NULL)
        return (dest);
    
    tmp = (unsigned char *)dest;
    src_tmp = (unsigned char *)src;

    while (n-- > 0)
    {
        *(tmp++) = *(src_tmp++); 
    }
    return (dest);
}

#include <stdio.h>
#include <string.h>

// Your ft_memcpy function here

// int main(void)
// {
//     char src1[] = "Hello World!";
//     char dest1[20];
//     char dest2[20];
    
//     // Test 1: Basic copy
//     printf("Test 1 - Basic copy:\n");
//     ft_memcpy(dest1, src1, strlen(src1) + 1); // +1 for null terminator
//     memcpy(dest2, src1, strlen(src1) + 1);
//     printf("ft_memcpy: %s\n", dest1);
//     printf("memcpy:    %s\n", dest2);
//     printf("Match: %s\n\n", strcmp(dest1, dest2) == 0 ? "✓" : "✗");
    
//     // Test 2: Partial copy
//     printf("Test 2 - Partial copy (first 5 chars):\n");
//     char src2[] = "Testing";
//     char dest3[10] = {0};
//     char dest4[10] = {0};
    
//     ft_memcpy(dest3, src2, 5);
//     memcpy(dest4, src2, 5);
//     printf("ft_memcpy: %s\n", dest3);
//     printf("memcpy:    %s\n", dest4);
//     printf("Match: %s\n\n", strncmp(dest3, dest4, 5) == 0 ? "✓" : "✗");
    
//     // Test 3: Copy to existing data (overlap test)
//     printf("Test 3 - Overwrite existing data:\n");
//     char buffer1[20] = "Original Data";
//     char buffer2[20] = "Original Data";
    
//     ft_memcpy(buffer1, "New", 3);
//     memcpy(buffer2, "New", 3);
//     printf("ft_memcpy: %s\n", buffer1);
//     printf("memcpy:    %s\n", buffer2);
//     printf("Match: %s\n\n", strcmp(buffer1, buffer2) == 0 ? "✓" : "✗");
    
//     // Test 4: Empty/NULL handling
//     printf("Test 4 - NULL pointer handling:\n");
//     char *null_ptr = NULL;
//     char normal[10] = "test";
    
//     // This should not crash (but standard memcpy behavior with NULL is undefined)
//     printf("Testing with NULL pointers...\n");
//     ft_memcpy(normal, normal, 0); // This should be safe
//     printf("Zero-length copy completed successfully ✓\n\n");
    
//     // Test 5: Binary data copy
//     printf("Test 5 - Binary data copy:\n");
//     int numbers_src[] = {1, 2, 3, 4, 5};
//     int numbers_dest1[5];
//     int numbers_dest2[5];
    
//     ft_memcpy(numbers_dest1, numbers_src, sizeof(numbers_src));
//     memcpy(numbers_dest2, numbers_src, sizeof(numbers_src));
    
//     printf("Arrays match: %s\n", 
//            memcmp(numbers_dest1, numbers_dest2, sizeof(numbers_src)) == 0 ? "✓" : "✗");
    
//     for (int i = 0; i < 5; i++) {
//         printf("ft_memcpy[%d] = %d, memcpy[%d] = %d %s\n", 
//                i, numbers_dest1[i], i, numbers_dest2[i],
//                numbers_dest1[i] == numbers_dest2[i] ? "✓" : "✗");
//     }
    
//     return 0;
// }