#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
int fd = open("test.txt", O_RDONLY);
char *res = get_next_line(fd);
printf("%s", res);
free(res);
res = get_next_line(fd);
printf("%s", res);
free(res);
res = get_next_line(fd);
printf("%s", res);
free(res);
res = get_next_line(fd);
printf("%s", res);
free(res);
res = get_next_line(fd);
printf("%s", res);
free(res);
res = get_next_line(fd);
printf("%s", res);
free(res);
return (0);
}