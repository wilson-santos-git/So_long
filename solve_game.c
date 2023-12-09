/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:04:59 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 17:06:55 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_game_complete(char **mtx)
{
	int	i;
	int	j;
	int w;
	int h;

	w = ft_strlen(mtx[0]);
	h = 0;
	while (mtx[h])
		h++;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (mtx[i][j] == 'C'
				|| mtx[i][j] == 'E')
				return (false); 
			j++;
		}
		i++;
	}
	return (true);
}

static int	is_move_valid(char **mtx, int *new_x, int *new_y, char move)
{
	int w;
	int h;

	w = ft_strlen(mtx[0]);
	h = 0;
	while (mtx[h])
		h++;
	if (move == 'W')
		(*new_y)--;
	else if (move == 'D')
		(*new_x)++;
	else if (move == 'S')
		(*new_y)++;
	else if (move == 'A')
		(*new_x)--;
	if (*new_x < 0 || *new_x >= w
		|| *new_y < 0 || *new_y >= h)
		return (0);
	else if (mtx[*new_y][*new_x] == 'X')
		return (0);
	return (mtx[*new_y][*new_x] != '1');
}

bool	find_game_path(char **mtx, int player_x, int player_y)
{
	int		i;
	int		new_x;
	int		new_y;
	char	*moves;

	if (is_game_complete(mtx))
		return (true);
	moves = "WDSA";
	i = 0;
	while (i < 4)
	{
		new_x = player_x;
		new_y = player_y;
		if (is_move_valid(mtx, &new_x, &new_y, moves[i++]))
		{
			mtx[player_y][player_x] = 'X';
			mtx[new_y][new_x] = 'P';
			if (find_game_path(mtx, new_x, new_y))
				return (true);
			mtx[player_y][player_x] = 'P';
			mtx[new_y][new_x] = '1';
		}
	}
	return (false);
}
