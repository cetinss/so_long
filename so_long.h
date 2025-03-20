/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:05:45 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/20 16:44:05 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"

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
	void	*player;
	void	*door;
	void	*carrot;
	void	*soil;
	void	*wall;
	void	*mlx;
	void	*win;
}			t_game;

//map.c
void	inital(t_game *game);
t_game	read_map(char **map);

//error.c
void	ft_error(t_game maps, char *message);
void	free_map(char **map);

//control.c
t_game	control(t_game game);
void	check_accessability(t_game game);



#endif