/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:52:01 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/07 16:15:10 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
tt_list 	*ft_lstnew(char	*buffer, ssize_t ret)
{
	tt_list *lstnew;
	
	lstnew = malloc(sizeof(tt_list));
	if (!lstnew)
		return (NULL);
	lstnew->size = ret;
	lstnew->stash = buffer;
	lstnew->next = NULL;
	return (lstnew);
}




/*
#include "get.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BS 10
int main(void)
{
	int	fd;
	ssize_t ret;
	static char buf[10];
//	t_list	*essai;
	fd = open("text", O_RDONLY);
	printf("%d\n", fd);
	ret = read(fd, buf, BS);
	printf("%zd\n", ret);
	printf("%s\n",  ft_fillstash(buf, ret));
	ret = read(fd, buf, BS);
	printf("%s\n",  ft_fillstash(buf, ret));
	return(0);
}
