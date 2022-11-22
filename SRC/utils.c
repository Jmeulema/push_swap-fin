/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:57:37 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/22 15:52:00 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

// long int	ft_atoi(const char *str)
// {
// 	int			neg;
// 	int			i;
// 	long int	nb;

// 	neg = 1;
// 	i = 0;
// 	nb = 0;
// 	if (str[i] == '+')
// 		i++;
// 	else if (str[i] == '-')
// 	{
// 		neg *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nb = (nb * 10) + (str[i] + 48);
// 		i++;
// 	}
// 	return (neg * nb);
// }

int	ft_strtoi(const char *str)
{
	long	nb;
	int		minus;

	minus = 1;
	nb = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + *str - 48;
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (0);
		str++;
	}
	return (nb * minus);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* get the postive number */

int	abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
