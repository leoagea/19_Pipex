/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:18:21 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 17:41:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	dll_insert_head(int data, t_dll *dll)
{
	t_node	*new;

	new = dll_new_node(data);
	if (dll->head == NULL)
	{
		dll->head = new;
		dll->tail = new;
	}
	else
	{
		new->next = dll->head;
		dll->head->prev = new;
		dll->head = new;
	}
}
