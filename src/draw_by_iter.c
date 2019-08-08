/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:36:15 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:33:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

static const t_fracitertab	g_printfun[] = {
	{none, NULL}
};

int			draw_by_iter(t_fractol *f)
{
	int		i;

	i = 0;
	while (g_printfun[i].fun)
	{
		if (f->type == g_printfun[i].type)
		{
			g_printfun[i].fun(f);
			break ;
		}
		i++;
	}
	mlx_put_image_to_window(f->env->mlx, f->env->win, f->env->img->img, 0, 0);
	return (0);
}
