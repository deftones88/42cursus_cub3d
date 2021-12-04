/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:03:55 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:03:57 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_e_alpha2(char *line, t_eflags *eflags, t_cubinfo *cubinfo)
{
	if (line[0] == 'S' && line[1] == '2' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, SPRITE2);
	if (line[0] == 'S' && line[1] == '3' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, SPRITE3);
	if (line[0] == 'F' && line[1] == 'T' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, E_FLOOR);
	if (line[0] == 'C' && line[1] == 'T' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, E_CEILING);
}

int		ft_check_e_bonus(char *line)
{
	if (line[0] == 'S' && line[1] == '2' && line[2] == ' ')
		return (1);
	if (line[0] == 'S' && line[1] == '3' && line[2] == ' ')
		return (1);
	if (line[0] == 'F' && line[1] == 'T' && line[2] == ' ')
		return (1);
	if (line[0] == 'C' && line[1] == 'T' && line[2] == ' ')
		return (1);
	else
		return (0);
}
