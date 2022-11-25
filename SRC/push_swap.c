/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:03:45 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/23 11:56:20 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static t_stack	*fill_stack_a(int size, char **tab)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < size && tab[i])
	{
		nb = ft_strtoi(tab[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = new_stack((int)nb);
		else
			add_bottom(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

static void	set_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		biggest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				biggest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size;
	}
}

/*check if it's already sorted */

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*check the way to sort it */

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		small_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**tab;

	if (ac < 2)
		return (0);
	tab = ft_check_input(ac, av);
	if (tab == NULL)
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_a(ft_size_tab(tab), tab);
	stack_size = get_stack_size(stack_a);
	set_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
