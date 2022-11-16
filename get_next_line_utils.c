
#include "get_next_line.h"

char	*ft_calloc(int count)
{
	char	*string;
	int		i;

	i = 0;
	string = malloc((count + 1) * sizeof(char));
	while (i <= count)
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
