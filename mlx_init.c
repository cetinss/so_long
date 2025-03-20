/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:29:38 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/20 22:15:04 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(*game, "MLX initialization failed!\n");
	game->win = mlx_new_window(game->mlx, game->line * 64, game->column * 64, "so_long");
	if (!game->win)
		ft_error(*game, "Window creation failed!\n");
}

void	load_textures(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &y);
	game->carrot = mlx_xpm_file_to_image(game->mlx, "textures/carrot64.xpm", &x, &y);
	game->door = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &y);
	game->soil = mlx_xpm_file_to_image(game->mlx, "textures/grass64.xpm", &x, &y);
	if (!game->player || !game->wall || !game->carrot || !game->door || !game->soil)
		ft_error(*game, "Texture loading failed!\n");
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->soil, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->carrot, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->door, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
