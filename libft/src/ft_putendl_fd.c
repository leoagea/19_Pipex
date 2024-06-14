/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:11:57 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:58:43 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	lenght;

	lenght = 0;
	if (!s || fd < 0)
		return ;
	while (s[lenght])
		lenght++;
	write(fd, s, lenght);
	write(fd, "\n", 1);
}
