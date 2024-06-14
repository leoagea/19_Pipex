/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:42:38 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 17:07:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_print_hex_add(unsigned long n)
{
	char	*base_16;

	base_16 = "0123456789abcdef";
	if (n < 16)
		return (ft_print_char(base_16[n]));
	else
	{
		if (ft_print_hex_add((unsigned long)n / 16))
			return (ft_print_char(base_16[n % 16]));
	}
	return (-1);
}

int	ft_print_add(unsigned long add)
{
	write(1, "0x", 2);
	ft_print_hex_add(add);
	return (ft_add_len(add) + 2);
}
