/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:14:25 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:03:13 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_set_fc_bonus(t_game *game)
{
	int		i;
	int		j;
	int		color;

	j = -1;
	while (++j < game->c.height)
	{
		ft_set_fc_basics(game, j);
		i = -1;
		while (++i < game->c.width)
		{
			ft_set_imgxy_color(game, &color);
			game->fc.floorx += game->fc.stepx;
			game->fc.floory += game->fc.stepy;
			if (!game->fc.is_floor)
			{
				if (game->e.ct)
					color = game->t[T_CEILING].img.data[game->t[T_CEILING].tex_w
					* game->fc.imgy + game->fc.imgx];
				else
					color = game->c.c.color;
			}
			game->buf[j][i] = fade_color(color, game->fc.lum);
		}
	}
}

void	ft_set_fc_basics(t_game *game, int j)
{
	double	raydir_x1;
	double	raydir_y1;

	game->fc.is_floor = j > game->c.height / 2 + game->fc.pitch;
	game->fc.raydir_x0 = game->p.dirx - game->p.planex;
	game->fc.raydir_y0 = game->p.diry - game->p.planey;
	raydir_x1 = game->p.dirx + game->p.planex;
	raydir_y1 = game->p.diry + game->p.planey;
	if (game->fc.is_floor)
		game->fc.dist = (0.5 * game->c.height)
		/ (j - game->c.height / 2 - game->fc.pitch);
	else
		game->fc.dist = (0.5 * game->c.height)
		/ (game->c.height / 2 - j + game->fc.pitch);
	game->fc.stepx = game->fc.dist * (raydir_x1 - game->fc.raydir_x0)
	/ game->c.width;
	game->fc.stepy = game->fc.dist * (raydir_y1 - game->fc.raydir_y0)
	/ game->c.width;
	game->fc.floorx = game->p.x + game->fc.dist * game->fc.raydir_x0;
	game->fc.floory = game->p.y + game->fc.dist * game->fc.raydir_y0;
	game->fc.lum = get_luminosity(game, game->fc.dist);
}

void	ft_set_imgxy_color(t_game *game, int *color)
{
	if (game->e.ft)
	{
		game->fc.imgx = (int)(game->t[T_FLOOR].tex_w * (game->fc.floorx
			- floor(game->fc.floorx))) & (game->t[T_FLOOR].tex_w - 1);
		game->fc.imgy = (int)(game->t[T_FLOOR].tex_h * (game->fc.floory
			- floor(game->fc.floory))) & (game->t[T_FLOOR].tex_h - 1);
		*color = game->t[T_FLOOR].img.data[game->t[T_FLOOR].tex_w
		* game->fc.imgy + game->fc.imgx];
	}
	else if (game->e.ct)
	{
		game->fc.imgx = (int)(game->t[T_CEILING].tex_w
			* (game->fc.floorx - floor(game->fc.floorx)));
		game->fc.imgy = (int)(game->t[T_CEILING].tex_h
			* (game->fc.floory - floor(game->fc.floory)));
		*color = game->c.f.color;
	}
	else
	{
		game->fc.imgx = (int)(game->p.x + game->fc.dist * game->fc.raydir_x0);
		game->fc.imgy = (int)(game->p.y + game->fc.dist * game->fc.raydir_y0);
		*color = game->c.f.color;
	}
}
