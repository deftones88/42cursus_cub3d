/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:33:34 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:33:36 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_check_arg(int argc, char *argv[], int *fd)
{
	if (argc != 2 && !(argc == 3 && !ft_strcmp("--save", argv[2])))
		error_putstr(1, argv[0]);
	ft_check_extension(argv[1], ".cub", 1);
	ft_open_check(fd, argv[1], 1);
}

void	ft_elem_last(t_parse *p, char **line, int fd)
{
	if (!(p->e.bonus) && p->e.total > TOTAL_E)
	{
		free(*line);
		close(fd);
		ft_return_error("Too many elements info\n");
	}
	if (p->e.total < TOTAL_E)
	{
		if (p->e.map_start)
			ft_return_error("Missing element info\n");
		ft_return_error("Element info not valid\n");
	}
}

void	ft_map_last(t_parse *p)
{
	int	idx;

	idx = 0;
	if (!p->m.row || !p->m.col)
		ft_return_error("Missing map\n");
	while (ft_check_map_vspace(p->m, &idx))
		ft_map_trim(&p->m, idx);
	ft_player_num_check(&p->m, 0);
}

void	ft_open_tex(t_parse *p, int bonus)
{
	int	fd;

	ft_open_check(&fd, p->c.no, 0);
	ft_open_check(&fd, p->c.so, 0);
	ft_open_check(&fd, p->c.we, 0);
	ft_open_check(&fd, p->c.ea, 0);
	ft_open_check(&fd, p->c.s, 0);
	if (bonus)
	{
		if (p->e.b.s2)
			ft_open_check(&fd, p->c.b.s2, 0);
		if (p->e.b.ft)
			ft_open_check(&fd, p->c.b.ft, 0);
		if (p->e.b.ct)
			ft_open_check(&fd, p->c.b.ct, 0);
		if (p->e.b.s3)
			ft_open_check(&fd, p->c.b.s3, 0);
	}
}

int		parse_gnl(t_parse *p, int fd)
{
	char	*line;
	int		ret;

	line = ft_strdup("");
	if (!line)
		return (-1);
	ft_eflags_init(&p->e);
	ft_cubinfo_init(&p->c);
	ret = 0;
	while (!ret && get_next_line(fd, &line) > 0)
		ret = parse_e(line, &p->e, &p->c);
	ft_elem_last(p, &line, fd);
	ft_mflags_init(&p->m);
	if (p->e.map_start)
		parse_m(line, &p->m, p->e.bonus);
	while (get_next_line(fd, &line) > 0)
		parse_m(line, &p->m, p->e.bonus);
	free(line);
	close(fd);
	ft_map_last(p);
	ft_open_tex(p, p->e.bonus);
	ft_map_visited(&p->m);
	return (0);
}
