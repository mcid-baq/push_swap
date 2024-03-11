/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:53:32 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/27 12:49:56 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	target_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		temp_a = *stack_a;
		temp_b->target_pos = INT_MAX;
		while (temp_a != NULL)
		{
			if (temp_a->value > temp_b->value
				&& temp_a->value < temp_b->target_pos)
				temp_b->target_pos = temp_a->value;
			temp_a = temp_a->next;
		}
		if (temp_b->target_pos == INT_MAX)
			temp_b->target_pos = ft_smallest(*stack_a);
		temp_b = temp_b->next;
	}
}

static void	target_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		temp_b = *stack_b;
		temp_a->target_pos = INT_MIN;
		while (temp_b != NULL)
		{
			if (temp_b->value < temp_a->value
				&& temp_b->value > temp_a->target_pos)
				temp_a->target_pos = temp_b->value;
			temp_b = temp_b->next;
		}
		if (temp_a->target_pos == INT_MIN)
			temp_a->target_pos = ft_biggest(*stack_b);
		temp_a = temp_a->next;
	}
}

static void	exec_move(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (*stack_a == NULL)
	{
		st->error = true;
		return ;
	}
	while (st->rotate[rrr]--)
		rotate_reverse(stack_a, stack_b, rrr, st);
	while (st->rotate[rr]--)
		rotate(stack_a, stack_b, rr, st);
	while (st->rotate[ra]--)
		rotate(stack_a, stack_b, ra, st);
	while (st->rotate[rb]--)
		rotate(stack_a, stack_b, rb, st);
	while (st->rotate[rra]--)
		rotate_reverse(stack_a, stack_b, rra, st);
	while (st->rotate[rrb]--)
		rotate_reverse(stack_a, stack_b, rrb, st);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_listsorted(*stack_a))
		return ;
	push(stack_a, stack_b, pb, st);
	push(stack_a, stack_b, pb, st);
	while (st->size_a > 3)
	{
		target_in_b(stack_a, stack_b);
		moves(stack_a, stack_b, st, 'a');
		exec_move(stack_a, stack_b, st);
		push(stack_a, stack_b, pb, st);
	}
	sort_three_numbers(stack_a, stack_b, st);
	while (st->size_b)
	{
		target_in_a(stack_a, stack_b);
		moves(stack_a, stack_b, st, 'b');
		exec_move(stack_a, stack_b, st);
		push(stack_a, stack_b, pa, st);
	}
	while (ft_listsorted(*stack_a) == false)
	{
		if ()
		rotate_reverse(stack_a, stack_b, rra, st);
	}
}
// pos->stack_a->index > size / 2)
// ra(data);
//         else
//             rra(data);)
