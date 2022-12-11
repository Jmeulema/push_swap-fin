/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:08:18 by jmeulema          #+#    #+#             */
/*   Updated: 2022/12/11 15:14:10 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_is_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '\0')
		return (0);
	if (ft_is_sign(str[i]) == 1 && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_is_digit(str[i]) == 1)
		i++;
	if (str[i] != '\0' && ft_is_digit(str[i]) == 0)
		return (0);
	return (1);
}

int	ft_check_if_int(const char *str)
{
	long	nb;
	int		minus;
	int		i;

	minus = -1;
	nb = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + str[i] - 48;
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (0);
		i++;
	}
	if (str[i] || (minus == 1 && i == 1) || i == 0)
		return (0);
	return (1);
}
