/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:31:37 by lagea             #+#    #+#             */
/*   Updated: 2024/05/23 17:32:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	skip_whitespace_and_sign(const char **str, int *sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

static int	is_check(char *str)
{
	int	i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) || str[i] == '-'
		|| str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (free(str), 0);
		i++;
	}
	return (free(str), 1);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	res;
	long	overflow;

	res = 0;
	sign = 1;
	overflow = 0;
	if (!is_check(ft_strdup((char *)str)))
		return (2147483647814);
	skip_whitespace_and_sign(&str, &sign);
	if (ft_isdigit(*str))
	{
		while (ft_isdigit(*str))
		{
			res *= 10;
			res += (*str - 48);
			str++;
			if (overflow > res)
				return (2147483647814);
			overflow = res;
		}
	}
	else
		return (2147483647814);
	return (res * sign);
}
