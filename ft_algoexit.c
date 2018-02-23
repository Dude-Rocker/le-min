/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:33:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/23 17:39:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	srcexit(t_lm *lm, int a, int j, int i)
{
	int			p;
	int			m;

	m = 0;
	p = 0;
	while (lm->place != 3)
	{
		while (lm->link[++i])
		{
			if (lm->link[i]->place == 3 || (lm->link[i]->place != 1 &&
				!lm->link[i]->way[1] &&	lm->link[i]->ex &&
				(!m || (lm->link[i]->ex < m))))
			{
				m = lm->link[i]->ex;
				p = i;
			}
		}
		lm->way[0] = j++;
		lm->way[1] = a;
		lm = lm->link[p];
		m = 0;
		i = -1;
	}
}

static	void	rightway(t_lm *lm, int i, int j, t_lm *bg)
{
	int			l;

	while (bg->link[++i])
	{
		lm = bg->link[i];
		l = lm->way[1];
		while (lm && lm->place != 3 &&  !(j = 0))
		{
			lm->way[1] *= -1;
			while (lm->link[j] && lm->link[j]->way[1] != l && lm->link[j]->ex)
				j++;
			lm = lm->link[j];
		}
	}
}

void			ft_algoexit(t_lm *lm, int a, t_lm *bg, int p)
{
	int			j[2];
	int			i;

	j[0] = 1;
	j[1] = 0;
	i = 0;
	while (bg->link[i])
		if (bg->link[i]->ex)
			i++;
	while (i--)
		srcexit(bg, 1, 1, -1);
	// rightway(bg, -1, -1, bg);
	ft_theway(lm, a, 0, j);
}
