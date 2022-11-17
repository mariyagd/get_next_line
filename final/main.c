#include "get_next_line.h"
#include <stdio.h>

int	main (void)
{
	int			fd;
	char	*line;
	ssize_t	ret;
	char	*buf;
	int		i;


	i = 0;
	ret = 1;
	fd = open("text.txt", O_RDONLY);


		line = get_next_line(fd);
		printf("RESULT 1  = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 2 = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 3 = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 4 = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 5 = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 6 = %s\n", line);
		line = get_next_line(fd);
		printf("RESULT 7 = %s\n", line);


	close(fd);
	return (0);
}
