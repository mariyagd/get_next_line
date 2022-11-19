/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:10:25 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/19 17:00:29 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	printf("\n--------------TEST1 - NORMAL TEXT ----------------\n");
	fd = open("text1", O_RDONLY);
	printf("TEST: %zu\n", read(fd, 0, 0));
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT1: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		printf("close() failed\n");

	printf("\n--------------TEST2 - ONLY NEW LINES----------------\n");
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

	printf("\n--------------TEST3 - ONE GIANT LINE----------------\n");
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

	printf("\n--------------TEST4 - EMPTY FILE----------------\n");
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

	printf("\n--------------TEST5 - EMPTY FILE THAT WAS NOT YET OPENED----------------\n");
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

	printf("\n--------------TEST6 - ONLY ONE CHARACTER----------------\n");
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

	printf("\n--------------TEST7 - OPEN FROM PAGES----------------\n");
	fd = open("text6.pages", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 7: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		printf("close() failed\n");

	printf("\n--------------TEST8 - OPEN FROM .TXT----------------\n");
	fd = open("text7.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("RESULT 8: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
        printf("close() failed\n");
	return (0);
}


