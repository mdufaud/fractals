/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 22:27:29 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:21:15 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double complex	polynome_1(t_fractol *f, double complex z)
{
	double		pow;

	pow = 3;
	pow = pow + f->pow < 0 ? 0 : pow + f->pow;
	pow = pow > 100 ? 100 : pow;
	return (cpow(z, pow) - 1.0);
}

double complex	derivate_1(t_fractol *f, double complex z)
{
	double		pow;

	pow = 3;
	pow = pow + f->pow < 1 ? 1 : pow + f->pow;
	pow = pow > 100 ? 100 : pow;
	return (pow * cpow(z, pow - 1));
}
