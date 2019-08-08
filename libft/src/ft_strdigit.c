/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 23:18:10 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:18:13 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strdigit(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}