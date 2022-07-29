/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:25:23 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/29 16:19:54 by rath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_swap *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->s);
	free(stack);
}

/*void	stack_init(t_swap *stack, int len)
{
	stack->len_a = len;
	stack->len_b = 0;
	stack->len_s = len;
	stack->len_ch = 0;
	stack->a = (int *)malloc(stack->len_a * sizeof(int));
	stack->b = (int *)malloc(stack->len_a * sizeof(int));
	stack->s = NULL;
	stack->mid_sort = set_mid(stack->len_s);
	stack->mid_stack = 0;
	stack->above_i = 0;
	stack->below_i = 0;
	stack->instruct = 0;
}*/

void	stack_init(t_swap *stack)
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
}

void	stack_b_operation(t_swap *stack, int index, int largest)
{
	int	above;
	int	below;
	
	above = cal_above_b(stack, largest);
	below = cal_below_b(stack, largest);
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		if (stack->b[stack->above_i] > stack->b[stack->below_i])
			use_above(stack, index, 'b');
		else
			use_below(stack, index, 'b');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'b');
	else
		use_above(stack, index, 'b');
	pa(stack);
}

void	stack_a_operation(t_swap *stack, int index)
{
	int	above;
	int	below;

	above = cal_above(stack, index, 'a');
	below = cal_below(stack, index, 'a');
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		if (stack->a[stack->above_i] < stack->a[stack->below_i])
			use_above(stack, index, 'a');
		else
			use_below(stack, index, 'a');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'a');
	else
		use_above(stack, index, 'a');
	pb(stack);
	check_stack_b(stack);
}

void	send_to_b(t_swap *stack, int chunk)
{
	static int	i = 0;
	static int	count = 0;
	static int	start = 0;
	int	top;

	stack->len_ch = stack->len_s / chunk;
	top = (i + stack->len_ch) - 1;
	//if (count == chunk)
	//if (count == 2)
	/*if (count == chunk)
		return ;*/
	if (stack->len_a == 0)
		return ;
	while (i <= top)
	{
		//printf("Round %i\n", i); //modify
		stack_a_operation(stack, start);
		++i;
	}
	start += stack->len_ch;
	++count;
	send_to_b(stack, chunk);
}

void	send_to_a(t_swap *stack, int chunk)
{
	static int	i = 0;
	int	floor;

	if (i == 0)
		i = stack->len_s - 1;
	floor = (i - stack->len_ch) + 1;
	if (stack->len_b == 0)
		return ;
	while (i >= floor)
	{
		stack_b_operation(stack, floor, stack->s[i]);
		--i;
	}
	send_to_a(stack, chunk);
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
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (stack->len_a == 3 || stack->len_a == 5)
	{
		reverse_arr(stack);
		if (stack->len_a == 3)
			sort3(stack);
		else
			sort5(stack);
		return (0);
	}
	stack->a = change_to_index(stack);
	reverse_arr(stack);
	if (stack->len_a == 100)
	{
		send_to_b(stack, 6);
		send_to_a(stack, 6);
	}
	if (argc == 501)
	{
		send_to_b(stack, 11);
		send_to_a(stack, 11);
	}
	/*print_stack(stack->a, stack->len_a);
	printf("\n");
	print_stack(stack->b, stack->len_b);
	printf("instruct is %i\n", stack->instruct);*/
	free_all(stack);
	return (0);
}
