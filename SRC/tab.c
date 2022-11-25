/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:57:37 by jmeulema          #+#    #+#             */
/*   Updated: 2022/11/25 12:14:23 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return (NULL);
	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free (tab);
	}
	return (NULL);
}

int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**fill_tab_with_two(char **av)
{
	char	**tab;

	tab = ft_split(av[1], ' ');
	if (!tab || !tab[0])
		return (NULL);
	if (argv_is_correct(tab) == 0)
	{
		if (tab[0])
			ft_free_tab(tab);
		else
			free(tab);
		return (NULL);
	}
	return (tab);
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
