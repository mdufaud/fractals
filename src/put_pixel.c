/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 12:31:47 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/10 20:12:31 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	t_img	*img;

	img = f->env->img;
	x = x == 0 ? 1 : x;
	y = y == 0 ? 1 : y;
	if (x < W_WIDTH && y < W_HEIGHT && x >= 0 && y >= 0)
	{
		img->data[img->sizel * y + x * (img->bpp / 8)] =
			(char)(color & 255);
		img->data[img->sizel * y + x * (img->bpp / 8) + 1] =
			(char)(color >> 8 & 255);
		img->data[img->sizel * y + x * (img->bpp / 8) + 2] =
			(char)(color >> 16 & 255);
	}
}

void	color_img(t_fractol *f, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < W_WIDTH)
	{
		j = 0;
		while (j < W_HEIGHT)
		{
			put_pixel(f, i, j, color);
			j++;
		}
		i++;
	}
}
