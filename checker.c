/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:15 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/22 17:27:42 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_leaks(void)
// {
// 	system("leaks push_swap");
// 	atexit(ft_leaks);
// }

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (i);
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static bool	aux(t_stack **stack_a, t_stack **stack_b, t_push *st, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push(stack_a, stack_b, pa, st);
	else if (ft_strcmp(line, "pb") == 0)
		push(stack_a, stack_b, pb, st);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(stack_a, stack_b, ra, st);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stack_a, stack_b, rb, st);
	else if (ft_strcmp(line, "rr") == 0)
		rotate(stack_a, stack_b, rr, st);
	else if (ft_strcmp(line, "rra") == 0)
		rotate_reverse(stack_a, stack_b, rra, st);
	else if (ft_strcmp(line, "rrb") == 0)
		rotate_reverse(stack_a, stack_b, rrb, st);
	else if (ft_strcmp(line, "rrr") == 0)
		rotate_reverse(stack_a, stack_b, rrr, st);
	else
	{
		st->error = true;
		return (false);
	}
	return (true);
}

static void	execute_command(t_stack **stack_a, t_stack **stack_b, \
t_push *st, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(stack_a, stack_b, sa, st);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_a, stack_b, sb, st);
	else if (ft_strcmp(line, "ss") == 0)
		swap(stack_a, stack_b, ss, st);
	else
		if (!aux(stack_a, stack_b, st, line))
			st->error = true;
}

static void	reading_instructions(t_stack **stack_a, t_stack **stack_b, \
t_push *st)
{
	char	*line;
	int		i;
	char	c;

	i = 0;
	line = NULL;
	while (read(0, &c, 1))
	{
		if (line == NULL)
			line = malloc(sizeof(char) * 4);
		if (c == '\n' || i == 3)
		{
			line[i] = '\0';
			execute_command(stack_a, stack_b, st, line);
			if (st->error)
				break ;
			i = 0;
			free(line);
			line = NULL;
		}
		else
			line[i++] = c;
	}
	if (line)
		free(line);
}

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
	st.checker = true;
	initialization(&stack_a, arc, argv, &st);
	if (!st.error)
		reading_instructions(&stack_a, &stack_b, &st);
	if (!st.error)
	{
		if (ft_listsorted(stack_a) && !st.size_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_stack_cleaning(&stack_a, &stack_b, &st);
	return (st.error);
}
