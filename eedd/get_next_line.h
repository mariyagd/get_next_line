<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:26 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/14 11:31:08 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

=======
>>>>>>> 82e3bc735068c7b93be042ea546099326154dd33
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

<<<<<<< HEAD
typedef	struct s_list
{
	char				*content;
	ssize_t				size;
	struct s_list		*next;
}						t_list;

char    *get_next_line(int fd);
int		check_if_n(char *buffer, ssize_t ret);
t_list  *create_node(char *buffer, ssize_t size);
t_list  *find_lastnode(t_list *head);
t_list  *create_linkedlist(t_list **head, t_list *node);
void    delete_list(t_list **head);

ssize_t count_stashsize(t_list *head);
char    *create_and_fillstash(t_list **head);
char    *create_and_fillresult(char *line);
ssize_t count_nextlinesize(char *line);
char    *create_and_fillnextline(char *line);


#endif
=======
char	*ft_calloc(int count);
int		ft_strlen(char *string);
char	*ft_join(char *nextline, char *buffer);
int		ft_check_n(char	*fullline);
char	*read_fd(char *nextline, int fd);
char	*create_result(char *fullline);
char	*create_nextline(char *result, char *fullline);
char *get_next_line(int fd);
>>>>>>> 82e3bc735068c7b93be042ea546099326154dd33
