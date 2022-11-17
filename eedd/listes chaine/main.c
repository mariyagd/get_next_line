/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/16 17:07:12 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main (void)
{
	int			fd;
	char	*line;

	fd = open("text", O_RDONLY);
	line = get_next_line(fd);
	printf("RESULT 1 = %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("RESULT 2 = %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("RESULT 3 = %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("RESULT 4 = %s\n", line);
	free(line);
	return (0);
}