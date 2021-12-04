/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_e_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:05:27 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:05:33 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_check_rgb(int a)
{
	if (!(a >= 0 && a <= 255))
		ft_return_error("RGB not within range [0 ~ 255]\n");
}

t_rgb	*ft_rgb_cub_ptr(t_cubinfo *cubinfo, int d)
{
	if (d == 1)
		return (&cubinfo->f);
	else
		return (&cubinfo->c);
}

int		*ft_rgb_flag_ptr(t_eflags *eflags, int d)
{
	if (d == 1)
		return (&eflags->f);
	else
		return (&eflags->c);
}

void	ft_rgb_check_error(int *pflag, char **temp1)
{
	if (*pflag)
	{
		free_double(temp1);
		ft_return_error("Duplicate info for F or C\n");
	}
	else if (!(temp1[0] && temp1[1] && temp1[2]) || temp1[3])
	{
		free_double(temp1);
		ft_return_error("Wrong color input [Format: F 101,214,103]\n");
	}
}

void	ft_read_rgb(char *line, t_eflags *eflags, t_cubinfo *cubinfo, int d)
{
	t_rgb	*pcub;
	int		*pflag;
	char	**temp1;

	pcub = ft_rgb_cub_ptr(cubinfo, d);
	pflag = ft_rgb_flag_ptr(eflags, d);
	temp1 = ft_split(line, ',');
	ft_rgb_check_error(pflag, temp1);
	ft_check_num(temp1);
	pcub->r = ft_atoi(temp1[0]);
	ft_check_rgb(pcub->r);
	pcub->g = ft_atoi(temp1[1]);
	ft_check_rgb(pcub->g);
	pcub->b = ft_atoi(temp1[2]);
	ft_check_rgb(pcub->b);
	free_map_char(3, temp1);
	if (temp1)
		free(temp1);
	*pflag = 1;
	++eflags->total;
	pcub->color = (pcub->r * 256 * 256) + (pcub->g * 256) + pcub->b;
}
