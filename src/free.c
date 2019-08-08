/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 17:49:23 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/17 23:16:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

void	free_fractol(t_fractol **f)
{
	if ((*f)->env && (*f)->env->img)
		destroy_img(f);
	if ((*f)->env)
	{
		mlx_destroy_window((*f)->env->mlx, (*f)->env->win);
		free((*f)->env);
		(*f)->env = NULL;
	}
	free((*f)->colors);
	free(*f);
	*f = NULL;
}
