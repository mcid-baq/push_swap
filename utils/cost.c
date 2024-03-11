/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:33:20 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 14:22:30 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_values_aux(t_push *st, int *rotate)
{
	if (rotate[rra] > 0 && rotate[rrb] > 0)
	{
		while (rotate[rra] && rotate[rrb])
		{
			rotate[rrr]++;
			rotate[rra]--;
			rotate[rrb]--;
		}
	}
	if (rotate[ra] + rotate[rb] + rotate[rra] + rotate[rrb] + rotate[rr] \
		+ rotate[rrr] < st->rotate[ra] + st->rotate[rb] + st->rotate[rra] \
		+ st->rotate[rrb] + st->rotate[rrr] + st->rotate[rr])
	{
		st->rotate[ra] = rotate[ra];
		st->rotate[rb] = rotate[rb];
		st->rotate[rr] = rotate[rr];
		st->rotate[rra] = rotate[rra];
		st->rotate[rrb] = rotate[rrb];
		st->rotate[rrr] = rotate[rrr];
	}
}

static void	set_values(t_push *st, int *rotate, bool init)
{
	if (init)
	{
		rotate[ra] = INT_MAX;
		rotate[rb] = INT_MAX;
		rotate[rra] = INT_MAX;
		return ;
	}
	if (rotate[ra] == INT_MAX)
		rotate[ra] = 0;
	if (rotate[rra] == INT_MAX)
		rotate[rra] = 0;
	if (rotate[rb] == INT_MAX)
		rotate[rb] = 0;
	if (rotate[rrb] == INT_MAX)
		rotate[rrb] = 0;
	if (rotate[ra] > 0 && rotate[rb] > 0)
	{
		while (rotate[ra] && rotate[rb])
		{
			rotate[rr]++;
			rotate[ra]--;
			rotate[rb]--;
		}
	}
	set_values_aux(st, rotate);
}

static void	min_mov_a(t_stack **stack_a, t_stack **stack_b, t_push *st, \
		t_stack *node)
{
	int		index;
	int		rotate[6];
	t_stack	*temp;

	index = 0;
	rotate[rr] = 0;
	rotate[rrr] = 0;
	rotate[rrb] = INT_MAX;
	set_values(st, rotate, true);
	temp = *stack_a;
	while (temp->value != node->value && index++ != -1)
		temp = temp->next;
	if (index > st->size_b / 2)
		rotate[rra] = st->size_a - index;
	else
		rotate[ra] = index;
	index = 0;
	temp = *stack_b;
	while (temp->value != node->target_pos && index++ != -1)
		temp = temp->next;
	if (index > st->size_b / 2)
		rotate[rrb] = st->size_b - index;
	else
		rotate[rb] = index;
	return (set_values(st, rotate, false));
}

static void	min_mov_b(t_stack **stack_a, t_stack **stack_b, t_push *st, \
		t_stack *node)
{
	int		index;
	int		rotate[6];
	t_stack	*temp;

	index = 0;
	rotate[rr] = 0;
	rotate[rrr] = 0;
	rotate[rrb] = INT_MAX;
	set_values(st, rotate, true);
	temp = *stack_b;
	while (temp->value != node->value && index++ != -1)
		temp = temp->next;
	if (index > st->size_b / 2)
		rotate[rrb] = st->size_b - index;
	else
		rotate[rb] = index;
	index = 0;
	temp = *stack_a;
	while (temp->value != node->target_pos && index++ != -1)
		temp = temp->next;
	if (index > st->size_a / 2)
		rotate[rra] = st->size_a - index;
	else
		rotate[ra] = index;
	return (set_values(st, rotate, false));
}

void	moves(t_stack **stack_a, t_stack **stack_b, t_push *st, int stack)
{
	t_stack	*temp;

	temp = *stack_b;
	if (stack == 'a')
		temp = *stack_a;
	st->rotate[ra] = 100;
	st->rotate[rb] = 100;
	st->rotate[rr] = 100;
	st->rotate[rra] = 100;
	st->rotate[rrb] = 100;
	st->rotate[rrr] = 100;
	while (temp != NULL)
	{
		if (stack == 'a')
			min_mov_a(stack_a, stack_b, st, temp);
		else
			min_mov_b(stack_a, stack_b, st, temp);
		temp = temp->next;
	}
}
