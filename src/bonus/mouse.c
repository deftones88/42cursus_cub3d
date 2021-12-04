/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:26:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:26:30 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

static void	ft_mouse_middle(int x, t_game *game)
{
	double	olddirx;
	double	oldplanex;
	double	r;

	r = R_SPEED / 10;
	olddirx = (game->p.dirx);
	oldplanex = (game->p.planex);
	if (x < game->mouse_x)
	{
		(game->p.dirx) = (game->p.dirx) * cos(r) - (game->p.diry) * sin(r);
		(game->p.diry) = olddirx * sin(r) + (game->p.diry) * cos(r);
		(game->p.planex) = oldplanex * cos(r) - (game->p.planey) * sin(r);
		(game->p.planey) = oldplanex * sin(r) + (game->p.planey) * cos(r);
	}
	else
	{
		(game->p.dirx) = (game->p.dirx) * cos(-r) - (game->p.diry) * sin(-r);
		(game->p.diry) = olddirx * sin(-r) + (game->p.diry) * cos(-r);
		(game->p.planex) = oldplanex * cos(-r) - (game->p.planey) * sin(-r);
		(game->p.planey) = oldplanex * sin(-r) + (game->p.planey) * cos(-r);
	}
}

static void	ft_mouse_outerl(int x, int y, t_game *game)
{
	double	olddirx;
	double	oldplanex;
	double	r;

	r = R_SPEED / 10;
	if (y != game->mouse_y && x != game->mouse_x)
	{
		olddirx = (game->p.dirx);
		(game->p.dirx) = (game->p.dirx) * cos(r) - (game->p.diry) * sin(r);
		(game->p.diry) = olddirx * sin(r) + (game->p.diry) * cos(r);
		oldplanex = (game->p.planex);
		(game->p.planex) = oldplanex * cos(r) - (game->p.planey) * sin(r);
		(game->p.planey) = oldplanex * sin(r) + (game->p.planey) * cos(r);
	}
}

static void	ft_mouse_outerr(int x, int y, t_game *game)
{
	double	olddirx;
	double	oldplanex;
	double	r;

	r = -R_SPEED / 10;
	if (y != game->mouse_y && x != game->mouse_x)
	{
		olddirx = (game->p.dirx);
		(game->p.dirx) = (game->p.dirx) * cos(r) - (game->p.diry) * sin(r);
		(game->p.diry) = olddirx * sin(r) + (game->p.diry) * cos(r);
		oldplanex = (game->p.planex);
		(game->p.planex) = oldplanex * cos(r) - (game->p.planey) * sin(r);
		(game->p.planey) = oldplanex * sin(r) + (game->p.planey) * cos(r);
	}
}

int			mouse_move(int x, int y, t_game *game)
{
	int		unit;

	unit = game->c.width / 6;
	if (y > 0 && y < game->c.height)
	{
		if (x > unit && x < game->c.width - unit)
			ft_mouse_middle(x, game);
		else if (x > 0 && x < unit)
			ft_mouse_outerl(x, y, game);
		else if (x > game->c.width - unit && x < game->c.width)
			ft_mouse_outerr(x, y, game);
	}
	game->mouse_x = x;
	game->mouse_y = y;
	return (0);
}
