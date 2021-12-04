/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:05:40 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:22:08 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_return_str(size_t i, unsigned int start)
{
	if (i < start)
		return (ft_strdup(""));
	return (0);
}

static int	ft_set_i(char const *s, unsigned int start)
{
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	ft_return_str(i, start);
	return (ft_strlen(s + start));
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = ft_set_i(s, start);
	if (i <= len)
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (!temp)
			return (0);
		i = -1;
		while (s[start + ++i])
			temp[i] = s[start + i];
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (len + 1));
		if (!temp)
			return (0);
		i = -1;
		while (++i < len)
			temp[i] = s[start + i];
	}
	temp[i] = 0;
	return (temp);
}
