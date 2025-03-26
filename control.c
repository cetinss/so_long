/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:04:09 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 10:57:24 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	map_size(t_game game)
{
	while (game.map[0][game.line])
		game.line++;
	while (game.map[game.column])
		game.column++;
	return (game);
}

static void	is_rectangle(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
			j++;
		if (j != game.line)
			ft_error(game, "Map is not a rectangle!\n");
		i++;
	}
}

static void	wall_control(t_game game)
{
	int	i;
	int	j;

	if (game.column < 3 || game.line < 3)
		ft_error(game, "Map is too small!\n");
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (i == 0 || i == game.column - 1 || j == 0 || j == game.line - 1)
			{
				if (game.map[i][j] != '1')
					ft_error(game, "Map is not surrounded by walls!\n");
			}
			j++;
		}
		i++;
	}
}

static t_game	map_content(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'C')
				game.collectible++;
			else if (game.map[i][j] == 'E')
				game.exit++;
			else if (game.map[i][j] == 'P')
				game.p++;
			else if (game.map[i][j] != '0' && game.map[i][j] != '1')
				ft_error(game, "Map contains invalid characters!\n");
			j++;
		}
		i++;
	}
	if (!(game.p == 1 && game.collectible >= 1 && game.exit == 1))
		ft_error(game, "Invalid number of player, exit, or collectible!\n");
	return (game);
}

t_game	control(t_game game)
{
	game = map_size(game);
	is_rectangle(game);
	wall_control(game);
	game = map_content(game);
	initialize_player_position(&game);
	check_accessability(game);
	return (game);
}
