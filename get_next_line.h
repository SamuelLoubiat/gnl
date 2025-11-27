#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_strdup(char *s);
size_t    ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
#endif
