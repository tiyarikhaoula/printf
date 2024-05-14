/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:58:01 by ktiyari           #+#    #+#             */
/*   Updated: 2024/01/07 15:09:20 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unigned(unsigned int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 0;
	if (nb > 9)
	{
		len += print_unigned(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb += 48;
		write(1, &nb, 1);
		len++;
	}
	return (len);
}
