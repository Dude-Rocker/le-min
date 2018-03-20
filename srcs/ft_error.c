/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:47:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/19 01:15:37 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			outerror(char *s, int j, int i)
{
	char	*ln;

	ln = s;
	while (*ln == '#')
	{
		ft_printf("%s\n", ln);
		if (!ft_strcmp("##start", ln) || !ft_strcmp("##end", ln))
		{
			free(ln);
			exit(ft_printf("ERROR\n"));
		}
		free(ln);
		get_next_line(0, &ln);
	}
	ft_printf("%s\n", ln);
	j = ft_atoi(ln);
	while (ln[i] && ln[i] > 47 && ln[i] < 58)
		i++;
	if (ln[i] || j < 1)
	{
		free(ln);
		exit(ft_printf("ERROR\n"));
	}
	free(ln);
	return (j);
}

void		ft_allfree(t_lm *lm, char *d, char *s, int o)
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

void		le_debug(t_lm *lm, int f, int *xy, t_lm *bg)
{
	if (f && lm->vs)
		le_visual(lm, lm, xy, 0);
	if (lm->ants)
		ft_printf("There were ants: %s%d%s\n", (lm->clr ? RD : WT),
			lm->ants, WT);
	if (f && lm->st)
		ft_printf("Only one step: %sstart%s-%sfinish%s\n", (lm->clr ? BL : ""),
			WT, (lm->clr ? GR : ""), WT);
	if (!f && lm->st)
		ft_printf("Total steps: %s%d%s\n", (lm->clr ? YL : WT), lm->st - 1, WT);
	if (lm->sh)
		ft_printf("Shortest path: ");
	while (lm->sh && bg->plc != 3)
	{
		f = 0;
		ft_printf("%s%s[%s] %s>>> ", (lm->clr ? YL : WT), (lm->clr &&
			bg->plc == 1 ? BL : ""), bg->nm, WT);
		while (bg->link[f]->plc != 3 && (bg->link[f]->way[1] != 1 ||
			(bg->link[f]->ex > bg->ex && bg->plc != 1)))
			f++;
		bg = bg->link[f];
	}
	if (lm->sh)
		ft_printf("%s[%s]%s\n", (lm->clr ? GR : WT), bg->nm, WT);
}

void		le_flags(int i, char **b, t_lm *lm, int a)
{
	if (!lm)
		exit(ft_printf("ERROR\n"));
	write(1, "\n", 1);
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
		if (!ft_strcmp(b[i], "-color"))
			lm->clr = 1;
		if (!ft_strcmp(b[i], "-sbs"))
			lm->sbs = 1;
	}
}
