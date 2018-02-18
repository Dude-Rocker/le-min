/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le-min.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/18 23:46:56 by vgladush         ###   ########.fr       */
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
	struct s_lm		*next;
	struct s_lm		**link;
}					t_lm;

void				outerror(char *s, int j, int i);
void				ft_allfree(t_lm *lm, char *s, int o);
int					writelink(t_lm *lm, char **s);

#endif
