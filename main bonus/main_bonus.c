/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:10:25 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/19 17:00:52 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;
	char	*line;

	fd1 = open("text9", O_RDONLY);
	fd2 = open("text10", O_RDONLY);
	fd3 = open("text11", O_RDONLY);
	fd4 = open("text12", O_RDONLY);
	fd5 = open("text13", O_RDONLY);

	line = get_next_line(fd1);

	while (line)
	{

		printf("RESULT fd1: %s\n", line);
		free(line);

		line = get_next_line(fd2);
		printf("RESULT fd2: %s\n", line);
		free(line);

		line = get_next_line(fd3);
		printf("RESULT fd3: %s\n", line);
		free(line);

		line = get_next_line(fd4);
		printf("RESULT fd4: %s\n", line);
		free(line);

		line = get_next_line(fd5);
		printf("RESULT fd5: %s\n", line);
		free(line);

		printf("\n-----------------------------\n");

		line = get_next_line(fd1);
	}
	return (0);
}


