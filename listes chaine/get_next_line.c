/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/16 18:14:52 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


char	*create_fullline(t_list **head)
{
	t_list *ptr;
	int		i;
	int		j;
	int 	size;
	char	*fullline;
	
	i = 0;
	j = 0;
	size = 0;
	ptr = *head;
	while (ptr != NULL)
	{
		while (ptr->content[i] != '\0')
		{
			i++;
			size++;
		}
		i = 0;
		ptr = ptr->next;
	}
	fullline = malloc((size + 1) * sizeof(char));
	i = 0;
	size = 0;
	ptr = *head;
	while (ptr != NULL)
	{
		while (ptr->content[i] != '\0')
		{
			fullline[j] = ptr->content[i];
			i++;
			j++;
		}
		i = 0;
		ptr = ptr->next;
	}
	fullline[j] = '\0';
	return (fullline);
}

void	ft_bzero(char *buffer, int size)
{
	int	i;
	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
	buffer[i] = '\0';
}

char	*read_fullline(char *nextline, int fd)
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	t_list	*head;
	t_list	*node;
	char 	*fullline;

	ret = 0;
	ft_bzero(buffer, BUFFER_SIZE);
	if (nextline != NULL)
	{
		while (nextline[ret] != '\0')
		{
			buffer[ret] = nextline[ret];
			ret++;
		}
		free(nextline);
	}
	else
		ret = (int)read(fd, buffer, BUFFER_SIZE);
	head = create_node(buffer, ret);
	while (ret > 0 && check_if_n(buffer, ret) == 1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		ret = (int)read(fd, buffer, BUFFER_SIZE);
		node = create_node(buffer, ret);
		create_linkedlist(&head, node);
	}
	if (ret < 0)
	{
		delete_list(&head);
		return (NULL);
	}
	 fullline = create_fullline(&head);
	 delete_list(&head);
	 return (fullline);
}

char	*create_result(char *fullline)
{
	int		i;
	char	*result;

	i = 0;
	while (fullline[i] != '\n' && fullline[i] != '\0')
		i++;
	result = malloc((i + 1) * sizeof(char));
	i = 0;
	while (fullline[i] != '\n' && fullline[i] != '\0')
	{
		result[i] = fullline[i];
		i++;
	}
	if (fullline[i] == '\n')
	{
		result[i] = '\n';
		i++;
	}
	result[i] = '\0';
	return (result);
}

	
char	*create_nextline(char *fullline)
{
	int		i;
	int		size;
	int		start;
	char	*nextline;

	i = 0;
	size = 0;
	while(fullline[i] != '\n' && fullline[i] != '\0')
		i++;
	if (fullline[i] == '\0')
		return (NULL);
	else if (fullline[i] == '\n')
	{
		i++;
		start = i;
	}
	while (fullline[i] != '\0')
	{
		i++;
		size++;
	}
	nextline = malloc((size + 1) * sizeof(char));
	i = 0;
	while (fullline[start] != '\0')
	{
		nextline[i] = fullline[start];
		i++;
		start++;
	}
	nextline[i] = '\0';
	return (nextline);
}



char    *get_next_line(int fd)
{
    static char		*nextline;
	char            *fullline;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	fullline = read_fullline(nextline, fd);
	if (!fullline)
		return (NULL);
	result = create_result(fullline);
	nextline = create_nextline(fullline);
	free(fullline);
	return (result);
}





