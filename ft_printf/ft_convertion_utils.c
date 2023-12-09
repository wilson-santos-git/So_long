/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:19 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 17:05:08 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	char			c;
	long			nbr;
	size_t			counter;

	counter = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		counter++;
	}
	if (nbr > 9)
		counter += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	counter += ft_putchar(c);
	return (counter);
}

int	check_base_size_and_errors(char *s1)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s1 && s1[j])
	{
		if (s1[j] == '+' || s1[j] == '-')
			return (1);
		k = j + 1;
		while (s1[k])
		{
			if (s1[j] == s1[k])
				return (1);
			k++;
		}
		j++;
	}
	if (j <= 1)
		return (1);
	return (j);
}

size_t	ft_putnbr_base(unsigned int nbr, char *base)
{
	long			longn;
	size_t			counter;

	counter = 0;
	longn = (long)nbr;
	if (longn < 0)
	{
		longn = -longn;
		counter += ft_putchar('-');
	}
	if (longn >= 16)
		counter += ft_putnbr_base(longn / 16, base);
	counter += ft_putchar(base[longn % 16]);
	return (counter);
}

size_t	ft_convert_ptr(unsigned int long p, char *base)
{
	size_t				counter;
	unsigned int long	converted;

	counter = 0;
	converted = p;
	if (!(void *)p)
	{
		ft_print_str("(nil)");
		counter += 5;
		return (counter);
	}
	if (converted >= 16)
		counter += ft_convert_ptr(converted / 16, base);
	counter += ft_putchar(base[converted % 16]);
	return (counter);
}

size_t	ft_unsigned_putnbr(int n)
{
	char			c;
	unsigned int	nbr;
	size_t			counter;

	counter = 0;
	nbr = (unsigned int)n;
	if (nbr > 9)
		counter += ft_unsigned_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	counter += ft_putchar(c);
	return (counter);
}
