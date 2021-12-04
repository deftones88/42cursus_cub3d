/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:38:24 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:38:51 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newline(char *backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_backup(char **backup, char **line, int idx)
{
	char			*temp;
	int				len;

	(*backup)[idx] = '\0';
	free(*line);
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		ft_return_line(char **backup, char **line, int read_size)
{
	int				idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (idx = ft_newline(*backup)) > -1)
		return (ft_backup(backup, line, idx));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	free(*line);
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	int				read_size;
	int				idx;

	if ((fd < 0) || (fd > OPEN_MAX) || (!line) || (BUFFER_SIZE < 1))
		return (-1);
	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buff[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((idx = ft_newline(backup[fd])) > -1)
			return (ft_backup(&backup[fd], line, idx));
	}
	return (ft_return_line(&backup[fd], line, read_size));
}
