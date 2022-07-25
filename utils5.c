/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:45:43 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/25 12:10:21 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_above_b(t_swap *stack, int largest)
{
	int	top;
	int	count_step;

	count_step = 0;
	top = stack->len_b - 1;
	stack->mid_stack = (top + 1) / 2;
	while (top >= stack->mid_stack && stack->b[top] != largest)
	{
		--top;
		++count_step;
	}
	if (top < stack->mid_stack)
		return (-1);
	stack->above_i = top;
	return (count_step);
}

int	cal_below_b(t_swap *stack, int largest)
{
	int	i;
	int	count_step;

	stack->mid_stack = stack->len_b / 2;
	count_step = 0;
	i = 0;
	while (i < stack->mid_stack && stack->b[i] != largest)
	{
		++i;
		++count_step;
	}
	if (i >= stack->mid_stack)
		return (-1);
	stack->below_i = i;
	return (count_step + 1);
}

void	use_above_b(t_swap *stack, int index)
{
	int	*stack2;
	int	top;
	int	i;

	stack2 = choose_stack(stack, &top, 'b');
	i = stack->above_i;
	if (i == top)
		return ;
	while (i < top - 1)
	{
		rotate(stack, 'b');
		++i;
	}
	if (is_insort(stack2[0], index, stack, 'a'))
		swap(stack, 'b');
	else
		rotate(stack, 'b');
}

void	use_below_b(t_swap *stack, int index)
{
	int	*stack2;
	int	top;
	int	i;

	(void)index;
	stack2 = choose_stack(stack, &top, 'b');
	i = stack->below_i;
	while (i > 0)
	{
		rev_rotate(stack, 'b');
		if (stack->b[top] < stack->b[top - 1])
			swap(stack, 'b');
		--i;
	}
	rev_rotate(stack, 'b'); //original
}
