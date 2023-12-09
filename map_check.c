/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:56:20 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 15:15:08 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_line(t_game *game, char *line, char c)
{
	int	i;

	if ((line[0] != '1') || (line[game->map.width - 1] != '1'))
		return (false);
	i = 1;
	if (c == '1')
	{
		while (i < game->map.width - 1)
		{
			if (line[i] != c)
				return (false);
			i++;
		}
	}
	if ((ft_strlen(line) > (long unsigned int)game->map.width)
		|| (ft_strlen(line) < (long unsigned int)game->map.width))
		return (false);
	return (true);
}

static bool	extra_check(t_game *game, int i)
{
	if ((i == 0) || (i == game->map.height - 1))
	{
		if (check_line(game, game->map.mtx[i], '1') == false)
			return (false);
	}
	else if (check_line(game, game->map.mtx[i], '0') == false)
		return (false);
	return (true);
}

static bool	extra_while(t_game *game, int players, int exits, int i)
{
	int	j;

	while (i < game->map.height)
	{
		if (extra_check(game, i) == false)
			return (false);
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.mtx[i][j] != 'E' && game->map.mtx[i][j] != 'C'
				&& game->map.mtx[i][j] != 'P' && game->map.mtx[i][j] != '1'
				&& game->map.mtx[i][j] != '0')
				return (false);
			else if (game->map.mtx[i][j] == 'E')
				exits++;
			else if (game->map.mtx[i][j] == 'P')
				players++;
			j++;
		}
		i++;
	}
	if ((exits == 0 || exits > 1) || (players == 0 || players > 1))
		return (false);
	return (true);
}

bool	check_map(t_game *game)
{
	int	i;
	int	exits;
	int	players;

	i = 0;
	if (game->map.height == game->map.width)
		return (false);
	if (game->map.eggs < 1)
		return (false);
	exits = 0;
	players = 0;
	if (extra_while(game, players, exits, i) == false)
		return (false);
	return (true);
}
