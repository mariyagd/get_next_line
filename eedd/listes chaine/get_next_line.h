#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_list
{
	char 			*content;
	struct s_list	*next;
}	t_list;

t_list  *create_node(char *buffer, ssize_t size);
t_list  *create_linkedlist(t_list **head, t_list *node);
void	delete_list(t_list **head);
int	check_if_n(char *buffer, int ret);
char	*create_fullline(t_list **head);
void	ft_bzero(char *buffer, int size);
char	*read_fullline(char *nextline, int fd);
char	*create_result(char *fullline);
char	*create_nextline(char *fullline);
char    *get_next_line(int fd);
