/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:06:48 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/17 17:04:52 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"
#include "get_next_line.h"

int ft_strlen(char *string)
{
    int i;

    i = 0;
    while (string[i] != '\0')
        i++;
    return (i);
}

char    *ft_join(char *line, char *buffer)
{
    int     i;
    int     j;
    char    *stash;

    i = ft_strlen(line);
    j = ft_strlen(buffer);
	if (line == NULL || buffer == NULL)
		return (NULL);
    stash = malloc((i + j + 1) * sizeof(char));
    if (!stash)
        return (NULL);
    i = 0;
    j = 0;
    while (line[i] != '\0')
    {
        stash[i] = line[i];
        i++;
    }
    while (buffer[j] != '\0')
    {
        stash[i] = buffer[j];
        i++;
        j++;
    }
    stash[i] = '\0';
    free(line);
    return (stash);
}

#include <limits.h>

int	main(void)
{
	int		fd;
	int		ret;
	char	*buffer;

	//Si buffer = NULL, read ne peut pas copier dans buffer et ret sera egal a -1
//	buffer = NULL;
	/*fd = open("text.txt", O_RDONLY);
	ret = (int)read(fd, buffer, BUFFER_SIZE);
	printf("%s\n", buffer);
	printf("%d\n", ret);

	char	*str = "HELLO";
	//printf("%s\n", ft_join(str, buffer));*/

	//BUFEER_SIZE > 32'767
	ssize_t	a;
	char	*buffer1[BUFFER_SIZE + 1];
	fd = open("text.txt", O_RDONLY);
	a = read(fd, buffer1, BUFFER_SIZE);
	printf("%zu\n", a);
	printf("%zu\n", SIZE_MAX);

	return (0);
}





