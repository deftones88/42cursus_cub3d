/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:59:45 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 20:59:46 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_extension(char *str, char *cmp, int is_cub)
{
	char	*temp;
	int		i;

	temp = ft_strrchr(str, '.');
	if (!temp)
		ft_return_error("Wrong file type\n");
	i = ft_strncmp(temp, cmp, ft_strlen(cmp));
	if (i)
	{
		if (is_cub)
			error_putstr(2, str);
		else
		{
			free(str);
			ft_return_error("Wrong file type\n");
		}
	}
}

void	error_putstr(int n, char *str)
{
	if (n == 1)
	{
		ft_putstr_fd("\n-- Wrong input (Usage : ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" [.cub file] [--save]", STDERR_FILENO);
		ft_putstr_fd(")\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (n == 2)
	{
		ft_putstr_fd("\n-- ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" is not a valid cub file\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (n == 3)
	{
		ft_putstr_fd("\n-- ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	ft_return_error(char *str)
{
	ft_putstr_fd("\n-- Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_open_check(int *fd, char *file, int argv)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		error_putstr(3, file);
	if (!argv)
		close(*fd);
}
