/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <ji-kim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:54:25 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:22:59 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int		flag;
	int		n;

	n = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
		if (*s++ == c)
		{
			if (flag == 1)
			{
				n++;
				flag = 0;
			}
		}
		else
			flag = 1;
	if (flag == 1)
		n++;
	return (n);
}

static char	*ft_wlen(int *a, const char *s, char c)
{
	int		i;
	int		k;
	char	*ret;

	i = 0;
	while (s[*a + i] && s[*a + i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	ret[i] = 0;
	*a += i;
	k = 0;
	while (--i >= 0)
		ret[i] = s[*a - ++k];
	return (ret);
}

static int	free_ret(char **ret)
{
	int		n;

	n = 0;
	while (ret[n])
		free(ret[n++]);
	free(ret);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		k;
	int		i;
	int		n;

	n = ft_wcount(s, c);
	ret = (char **)ft_calloc((n + 1), sizeof(char *));
	if (!ret)
		return (0);
	i = -1;
	k = 0;
	while (++i < n)
	{
		while (s[k] && s[k] == c)
			k++;
		ret[i] = ft_wlen(&k, s, c);
		if (!ret)
			free_ret(ret);
	}
	return (ret);
}
