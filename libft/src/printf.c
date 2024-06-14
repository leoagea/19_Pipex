/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:06:25 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:37:12 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_printf(const char *s, ...)
{
	int		temp;
	int		index;
	va_list	arg;

	temp = 0;
	index = 0;
	va_start(arg, s);
	while (s[index])
	{
		if (s[index] == '%' && ft_check_next_char(s, index))
		{
			temp += ft_parse_printf(s, index, &arg);
			index++;
		}
		else
			temp += ft_print_char(s[index]);
		index++;
	}
	va_end(arg);
	return (temp);
}
