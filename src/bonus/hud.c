/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:12:09 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:04:02 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	draw_rec_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	x *= game->hud.tile_size;
	y *= game->hud.tile_size;
	i = -1;
	while (++i < game->hud.tile_size)
	{
		j = -1;
		while (++j < game->hud.tile_size)
			game->img.data[(y + i) * game->c.width + x + j] = color;
	}
}

void	draw_rec(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->hud.row)
	{
		j = -1;
		while (++j < game->hud.col)
		{
			if (game->map[i][j] == WALL || game->map[i][j] == W_SPACE)
				draw_rec_square(game, j, i, 0x072A4D);
			else if (game->map[i][j] == SPRITE || game->map[i][j] == SPRITE2
			|| game->map[i][j] == SPRITE3)
				draw_rec_square(game, j, i, 0xFCAC5B);
			else
				draw_rec_square(game, j, i, 0xFAE9B9);
		}
	}
}

void	ft_draw_hud(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	draw_rec(game);
	x = (int)floor((game->p.x * game->hud.tile_size)
	- (game->hud.tile_size / 2));
	y = (int)floor((game->p.y * game->hud.tile_size)
	- (game->hud.tile_size / 2));
	i = -1;
	while (++i < game->hud.tile_size)
	{
		j = -1;
		while (++j < game->hud.tile_size)
			game->img.data[(x + i) * game->c.width + y + j] = 0x3f9ab5;
	}
	hud_ray(game, x, y);
}

void	hud_ray(t_game *game, int x, int y)
{
	int		i;

	y = (int)floor(game->p.y * game->hud.tile_size);
	x = (int)floor(game->p.x * game->hud.tile_size);
	i = -1;
	while (++i < game->hud.ray_len)
	{
		game->img.data[(int)(floor(x + i * game->p.dirx) * game->c.width
		+ floor(y + i * game->p.diry))] = 0xff1100;
	}
}
