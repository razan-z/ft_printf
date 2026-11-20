/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzbib <rzbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:08:43 by rzbib             #+#    #+#             */
/*   Updated: 2026/11/19 15:12:11 by rzbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbrbase(unsigned long n, unsigned int base, char *digits);
int	ft_putnbr(int n);
int	ft_printptr(void *ptr);

int	handle_specifier(char specifier, va_list *args);

int	ft_printf(const char *str, ...);

#endif