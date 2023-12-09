/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:47:25 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/08 16:29:16 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game, int size)
{
	game->map.img_egg = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Egg.xpm", &size, &size);
	game->map.img_wall = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Wall.xpm", &size, &size);
	game->map.img_floor = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Floor.xpm", &size, &size);
	game->map.img_player = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Player.xpm", &size, &size);
	game->map.img_player_m = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Player_M.xpm", &size, &size);
	game->map.img_exit_open = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Exit_Open.xpm", &size, &size);
	game->map.img_exit_close = mlx_xpm_file_to_image(game->mlx.ptr, \
		"imgs/Exit_Close.xpm", &size, &size);
}

t_player	init_player(void)
{
	t_player	player;

	player.x = 0;
	player.y = 0;
	player.moves = 0;
	return (player);
}

t_door	init_exit(void)
{
	t_door	exit;

	exit.x = 0;
	exit.y = 0;
	exit.open = false;
	return (exit);
}
