/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:24:27 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/04 21:06:57 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	if (c > 255 || c < 0)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			break ;
		s++;
	}
	if ((char)c == 0)
		return (s);
	if (*s)
		return (s);
	else
		return (0);
}
