/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:26 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/08 15:20:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef	struct s_list
{
	char				*content;
	ssize_t				size;
	struct s_list		*next;
}						t_list;

char    *create_malloc(ssize_t size);
char    *create_result(t_list *head);
t_list  *ft_node(char *buffer, ssize_t size);
t_list  *ft_backadd(t_list **head, t_list *node);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **head);

#endif
