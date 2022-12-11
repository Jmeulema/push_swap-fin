/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:36:04 by jmeulema          #+#    #+#             */
/*   Updated: 2022/12/11 16:38:36 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/* cost_b and cost_a is associated to an element in B */
/* cost_b represents the cost to get the element in B to the top of B */
/* cost_a represents the cost to get the element in the right position in A */
/* the sign depend, if it's in the top half (+) and in the bottom half (-) */

int	abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/* Find the element in B with the cheapest cost to move to A */
/* do_move to get it in the correct position in stack A */

void	do_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs_nb(tmp->cost_a) + abs_nb(tmp->cost_b) < abs_nb(cheapest))
		{
			cheapest = abs_nb(tmp->cost_a) + abs_nb(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
