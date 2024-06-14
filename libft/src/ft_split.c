/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:15:05 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:15:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*free_all_char(char **c)
{
	int	i;

	i = 0;
	while (c[i] != NULL)
	{
		free(c[i]);
		i++;
	}
	return (NULL);
}

static int	count_strings(char const *s, char c)
{
	int	index;
	int	nbr_words;

	index = 0;
	nbr_words = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != '\0')
			nbr_words++;
		while (s[index] != c && s[index])
			index++;
	}
	return (nbr_words);
}

static char	*malloc_len_word(char const *s, char c)
{
	char	*new;
	int		i;
	int		index;
	int		len_word;

	i = 0;
	index = 0;
	len_word = 0;
	while (s[index] != c && s[index])
	{
		index++;
		len_word++;
	}
	new = (char *)malloc((len_word + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len_word)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**put_in_strings(const char *s, char c, int nbr_words,
		char **news_s)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (s[index] && i < nbr_words)
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != '\0')
		{
			news_s[++i] = malloc_len_word(&s[index], c);
			if (news_s[i] == NULL)
				return (free_all_char(news_s), free(news_s), NULL);
		}
		while (s[index] != c && s[index])
			index++;
	}
	return (news_s);
}

char	**ft_split(char const *s, char c)
{
	int		nbr_words;
	char	**news_s;

	if (!s)
		return (NULL);
	nbr_words = count_strings(s, c) + 1;
	news_s = (char **)malloc((nbr_words) * sizeof(char *));
	if (!news_s)
		return (NULL);
	if (put_in_strings(s, c, nbr_words, news_s) == NULL)
		return (NULL);
	news_s[nbr_words - 1] = NULL;
	return (news_s);
}
