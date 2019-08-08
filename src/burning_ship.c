/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:18:24 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

int		draw_burning_ship(t_fractol *f, int y, int x)
{
	int			iter;

	iter = 0;
	f->y = (y - W_HEIGHT / 2) * (f->zoom / W_WIDTH) - f->ky;
	f->x = (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) - f->kx;
	if (f->rotation)
		rotate_points_double(&f->x, &f->y, f->rotation);
	f->real = f->x;
	f->im = f->y;
	while (iter < f->iterations)
	{
		f->real_tmp = f->real;
		f->im_tmp = f->im;
		f->real = f->real * f->real - f->im * f->im - (f->x);
		f->im = 2 * ABS(f->real_tmp * f->im) - (-f->y);
		if (f->real * f->real + f->im * f->im > 10)
			break ;
		iter++;
	}
	if (iter == f->iterations)
		return (0);
	if (f->smooth)
		return (get_smooth_color(f, iter));
	return (get_color(f, iter));
}
