/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/17 17:06:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atointmax(str) < INT_MINI || ft_atointmax(str) > INT_MAXI)
		return (0);
	return (1);
}

void	ft_ab_minmax(t_heaps **ab, int nb)
{
	if (*ab && !(*ab)->a)
	{
		(*ab)->min = nb;
		(*ab)->max = nb;
	}
	else if (*ab)
	{
		if (nb < (*ab)->min)
			(*ab)->min = nb;
		if (nb > (*ab)->max)
			(*ab)->max = nb;
	}
}

int		ft_read_and_fillstack(int ac, char **av, t_heaps **ab)
{
	int		nb;
	int		i;
	char	**tab;

	if (!(*ab))
		ft_error(ab, "read_and_fillstack");
	while (ac > 1)
	{
		ac--;
		i = 0;
		tab = ft_strsplit(av[ac], ' ');
		while (tab[i])
			i++;
		while (--i >= 0)
		{
			if (ft_isnumber(tab[i]))
			{
				nb = ft_atoi(tab[i]);
				ft_ab_minmax(ab, nb);
				ft_stackpush(ab, &(*ab)->a, nb, 'a');
			}
			else if (tab[i][0] == '-' && tab[i][1] == 'v')
				(*ab)->option_v = 1;
			else
				ft_error(ab, 0);
		}
		ft_freetab_strsplit(tab);
	}
	(*ab)->a_min = (*ab)->min;
	(*ab)->a_max = (*ab)->max;
	(*ab)->count = (*ab)->a->index;
	return (1);
}
