/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:55:48 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:59:20 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	length;

	length = 0;
	if (!s || fd < 0)
		return ;
	while (s[length])
		length++;
	write(fd, s, length);
}
