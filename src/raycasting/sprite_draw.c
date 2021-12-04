/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:00:32 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:01:12 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_set_sprite(t_game *game, int o)
{
	double	sx;
	double	sy;
	double	invd;

	sx = (game->sp.s[o].x - game->p.x + 0.5);
	sy = (game->sp.s[o].y - game->p.y + 0.5);
	invd = 1.0 / (game->p.planex * game->p.diry
		- game->p.dirx * game->p.planey);
	game->sp.v.transx = invd * (game->p.diry * sx - game->p.dirx * sy);
	game->sp.v.transy = invd * (-game->p.planey * sx + game->p.planex * sy);
	game->sp.v.screenx = (int)((game->c.width / 2)
	* (1 + game->sp.v.transx / game->sp.v.transy));
	game->sp.v.mscreen = (int)(game->sp.s[o].vmove / game->sp.v.transy)
	+ game->fc.pitch;
}

void	ft_set_sprite_draw(t_game *game, int o)
{
	game->sp.v.s_height = (int)fabs((game->c.height / game->sp.v.transy)
	/ game->sp.s[o].vdiv);
	game->sp.v.drawsy = -game->sp.v.s_height / 2 + game->c.height
	/ 2 + game->sp.v.mscreen;
	if (game->sp.v.drawsy < 0)
		game->sp.v.drawsy = 0;
	game->sp.v.drawey = game->sp.v.s_height / 2 + game->c.height
	/ 2 + game->sp.v.mscreen;
	if (game->sp.v.drawey >= game->c.height)
		game->sp.v.drawey = game->c.height - 1;
	game->sp.v.s_width = (int)fabs((game->c.height / game->sp.v.transy)
	/ game->sp.s[o].udiv);
	game->sp.v.drawsx = -game->sp.v.s_width / 2 + game->sp.v.screenx;
	if (game->sp.v.drawsx < 0)
		game->sp.v.drawsx = 0;
	game->sp.v.drawex = game->sp.v.s_width / 2 + game->sp.v.screenx;
	if (game->sp.v.drawex >= game->c.width)
		game->sp.v.drawex = game->c.width - 1;
}

void	ft_sprite_render_buff(t_game *game, int k, int o)
{
	int		texx;
	int		texy;
	int		j;
	int		color;

	texx = (int)(256 * (k - (-game->sp.v.s_width / 2 + game->sp.v.screenx))
	* game->t[game->sp.s[o].tex].tex_w / game->sp.v.s_width) / 256;
	if (game->sp.v.transy > 0 && k > 0 && k < game->c.width
		&& game->sp.v.transy < game->sp.zbuffer[k])
	{
		j = game->sp.v.drawsy - 1;
		while (++j < game->sp.v.drawey)
		{
			texy = ((((j - game->sp.v.mscreen) * 256 - game->c.height * 128
			+ game->sp.v.s_height * 128) * game->t[game->sp.s[o].tex].tex_h)
			/ game->sp.v.s_height) / 256;
			color = game->t[game->sp.s[o].tex].img.data
			[game->t[game->sp.s[o].tex].tex_w * texy + texx];
			if (game->bonus)
				color = fade_color(color, game->sp.lum);
			if ((color & 0x00FFFFFF) != 0)
				game->buf[j][k] = color;
		}
	}
}

void	ft_draw_sp(t_game *game)
{
	int		i;
	int		k;
	int		o;

	i = -1;
	while (++i < game->sp_total)
	{
		game->sp.order[i] = i;
		game->sp.distance[i] = ((game->p.x - game->sp.s[i].x)
		* (game->p.x - game->sp.s[i].x) + (game->p.y - game->sp.s[i].y)
		* (game->p.y - game->sp.s[i].y));
	}
	ft_sort_sp(game);
	i = -1;
	while (++i < game->sp_total)
	{
		o = game->sp.order[i];
		ft_set_sprite(game, o);
		ft_set_sprite_draw(game, o);
		game->sp.lum = get_luminosity(game, game->sp.distance[i] / 12);
		k = game->sp.v.drawsx - 1;
		while (++k < game->sp.v.drawex)
			ft_sprite_render_buff(game, k, o);
	}
}

void	ft_sort_sp(t_game *game)
{
	int		order;
	double	dist;
	int		i;
	int		j;

	i = -1;
	while (++i < game->sp_total)
	{
		j = -1;
		while (++j < game->sp_total - 1)
		{
			if (game->sp.distance[j] < game->sp.distance[j + 1])
			{
				order = game->sp.order[j];
				game->sp.order[j] = game->sp.order[j + 1];
				game->sp.order[j + 1] = order;
				dist = game->sp.distance[j];
				game->sp.distance[j] = game->sp.distance[j + 1];
				game->sp.distance[j + 1] = dist;
			}
		}
	}
}
