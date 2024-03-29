/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:38:05 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/13 15:37:47 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hash_lst(t_hash *hash, int index)
{
	if (hash->type == type_intptr)
		ft_putnbr(((int *)hash->value)[index]);
	if (hash->type == type_tab)
		ft_putstr(((char **)hash->value)[index]);
	ft_putchar('\n');
}

static void	print_hash_mono(t_hash *hash)
{
	if (hash->type == type_int)
		ft_putnbr(*((int *)hash->value));
	if (hash->type == type_char)
		ft_putchar(*((char *)(hash->value)));
	if (hash->type == type_fd)
		ft_putnbr(*((int *)(hash->value)));
	if (hash->type == type_charptr)
		ft_putstr((char *)hash->value);
	if (hash->type == type_addr)
		ft_printaddr(hash->value);
	ft_putchar('\n');
}

void		ft_hashprintendl(t_hash *hash, int index)
{
	if (hash->type == type_int
			|| hash->type == type_char || hash->type == type_fd
			|| hash->type == type_charptr || hash->type == type_addr)
		print_hash_mono(hash);
	if (hash->type == type_intptr || hash->type == type_tab)
		print_hash_lst(hash, index);
}
