/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:30:15 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/04 01:30:26 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_swap *stack)
{
	stack->a = change_to_index(stack);
	reverse_arr(stack);
	if (stack->len_a >= 100 && stack->len_a < 500)
	{
		send_to_b(stack, 6);
		send_to_a(stack, 6);
	}
	else if (stack->len_a >= 500)
	{
		send_to_b(stack, 15);
		send_to_a(stack, 15);
	}
}
