/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 22:29:15 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:34:40 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_code.h"
#include <mlx.h>
#include "debug.h"

static const t_keycode	g_keycode[] = {
	{LEFT_ARROW, arrow_keys},
	{RIGHT_ARROW, arrow_keys},
	{UP_ARROW, arrow_keys},
	{DOWN_ARROW, arrow_keys},
	{PAGE_UP, graph_keys},
	{PAGE_DOWN, graph_keys},
	{PAVEPLUS_KEY, graph_keys},
	{PAVELESS_KEY, graph_keys},
	{CROCHETBEGIN_KEY, graph_keys},
	{CROCHETEND_KEY, graph_keys},
	{END_KEY, utility_keys},
	{Q_KEY, utility_keys},
	{ESCAPE_KEY, utility_keys},
	{ONE_KEY, utility_keys},
	{TWO_KEY, utility_keys},
	{THREE_KEY, utility_keys},
	{FOUR_KEY, utility_keys},
	{T_KEY, utility_keys},
	{H_KEY, utility_keys},
	{R_KEY, color_keys},
	{G_KEY, color_keys},
	{B_KEY, color_keys},
	{C_KEY, color_keys},
	{P_KEY, color_keys},
	{S_KEY, color_keys},
	{EQUAL_KEY, color_keys},
	{LESS_KEY, color_keys},
	{0, NULL}
};

int			mouse_hook(int button, int x, int y, t_fractol *f)
{
	f->mx = x;
	f->my = y;
	if (button == 4)
		f->zoom /= 1.1;
	if (button == 5)
		f->zoom *= 1.1;
	if (button >= 1 && button <= 3)
	{
		f->kx += (x - W_WIDTH / 2) * (f->zoom / W_WIDTH) * -1;
		f->ky += (y - W_HEIGHT / 2) * (f->zoom / W_HEIGHT) * -1;
	}
	else if (button >= 4 && button <= 5)
	{
		f->kx += ((x - W_WIDTH / 2) * (f->zoom / W_WIDTH) * -1) / 4;
		f->ky += ((y - W_HEIGHT / 2) * (f->zoom / W_HEIGHT) * -1) / 4;
	}
	print_fractol(f);
	return (0);
}

int			motion_hook(int x, int y, t_fractol *f)
{
	if (x > W_WIDTH || x < 0)
		return (0);
	if (y > W_HEIGHT || y < 0)
		return (0);
	if (f->type == julia || f->type == phoenix)
	{
		f->mx = x;
		f->my = y;
		f->motion++;
		print_fractol(f);
	}
	return (1);
}

int			expose_hook(t_fractol *f)
{
	print_fractol(f);
	return (0);
}

int			key_hook(int keycode, t_fractol *f)
{
	int		i;

	i = 0;
	if (keycode == ESCAPE_KEY || keycode == Q_KEY)
		f->ended = 1;
	while (!f->ended && g_keycode[i].fun)
	{
		if (keycode == g_keycode[i].keycode)
			g_keycode[i].fun(f, keycode);
		i++;
	}
	print_fractol(f);
	return (0);
}
