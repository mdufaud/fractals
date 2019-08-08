/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 22:29:07 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:32:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int	usage(void)
{
	ft_putstr_fd("Usage: ./fract_ol <mandelbrot/julia/newton/newton2", 2);
	ft_putstr_fd("/newton3/burning_ship/tricorn/popcorn/phoenix", 2);
	ft_putendl_fd(">", 2);
	return (1);
}

static int	check_fractols(t_fractol **fractols)
{
	int	i;

	i = 0;
	if (!fractols)
		return (1);
	while (i < FRACTAL_NUMBER)
	{
		if (fractols[i])
			return (0);
		i++;
	}
	error("You did not select any fractal");
	free(fractols);
	usage();
	return (1);
}

int			main(int argc, char **argv)
{
	t_fractol	**fractols;

	if (argc < 2)
		return (usage());
	if (N_COLORS > 256)
		return (error("Too many colors."));
	fractols = NULL;
	if (init_fractols(&fractols, argc, argv))
		return (1);
	if (check_fractols(fractols))
		return (1);
	start_windows(fractols);
	return (0);
}
