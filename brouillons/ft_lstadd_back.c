/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:05:06 by mdanchev          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/10/24 16:33:52 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;
=======
/*   Updated: 2022/11/07 16:19:33 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get.h"

tt_list	*ft_lstlast(tt_list *lst);

tt_list		*ft_lstadd_back(tt_list **lst, tt_list *new)
{
	tt_list	*lstlast;
>>>>>>> Stashed changes

	if (*lst == NULL)
		*lst = new;
	else if (!lst || !new)
		return ;
	else
	{
		lstlast = ft_lstlast(*lst);
		lstlast->next = new;
	}
<<<<<<< Updated upstream
=======
	return(*lst);
>>>>>>> Stashed changes
}
