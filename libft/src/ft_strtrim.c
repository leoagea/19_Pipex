/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:23:49 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:15:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static char	*create_trimmed_string(const char *s1, size_t start, size_t end)
{
	char	*s_trimmed;
	size_t	i;

	s_trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!s_trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s_trimmed[i++] = s1[start++];
	}
	s_trimmed[i] = '\0';
	return (s_trimmed);
}

static size_t	find_start(const char *s1, const char *set)
{
	size_t	index;

	index = 0;
	while (s1[index] && is_set(s1[index], set))
		index++;
	return (index);
}

static size_t	find_end(const char *s1, const char *set, size_t len)
{
	size_t	index;

	index = len - 1;
	while (index > 0 && is_set(s1[index], set))
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	start = find_start(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = find_end(s1, set, len);
	if (start > end)
		return (ft_strdup(""));
	return (create_trimmed_string(s1, start, end));
}
