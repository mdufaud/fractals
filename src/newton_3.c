/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 22:28:47 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/17 22:42:46 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double complex	polynome_3(t_fractol *f, double complex z)
{
	(void)f;
	return (cpow(z, 3) - 2 * z + 2);
}

double complex	derivate_3(t_fractol *f, double complex z)
{
	(void)f;
	return (3 * cpow(z, 2) - 2);
}
