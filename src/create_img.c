/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:43:08 by mdufaud           #+#    #+#             */
/*   Updated: 2015/10/15 17:43:01 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

void		create_img(t_fractol **f)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		error("Not enough memory");
	img->width = (*f)->env->win_width;
	img->height = (*f)->env->win_height;
	if (!(img->img = mlx_new_image((*f)->env->mlx, (*f)->env->win_width,
		(*f)->env->win_height)))
		error("Could not create image");
	if (!(img->data = mlx_get_data_addr(img->img, &img->bpp,
		&img->sizel, &img->endian)))
		error("Could not create data addr");
	(*f)->env->img = img;
}
