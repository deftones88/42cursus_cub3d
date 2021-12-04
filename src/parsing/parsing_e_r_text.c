/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_e_r_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:38:35 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:38:37 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_read_resolution(char *line, t_eflags *eflags, t_cubinfo *cubinfo)
{
	char	**temp1;

	temp1 = ft_split(line, ' ');
	if (eflags->r)
	{
		free_double(temp1);
		free(temp1);
		ft_return_error("Multiple resolution description\n");
	}
	else if (!(temp1[0] && temp1[1]) || temp1[2])
	{
		free_double(temp1);
		free(temp1);
		ft_return_error("Resolution description error [Format: R 800 500]\n");
	}
	ft_check_num(temp1);
	cubinfo->width = ft_atoi(temp1[0]);
	cubinfo->height = ft_atoi(temp1[1]);
	free_double(temp1);
	free(temp1);
	eflags->r = 1;
	++eflags->total;
}

char	**ft_tex_cub_ptr(t_cubinfo *cubinfo, int d, int bonus)
{
	if (bonus)
	{
		if (d == SPRITE2)
			return (&cubinfo->b.s2);
		if (d == SPRITE3)
			return (&cubinfo->b.s3);
		if (d == E_CEILING)
			return (&cubinfo->b.ct);
		if (d == E_FLOOR)
			return (&cubinfo->b.ft);
	}
	if (d == NORTH)
		return (&cubinfo->no);
	else if (d == SOUTH)
		return (&cubinfo->so);
	else if (d == WEST)
		return (&cubinfo->we);
	else if (d == EAST)
		return (&cubinfo->ea);
	else
		return (&cubinfo->s);
}

int		*ft_tex_flag_ptr(t_eflags *eflags, int d)
{
	if (eflags->bonus)
	{
		if (d == SPRITE2)
			return (&eflags->b.s2);
		if (d == SPRITE3)
			return (&eflags->b.s3);
		if (d == E_CEILING)
			return (&eflags->b.ct);
		if (d == E_FLOOR)
			return (&eflags->b.ft);
	}
	if (d == NORTH)
		return (&eflags->no);
	else if (d == SOUTH)
		return (&eflags->so);
	else if (d == WEST)
		return (&eflags->we);
	else if (d == EAST)
		return (&eflags->ea);
	else
		return (&eflags->s);
}

void	ft_read_texture(char *line, t_eflags *eflags, t_cubinfo *cubinfo, int d)
{
	char	**temp1;
	char	**pcub;
	int		*pflag;

	pcub = ft_tex_cub_ptr(cubinfo, d, eflags->bonus);
	pflag = ft_tex_flag_ptr(eflags, d);
	temp1 = ft_split(line, ' ');
	if (*pflag)
	{
		free_double(temp1);
		free(temp1);
		ft_return_error("Duplicate texture element description\n");
	}
	else if (temp1[1] || !temp1[0])
	{
		free_double(temp1);
		free(temp1);
		ft_return_error("Texture description error\n");
	}
	ft_check_extension(temp1[0], ".xpm", 0);
	*pcub = ft_strdup_filepath(temp1[0]);
	free_double(temp1);
	free(temp1);
	*pflag = 1;
	++eflags->total;
}
