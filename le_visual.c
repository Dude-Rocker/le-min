/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 00:32:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/03 18:31:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	void	emptylem(t_lm *lm, int min, int y)
{
	int			j;
	int			yx[2];
	char		c;

	yx[0] = min;
	yx[1] = y;
	dreelinks(lm, yx, 0, 48);
	j = 11;
	c = ((checklinks(lm, yx, 3) ? '-' : ' '));
	write(1, &c, 1);
	ft_printf("%c", (checklinks(lm, yx, 4) ? '|' : c));
	while (--j)
		write(1, &c, 1);
}

static	void	printlem(t_lm *tm, t_lm *lm, int min, int y)
{
	int			i;
	int			j;
	char		*s;
	int			yx[2];

	i = tm->ant[1];
	yx[0] = min;
	yx[1] = y;
	dreelinks(lm, yx, 0, 48);
	s = ft_strdup(tm->nm);
	j = (!i ? (int)ft_strlen(s) - 3 : (int)ft_strlen(s) + ft_nbrlen(i, 1));
	if (j > 7 && (j = (i ? 7 - ft_nbrlen(i, 1) : 10)))
	{
		s[j - 1] = '.';
		s[j] = 0;
	}
	j = (i ? 8 - ft_nbrlen(i, 1) - ft_strlen(s) : 11 - ft_strlen(s));
	ft_printf("[%s", s);
	if (i)
		ft_printf(" %sL-%d%s", (lm->color ? RED : ""), i, (lm->color ? COLOR_RESET : ""));
	ft_printf("%c", ']');
	*s = (checklinks(lm, yx, 3) ? '-' : ' ');
	while (--j)
		write(1, s, 1);
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
	ft_printf("\ny\\x   ");
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
				if (tm->x == min && tm->y == xy[2])
					break ;
				tm = tm->next;
			}
			if (tm)
				printlem(tm, lm, min, xy[2]);
			else
				emptylem(lm, min, xy[2]);
			min++;
		}
		ft_printf("\n     ");
		drawlinks(lm, xy);
		xy[2] += 1;
	}
}
