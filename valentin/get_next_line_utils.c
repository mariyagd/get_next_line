/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfinocie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:11:32 by vfinocie          #+#    #+#             */
/*   Updated: 2022/11/01 17:34:02 by vfinocie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *ptr, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)ptr;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *tmpbuff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(buffer) + ft_strlen(tmpbuff) +1);
	if (!buffer || !tmpbuff || !str)
		return (NULL);
	while (buffer[i] != 0)
	{
		str[i] = buffer[i];
		i++;
	}
	while (tmpbuff[j] != 0)
	{
		str[i + j] = tmpbuff[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}
