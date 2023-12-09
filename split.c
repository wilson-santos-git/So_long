/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:57:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 18:03:36 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_words(char const *s, char c)
{
	int	h;
	int	count;

	h = 0;
	count = 0;
	while (s && s[h])
	{
		if (s[h] == c)
		{
			while (s[h] == c && s[h])
				h++;
			count += (s[h] != '\0');
			continue ;
		}
		else if (count == 0)
			count++;
		h++;
	}
	return (count);
}

int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

int	ft_alloc_word(char **p, char const *s, int i, char c)
{
	*p = calloc((ft_size_word(s, c, i) + 1), sizeof(char));
	if (!*p)
		return (0);
	ft_strlcpy(*p, s + i, (size_t)ft_size_word(s, c, i) + 1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = calloc(((ft_count_words(s, c)) + 1), sizeof(char *));
	if (!p || !s)
		return (p);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			if (!(ft_alloc_word(&p[j++], s, i, c)))
			{
				free_mtx(p);
				return (NULL);
			}
			i += ft_size_word(s, c, i);
		}
		else
			i++;
	}
	return (p);
}
