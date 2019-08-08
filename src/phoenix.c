/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:49:45 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 17:48:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

static int	get_iter(t_fractol *f, double c_re, double c_im)
{
	int		iter;
	double	b_re;
	double	b_im;

	iter = 0;
	b_re = 0;
	b_im = 0;
	while (iter < f->iterations && f->real * f->real + f->im * f->im < 4)
	{
		f->real_tmp = f->real;
		f->im_tmp = f->im;
		f->real = f->real * f->real - f->im * f->im + c_re + c_im * b_re;
		f->im = 2 * f->real_tmp * f->im + c_im * b_im;
		b_re = f->real_tmp;
		b_im = f->im_tmp;
		iter++;
	}
	return (iter);
}

int			draw_phoenix(t_fractol *f, int y, int x)
{
	int		iter;
	double	c_re;
	double	c_im;

	f->y = (y - W_HEIGHT / 2) * (f->zoom / W_WIDTH) - f->ky;
	f->x = (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) - f->kx;
	if (f->rotation)
		rotate_points_double(&f->x, &f->y, f->rotation);
	c_re = (-f->mx / 500);
	c_im = (-f->my / 500);
	f->real = f->x;
	f->im = f->y;
	iter = get_iter(f, c_re, c_im);
	if (iter == f->iterations)
		return (0);
	if (f->smooth)
		return (get_smooth_color(f, iter));
	return (get_color(f, iter));
}
