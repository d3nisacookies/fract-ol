#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

/* ============================ */
/*         CHARACTER            */
/* ============================ */

// Character classification
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// Character conversion
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ============================ */
/*          STRING              */
/* ============================ */

// String examination
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// String manipulation
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
char *ft_strtrim(const char *s1, const char *set);

// String iteration
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ============================ */
/*          MEMORY              */
/* ============================ */

// Memory manipulation
void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *s, size_t n);
void	*ft_memmove(void *dest, const void *s, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);

// Memory allocation
void	*ft_calloc(size_t num, size_t size);

/* ============================ */
/*          CONVERSION          */
/* ============================ */

int		ft_atoi(const char *str);

/* ============================ */
/*          OUTPUT              */
/* ============================ */

// File descriptor output
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int c, int fd);

#endif