/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:46:05 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 20:56:49 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "./cub3d_bonus.h"
# include "./sprite.h"

# define WINDOW_TITLE "CUB3D"

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}					t_rgb;

typedef struct		s_cubinfo
{
	int				width;
	int				height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	t_rgb			f;
	t_rgb			c;
	t_cbonus		b;
}					t_cubinfo;

/*
** utils_one.c
*/
int					ft_strcmp(const char *str1, const char *str2);
int					ft_isspace(char c);
char				*ft_strdup_filepath(const char *str);
/*
** error_message.c
*/
void				ft_check_extension(char *str, char *cmp, int is_cub);
void				error_putstr(int n, char *str);
void				ft_return_error(char *str);
void				ft_open_check(int *fd, char *file, int argv);
/*
** bgm.c
*/
void				run_bgm(void);

#endif
