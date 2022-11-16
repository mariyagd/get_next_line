/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/11 15:45:38 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
//#define BUFFER_SIZE 55

int ft_check_n(char *buffer, ssize_t ret)
{
    ssize_t i;
    i = 0;
    while (i < ret && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (0);
    else
        return (i);
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

char    *get_next_line(int fd)
{
    char     		buffer[BUFFER_SIZE + 1];
	static char		*nextline;
	ssize_t			nextline_size;
    ssize_t         ret;
	t_list          *head;
    t_list          *node;

	nextline = NULL;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (nextline != NULL)
		head = ft_node(nextline, nextline_size);
	else
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
		if (ret < 0)
			return (NULL);
	}
	return(create_result(head));
}



int	main (void)
{

	int			fd;

	char	*line;

	fd = open("text", O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	/*line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);*/
	return (0);
}
