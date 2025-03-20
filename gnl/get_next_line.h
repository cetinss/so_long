/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:39:35 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/20 15:02:39 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
#include "../libft/libft.h"

int		check_nl(char *str);
void	*ft_free(void *ptr);
int     ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);

char	*read_file(int fd, char *str);
char	*before_nl(char *str);
char	*after_nl(char *str);
char	*get_next_line(int fd);

#endif