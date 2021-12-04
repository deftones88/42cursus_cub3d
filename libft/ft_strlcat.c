/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:18:41 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/11 14:16:29 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srcl;
	size_t	destl;
	size_t	i;
	size_t	j;

	srcl = ft_strlen(src);
	destl = ft_strlen(dest);
	if (destl >= n)
		return (srcl + n);
	else
	{
		i = 0;
		j = destl;
		while (n - destl - 1 > 0 && src[i])
		{
			dest[j++] = src[i++];
			n--;
		}
		dest[j] = 0;
		return (destl + srcl);
	}
}
