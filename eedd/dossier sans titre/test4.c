#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char  *ft_calloc()
{
	char	*buffer;
    int 	i;
   
	i = 0;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    while (i <= BUFFER_SIZE)
    {
       buffer[i] = '\0';
        i++;
    }
	return (buffer);
}


int main (void)
{
    int     ret;
    char    *buffer;

    ret = 0;
    buffer = ft_calloc();
	int fd = open("text", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	while (ret < BUFFER_SIZE)
	{
		printf("%c\n", buffer[ret]);
		ret++;
	}
}

