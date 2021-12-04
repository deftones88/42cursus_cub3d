/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminosity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:01:03 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:02:27 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

double	get_luminosity(t_game *game, double dist)
{
	double	d;

	d = (game->map_row + game->map_col) / 2.0;
	if (dist > d)
		return (0);
	else
		return (1.0 - (dist / d));
}

int		fade_color(int color, double lum)
{
	int		r;
	int		g;
	int		b;

	if (lum < 0)
		lum = 0;
	else if (lum > 1)
		lum = 1;
	decode_color(color, &r, &g, &b);
	return (encode_color((int)(r * lum), (int)(g * lum), (int)(b * lum)));
}

void	decode_color(int color, int *r, int *g, int *b)
{
	*r = (color & 0xFF0000) >> 16;
	*g = (color & 0x00FF00) >> 8;
	*b = (color & 0x0000FF);
}

int		encode_color(int r_lum, int g_lum, int b_lum)
{
	return (r_lum * 256 * 256 + g_lum * 256 + b_lum);
}
