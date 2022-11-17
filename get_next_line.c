/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:27:55 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/14 17:56:23 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/*************************************************************************** */
#include "get_next_line.h"

ssize_t count_stashsize(t_list *head)
{
    ssize_t     size;
    t_list      *ptr;

    size = 0;
    ptr = head;
    while (ptr != NULL)
    {
        size = size + ptr->size;
        ptr = ptr->next;
    }
    return(size);
}

char    *create_and_fillstash(t_list **head)
{
    char        *line;
    ssize_t     size;
    ssize_t     i;
    t_list      *ptr;

    i = 0;
    size = count_stashsize(*head);
	if (size == 0)
		return (NULL);
    line = malloc((size + 1) * sizeof(char));
    size = 0;
    ptr = *head;
    while (ptr != NULL)
    {
        while (i < ptr->size)
        {
            line[size] = ptr->content[i];
            size++;
            i++;
        }
        i = 0;
        ptr = ptr->next;
    }
    line[size] = '\0';

    return (line);
}

char    *create_and_fillresult(char *line)
{
    ssize_t i;
    ssize_t j;
    char    *result;

    i = 0;
    j = 0;
    while (line[i] != '\n' || line[i] == '\0')
        i++;
	if (line[i] == '\n')
		i++;

    result = malloc((i + 1)*sizeof(char));
    while (j < i)
    {
        result[j] = line[j];
        j++;
    }
    result[j] = '\0';
    return (result);
}

ssize_t count_nextlinesize(char *line)
{
    ssize_t i;
    ssize_t size_nextline;

    i = 0;
    size_nextline = 0;
	if (line[i] == '\n' && line[i + 1] == '\0')
		return (0);
    while (line[i] != '\n')
        i++;
    i++;
    while (line[i] != '\0')
    {
        i++;
        size_nextline++;
    }
    return (size_nextline);
}


char    *create_and_fillnextline(char *line)
{
    char *nextline;
    ssize_t size_nextline;
    ssize_t i;

    size_nextline = count_nextlinesize(line);
	if (size_nextline == 0)
		return (NULL);
    nextline = malloc(size_nextline * sizeof(char));
    size_nextline = 0;
    i = 0;
    while (line[i] != '\n')
       i++;
	if (line[i] == '\n')
		i++;
    while (line[i] != '\0')
    {
        nextline[size_nextline] = line[i];
        i++;
        size_nextline++;
    }
    return (nextline);
}

char	*mallocbuffer(char *buffer)
{
	ssize_t	i;

	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*read_and_create_list(int fd, char **nextline, ssize_t size, char **fullline)
{
    ssize_t             ret;
    char                *buffer;
    t_list              *node;
	t_list				*head;

	ret= 0;
	buffer = NULL;
	if (*nextline != NULL)
	{
		head = create_node(*nextline, size);
		if (check_if_n(*nextline, size) == 1)
		{
			while (check_if_n(buffer, ret) == 1)
			{

				buffer = NULL;
				buffer = mallocbuffer(buffer);
				ret = read(fd, buffer, BUFFER_SIZE);
				node = create_node(buffer, ret);
				create_linkedlist(&head, node);
			}
		}
	}
	else if (*nextline == NULL)
	{
		buffer = mallocbuffer(buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0 || ret < 0)
			return (NULL);
		head = create_node(buffer, ret);
		while (check_if_n(buffer, ret) == 1)
		{
			free(buffer);
			buffer = NULL;
			buffer = mallocbuffer(buffer);
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret < 0)
			{
				delete_list(&head);
				return (NULL);
			}
			if (ret == 0)
				break;
			node = create_node(buffer, BUFFER_SIZE);
			create_linkedlist(&head, node);
		}
	}
    *fullline = create_and_fillstash(&head);
    delete_list(&head);
	return (*fullline);
}

char    *get_next_line(int fd)
{
    char            *fullline;
    char            *result;
	static char		*nextline;
	static ssize_t	size;

	if (fd < 0)
		return (NULL);
    fullline = read_and_create_list(fd, &nextline, size, &fullline);
	if (fullline == NULL)
		return (NULL);
	nextline = create_and_fillnextline(fullline);
	if (nextline != NULL)
		size = count_nextlinesize(fullline);
	result = create_and_fillresult(fullline);
	free(fullline);
    return (result);
}

