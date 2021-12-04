/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:53:55 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:07:17 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./cub3d.h"
# include "../gnl/get_next_line.h"

enum			e_map_element
{
	E_SPACE,
	WALL,
	SPRITE,
	SPRITE2,
	SPRITE3,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	TOTAL_E = 8,
	W_SPACE
};

enum			e_tex_element
{
	E_CEILING,
	E_FLOOR
};

typedef struct	s_eflags
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			bonus;
	int			total;
	int			map_start;
	t_ebonus	b;
}				t_eflags;

typedef struct	s_mflags
{
	int			col;
	int			row;
	int			dir;
	int			**map;
	char		**cvisited;
	int			x;
	int			y;
	int			sp_total;
}				t_mflags;

typedef struct	s_parse
{
	t_eflags	e;
	t_cubinfo	c;
	t_mflags	m;
}				t_parse;
/*
** parse_init.c
*/
void			ft_eflags_init(t_eflags *eflags);
void			ft_mflags_init(t_mflags *mflags);
void			ft_cubinfo_init(t_cubinfo *cubinfo);
/*
** parsing_e.c
*/
void			ft_check_num(char **temp);
void			free_double(char **temp);
void			free_map_char(int row, char **temp);
int				parse_e_alpha(char *line, t_eflags *eflags, t_cubinfo *cubinfo);
int				parse_e(char *line, t_eflags *eflags, t_cubinfo *cubinfo);
/*
** parsing_e_r_text.c
*/
void			ft_read_resolution(char *line, t_eflags *eflags,
		t_cubinfo *cubinfo);
char			**ft_tex_cub_ptr(t_cubinfo *cubinfo, int d, int bonus);
int				*ft_tex_flag_ptr(t_eflags *eflags, int d);
void			ft_read_texture(char *line, t_eflags *eflags,
		t_cubinfo *cubinfo, int d);
/*
** parsing_e_rgb.c
*/
void			ft_check_rgb(int a);
t_rgb			*ft_rgb_cub_prt(t_cubinfo *cubinfo, int d);
int				*ft_rgb_flag_ptr(t_eflags *eflags, int d);
void			ft_rgb_check_error(int *pflag, char **temp1);
void			ft_read_rgb(char *line, t_eflags *eflags, t_cubinfo *cubinfo,
		int d);
/*
** parsing_m_check.c
*/
int				ft_check_map_char(int bonus, char c);
int				ft_check_map_int(int c);
void			ft_player_num_check(t_mflags *mflags, int is_or);
int				ft_check_map_line(char *line, t_mflags *mflags, int bonus);
int				ft_check_line(char *line);
/*
** parsing_m_convert.c
*/
int				*ft_convert_map(char *line, t_mflags *mflags, int o);
int				**ft_map_temp(char *line, t_mflags *mflags, int o);
/*
** parsing_m_trim.c
*/
int				ft_check_map_vspace(t_mflags mflags, int *idx);
void			ft_map_trim(t_mflags *mflags, int idx);
/*
** parsing_m.c
*/
void			ft_free_int_map(int **map, int row);
void			parse_m(char *line, t_mflags *mflags, int bonus);
/*
** dfs.c
*/
int				dfs(int i, int j, t_mflags *mflags);
char			**ft_char_map_malloc(t_mflags *mflags);
void			ft_map_copy(t_mflags *mflags);
void			ft_map_visited(t_mflags *mflags);
/*
** parsing.c
*/
void			ft_check_arg(int argc, char *argv[], int *fd);
void			ft_elem_last(t_parse *p, char **line, int fd);
void			ft_map_last(t_parse *p);
int				parse_gnl(t_parse *p, int fd);
/*
** parsing_bonus.c
*/
void			parse_e_alpha2(char *line, t_eflags *eflags,
		t_cubinfo *cubinfo);
int				ft_check_e_bonus(char *line);

#endif
