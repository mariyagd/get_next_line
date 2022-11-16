/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:07 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/16 17:14:02 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list  *create_node(char *buffer, ssize_t size)
{
    t_list  *node;
	char	*stash;
	ssize_t	i;

	i = 0;
	stash = malloc((size + 1) * sizeof(char));
	while (buffer[i] != '\0')
	{
		stash[i] = buffer[i];
		i++;
	}
	stash[i] = '\0';
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = stash;
    node->next = NULL;
    return (node);
}

t_list  *create_linkedlist(t_list **head, t_list *node)
{
    t_list  *lastnode;
	t_list	*ptr;

	ptr = *head;
    if (*head == NULL)
        *head = node;
	else if (*head != NULL && node != NULL)
	{

		while (ptr->next != NULL && ptr != NULL)
			ptr = ptr->next;
		lastnode = ptr;
		lastnode->next = node;
	}
    return (*head);
}

void	delete_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}

int	check_if_n(char *buffer, int ret)
{
	int	i;

	i = 0;
	while(buffer[i] != '\0' && i < ret)
	{
		if (buffer[i] == '\n')
			break;
		i++;
	}
	if (buffer[i] == '\n')
		return (0);
	else
		return (1);
}
