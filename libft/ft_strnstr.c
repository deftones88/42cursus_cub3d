/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:18:35 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/07 19:06:00 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsrch(const char *str1, const char *str2)
{
	while (*str2)
		if (*str2++ != *str1++)
			return (0);
	return (1);
}

char		*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str2[i])
		i++;
	if (!*str2)
		return ((char *)str1);
	while (*str1 && n)
	{
		if (ft_strsrch(str1, str2) && i <= n)
			return ((char *)str1);
		n--;
		str1++;
	}
	return (0);
}
