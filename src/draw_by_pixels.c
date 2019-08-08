/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:22:03 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 17:48:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

static const t_fracpixeltab	g_printfun[] = {
	{mandelbrot, &draw_mandelbrot},
	{julia, &draw_julia},
	{newton, &draw_newton},
	{newton2, &draw_newton},
	{newton3, &draw_newton},
	{burning_ship, &draw_burning_ship},
	{tricorn, &draw_tricorn},
	{popcorn, &draw_popcorn},
	{phoenix, &draw_phoenix},
	{none, NULL}
};

static int	get_type(t_fractol *f)
{
	int		i;

	i = 0;
	while (g_printfun[i].fun)
	{
		if (f->type == g_printfun[i].type)
			break ;
		i++;
	}
	return (i);
}

int			draw_by_pixels(t_fractol *f)
{
	int		i;
	int		j;
	int		color;
	int		index;

	i = 0;
	index = get_type(f);
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			color = g_printfun[index].fun(f, i, j);
			put_pixel(f, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f->env->mlx, f->env->win, f->env->img->img, 0, 0);
	return (0);
}
