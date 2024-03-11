/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:12:58 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 12:24:49 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_op(t_stack **source, t_stack **destiny)
{
	t_stack	*top_src;
	t_stack	*top_dest;

	if (*source == NULL)
		return ;
	top_src = *source;
	top_dest = *destiny;
	*source = top_src->next;
	if (*source)
		(*source)->prev = NULL;
	if (top_dest == NULL)
	{
		top_src->next = NULL;
		*destiny = top_src;
		(*destiny)->prev = NULL;
		return ;
	}
	top_src->next = top_dest;
	top_dest->prev = top_src;
	*destiny = top_src;
}

void	push(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == pb || move == pa))
		write(1, "P.Error", 8);
	if (move == pb)
	{
		push_op(stack_a, stack_b);
		st->size_a--;
		st->size_b++;
	}
	if (move == pa)
	{
		push_op(stack_b, stack_a);
		st->size_a++;
		st->size_b--;
	}
	if (st->checker)
		return ;
	if (move == pb)
		write(1, "pb\n", 3);
	if (move == pa)
		write(1, "pa\n", 3);
}
