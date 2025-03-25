/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/25 16:52:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	win_message(int moves)
{
	ft_putstr_fd("\n🎉 Congratulations! 🎉\n", 1);
	ft_putstr_fd("You completed the game in ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd(" moves!\n", 1);
	ft_putstr_fd("Thanks for playing So_Long 💚\n\n", 1);
}

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
	game->p = 0;
	game->player = NULL;
	game->door = NULL;
	game->carrot = NULL;
	game->soil = NULL;
	game->wall = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->filename = NULL;
}

int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

t_game read_map(t_game game, char **argv)
{
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
	close(fd);
	game.map = ft_split(line, '\n');
	game.filename = argv[1];
	free (line);
	return (game);
}

int main(int ac, char **av)
{
	t_game	game;
	if (ac != 2)
		return (INVALID_ARG);
	if (!check_file_extension(av[1]))
	{
		ft_putstr_fd("Error: File extension must be .ber\n", 2);
		return (1);
	}
	inital(&game);
	game.filename = av[1];
	game = read_map(game, av);
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
