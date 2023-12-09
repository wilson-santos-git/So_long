/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:49:21 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/06 19:09:00 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_exit(t_game *game)
{
	free_map(game, true);
	mlx_clear_window(game->mlx.ptr, game->mlx.window);
	mlx_destroy_window(game->mlx.ptr, game->mlx.window);
	mlx_destroy_display(game->mlx.ptr);
	free(game->mlx.ptr);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D)
		check_new_position(game, keycode);
	else if (keycode == KEY_ESC)
		win_exit(game);
	return (0);
}
