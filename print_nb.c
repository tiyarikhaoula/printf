/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:11:24 by ktiyari           #+#    #+#             */
/*   Updated: 2024/01/07 15:03:03 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_nb(int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len++;
	}
	if (nb > 9)
	{
		len += print_nb(nb / 10);
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
