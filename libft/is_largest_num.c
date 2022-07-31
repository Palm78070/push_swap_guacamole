#include "libft.h"

int	is_largest_num(int *stack, int num, int len)
{
	int	i;
	int	largest;

	i = -1;
	largest = stack[0];
	while(++i < len)
	{
		if (stack[i] > largest)
			largest = stack[i];
	}
	if (num == largest)
		return (1);
	return (0);
}
