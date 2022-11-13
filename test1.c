/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/12 22:05:54 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_list
{
	char 			*content;
	ssize_t			size;
	struct s_list	*next;
}					t_list;

int check_if_n(char *buffer, ssize_t ret)
{
    ssize_t i;
    i = 0;
    while (i < ret && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (0);
    else
        return (1);
}

t_list  *create_node(char *buffer, ssize_t size)
{
    t_list  *node;
	char	*stash;
	ssize_t	i;

	i = 0;
	stash = malloc((size + 1) * sizeof(char));
	while (i < size)
	{
		stash[i] = buffer[i];
		i++;
	}
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->size = size;
    node->content = stash;
    node->next = NULL;
    return (node);
}

t_list  *find_lastnode(t_list *head)
{
    while (head->next != NULL && head != NULL)
        head = head->next;
    return (head);
}

t_list  *create_linkedlist(t_list **head, t_list *node)
{
    t_list  *lastnode;

    if (*head == NULL)
        *head = node;
	else if (*head != NULL && node != NULL)
	{
		lastnode = find_lastnode(*head);
		lastnode->next = node;
	}
    return (*head);
}


ssize_t	count_stashsize(t_list *head)
{
	ssize_t		size;
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


char	*create_and_fillresult(char *line)
{
	ssize_t	i;
	ssize_t j;
	char	*result;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
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


void	delete_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}

ssize_t	count_nextlinesize(char *line)
{
	ssize_t	i;
	ssize_t	size_nextline;
	
	i = 0;
	size_nextline = 0;
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

char	*create_and_fillnextline(char *line)
{
	char *nextline;
	ssize_t	size_nextline;
	ssize_t	i;

	size_nextline = count_nextlinesize(line);
	nextline = malloc(size_nextline * sizeof(char));
	size_nextline = 0;
	i = 0;
	while (line[i] != '\n')
	   i++;
	i++;
	while (line[i] != '\0')
	{
		nextline[size_nextline] = line[i];
		i++;
		size_nextline++;
	}
	return (nextline);
}

char	*read_and_create_list(int fd, t_list **head)
{
	ssize_t				ret;
    char     			buffer[BUFFER_SIZE + 1];
	t_list				*node;
	char				*fullline;
	static ssize_t		size;
	static char *nextline;

	nextline = NULL;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (nextline != NULL)
		*head = create_node(nextline, size);
	else
		*head = create_node(buffer, ret);
	while (check_if_n(buffer, ret) == 1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			delete_list(head);
			return (NULL);
		}
		node = create_node(buffer, BUFFER_SIZE);
		create_linkedlist(head, node);
	}
	fullline = create_and_fillstash(head);
	delete_list(head);
	nextline = create_and_fillnextline(fullline);
	size = count_nextlinesize(fullline);
	return (fullline);
}

char    *get_next_line(int fd)
{
	static ssize_t	size_nextline;
    char            *fullline;
	char			*result;
	t_list			*head;

	size_nextline = 0;
	fullline = read_and_create_list(fd, &head);
	result = create_and_fillresult(fullline);
	free(fullline);
	return (result);
}



int	main (void)
{
	int			fd;
	char	*line;

	fd = open("text", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);

	line = get_next_line(fd);
	printf("%s\n", line);

	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}

