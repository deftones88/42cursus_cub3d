/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:46:21 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:46:23 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

static void	ft_copy_dir(t_parse *p, t_game *game)
{
	if (p->m.dir == NORTH)
	{
		game->p.dirx = -1;
		game->p.diry = 0;
		game->p.planey = PLANE;
	}
	else if (p->m.dir == SOUTH)
	{
		game->p.dirx = 1;
		game->p.diry = 0;
		game->p.planey = -PLANE;
	}
	else if (p->m.dir == EAST)
	{
		game->p.dirx = 0;
		game->p.diry = 1;
		game->p.planex = PLANE;
	}
	else if (p->m.dir == WEST)
	{
		game->p.dirx = 0;
		game->p.diry = -1;
		game->p.planex = -PLANE;
	}
}

void		ft_copy_info(t_parse *p, t_game *game, int argc)
{
	game->save = argc;
	game->bonus = p->e.bonus;
	game->e = p->e.b;
	game->map_col = p->m.col;
	game->map_row = p->m.row;
	game->p.planex = 0;
	game->p.planey = 0;
	game->map = p->m.map;
	game->p.x = p->m.x - 0.5;
	game->p.y = p->m.y - 0.5;
	ft_copy_dir(p, game);
	game->c = p->c;
	mlx_get_screen_size(game->mlx, &game->sizex, &game->sizey);
	if (game->c.width > game->sizey)
		game->c.width = game->sizey;
	if (game->c.height > game->sizex)
		game->c.height = game->sizex;
	game->sp_total = p->m.sp_total;
	game->mouse_x = 0;
	game->mouse_y = 0;
	ft_get_sp(game);
	if (game->bonus)
		ft_bonus_init(game);
}

void		tex_init(t_game *game)
{
	int	i;

	i = -1;
	game->buf = (int **)calloc(sizeof(int *), game->c.height);
	if (!game->buf)
		return ;
	while (++i < game->c.height)
	{
		game->buf[i] = (int *)calloc(sizeof(int), game->c.width);
		if (!game->buf[i])
			ft_free_int_map(game->buf, game->c.height);
	}
	i = -1;
	while (++i < T_TOTAL)
		game->t[i].img.img = NULL;
}

void		window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_return_error("Failed to initialize mlx\n");
	game->win = mlx_new_window(game->mlx, game->c.width, game->c.height,
		WINDOW_TITLE);
	if (!game->win)
		ft_return_error("Failed to set new window\n");
}

void		img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->c.width, game->c.height);
	if (!game->img.img)
		ft_return_error("Failed to assign image\n");
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
		&game->img.size_l, &game->img.endian);
}
