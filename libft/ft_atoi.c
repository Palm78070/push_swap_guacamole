/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:08:40 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/26 12:41:44 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_instr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		++s;
	}
	return (0);
}

static int	ft_isspace(char c)
{
	return (is_instr(c, " \t\r\n\v\f"));
}

static int	get_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			++sign;
		++i;
	}
	if (sign % 2 != 0)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = get_sign(str);
	while (*str && ft_isspace(*str))
		++str;
	while (*str != '\0' && (*str == '+' || *str == '-'))
		++str;
	while (*str && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > LLONG_MAX && sign > 0)
			return (-1);
		else if (result > LLONG_MAX)
			return (0);
		++str;
	}
	return ((int)(result * sign));
}
