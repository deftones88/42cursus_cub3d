/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:53:48 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/04 21:26:37 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- && (*str1 || *str2))
		if (*str1++ != *str2++)
			return ((unsigned char)*--str1 - (unsigned char)*--str2);
	return (0);
}
