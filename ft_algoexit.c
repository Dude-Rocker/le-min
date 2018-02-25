/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:33:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/26 00:00:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	srcexit(t_lm *lm, int a, int j, int i);

static	int		changeway(t_lm *lm, int *a, int j, int i)
{
	// ft_printf("pp %s %d\n", lm->nm, lm->way[1]);
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
		// while (lm->link[i] && lm->link[i]->link[j]->nm != lm->nm)
		// 	j++;
		// ft_printf("1 %s %d\n", lm->link[i]->nm, lm->link[i]->way[1]);
		if (lm->link[i] &&
			!changeway(lm->link[i], a, lm->ex, -1))
			srcexit(lm->link[i], lm->way[1] * -1, lm->way[0], -1);
		// ft_printf("2 %s %d\n", lm->link[i]->nm, lm->link[i]->way[1]);
		// if (lm->link[i] && lm->link[i]->way[1] > -1)
		// {
			lm->way[1] = 0;
			lm->way[0] = 0;
		// }
		// ft_printf("3 %d\n", lm->link[i]->way[1]);
		return (1);
	}
	// ft_printf("end %s\n", lm->link[i]->nm);
	return (0);
}

static	void	srcexit(t_lm *lm, int a, int j, int i)
{
	int			p;
	int			m;

	while (lm->place != 3 && !(p = 0))
	{
		m = 0;
		while (lm->link[++i])
		{
			if ((lm->link[i]->place == 3 || (lm->link[i]->ex && ((lm->place != 1
				&& lm->link[i]->way[1] > -1) || (lm->place == 1 &&
				!lm->link[i]->way[1])) && (!m || lm->link[i]->ex < m)))
				&& (m = lm->link[i]->ex))
				p = i;
		}
		if (lm->link[p]->place != 3 && (i = -1))
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
		while (lm->link[o]->way[1] != j && lm->link[o]->place != 3)
			o++;
		if (lm->link[o]->place != 3)
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

void			ft_algoexit(t_lm *lm, int a, t_lm *bg)
{
	int			j[2];
	int			i;
	int			o;

	j[0] = 1;
	j[1] = 0;
	i = -1;
	o = 0;
	lm->ex = -1;
	while (bg->link[++i])
		if (bg->link[i]->ex)
			o++;
	i = 1;
	while (o--)
		srcexit(bg, i++, 1, -1);
	rightway(bg, 0, 0, 0);
	trueway(bg, 0, 0, 1);
	ft_theway(lm, a, bg, j);
}
