/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:29:38 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 14:56:06 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(*game, "MLX initialization failed!\n");
	game->win = mlx_new_window(game->mlx, game->line * 64,
			game->column * 64, "so_long");
	if (!game->win)
		ft_error(*game, "Window creation failed!\n");
}

void	load_textures(t_game *game)
{
	int	x;

	x = 64;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &x, &x);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &x);
	game->carrot = mlx_xpm_file_to_image(game->mlx,
			"textures/carrot64.xpm", &x, &x);
	game->door = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &x);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/grass64.xpm", &x, &x);
	if (!game->player || !game->wall || !game->carrot
		|| !game->door || !game->floor)
		ft_error(*game, "Texture loading failed!\n");
}

void	render_map(t_game g)
{
	int	i;
	int	j;

	i = 0;
	while (g.map[i])
	{
		j = 0;
		while (g.map[i][j])
		{
			if (g.map[i][j] == '1')
				mlx_put_image_to_window(g.mlx, g.win, g.wall, j * 64, i * 64);
			else if (g.map[i][j] == '0')
				mlx_put_image_to_window(g.mlx, g.win, g.floor, j * 64, i * 64);
			else if (g.map[i][j] == 'C')
				mlx_put_image_to_window(g.mlx, g.win, g.carrot, j * 64, i * 64);
			else if (g.map[i][j] == 'E')
				mlx_put_image_to_window(g.mlx, g.win, g.door, j * 64, i * 64);
			else if (g.map[i][j] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, g.player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
