/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:17:29 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

static int	get_julia_iter(t_fractol *f)
{
	int		iter;
	double	c_re;
	double	c_im;

	iter = 0;
	c_re = (-f->mx / 500);
	c_im = (-f->my / 500);
	while (iter < f->iterations && f->real * f->real + f->im * f->im < 4)
	{
		f->real_tmp = f->real;
		f->im_tmp = f->im;
		f->real = f->real * f->real - f->im * f->im + c_re;
		f->im = 2 * f->real_tmp * f->im + c_im;
		iter++;
	}
	return (iter);
}

int			draw_julia(t_fractol *f, int y, int x)
{
	int			iter;

	f->y = (y - W_HEIGHT / 2) * (f->zoom / W_WIDTH) - f->ky;
	f->x = (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) - f->kx;
	if (f->rotation)
		rotate_points_double(&f->x, &f->y, f->rotation);
	f->real = f->x;
	f->im = f->y;
	iter = get_julia_iter(f);
	if (iter == f->iterations)
		return (0);
	if (f->smooth)
		return (get_smooth_color(f, iter));
	return (get_color(f, iter));
}
