/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:25:13 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/22 17:06:07 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Utils */

// long int	ft_atoi(const char *str);
int			ft_strtoi(const char *str);
int			abs_nb(int nb);
void		ft_putstr(char	*str);
void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* ft_split */

char		**ft_split(char const *s, char c);

/* tab */

char		**ft_free_tab(char **tab);
int			ft_size_tab(char **tab);
char		**fill_tab_with_two(char **av);

/* Stack utils */

t_stack		*get_last_stack(t_stack *stack);
t_stack		*get_before_last_stack(t_stack *stack);
t_stack		*new_stack(int value);
void		add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);

/* Argv check */

int			argv_is_correct(char **av);
int			ft_is_digit(int c);
int			ft_is_sign(char c);
int			ft_is_nbr(char *str);
int			ft_cmp_nbr(const char *s1, const char *s2);
int			ft_check_if_int(const char *str);
char		**ft_remove_one(int ac, char **av);
char		**ft_check_input(int ac, char **av);

/* Position */

int			get_lowest_index_pos(t_stack **stack);
void		get_target_position(t_stack **a, t_stack **b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_best_move(t_stack **stack_a, t_stack **stack_b);

/* Move */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* sort */

int			is_sorted(t_stack *stack);
void		small_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Instructions */
/* Push */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);

/* Swap */

void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);

/* Rotate */

void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate */

void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif