/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_m_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:39:11 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:39:13 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	ft_convert_map_dir(t_mflags *mflags, int dir)
{
	if (dir == NORTH)
		mflags->dir += NORTH;
	else if (dir == SOUTH)
		mflags->dir += SOUTH;
	else if (dir == EAST)
		mflags->dir += EAST;
	else if (dir == WEST)
		mflags->dir += WEST;
	return (dir);
}

static int	ft_convert_map_alpha(char c, t_mflags *mflags)
{
	if (c == 'N')
		return (ft_convert_map_dir(mflags, NORTH));
	else if (c == 'S')
		return (ft_convert_map_dir(mflags, SOUTH));
	else if (c == 'E')
		return (ft_convert_map_dir(mflags, EAST));
	else if (c == 'W')
		return (ft_convert_map_dir(mflags, WEST));
	else
		return (W_SPACE);
}

int			*ft_convert_map(char *line, t_mflags *mflags, int o)
{
	int		i;
	int		*mline;

	i = -1;
	o = ft_strlen(line);
	mline = (int *)calloc(sizeof(int), mflags->col);
	if (!mline)
		return (0);
	while (++i < mflags->col)
	{
		if (i < o && ft_isdigit(line[i]))
		{
			mline[i] = line[i] - '0';
			if (mline[i] == SPRITE || mline[i] == SPRITE2
				|| mline[i] == SPRITE3)
				mflags->sp_total++;
		}
		else if (i < o && ft_isalpha(line[i]))
			mline[i] = ft_convert_map_alpha(line[i], mflags);
		else
			mline[i] = W_SPACE;
		ft_player_num_check(mflags, 1);
	}
	return (mline);
}

static int	*ft_map_temp2(t_mflags *mflags, int ***temp, int i, int o)
{
	int		*tmp;
	int		j;

	tmp = (int *)ft_calloc(sizeof(int), (mflags->col));
	if (!tmp)
	{
		ft_free_int_map(*temp, mflags->row);
		return (0);
	}
	j = -1;
	while (++j < o && j < mflags->col)
		tmp[j] = mflags->map[i][j];
	if (j != mflags->col)
	{
		while (j < mflags->col)
			tmp[j++] = W_SPACE;
	}
	return (tmp);
}

int			**ft_map_temp(char *line, t_mflags *mflags, int o)
{
	int		**temp;
	int		i;

	i = -1;
	temp = (int **)malloc(sizeof(int *) * (mflags->row));
	if (!temp)
		return (0);
	while (++i < mflags->row - 1)
		temp[i] = ft_map_temp2(mflags, &temp, i, o);
	temp[i] = ft_convert_map(line, mflags, o);
	return (temp);
}
