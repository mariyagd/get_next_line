/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:36:05 by mdanchev          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/10/24 16:33:05 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
=======
/*   Updated: 2022/11/07 16:19:17 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get.h"

tt_list	*ft_lstlast(tt_list *lst)
>>>>>>> Stashed changes
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
