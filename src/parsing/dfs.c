/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:37:08 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 22:05:10 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		dfs(int i, int j, t_mflags *mflags)
{
	const int	g_dirx[4] = {-1, 0, 1, 0};
	const int	g_diry[4] = {0, 1, 0, -1};
	int			x;

	if (mflags->cvisited[i][j] == '1' || mflags->cvisited[i][j] == 'x')
		return (1);
	if (mflags->cvisited[i][j] == 0)
		return (0);
	mflags->cvisited[i][j] = 'x';
	x = -1;
	while (++x < 4)
	{
		if ((i + g_dirx[x]) < 0 || i + g_dirx[x] > mflags->row + 1)
			continue ;
		if (j + g_diry[x] < 0 || j + g_diry[x] > mflags->col + 1)
			continue ;
		if (!dfs(i + g_dirx[x], j + g_diry[x], mflags))
			return (0);
	}
	return (1);
}

char	**ft_char_map_malloc(t_mflags *mflags)
{
	char	**cvisited;
	int		i;

	i = -1;
	cvisited = (char **)calloc(sizeof(char *), (mflags->row + 2));
	if (!cvisited)
		return (NULL);
	while (++i < mflags->row + 2)
	{
		cvisited[i] = (char *)calloc(sizeof(char), mflags->col + 2);
		if (!cvisited[i])
		{
			free_map_char(mflags->row + 2, mflags->cvisited);
			return (NULL);
		}
	}
	return (cvisited);
}

void	ft_map_copy(t_mflags *mflags)
{
	char	**cvisited;
	int		i;
	int		j;

	cvisited = ft_char_map_malloc(mflags);
	i = 0;
	while (++i <= mflags->row)
	{
		j = 0;
		while (++j <= mflags->col)
		{
			if (mflags->map[i - 1][j - 1] == 9)
				continue ;
			if (mflags->map[i - 1][j - 1] >= NORTH)
			{
				if (mflags->map[i - 1][j - 1] <= WEST)
				{
					mflags->x = i;
					mflags->y = j;
				}
			}
			cvisited[i][j] = mflags->map[i - 1][j - 1] + '0';
		}
	}
	mflags->cvisited = cvisited;
}

void	ft_map_visited(t_mflags *mflags)
{
	ft_map_copy(mflags);
	if (!dfs(mflags->x, mflags->y, mflags))
	{
		free_map_char(mflags->row + 2, mflags->cvisited);
		ft_return_error("Map wall not closed\n");
	}
	free_map_char(mflags->row + 2, mflags->cvisited);
}
