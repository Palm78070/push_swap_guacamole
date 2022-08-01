#include "push_swap.h"

static void	free_all(t_swap *stack, char *s)
{
	free(stack->a);
	free(stack->b);
	free(stack->s);
	free(stack);
	free(s);
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

/*int	match_str(char *s, char *str)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != str[i])
		return (0);
	}
	return (1);
}

void	use_instruct(t_swap *stack, char *s)
{
	if (match_str(s, "sa\n"))
		swap2(stack, 'a');
	else if (match_str(s, "sb\n"))
		swap2(stack, 'b');
	else if (match_str(s, "ra\n"))
		rotate2(stack, 'a');
	else if (match_str(s, "rb\n"))
		rotate2(stack, 'b');
	else if (match_str(s, "rra\n"))
		rev_rotate2(stack, 'a');
	else if (match_str(s, "rrb\n"))
		rev_rotate2(stack, 'b');
	else if (match_str(s, "pa\n"))
		pa2(stack);
	else if (match_str(s, "pb\n"))
		pb2(stack);
}*/

/*void	use_instruct(t_swap *stack, char *s)
{
	if (match_str(s, "sa\n"))
		swap(stack, 'a');
	else if (match_str(s, "sb\n"))
		swap(stack, 'b');
	else if (match_str(s, "ra\n"))
		rotate(stack, 'a');
	else if (match_str(s, "rb\n"))
		rotate(stack, 'b');
	else if (match_str(s, "rra\n"))
		rev_rotate(stack, 'a');
	else if (match_str(s, "rrb\n"))
		rev_rotate(stack, 'b');
	else if (match_str(s, "pa\n"))
		pa(stack);
	else if (match_str(s, "pb\n"))
		pb(stack);
}*/

/*void	use_instruct(t_swap *stack, char *s)
{
	(void)stack;
	if (match_str(s, "sa\n"))
		printf("use sa\n");
	else if (match_str(s, "sb\n"))
		printf("use sb\n");
	else if (match_str(s, "ra\n"))
		printf("use ra\n");
	else if (match_str(s, "rb\n"))
		printf("use rb\n");
	else if (match_str(s, "rra\n"))
		printf("use rra\n");
	else if (match_str(s, "rrb\n"))
		printf("use rrb\n");
	else if (match_str(s, "pa\n"))
		printf("use pa\n");
	else if (match_str(s, "pb\n"))
		printf("use pb\n");
}*/

int	main(int argc, char **argv)
{
	t_swap	*stack;
	char	*s;

	stack = (t_swap *)malloc(sizeof(t_swap));
	s = NULL;
	stack_init(stack);
	if (argc == 1)
		exit(1);
	stack->a = format_input(stack, argv);
	if (stack->a == NULL)
	{
		free_all(stack, s);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}	
	reverse_arr(stack);
	s = get_next_line(STDIN_FILENO);
	while (s != NULL)
	{
		use_instruct(stack, s);
		s = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sort(stack->a, stack->len_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	print_stack(stack->a, stack->len_a); //mo
	free_all(stack, s);
	return (0);
}
