/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_m_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:30:54 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:31:23 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		ft_check_map_char(int bonus, char c)
{
	if (bonus)
		return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '3' || c == '4' || ft_isspace(c));
	else
		return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || ft_isspace(c));
}

int		ft_check_map_int(int c)
{
	return (c == W_SPACE || c == WALL);
}

void	ft_player_num_check(t_mflags *mflags, int is_or)
{
	if (is_or)
	{
		if (mflags->dir >= NORTH + NORTH)
		{
			ft_free_int_map(mflags->map, mflags->row - 1);
			ft_return_error("Too many players\n");
		}
	}
	else
	{
		if (!(mflags->dir))
		{
			ft_free_int_map(mflags->map, mflags->row);
			ft_return_error("No player\n");
		}
	}
}

int		ft_check_map_line(char *line, t_mflags *mflags, int bonus)
{
	int		i;
	int		l;
	int		o;

	i = 0;
	l = ft_strlen(line);
	o = mflags->col;
	while (line[i] && ft_check_map_char(bonus, line[i]))
		i++;
	if (line[i] != '\0')
	{
		ft_free_int_map(mflags->map, mflags->row);
		ft_return_error("Wrong character in map\n");
	}
	++mflags->row;
	if (l > mflags->col)
		mflags->col = l;
	return (o);
}

int		ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i])
		return (1);
	return (0);
}
