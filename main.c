/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:42:17 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/17 01:28:11 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *g)
{
	g->mlx.ptr = mlx_init();
	g->mlx.window = mlx_new_window(g->mlx.ptr, g->map.width * T_SIZE,
			g->map.height * T_SIZE, "so_long");
	init_images(g, T_SIZE);
	display_map(g);
	mlx_key_hook(g->mlx.window, key_press, g);
	mlx_hook(g->mlx.window, X_EVENT_KEY_EXIT, 0, win_exit, g);
	mlx_loop(g->mlx.ptr);
}

int	main(int argc, char **argv)
{
	t_game	main_game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}

	if (!validate_map(&main_game, argv[1]))
	{
		ft_printf("Error\nInvalid map\n");
		return (1);
	}

	start_game(&main_game);
}
