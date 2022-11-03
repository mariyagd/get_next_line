/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:47:19 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 16:20:53 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "../Libft-42/libft/libft.h"

//char *get_next_line(int fd)

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;

	fd = open("text", O_RDONLY);
	ft_putnbr_fd(fd,1);
	if (fd == -1)
		ft_putstr_fd("open() failed\n", 1);
	/*if (close(fd) == -1)
		ft_putstr_fd("close() failed\n", 1);*/

	printf("\n");
	fd1 = open("text1", O_WRONLY | O_CREAT);
	if (fd1 == -1)
		ft_putstr_fd("open() failed\n", 1);
/*	if (close(fd1) == -1)
		ft_putstr_fd("close() failed\n", 1);*/
	ft_putnbr_fd(fd1, 1);

	//creer un nouveau fichier text2 et avoir les droits d'ecriture
	//et de lecture
	printf("\n");
	fd2 = open("text2", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd2 == -1)
		ft_putstr_fd("open() failed\n", 1);
/*	if (close(fd2) == -1)
		ft_putstr_fd("close() failed\n", 1);*/
	ft_putnbr_fd(fd2, 1);
	return (0);

}
