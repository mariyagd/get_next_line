<<<<<<< HEAD
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
=======
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
>>>>>>> 82e3bc735068c7b93be042ea546099326154dd33
	{
		buffer[i] = '\0';
		i++;
	}
<<<<<<< HEAD
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
=======
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
>>>>>>> 82e3bc735068c7b93be042ea546099326154dd33
}

