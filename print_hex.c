/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:08:41 by ktiyari           #+#    #+#             */
/*   Updated: 2024/01/10 23:25:46 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(unsigned long v, char specifier)
{
	char	*base;
	int		i;

	i = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	if (v < 16)
		i += print_char(base[v]);
	else
	{
		i += print_hex(v / 16, specifier);
		i += print_hex(v % 16, specifier);
	}
	return (i);
}
// int main() {

//   int h = 355;
//   print_hex(h);
//   return 0;
// }
