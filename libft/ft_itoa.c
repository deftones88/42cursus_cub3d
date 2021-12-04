/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:33:21 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/11 19:26:27 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*temp;
	int		i;

	i = ft_intlen(n);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	if (n == 0)
		temp[0] = '0';
	else if (n < 0)
		temp[0] = '-';
	temp[i] = 0;
	while (n)
	{
		temp[--i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (temp);
}
