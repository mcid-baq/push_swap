/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:32:54 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 12:49:51 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_smallest(t_stack *list)
{
	t_stack	*temp;
	int		smallest;

	temp = list;
	smallest = temp->value;
	while (temp)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		temp = temp->next;
	}
	return (smallest);
}

int	ft_biggest(t_stack *list)
{
	t_stack	*temp;
	int		biggest;

	temp = list;
	biggest = temp->value;
	while (temp)
	{
		if (temp->value > biggest)
			biggest = temp->value;
		temp = temp->next;
	}
	return (biggest);
}

t_stack	*ft_lastlist(t_stack *list)
{
	t_stack	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

void	sort_three_numbers(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size_a == 2)
		swap(stack_a, stack_b, sa, st);
	while (ft_listsorted(*stack_a) == false)
	{
		if ((*stack_a)->value == ft_smallest(*stack_a)
			&& (*stack_a)->next->value == ft_biggest(*stack_a))
			rotate_reverse(stack_a, stack_b, rra, st);
		else if ((*stack_a)->value == ft_biggest(*stack_a)
			&& ft_lastlist(*stack_a)->value == ft_smallest(*stack_a))
			swap(stack_a, stack_b, sa, st);
		else if (ft_lastlist(*stack_a)->value == ft_smallest(*stack_a)
			&& (*stack_a)->next->value == ft_biggest(*stack_a))
			rotate_reverse(stack_a, stack_b, rra, st);
		else if ((*stack_a)->value == ft_biggest(*stack_a)
			&& (*stack_a)->next->value == ft_smallest(*stack_a))
			rotate(stack_a, stack_b, ra, st);
		else if (ft_lastlist(*stack_a)->value == ft_biggest(*stack_a)
			&& (*stack_a)->next->value == ft_smallest(*stack_a))
			swap(stack_a, stack_b, sa, st);
		else
			break ;
	}
}

bool	ft_listsorted(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
