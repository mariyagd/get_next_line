/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:47:19 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/04 10:21:15 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "../Libft-42/libft/libft.h"

//char *get_next_line(int fd)
#define BUF_SIZE 10

int	main(void)
{
	int		fd;
	int		ret;
//	int		fd1;
//	int		ret1;
	char	buf[BUF_SIZE + 1];
//	char	buf1[BUF_SIZE + 1];

	fd = open("text", O_RDONLY);
	ft_putnbr_fd(fd, 1);
	printf("\n");
	if (fd == -1)
		ft_putstr_fd("open() failed\n", 1);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr_fd(buf, 1);
	ft_putnbr_fd(ret, 1);
	if (close(fd) == -1)
		ft_putstr_fd("close() failed\n", 1);

/*	fd1 = open("text0", O_RDONLY);
	if (fd1 == -1)
	{
		ft_putstr_fd("open() failed\n", 1);
		return(1);
	}ret = read(fd, buf, BUF_SIZE);
	while ((ret1 = read(fd1, buf1, BUF_SIZE)))
	{

		buf[ret1] = '\0';
		ft_putstr_fd(buf1, 1);
//		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(ret1, 1);
//		ft_putchar_fd('\n', 1);
	}
	printf("\n");
	ft_putnbr_fd(ret1, 1);
	if (close(fd1) == -1)
		ft_putstr_fd("close() failed\n", 1);*/
	return (0);

}
