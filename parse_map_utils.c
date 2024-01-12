/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:05:27 by wteles-d          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:29 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		free(mtx[i++]);
	free(mtx);
}

char **dup_map_mtx(char **mtx)
{
	char **dup;
	int i;

	i = 0;
	while (mtx[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (mtx[i])
	{
		dup[i] = ft_strdup(mtx[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

bool	is_chars_valid(char *map_str)
{
	int	i;
	
	i = 0;
	while (map_str[i])
	{
		if (map_str[i] != '1' && map_str[i] != 'C'
			&& map_str[i] != 'P' && map_str[i] != 'E'
			&& map_str[i] != '0' && map_str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}