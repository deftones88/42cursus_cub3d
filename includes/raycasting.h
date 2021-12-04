/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:55:33 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 20:56:24 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "./parsing.h"
# include "./bmp.h"

/*
** keys
*/
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_MOTION		6
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_L		123
# define KEY_ARROW_R		124
# define KEY_ARROW_U		126
# define KEY_ARROW_D		125

/*
** textures
*/
enum	e_text_side
{
	T_NORTH,
	T_SOUTH,
	T_EAST,
	T_WEST,
	T_SPRITE,
	T_SPRITE2,
	T_SPRITE3,
	T_CEILING,
	T_FLOOR,
	T_TOTAL
};
/*
** game
*/
# define M_SPEED		0.2
# define R_SPEED		0.2
# define PLANE			0.66

typedef struct	s_player
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_player;

typedef struct	s_raydir
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		side_dx;
	double		side_dy;
	double		delta_dx;
	double		delta_dy;
	double		pwall_d;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_raydir;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_tex
{
	t_img		img;
	double		step;
	int			tex_h;
	int			tex_w;
}				t_tex;

typedef struct	s_game
{
	int			save;
	int			bonus;
	int			**buf;
	void		*mlx;
	void		*win;
	int			sizex;
	int			sizey;
	int			**map;
	int			map_row;
	int			map_col;
	int			sp_total;
	int			mouse_x;
	int			mouse_y;
	t_img		img;
	t_player	p;
	t_raydir	r;
	t_tex		t[T_TOTAL];
	t_cubinfo	c;
	t_ebonus	e;
	t_bmp		bmp;
	t_fcbonus	fc;
	t_sppack	sp;
	t_hud		hud;
	int			item[4];
	int			i_num;
	int			*i_tex;
	int			i_width;
	t_life		l;
}				t_game;
/*
** game_init.c
*/
void			ft_copy_info(t_parse *p, t_game *game, int argc);
void			tex_init(t_game *game);
void			window_init(t_game *game);
void			img_init(t_game *game);
/*
** game_init2.c
*/
void			write_int(T_BYTE *color, unsigned param);
void			ft_bmp_init(t_game *game);
void			ft_hud_init(t_game *game);
void			ft_bonus_init(t_game *game);
/*
** raycasting.c
*/
void			ft_set_up(t_game *game, int i);
void			ft_set_side_step(t_game *game);
void			ft_set_pwalldist(t_game *game);
void			ray_loop(t_game *game);
/*
** texture.c
*/
void			ft_set_drawstart_end(t_game *game);
void			ft_draw_tex(t_game *game, int tex_x, int i, int tex_num);
int				ft_set_tex_num(t_game *game);
void			ft_set_tex(t_game *game, int i);
/*
** keys.c
*/
int				ft_is_wallsprite(int a);
void			key_w_s(int keycode, t_game *game);
void			key_a_d(int keycode, t_game *game);
void			key_l_r(int keycode, t_game *game);
int				key_press(int keycode, t_game *game);
/*
** mouse.c
*/
int				motion_hook(int keycode, t_game *game);
/*
** cub3d.c
*/
void			image_draw(t_game *game);
void			load_image(t_game *game, char *path, t_img *img);
void			load_texture(t_game *game);
int				main_loop(t_game *game);
/*
** luminosity.c
*/
double			get_luminosity(t_game *game, double dist);
int				fade_color(int color, double lum);
void			decode_color(int color, int *r, int *g, int *b);
int				encode_color(int r_lum, int g_lum, int b_lum);
/*
** raycasting_bonus.c
*/
void			ft_set_fc_bonus(t_game *game);
void			ft_set_fc_basics(t_game *game, int j);
void			ft_set_imgxy_color(t_game *game, int *color);
/*
** save.c
*/
void			capture_bmp(t_game *game);
int				ft_bmp_write(t_game *game);
void			ft_write_pixel(int fd, t_game *game);
/*
** sprite.c
*/
void			ft_sprite_init(t_game *game);
void			ft_parse_sp(t_game *game, int i, int j, int k);
void			ft_get_sp(t_game *game);
/*
** sprite_draw.c
*/
void			ft_set_sprite(t_game *game, int o);
void			ft_set_sprite_draw(t_game *game, int o);
void			ft_sprite_render_buff(t_game *game, int k, int o);
void			ft_draw_sp(t_game *game);
void			ft_sort_sp(t_game *game);
/*
** exit.c
*/
void			ft_free_string(t_game *game);
void			ft_free_all(t_game *game);
void			ft_init_buf(t_game *game);
/*
** main.c
*/
void			ft_run_game(t_game *game, int argc);
int				main(int argc, char *argv[]);
int				ft_close(t_game *game);
/*
** mouse.c
*/
int				mouse_move(int x, int y, t_game *game);
/*
** hud.c
*/
void			draw_rec_square(t_game *game, int x, int y, int color);
void			draw_rec(t_game *game);
void			ft_draw_hud(t_game *game);
void			hud_ray(t_game *game, int x, int y);
/*
** points.c
*/
void			ft_check_item(t_game *game);
void			ft_item_pixel(t_game *game, int y, int x, int k);
void			ft_draw_item(t_game *game);
void			ft_item_init(t_game *game);
void			ft_i_tex_init(t_game *game);
/*
** keys_bonus2.c
*/
void			key_u_d(int keycode, t_game *game);
void			ft_set_pitch(t_game *game);
/*
**	lifebar.c
*/
void			ft_draw_life(t_game *game);
void			ft_draw_end(t_game *game);
void			ft_draw_win(t_game *game);

#endif
