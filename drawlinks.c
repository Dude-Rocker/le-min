/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:14:32 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/19 01:11:35 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		checkfar(t_lm *tm, int *yx, int j, int i)
{
	while (tm->link && tm->link[i])
	{
		if ((!j || j == 1) && tm->link[i]->x < yx[0] && tm->link[i]->y < yx[1])
			return (1);
		if (((j == 2 && tm->link[i]->y > yx[1] + 1) || (j == 5 &&
			tm->link[i]->y < yx[1])) && tm->link[i]->x == yx[0])
			return (1);
		if ((((j == 3 || j == 8) && tm->link[i]->x > yx[0]) || (j == 4 &&
			tm->link[i]->x < yx[0])) && tm->link[i]->y <= yx[1])
			return (1);
		if (j == 6 && ((tm->link[i]->x >= yx[0] && tm->link[i]->y == yx[1]) ||
			(tm->link[i]->x > yx[0] && tm->link[i]->y < yx[1])))
			return (1);
		if (j == 7 && tm->link[i]->x > yx[0] && tm->link[i]->y <= yx[1])
			return (1);
		i++;
	}
	return (0);
}

static	int		farlinks(t_lm *tm, int *yx, int i)
{
	while (tm)
	{
		if (!i && tm->x == yx[0] && tm->y > yx[1] && checkfar(tm, yx, i, 0))
			return (1);
		if (i == 1 && tm->x == yx[0] && tm->y > yx[1] + 1 &&
			checkfar(tm, yx, i, 0))
			return (1);
		if (((i == 2 && tm->y == yx[1]) || (i == 5 && tm->y == yx[1] + 1)) &&
			tm->x < yx[0] && checkfar(tm, yx, i, 0))
			return (1);
		if ((((i == 3 || i == 4) && tm->x == yx[0]) || (i == 8 && tm->x <=
			yx[0])) && tm->y == yx[1] + 1 && checkfar(tm, yx, i, 0))
			return (1);
		if ((i == 6 || i == 7) && tm->x < yx[0] && tm->y == yx[1] + 1 &&
			checkfar(tm, yx, i, 0))
			return (1);
		tm = tm->next;
	}
	return (0);
}

void			dreelinks(t_lm *lm, int *xy, int i, char c)
{
	if (!i && (c = (checklinks(lm, xy, 0) ? '-' : ' ')))
		ft_printf("%c%c%c", c, (farlinks(lm, xy, 0) ||
			checklinks(lm, xy, 1) ? '|' : c), c);
	if (i == 1)
	{
		c = (checklinks(lm, xy, 8) || farlinks(lm, xy, 6) ? '_' : ' ');
		ft_printf("%c", (farlinks(lm, xy, 5) ? '/' : c));
		ft_printf("%c", (farlinks(lm, xy, 0) ||
			checklinks(lm, xy, 2) ? '|' : c));
		c = (checklinks(lm, xy, 12) || farlinks(lm, xy, 6) ? '_' : ' ');
		ft_printf("%c", (checklinks(lm, xy, 7) ? '/' : c));
	}
	if (i == 2)
	{
		ft_printf("%c", (farlinks(lm, xy, 2) ? '\\' : ' '));
		ft_printf("%c", (checklinks(lm, xy, 5) ||
			farlinks(lm, xy, 1) ? '|' : ' '));
		ft_printf("%c", (checklinks(lm, xy, 11) ||
			farlinks(lm, xy, 4) ? '\\' : ' '));
	}
}

static	void	dralisec(t_lm *lm, int *xy)
{
	int			yx[2];

	yx[0] = xy[0];
	yx[1] = xy[2];
	if (xy[2] == xy[3])
		ft_printf("\n");
	else
	{
		ft_printf("\n     ");
		while (yx[0] <= xy[1])
		{
			dreelinks(lm, yx, 2, 48);
			ft_printf(" %c ", (checklinks(lm, yx, 4) ? '|' : ' '));
			ft_printf("%c        ", (farlinks(lm, yx, 3) ? '/' : ' '));
			yx[0] += 1;
		}
	}
	ft_printf("\n");
}

void			drawlinks(t_lm *lm, int *xy)
{
	char		c;
	char		b;
	int			yx[2];
	int			j;

	b = 48;
	yx[0] = xy[0];
	yx[1] = xy[2];
	while (yx[0] <= xy[1])
	{
		j = 8;
		dreelinks(lm, yx, 1, 48);
		c = (yx[0] < xy[1] && (checklinks(lm, yx, 9) ||
			farlinks(lm, yx, 7)) ? '_' : ' ');
		ft_printf("%c%c%c", c, (checklinks(lm, yx, 4) ? '|' : c), c);
		b = (checklinks(lm, yx, 10) ? '\\' : c);
		ft_printf("%c", b);
		c = (b == '\\' || farlinks(lm, yx, 8) ? '_' : c);
		while (j--)
			ft_printf("%c", c);
		yx[0] += 1;
	}
	dralisec(lm, xy);
}
