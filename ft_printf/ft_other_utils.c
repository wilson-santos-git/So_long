/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:51 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 17:05:06 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_print_str(char *s)
{
	int		i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (!s)
	{
		ft_print_str("(null)");
		counter += 6;
	}
	while (s && s[i])
		counter += ft_putchar(s[i++]);
	return (counter);
}
