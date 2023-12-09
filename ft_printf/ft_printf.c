/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:43:34 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/06 19:24:04 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

size_t	ft_found_arg(char c, va_list *al, size_t counter)
{
	unsigned long int	p;

	if (c == '%')
		counter += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(*al, int));
	else if (c == 'c')
		counter += ft_putchar(va_arg(*al, int));
	else if (c == 's')
		counter += ft_print_str(va_arg(*al, char *));
	else if (c == 'u')
		counter += ft_unsigned_putnbr(va_arg(*al, unsigned int));
	else if (c == 'x')
		counter += ft_putnbr_base(va_arg(*al, int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_putnbr_base(va_arg(*al, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		p = va_arg(*al, unsigned long int);
		if (p)
			counter += ft_print_str("0x");
		counter += ft_convert_ptr(p, "0123456789abcdef");
	}
	return (counter);
}

int	ft_is_ws(char c)
{
	if (c >= 7 && c <= 13)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	al;
	size_t	counter;

	i = 0;
	counter = 0;
	va_start(al, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			counter += ft_found_arg(str[i + 1], &al, 0);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(al);
	return (counter);
}
