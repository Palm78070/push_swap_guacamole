/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:34:02 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/02 15:52:50 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_insort(int num, int index, t_swap *stack, char c)
{
	int	i;
	int	last;
	int	chunk; ///////////////mo
	int	rem; ///////////////mo

	(void)c;
	//if (index < 0)
	//	printf("index is %i\n", index);
	i = index - 1;
	chunk = stack->chunk;
	rem = stack->len_s % chunk;
	//if (c == 'b')
	//	last = index + (stack->chunk - 1); //modify
		//last = index + ((stack->len_ch / 4) - 1); //modify
	if (stack->len_a <= rem && rem != 0)
		last = index + (rem - 1);
	else
		last = index + (stack->len_ch - 1); //modify
	while (++i <= last)
	{
		//if (i < 0)
		//{
			//printf("num is %i\n", num); //modify
			//printf("i is %i\n", i); //modify
			//printf("stack->s[i] is %i\n", stack->s[i]); ///modify
		//}
		if (num == stack->s[i])
			return (1);
	}
	return (0);
}

int	stack_is_sort(int *stack, int len)
{
	int	i;
	int	j;

	i = len - 1;
	j = i;
	while (i >= 1)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stack[i] > stack[j])
				return (0);
			--j;
		}
		--i;
	}
	return (1);
}

/*int	same_part(int num1, int num2, t_swap *stack)
{
	int	index1;
	int	index2;
	int	max;

	index1 = 0;
	index2 = 0;
	max = stack->len_s - 1;
	while (!is_insort(num1, index1, stack, 'b') && index1 <= max)
		index1 += 5;
	while (!is_insort(num2, index2, stack, 'b') && index2 <= max)
		index2 += 5;
	if (index1 == index2)
		return (1);
	else
		return (0);
}*/

/*static int	cal_insert_b(t_swap *stack, int num)
{
	int	i;
	int	top2;

	i = 0;
	top2 = stack->len_b - 2;
	printf("num is %i\n", num);
	printf("stack->b[top2] %i\n", stack->b[top2]);
	while (i <= 9 && top2 >= 0 &&!same_part(num, stack->b[top2], stack))
	{
		++i;
		--top2;
	}
	printf("top2 is %i\n", top2);
	printf("stack->b[top2] %i\n", stack->b[top2]);
	printf("i is %i\n", i);
	if (i > 9 || top2 < 0)
		return (-1);
	stack->above_i = top2;
	return (i);
}

static void	insert_to_b(t_swap *stack)
{
	int	cal_insert;
	int	count;
	int	top;
	int	edge_a;

	cal_insert = cal_insert_b(stack, stack->b[stack->len_b - 1]);
	printf("cal_insert is %i\n", cal_insert);
	count = 0;
	top = stack->len_a - 1;
	edge_a = stack->a[top];
	printf("edge_a is %i\n", edge_a);
	printf("stack->b[0] %i\n", stack->b[0]);
	if (cal_insert >= -1 && cal_insert <= 1)
	{
		if (cal_insert == 1)
			swap(stack, 'b');
		return ;
	}
	rotate(stack, 'b');
	if (same_part(stack->b[0], stack->b[1], stack))
	{
		while (stack->b[stack->len_b - 1] == stack->b[0] - 1) ////
			rotate(stack, 'b'); ////
		return ;
	}
	while (count < cal_insert)
	{
		pa(stack);
		top = stack->len_a - 1;
		if (stack->a[top - 1] != edge_a && stack->a[top] > stack->a[top - 1])
			swap(stack, 'a');
		++count;
	}
	rev_rotate(stack, 'b');
	if (stack->b[stack->len_b - 1] < stack->b[stack->len_b - 2])
		swap(stack, 'b');
	while (cal_insert > 0)
	{
		--cal_insert;
		pb(stack);
	}
}*/

/*void	check_stack_b(t_swap *stack)
{
	int	top;
	//static int	i = 0; //modify

	//if (i <= 3) //modify
	//insert_to_b(stack); //modify
	//++i; //modify
	top = stack->len_b - 1;
	if (top == 0)
		return ;
	*if (same_part(stack->b[top], stack->b[top - 1], stack))
	{
		if (stack->b[top] < stack->b[top - 1])
			swap(stack, 'b');
	}
	else if (same_part(stack->b[top], stack->b[top - 2], stack))
		swap(stack, 'b');
	else if (same_part(stack->b[top], stack->b[0], stack))
	{
		if (stack->b[top] > stack->b[0])
		{
			rev_rotate(stack, 'b');
			swap(stack, 'b');
			rotate(stack, 'b');
		}
		rotate(stack, 'b');
	}
	if (stack->b[top] == stack->b[0] + 1)
		rotate(stack, 'b');
	if (stack->b[top] < stack->b[0])
		rotate(stack, 'b');
	if (stack->b[top] < stack->b[top - 1])
		swap(stack, 'b');
}*/
