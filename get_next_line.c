#include "get_next_line.h"

char	*ft_join(char *nextline, char *buffer)
{
	int		i;
	int		j;
	char	*fullline;

	i = ft_strlen(nextline);
	j = ft_strlen(buffer);
	fullline = malloc((i + j + 1) * sizeof(char));
	if (!fullline)
		return (NULL);
	i = 0;
	j = 0;	
	while (nextline[i] != '\0')
	{
		fullline[i] = nextline[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		fullline[i] = buffer[j];
		i++;
		j++;
	}
	fullline[i] = '\0';
	free(nextline);
	return (fullline);
}

int		ft_check_n(char	*fullline)
{
	int	i;

	i = 0;
	while (fullline[i] != '\0')
	{
		if (fullline[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_bzero(char *buffer)
{
	int	i;
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*read_fd(char *nextline, int fd)
{
	char	*buffer;
	int		ret;

	ret = 1;
	buffer = ft_calloc(BUFFER_SIZE);
	if (nextline == NULL)
		nextline = ft_calloc(0);
	while (ret > 0)
	{
		ret = (int)read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		nextline =  ft_join(nextline, buffer);
		if (!nextline)
			return (NULL);
		if (ft_check_n(nextline) == 0)
			break;
		ft_bzero(buffer);
	}
	free(buffer);
	return (nextline);
}

char	*create_result(char *fullline)
{
	int		i;
	char	*result;

	i = 0;
	while(fullline[i] != '\0')
	{
		if (fullline [i] == '\n')
			break;
		i++;
	}
	result = malloc((i + 1) * sizeof(char));
	i = 0;
	while (fullline[i] != '\0')
	{
		result[i] = fullline[i];
		if (fullline[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*create_nextline(char *result, char *fullline)
{
	int		start;
	int		size;
	char	*nextline;

	start = ft_strlen(result);
	size = ft_strlen(fullline);
	size = size - start;
	if (size == 0)
		return (NULL);
	size = ft_strlen(fullline) - size;
	nextline = malloc((size + 1) * sizeof(char));
	if (!nextline)
		return (NULL);
	start++;
	size = 0;
	while (fullline[start] != '\0')
	{
		nextline[size] = fullline[start];
		size++;
		start++;
	}
	nextline[size] = '\0';
	return (nextline);
}

char *get_next_line(int fd)
{
	static char	*nextline;
	char		*fullline;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	fullline = read_fd(nextline, fd);
	if (!fullline)
		return (NULL);
	result = create_result(fullline);
	nextline = create_nextline(result, fullline);
	free(fullline);
	return (result);
}

