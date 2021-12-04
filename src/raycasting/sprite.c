/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:06:34 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:06:37 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_sprite_init(t_game *game)
{
	t_sprite	*temp;
	double		*dbl_temp;
	int			*order;

	temp = (t_sprite *)calloc(sizeof(t_sprite), game->sp_total);
	if (!temp)
		return ;
	game->sp.s = temp;
	dbl_temp = (double *)calloc(sizeof(double), game->c.width);
	if (!dbl_temp)
		return ;
	game->sp.zbuffer = dbl_temp;
	dbl_temp = (double *)calloc(sizeof(double), game->sp_total);
	if (!dbl_temp)
		return ;
	game->sp.distance = dbl_temp;
	order = (int *)calloc(sizeof(int), game->sp_total);
	if (!order)
		return ;
	game->sp.order = order;
}

void	ft_parse_sp(t_game *game, int i, int j, int k)
{
	if (game->map[i][j] == SPRITE)
	{
		game->sp.s[k].tex = T_SPRITE;
		game->sp.s[k].udiv = 1;
		game->sp.s[k].vdiv = 1;
		game->sp.s[k].vmove = 0;
	}
	else if (game->map[i][j] == SPRITE2)
	{
		game->sp.s[k].tex = T_SPRITE2;
		game->sp.s[k].udiv = 1;
		game->sp.s[k].vdiv = 1;
		game->sp.s[k].vmove = 0;
	}
	else
	{
		game->sp.s[k].tex = T_SPRITE3;
		game->sp.s[k].udiv = 3;
		game->sp.s[k].vdiv = 3;
		game->sp.s[k].vmove = 0;
	}
}

void	ft_get_sp(t_game *game)
{
	int		i;
	int		j;
	int		k;

	ft_sprite_init(game);
	k = 0;
	i = -1;
	while (++i < game->map_row)
	{
		j = -1;
		while (++j < game->map_col)
		{
			if (game->map[i][j] == SPRITE || game->map[i][j] == SPRITE2
			|| game->map[i][j] == SPRITE3)
			{
				game->sp.s[k].x = i;
				game->sp.s[k].y = j;
				ft_parse_sp(game, i, j, k);
				k++;
			}
		}
	}
}
