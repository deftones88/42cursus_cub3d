/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:05:40 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/07 10:08:38 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	char		*d;
	char		*len;
	const char	*s;

	d = dest;
	len = dest + n;
	s = src;
	if (!d || !s || n < 0)
		return (0);
	while (*s && d < len)
		*d++ = *s++;
	if (d < len)
		*d = 0;
	else if (n > 0)
		d[-1] = 0;
	while (*s)
		s++;
	return ((size_t)(s - src));
}
