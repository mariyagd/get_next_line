/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/08 17:18:25 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "gnl.h"
//#define BUFFER_SIZE 55
int error_read_ft(ssize_t ret)
{
    if (ret < 0)
        return (0);
    else
        return (1);
}

int error_open_ft(int fd)
{
    if (fd < 0)
        return (0);
    else
        return (1);
}

int ft_check_n(char *buffer, ssize_t ret)
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

t_list  *ft_node(char *buffer, ssize_t size)
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

t_list  *ft_lastnode(t_list *head)
{
    while (head->next != NULL && head != NULL)
        head = head->next;
    return (head);
}

t_list  *ft_backadd(t_list **head, t_list *node)
{
    t_list  *lastnode;

    if (*head == NULL)
        *head = node;
	else if (*head != NULL && node != NULL)
	{
		lastnode = ft_lastnode(*head);
		lastnode->next = node;
	}
    return (*head);
}


ssize_t	ft_count_size(t_list *head)
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

char    *ft_fillstash(t_list *head)
{
    char        *line;
    ssize_t     size;
    ssize_t     i;
    t_list      *ptr;

    i = 0;
	size = ft_count_size(head);
    line = malloc((size + 1) * sizeof(char));
    size = 0;
    ptr = head;
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


char	*ft_fill_result(char	*line, ssize_t i)
{
	ssize_t	i2;
	char	*result;

	i2 = 0;
//	i = i - 1;
	result = malloc((i + 1)*sizeof(char));
	while (i2 < i)
	{
		result[i2] = line[i2];
		i2++;
	}
	result[i2] = '\0';
	return (result);
}


char	*ft_fill_result2(char	*line, ssize_t i)
{
	ssize_t	i2;
	char	*result;

	i2 = 0;
	result = malloc((i + 1)*sizeof(char));
	while (i2 < i)
	{
		result[i2] = line[i2];
		i2++;
	}
	result[i2] = '\0';
	return (result);
}

void	ft_lstclear(t_list *head/*, char *line*/)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = head;
	temp = ptr;
//	free(line);
	while (ptr != NULL)
	{
		ptr = head->next;
		free(head->content);
		head = head->next;
	}
}

t_list	*ft_fill_nextline(char *line, t_list *head)
{
	ssize_t	i;
	ssize_t i2;
	char	*nextline;

	i = 0;
	i2 = 0;
	while (line[i] != '\0')
		i++;
	while (line[i2] != '\n')
		i2++;
	i2++;
	nextline = malloc((i - i2) * sizeof(char));
	i = 0;
	while(line[i2] != '\0')
	{
		nextline[i] = line[i2];
		i++;
		i2++;
	}
	ft_lstclear(head/*, line*/);
	return(ft_node(nextline, i));
}

char	*full_line(char	*line, t_list *head)
{
	ssize_t	i;
	ssize_t	size;
	char	*result;
//	static char	*nextline;


	i = 0;
	result = NULL;
//	nextline = NULL;
	size = ft_count_size(head);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n' && i < size)
	{
		result = ft_fill_result(line, i);
		ft_fill_nextline(line, head);
	}
	else
	{
		result = ft_fill_result2(line, i);
		ft_lstclear(head/*, line*/);
	}
	free(line);

	return (result);
}

char    *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE + 1];
    char            *line;
    ssize_t         ret;
	static t_list          *head;
    t_list          *node;

    head = NULL;
    node = NULL;
    if (error_open_ft(fd) == 0)
        return (NULL);
    ret = read(fd, buffer, BUFFER_SIZE);
    if (error_read_ft(ret) == 0)
        return (NULL);
	if (head == NULL)
		head = ft_node(buffer, ret);
	if (ft_check_n(buffer, ret) == 0)
		line = ft_fillstash(head);
	else
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (error_read_ft(ret) == 0)
			return (NULL);
		while (ret > 0)
		{
			node = ft_node(buffer, ret);
			ft_backadd(&head, node);
			if (ft_check_n(buffer, ret) == 0)
				break;
			ret = read(fd, buffer, BUFFER_SIZE);
			if (error_read_ft(ret) == 0)
				return (NULL);
		}
	}
    line = ft_fillstash(head);
	head = ft_fill_nextline(line, head);
    return (full_line(line, head));
}



int	main (void)
{
//	static char buffer[BUFFER_SIZE + 1];
	int			fd;
//	t_list		*node;
//	t_list		*node1;
//	t_list		*node2;
//	t_list		*ptr;
//	ssize_t		ret;
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
/*	//1er node
	ret = read(fd, buffer, BUFFER_SIZE);
	node = ft_node(buffer, ret);
	if (ft_check_n(buffer, ret) == 0)
		return (1);


	ret = read(fd, buffer, BUFFER_SIZE);
	if (ft_check_n(buffer, ret) == 0)
		return (1);
	while (ret > 0)
	{
		node1 = ft_node(buffer, ret);
		ft_backadd(&node, node1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ft_check_n(buffer, ret) == 0)
			break;
	}

	line = ft_fillstash(node);
	printf("%s\n", line);*/

/*	//2ieme node
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ft_check_n(buffer, ret) == 0)
		return (1);
	node1 = ft_node(buffer, ret);
	printf("%s\n", node1->content);

	//backadd node et node1
	ft_backadd(&node, node1);

	//3ieme node
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ft_check_n(buffer, ret) == 0)
		return (1);

	node2 = ft_node(buffer, ret);
	printf("%s\n", node2->content);

	//backadd node et node2
	ft_backadd(&node, node2);9*/

	//test backadd
/*	ptr = node;
	while (ptr != NULL)
	{
		printf("%s", ptr->content);
		ptr = ptr->next;
	}*/
/*	ptr = node;
	printf("%s", ptr->content);
	ptr = ptr-> next;
	while (ptr != NULL)
	{
		printf("%s", ptr->content);
		ptr = ptr->next;
	}*/
	return (0);
}

