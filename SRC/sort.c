/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:26:39 by jmeulema          #+#    #+#             */
/*   Updated: 2022/12/11 15:32:33 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	get_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* sort for 3 numbers / max 2 moves */

void	small_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack) == 1)
		return ;
	highest = get_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
/* push_all_save_three:
Pushes all the elements of stack a into stack b, except the three last ones.
Pushes the smaller values first, and then the larger values to help with
sorting efficiency */

static void	push_and_save(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* change stack_a until the lowest value is at the top. 
If it is in the bottom half of the stack reverse rotate it into position
otherwise rotate until it is at the top of the stack */

static void	change_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	lowest_pos = get_lowest_index_pos(stack_a);
	stack_size = get_stack_size(*stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* Sorting a stack larger than 3.
Push everything but 3 numbers to stack B.
Sort the 3 numbers left in stack A.
Calculate the most cost-effective move.
change elements until stack A is in order */

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_and_save(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_best_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
	{
		change_stack(stack_a);
	}
}
