/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:26:41 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:34:50 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/raycasting.h"

void	image_draw(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->c.height)
	{
		j = -1;
		while (++j < game->c.width)
			game->img.data[(int)floor(i) * game->c.width + (int)floor(j)] =
			game->buf[i][j];
	}
	if (game->bonus)
	{
		ft_draw_hud(game);
		ft_draw_item(game);
		ft_draw_life(game);
	}
	if (game->save == 3)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	load_image(t_game *game, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width,
		&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
		&img->endian);
}

void	load_texture(t_game *game)
{
	int		i;

	load_image(game, game->c.no, &game->t[T_NORTH].img);
	load_image(game, game->c.so, &game->t[T_SOUTH].img);
	load_image(game, game->c.ea, &game->t[T_EAST].img);
	load_image(game, game->c.we, &game->t[T_WEST].img);
	load_image(game, game->c.s, &game->t[T_SPRITE].img);
	if (game->bonus)
	{
		if (game->e.s2)
			load_image(game, game->c.b.s2, &game->t[T_SPRITE2].img);
		if (game->e.ct)
			load_image(game, game->c.b.ct, &game->t[T_CEILING].img);
		if (game->e.ft)
			load_image(game, game->c.b.ft, &game->t[T_FLOOR].img);
		if (game->e.s3)
			load_image(game, game->c.b.s3, &game->t[T_SPRITE3].img);
	}
	i = -1;
	while (++i < T_TOTAL)
	{
		game->t[i].tex_w = game->t[i].img.img_width;
		game->t[i].tex_h = game->t[i].img.img_height;
	}
	ft_free_string(game);
}

int		main_loop(t_game *game)
{
	if (game->bonus && (game->l.timeout || game->l.win))
	{
		if (game->l.win)
			ft_draw_win(game);
		else
			ft_draw_end(game);
	}
	else
	{
		ray_loop(game);
		ft_draw_sp(game);
		game->l.curr = clock();
		image_draw(game);
		ft_init_buf(game);
	}
	return (0);
}
