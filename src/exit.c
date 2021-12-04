/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:40:29 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:40:30 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	ft_free_string(t_game *game)
{
	free(game->c.no);
	free(game->c.so);
	free(game->c.we);
	free(game->c.ea);
	free(game->c.s);
	if (game->bonus)
	{
		if (game->c.b.ft)
			free(game->c.b.ft);
		if (game->c.b.ct)
			free(game->c.b.ct);
		if (game->c.b.s2)
			free(game->c.b.s2);
		if (game->c.b.s3)
			free(game->c.b.s3);
	}
}

void	ft_free_all(t_game *game)
{
	ft_free_int_map(game->map, game->map_row);
	ft_free_int_map(game->buf, game->c.height);
	free(game->sp.order);
	free(game->sp.distance);
	free(game->sp.zbuffer);
	if (game->bonus)
		free(game->i_tex);
}

void	ft_init_buf(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->c.height)
	{
		x = -1;
		while (++x < game->c.width)
			game->buf[y][x] = 0;
	}
}
