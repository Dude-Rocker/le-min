/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:28:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/21 16:37:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void			ft_creat(t_lm *lm, int i, int j, int k)
{
	if (k)
	{
		lm->next = 0;
		lm->link = 0;
		lm->ant[0] = 0;
		lm->ant[1] = 0;
		lm->way = 0;
		lm->ex = 0;
		return ;
	}
	ft_printf("%s\n", lm->nm);
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
		if (!(lnm1->link = (t_lm **)malloc(sizeof(t_lm *))))
			return (0);
		lnm1->link[i] = 0;
	}
	if (!lnm2->link)
	{
		if (!(lnm2->link = (t_lm **)malloc(sizeof(t_lm *))))
			return (0);
		lnm2->link[i] = 0;
	}
	while (lnm1->link[i])
	{
		if (ft_strcmp(lnm1->link[i]->nm, lnm2->nm))
			return (1);
		i++;
	}
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
		if (!ft_strcmp(nm, lm->nm))
			lnm1 = lm;
		else if (!ft_strcmp(nm2, lm->nm))
			lnm2 = lm;
		lm = lm->next;
	}
	i = (lnm1 && lnm2 && ft_strcmp(nm, nm2) ? 1 : 0);
	free(nm);
	free(nm2);
	return (i ? linkjoin(lnm1, lnm2, 0) : 0);
}

void			ft_logic(int i, t_lm *lm)
{
	t_lm		*cp;

	cp = lm;
	if (!lm)
		exit(ft_printf("ERROR\n"));
	while (cp)
	{
		if (cp->place == 3)
			break ;
		cp = cp->next;
	}
	if (!cp->link)
		ft_allfree(lm, 0, 0, 1);
	ft_creat(cp, 0, 0, 0);
	cp = lm;
	while (cp)
	{
		if (cp->place == 1)
			break ;
		cp = cp->next;
	}
	if (!cp->ex)
		ft_allfree(lm, 0, 0, 1);
	// ft_algoexit(lm, i);
}

