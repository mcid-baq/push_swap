/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:59 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 12:28:30 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_op(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*swap;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	swap = (*stack)->next;
	if (swap->next)
		swap->next->prev = *stack;
	swap->prev = temp->prev;
	temp->prev = swap;
	(*stack)->next = swap->next;
	swap->next = temp;
	*stack = swap;
}

void	swap(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == sa || move == sb || move == ss))
		write(1, "S.Error\n", 8);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == sa || move == ss)
		swap_op(stack_a);
	if (move == sb || move == ss)
		swap_op(stack_b);
	if (st->checker)
		return ;
	if (move == sa)
		write(1, "sa\n", 3);
	if (move == sb)
		write(1, "sb\n", 3);
	if (move == ss)
		write(1, "ss\n", 3);
}
