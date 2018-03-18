/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:52:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/05 23:26:06 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	int	colordetec(t_lm *lm, int i, int cn)
{
	if (lm->plc != 1 && cn == lm->ant[1] && (lm->link[i]->ant[1] = lm->ant[1]))
	{
		if (lm->link[i]->plc == 3)
			ft_printf("%sL%d%s-%s%s%s", (lm->clr ? RD : ""),
			lm->link[i]->ant[1], WT, (lm->clr ? GR : ""), lm->link[i]->nm, WT);
		else
			ft_printf("%sL%d%s-%s%s%s", (lm->clr ? RD : ""),
			lm->link[i]->ant[1], WT, (lm->clr ? YL : ""), lm->link[i]->nm, WT);
		lm->ant[1] = 0;
		return (1);
	}
	return (0);
}

static	int		ft_printres(t_lm *lm, int j, int i, int cn)
{
	while (!(i = 0) && lm->plc != 1 && (cn != lm->ant[1] || lm->plc == 3))
	{
		while (lm->link[i]->plc != 1 && (lm->link[i]->way[1] != j ||
			lm->ex > lm->link[i]->ex))
			i++;
		if (lm->clr)
			lm->link[i]->clr = 1;
		lm = lm->link[i];
	}
	while (lm->link[i]->plc != 3 && (lm->link[i]->way[1] != j ||
		(lm->plc != 1 && lm->ex < lm->link[i]->ex)))
		i++;
	if (lm->plc == 1 && lm->link[i]->ant[0] == cn)
	{
		ft_printf("%sL%d%s-%s%s%s", (lm->clr ? RD : ""), lm->link[i]->ant[0],
			WT, (lm->clr ? YL : ""), lm->link[i]->nm, WT);
		lm->link[i]->ant[1] = lm->link[i]->ant[0];
		lm->link[i]->ant[0] = 0;
		return (1);
	}
	return (colordetec(lm, i, cn));
}

static	void	ft_resout(t_lm *end, t_lm *lm, int cn, int ant)
{
	int			i;
	int			j;
	int			xy[4];

	i = 0;
	j = 1;
	while (cn <= ant)
	{
		while (end->link[i] && end->link[i]->way[1] != j)
			i++;
		if (end->link[i] && lm->clr)
			end->link[i]->clr = 1;
		if ((!end->link[i] && !(j = 0)))
			cn += 1;
		else if (ft_printres(end->link[i], j, 0, cn) && !(j = 0) &&
			(cn += 1) && cn <= ant)
			ft_printf(" ");
		i = 0;
		j++;
	}
	ft_printf("\n");
	if (lm->st)
		lm->st += 1;
	if (lm->vs)
		le_visual(lm, lm, xy, 0);
}

void			ft_theway(t_lm *end, t_lm *lm, t_lm *bg, int *j)
{
	int			ant;
	int			u;
	int			i;

	ant = 0;
	while (j[2] && !(i = 0))
	{
		while (bg->link[i] && bg->link[i]->way[1] != j[0])
			i++;
		if (bg->link[i] || (j[0] = 0))
		{
			u = -1;
			j[1] = j[2];
			while (bg->link[++u] && j[0] > 1)
				if (bg->link[u]->way[1] > 0 && bg->link[u]->way[1] < j[0])
					j[1] -= (bg->link[i]->ex - bg->link[u]->ex);
			if ((j[1] > 0 && (j[2] -= 1) > -1) || (j[0] = 0))
				bg->link[i]->ant[0] = ++ant;
		}
		if ((j[0] += 1) == 1 && (bg->ant[1] = j[2]))
			ft_resout(end, lm, 1, ant);
		while (!j[2] && end->ant[1] < ant && !(bg->ant[1] = j[2]))
			ft_resout(end, lm, 1, ant);
	}
}

void			minull(t_lm *bg, int i)
{
	while (bg->link[i])
	{
		if (bg->link[i]->way[1] < 0)
			bg->link[i]->way[1] = 0;
		i++;
	}
}
