/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:21:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/23 14:30:06 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	int		chvalsec(char *s, int j)
{
	if (s[j] == '-' || s[j] == '+')
		j++;
	if (s[j] < 48 || s[j] > 57)
		return (0);
	while (s[j] && s[j] > 47 && s[j] < 58)
		j++;
	if (s[j] == ' ')
		j++;
	else
		return (0);
	if (s[j] == '-' || s[j] == '+')
		j++;
	if (s[j] < 48 || s[j] > 57)
		return (0);
	while (s[j] && s[j] > 47 && s[j] < 58)
		j++;
	if (s[j])
		return (0);
	return (1);
}

static	int		checkval(char **s, int j, int *i)
{
	*i = (!*i ? 0 : 2);
	while (**s == '#')
	{
		if (*i && !ft_strcmp(*s, "##start") && ++j)
			*i = 1;
		else if (*i && !ft_strcmp(*s, "##end") && ++j)
			*i = 3;
		if (j > 1 || (j > 0 && !*i))
			return (0);
		free(*s);
		get_next_line(0, s);
	}
	if (!**s || **s == 'L' || **s == ' ')
		return (0);
	j = 0;
	while (s[0][j] && s[0][j] != ' ' && s[0][j] != '-')
		j++;
	if (s[0][j] == '-')
		*i = 0;
	else if (*i && s[0][j] == ' ' && j++)
		return (chvalsec(*s, j));
	else if ((!*i && s[0][j] != '-') || (*i && s[0][j] != ' '))
		return (0);
	return (1);
}

static	void	wrvalsec(t_lm *lm, int *xy, char *s, char *nm)
{
	t_lm		*ml;
	t_lm		*st;

	st = lm;
	ml = 0;
	while (lm)
	{
		if ((lm->x == xy[0] && lm->y == xy[1]) || !ft_strcmp(nm, lm->nm)
			|| (xy[2] != 2 && lm->place == xy[2]))
			ft_allfree(st, nm, s, 1);
		ml = lm;
		lm = lm->next;
	}
	if (!(ml->next = (t_lm *)malloc(sizeof(t_lm))))
		return ;
	ml->next->x = xy[0];
	ml->next->y = xy[1];
	ml->next->place = xy[2];
	ml->next->nm = ft_strdup(nm);
	ft_creat(ml->next, 0, 0, 1);
}

static	void	writevalue(t_lm **lm, int i, char *s, int r)
{
	int			xy[3];
	char		*nm;

	while (s[i] && s[i] != ' ')
		i++;
	nm = ft_strsub(s, 0, i);
	xy[0] = ft_atoi(s + i);
	i += ft_nbrlen(xy[0], 1) + 2;
	xy[1] = ft_atoi(s + i);
	xy[2] = r;
	if (!*lm)
	{
		if (!(*lm = (t_lm *)malloc(sizeof(t_lm))))
			return ;
		(*lm)->x = xy[0];
		(*lm)->y = xy[1];
		(*lm)->place = r;
		(*lm)->nm = ft_strdup(nm);
		ft_creat(*lm, 0, 0, 1);
	}
	else
		wrvalsec(*lm, xy, s, nm);
	free(nm);
}

int				main(void)
{
	t_lm		*lm;
	char		*ln;
	int			ants;
	int			i;

	i = 2;
	lm = 0;
	if (get_next_line(0, &ln) < 0)
		exit(ft_printf("ERROR\n"));
	ants = ft_atoi(ln);
	outerror(ln, ants, 0);
	while (!(ln = 0) && get_next_line(0, &ln) > 0)
	{
		if (!*ln || !checkval(&ln, 0, &i) || (!i && !writelink(lm, ln, 0)))
			break ;
		else if (i)
			writevalue(&lm, 0, ln, i);
		free(ln);
	}
	if (ln)
		free(ln);
	ft_logic(ants, lm);
	ft_printf("good\n");
	return (0);
}
