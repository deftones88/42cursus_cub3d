/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:44:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:45:47 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

typedef struct	s_hud
{
	int			col;
	int			row;
	int			width;
	int			height;
	int			tile_size;
	double		ray_len;
}				t_hud;

#endif
