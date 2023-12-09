/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:05:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/09 21:52:20 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_spec_strcpy(char *dst, const char *src, int i)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (src[c])
		c++;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (0);
	ft_strlcpy(dup, s, (ft_strlen(s) + 1));
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (p);
	i = ft_spec_strcpy(p, s1, i);
	i = ft_spec_strcpy(p, s2, i);
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
