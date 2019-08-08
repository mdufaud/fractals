/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 16:15:44 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/10 20:08:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void				print_fractol_type(t_fractol *f)
{
	char	*s;

	s = get_fractol_name(f);
	if (s)
	{
		ft_putstr("Found type: ");
		ft_putendl(s);
	}
	else
		ft_putendl("Error fractal type not found.");
}

static t_fractol	*init_fractol(t_fractal type)
{
	t_fractol	*f;

	if (!(f = malloc(sizeof(t_fractol))))
		return (addr_error("not enough memory", NULL));
	f->env = NULL;
	f->type = type;
	f->ended = 0;
	fractol_origin(f);
	return (f);
}

int					init_fractols(t_fractol ***fractols, int argc, char **argv)
{
	int			i;
	int			parse_index;
	int			n_frac;
	t_fractal	type;

	i = 0;
	parse_index = 1;
	n_frac = 0;
	type = none;
	if (!((*fractols) = malloc(sizeof(t_fractol *) * (FRACTAL_NUMBER + 1))))
		return (error("Cannot allocate fractals"));
	while (i < FRACTAL_NUMBER)
	{
		if ((type = parse_type(argc, argv, &parse_index)))
		{
			(*fractols)[n_frac++] = init_fractol(type);
			print_fractol_type((*fractols)[n_frac - 1]);
			type = none;
		}
		else
			(*fractols)[i] = 0;
		i++;
	}
	(*fractols)[n_frac] = NULL;
	return (0);
}
