/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:50:52 by mdufaud           #+#    #+#             */
/*   Updated: 2015/10/15 17:43:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

void		destroy_img(t_fractol **f)
{
	mlx_destroy_image((*f)->env->mlx, (*f)->env->img->img);
	free((*f)->env->img);
	(*f)->env->img = NULL;
}
