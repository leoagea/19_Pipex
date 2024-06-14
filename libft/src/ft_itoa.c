/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:25:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:15:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	int_len(long n)
{
	size_t	len_nbr;

	len_nbr = 0;
	if (n < 0)
	{
		n = -n;
		len_nbr = 1;
	}
	else if (n == 0)
		len_nbr = 1;
	while (n != 0)
	{
		n /= 10;
		len_nbr++;
	}
	return (len_nbr);
}

char	*ft_itoa(int n)
{
	size_t	len_nbr;
	long	cast_n;
	int		is_neg;
	char	*nbr;

	is_neg = 0;
	cast_n = (long)n;
	len_nbr = int_len((long)n);
	nbr = (char *)malloc((len_nbr + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		cast_n = -cast_n;
		nbr[0] = '-';
		is_neg = 1;
	}
	nbr[len_nbr] = '\0';
	while (len_nbr > (size_t)is_neg)
	{
		nbr[len_nbr - 1] = (cast_n % 10) + 48;
		cast_n /= 10;
		len_nbr--;
	}
	return (nbr);
}
