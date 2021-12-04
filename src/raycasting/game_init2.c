/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:49:49 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 21:53:01 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

/*
** FILE_HEADER
**
** bfType(2) : must always be set to 'BM' to declare that this is a .bmp-file.
** bfSize(4) : total size of the bitmap file in bytes
** bfReserved1(2) : must always be set to zero.
** bfReserved2(2) : must always be set to zero.
** bfOffBits(4) : the offset from the beginning of the file to the bitmap data.
**
** INFO_HEADER
**
** biSize : the size of the BITMAPINFOHEADER structure, in bytes.
** biWidth : the **width** of the image, in pixels.
** biHeight : the **height** of the image, in pixels.
** biPlanes : the **number of planes** of the target device, must be zero.
** biBitCount : the number of **bits per pixel** (resolution of the bitmap).
** - 1 (black/white)
** - 4 (16 colors)
** - 8 (256 colors)
** - 24 (16.7 million colors)
** biCompression : the type of **compression**, usually zero (no compression).
** biSizeImage : the **size** of the image data, in bytes.
** biXPelsPerMeter : the the horizontal **pixels per meter**, usually zero.
** biYPelsPerMeter : the the vertical **pixels per meter**, usually zero.
** biClrUsed : the number of colors used in the bitmap,
** biClrImportant : the number of color that are 'important' for the bitmap,
*/

void	ft_bmp_init(t_game *game)
{
	int		file_size;
	int		h_size;

	h_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
	file_size = (h_size) + (game->c.width * game->c.height * IMG_DEPTH);
	ft_bzero(game->bmp.file_header, FILE_HEADER_SIZE);
	ft_bzero(game->bmp.info_header, INFO_HEADER_SIZE);
	game->bmp.file_header[0] = (unsigned char)'B';
	game->bmp.file_header[1] = (unsigned char)'M';
	game->bmp.file_header[2] = (unsigned char)(file_size);
	game->bmp.file_header[3] = (unsigned char)(file_size >> 8);
	game->bmp.file_header[4] = (unsigned char)(file_size >> 16);
	game->bmp.file_header[5] = (unsigned char)(file_size >> 24);
	game->bmp.file_header[10] = (unsigned char)(h_size);
	game->bmp.info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	game->bmp.info_header[4] = (unsigned char)(game->c.width);
	game->bmp.info_header[5] = (unsigned char)(game->c.width >> 8);
	game->bmp.info_header[6] = (unsigned char)(game->c.width >> 16);
	game->bmp.info_header[7] = (unsigned char)(game->c.width >> 24);
	game->bmp.info_header[8] = (unsigned char)(game->c.height);
	game->bmp.info_header[9] = (unsigned char)(game->c.height >> 8);
	game->bmp.info_header[10] = (unsigned char)(game->c.height >> 16);
	game->bmp.info_header[11] = (unsigned char)(game->c.height >> 24);
	game->bmp.info_header[12] = (unsigned char)1;
	game->bmp.info_header[14] = (unsigned char)(BMP_BPP);
}

void	write_int(T_BYTE *color, unsigned param)
{
	color[0] = (param >> 0);
	color[1] = (param >> 8);
	color[2] = (param >> 16);
}

void	ft_hud_init(t_game *game)
{
	game->hud.col = game->map_col;
	game->hud.row = game->map_row;
	game->hud.tile_size = (game->c.width / 4) / game->hud.col;
	game->hud.width = game->hud.col * game->hud.tile_size;
	game->hud.height = game->hud.row * game->hud.tile_size;
	game->hud.ray_len = game->hud.tile_size;
}

void	ft_bonus_init(t_game *game)
{
	ft_hud_init(game);
	game->fc.pitch = 0;
	game->l.timeout = 0;
	game->l.win = 0;
	ft_item_init(game);
}
