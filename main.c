/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:25:23 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/01 18:40:44 by rath             ###   ########.fr       */
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
	stack_init(stack);
	if (argc <= 1)
		exit(1);
	stack->a = format_input(stack, argv);
	if (stack->a == NULL)
	{
		free_all(stack);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	if (stack->len_a >= 0 && stack->len_a < 100)
	{
		reverse_arr(stack);
		sort_small(stack);
	}
	if (stack->len_a >= 100 || stack->len_a >= 500)
	{
		stack->a = change_to_index(stack);
		reverse_arr(stack);
		if (!stack_is_sort(stack->a, stack->len_a))
			sort_big(stack);
	}
	/*print_stack(stack->a, stack->len_a);
	printf("\n");
	print_stack(stack->b, stack->len_b);
	printf("instruct is %i\n", stack->instruct);
	printf("len_a is %i\n", stack->len_a);
	printf("len_b is %i\n", stack->len_b);*/
	free_all(stack);
	return (0);
}
