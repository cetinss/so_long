/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/21 01:24:31 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	inital(t_game *game)
{
	game->map = NULL;
	game->column = 0;
	game->line = 0;
	game->move = 0;
	game->x = 0;
	game->y = 0;
	game->exit = 0;
	game->collectible = 0;
	game->player = NULL;
	game->door = NULL;
	game->carrot = NULL;
	game->soil = NULL;
	game->wall = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->filename = NULL;
}

t_game read_map(char **argv)
{
	t_game	maps;
	char	*str;
	char	*line;
	char	*cpy;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (1);
	line = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		cpy = line;
		line = ft_strjoin(line, str);
		free(str);
		free(cpy);
		str = get_next_line(fd);
	}
	fd = close(fd);
	maps.map = ft_split(line, '\n');
	maps.filename = argv[1];
	free (line);
	return (maps);
}

int main(int ac, char **av)
{
	t_game	game;
	if (ac != 2)
		return (INVALID_ARG);
	inital(&game);
	game.filename = av[1];
	game = read_map(av);
	if (!game.map || !game.map[0])
		ft_error(game , "Map file is empty!\n");
	initialize_player_position(&game);
	game = control(game);
	init_window(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1, key_event, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
