/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 17:37:09 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/10 19:07:46 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		error(char *s)
{
	ft_putcstr_fd("Error: ", 2, red);
	ft_putendl(s);
	return (1);
}

void	*addr_error(char *s, void *p)
{
	ft_putcstr_fd("Error: ", 2, red);
	ft_putendl(s);
	return (p);
}
