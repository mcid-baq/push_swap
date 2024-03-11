/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/23 11:37:10 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isdigit(char *str, t_push *st)
{
	int	i;

	if (st->error == true)
		return ;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != '\0' && str[i \
		+ 1] != ' '))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			st->error = true;
		i++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_stack_cleaning(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	t_stack	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	while (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
	if (st->error == true)
		write(2, "Error\n", 6);
}
