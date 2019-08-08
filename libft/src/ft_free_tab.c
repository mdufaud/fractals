/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 20:17:58 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:16:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!tab)
		return ;
	tmp = *tab;
	while (tmp[i])
	{
		if (tmp[i])
			ft_strdel(&(tmp[i]));
		i++;
	}
	free(*tab);
	*tab = NULL;
}
