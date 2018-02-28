/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklinks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:30:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/28 00:05:36 by vgladush         ###   ########.fr       */
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
		if (((!j && tm->link[i]->x >= yx[0]) || (j && tm->link[i]->x > yx[0]))
			&& tm->link[i]->y == yx[1])
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

static	int		le_y_far(t_lm *lm, t_lm *tm, int *yx)
{
	int			i;
	t_lm		*bf;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if (tm->link[i]->x > yx[0] && tm->link[i]->y >= yx[1])
		{
			if (tm->link[i]->y > yx[1])
				return (1);
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

static	int		le_x_far(t_lm *lm, t_lm *tm, int *yx)
{
	int			i;

	i = 0;
	while (tm->link && tm->link[i])
	{
		if (tm->link[i]->x == yx[0] + 1 && tm->link[i]->y > yx[1])
				return (1);
		i++;
	}
	return (0);
}

int				checklinks(t_lm *tm, int *yx, int i)
{
	t_lm		*bf;

	bf = tm;
	while (tm)
	{
		if (!i && tm->x < yx[0] && tm->y == yx[1] && le_x_far(bf, tm, yx))
			return (1);
		if (i == 1 && tm->y <= yx[1] && tm->x == yx[0] && le_y_close(bf, tm, yx))
			return (1);
		if (i == 2 && tm->x <= yx[0] && tm->y < yx[1] && le_y_far(bf, tm, yx))
			return (1);
		if (i == 3 && tm->x < yx[0] && tm->y == yx[1] && le_x_close(bf, tm, yx, 0))
			return (1);
		if (i == 5 && tm->x == yx[0] && tm->y == yx[1] && le_x_far(bf, tm, yx))
			return (1);
		if (i == 6 && tm->x <= yx[0] && tm->y == yx[1] && le_x_close(bf, tm, yx, 1))
			return (1);
		tm = tm->next;
	}
	return (0);
}
