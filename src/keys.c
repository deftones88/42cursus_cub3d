/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:42:37 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:43:03 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int		ft_is_wallsprite(int a)
{
	return (a == WALL || a == SPRITE);
}

void	key_w_s(int keycode, t_game *game)
{
	double	a;
	double	b;

	a = game->p.dirx * M_SPEED;
	b = game->p.diry * M_SPEED;
	if (keycode == KEY_W)
	{
		if (game->map[(int)(game->p.x + a)][(int)game->p.y] != WALL)
			(game->p.x) += (game->p.dirx) * M_SPEED;
		if (game->map[(int)(game->p.x)][(int)(game->p.y + b)] != WALL)
			(game->p.y) += (game->p.diry) * M_SPEED;
	}
	if (keycode == KEY_S)
	{
		if (game->map[(int)(game->p.x - a)][(int)game->p.y] != WALL)
			(game->p.x) -= (game->p.dirx) * M_SPEED;
		if (game->map[(int)(game->p.x)][(int)(game->p.y - b)] != WALL)
			(game->p.y) -= (game->p.diry) * M_SPEED;
	}
}

void	key_a_d(int keycode, t_game *game)
{
	double	a;
	double	b;

	a = game->p.dirx * M_SPEED;
	b = game->p.diry * M_SPEED;
	if (keycode == KEY_D)
	{
		if (game->map[(int)(game->p.x + b)][(int)game->p.y] != WALL)
			(game->p.x) += (game->p.diry) * M_SPEED;
		if (game->map[(int)(game->p.x)][(int)(game->p.y - a)] != WALL)
			(game->p.y) -= (game->p.dirx) * M_SPEED;
	}
	if (keycode == KEY_A)
	{
		if (game->map[(int)(game->p.x - b)][(int)game->p.y] != WALL)
			(game->p.x) -= (game->p.diry) * M_SPEED;
		if (game->map[(int)(game->p.x)][(int)(game->p.y + a)] != WALL)
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
		(game->p.dirx) = game->p.dirx * cos(-r) - (game->p.diry) * sin(-r);
		(game->p.diry) = olddirx * sin(-r) + (game->p.diry) * cos(-r);
		(game->p.planex) = game->p.planex * cos(-r)
		- (game->p.planey) * sin(-r);
		(game->p.planey) = oldpx * sin(-r) + (game->p.planey) * cos(-r);
	}
	if (keycode == KEY_ARROW_L)
	{
		(game->p.dirx) = game->p.dirx * cos(r) - (game->p.diry) * sin(r);
		(game->p.diry) = olddirx * sin(r) + (game->p.diry) * cos(r);
		(game->p.planex) = game->p.planex * cos(r)
		- (game->p.planey) * sin(r);
		(game->p.planey) = oldpx * sin(r) + (game->p.planey) * cos(r);
	}
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(keycode, game);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(keycode, game);
	else if (keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		key_l_r(keycode, game);
	return (0);
}
