/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:05:45 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 13:19:09 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include "./minilibx-linux/mlx.h"

# define INVALID_ARG 2

typedef struct s_game
{
	char	**map;
	int		column;
	int		line;
	int		move;
	int		x;
	int		y;
	int		exit;
	int		collectible;
	int		p;
	void	*player;
	void	*door;
	void	*carrot;
	void	*soil;
	void	*wall;
	void	*mlx;
	void	*win;
}			t_game;

void	inital(t_game *game);
t_game	read_map(t_game game, char **argv);
void	newline_check(char *line);

void	ft_error(t_game maps, char *message);
void	free_map(char **map);
void	win_message(int moves);

t_game	control(t_game game);
void	check_accessability(t_game game);
void	check_file_extension(char *filename);

void	init_window(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);

int		key_event(int keycode, t_game *game);
int		close_window(t_game *game);
void	initialize_player_position(t_game *game);

#endif