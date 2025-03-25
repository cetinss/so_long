/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:08:40 by sencetin          #+#    #+#             */
/*   Updated: 2024/10/28 13:33:00 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	end = (ft_strlen(s1));
	if (end == 0 || end == start)
		return (ft_strdup(""));
	--end;
	while (end > start && ft_strchr(set, s1[end]) != 0)
		end--;
	return (ft_substr((s1 + start), 0, (end - start) + 1));
}
