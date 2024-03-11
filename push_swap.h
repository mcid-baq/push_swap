/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:15:30 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/22 15:49:38 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				target_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_push
{
	bool			error;
	bool			checker;
	int				rotate[6];
	int				size_a;
	int				size_b;
}					t_push;

enum	e_moves
{
	ra,
	rb,
	rra,
	rrb,
	rr,
	rrr,
	sa,
	sb,
	ss,
	pa,
	pb,
};

/*initialization*/
void	initialization(t_stack **stack_a, int arc, char **argv, t_push *st);
/*move*/
void	moves(t_stack **stack_a, t_stack **stack_b, t_push *st, int stack);
/* swap*/
void	swap(t_stack **stack_a, t_stack **stack_b, int move, t_push *st);
/*rotate*/
void	rotate(t_stack **stack_a, t_stack **stack_b, int move, t_push *st);
void	rotate_reverse(t_stack **stack_a, t_stack **stack_b, int move, \
t_push *st);
/*sort*/
void	sort_three_numbers(t_stack **stack_a, t_stack **stack_b, t_push *st);
void	sort_list(t_stack **stack_a, t_stack **stack_b, t_push *st);
/*push*/
void	push(t_stack **stack_a, t_stack **stack_b, int move, \
t_push *st);
/*utils*/
void	ft_isdigit(char *str, t_push *st);
char	**ft_split(char const *str, char c);
int		ft_smallest(t_stack *list);
int		ft_biggest(t_stack *list);
t_stack	*ft_lastlist(t_stack *list);
bool	ft_listsorted(t_stack *list);
/*error and free*/
void	ft_stack_cleaning(t_stack **stack_a, t_stack **stack_b, t_push *st);
void	ft_free_split(char **split);

#endif