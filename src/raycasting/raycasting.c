/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:55:07 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:56:36 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

static void	ft_set_fc(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->c.width)
	{
		j = -1;
		while (++j < game->c.height)
		{
			game->buf[j][i] = game->c.f.color;
			game->buf[game->c.height - j - 1][i] = game->c.c.color;
		}
	}
}

void		ft_set_up(t_game *game, int i)
{
	game->r.camerax = 2 * i / (double)game->c.width - 1;
	game->r.raydirx = game->p.dirx + game->p.planex * game->r.camerax;
	game->r.raydiry = game->p.diry + game->p.planey * game->r.camerax;
	game->r.mapx = (int)(game->p.x);
	game->r.mapy = (int)(game->p.y);
	game->r.delta_dx = fabs(1 / game->r.raydirx);
	game->r.delta_dy = fabs(1 / game->r.raydiry);
	game->r.hit = 0;
}

void		ft_set_side_step(t_game *game)
{
	if (game->r.raydirx < 0)
	{
		game->r.side_dx = (game->p.x - game->r.mapx) * game->r.delta_dx;
		game->r.stepx = -1;
	}
	else
	{
		game->r.side_dx = ((game->r.mapx + 1.0) - game->p.x) * game->r.delta_dx;
		game->r.stepx = 1;
	}
	if (game->r.raydiry < 0)
	{
		game->r.side_dy = (game->p.y - game->r.mapy) * game->r.delta_dy;
		game->r.stepy = -1;
	}
	else
	{
		game->r.side_dy = ((game->r.mapy + 1.0) - game->p.y) * game->r.delta_dy;
		game->r.stepy = 1;
	}
}

void		ft_set_pwalldist(t_game *game)
{
	while (!(game->r.hit))
	{
		if (game->r.side_dx < game->r.side_dy)
		{
			game->r.side_dx += game->r.delta_dx;
			game->r.mapx += game->r.stepx;
			game->r.side = 0;
		}
		else
		{
			game->r.side_dy += game->r.delta_dy;
			game->r.mapy += game->r.stepy;
			game->r.side = 1;
		}
		if (game->map[game->r.mapx][game->r.mapy] == WALL)
			game->r.hit = 1;
	}
	if (game->r.side)
		game->r.pwall_d = (game->r.mapy - game->p.y + ((1 - game->r.stepy) / 2))
		/ game->r.raydiry;
	else
		game->r.pwall_d = (game->r.mapx - game->p.x + ((1 - game->r.stepx) / 2))
		/ game->r.raydirx;
}

void		ray_loop(t_game *game)
{
	int	i;

	if (game->bonus)
		ft_set_fc_bonus(game);
	else
		ft_set_fc(game);
	i = -1;
	while (++i < game->c.width)
	{
		ft_set_up(game, i);
		ft_set_side_step(game);
		ft_set_pwalldist(game);
		ft_set_drawstart_end(game);
		ft_set_tex(game, i);
		game->sp.zbuffer[i] = game->r.pwall_d;
	}
}
