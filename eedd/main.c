#include "get_next_line.h"

<<<<<<< HEAD
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
=======
int	main (void)
{
	int			fd;
	char	*line;
	ssize_t	ret;
	char	*buf;
	int		i;


	i = 0;
	ret = 1;
	fd = open("text", O_RDONLY);


		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT  = %s\n", line);
	return (0);
>>>>>>> 82e3bc735068c7b93be042ea546099326154dd33
}
