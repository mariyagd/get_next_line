/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/10 19:43:26 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "gnl.h"

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


char    *get_next_line(int fd)
{
    static char 	    buffer[BUFFER_SIZE + 1];
    char            	*line;
	char				*result;
    char				*nextline;
	ssize_t         	ret;
	static t_list       *head;
    t_list          	*node;
	ssize_t				size_nextline;

	head = NULL;
    ret = read(fd, buffer, BUFFER_SIZE);
	if (head == NULL)
		head = ft_node(buffer, ret);
	if (ft_check_n(buffer, ret) != 0)	
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		while (ret > 0)
		{
			node = ft_node(buffer, ret);
			ft_backadd(&head, node);
			if (ft_check_n(buffer, ret) == 0)
				break;
			ret = read(fd, buffer, BUFFER_SIZE);
		}
	}
	line = create_current_line(head);
	/*t_list	*ptr;
	ptr = head;
	while (ptr != NULL)
	{
		printf("%zd\n", ptr->size);
		ptr = ptr->next;
	}*/
	return (line);
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
	printf("RESULT = %s\n", line);
	free(line);

/*	line = get_next_line(fd);
	printf("RESULT = %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("RESULT = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("RESULT = %s\n", line);
	free(line);*/
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

