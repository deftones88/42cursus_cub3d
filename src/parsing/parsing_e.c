/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:34:16 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:34:17 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_check_num(char **temp)
{
	int		i;
	int		j;

	j = -1;
	while (temp[++j])
	{
		i = 0;
		while (ft_isspace(temp[j][i]))
			++i;
		while (ft_isdigit(temp[j][i]))
			++i;
		while (ft_isspace(temp[j][i]))
			++i;
		if (temp[j][i] != 0)
		{
			free_double(temp);
			ft_return_error("Number decription(s) not valid\n");
		}
	}
}

void	free_double(char **temp)
{
	if (temp)
	{
		while (*temp)
			free(*temp++);
		*temp = 0;
	}
}

void	free_map_char(int row, char **temp)
{
	int		i;

	i = -1;
	if (temp)
	{
		while (++i < row)
			free(*temp++);
		*temp = 0;
	}
}

int		parse_e_alpha(char *line, t_eflags *eflags, t_cubinfo *cubinfo)
{
	if (ft_strlen(line) < 3)
		return (1);
	if (eflags->bonus && ft_check_e_bonus(line))
		parse_e_alpha2(line, eflags, cubinfo);
	else if (line[0] == 'R' && line[1] == ' ')
		ft_read_resolution(line + 2, eflags, cubinfo);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, NORTH);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, SOUTH);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, WEST);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, EAST);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_read_texture(line + 2, eflags, cubinfo, SPRITE);
	else if (line[0] == 'F' && line[1] == ' ')
		ft_read_rgb(line + 2, eflags, cubinfo, 1);
	else if (line[0] == 'C' && line[1] == ' ')
		ft_read_rgb(line + 2, eflags, cubinfo, 2);
	else
		return (1);
	return (0);
}

int		parse_e(char *line, t_eflags *eflags, t_cubinfo *cubinfo)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		++i;
	if (ft_isalpha(line[i]))
	{
		if (parse_e_alpha(line + i, eflags, cubinfo))
			return (-1);
	}
	else if (ft_isdigit(line[i]))
	{
		eflags->map_start = 1;
		return (-1);
	}
	else if (i != (int)ft_strlen(line))
		return (-1);
	return (0);
}
