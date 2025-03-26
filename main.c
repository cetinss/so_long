/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 13:15:22 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	newline_check(char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (i < len - 1)
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_putstr_fd("Error: Invalid map!\n", 2);
			free(line);
			exit(1);
		}
		i++;
	}
	if (line[0] == '\n' || line[len - 1] == '\n')
	{
		ft_putstr_fd("Error: Invalid map!\n", 2);
		free(line);
		exit(1);
	}
}

void	check_file_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4 || ft_strncmp(av + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: File extension must be .ber\n", 2);
		exit (1);
	}
}

t_game	read_map(t_game game, char **argv)
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
	newline_check(line);
	game.map = ft_split(line, '\n');
	free (line);
	return (game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (INVALID_ARG);
	check_file_extension(av[1]);
	inital(&game);
	game = read_map(game, av);
	if (!game.map || !game.map[0])
		ft_error(game, "Map file is empty!\n");
	game = control(game);
	init_window(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1, key_event, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
