/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:34:27 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:20:06 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s1, char *s2)
{
	int		l;

	l = 1;
	if (s1)
		l = ft_strlen(s1);
	if (s2)
		l += ft_strlen(s2);
	return (l);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*temp;

	i = -1;
	l = ft_len((char *)s1, (char *)s2);
	temp = (char *)malloc(sizeof(char) * l);
	if (!temp)
		return (0);
	if (s1)
		while (s1[++i])
			temp[i] = s1[i];
	l = -1;
	if (s2)
		while (s2[++l])
			temp[i++] = s2[l];
	temp[i] = 0;
	return (temp);
}
