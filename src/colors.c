/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:08:48 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:16:29 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

#include <math.h>

static const t_colors	g_colorfun[] = {
	{&colorfull_palette},
	{&gray_palette},
	{&yolo_palette},
	{NULL},
};

int					get_color(t_fractol *f, int iter)
{
	int		color;
	int		index;

	color = (int)iter + f->color_speed;
	color = color <= 0 ? 0 : color;
	color = (color * (f->n_colors - 1)) / TRUE(f->iterations);
	index = color % f->color_max;
	return (f->colors[index] + f->color);
}

int					get_smooth_color(t_fractol *f, int iter)
{
	int		color;

	color = (iter + f->color_speed);
	color -= log2(log(cabs(complexe(f->real, f->im))) / log(f->iterations));
	return (f->colors[color % f->color_max] + f->color);
}

void				get_palette(int index, t_fractol *f)
{
	int		i;

	i = 0;
	if (f->colors)
	{
		free(f->colors);
		f->colors = NULL;
	}
	while (g_colorfun[i].fun)
		i++;
	if (g_colorfun[index % i].fun(f))
	{
		f->n_colors = 0;
		f->color_max = 0;
		f->colors = NULL;
	}
}
