/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:23:31 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

static int		get_tricorn_iter(t_fractol *f)
{
	int				iter;

	iter = 0;
	while (iter < f->iterations)
	{
		f->z0 = cpow(conj(f->z), 2) + complexe(f->x, f->y);
		if (pow(creal(f->z0), 2) + pow(cimag(f->z0), 2) > 4)
			break ;
		f->z = f->z0;
		iter++;
	}
	return (iter);
}

int				draw_tricorn(t_fractol *f, int y, int x)
{
	int				iter;

	f->y = (y - W_HEIGHT / 2) * (f->zoom / W_WIDTH) - f->ky;
	f->x = (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) - f->kx;
	if (f->rotation)
		rotate_points_double(&f->x, &f->y, f->rotation);
	f->z = complexe(f->x, f->y);
	iter = get_tricorn_iter(f);
	f->real = creal(f->z);
	f->im = cimag(f->z);
	return (get_color(f, iter));
}
