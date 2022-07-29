#include "libft.h"

void	free_double(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s[i]);
	free(s);
}
