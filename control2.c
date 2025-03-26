/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:18:23 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 10:55:38 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game game)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (game.column + 1));
	i = 0;
	while (i < game.column)
	{
		copy[i] = ft_strdup(game.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	check_flood_fill(t_game game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_map(map);
				ft_error(game, "No valid path to collectibles or exit!\n");
			}
			j++;
		}
		i++;
	}
}

void	check_accessability(t_game game)
{
	char	**map;

	map = copy_map(game);
	flood_fill(map, game.x, game.y);
	check_flood_fill(game, map);
	free_map(map);
}
