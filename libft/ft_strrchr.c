/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:01:34 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/04 21:09:38 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;

	ret = 0;
	if (c > 255 || c < 0)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			ret = (char *)str;
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (ret);
}
