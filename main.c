/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:25:23 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/04 19:29:35 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_swap *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->s);
	free(stack);
}

static void	stack_init(t_swap *stack)
{
	stack->len_a = 0;
	stack->len_b = 0;
	stack->len_s = 0;
	stack->len_ch = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->s = NULL;
	stack->mid_sort = set_mid(stack->len_s);
	stack->mid_stack = 0;
	stack->above_i = 0;
	stack->below_i = 0;
	stack->instruct = 0;
	stack->chunk = 0;
}

int	main(int argc, char **argv)
{
	t_swap	*stack;

	stack = (t_swap *)malloc(sizeof(t_swap));
	if (!stack)
		exit(1);
	stack_init(stack);
	if (argc <= 1)
		exit(1);
	stack->a = format_input(stack, argv);
	stack->b = (int *)malloc(stack->len_a * sizeof(int));
	if (stack->a == NULL || stack->b == NULL)
	{
		free_all(stack);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	if (stack->len_a >= 0 && stack->len_a < 100)
		sort_small(stack);
	if (stack->len_a >= 100 || stack->len_a >= 500)
	{
		if (!stack_is_sort(stack->a, stack->len_a))
			sort_big(stack);
	}
	free_all(stack);
	return (0);
}
