/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:29:03 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/04 01:30:07 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	match_str(char *s, char *str)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != str[i])
			return (0);
	}
	return (1);
}

void	use_instruct(t_swap *stack, char *s)
{
	if (match_str(s, "sa\n"))
		swap2(stack, 'a');
	else if (match_str(s, "sb\n"))
		swap2(stack, 'b');
	else if (match_str(s, "ra\n"))
		rotate2(stack, 'a');
	else if (match_str(s, "rb\n"))
		rotate2(stack, 'b');
	else if (match_str(s, "rra\n"))
		rev_rotate2(stack, 'a');
	else if (match_str(s, "rrb\n"))
		rev_rotate2(stack, 'b');
	else if (match_str(s, "pa\n"))
		pa2(stack);
	else if (match_str(s, "pb\n"))
		pb2(stack);
}
