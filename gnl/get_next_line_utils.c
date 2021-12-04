/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:40:43 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:40:46 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (n == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dest_len + 1 + i < n)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (n < dest_len)
		return (n + src_len);
	return (dest_len + src_len);
}

char		*ft_strdup(const char *str)
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	free((void *)s1);
	ft_strlcat(temp + s1_len, s2, s2_len + 1);
	return (temp);
}
