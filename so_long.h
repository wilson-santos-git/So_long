/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:42:24 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/17 01:27:59 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_SPACE	32

# define X_EVENT_KEY_EXIT		17
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define MAP_FILE "map3.ber"

# define T_SIZE	64

typedef struct map_vars {
	int		eggs;
	int		width;
	char	**mtx;
	int		height;
	void	*img_egg;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_player_m;
	void	*img_exit_open;
	void	*img_exit_close;
}					t_map;

typedef struct mlx_vars {
	void	*ptr;
	void	*window;
}					t_mlx;

typedef struct player_vars {
	int		x;
	int		y;
	int		moves;
}					t_play;

typedef struct exit_vars {
	int		x;
	int		y;
	bool	open;
}					t_door;

typedef struct game_objects {
	t_map		map;
	t_mlx		mlx;
	t_door		exit;
	t_play	player;
}					t_game;

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

t_door	init_exit(void);
t_play	init_player(void);
void	init_images(t_game *game, int size);
char	*read_loop(t_map *map, int i, int fd);

void	free_mtx(char **mtx);
int		win_exit(t_game *game);
void	find_objs(t_game *game);
void	open_exit(t_game *game);
bool	check_map(t_game *game);
void	display_map(t_game *game);
void	collect_egg(t_game *game);
char	**dup_map_mtx(char **mtx);
void	update(t_game *game, int keycode);
int		key_press(int keycode, t_game *game);
void	check_exit(t_game *game, int keycode);
void	free_map(t_game *game, bool free_imgs);
bool	validate_map(t_game *g, char *map_file);
void	check_new_position(t_game *game, int keycode);
bool	find_game_path(char **mtx, int player_x, int player_y);

#endif