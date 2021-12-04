/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:23:33 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/04 20:30:07 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}
