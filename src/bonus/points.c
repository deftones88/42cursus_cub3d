/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:26:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:26:30 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_check_item(t_game *game)
{
	int		i;

	if (game->map[(int)(game->p.x)][(int)(game->p.y)] == SPRITE3)
	{
		game->map[(int)(game->p.x)][(int)(game->p.y)] = 0;
		i = -1;
		while (++i < game->sp_total)
		{
			if (game->sp.s[i].x == (int)(game->p.x)
			&& game->sp.s[i].y == (int)(game->p.y))
			{
				game->sp.s[i].x = 0;
				game->sp.s[i].y = 0;
			}
		}
		game->item[game->i_num++] = 1;
	}
	if (game->i_num == 4)
		game->l.win = 1;
}

void	ft_item_init(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
		game->item[i] = 0;
	game->i_num = 0;
	game->i_tex = 0;
}

void	ft_item_pixel(t_game *game, int y, int x, int k)
{
	int		color;
	int		i;
	int		j;

	i = -1;
	while (++i < game->i_width)
	{
		j = -1;
		while (++j < game->i_width)
		{
			color = game->i_tex[i * game->i_width + j];
			if ((color & 0x00FFFFFF) != 0)
			{
				if (game->item[k] != 1)
					color = 0xc9b3ba;
				game->img.data[(y + i) * game->c.width + x + j] = color;
			}
		}
	}
}

void	ft_i_tex_init(t_game *game)
{
	t_img		img;
	int			x;
	int			y;

	img.img = mlx_xpm_file_to_image(game->mlx, "textures/bonus/jelly_40.xpm",
	&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l,
		&img.endian);
	game->i_width = img.img_width;
	game->i_tex = (int *)malloc(sizeof(int) * (img.img_width
			* img.img_height));
	x = -1;
	while (++x < img.img_height)
	{
		y = -1;
		while (++y < img.img_width)
			game->i_tex[x * img.img_width + y] =
				img.data[img.img_width * x + y];
	}
	mlx_destroy_image(game->mlx, img.img);
}

void	ft_draw_item(t_game *game)
{
	int		k;
	int		x;

	k = -1;
	while (++k < 4)
	{
		x = game->hud.width + 20 + k * (game->i_width + 10);
		ft_item_pixel(game, 10, x, k);
	}
}
