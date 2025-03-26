/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:16:25 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 13:27:08 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_count(int move)
{
	ft_putnbr_fd(move, 1);
	write(1, "\n", 1);
}

void	initialize_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	update_player_position(t_game *game, int a, int b)
{
	game->move++;
	move_count(game->move);
	if (game->map[game->y + b][game->x + a] != '1')
	{
		if (game->map[game->y + b][game->x + a] == 'C')
			game->collectible--;
		if (game->map[game->y + b][game->x + a] == 'E' && game->collectible == 0)
		{
            win_message(game->move);
            game->move++;
			close_window(game);
			return ;
		}
		else if (game->map[game->y + b][game->x + a] == 'E'&& game->collectible > 0)
			return ;
		game->map[game->y][game->x] = '0';
		game->map[game->y + b][game->x + a] = 'P';
		game->y += b;
		game->x += a;
		render_map(game);
	}
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119 || keycode == 65362)
		update_player_position(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		update_player_position(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		update_player_position(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		update_player_position(game, 1, 0);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->carrot)
		mlx_destroy_image(game->mlx, game->carrot);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->soil)
		mlx_destroy_image(game->mlx, game->soil);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
	return (0);
}
