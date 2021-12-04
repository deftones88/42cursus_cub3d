/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:39:35 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:40:13 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
