#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_calloc(int count);
int		ft_strlen(char *string);
char	*ft_join(char *nextline, char *buffer);
int		ft_check_n(char	*fullline);
char	*read_fd(char *nextline, int fd);
char	*create_result(char *fullline);
char	*create_nextline(char *result, char *fullline);
char *get_next_line(int fd);
