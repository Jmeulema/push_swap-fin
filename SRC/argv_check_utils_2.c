/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:46:40 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/22 17:06:01 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	check_duplicate(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		j = 1;
		while (tab[j])
		{
			if (j != i && ft_cmp_nbr(tab[i], tab[j]) == 0)
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
	if (nb_zero > 1)
		return (0);
	if (check_duplicate(tab) == 1)
		return (0);
	return (1);
}

char	**ft_remove_one(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 1;
	if (!av)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ac);
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[i - 1] = av[i];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_check_input(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	else if (ac > 2)
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
