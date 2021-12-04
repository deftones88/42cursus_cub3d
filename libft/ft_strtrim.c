/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:45:29 by ji-kim            #+#    #+#             */
/*   Updated: 2020/10/06 14:01:56 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_yes(char c, char const *set)
{
	int			i;
	int			b;

	i = -1;
	b = 0;
	while (set[++i])
		if (set[i] == c)
		{
			b = 1;
			break ;
		}
	if (b)
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			idx;
	int			j;
	char		*temp;

	i = -1;
	j = -1;
	if (!s1 || !set)
		return (0);
	while (s1[++i])
		if (!ft_yes(s1[i], set))
			break ;
	idx = i;
	i = ft_strlen(s1);
	while (i-- > idx)
		if (!ft_yes(s1[i], set))
			break ;
	temp = (char *)malloc(sizeof(char) * (i - idx + 2));
	if (!temp)
		return (0);
	while (idx + ++j <= i)
		temp[j] = s1[idx + j];
	temp[j] = 0;
	return (temp);
}
