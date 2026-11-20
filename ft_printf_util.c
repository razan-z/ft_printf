/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzbib <rzbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:41:46 by rzbib             #+#    #+#             */
/*   Updated: 2026/11/19 16:46:22 by rzbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
	{
		if (ft_putchar(str[count]) < 0)
			return (-1);
		count ++;
	}
	return (count);
}

int	ft_putnbrbase(unsigned long n, unsigned int base, char *digits)
{
	int	count;
	int	error;

	count = 0;
	if (n >= base)
	{
		error = ft_putnbrbase(n / base, base, digits);
		if (error < 0)
			return (-1);
		count += error;
	}
	if (ft_putchar(digits[n % base]) < 0)
		return (-1);
	count ++;
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		error;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
		nb = -nb;
	}
	error = ft_putnbrbase((unsigned long)nb, 10, "0123456789");
	if (error < 0)
		return (-1);
	count += error;
	return (count);
}

int	ft_printptr(void *ptr)
{
	int	count;
	int	error;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	error = 0;
	if (count < 0)
		return (-1);
	error += ft_putnbrbase((uintptr_t)ptr, 16, "0123456789abcdef");
	if (error < 0)
		return (-1);
	count += error;
	return (count);
}
