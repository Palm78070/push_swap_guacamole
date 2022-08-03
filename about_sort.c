/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:34:02 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/03 22:57:39 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_insort(int num, int index, t_swap *stack)
{
	int	i;
	int	last;
	int	chunk;
	int	rem;

	i = index - 1;
	chunk = stack->chunk;
	rem = stack->len_s % chunk;
	if (stack->len_a <= rem && rem != 0)
		last = index + (rem - 1);
	else
		last = index + (stack->len_ch - 1);
	while (++i <= last)
	{
		if (num == stack->s[i])
			return (1);
	}
	return (0);
}

int	stack_is_sort(int *stack, int len)
{
	int	i;
	int	j;

	i = len - 1;
	j = i;
	while (i >= 1)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stack[i] > stack[j])
				return (0);
			--j;
		}
		--i;
	}
	return (1);
}
