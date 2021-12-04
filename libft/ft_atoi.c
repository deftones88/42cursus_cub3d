/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:58:20 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/04 20:50:22 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	a;
	int sign;

	a = 0;
	sign = 1;
	while (*str == 13 || *str == 12 || *str == 11 ||
			*str == 9 || *str == 10 || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			a = (a * 10) + *str - '0';
		else
			break ;
		str++;
	}
	return (sign * a);
}
