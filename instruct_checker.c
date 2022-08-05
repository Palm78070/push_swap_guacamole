/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:32:46 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/05 17:11:51 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap2(t_swap *stack, char c)
{
	int	tmp;
	int	before_top;
	int	top;
	int	*stack2;

	if (c == '2')
	{
		swap2(stack, 'a');
		swap2(stack, 'b');
		return ;
	}
	stack2 = choose_stack(stack, &top, c);
	if (top <= 0)
		return ;
	before_top = top - 1;
	tmp = stack2[top];
	stack2[top] = stack2[before_top];
	stack2[before_top] = tmp;
	stack->instruct += 1;
}

void	rotate2(t_swap *stack, char c)
{
	int	tmp;
	int	top;
	int	*stack2;

	if (c == '2')
	{
		rotate2(stack, 'a');
		rotate2(stack, 'b');
		return ;
	}
	stack2 = choose_stack(stack, &top, c);
	if (top <= 0)
		return ;
	tmp = stack2[top];
	while (top > 0)
	{
		stack2[top] = stack2[top - 1];
		--top;
	}
	stack2[0] = tmp;
	stack->instruct += 1;
}

void	rev_rotate2(t_swap *stack, char c)
{
	int	tmp;
	int	top;
	int	i;
	int	*stack2;

	if (c == '2')
	{
		rev_rotate2(stack, 'a');
		rev_rotate2(stack, 'b');
		return ;
	}
	i = -1;
	stack2 = choose_stack(stack, &top, c);
	if (top <= 0)
		return ;
	tmp = stack2[0];
	while (++i < top)
		stack2[i] = stack2[i + 1];
	stack2[top] = tmp;
	stack->instruct += 1;
}

void	pa2(t_swap *stack)
{
	int	*stack_p;
	int	*stack_r;
	int	top_p;
	int	top_r;

	(stack->len_b) -= 1;
	(stack->len_a) += 1;
	top_p = stack->len_b;
	top_r = stack->len_a - 1;
	stack_p = stack->b;
	stack_r = stack->a;
	stack_r[top_r] = stack_p[top_p];
	stack->instruct += 1;
}

void	pb2(t_swap *stack)
{
	int	*stack_p;
	int	*stack_r;
	int	top_p;
	int	top_r;

	(stack->len_a) -= 1;
	(stack->len_b) += 1;
	top_p = stack->len_a;
	top_r = stack->len_b - 1;
	stack_p = stack->a;
	stack_r = stack->b;
	stack_r[top_r] = stack_p[top_p];
	stack->instruct += 1;
}
