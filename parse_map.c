/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:05:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/17 01:29:29 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rectangular(t_map map)
{
	size_t	w;
	size_t	h;

	w = ft_strlen(map.mtx[0]);
	h = 0;
	while (map.mtx[h])
		if (ft_strlen(map.mtx[h++]) != w)
			return (false);
	return (h != w);
}

static bool	is_enclosed(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.mtx[i])
	{
		if (map.mtx[i][0] != '1' || map.mtx[i][map.width - 1] != '1')
			return (false);
		if (i == 0 || i == map.height - 1)
		{
			j = 0;
			while (map.mtx[i][j])
				if (map.mtx[i][j++] != '1')
					return (false);
		}
		i++;
	}
	return (true);
}

static bool	find_chars(char *map_str)
{
	int	i;
	int	exit_count;
	int	player_count;

	if (ft_strrchr(map_str, '1') && ft_strrchr(map_str, '0') \
		&& ft_strrchr(map_str, 'C') && ft_strrchr(map_str, 'E') \
		&& ft_strrchr(map_str, 'P'))
	{
		i = 0;
		exit_count = 0;
		player_count = 0;
		while (map_str[i])
		{
			if (map_str[i] == 'P')
				player_count++;
			else if (map_str[i] == 'E')
				exit_count++;
			i++;
		}
		return (player_count == 1 && exit_count == 1);
	}
	return (false);
}

static void	get_map(t_game *g, char *map_file, char **map_str)
{
	int	i;
	int	fd;

	i = 0;
	g->map.eggs = 0;
	g->map.width = 0;
	g->map.height = 0;
	g->map.mtx = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		exit (1);
	}
	*map_str = read_loop(&g->map, i, fd);
	close (fd);
	g->map.mtx = ft_split(*map_str, '\n');
	while (g->map.mtx[i])
		i++;
	g->map.height = i;
}

bool	validate_map(t_game *g, char *map_file)
{
	char	*tmp;
	char	**dup_mtx;
	bool	has_valid_path;

	has_valid_path = false;
	tmp = ft_strrchr(map_file, '.');
	if (tmp && ft_strlen(map_file) >= 5 && !ft_strncmp(tmp, ".ber", 4))
	{
		get_map(g, map_file, &tmp);
		if (find_chars(tmp) && is_rectangular(g->map) \
			&& is_enclosed(g->map))
		{
			free(tmp);
			g->player = init_player();
			g->exit = init_exit();
			find_objs(g);
			dup_mtx = dup_map_mtx(g->map.mtx);
			has_valid_path = find_game_path(dup_mtx, g->player.x, g->player.y);
			free_mtx(dup_mtx);
			return (has_valid_path);
		}
		free(tmp);
		free_map(g, false);	
	}
	return (false);
}
