/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:28:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/18 23:46:16 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le-min.h"

int			writelink(t_lm *lm, char **s)
{
	int			xy[3];
	char		*nm;
	char		*nm2;

	while (s[i] && s[i] != '-')
		i++;
	nm = ft_strsub(s, 0, i);
	nm2 = ft_strdup(s + i + 1);
	while (lm)
	{
		if (!ft_strcmp(nm, lm->nm))
		{

			break ;
		}
		else if ()
		{
			
			break ;
		}
		lm = lm->next;
	}
	if (!lm || !ft_strcmp(nm, nm2))
		return (0);
	free(nm);
	free(nm2);
	return (1);
}
