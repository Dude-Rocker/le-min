/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:33:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/12 16:41:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	srcexit(t_lm *lm, int a, int j, int i);

static	int		changeway(t_lm *lm, int *a, int j, int i)
{
	while (lm->link[++i])
		if (lm->link[i]->ex == j && !lm->link[i]->way[1])
			break ;
	if (lm->link[i])
		*a = i;
	else if (!(j = 0))
	{
		i = 0;
		while (lm->link[i] && lm->link[i]->way[1] != lm->way[1])
			i++;
		lm->way[1] *= -1;
		if (lm->link[i] && !changeway(lm->link[i], a, lm->ex, -1))
			srcexit(lm->link[i], lm->way[1] * -1, lm->way[0], -1);
		if (lm->link[i] && lm->link[i]->way[1] > -1)
		{
			lm->way[1] = 0;
			lm->way[0] = 0;
		}
		return (1);
	}
	return (0);
}

static	void	srcexit(t_lm *lm, int a, int j, int i)
{
	int			p;
	int			m;

	while (lm->plc != 3 && !(p = 0))
	{
		m = 0;
		while (lm->link[++i])
		{
			if ((lm->link[i]->plc == 3 || (lm->link[i]->ex && ((lm->plc != 1
				&& lm->link[i]->way[1] > -1) || (lm->plc == 1 &&
				!lm->link[i]->way[1])) && (!m || lm->link[i]->ex < m)))
				&& (m = lm->link[i]->ex))
				p = i;
		}
		if (lm->link[p]->plc != 3 && (i = -1))
		{
			if (lm->link[p]->way[1])
				if (changeway(lm, &p, lm->link[p]->ex, -1))
					return ;
			lm->link[p]->way[0] = j++;
			lm->link[p]->way[1] = a;
		}
		lm = lm->link[p];
	}
}

static	void	rightway(t_lm *lm, int i, int j, int o)
{
	if (i)
	{
		lm->way[1] = i;
		while (lm->link[o]->way[1] != j && lm->link[o]->plc != 3)
			o++;
		if (lm->link[o]->plc != 3)
			rightway(lm->link[o], i, j, 0);
		return ;
	}
	while (lm->link[i])
	{
		if (lm->link[i]->way[1] > 0)
		{
			lm->link[i]->way[1] *= -1;
			rightway(lm->link[i], 0, 0, 0);
		}
		i++;
	}
}

static	void	trueway(t_lm *lm, int i, int j, int o)
{
	int			p;
	int			w;

	p = 1;
	w = 1;
	while (p)
	{
		i = 0;
		j = 0;
		while (lm->link[i])
		{
			if (lm->link[i]->way[1] < 0 && (!j || lm->link[i]->ex < j))
			{
				j = lm->link[i]->ex;
				o = i;
			}
			i++;
		}
		i = 0;
		p = 0;
		rightway(lm->link[o], w++, lm->link[o]->way[1], 0);
		while (lm->link[i])
			if (lm->link[i++]->way[1] < 0)
				p++;
	}
}

void			ft_algoexit(t_lm *end, int a, t_lm *bg, t_lm *lm)
{
	int			j[3];
	int			i;
	int			o;

	j[0] = 1;
	j[1] = 0;
	j[2] = a;
	i = -1;
	o = 0;
	end->ex = -1;
	while (bg->link[++i])
		if (bg->link[i]->ex)
			o++;
	i = 1;
	while (o--)
		srcexit(bg, i++, 1, -1);
	minull(bg, 0);
	rightway(bg, 0, 0, 0);
	trueway(bg, 0, 0, 1);
	ft_theway(end, lm, bg, j);
}
