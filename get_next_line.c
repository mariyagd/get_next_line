/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:47:19 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:28 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "../Libft-42/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static char		*stash;
	size_t			i;
	int				ret;
	size_t			count;


	i = 0;
	count = 0;
	if (fd < 0)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	while (buffer[i] != '\n')
	{
		i++;
		if (buffer[i] == '\n')
		{
			ft_fillstash();
		}
		else
		{
			i = 0;
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret < 0)
				return (NULL);
		}
	}
	return (stash);
}


int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("text", O_RDONLY);
	ft_putnbr_fd(fd, 1);
	printf("\n");
	if (fd == -1)
		return (-1);
	printf("%s\n", get_next_line(fd));
	if (close(fd) == -1)
		return (-1);

	return (0);

}
