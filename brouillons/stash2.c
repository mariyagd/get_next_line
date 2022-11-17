ssize_t count_stashsize(t_list *head)
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

char    *create_and_fillstash(t_list **head)
{
    char        *line;
    ssize_t     size;
    ssize_t     i;
    t_list      *ptr;

    i = 0;
    size = count_stashsize(*head);
    line = malloc((size + 1) * sizeof(char));
    size = 0;
    ptr = *head;
    while (ptr != NULL)
    {
        while (i < ptr->size)
        {
            line[size] = ptr->content[i];
            size++;
            i++;
        }
        i = 0;
        ptr = ptr->next;
    }
    line[size] = '\0';

    return (line);
}

char    *create_and_fillresult(char *line)
{
    ssize_t i;
    ssize_t j;
    char    *result;

    i = 0;
    j = 0;
    while (line[i] != '\n')
        i++;
    i++;
    result = malloc((i + 1)*sizeof(char));
    while (j < i)
    {
        result[j] = line[j];
        j++;
    }
    result[j] = '\0';
    return (result);
}

ssize_t count_nextlinesize(char *line)
{
    ssize_t i;
    ssize_t size_nextline;

    i = 0;
    size_nextline = 0;
    while (line[i] != '\n')
        i++;
    i++;
    while (line[i] != '\0')
    {
        i++;
        size_nextline++;
    }
    return (size_nextline);
}


char    *create_and_fillnextline(char *line)
{
    char *nextline;
    ssize_t size_nextline;
    ssize_t i;

    size_nextline = count_nextlinesize(line);
    nextline = malloc(size_nextline * sizeof(char));
    size_nextline = 0;
    i = 0;
    while (line[i] != '\n')
       i++;
    i++;
    while (line[i] != '\0')
    {
        nextline[size_nextline] = line[i];
        i++;
        size_nextline++;
    }
    return (nextline);
}
