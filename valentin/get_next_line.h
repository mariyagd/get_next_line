/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfinocie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:25:13 by vfinocie          #+#    #+#             */
/*   Updated: 2022/11/19 15:52:44 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


char	*get_next_line(int fd);
char	*ft_prepline(char *buffer);
char	*ft_joinandfree(char *buffer, char *tmpbuff);
char	*ft_readfile(char *buffer, int fd);
char	*ft_delreadline(char *buffer);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *buffer, char *tmpbuff);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
void	ft_bzero(void *str, size_t size);

#endif
