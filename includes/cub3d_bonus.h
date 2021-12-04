/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:43:42 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:44:06 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "./lifebar.h"
# include "./hud.h"

typedef struct	s_ebonus
{
	int		ft;
	int		ct;
	int		s2;
	int		s3;
}				t_ebonus;

typedef struct	s_cbonus
{
	char	*ft;
	char	*ct;
	char	*s2;
	char	*s3;
}				t_cbonus;

typedef struct	s_fcbonus
{
	double	dist;
	double	floorx;
	double	floory;
	double	raydir_x0;
	double	raydir_y0;
	double	stepx;
	double	stepy;
	double	lum;
	double	pitch;
	int		imgx;
	int		imgy;
	int		is_floor;
}				t_fcbonus;

#endif
