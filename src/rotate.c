/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 21:38:50 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:19:57 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		rotate_points_int(int *x, int *y, double rotation)
{
	int		tmp_x;
	float	rad;

	rad = rotation / 180.0 * M_PI;
	tmp_x = *x;
	*x = (*x * cos(rad)) - (*y * sin(rad));
	*y = (tmp_x * sin(rad)) + (*y * cos(rad));
}

void		rotate_points_double(double *x, double *y, double rotation)
{
	double	tmp_x;
	float	rad;

	rad = rotation / 180.0 * M_PI;
	tmp_x = *x;
	*x = (*x * cos(rad)) - (*y * sin(rad));
	*y = (tmp_x * sin(rad)) + (*y * cos(rad));
}
