/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:03:01 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/26 10:44:44 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_leaks(void)
// {
// 	system("leaks push_swap");
// 	atexit(ft_leaks);
// }

int	main(int arc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_push	st;

	if (arc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	st = (t_push){0};
	initialization(&stack_a, arc, argv, &st);
	if (!st.error)
	{
		if (st.size_a > 3)
			sort_list(&stack_a, &stack_b, &st);
		else 
		{
			if (!ft_listsorted(stack_a))
				sort_three_numbers(&stack_a, &stack_b, &st);
		}
	}
	ft_stack_cleaning(&stack_a, &stack_b, &st);
	return (st.error);
}
