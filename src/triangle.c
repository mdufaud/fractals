/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2017/09/03 22:00:16 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

t_triangle			get_real(t_fractol *f, t_triangle t)
{
	int		coeff;

	coeff = 500;
	t.p1.y = (t.p1.y) / (f->zoom) + f->ky * (coeff / f->zoom);
	t.p1.x = (t.p1.x) / (f->zoom) + f->kx * (coeff / f->zoom);
	t.p2.y = (t.p2.y) / (f->zoom) + f->ky * (coeff / f->zoom);
	t.p2.x = (t.p2.x) / (f->zoom) + f->kx * (coeff / f->zoom);
	t.p3.y = (t.p3.y) / (f->zoom) + f->ky * (coeff / f->zoom);
	t.p3.x = (t.p3.x) / (f->zoom) + f->kx * (coeff / f->zoom);
	return (t);
}

static t_triangle	rec_point(t_fractol *f, t_triangle t, int type)
{
	t_triangle	tr;

	if (type == 1)
	{
		tr.p1.x = (t.p1.x + t.p2.x) / 2 + (t.p2.x - t.p3.x) / 2;
		tr.p1.y = (t.p1.y + t.p2.y) / 2 + (t.p2.y - t.p3.y) / 2;
		tr.p2.x = (t.p1.x + t.p2.x) / 2 + (t.p1.x - t.p3.x) / 2;
		tr.p2.y = (t.p1.y + t.p2.y) / 2 + (t.p1.y - t.p3.y) / 2;
		tr.p3.x = (t.p1.x + t.p2.x) / 2;
		tr.p3.y = (t.p1.y + t.p2.y) / 2;
	}
	else
	{
		tr.p1.x = (t.p3.x + t.p2.x) / 2 + (t.p2.x - t.p1.x) / 2;
		tr.p1.y = (t.p3.y + t.p2.y) / 2 + (t.p2.y - t.p1.y) / 2;
		tr.p2.x = (t.p3.x + t.p2.x) / 2 + (t.p3.x - t.p1.x) / 2;
		tr.p2.y = (t.p3.y + t.p2.y) / 2 + (t.p3.y - t.p1.y) / 2;
		tr.p3.x = (t.p3.x + t.p2.x) / 2;
		tr.p3.y = (t.p3.y + t.p2.y) / 2;
	}
	(void)f;
	return (tr);
}

static t_triangle	rec_point3(t_fractol *f, t_triangle t)
{
	t_triangle	tr;

	tr.p1.x = (t.p1.x + t.p3.x) / 2 + (t.p3.x - t.p2.x) / 2;
	tr.p1.y = (t.p1.y + t.p3.y) / 2 + (t.p3.y - t.p2.y) / 2;
	tr.p2.x = (t.p1.x + t.p3.x) / 2 + (t.p1.x - t.p2.x) / 2;
	tr.p2.y = (t.p1.y + t.p3.y) / 2 + (t.p1.y - t.p2.y) / 2;
	tr.p3.x = (t.p1.x + t.p3.x) / 2;
	tr.p3.y = (t.p1.y + t.p3.y) / 2;
	(void)f;
	return (tr);
}

static void			rec_triangle(t_fractol *f, int iter, t_triangle t)
{
	draw_line(f, t.p1, t.p2, 0xFFFFFF);
	draw_line(f, t.p1, t.p3, 0xFFFFFF);
	draw_line(f, t.p2, t.p3, 0xFFFFFF);
	if (iter < f->iterations)
	{
		rec_triangle(f, iter + 1, rec_point(f, t, 1));
		rec_triangle(f, iter + 1, rec_point(f, t, 2));
		rec_triangle(f, iter + 1, rec_point3(f, t));
	}
}

int					draw_triangle(t_fractol *f)
{
	t_triangle	t;
	t_triangle	tr;

	color_img(f, 0);
	t.p1.x = 10;
	t.p1.y = W_HEIGHT - 10;
	t.p2.x = W_WIDTH - 10;
	t.p2.y = W_HEIGHT - 10;
	t.p3.x = W_WIDTH / 2;
	t.p3.y = 10;
	t = get_real(f, t);
	draw_line(f, t.p1, t.p2, 0xFFFFFF);
	draw_line(f, t.p1, t.p3, 0xFFFFFF);
	draw_line(f, t.p2, t.p3, 0xFFFFFF);
	tr.p1.x = (t.p1.x + t.p2.x) / 2;
	tr.p1.y = (t.p1.y + t.p2.y) / 2;
	tr.p2.x = (t.p1.x + t.p3.x) / 2;
	tr.p2.y = (t.p1.y + t.p3.y) / 2;
	tr.p3.x = (t.p2.x + t.p3.x) / 2;
	tr.p3.y = (t.p2.y + t.p3.y) / 2;
	rec_triangle(f, 0, tr);
	return (0);
}
