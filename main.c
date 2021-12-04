/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:57:49 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 20:57:51 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/raycasting.h"

void	ft_run_game(t_game *game, int argc)
{
	if (argc == 3)
		capture_bmp(game);
	else
	{
		if (game->bonus)
		{
			run_bgm();
			mlx_hook(game->win, X_EVENT_MOTION, 1L << 6, &mouse_move, game);
			game->l.start = clock();
		}
		mlx_loop_hook(game->mlx, &main_loop, game);
		mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, game);
		mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 5, &ft_close, game);
		mlx_loop(game->mlx);
	}
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_parse p;
	t_game	game;

	ft_check_arg(argc, argv, &fd);
	fd = parse_gnl(&p, fd);
	if (fd < 0)
		return (-1);
	ft_copy_info(&p, &game, argc);
	window_init(&game);
	img_init(&game);
	tex_init(&game);
	load_texture(&game);
	if (game.bonus)
		ft_i_tex_init(&game);
	ft_run_game(&game, argc);
	return (0);
}

int		ft_close(t_game *game)
{
	if (game->bonus)
		system("killall afplay");
	ft_free_all(game);
	exit(0);
}
