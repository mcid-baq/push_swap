/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:32:55 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/23 13:15:28 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ft_new_list(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

static void	check_copies(t_stack *stack_a, t_push *st, int content)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->value == content)
			st->error = true;
		temp = temp->next;
	}
}

static long	ft_atoi(char *str, t_push *st)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	if (st->error == true)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && st->error == false)
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr < 0)
			st->error = true;
	}
	return (nbr * sign);
}

static void	ft_list_add_back(t_stack **stack, int content, t_push *st)
{
	t_stack	*last;
	t_stack	*new;

	if (!stack)
		st->error = true;
	if (st->error == true)
		return ;
	new = ft_new_list(content);
	if (!new)
	{
		st->error = true;
		return ;
	}
	st->size_a++;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_lastlist(*stack);
	new->prev = last;
	last->next = new;
}

void	initialization(t_stack **stack_a, int arc, char **argv, t_push *st)
{
	int	i;
	int	content;

	i = 0;
	if (arc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			st->error = true;
		i = -1;
	}
	while (argv[++i] && st->error == false)
	{
		ft_isdigit(argv[i], st);
		content = ft_atoi(argv[i], st);
		if (st->error == true)
			break ;
		if (content > INT_MAX || content < INT_MIN)
			ft_stack_cleaning(stack_a, NULL, st);
		ft_list_add_back(stack_a, content, st);
		check_copies(*stack_a, st, content);
	}
	if (arc == 2)
		ft_free_split(argv);
}
