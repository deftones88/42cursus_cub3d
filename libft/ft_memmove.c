/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 09:09:43 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/05 18:34:15 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dest < src)
		while (i < (int)n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	else if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	return (dest);
}
