/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 19:41:14 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:33:42 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>
#include "debug.h"

static const t_fracprinttab	g_printfun[] = {
	{mandelbrot, &draw_by_pixels},
	{julia, &draw_by_pixels},
	{newton, &draw_by_pixels},
	{newton2, &draw_by_pixels},
	{newton3, &draw_by_pixels},
	{burning_ship, &draw_by_pixels},
	{tricorn, &draw_by_pixels},
	{popcorn, &draw_by_pixels},
	{phoenix, &draw_by_pixels},
	{none, NULL}
};

void		window_infos(t_fractol *f)
{
	char	*infos;
	char	*iter;
	char	*type;

	if (f->hide)
		return ;
	iter = ft_itoa(f->iterations);
	infos = ft_strjoin("Iterations: ", iter);
	type = ft_strjoin("Type: ", get_fractol_name(f));
	free(iter);
	mlx_string_put(f->env->mlx, f->env->win, 10, 10, 0xFFFFFF, infos);
	mlx_string_put(f->env->mlx, f->env->win, 10, 30, 0xFFFFFF, type);
	free(infos);
	free(type);
}

void		change_fract_type(t_fractol *f)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (g_printfun[size].fun)
		size++;
	while (g_printfun[i].fun)
	{
		if (f->type == g_printfun[i].type)
		{
			f->type = g_printfun[(i + 1) % size].type;
			fractol_origin(f);
			return ;
		}
		i++;
	}
}

int			print_fractol(t_fractol *f)
{
	int		i;

	if (!f || (f && f->ended))
		return (1);
	i = 0;
	while (g_printfun[i].fun)
	{
		if (f->type == g_printfun[i].type)
		{
			g_printfun[i].fun(f);
			window_infos(f);
		}
		i++;
	}
	return (0);
}
