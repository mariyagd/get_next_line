/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:31:41 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/19 17:32:32 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_calloc(int count);
int		ft_strlen(char *string);
char	*ft_join(char *nextline, char *buffer);
int		there_is_n(char	*line);
char	*read_fd(char *nextline, int fd, int *error);
char	*create_result(char *line);
char	*create_nextline(char *result, char *line);
char	*get_next_line(int fd);
int		check_errors(int fd, char **line);
void	prepare_forstash(char **line, char **buffer);

#endif
