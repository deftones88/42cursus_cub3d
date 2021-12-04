/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:26:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:26:30 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

int		ft_is_wallsprite(int a)
{
	return (a == WALL || a == SPRITE || a == SPRITE2);
}

void	key_w_s(int keycode, t_game *game)
{
	double	x;
	double	y;
	double	py;

	x = game->p.dirx * M_SPEED;
	y = game->p.diry * M_SPEED;
	py = game->p.y;
	if (keycode == KEY_W)
	{
		if (!ft_is_wallsprite(game->map[(int)(game->p.x + x)][(int)py]))
			(game->p.x) += (game->p.dirx) * M_SPEED;
		if (!ft_is_wallsprite(game->map[(int)(game->p.x)][(int)(py + y)]))
			(game->p.y) += (game->p.diry) * M_SPEED;
	}
	if (keycode == KEY_S)
	{
		if (!ft_is_wallsprite(game->map[(int)(game->p.x - x)][(int)py]))
			(game->p.x) -= (game->p.dirx) * M_SPEED;
		if (!ft_is_wallsprite(game->map[(int)(game->p.x)][(int)(py - y)]))
			(game->p.y) -= (game->p.diry) * M_SPEED;
	}
}

void	key_a_d(int keycode, t_game *game)
{
	double	x;
	double	y;
	double	py;

	x = game->p.dirx * M_SPEED;
	y = game->p.diry * M_SPEED;
	py = game->p.y;
	if (keycode == KEY_D)
	{
		if (!ft_is_wallsprite(game->map[(int)(game->p.x + x)][(int)py]))
			(game->p.x) += (game->p.diry) * M_SPEED;
		if (!ft_is_wallsprite(game->map[(int)(game->p.x)][(int)(py - y)]))
			(game->p.y) -= (game->p.dirx) * M_SPEED;
	}
	if (keycode == KEY_A)
	{
		if (!ft_is_wallsprite(game->map[(int)(game->p.x - x)][(int)py]))
			(game->p.x) -= (game->p.diry) * M_SPEED;
		if (!ft_is_wallsprite(game->map[(int)(game->p.x)][(int)(py + y)]))
			(game->p.y) += (game->p.dirx) * M_SPEED;
	}
}

void	key_l_r(int keycode, t_game *game)
{
	double	olddirx;
	double	oldpx;
	double	r;

	olddirx = (game->p.dirx);
	oldpx = (game->p.planex);
	r = R_SPEED;
	if (keycode == KEY_ARROW_R)
	{
		(game->p.dirx) = (game->p.dirx) * cos(-r) - (game->p.diry) * sin(-r);
		(game->p.diry) = olddirx * sin(-r) + (game->p.diry) * cos(-r);
		(game->p.planex) = oldpx * cos(-r) - (game->p.planey) * sin(-r);
		(game->p.planey) = oldpx * sin(-r) + (game->p.planey) * cos(-r);
	}
	if (keycode == KEY_ARROW_L)
	{
		(game->p.dirx) = (game->p.dirx) * cos(r) - (game->p.diry) * sin(r);
		(game->p.diry) = olddirx * sin(r) + (game->p.diry) * cos(r);
		(game->p.planex) = oldpx * cos(r) - (game->p.planey) * sin(r);
		(game->p.planey) = oldpx * sin(r) + (game->p.planey) * cos(r);
	}
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		system("killall afplay");
		ft_free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(keycode, game);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(keycode, game);
	else if (keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		key_l_r(keycode, game);
	else if (keycode == KEY_ARROW_U || keycode == KEY_ARROW_D)
		key_u_d(keycode, game);
	ft_check_item(game);
	ft_set_pitch(game);
	return (0);
}
