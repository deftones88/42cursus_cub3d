/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:50:02 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:51:31 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct	s_sprite
{
	int			x;
	int			y;
	int			tex;
	int			udiv;
	int			vdiv;
	double		vmove;
}				t_sprite;

typedef struct	s_sprite_render
{
	double		transx;
	double		transy;
	int			screenx;
	int			mscreen;
	int			s_height;
	int			drawsy;
	int			drawey;
	int			s_width;
	int			drawsx;
	int			drawex;
}				t_sp_r;

typedef struct	s_sppack
{
	int			*order;
	double		lum;
	double		*distance;
	double		*zbuffer;
	t_sprite	*s;
	t_sp_r		v;
}				t_sppack;

#endif
