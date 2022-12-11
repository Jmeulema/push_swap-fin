/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:46:40 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/25 12:21:55 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	ft_nbcmp(char *nb1, char *nb2)
{
	return (ft_strtoi(nb1) == ft_strtoi(nb2));
}

static int	check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_nbcmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	argv_is_zero(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_is_sign(str[i]) == 1)
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	argv_is_correct(char **tab)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (ft_check_if_int(tab[i]) == 0 || ft_check_if_int(tab[i]) == -1)
			return (0);
		if (ft_is_nbr(tab[i]) == 0)
			return (0);
		if (argv_is_zero(tab[i]))
			nb_zero += 1;
		i++;
	}
	if (check_duplicate(tab) == 1)
		return (0);
	if (nb_zero > 1)
		return (0);
	return (1);
}

char	**ft_check_input(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	if (ac > 2)
	{
		tab = ft_remove_one(ac, av);
		if (argv_is_correct(tab) == 0)
		{
			free(tab);
			return (NULL);
		}
	}
	else
		tab = fill_tab_with_two(av);
	return (tab);
}
