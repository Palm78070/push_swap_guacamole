/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:11:58 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/29 19:02:35 by rath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct p_swap
{
	int	*a;
	int	*b;
	int	*s;
	int	len_a;
	int	len_b;
	int	len_s;
	int	len_ch;
	int	mid_sort;
	int	mid_stack;
	int	above_i;
	int	below_i;
	int	instruct;
	int	chunk;
} t_swap;

//utils => 5
int	*format_input(t_swap *stack, char **argv);

//utils2 => 5
void	print_stack(int *stack, int len);
void	reverse_arr(t_swap *stack);
int	*intdup(int *arr, int len, int index);
int	*change_to_index(t_swap *stack);
int	set_mid(int len);

//utils3 => 5
int	*choose_stack(t_swap *stack, int *top, char c);
int	cal_above(t_swap *stack, int index, char c);
int	cal_below(t_swap *stack, int index, char c);
void	use_above(t_swap *stack, int index, char c);
void	use_below(t_swap *stack, int index, char c);
//int	*choose_stack(t_swap *stack, int *top, char c);
//int	is_insort(int num, int index, t_swap *stack, char c); //mv
//void	check_stack_b(t_swap *stack); //mv

//utils4 => 4
int	is_insort(int num, int index, t_swap *stack, char c);
int	same_part(int num1, int num2, t_swap *stack);
void	check_stack_b(t_swap *stack);

//utils5 => 2
int	cal_above_b(t_swap *stack, int largest);
int	cal_below_b(t_swap *stack, int largest);
void	use_above_b(t_swap *stack, int index);
void	use_below_b(t_swap *stack, int index);

//mergesort
void	merge_sort(int *arr, int len);

//instruct
void	swap(t_swap *stack, char c);
void	rotate(t_swap *stack, char c);
void	rev_rotate(t_swap *stack, char c);
void	pa(t_swap *stack);
void	pb(t_swap *stack);

//sort_small
void	sort3(t_swap *stack);
void	sort5(t_swap *stack);

#endif
