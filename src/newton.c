/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:43:35 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 17:09:07 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>

static const t_newton	g_fun[] = {
	{newton, &polynome_1, &derivate_1},
	{newton2, &polynome_2, &derivate_2},
	{newton3, &polynome_3, &derivate_3},
	{none, NULL, NULL},
};

static int		get_newton(t_fractol *f)
{
	int		i;

	i = 0;
	while (g_fun[i].poly)
	{
		if (g_fun[i].type == f->type)
			break ;
		i++;
	}
	return (i);
}

static int		get_newton_iter(t_fractol *f, int i)
{
	double			eps;
	double			a;
	int				iter;

	iter = 0;
	eps = 0.01;
	a = 1.0 + f->utility_one > 1.9 ? 1.9 : 1.0 + f->utility_one;
	a = a <= 0.1 ? 0.1 : a;
	while (iter < f->iterations)
	{
		f->z0 = f->z - a * (g_fun[i].poly(f, f->z) / g_fun[i].deriv(f, f->z));
		if (cabs(f->z0 - f->z) < eps)
			break ;
		f->z = f->z0;
		iter++;
	}
	return (iter);
}

int				draw_newton(t_fractol *f, int y, int x)
{
	int				iter;
	int				i;

	iter = 0;
	i = get_newton(f);
	f->y = (y - W_HEIGHT / 2) * (f->zoom / W_WIDTH) - f->ky;
	f->x = (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) - f->kx;
	if (f->rotation)
		rotate_points_double(&f->x, &f->y, f->rotation);
	f->z = complexe(f->x, f->y);
	iter = get_newton_iter(f, i);
	f->real = creal(f->z);
	f->im = cimag(f->z);
	return (get_color(f, iter));
}
