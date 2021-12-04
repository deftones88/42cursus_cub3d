/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:00:09 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:00:12 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_eflags_init(t_eflags *eflags)
{
	eflags->r = 0;
	eflags->no = 0;
	eflags->so = 0;
	eflags->we = 0;
	eflags->ea = 0;
	eflags->s = 0;
	eflags->f = 0;
	eflags->c = 0;
	eflags->bonus = 1;
	eflags->b.ft = 0;
	eflags->b.ct = 0;
	eflags->b.s2 = 0;
	eflags->b.s3 = 0;
	eflags->total = 0;
	eflags->map_start = 0;
}

void	ft_mflags_init(t_mflags *mflags)
{
	mflags->col = 0;
	mflags->row = 0;
	mflags->dir = 0;
	mflags->x = 0;
	mflags->y = 0;
	mflags->sp_total = 0;
	mflags->map = 0;
	mflags->cvisited = 0;
}

void	ft_cubinfo_init(t_cubinfo *cubinfo)
{
	cubinfo->width = 0;
	cubinfo->height = 0;
	cubinfo->no = 0;
	cubinfo->so = 0;
	cubinfo->we = 0;
	cubinfo->ea = 0;
	cubinfo->s = 0;
	cubinfo->f.r = 0;
	cubinfo->f.g = 0;
	cubinfo->f.b = 0;
	cubinfo->f.color = 0;
	cubinfo->c.r = 0;
	cubinfo->c.g = 0;
	cubinfo->c.b = 0;
	cubinfo->c.color = 0;
	cubinfo->b.ft = 0;
	cubinfo->b.ct = 0;
	cubinfo->b.s2 = 0;
	cubinfo->b.s3 = 0;
}
