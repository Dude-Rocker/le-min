/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:47:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/22 22:06:58 by vgladush         ###   ########.fr       */
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

void	startend(t_lm *cl, t_lm *bg, t_lm *end, int j)
{
	int	i;
	int	ant;

	i = 0;
	ant = 0;
	while (bg->link[i])
	{
		if (!strcmp(bg->link[i]->nm, end->nm))
		{
			while (ant++ < j)
			{
				ft_printf("L%d-%s", ant, end->nm);
				if (ant < j)
					ft_printf(" ");
			}
			ft_printf("\n");
			ft_allfree(cl, 0, 0, 0);
			exit(1);
		}
		i++;
	}
}
