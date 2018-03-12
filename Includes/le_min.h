/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_min.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/12 16:50:42 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_MIN_H
# define LE_MIN_H

# include "libft.h"
# define RD "\x1B[35m"
# define YL "\x1B[33m"
# define WT "\x1B[37m"
# define GR "\x1B[32m"
# define BL "\x1B[36m"

typedef	struct		s_lm
{
	int				ants;
	int				clr;
	int				vs;
	int				st;
	int				sh;
	char			*nm;
	int				plc;
	int				x;
	int				y;
	int				ex;
	int				way[2];
	int				ant[2];
	struct s_lm		*next;
	struct s_lm		**link;
}					t_lm;

int					outerror(char *s, int j, int i);
void				ft_allfree(t_lm *lm, char *d, char *s, int o);
int					writelink(t_lm *lm, char *s, int i);
void				ft_logic(int i, t_lm *lm);
void				ft_theway(t_lm *end, t_lm *lm, t_lm *bg, int *j);
void				ft_creat(t_lm *lm, int i, int j, int k);
void				ft_algoexit(t_lm *end, int a, t_lm *bg, t_lm *lm);
void				le_visual(t_lm *lm, t_lm *tm, int *xy, int min);
int					checklinks(t_lm *tm, int *yx, int i);
void				drawlinks(t_lm *lm, int *xy);
void				dreelinks(t_lm *lm, int *xy, int i, char c);
void				le_flags(int i, char **b, t_lm *lm, int a);
void				le_debug(t_lm *lm, int f, int *xy, t_lm *bg);
void				minull(t_lm *bg, int i);

#endif
