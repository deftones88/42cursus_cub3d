/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_m_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:32:15 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:32:49 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int			ft_check_map_vspace(t_mflags mflags, int *idx)
{
	int	i;
	int	j;
	int	c;

	j = -1;
	while (++j < mflags.col)
	{
		c = 0;
		i = -1;
		while (++i < mflags.row)
		{
			if (mflags.map[i][j] == W_SPACE)
				c++;
		}
		if (c == mflags.row)
		{
			*idx = j;
			return (1);
		}
	}
	return (0);
}

static int	*ft_map_trim_2(t_mflags *mflags, int ***temp, int i, int idx)
{
	int	j;
	int	k;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (mflags->col - 1));
	if (!tmp)
	{
		ft_free_int_map(*temp, mflags->row);
		return (0);
	}
	j = -1;
	k = -1;
	while (++j < mflags->col)
	{
		if (j == idx && j != mflags->col)
			j++;
		tmp[++k] = mflags->map[i][j];
	}
	return (tmp);
}

void		ft_map_trim(t_mflags *mflags, int idx)
{
	int	i;
	int	**temp;

	i = -1;
	temp = (int **)malloc(sizeof(int *) * mflags->row);
	if (!temp)
		return ;
	while (++i < mflags->row)
		temp[i] = ft_map_trim_2(mflags, &temp, i, idx);
	ft_free_int_map(mflags->map, mflags->row);
	--mflags->col;
	mflags->map = temp;
}
