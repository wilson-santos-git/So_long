/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:28 by wteles-d          #+#    #+#             */
/*   Updated: 2024/01/10 15:37:50 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game, bool free_imgs)
{
	free_mtx(game->map.mtx);
	if (free_imgs == true)
	{
		mlx_destroy_image(game->mlx.ptr, game->map.img_egg);
		mlx_destroy_image(game->mlx.ptr, game->map.img_wall);
		mlx_destroy_image(game->mlx.ptr, game->map.img_floor);
		mlx_destroy_image(game->mlx.ptr, game->map.img_player);
		mlx_destroy_image(game->mlx.ptr, game->map.img_player_m);
		mlx_destroy_image(game->mlx.ptr, game->map.img_exit_open);
		mlx_destroy_image(game->mlx.ptr, game->map.img_exit_close);
	}
}

void	check_exit(t_game *game, int keycode)
{
	int		x;
	int		y;
	char	**map;

	x = game->player.x;
	y = game->player.y;
	map = game->map.mtx;
	if (((keycode == KEY_W && map[y - 1][x] == 'E')
		|| (keycode == KEY_A && map[y][x - 1] == 'E')
		|| (keycode == KEY_S && map[y + 1][x] == 'E')
		|| (keycode == KEY_D && map[y][x + 1] == 'E'))
		&& game->exit.open == true)
		win_exit(game);
}

void	open_exit(t_game *game)
{
	game->exit.open = true;
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.window,
		game->map.img_exit_open, game->exit.x * T_SIZE,
		game->exit.y * T_SIZE);
}
