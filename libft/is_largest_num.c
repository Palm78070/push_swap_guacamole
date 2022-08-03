/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_largest_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:48:55 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/03 22:49:22 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_largest_num(int *stack, int num, int len)
{
	int	i;
	int	largest;

	i = -1;
	largest = stack[0];
	while (++i < len)
	{
		if (stack[i] > largest)
			largest = stack[i];
	}
	if (num == largest)
		return (1);
	return (0);
}
