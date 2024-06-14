/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:27:13 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:34:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_print_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_int_len((int)n));
}

int	ft_print_udecimal(unsigned int n)
{
	ft_putunbr_fd(n, 1);
	return (ft_int_len((unsigned int)n));
}

int	ft_print_hex(unsigned int n, char *base)
{
	if (n < 16)
		return (ft_print_char(base[n]));
	else
	{
		if (ft_print_hex(((unsigned int)n / 16), base))
			ft_print_char(base[n % 16]);
	}
	return (ft_hex_len(n));
}
