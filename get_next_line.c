/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:47:19 by mdanchev          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/11/08 14:40:59 by mdanchev         ###   lausanne.ch       */
=======
/*   Updated: 2022/11/07 16:20:49 by mdanchev         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< Updated upstream
#include <stdio.h>
#include "gnl.h"
#define BUFFER_SIZE 10

int error_read_ft(ssize_t ret)
{
    if (ret < 0)
        return (0);
    else
        return (1);
}
=======
#include "get.h"
#define BUFFER_SIZE 1

char	*ft_line(tt_list *head);
tt_list	*ft_lestnew(char *buffer, ssize_t ret);
tt_list	ft_lstadd_back(tt_list **lst, tt_list *new);

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	size_t			i;
	ssize_t			ret;
	t_list			*head;
	t_list			*node;
>>>>>>> Stashed changes

int error_open_ft(int fd)
{
    if (fd < 0)
        return (0);
    else
        return (1);
}

<<<<<<< Updated upstream
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
=======
	i = 0;
	if (fd < 0)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	if (ret > 0)
		head = ft_fillstash(buffer, ret);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	while (ret > 0)
	{
		node = ft_fillstash(buffer, ret);
		i = 0;
		while (i < ret && buffer[i] != \n)
		{
			i++;
		}
		if (buffer[i] != '\n')
		{
			head = ft_lstadd_back(&head, node);
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret < 0)
				return (0);
		}
	}
	return (head);
>>>>>>> Stashed changes
}

t_list  *ft_node(char *buffer, ssize_t size)
{
    t_list  *node;
    char    *stash;
    ssize_t i;

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

char    *ft_fillstash(t_list *head)
{
    char        *line;
    ssize_t     size;
    ssize_t     i;
    t_list      *ptr;

    size = 0;
    i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        size = size + ptr->size;
        ptr = ptr->next;
    }
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

char    *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE + 1];
    char            *line;
    ssize_t         ret;
    t_list          *head;
    t_list          *node;

    head = NULL;
    node = NULL;
    if (error_open_ft(fd) == 0)
        return (NULL);
    ret = read(fd, buffer, BUFFER_SIZE);
    if (error_read_ft(ret) == 0)
        return (NULL);
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
    return (line);
}

char	*ft_line(tt_list *head)
{
	t_list	*ptr;
	ssize_t size;
	char *line;
	ssize_t i;

	size = 0;
	i = 0;

	while(head->next != NULL || head != NULL)
	{
		ptr = head->size;
		size = size + *ptr;
		head = head->next
	}
	line = malloc((size + 1) * sizeof(char));
	while(head->next != NULL || head != NULL)
	{
		while(i < head->size)
		{
			line[i] = head->stash[i];
			i++;
		}
		head = head->next;
	}
	line[i] = '\0';
	return(line);
}






int	main(void)
{
	int		fd;
	int		i;
<<<<<<< Updated upstream
	char	*result;

	i = 0;
	fd = open("text", O_RDONLY);
	printf("FILE DESCRIPTOR: %d\n", fd);
	result = get_next_line(fd);
	printf("%s\n", result);
=======
	tt_list	*result;

	i = 0;
	fd = open("text", O_RDONLY);
	printf("File Descriptor: %d\n", fd);
	if (fd == -1)
		return (-1);
	get_next_line(fd);
	if (close(fd) == -1)
		return (-1);

>>>>>>> Stashed changes
	return (0);

}
