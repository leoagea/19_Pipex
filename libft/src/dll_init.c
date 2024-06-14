/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:44:53 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 20:00:11 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dll_init(t_dll *dll)
{
	t_dll	*dll;

	dll = malloc(sizeof(t_dll));
	dll->head = NULL;
	dll->tail = NULL;
}