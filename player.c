/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:49 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 17:52:29 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_egg(t_game *game)
{
	if (game->map.eggs > 0)
		game->map.eggs--;
	if (game->map.eggs == 0)
		open_exit(game);
}

void	update(t_game *game, int keycode)
{
	bool	mirror;

	mirror = keycode == KEY_A;
	game->map.mtx[game->player.y][game->player.x] = '0';
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.window,
		game->map.img_floor, game->player.x * T_SIZE, game->player.y * T_SIZE);
	if (keycode == KEY_W)
		--game->player.y;
	else if (keycode == KEY_A)
		--game->player.x;
	else if (keycode == KEY_S)
		++game->player.y;
	else
		++game->player.x;
	if (game->map.mtx[game->player.y][game->player.x] == 'C')
		collect_egg(game);
	game->map.mtx[game->player.y][game->player.x] = 'P';
	if (mirror == true)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.window,
			game->map.img_player_m, game->player.x * T_SIZE,
			game->player.y * T_SIZE);
	else
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.window,
			game->map.img_player, game->player.x * T_SIZE,
			game->player.y * T_SIZE);
}

void	check_new_position(t_game *game, int keycode)
{
	int		x;
	int		y;
	char	**map;

	x = game->player.x;
	y = game->player.y;
	map = game->map.mtx;
	if ((keycode == KEY_W && map[y - 1][x] != '1')
		|| (keycode == KEY_A && map[y][x - 1] != '1')
		|| (keycode == KEY_S && map[y + 1][x] != '1')
		|| (keycode == KEY_D && map[y][x + 1] != '1'))
	{
		if (((keycode == KEY_W && map[y - 1][x] == 'E')
			|| (keycode == KEY_A && map[y][x - 1] == 'E')
			|| (keycode == KEY_S && map[y + 1][x] == 'E')
			|| (keycode == KEY_D && map[y][x + 1] == 'E'))
			&& game->exit.open == false)
			return ;
		else
		{
			check_exit(game, keycode);
			update(game, keycode);
			ft_printf("Player Moves = %i\n", ++game->player.moves);
		}
	}
}
