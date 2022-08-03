/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:35:51 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/04 00:26:34 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*choose_stack(t_swap *stack, int *top, char c)
{
	if (c == 'a')
	{
		if (top != NULL)
			*top = stack->len_a - 1;
		return (stack->a);
	}
	if (c == 'b')
	{
		if (top != NULL)
			*top = stack->len_b - 1;
		return (stack->b);
	}
	return (NULL);
}

int	cal_above(t_swap *stack, int index, char c)
{
	int	top;
	int	count_step;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	stack->mid_stack = (top + 1) / 2;
	if (!stack2)
		return (-1);
	count_step = 0;
	while (top >= stack->mid_stack && !is_insort(stack2[top], index, stack))
	{
		--top;
		++count_step;
	}
	if (top < stack->mid_stack)
		return (-1);
	stack->above_i = top;
	return (count_step);
}

int	cal_below(t_swap *stack, int index, char c)
{
	int	top;
	int	count_step;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	stack->mid_stack = (top + 1) / 2;
	if (!stack2)
		return (-1);
	count_step = 0;
	top = 0;
	while (top < stack->mid_stack && !is_insort(stack2[top], index, stack))
	{
		++top;
		++count_step;
	}
	if (top >= stack->mid_stack)
		return (-1);
	stack->below_i = top;
	return (count_step + 1);
}

void	use_above(t_swap *stack, int index, char c)
{
	int	*stack2;
	int	top;
	int	i;

	stack2 = choose_stack(stack, &top, c);
	i = stack->above_i;
	if (i == top)
	{
		if (i == 0)
			top = 1;
		if (is_insort(stack2[top - 1], index, stack) && c == 'a')
		{
			if (stack2[top - 1] < stack2[top])
				swap(stack, c);
		}
		return ;
	}
	--i;
	while (++i < top - 1)
		rotate(stack, c);
	rotate(stack, c);
}

void	use_below(t_swap *stack, int index, char c)
{
	int	*stack2;
	int	top;
	int	i;

	(void)index;
	stack2 = choose_stack(stack, &top, c);
	i = stack->below_i;
	while (i > 0)
	{
		rev_rotate(stack, c);
		if (c == 'b' && stack->b[top] < stack->b[top - 1])
			swap(stack, 'b');
		--i;
	}
	rev_rotate(stack, c);
}
