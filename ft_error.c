/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:47:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/03 20:05:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void	outerror(char *s, int j, int i)
{
	while (s[i] && s[i] > 47 && s[i] < 58)
		i++;
	if (s[i] || j < 1)
	{
		free(s);
		exit(ft_printf("ERROR\n"));
	}
	free(s);
}

void	ft_allfree(t_lm *lm, char *d, char *s, int o)
{
	if (lm->next)
		ft_allfree(lm->next, 0, 0, 0);
	if (lm->nm)
		free(lm->nm);
	if (s)
		free(s);
	if (d)
		free(d);
	if (lm->link)
		free(lm->link);
	if (lm->next)
		free(lm->next);
	if (o)
		exit(ft_printf("ERROR\n"));
}

void	le_debug(t_lm *lm, int f, int *xy, t_lm *bg)
{
	if (f && lm->vs)
		le_visual(lm, lm, xy, 0);
	if (lm->ants)
		ft_printf("There were ants: %d\n", lm->ants);
	if (f && lm->st)
		ft_printf("Only one step: start-finish\n");
	if (!f && lm->st)
		ft_printf("Total steps: %d\n", lm->st - 1);
	if (lm->sh)
		ft_printf("Shortest path: ");
	while (lm->sh && bg->place != 3)
	{
		f = 0;
		ft_printf("[%s] >>> ", bg->nm);
		while (bg->link[f]->place != 3 && (bg->link[f]->way[1] != 1 ||
			(bg->link[f]->ex > bg->ex && bg->place != 1)))
			f++;
		bg = bg->link[f];
		if (!bg)
			exit(printf("asdfsfd\n"));
	}
	if (lm->sh)
		ft_printf("[%s]\n", bg->nm);
}

void	le_flags(int i, char **b, t_lm *lm, int a)
{
	if (i < 2)
		return ;
	while (--i)
	{
		if (!ft_strcmp(b[i], "-visual"))
			lm->vs = 1;
		if (!ft_strcmp(b[i], "-steps"))
			lm->st = 1;
		if (!ft_strcmp(b[i], "-short"))
			lm->sh = 1;
		if (!ft_strcmp(b[i], "-ants"))
			lm->ants = a;
	}
}
