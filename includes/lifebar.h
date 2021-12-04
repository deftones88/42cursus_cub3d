/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifebar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:44:28 by ji-kim            #+#    #+#             */
/*   Updated: 2021/03/31 19:45:47 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFEBAR_H
# define LIFEBAR_H

# include <time.h>

# define GAUGE_W 150
# define GAUGE_H 20
# define TMAX 100.0
# define PXMS 1.5

typedef struct	s_life
{
	int			start;
	int			curr;
	int			timeout;
	int			win;
}				t_life;

#endif
