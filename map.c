/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:43:28 by wteles-d          #+#    #+#             */
/*   Updated: 2024/01/12 17:41:46 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*find_img_type(t_game *game, int i, int j)
{
	if (game->map.mtx[i][j] == '1')
		return (game->map.img_wall);
	else if (game->map.mtx[i][j] == '0')
		return (game->map.img_floor);
	else if (game->map.mtx[i][j] == 'E')
		return (game->map.img_exit_close);
	else if (game->map.mtx[i][j] == 'P')
		return (game->map.img_player);
	else if (game->map.mtx[i][j] == 'C')
		return (game->map.img_egg);
	return (NULL);
}

void	display_map(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (game->map.mtx[i])
	{
		j = 0;
		while (game->map.mtx[i][j])
		{
			img = find_img_type(game, i, j);
			mlx_put_image_to_window(game->mlx.ptr, game->mlx.window, img,
				j * T_SIZE, i * T_SIZE);
			j++;
		}
		i++;
	}
}

void	find_objs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.mtx[i])
	{
		j = 0;
		while (game->map.mtx[i][j])
		{
			if (game->map.mtx[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->map.mtx[i][j] == 'C')
				game->map.eggs++;
			else if (game->map.mtx[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
			}
			j++;
		}
		i++;
	}
}

char	*read_loop(t_map *map, int i, int fd)
{
	char	*line;
	char	*s1;
	char	*temp_str;

	s1 = NULL;
	line = NULL;
	temp_str = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		map->width = ft_strlen(line);
		s1 = temp_str;
		temp_str = ft_strjoin(s1, line);
		if (!temp_str)
		{
			free(line);
			return (NULL);
		}
		free(line);
		free(s1);
	}
	return (temp_str);
}

bool	check_newlines(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (false);
	while (str[i])
	{
		if ((str[i] == '\n') && (str[i + 1] == '\n'))
			return (false);
		i++;
	}
	return (true);
}
