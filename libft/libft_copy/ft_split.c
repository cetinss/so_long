/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:20:40 by sencetin          #+#    #+#             */
/*   Updated: 2024/10/28 12:20:41 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*create_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **result, int index)
{
	while (index > 0)
		free(result[--index]);
	free(result);
	return (NULL);
}

static char	**split_words(char **result, char const *s, char c)
{
	int		start;
	int		end;
	int		index;

	start = 0;
	index = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (start < end)
		{
			result[index] = create_word(s, start, end);
			if (!result[index])
				return (free_all(result, index));
			index++;
		}
		start = end;
	}
	result[index] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (split_words(result, s, c));
}
