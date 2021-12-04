/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:34:10 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/06 11:52:31 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	l;

	l = n;
	if (n < 0)
	{
		l *= -1;
		c = '-';
		write(fd, &c, 1);
	}
	if (l < 10)
	{
		c = l + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putnbr_fd(l % 10, fd);
	}
}
