/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:26 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/10 21:21:34 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef	struct s_list
{
	char				*content;
	ssize_t				size;
	struct s_list		*next;
}						t_list;

int ft_check_n(char *buffer, ssize_t ret);
t_list  *ft_node(char *buffer, ssize_t size);
t_list  *ft_lastnode(t_list *head);
t_list  *ft_backadd(t_list **head, t_list *node);
ssize_t ft_count_size(t_list *head);
void    ft_lstclear(t_list **head);
char    *fill_result(char *line, ssize_t size_result);
char    *separate_stash(char *line, t_list *head);
char    *create_stash(t_list *head);
char  *fill_nextline(t_list *head, char *line);
ssize_t ft_size_nextline(char *line);
char    *create_current_line(t_list *head);
t_list  *create_new_head(t_list *head);
ssize_t count_currentline_size(t_list * head);
ssize_t count_nextline_size(t_list  **head);
ssize_t count_nextline(t_list *head);
char  *create_newhead(t_list *head);
#endif

