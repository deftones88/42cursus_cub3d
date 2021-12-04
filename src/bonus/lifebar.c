/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifebar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:12:09 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:04:02 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_draw_life(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		end;

	x = game->c.width - GAUGE_W - 20;
	y = 20;
	end = (GAUGE_W - (game->l.curr - game->l.start) / CLOCKS_PER_SEC * PXMS);
	i = -1;
	while (++i < GAUGE_H)
	{
		j = -1;
		while (++j < end)
			game->img.data[((i + y) * game->c.width) + j + x] = 0xc000fa;
		while (j < GAUGE_W)
			game->img.data[((i + y) * game->c.width) + j++ + x] = 0xb6a6ba;
	}
	if (!end)
		game->l.timeout = 1;
}

void	ft_draw_end(t_game *game)
{
	t_img		img;

	img.img = mlx_xpm_file_to_image(game->mlx, "textures/bonus/lose.xpm",
	&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l,
		&img.endian);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}

void	ft_draw_win(t_game *game)
{
	t_img		img;

	img.img = mlx_xpm_file_to_image(game->mlx, "textures/bonus/win.xpm",
	&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l,
		&img.endian);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}
