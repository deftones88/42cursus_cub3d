/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:41:53 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:41:54 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	while ((*str1 || *str2))
		if (*str1++ != *str2++)
			return ((unsigned char)*--str1 - (unsigned char)*--str2);
	return (0);
}

int		ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

char	*ft_strdup_filepath(const char *str)
{
	char	*temp;
	int		i;
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\r')
		len++;
	temp = (char *)calloc(sizeof(char), (len + 1));
	if (!temp)
		return (0);
	i = -1;
	while (++i < len)
		temp[i] = str[i];
	return (temp);
}
