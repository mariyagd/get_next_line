/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stashs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:28 by mdanchev          #+#    #+#             */
/*   Updated: 2022/11/10 21:43:50 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

ssize_t ft_count_size(t_list *head)
{
    ssize_t     size;
    t_list      *ptr;

    size = 0;
    ptr = head;
    while (ptr != NULL)
    {
        size = size + ptr->size;
        ptr = ptr->next;
    }
    return(size);
}



char	*fill_nextline(t_list *head, char *line)
{
	ssize_t	i;
	ssize_t	start;
	char	*nextline;
	char	*new_head;
	
	new_head = NULL;
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	start = i;
	if (line[i] != '\0')
	{
		while (line[i] != '\0')
			i++;
		nextline = malloc ((i + 1) * sizeof(char));
		if(!nextline)
			return (NULL);
		i = 0;
		while (line[start] != '\0')
		{
			nextline[i] = line[start];
			i++;
			start++;
		}
	}
	return (new_head);
}

ssize_t	ft_size_nextline(char *line)
{
	ssize_t i;
	ssize_t	start;
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	start = i;
	while (line[i] != '\0')
		i++;
	return(i - start);
}

ssize_t count_currentline_size(t_list * head)
{
	ssize_t i;
	ssize_t	size;
	t_list	*ptr;

	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		while(i < ptr->size && ptr->content[i] != '\n')
		{
			i++;
			size++;
		}
		i = 0;
		ptr = ptr->next;
	}
	return (size + 1);
}
char	*create_current_line(t_list *head)
{
	ssize_t	i;
	t_list	*ptr;
	ssize_t	size;
	char	*result;

	i = 0;
	ptr = head;
	size = count_currentline_size(head);
    result = malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	size = 0;
    while (ptr != NULL)
    {
		while (i < ptr->size && ptr->content[i] != '\n' )
		{
			result[size] = ptr->content[i];
			size++;
			i++;
		}
		i = 0;
		ptr = ptr->next;
	}
	result[size++] = '\n';
    result[size++] = '\0';
    return (result);
}

void    ft_lstclear(t_list **head)
{
    t_list  *current;
    t_list  *next;

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

ssize_t	count_nextline(t_list *head)
{
	ssize_t	i;
	t_list *ptr;
	ssize_t count;

	i = 0;
	count = 0;
	ptr = head;
	while (i < ptr->size && ptr->content[i] != '\n')
	{
		i++;
		if (i == ptr->size)
			ptr = ptr->next;
		if (ptr->content[i] == '\n')
			break;
	}
	while (ptr != NULL)
	{
		i++;
		while(i < ptr->size)
		{
			i++;
			count++;
		}
		ptr = ptr->next;
	}
	return (count);
}

char	*create_newhead(t_list *head)
{
	ssize_t i;
	ssize_t size;
	ssize_t	j;
	char	*nextline;
	t_list	*ptr;

	i = 0;
	j = 0;
	ptr = head;
	size = count_nextline(head);
	if (size == 0)
	{
		return (NULL);
	}
	while (i < ptr->size && ptr->content[i] != '\n')
	{
		i++;
		if (i == ptr->size)
			ptr = ptr->next;
		if (ptr->content[i] == '\n')
			break;
	}
	while (ptr != NULL)
	{
	//	i++;
		while(j <= size && i < ptr->size)
		{
			nextline[j] = ptr->content[i]; 
			i++;
			j++;
		}
		ptr = ptr->next;
	}
	return (nextline);
}



