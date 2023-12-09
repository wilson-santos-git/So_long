/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:44:57 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 17:04:51 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_putnbr(int n);
size_t	ft_putchar(char c);
size_t	ft_print_str(char *s);
size_t	ft_unsigned_putnbr(int n);
int		ft_printf(const char *str, ...);
int		check_base_size_and_errors(char *s1);
size_t	ft_putnbr_base(unsigned int nbr, char *base);
size_t	ft_convert_ptr(unsigned int long p, char *base);
size_t	ft_found_arg(char c, va_list *al, size_t counter);

#endif