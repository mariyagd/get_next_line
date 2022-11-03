/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:25 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/03 15:00:17 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include "../Libft-42/libft/libft.h"

//char *get_next_line(int fd)

int	main(void)
{
	int		fd;

	fd = open("text", O_RDONLY);
	ft_putnbr_fd(fd,1);
	return (0);

}
