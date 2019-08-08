/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 22:28:26 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/17 22:29:37 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double complex	polynome_2(t_fractol *f, double complex z)
{
	(void)f;
	return (csin(z));
}

double complex	derivate_2(t_fractol *f, double complex z)
{
	(void)f;
	return (ccos(z));
}
