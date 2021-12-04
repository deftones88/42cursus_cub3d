/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:41:42 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:43:17 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# define BMP_BPP 24
# define IMG_DEPTH 3
# define T_BYTE char

typedef struct	s_bmp
{
	T_BYTE	file_header[FILE_HEADER_SIZE];
	T_BYTE	info_header[INFO_HEADER_SIZE];
}				t_bmp;

#endif
