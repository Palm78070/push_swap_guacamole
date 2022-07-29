#include "libft.h"

static int	is_instr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		++s;
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (is_instr(c, " \t\r\n\v\f"));
}
