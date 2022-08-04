/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:30:35 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/04 01:30:52 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_swap *stack)
{
	if (is_largest_num(stack->a, stack->a[2], 3))
	{
		rotate(stack, 'a');
		if (stack->a[2] > stack->a[1])
			swap(stack, 'a');
	}
	else if (is_largest_num(stack->a, stack->a[1], 3))
	{
		if (stack->a[2] > stack->a[0])
			rev_rotate(stack, 'a');
		else
		{
			rev_rotate(stack, 'a');
			swap(stack, 'a');
		}
	}
	else if (is_largest_num(stack->a, stack->a[0], 3))
	{
		if (stack->a[2] > stack->a[1])
			swap(stack, 'a');
	}
}

static void	push_to_b(t_swap *stack, int num)
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

static void	sort5(t_swap *stack)
{
	int	i;

	i = -1;
	stack->s = intdup(stack->a, stack->len_a, 0);
	merge_sort(stack->s, stack->len_s);
	while (stack->len_a != 3)
		push_to_b(stack, stack->s[++i]);
	sort3(stack);
	while (stack->len_b != 0)
		pa(stack);
}

void	sort_small(t_swap *stack)
{
	int	len_a;

	len_a = stack->len_a;
	reverse_arr(stack);
	if (len_a == 1 || stack_is_sort(stack->a, stack->len_a))
		return ;
	else if (len_a == 2 && stack->a[1] > stack->a[0])
		swap(stack, 'a');
	else if (len_a == 3)
		sort3(stack);
	else if (len_a >= 4)
		sort5(stack);
}
