#include "push_swap.h"

void	stack_a_operation(t_swap *stack, int index)
{
	int	above;
	int	below;

	above = cal_above(stack, index, 'a');
	below = cal_below(stack, index, 'a');
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		if (stack->a[stack->above_i] < stack->a[stack->below_i])
			use_above(stack, index, 'a');
		else
			use_below(stack, index, 'a');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'a');
	else
		use_above(stack, index, 'a');
	pb(stack);
	check_stack_b(stack);
}

void	stack_b_operation(t_swap *stack, int index, int largest)
{
	int	above;
	int	below;
	
	above = cal_above_b(stack, largest);
	below = cal_below_b(stack, largest);
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		if (stack->b[stack->above_i] > stack->b[stack->below_i])
			use_above(stack, index, 'b');
		else
			use_below(stack, index, 'b');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'b');
	else
		use_above(stack, index, 'b');
	pa(stack);
}

void	send_to_b(t_swap *stack, int chunk)
{
	static int	i = 0;
	static int	start = 0;
	int	top;

	stack->len_ch = stack->len_s / chunk;
	stack->chunk = chunk;
	if (stack->len_a == stack->len_s % chunk)
		top = i + (stack->len_a - 1);
	else
		top = (i + stack->len_ch) - 1;
	if (stack->len_a == 0)
		return ;
	while (i <= top)
	{
		stack_a_operation(stack, start);
		++i;
	}
	start += stack->len_ch;
	send_to_b(stack, chunk);
}

void	send_to_a(t_swap *stack, int chunk)
{
	static int	i = 0;
	int	floor;

	if (i == 0)
		i = stack->len_s - 1;
	floor = (i - stack->len_ch) + 1;
	if (stack->len_b == 0)
		return ;
	while (i >= floor)
	{
		stack_b_operation(stack, floor, stack->s[i]);
		--i;
	}
	send_to_a(stack, chunk);
}
