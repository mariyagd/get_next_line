/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:10:25 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/19 15:52:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int arg,char *argv[])
{
	int	fd;
	char	*line;

	printf("\n--------------TEXT1 - NORMAL TEXT ----------------\n");
	fd = open("text10", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT1: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
	free(line);
        printf("close() failed\n");

	printf("\n--------------TEXT2 - ONLY NEW LINES----------------\n");
	fd = open("text2", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 2: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
        printf("close() failed\n");

	printf("\n--------------TEXT3 - ONE GIANT LINE----------------\n");
	fd = open("text3", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 3: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
        printf("close() failed\n");

	printf("\n--------------TEXT4 - EMPTY FILE----------------\n");
	fd = open("text4", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 4: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
        printf("close() failed\n");

	printf("\n--------------TEXT5 - EMPTY FILE THAT WAS NOT YET OPENED----------------\n");
	fd = open("text5", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 5: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
        printf("close() failed\n");

	printf("\n--------------TEXT6 - ONLY ONE CHARACTER----------------\n");
	fd = open("text6", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 6: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
        printf("close() failed\n");

	printf("\n--------------TEST7 - READ FROM STD INPUT----------------\n");
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 6: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
        printf("close() failed\n");
	return (0);
}


