/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfinocie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:23:26 by vfinocie          #+#    #+#             */
/*   Updated: 2022/11/19 16:00:42 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_delreadline(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(buffer + i) + 1), sizeof(char));
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}

char	*ft_prepline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_joinandfree(char *buffer, char *tmpbuff)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, tmpbuff);
	free(buffer);
	return (tmp);
}

char	*ft_readfile(char *buffer, int fd)
{
	char	*tmpbuff;
	int		bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmpbuff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0 && ft_strchr(tmpbuff, '\n') == 0)
	{
		if (tmpbuff)
			ft_bzero(tmpbuff, ft_strlen(tmpbuff));
		bytes = read(fd, tmpbuff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmpbuff);
			free(buffer);
			return (NULL);
		}
		tmpbuff[bytes] = 0;
		buffer = ft_joinandfree(buffer, tmpbuff);
	}
	free(tmpbuff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_readfile(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_prepline(buffer);
	buffer = ft_delreadline(buffer);
	return (line);
}
