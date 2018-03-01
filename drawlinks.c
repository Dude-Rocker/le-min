/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:14:32 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/01 14:41:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void			dreelinks(t_lm *lm, int *xy, int i, char c)
{
	if (!i && (c = (checklinks(lm, xy, 3, 0) ? '-' : ' ')))
		ft_printf("%c%c%c", c, (checklinks(lm, xy, 2, 0) ||
			checklinks(lm, xy, 4, 0) ? '|' : c), c);
	if (i == 1)
	{
		c = (checklinks(lm, xy, 0, 0) ? '_' : ' ');
		ft_printf("%c", (checklinks(lm, xy, 7, 0) ? '/' : c));
		ft_printf("%c", (checklinks(lm, xy, 2, 0) ||
			checklinks(lm, xy, 4, 0) ? '|' : c));
		ft_printf("%c", (checklinks(lm, xy, 8, 0) ? '/' : c));
	}
	if (i == 2)
	{
		ft_printf("%c", (checklinks(lm, xy, 9, 0) ? '\\' : ' '));
		ft_printf("%c", (checklinks(lm, xy, 10, 0) ||
			checklinks(lm, xy, 11, 0) ? '|' : ' '));
		// xy[1] -= 1;
		// ft_printf("%c", (checklinks(lm, xy, 10, 0) ||
		// 	checklinks(lm, xy, 11, 0) ? '\\' : ' '));
		// xy[1] += 1;
	}
}

static	void	dralisec(t_lm *lm, int *xy)
{
	char		c;
	char		b;
	int			yx[2];

	yx[0] = xy[0];
	yx[1] = xy[2];
	if (xy[2] == xy[3])
		ft_printf("\n\n");
	else
	{
		ft_printf("\n     ");
		while (yx[0] <= xy[1])
		{
			dreelinks(lm, yx, 2, 48);
			ft_printf("            ");
			// c = (yx[0] < xy[1] && checklinks(lm, yx, 0, 0) ? '\\' : ' ');
			// b = (checklinks(lm, yx, 1, 0) ? '|' : ' ');
			// ft_printf("%c%c%c", c, b, c);
			// ft_printf("%c", (checklinks(lm, yx, 5, 0) && (c = '_')) ? '\\' : c);
			// ft_printf("%c", c);
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

	yx[0] = xy[0];
	yx[1] = xy[2];
	while (yx[0] <= xy[1])
	{
		j = 8;
		dreelinks(lm, yx, 1, 48);
		c = (yx[0] < xy[1] && checklinks(lm, yx, 0, 0) ? '_' : ' ');
		b = (checklinks(lm, yx, 1, 0) ? '|' : c);
		ft_printf("%c%c%c", c, b, c);
		ft_printf("%c", (checklinks(lm, yx, 5, 0) && (c = '_')) ? '\\' : c);
		while (j--)
			ft_printf("%c", c);
		yx[0] += 1;
	}
	dralisec(lm, xy);
}
