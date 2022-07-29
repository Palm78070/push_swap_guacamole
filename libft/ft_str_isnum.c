/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:02:07 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/28 16:54:44 by rath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_str_isnum(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (is_sign(s[i]))
		++i;
	i -= 1;
	while (s[++i])
	{
		if (ft_isdigit(s[i]))
			flag = 1;
		if (!(ft_isdigit(s[i])) && !is_sign(s[i]))
			return (0);
	}
	if (flag == 0)
		return (0);
	return (1);
}
