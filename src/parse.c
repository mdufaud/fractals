/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 19:52:52 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/22 15:31:59 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const t_fracmatch	g_fractmatch[] = {
	{mandelbrot, "mandelbrot"},
	{julia, "julia"},
	{newton, "newton"},
	{newton2, "newton2"},
	{newton3, "newton3"},
	{burning_ship, "burning_ship"},
	{tricorn, "tricorn"},
	{popcorn, "popcorn"},
	{phoenix, "phoenix"},
	{none, NULL}
};

char						*get_fractol_name(t_fractol *f)
{
	int		i;

	i = 0;
	while (g_fractmatch[i].name)
	{
		if (f->type == g_fractmatch[i].type)
			return (g_fractmatch[i].name);
		i++;
	}
	return (NULL);
}

static int					lower_comp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (ft_tolower(s1[i]) == ft_tolower(s2[i]))
			i++;
		else
			return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
	}
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
}

t_fractal					parse_type(int argc, char **argv, int *parse_index)
{
	int			j;

	while (*parse_index < argc)
	{
		j = 0;
		while (g_fractmatch[j].name)
		{
			if (lower_comp(argv[*parse_index], g_fractmatch[j].name) == 0)
			{
				*parse_index += 1;
				return (g_fractmatch[j].type);
			}
			j++;
		}
		if (!(argv[*parse_index][0] == '-'))
		{
			ft_putcstr_fd("Type not found: ", 2, red);
			ft_putendl_fd(argv[*parse_index], 2);
		}
		*parse_index += 1;
	}
	return (none);
}
