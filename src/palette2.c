/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:20:11 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 18:01:01 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int			init_color(t_fractol *f, int num, int total)
{
	int		*colors;

	if (!(colors = malloc(sizeof(int) * (num * total + 1))))
		return (1);
	f->n_colors = num;
	f->color_max = num * total;
	colors[f->color_max] = 0;
	f->colors = colors;
	return (0);
}

static int			add_color(int r, int g, int b)
{
	int		color;

	color = (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}

int					gray_palette(t_fractol *f)
{
	int			i;
	int			*colors;
	int			n;
	int			t;

	i = 0;
	n = 230;
	t = 2;
	if (init_color(f, n, t))
		return (error("cannot create colors"));
	colors = f->colors;
	while (i < n)
	{
		t = (n - 1) - i;
		colors[i] = add_color(t, t, t);
		colors[i + n] = add_color(i, i, i);
		i++;
	}
	f->colors = colors;
	return (0);
}

int					yolo_palette(t_fractol *f)
{
	int			i;
	int			*colors;
	int			n;
	int			t;

	i = 0;
	n = 230;
	t = 8;
	if (init_color(f, n, t))
		return (error("cannot create colors"));
	colors = f->colors;
	while (i < n)
	{
		colors[i] = add_color(i, 0, 0);
		colors[i + n * 1] = add_color((n - 1), i, 0);
		colors[i + n * 2] = add_color((n - 1) - i, (n - 1) - i, 0);
		colors[i + n * 3] = add_color(0, i, i);
		colors[i + n * 4] = add_color(0, (n - 1) - i, (n - 1) - i);
		colors[i + n * 5] = add_color(i, 0, i);
		colors[i + n * 6] = add_color((n - 1) - i, 0, (n - 1));
		colors[i + n * 7] = add_color(0, 0, (n - 1) - i);
		i++;
	}
	f->colors = colors;
	return (0);
}

int					colorfull_palette(t_fractol *f)
{
	int			i;
	int			*colors;
	int			n;
	int			t;

	i = 0;
	n = 230;
	t = 7;
	if (init_color(f, n, t))
		return (error("cannot create colors"));
	colors = f->colors;
	while (i < n)
	{
		colors[i] = add_color(i, 0, i);
		colors[i + n * 1] = add_color((n - 1) - i, 0, (n - 1));
		colors[i + n * 2] = add_color(0, i, (n - 1));
		colors[i + n * 3] = add_color(0, (n - 1), (n - 1) - i);
		colors[i + n * 4] = add_color(i, (n - 1), 0);
		colors[i + n * 5] = add_color((n - 1), (n - 1) - i, 0);
		colors[i + n * 6] = add_color((n - 1) - i, 0, 0);
		i++;
	}
	f->colors = colors;
	return (0);
}
