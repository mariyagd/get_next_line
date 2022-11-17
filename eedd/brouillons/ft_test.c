/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:16:26 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "../Libft-42/libft/libft.h"

char*	ft_fillstash(char *stash, char *buffer, size_t count)
{
	char *line;
	size_t size;
	int		i;

	i = 0;
	stash = malloc(1 * sizeof(char));
	stash = &buffer;
	line = malloc((count + 1) * sizeof(char));
	line[i] = stash[i];


}

int main(void)
{
	char			*str = "kitty";
	static	char	*result = "hello";
	printf("%s\n", ft_test(result, str, 5));
	return (0);
}



