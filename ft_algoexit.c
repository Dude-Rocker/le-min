/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:33:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/22 19:56:01 by vgladush         ###   ########.fr       */
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
			if (!m || m > lm->link[i]->ex)
			{
				m = lm->link[i]->ex;
				p = i;
			}
		lm->way[0] = j++;
		lm->way[1] = a;
		lm = lm->link[p];
		m = 0;
	}
}

static	void	rightway(t_lm *lm, int i, int j, t_lm *bg)
{
	int			l;

	while (bg->link[++i])
	{
		lm = bg->link[i];
		l = lm->way[1];
		lm->way[1] *= -1;
		// while (lm->place != 3)
		// {
		// 	while (lm->link[++j] != )
		// }
	}
}

void			ft_algoexit(t_lm *lm, int a, t_lm *bg, int p)
{
	int			j[2];
	int			i;

	j[0] = 1;
	j[1] = 0;
	i = -1;
	srcexit(bg, 1, 1, -1);
	rightway(bg, -1, -1, bg);
	ft_theway(lm, a, 0, j);
}
