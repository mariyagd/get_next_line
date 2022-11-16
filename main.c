#include "get_next_line.h"

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
}
