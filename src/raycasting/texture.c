/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:06:46 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:06:49 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_set_drawstart_end(t_game *game)
{
	game->r.lineheight = (int)(game->c.height / game->r.pwall_d);
	game->r.drawstart = (-(game->r.lineheight) / 2) + (game->c.height / 2)
	+ game->fc.pitch;
	if (game->r.drawstart < 0)
		game->r.drawstart = 0;
	game->r.drawend = (game->r.lineheight / 2) + (game->c.height / 2)
	+ game->fc.pitch;
	if (game->r.drawend >= game->c.height)
		game->r.drawend = game->c.height;
}

void	ft_draw_tex(t_game *game, int tex_x, int i, int tex_num)
{
	double	tex_pos;
	int		tex_y;
	int		color;
	int		j;
	double	lum;

	tex_pos = (game->r.drawstart - game->fc.pitch - game->c.height / 2
		+ game->r.lineheight / 2) * game->t[tex_num].step;
	j = game->r.drawstart - 1;
	while (++j < game->r.drawend)
	{
		tex_y = (int)tex_pos & (game->t[tex_num].tex_h - 1);
		tex_pos += game->t[tex_num].step;
		color =
			game->t[tex_num].img.data[game->t[tex_num].tex_h * tex_y + tex_x];
		lum = get_luminosity(game, game->r.pwall_d);
		if (game->bonus)
			game->buf[j][i] = fade_color(color, lum);
		else
			game->buf[j][i] = color;
	}
}

int		ft_set_tex_num(t_game *game)
{
	if (game->r.side)
	{
		if (0 < game->r.raydiry)
			return (T_EAST);
		else
			return (T_WEST);
	}
	else
	{
		if (0 < game->r.raydirx)
			return (T_SOUTH);
		else
			return (T_NORTH);
	}
}

void	ft_set_tex(t_game *game, int i)
{
	int		tex_num;
	double	wallx;
	int		tex_x;

	tex_num = ft_set_tex_num(game);
	game->t[tex_num].step = 1.0 * game->t[tex_num].img.img_height
	/ game->r.lineheight;
	if (!game->r.side)
		wallx = game->p.y + game->r.pwall_d * game->r.raydiry;
	else
		wallx = game->p.x + game->r.pwall_d * game->r.raydirx;
	wallx -= floor(wallx);
	tex_x = (int)(wallx * (double)game->t[tex_num].tex_w);
	if (game->r.side == 0 && game->r.raydirx > 0)
		tex_x = game->t[tex_num].tex_w - tex_x - 1;
	if (game->r.side == 1 && game->r.raydiry < 0)
		tex_x = game->t[tex_num].tex_w - tex_x - 1;
	ft_draw_tex(game, tex_x, i, tex_num);
}
