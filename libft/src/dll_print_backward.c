/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_backward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:38:24 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 19:59:41 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	dll_print_backward(t_dll *dll)
{
	int		i;
	t_node	*current;

	i = 0;
	current = dll->tail;
	while (current != NULL)
	{
		ft_printf("index %d : %d\n", i, current->value);
		current = current->prev;
		i++;
	}
}
