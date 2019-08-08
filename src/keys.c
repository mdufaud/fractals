/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:35:28 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:18:04 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_code.h"
#include <mlx.h>

void		describe_keys(void)
{
	ft_putendl("Keys:");
	ft_putendl("- Arrows to move");
	ft_putendl("- Page up / Page down to zoom");
	ft_putendl("- End to reset everything");
	ft_putendl("- R / G / B to add respectively Red, Green, Blue");
	ft_putendl("- PAV + or - for more/less iterations");
	ft_putendl("- [ or ] to rotate");
	ft_putendl("- 1 or 2 for more power");
	ft_putendl("- 3 or 4 for utility");
	ft_putendl("- T to change fractal type");
	ft_putendl("- P to change color palette");
	ft_putendl("- S to change color smoothness when available");
}

void		arrow_keys(t_fractol *f, int keycode)
{
	if (keycode == LEFT_ARROW)
		f->kx += (1 - W_WIDTH / 20) * (f->zoom / W_WIDTH) * -1;
	else if (keycode == RIGHT_ARROW)
		f->kx -= (1 - W_WIDTH / 20) * (f->zoom / W_WIDTH) * -1;
	else if (keycode == UP_ARROW)
		f->ky += (1 - W_HEIGHT / 20) * (f->zoom / W_HEIGHT) * -1;
	else if (keycode == DOWN_ARROW)
		f->ky -= (1 - W_HEIGHT / 20) * (f->zoom / W_HEIGHT) * -1;
}

void		utility_keys(t_fractol *f, int keycode)
{
	if (keycode == END_KEY)
		fractol_origin(f);
	else if (keycode == ONE_KEY)
		f->pow -= 1;
	else if (keycode == TWO_KEY)
		f->pow += 1;
	else if (keycode == THREE_KEY)
		f->utility_one -= 0.1;
	else if (keycode == FOUR_KEY)
		f->utility_one += 0.1;
	else if (keycode == H_KEY)
		f->hide = f->hide == 0 ? 1 : 0;
	else if (keycode == T_KEY)
		change_fract_type(f);
}

void		graph_keys(t_fractol *f, int keycode)
{
	if (keycode == PAGE_UP)
		f->zoom /= 1.1;
	else if (keycode == PAGE_DOWN)
		f->zoom *= 1.1;
	else if (keycode == PAVEPLUS_KEY)
		f->iterations += 1;
	else if (keycode == PAVELESS_KEY)
		f->iterations -= 1;
	else if (keycode == CROCHETBEGIN_KEY)
		f->rotation += (0.001 - W_HEIGHT / 2) * (f->zoom / W_HEIGHT);
	else if (keycode == CROCHETEND_KEY)
		f->rotation -= (0.001 - W_HEIGHT / 2) * (f->zoom / W_HEIGHT);
}

void		color_keys(t_fractol *f, int keycode)
{
	if (keycode == R_KEY)
		f->color += 3 << 16;
	else if (keycode == G_KEY)
		f->color += 3 << 8;
	else if (keycode == B_KEY || keycode == C_KEY)
		f->color += 3;
	else if (keycode == LESS_KEY)
		f->color_speed -= 1;
	else if (keycode == EQUAL_KEY)
		f->color_speed += 1;
	else if (keycode == S_KEY)
		f->smooth = f->smooth == 1 ? 0 : 1;
	else if (keycode == P_KEY)
	{
		f->colors_i += 1;
		get_palette(f->colors_i, f);
	}
}
