/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzbib <rzbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:07:15 by rzbib             #+#    #+#             */
/*   Updated: 2026/11/19 16:28:32 by rzbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_putnbrbase(va_arg(*args, unsigned int), 10, "0123456789"));
	else if (specifier == 'x')
		return (ft_putnbrbase(va_arg(*args, unsigned int), 16,
				"0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_putnbrbase(va_arg(*args, unsigned int), 16,
				"0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = -1;
	total = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			total += handle_specifier(str[++i], &args);
		else if (ft_putchar(str[i]) < 0)
		{
			va_end(args);
			return (-1);
		}
		else
			total++;
	}
	va_end(args);
	return (total);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int x = 42;
// 	int len1;
// 	int len2;

// 	len1 = ft_printf("Custom:   Char=%c | Str=%s 
// 			| Int=%d | Hex=%x | Cap Hex=%X | Unsigned=%u | Ptr=%p\n",
// 			'A', "Hello", -255, 255, 107, 12, &x);
// 	len2 = printf("Standard: Char=%c | Str=%s 
//			| Int=%d | Hex=%x | Cap Hex=%X | Unsigned=%u | Ptr=%p\n",
// 			'A', "Hello", -255, 255, 107, 12, &x);

// 	ft_printf("Printed lengths -> Custom: %d, Standard: %d\n", len1, len2);

// 	ft_printf("String: %s\n", NULL);
// 	printf("String: %s\n", (char *)NULL);
// 	ft_printf("Pointer: %p\n", NULL);
// 	printf("Pointer: %p\n", NULL);
// 	return (0);
// }
