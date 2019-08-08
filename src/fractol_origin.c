/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_origin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:22:17 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:33:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		get_by_type(t_fractol *f)
{
	if (f->type >= newton && f->type <= newton3)
	{
		f->color_speed = 7;
	}
	else if (f->type == julia)
	{
		f->mx = GLOBAL_WIN_WIDTH * 0.565;
		f->my = GLOBAL_WIN_HEIGHT * 0.294;
	}
}

void			fractol_origin(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	f->kx = 0;
	f->ky = 0;
	f->mx = 0;
	f->my = 0;
	f->motion = 0;
	f->smooth = 0;
	f->zoom = 5;
	f->color = 0x00000F;
	f->iterations = 30;
	f->rotation = 0.0;
	f->color_speed = 0;
	f->pow = 0;
	f->utility_one = 0.0;
	f->hide = 0;
	f->iter = 0;
	f->z = 0;
	f->z0 = 0;
	get_by_type(f);
}
