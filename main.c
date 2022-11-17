#include "get_next_line.h"

int main (void)
{
    int         fd;
    char    *line;

    fd = open("text1ch", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    return (0);
}
