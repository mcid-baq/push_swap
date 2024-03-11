/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:40 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 12:44:16 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_op(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = ft_lastlist(*stack);
	*stack = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == ra || move == rb || move == rr))
		write(1, "R.Error\n", 8);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == ra || move == rr)
		rotate_op(stack_a);
	if (move == rb || move == rr)
		rotate_op(stack_b);
	if (st->checker)
		return ;
	if (move == ra)
		write(1, "ra\n", 3);
	if (move == rb)
		write(1, "rb\n", 3);
	if (move == rr)
		write(1, "rr\n", 3);
}
