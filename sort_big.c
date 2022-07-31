#include "push_swap.h"

void	sort_big(t_swap *stack)
{
	if (stack->len_a >= 100 && stack->len_a < 500)
	{
		send_to_b(stack, 6);
		send_to_a(stack, 6);
	}
	else if (stack->len_a >= 500)
	{
		send_to_b(stack, 15);
		send_to_a(stack, 15);
	}
}
