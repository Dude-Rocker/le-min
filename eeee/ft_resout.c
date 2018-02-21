/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:52:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/21 14:45:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	int		ft_printres(t_lm *lm, int j, int i, int cn)
{
	while (lm->place != 1 && cn != lm->ant[1])
	{
		while (lm->link[i]->way != j || lm->ex > lm->link[i]->ex)
			i++;
		lm = lm->link[i];
		i = 0;
	}
	while (lm->link[i]->way != j || lm->ex < lm->link[i]->ex)
		i++;
	if (lm->place == 1 && lm->link[i]->ant[0] == cn)
	{
		ft_printf("L%d-%s\n", lm->link[i]->ant[0], lm->link[i]->nm);
		lm->link[i]->ant[1] = lm->link[i]->ant[0];
		lm->link[i]->ant[0] = 0;
		return (1);
	}
	if (cn == lm->ant[1])
	{
		ft_printf("L%d-%s\n", lm->ant[1], lm->link[i]->nm);
		lm->link[i]->ant[1] = lm->ant[1];
		lm->ant[1] = 0;
		return (1);
	}
	return (0);
}

static	void	ft_resout(t_lm *lm, int j, int cn, int ant)
{
	int			i;

	i = 0;
	while (cn <= ant)
	{
		while (lm->link[i] && lm->link[i]->way != j)
			i++;
		if (!lm->link[i])
			j = 0;
		else if (ft_printres(lm->link[i], j, 0, cn) && (cn += 1) && cn <= ant)
			ft_printf(" ");
		i = 0;
		j++;
	}
	ft_printf("\n");
}

static	void	ft_lastout(t_lm *lm, int cn, int ants)
{
	int			i;

	i = 0;
	while (lm->place != 3)
	{
		while (lm->link[i]->way != 1 || lm->ex < lm->link[i]->ex)
			i++;
		lm = lm->link[i];
		i = 0;
	}
	i = lm->ant[1] + 1;
	if (cn)
		ft_resout(lm, 1, i, ants);
	else
		while (lm->ant[1] != ants)
			ft_resout(lm, 1, i, ants);
}

void			ft_theway(t_lm *lm, int cn, int i, int *j)
{
	int			res;
	int			ant;
	int			u;

	ant = 1;
	while (lm->ant[1] != cn + ant - 1 && !(i = 0))
	{
		res = 0;
		while (lm->link[i] && lm->link[i]->way != j[0])
			i++;
		if (lm->link[i] || (j[0] = 0))
		{
			u = 0;
			res = cn;
			j[1] = j[0] - 1;
			while (lm->link[u] && j[1])
				if (lm->link[u++]->way == j[1] && (j[1]--))
					res -= (lm->link[i]->ex - lm->link[u - 1]->ex);
			if ((res > 0 && (cn--)) || (j[0] = 0))
				lm->link[i]->ant[0] = ant++;
		}
		if ((j[0] += 1) == 1 || !cn)
			ft_lastout(lm, cn, ant - 1);
	}
}

// j[0] = 1; j[1] = 0
// 