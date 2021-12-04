/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:41:19 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:41:21 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	capture_bmp(t_game *game)
{
	ray_loop(game);
	ft_draw_sp(game);
	image_draw(game);
	ft_bmp_init(game);
	if (!ft_bmp_write(game))
	{
		mlx_destroy_image(game->mlx, game->img.img);
		ft_init_buf(game);
		error_putstr(3, "Failed to save image\n");
	}
	mlx_destroy_image(game->mlx, game->img.img);
	ft_init_buf(game);
}

int		ft_bmp_write(t_game *game)
{
	int		fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (fd < 0)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		error_putstr(3, "Failed to save image\n");
	}
	write(fd, game->bmp.file_header, FILE_HEADER_SIZE);
	write(fd, game->bmp.info_header, INFO_HEADER_SIZE);
	ft_write_pixel(fd, game);
	close(fd);
	return (1);
}

void	ft_write_pixel(int fd, t_game *game)
{
	int		i;
	int		j;
	T_BYTE	color[3];
	T_BYTE	padding[3];
	int		padding_size;

	ft_bzero(padding, 3);
	padding_size = (4 - (game->c.width * IMG_DEPTH) % 4) % 4;
	i = game->c.height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < game->c.width)
		{
			write_int(color, game->img.data[(i * game->c.width + j)]);
			write(fd, color, 3);
		}
		write(fd, padding, padding_size);
	}
}
