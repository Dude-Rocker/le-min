/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_min.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/21 14:49:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_MIN_H
# define LE_MIN_H

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
void				ft_allfree(t_lm *lm, char *d, char *s, int o);
int					writelink(t_lm *lm, char *s, int i);
void				ft_logic(int i, t_lm *lm);
void				ft_theway(t_lm *lm, int cn, int i, int *j);
void				ft_creat(t_lm *lm, int i, int j, int k);

#endif
