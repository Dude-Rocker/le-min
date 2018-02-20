/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le-min.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/20 23:32:42 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef	struct		s_lm
{
	char			*nm;
	int				place;
	int				x;
	int				y;
	int				ex;
	int				way;
	int				ant[2];
	struct s_lm		*next;
	struct s_lm		**link;
}					t_lm;

void				outerror(char *s, int j, int i);
void				ft_allfree(t_lm *lm, char *s, int o);
int					writelink(t_lm *lm, char **s);
void				ft_theway(t_lm *lm, int cn, int i, int *j);

#endif
