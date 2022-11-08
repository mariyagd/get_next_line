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

typedef	struct s_list
{
	char				*content;
	ssize_t				size;
	struct s_list		*next;
}						t_list;

#endif
