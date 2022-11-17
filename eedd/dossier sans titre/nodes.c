#include "gnl.h"

t_list  *ft_node(char *buffer, ssize_t size)
{
    t_list  *node;
	char	*stash;
	ssize_t	i;

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
    node->size = size;
    node->content = stash;
    node->next = NULL;
    return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list  *ft_backadd(t_list **head, t_list *node)
{
    t_list  *lastnode;

    if (*head == NULL)
        *head = node;
	else if (*head != NULL && node != NULL)
	{

        lastnode = ft_lstlast(*head);
        lastnode->next = node;
	}
    return (*head);
}

void	ft_lstclear(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
        free (current);
		current = next;
	}
    *head = NULL;
}