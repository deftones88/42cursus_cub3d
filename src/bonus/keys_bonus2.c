/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:26:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:26:30 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	key_u_d(int keycode, t_game *game)
{
	if (keycode == KEY_ARROW_U)
	{
		game->fc.pitch += 400 * M_SPEED;
		if (game->fc.pitch > 200)
			game->fc.pitch = 200;
	}
	if (keycode == KEY_ARROW_D)
	{
		game->fc.pitch -= 400 * M_SPEED;
		if (game->fc.pitch < -200)
			game->fc.pitch = -200;
	}
}

void	ft_set_pitch(t_game *game)
{
	int		a;

	if (game->fc.pitch > 0)
	{
		a = game->fc.pitch - 100 * M_SPEED;
		game->fc.pitch = 0;
		if (a > 0)
			game->fc.pitch = a;
	}
	if (game->fc.pitch < 0)
	{
		a = game->fc.pitch + 100 * M_SPEED;
		game->fc.pitch = 0;
		if (a < 0)
			game->fc.pitch = a;
	}
}
