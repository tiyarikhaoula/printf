/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:15:07 by ktiyari           #+#    #+#             */
/*   Updated: 2024/01/10 23:19:21 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_specifier(const char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += print_char(va_arg(args, int));
	else if (specifier == 's')
		len += print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += print_nb(va_arg(args, int));
	else if (specifier == 'u')
		len += print_unigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		len += print_ptr(va_arg(args, unsigned long));
	else if (specifier == '%')
		len += print_char('%');
	else
		print_char(specifier);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_specifier(str[i + 1], args);
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
// #include<stdio.h>
// int main()
// {
// // char *n = NULL;
// // int t = 10;
// // ft_printf("hi %s its %d PM\n", n, t);
// // printf("hi %s its %d PM\n", n, t);
// // int hex = 0;
// // ft_printf("hex = %x\n", 0);
// // printf("  hii %r\n");
// // ft_printf("%r \n");

// ft_printf("%%%% \n");
// printf("%%%c \n", 'x');

// //printf("hex = %x\n", 0);

// // int a = 10;
// // int *b = &a;
// // ft_printf("%p\n",b);
// // ft_printf("%X\n",b);
// return 0;
// }
