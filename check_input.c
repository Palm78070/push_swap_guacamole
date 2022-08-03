/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:27:50 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/02 20:41:17 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(t_swap *stack, int index, int num)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
	{
		if (i == index)
			++i;
		if (num == stack->a[i] && i < stack->len_a)
		{
			free(stack->a);
			return (0);
		}
	}
	return (1);
}

static int	check_str_isnum(t_swap *stack, char **s)
{
	int	i;

	i = -1;
	while (s[++i] != NULL)
	{
		if (!ft_str_isnum(s[i]))
		{
			free(stack->a);
			free_double(s);
			return (0);
		}
	}
	return (1);
}

static void	insert_num(t_swap *stack, int n)
{
	int	i;
	int	*tmp;

	stack->len_a += 1;
	i = -1;
	//if (stack->a != NULL)//////////////////mo
		tmp = stack->a;
	//else
	//	tmp = NULL;/////////////////mo
	//stack->a = (int *)malloc(stack->len_a * sizeof(int));
	stack->a = (int *)malloc((stack->len_a + 1) * sizeof(int)); ////add 1 more
	if (!stack->a)
	{
		if (tmp)
			free(tmp);
		return ;
	}
	stack->a[stack->len_a] = 0; ///////mo
	while (++i < stack->len_a - 1)
		stack->a[i] = tmp[i];
	stack->a[i] = n;
	if (tmp)
		free(tmp);
}

static int	check_and_insert(t_swap *stack, char **s)
{
	int	i;
	long long	n;

	i = -1;
	n = 0;
	while (s[++i] != NULL)
	{
		n = ft_atoi(s[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			if (stack->a)
				free(stack->a);
			free_double(s);
			return (0);
		}
		insert_num(stack, (int)n);
	}
	free_double(s);
	return (1);
}

int	*format_input(t_swap *stack, char **argv)
{
	char	**s;
	int	i;

	i = 0;
	s = NULL;
	while (argv[++i])
	{
		s = ft_split(argv[i], ' ');
		if (!check_str_isnum(stack, s) || !check_and_insert(stack, s))
			return (NULL);
	}
	i = -1;
	while (++i < stack->len_a)
	{
		if (!check_dup(stack, i, stack->a[i]))
			return (NULL);
	}
	if (stack->a != NULL)
	{
		stack->len_s = stack->len_a;
		stack->mid_sort = set_mid(stack->len_s);
		/*stack->b = (int *)malloc(stack->len_a * sizeof(int));
		if (!stack->b) ///////////////////mo
		{
			if (stack->a)
				free(stack->a);
			return (NULL);
		} //////////////////////////////////mo*/
	}
	return (stack->a);
}
