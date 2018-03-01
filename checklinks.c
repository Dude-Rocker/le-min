/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklinks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:30:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/01 14:39:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static	int		le_x_close(t_lm *lm, t_lm *tm, int *yx, int j)
{
	int			i;
	t_lm		*bf;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if (j == 11 && tm->link[i]->x == yx[0] && tm->link[i]->y > yx[1] + 1)
			return (1);
		if ((((!j || j == 3) && tm->link[i]->x >= yx[0]) || (j == 7
			&& tm->link[i]->x > yx[0])) && tm->link[i]->y == yx[1])
		{
			bf = lm;
			while (bf)
			{
				if (bf->y == yx[1] && bf->x < tm->link[i]->x && bf->x > tm->x)
					break ;
				bf = bf->next;
			}
			if (!bf)
				return (1);
		}
		i++;
	}
	return (0);
}

static	int		le_y_close(t_lm *lm, t_lm *tm, int *yx)
{
	int			i;
	t_lm		*bf;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if (tm->link[i]->y > yx[1] && tm->link[i]->x == yx[0])
		{
			bf = lm;
			while (bf)
			{
				if (bf->x == yx[0] && bf->y < tm->link[i]->y && bf->y > tm->y)
					break ;
				bf = bf->next;
			}
			if (!bf)
				return (1);
		}
		i++;
	}
	return (0);
}

static	int		le_y_far(t_lm *lm, t_lm *tm, int *yx, int j)
{
	int			i;
	t_lm		*bf;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if (((i == 10 && tm->link[i]->x < yx[0] && tm->link[i]->y > yx[1] + 1)
			|| (j == 9 && tm->link[i]->y > yx[1] + 1 && tm->link[i]->x == yx[0])
			|| (tm->link[i]->y > yx[1] && ((j == 2 && tm->link[i]->x == yx[0])
			|| ((j == 4 || j == 8) && tm->link[i]->x < yx[0])))))
			return (1);
		if (tm->link[i]->x == yx[0] && (((j == 4 || j == 8) && tm->link[i]->y >
			yx[1]) || (j == 10 && tm->link[i]->y > yx[1] + 1)))
		{
			bf = lm;
			while (bf)
			{
				if (bf->x == yx[0] && bf->y < tm->link[i]->y && bf->y > tm->y)
					return (1);
				bf = bf->next;
			}
		}
		i++;
	}
	return (0);
}

static	int		le_x_far(t_lm *lm, t_lm *tm, int *yx, int j)
{
	int			i;
	t_lm		*bf;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if ((j && tm->link[i]->x == yx[0] && tm->link[i]->y < yx[1]) ||
			(!j && tm->link[i]->x >= yx[0] && tm->link[i]->y > yx[1]))
			return (1);
		if (!j && tm->link[i]->x >= yx[0] && tm->link[i]->y == yx[1])
		{
			bf = lm;
			while (bf)
			{
				if (bf->y == yx[1] && bf->x < tm->link[i]->x && bf->x > tm->x)
					return (1);
				bf = bf->next;
			}
		}
		i++;
	}
	return (0);
}

int				checklinks(t_lm *tm, int *yx, int i, t_lm *sc)
{
	t_lm		*bf;

	bf = tm;
	if (i == 6)
		return (le_x_close(bf, sc, yx, 7));
	while (tm)
	{
		if (tm->x < yx[0] && ((!i && tm->y == yx[1]) || (i == 7 &&
			tm->y == yx[1] + 1)) && le_x_far(bf, tm, yx, i))
			return (1);
		if (i == 1 && tm->y <= yx[1] && tm->x == yx[0] && le_y_close(bf, tm, yx))
			return (1);
		if (((i == 10 && tm->y <= yx[1] && tm->x == yx[0]) || (tm->y < yx[1] &&
			((i == 4 && tm->x == yx[0]) || (i == 2 && tm->x < yx[0]))) ||
			(tm->y == yx[1] && ((i == 8 && tm->x == yx[0]) || (i == 9 && tm->x <
			yx[0])))) && le_y_far(bf, tm, yx, i))
			return (1);
		if (((i == 3 && tm->x < yx[0] && tm->y == yx[1]) || (i == 11 &&
			tm->y <= yx[1] && tm->x < yx[0])) && le_x_close(bf, tm, yx, i))
			return (1);
		if (i == 5 && tm->x == yx[0] && tm->y == yx[1] && le_x_far(bf, tm, yx, 0))
			return (1);
		tm = tm->next;
	}
	return (0);
}
