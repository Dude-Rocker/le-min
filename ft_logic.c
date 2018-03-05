/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:28:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/04 00:40:13 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	startend(t_lm *cl, t_lm *bg, t_lm *end, int j)
{
	int			i;
	int			ant;
	int			xy[4];

	i = 0;
	ant = 0;
	while (bg->link[i])
	{
		if (!ft_strcmp(bg->link[i]->nm, end->nm))
		{
			while (ant++ < j)
			{
				ft_printf("L%d-%s", ant, end->nm);
				if (ant < j)
					ft_printf(" ");
			}
			ft_printf("\n\n");
			end->ant[1] = j;
			le_debug(cl, 1, xy, bg);
			ft_allfree(cl, 0, 0, 0);
			exit(1);
		}
		i++;
	}
}

void			ft_creat(t_lm *lm, int i, int j, int k)
{
	if (k)
	{
		lm->vs = 0;
		lm->st = 0;
		lm->sh = 0;
		lm->ants = 0;
		lm->next = 0;
		lm->link = 0;
		lm->color = 0;
		lm->ant[0] = 0;
		lm->ant[1] = 0;
		lm->way[0] = 0;
		lm->way[1] = 0;
		lm->ex = 0;
		return ;
	}
	if (lm->ex && lm->ex <= j)
		return ;
	lm->ex = j;
	j++;
	while (lm->link && lm->link[i])
		ft_creat(lm->link[i++], 0, j, 0);
}

static	int		linkjoin(t_lm *lnm1, t_lm *lnm2, int i)
{
	if (!lnm1->link)
	{
		if (!(lnm1->link = (t_lm **)malloc(sizeof(t_lm *) * 100)))
			return (0);
		lnm1->link[0] = 0;
	}
	if (!lnm2->link)
	{
		if (!(lnm2->link = (t_lm **)malloc(sizeof(t_lm *) * 100)))
			return (0);
		lnm2->link[0] = 0;
	}
	while (lnm1->link[++i])
		if (!ft_strcmp(lnm1->link[i]->nm, lnm2->nm))
			return (1);
	lnm1->link[i] = lnm2;
	lnm1->link[i + 1] = 0;
	i = 0;
	while (lnm2->link[i])
		i++;
	lnm2->link[i] = lnm1;
	lnm2->link[i + 1] = 0;
	return (1);
}

int				writelink(t_lm *lm, char *s, int i)
{
	char		*nm;
	char		*nm2;
	t_lm		*lnm1;
	t_lm		*lnm2;

	lnm1 = 0;
	lnm2 = 0;
	while (s[i] && s[i] != '-')
		i++;
	nm = ft_strsub(s, 0, i);
	nm2 = ft_strdup(s + i + 1);
	while (lm)
	{
		if (!lnm1 && !ft_strcmp(nm, lm->nm))
			lnm1 = lm;
		else if (!lnm2 && !ft_strcmp(nm2, lm->nm))
			lnm2 = lm;
		if (lnm1 && lnm2)
			break ;
		lm = lm->next;
	}
	free(nm);
	free(nm2);
	return (lm ? linkjoin(lnm1, lnm2, -1) : 0);
}

void			ft_logic(int i, t_lm *lm)
{
	t_lm		*bg;
	t_lm		*end;

	bg = lm;
	end = lm;
	if (!lm)
		exit(ft_printf("ERROR\n"));
	while (end && end->place != 3)
		end = end->next;
	if (!end || !end->link)
		ft_allfree(lm, 0, 0, 1);
	ft_creat(end, 0, 0, 0);
	end->ex = 0;
	while (bg && bg->place != 1)
		bg = bg->next;
	if (!bg || !bg->ex)
		ft_allfree(lm, 0, 0, 1);
	bg->ex = 0;
	startend(lm, bg, end, i);
	ft_algoexit(end, i, bg, lm);
	le_debug(lm, 0, 0, bg);
}
