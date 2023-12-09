/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:05:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 17:48:15 by bcarreir         ###   ########.fr       */
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
