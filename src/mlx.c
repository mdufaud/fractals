/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 16:26:27 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/17 23:00:56 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static int	start_window(t_fractol *f, void *mlx)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (error("not enough memory"));
	e->mlx = mlx;
	f->env = e;
	e->win_width = GLOBAL_WIN_WIDTH;
	e->win_height = GLOBAL_WIN_HEIGHT;
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "Fract'ol");
	if (!e->win)
		return (error("could not init window"));
	e->img = 0;
	mlx_expose_hook(e->win, expose_hook, f);
	mlx_mouse_hook(e->win, mouse_hook, f);
	mlx_do_key_autorepeaton(f->env->mlx);
	mlx_hook(f->env->win, 2, 3, key_hook, f);
	mlx_hook(f->env->win, 6, (1 << 6), motion_hook, f);
	create_img(&f);
	print_fractol(f);
	mlx_put_image_to_window(f->env->mlx, f->env->win, f->env->img->img, 0, 0);
	return (0);
}

static int	has_ended(t_fractol **fractols)
{
	int		i;
	int		stop;

	i = 0;
	stop = 1;
	while (i < FRACTAL_NUMBER)
	{
		if (fractols[i] && !fractols[i]->ended)
			stop = 0;
		else if (fractols[i])
			free_fractol(&(fractols[i]));
		i++;
	}
	if (stop)
	{
		free(fractols);
		exit(0);
	}
	return (1);
}

int			start_windows(t_fractol **fractols)
{
	int		i;
	void	*mlx;

	i = 0;
	if (!(mlx = mlx_init()))
		return (error("could not init mlx"));
	describe_keys();
	while (fractols[i])
	{
		fractols[i]->colors_i = 0;
		fractols[i]->colors = NULL;
		get_palette(0, fractols[i]);
		start_window(fractols[i], mlx);
		i++;
	}
	mlx_loop_hook(mlx, has_ended, fractols);
	mlx_loop(mlx);
	return (1);
}
