/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:06:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:34:32 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_check_next_char(const char *s, int index)
{
	if (!s[index + 1])
		return (0);
	else if (s[index] == 'c' || s[index] == 's' || s[index] == 'p')
		return (1);
	else if (s[index] == 'i' || s[index] == 'd' || s[index] == '%')
		return (1);
	else if ((s[index] == 'u' || s[index] == 'x' || s[index] == 'X'))
		return (1);
	else
		return (0);
}

int	ft_parse_printf(const char *s, int index, va_list *par)
{
	if (s[index + 1] == 'c')
		return (ft_print_char(va_arg(*par, int)));
	else if (s[index + 1] == 's')
		return (ft_print_string(va_arg(*par, char *)));
	else if (s[index + 1] == 'p')
		return (ft_print_add(va_arg(*par, unsigned long)));
	else if (s[index + 1] == 'd' || s[index + 1] == 'i')
		return (ft_print_decimal(va_arg(*par, int)));
	else if (s[index + 1] == 'u')
		return (ft_print_udecimal(va_arg(*par, unsigned int)));
	else if (s[index + 1] == 'x')
		return (ft_print_hex(va_arg(*par, long), "0123456789abcdef"));
	else if (s[index + 1] == 'X')
		return (ft_print_hex(va_arg(*par, long), "0123456789ABCDEF"));
	else if (s[index + 1] == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
