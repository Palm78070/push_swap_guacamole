/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:15:12 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/05 18:58:39 by rthammat         ###   ########.fr       */
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
	stack->chunk = 0;
}

static void	check_input(t_swap *stack)
{
	char	*s;

	s = get_next_line(STDIN_FILENO);
	while (s != NULL)
	{
		if (!use_instruct(stack, s))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free(s);
			return ;
		}
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sort(stack->a, stack->len_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(s);
}

int	main(int argc, char **argv)
{
	t_swap	*stack;

	stack = (t_swap *)malloc(sizeof(t_swap));
	stack_init(stack);
	if (argc == 1)
	{
		free_all(stack);
		exit(1);
	}
	stack->a = format_input(stack, argv);
	stack->b = (int *)malloc(stack->len_a * sizeof(int));
	if (stack->a == NULL || stack->b == NULL)
	{
		free_all(stack);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}	
	reverse_arr(stack);
	check_input(stack);
	free_all(stack);
	return (0);
}
