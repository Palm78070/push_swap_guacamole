#include "push_swap.h"

static int	is_largest(t_swap *stack, int num, int len)
{
	int	i;
	int	largest;

	i = -1;
	largest = stack->a[0];
	while(++i < len)
	{
		if (stack->a[i] > largest)
			largest = stack->a[i];
	}
	if (num == largest)
		return (1);
	return (0);
}

void	sort3(t_swap *stack)
{
	if (is_largest(stack, stack->a[2], 3))
	{
		rotate(stack, 'a');
		if (stack->a[2] > stack->a[1])
			swap(stack, 'a');
	}
	else if (is_largest(stack, stack->a[1], 3))
	{
		if (stack->a[2] > stack->a[0])
			rev_rotate(stack, 'a');
		else
		{
			rev_rotate(stack, 'a');
			swap(stack, 'a');
		}
	}
	else if (is_largest(stack, stack->a[0], 3))
	{
		if (stack->a[2] > stack->a[1])
			swap(stack, 'a');
	}
}

void	push_to_b(t_swap *stack, int num)
{
	int	index;

	index = stack->len_a - 1;
	while (index >= 0 && stack->a[index] != num)
		--index;
	if (index > 1)
	{
		while (stack->a[stack->len_a - 1] != num)
			rotate(stack, 'a');
	}
	else if (index == 1 || index == 0)
	{
		while (stack->a[stack->len_a - 1] != num)
			rev_rotate(stack, 'a');
	}
	pb(stack);
}

void	sort5(t_swap *stack)
{
	stack->s = intdup(stack->a, stack->len_a, 0);
	merge_sort(stack->s, stack->len_s);
	push_to_b(stack, stack->s[0]);
	push_to_b(stack, stack->s[1]);
	sort3(stack);
	while (stack->len_b != 0)
		pa(stack);
}
