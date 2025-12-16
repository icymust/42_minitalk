/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:09:17 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/04 13:45:22 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*split_word(char const *str, char c)
{
	char	*word;
	int		word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	word_len = 0;
	while (str[word_len] && str[word_len] != c)
	{
		word[word_len] = str[word_len];
		word_len++;
	}
	word[word_len] = '\0';
	return (word);
}

static void	free_all(char **words, int pos)
{
	while (pos--)
		free(words[pos]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		words_pos;
	int		i;

	words_pos = 0;
	i = 0;
	words = (char **)malloc(sizeof(char *) * (size(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[words_pos] = split_word(&s[i], c);
			if (!words[words_pos])
				return (free_all(words, words_pos), NULL);
			words_pos++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	words[words_pos] = NULL;
	return (words);
}
