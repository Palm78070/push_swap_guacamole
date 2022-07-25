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

static int	is_least(t_swap *stack, int num, int len)
{
	int	i;
	int	least;

	i = -1;
	least = stack->a[0];
	while(++i < len)
	{
		if (stack->a[i] < least)
			least = stack->a[i];
	}
	if (num == least)
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

static void	b_to_a(t_swap *stack)
{
	int	top_a;
	int	top_b;
	int	largest;

	top_a = stack->len_a - 1;
	top_b = stack->len_b - 1;
	largest = stack->a[0];
	if (stack->b[top_b] > stack->a[top_a])
	{
		if (stack->b[top_b] > stack->a[0])
		{
			pa(stack);
			rotate(stack, 'a');
		}
		else if (stack->b[top_b] < stack->a[top_a - 1])
		{
			pa(stack);
			swap(stack, 'a');
		}
		else
		{
			while (stack->b[top_b] > stack->a[stack->len_a - 2])
				rotate(stack, 'a');
			pa(stack);
			swap(stack, 'a');
			while (stack->a[0] != largest)
				rev_rotate(stack, 'a');
		}			
	}
	else
		pa(stack);
}

void	sort5(t_swap *stack)
{
	if (is_least(stack, stack->a[0], 5))
		rev_rotate(stack, 'a');
	else if (is_largest(stack, stack->a[4], 5))
		rotate(stack, 'a');
	pb(stack);
	pb(stack);
	check_stack_b(stack);
	sort3(stack);
	while (stack->len_b != 0)
		b_to_a(stack);
}
