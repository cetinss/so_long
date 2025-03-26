/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:39:43 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/26 13:09:58 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(t_game maps, char *message)
{
	free_map(maps.map);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	exit (1);
}

void	win_message(int moves)
{
	ft_putstr_fd("\n🎉 Congratulations! 🎉\n", 1);
	ft_putstr_fd("You completed the game in ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd(" moves!\n", 1);
	ft_putstr_fd("Thanks for playing So_Long 💚\n\n", 1);
}
