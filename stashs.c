#include "gnl.h"

char    *create_malloc(ssize_t size)
{
    char    *result;

    result = malloc(size * sizeof(char));
    if (!result)
        return (NULL);
    return (result);
}

ssize_t     count_size(t_list *head)
{
    t_list  *ptr;
    ssize_t i;
    ssize_t size;

    i = 0;
    size = 0;
    ptr = head;
    while (ptr != NULL)
    {
        while (ptr->content[i] != '\n' && i < ptr->size)
           {
            size++;
            i++;
           } 
        if (ptr->content[i] == '\n')
            break;
        i = 0;
        ptr = ptr->next;
    }
    size = size + 1;
    return (size);
}

char    *create_result(t_list *head)
{
    t_list  *ptr;
    ssize_t i;
    ssize_t j = 0;
    ssize_t size;
    char    *result;

    i = 0;
    ptr = head;
    size = count_size(head);
    result = create_malloc(size);
    size = 0;
    while (ptr != NULL)
    {
        while (i < size)
        {
            result[i] = ptr->content[j];
            i++;
            j++;
        }
        if (ptr->content[j] == '\n')
            break;
        j = 0;
        ptr = ptr->next;
    }
    result[size] = '\0';
    return (result);
}