/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:31:12 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/19 17:31:15 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	prepare_forstash(char **line, char **buffer)
{
	*buffer = ft_calloc(BUFFER_SIZE);
	if (*line == NULL)
		*line = ft_calloc(0);
}

char	*ft_join(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*stash;

	if (!line || !buffer)
		return (NULL);
	i = ft_strlen(line);
	j = ft_strlen(buffer);
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
		stash[i++] = buffer[j++];
	stash[i] = '\0';
	free(line);
	return (stash);
}

char	*ft_calloc(int count)
{
	char	*string;
	int		i;

	i = 0;
	string = malloc((count + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (i <= count)
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	there_is_n(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
