#include "get_next_line.h"

int check_if_n(char *buffer, ssize_t ret)
{
    ssize_t i;
    i = 0;
    while (i < ret && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (0);
    else
        return (1);
}

t_list  *create_node(char *buffer, ssize_t size)
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
    node->size = size;
    node->content = stash;
    node->next = NULL;
    return (node);
}

t_list  *find_lastnode(t_list *head)
{
    while (head->next != NULL && head != NULL)
        head = head->next;
    return (head);
}

t_list  *create_linkedlist(t_list **head, t_list *node)
{
    t_list  *lastnode;

    if (*head == NULL)
        *head = node;
    else if (*head != NULL && node != NULL)
    {
        lastnode = find_lastnode(*head);
        lastnode->next = node;
    }
    return (*head);
}

void    delete_list(t_list **head)
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
