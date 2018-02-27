/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 00:32:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/28 00:27:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	drawlaststr(t_lm *lm, int *xy, char c, int i)
{
	if (!i)
	// {
		ft_printf("%c%c%c\n", (checklinks(lm, xy, 5) ? '_' : ' '),
			(checklinks(lm, xy, 11) ? '|' : c), (checklinks(lm, xy, 11) ? '/' : ' '));
	// 	c = (checklinks(lm, xy, 5) ? '_' : ' ');
	// 	ft_printf("%c\n", c);
	// 	c = (checklinks(lm, xy, 11) ? '|' : c);
	// 	ft_printf("%c\n", c);
	// 	c = (checklinks(lm, xy, 11) ? '/' : ' ');
	// 	ft_printf("%c\n", c);
	// }
	if (i == 1)
	{
		c = (checklinks(lm, xy, 5) ? '_' : ' ');
		ft_printf("%c\n", c);
		c = (checklinks(lm, xy, 11) ? '|' : c);
		ft_printf("%c\n", c);
		c = (checklinks(lm, xy, 11) ? '/' : ' ');
		ft_printf("%c\n", c);
	}
}

static	void	drawlinks(t_lm *lm, int *xy, int x, int y)
{
	char		c;
	char		b;
	int			yx[2];
	int			j;

	yx[0] = x;
	yx[1] = y;
	while (yx[0] <= xy[1] && (j = 8))
	{
		c = (yx[0] < xy[1] && checklinks(lm, yx, 0) ? '_' : ' ');
		b = (checklinks(lm, yx, 1) ? '|' : c);
		ft_printf("%c%c%c", c, b, c);
		if (yx[0] < xy[1])
		{
			if ((checklinks(lm, yx, 5) && (c = '_')) || checklinks(lm, yx, 2))
				ft_printf("%c", '\\');
			else
				ft_printf("%c", c);
			while (j--)
				ft_printf("%c", c);
			ft_printf("   ");
			// drawlaststr(lm, yx, ' ', 0);
		}
		yx[0] += 1;
	}
	ft_printf("\n");
	// drawlaststr(lm, xy, ' ', 1);
}

static	void	printlem(char *t, int i)
{
	int			j;
	char		*s;

	s = ft_strdup(t);
	j = (!i ? (int)ft_strlen(s) - 3 : (int)ft_strlen(s) + ft_nbrlen(i, 1));
	if (j > 7)
	{
		j = (i ? 7 - ft_nbrlen(i, 1) : 10);
		s[j - 1] = '.';
		s[j] = 0;
	}
	j = (i ? 8 - ft_nbrlen(i, 1) - ft_strlen(s) : 11 - ft_strlen(s));
	ft_printf("[%s", s);
	if (i)
		ft_printf(" L-%d", i);
	ft_printf("%-*s", j, "]");
	free(s);
}

static	void	fillixy(t_lm *lm, int *xy, int t)
{
	xy[1] = 0;
	xy[0] = -1;
	xy[3] = 0;
	xy[2] = -1;
	while (lm)
	{
		if (lm->x < xy[0] || xy[0] == -1)
			xy[0] = lm->x;
		if (lm->x > xy[1])
			xy[1] = lm->x;
		if (lm->y < xy[2] || xy[2] == -1)
			xy[2] = lm->y;
		if (lm->y > xy[3])
			xy[3] = lm->y;
		lm = lm->next;
	}
	t = xy[0];
	ft_printf("y\\x");
	while (t <= xy[1])
		ft_printf("   %-12d", t++);
	ft_printf("\n\n");
}

void			le_visual(t_lm *lm, t_lm *tm, int *xy, int min)
{
	fillixy(lm, xy, 0);
	while (xy[2] <= xy[3])
	{
		ft_printf("%-5d", xy[2]);
		min = xy[0];
		while (min <= xy[1])
		{
			tm = lm;
			while (tm)
			{
				if(tm->x == min && tm->y == xy[2])
					break ;
				tm = tm->next;
			}
			if (tm)
				printlem(tm->nm, tm->ant[1]);
			else
				ft_printf("            ");
			ft_printf("   ");
			min++;
		}
		ft_printf("\n     ");
		drawlinks(lm, xy, xy[0], xy[2]);
		xy[2] += 1;
	}
}
