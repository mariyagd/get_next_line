/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:35 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:12 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

 t_list  *ft_node(char *buffer, ssize_t size)
 {
      t_list  *node;
      char    *stash;
      ssize_t i;
 
      i = 0;
      stash = malloc((size + 1) * sizeof(char));
      while (i < size)
      {
          stash[i] = buffer[i];
          i++;
      }
	  node = malloc(sizeof(t_list));
	  if (!node)
		  return (NULL);
	  node->content = stash;
	  node->next = NULL;
	  return (node);
 }

t_list  *ft_lastnode(t_list *head)
{
    while (head->next != NULL && head != NULL)
        head = head->next;
    return (head);
}

t_list  *ft_backadd(t_list **head, t_list *node)
{
    t_list  *lastnode;

    if (*head == NULL)
        *head = node;
    else if (*head != NULL && node != NULL)
    {
        lastnode = ft_lastnode(*head);
        lastnode->next = node;
    }
    return (*head);
}

