/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:29:43 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:29:45 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_free_int_map(int **map, int row)
{
	int i;
	int ***p;

	i = -1;
	p = &map;
	if (row)
	{
		while (++i < row)
		{
			if ((*p)[i])
				free((*p)[i]);
		}
		free((*p));
	}
}

void	parse_m(char *line, t_mflags *mflags, int bonus)
{
	int		**temp;
	int		o;

	if (!ft_check_line(line))
	{
		ft_free_int_map(mflags->map, mflags->row);
		ft_return_error("New line in map\n");
	}
	o = ft_check_map_line(line, mflags, bonus);
	temp = ft_map_temp(line, mflags, o);
	if (mflags->row > 1)
		ft_free_int_map(mflags->map, mflags->row - 1);
	mflags->map = temp;
}
