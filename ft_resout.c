/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:52:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/25 17:22:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	int		ft_printres(t_lm *lm, int j, int i, int cn)
{
	while (!(i = 0) && lm->place != 1 && cn != lm->ant[1])
	{
		while (lm->link[i]->place != 1 && (lm->link[i]->way[1] != j ||
			lm->ex > lm->link[i]->ex))
			i++;
		lm = lm->link[i];
	}
	while (lm->link[i]->place != 3 && (lm->link[i]->way[1] != j ||
		(lm->place != 1 && lm->ex < lm->link[i]->ex)))
		i++;
	if (lm->place == 1 && lm->link[i]->ant[0] == cn)
	{
		ft_printf("L%d-%s", lm->link[i]->ant[0], lm->link[i]->nm);
		lm->link[i]->ant[1] = lm->link[i]->ant[0];
		lm->link[i]->ant[0] = 0;
		return (1);
	}
	if (cn == lm->ant[1])
	{
		ft_printf("L%d-%s", lm->ant[1], lm->link[i]->nm);
		lm->link[i]->ant[1] = lm->ant[1];
		lm->ant[1] = 0;
		return (1);
	}
	return (0);
}

static	void	ft_resout(t_lm *end, int j, int cn, int ant)
{
	int			i;

	i = 0;
	while (cn <= ant)
	{
		while (end->link[i] && end->link[i]->way[1] != j)
			i++;
		if (!end->link[i])
			j = 0;
		else if (ft_printres(end->link[i], j, 0, cn) && (cn += 1) && cn <= ant)
			ft_printf(" ");
		i = 0;
		j++;
	}
	ft_printf("\n");
}

void			ft_theway(t_lm *end, int cn, t_lm *bg, int *j)
{
	int			ant;
	int			u;
	int			i;

	ant = 0;
	while (cn && !(i = 0))
	{
		while (bg->link[i] && bg->link[i]->way[1] != j[0])
			i++;
		if (bg->link[i] || (j[0] = 0))
		{
			u = -1;
			j[1] = cn;
			while (bg->link[++u] && j[0] > 1)
				if (bg->link[u]->way[1] > 0 && bg->link[u]->way[1] < j[0])
					j[1] -= (bg->link[i]->ex - bg->link[u]->ex);
			if ((j[1] > 0 && (cn--)) || (j[0] = 0))
				bg->link[i]->ant[0] = ++ant;
		}
		if ((j[0] += 1) == 1)
			ft_resout(end, 1, end->ant[1] + 1, ant);
		while (!cn && end->ant[1] < ant)
			ft_resout(end, 1, end->ant[1] + 1, ant);
	}
}
