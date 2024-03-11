/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:58 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 13:37:32 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_reverse_op(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	last->next = *stack;
	temp->next = NULL;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}

void	rotate_reverse(t_stack **stack_a, t_stack **stack_b, int move,
	t_push *st)
{
	if (!(move == rra || move == rrb || move == rrr))
		write(1, "RR.Error\n", 9);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == rra || move == rrr)
		rotate_reverse_op(stack_a);
	if (move == rrb || move == rrr)
		rotate_reverse_op(stack_b);
	if (st->checker)
		return ;
	if (move == rra)
		write(1, "rra\n", 4);
	if (move == rrb)
		write(1, "rrb\n", 4);
	if (move == rrr)
		write(1, "rrr\n", 4);
}
